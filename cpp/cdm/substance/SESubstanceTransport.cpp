/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#include "stdafx.h"
#include "substance/SESubstanceTransport.h"
#include "properties/SEScalar0To1.h"
#include "properties/SEScalarMass.h"
#include "properties/SEScalarMassPerVolume.h"
#include "properties/SEScalarVolume.h"
#include "properties/SEScalarVolumePerTime.h"

#include <Eigen/Core>
#include <Eigen/LU>

//#define VERBOSE
#define ZERO_APPROX 1e-10

template <typename GraphType, typename FluxUnit, typename QuantityUnit, typename ExtensiveUnit, typename IntensiveUnit>
SESubstanceTransporter<GraphType, FluxUnit, QuantityUnit, ExtensiveUnit, IntensiveUnit>::SESubstanceTransporter(const FluxUnit& fUnit,
  const QuantityUnit& qUnit,
  const ExtensiveUnit& eUnit,
  const IntensiveUnit& iUnit,
  Logger* logger) : Loggable(logger),
  m_FluxUnit(fUnit),
  m_QuantityUnit(qUnit),
  m_ExtensiveUnit(eUnit),
  m_IntensiveUnit(iUnit)
{

}

//--------------------------------------------------------------------------------------------------
/// \brief
/// Calculates the intensive and extensive properties for this Graph
///
/// \param  timestep time-step of the system
///
/// \details
/// Calculates the intensive (liquid concentration or gas volume fraction) and extensive (mass in liquid or volume of gas)
/// properties for all vertexs in the graph.
/// This uses an Eigen solver.
/// An INTENSIVE property is a bulk property, meaning that it is a physical property of a system that does not depend on the system size or the amount of material in the system.
/// For us, this includes Concentration and VolumeFraction
/// An EXTENSIVE property is additive for independent, non-interacting subsystems. The property is proportional to the amount of material in the system.
/// For us, this includes Mass and Volume
//--------------------------------------------------------------------------------------------------
template <typename GraphType, typename FluxUnit, typename QuantityUnit, typename ExtensiveUnit, typename IntensiveUnit>
void SESubstanceTransporter<GraphType, FluxUnit, QuantityUnit, ExtensiveUnit, IntensiveUnit>::Transport(GraphType& graph, double timeStep_s)
{
  //We can assume the flows and volumes are already solved for this time-step, but no substances moved

  auto& verticies = graph.GetVerticies();
  size_t numVerts = verticies.size();

  // We assume every vertex has the same amount of substances and are in the same order
  size_t numSubstances = verticies[0]->GetTransportSubstances().size();
  if (numSubstances == 0)
    return;

  // The A matrix is a square matrix for all nodes
  //All zeros - we'll modify the values later
  //Ax=b
  Eigen::MatrixXd AMatrix = Eigen::MatrixXd::Zero(numVerts, numVerts);
  Eigen::MatrixXd AMatrixInverse = Eigen::MatrixXd::Zero(numVerts, numVerts);

  //1) Determine A matrix - this will be the same for all substances -------------------------------------------------
  for (size_t i = 0; i < numVerts; i++)
  {
    auto* v = verticies[i];
    auto& quantity = v->GetQuantity();
    //Put the current quantity in the matrix
    //If it doesn't have a quantity, just leave it zero
    if (quantity.IsInfinity())
    {
      //Infinite quantity means intensive property is constant
      AMatrix(i, i) = 1.0;
      continue;
    }
    else if (!quantity.IsValid() || quantity.IsZero())
    {
      //If there's no quantity and therefore no intensive or extensive properties, we need to mimic a super small volume
      //Setting it to zero and adding extensive balance from paths in and out will not solve
      //Also setting it to a constant value of zero and no adding the in and out path will not solve
      //Basically divide by zero / un-invertable matrix issues
      //The solution is to use an approximately zero quantity
      AMatrix(i, i) += 1e-20;// ZERO_APPROX;
    }
    else
    {
      if (quantity.IsNegative())
      {
        ///\error Fatal: Can't transport with a negative quantity included.
        std::stringstream ss;
        ss << "Can't transport with a negative volume included. Node = " << v->GetName()
          << ". Volume = " << v->GetQuantity().GetValue(VolumeUnit::mL) << " mL";
        ///\error Fatal: Can't transport with a negative volume included.
        Fatal(ss);
      }

      AMatrix(i, i) += quantity.GetValue(m_QuantityUnit);
    }

    auto* sEdges = graph.GetSourceEdges(*v);
    if (sEdges != nullptr)
    {
      for (auto* srcEdge : *sEdges)
      {
        if (srcEdge->HasFlux())
        {
          double flux = srcEdge->GetFlux().GetValue(m_FluxUnit);

          if (std::abs(flux) < ZERO_APPROX)
          {
            //This is basically zero and not worth dealing with
            continue;
          }

          if (flux < 0.0)
          {
            //Flow in
            AMatrix(i, graph.GetVertexIndex(srcEdge->GetTargetVertex())) -= std::abs(flux) * timeStep_s;
          }
          else
          {
            //Flow out
            AMatrix(i, i) += std::abs(flux) * timeStep_s;
          }
        }
      }
    }

    auto* tEdges = graph.GetTargetEdges(*v);
    if (tEdges != nullptr)
    {
      for (auto* tgtEdge : *tEdges)
      {
        if (tgtEdge->HasFlux())
        {
          double flux = tgtEdge->GetFlux().GetValue(m_FluxUnit);

          if (std::abs(flux) < ZERO_APPROX)
          {
            //This is basically zero and not worth dealing with
            continue;
          }

          if (flux < 0.0)
          {
            //Flow out
            AMatrix(i, i) += std::abs(flux) * timeStep_s;
          }
          else
          {
            //Flow in          
            AMatrix(i, graph.GetVertexIndex(tgtEdge->GetSourceVertex())) -= std::abs(flux) * timeStep_s;
          }
        }
      }
    }
  }

  //Since A doesn't change, we'll just calculate it's inverse and reuse it to solve for x for each substance
  AMatrixInverse = AMatrix.inverse();

  //2) Loop over the extensive/intensive properties per substances -------------------------------------------------  
  for (size_t s = 0; s < numSubstances; s++)
  {
    //Ax = b
    Eigen::VectorXd xVector(numVerts); //x
    Eigen::VectorXd bVector(numVerts); //b
    bVector = Eigen::VectorXd::Zero(numVerts);

    //2a) Put the extensive property in the b vector for each node -------------------------------------------------
    for (size_t i = 0; i < numVerts; i++)
    {
      auto* v = verticies[i];
      if (!v->HasQuantity())
        continue;
      auto* q = v->GetTransportSubstances()[s];
      if (q->HasIntensive())
      {
        if (v->GetQuantity().IsInfinity())
        {
          //Concentration doesn't change - this happens at reference nodes a lot (e.g. the Environment)
          bVector(i) = q->GetIntensive().GetValue(m_IntensiveUnit);
        }
        else
        {
          bVector(i) += q->GetExtensive().GetValue(m_ExtensiveUnit);
        }
      }
    }

    //2b) Solve for the intensive property x vector -------------------------------------------------
    xVector = AMatrixInverse * bVector;

    //2c) Parse the intensive property and calculate the new intensive property -------------------------------------------------
    for (size_t i = 0; i < numVerts; i++)
    {
      auto* v = verticies[i];
      auto* q = v->GetTransportSubstances()[s];
      if (q->HasExtensive())
      {
        if (!v->HasQuantity())
        {
          q->Invalidate();
          continue;
        }
        double newIntensiveVlaue = xVector(i);
        if (std::abs(newIntensiveVlaue) < ZERO_APPROX)
        {
          newIntensiveVlaue = 0.0;
        }
        //We force this value becuase it can get above 1 when there is a disconinuity that causes numerical error.
        //That generally only occurs when an extreme action or condition is applied.
        //The balance call after this loop will adjust everything to sum nicely to 1.0.
        q->GetIntensive().ForceValue(newIntensiveVlaue, m_IntensiveUnit);
      }
    }
  }
  graph.BalanceByIntensive();
}

SEGasTransporter::SEGasTransporter(Logger* logger) : SESubstanceTransporter<SEGasTransportGraph, VolumePerTimeUnit, VolumeUnit, VolumeUnit, NoUnit>(
  VolumePerTimeUnit::L_Per_s, VolumeUnit::L, VolumeUnit::L, NoUnit::unitless, logger)
{

}
SEGasTransporter::SEGasTransporter(const VolumePerTimeUnit& fUnit, const VolumeUnit& qUnit, const VolumeUnit& eUnit, Logger* logger)
  : SESubstanceTransporter<SEGasTransportGraph, VolumePerTimeUnit, VolumeUnit, VolumeUnit, NoUnit>(fUnit, qUnit, eUnit, NoUnit::unitless, logger)
{

}
SEGasTransporter::~SEGasTransporter()
{

}

SELiquidTransporter::SELiquidTransporter(Logger* logger) : SESubstanceTransporter<SELiquidTransportGraph, VolumePerTimeUnit, VolumeUnit, MassUnit, MassPerVolumeUnit>(
  VolumePerTimeUnit::L_Per_s, VolumeUnit::mL, MassUnit::ug, MassPerVolumeUnit::ug_Per_mL, logger)
{

}
SELiquidTransporter::SELiquidTransporter(const VolumePerTimeUnit& fUnit, const VolumeUnit& qUnit, const MassUnit& eUnit, const MassPerVolumeUnit& iUnit, Logger* logger)
  : SESubstanceTransporter<SELiquidTransportGraph, VolumePerTimeUnit, VolumeUnit, MassUnit, MassPerVolumeUnit>(fUnit, qUnit, eUnit, iUnit, logger)
{

}
SELiquidTransporter::~SELiquidTransporter()
{

}

// Transportables
template class SESubstanceTransportVertex<SEScalarVolume, SEScalarVolume, SEScalar0To1>;
template class SESubstanceTransportVertex<SEScalarVolume, SEScalarMass, SEScalarMassPerVolume>;
template class SESubstanceTransportEdge<SEScalarVolumePerTime, SEScalarVolume, SEScalarVolume, SEScalar0To1>;
template class SESubstanceTransportEdge<SEScalarVolumePerTime, SEScalarVolume, SEScalarMass, SEScalarMassPerVolume>;
template class SESubstanceTransportGraph<SEScalarVolumePerTime, SEScalarVolume, SEScalarVolume, SEScalar0To1>;
template class SESubstanceTransportGraph<SEScalarVolumePerTime, SEScalarVolume, SEScalarMass, SEScalarMassPerVolume>;
template class SESubstanceTransporter<SEGasTransportGraph, VolumePerTimeUnit, VolumeUnit, VolumeUnit, NoUnit>;
template class SESubstanceTransporter<SELiquidTransportGraph, VolumePerTimeUnit, VolumeUnit, MassUnit, MassPerVolumeUnit>;
