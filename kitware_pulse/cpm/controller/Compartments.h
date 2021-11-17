/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#pragma once
class PulseData;
#include "compartment/SECompartmentManager.h"

/**
* @brief Manages all compartments and graphs associated with all %Pulse systems/equipement
*/
class PULSE_DECL PulseCompartments : public SECompartmentManager
{
  friend class PulseSubstances;
public:

  PulseCompartments(PulseData& data);
  virtual ~PulseCompartments();

  virtual void Clear();

  virtual void StateChange();
  virtual void UpdateAirwayGraph() { m_UpdateActiveAirwayGraph = true; m_UpdateActiveAerosolGraph = true; }

  virtual SELiquidCompartmentGraph& GetActiveCardiovascularGraph();
  virtual SELiquidCompartmentGraph& GetCardiovascularGraph();
  virtual SELiquidCompartmentGraph& GetRenalGraph();

  virtual SEGasCompartmentGraph&    GetActiveRespiratoryGraph();
  virtual SEGasCompartmentGraph&    GetRespiratoryGraph();
  virtual SEGasCompartmentGraph&    GetRespiratoryAndAnesthesiaMachineGraph();
  virtual SEGasCompartmentGraph&    GetRespiratoryAndInhalerGraph();
  virtual SEGasCompartmentGraph&    GetRespiratoryAndNasalCannulaGraph();
  virtual SEGasCompartmentGraph&    GetRespiratoryAndSimpleMaskGraph();
  virtual SEGasCompartmentGraph&    GetRespiratoryAndNonRebreatherMaskGraph();
  virtual SEGasCompartmentGraph&    GetRespiratoryAndMechanicalVentilationGraph();
  virtual SEGasCompartmentGraph&    GetRespiratoryAndMechanicalVentilatorGraph();

  virtual SEGasCompartmentGraph&    GetAnesthesiaMachineGraph();
  virtual SEGasCompartmentGraph&    GetMechanicalVentilatorGraph();

  virtual SELiquidCompartmentGraph& GetActiveAerosolGraph();
  virtual SELiquidCompartmentGraph& GetAerosolGraph();
  virtual SELiquidCompartmentGraph& GetAerosolAndInhalerGraph();
  virtual SELiquidCompartmentGraph& GetAerosolAndMechanicalVentilationGraph();
  virtual SELiquidCompartmentGraph& GetAerosolAndMechanicalVentilatorGraph();

  // Compartment Helpers  
  std::vector<SELiquidCompartment*>const& GetAerosolCompartments() { return m_AerosolCompartments; }
  std::vector<SELiquidCompartment*>const& GetAerosolLeafCompartments() { return m_AerosolLeafCompartments; }

  std::vector<SELiquidCompartment*>const& GetChymeCompartments() { return m_ChymeCompartments; }
  std::vector<SELiquidCompartment*>const& GetChymeLeafCompartments() { return m_ChymeLeafCompartments; }

  std::vector<SEGasCompartment*>const& GetPulmonaryCompartments() { return m_PulmonaryCompartments; }
  std::vector<SEGasCompartment*>const& GetPulmonaryLeafCompartments() { return m_PulmonaryLeafCompartments; }

  std::vector<SEThermalCompartment*>const& GetTemperatureCompartments() { return m_TemperatureCompartments; }
  std::vector<SEThermalCompartment*>const& GetTemperatureLeafCompartments() { return m_TemperatureLeafCompartments; }

  std::vector<SETissueCompartment*>const& GetTissueCompartments() { return m_TissueCompartments; }
  std::vector<SETissueCompartment*>const& GetTissueLeafCompartments() { return m_TissueLeafCompartments; }

  std::vector<SELiquidCompartment*>const& GetUrineCompartments() { return m_UrineCompartments; }
  std::vector<SELiquidCompartment*>const& GetUrineLeafCompartments() { return m_UrineLeafCompartments; }

  std::vector<SELiquidCompartment*>const& GetVascularCompartments() { return m_VascularCompartments; }
  std::vector<SELiquidCompartment*>const& GetVascularLeafCompartments() { return m_VascularLeafCompartments; }

  std::vector<SEGasCompartment*>const& GetAnesthesiaMachineCompartments() { return m_AnesthesiaMachineCompartments; }
  std::vector<SEGasCompartment*>const& GetAnesthesiaMachineLeafCompartments() { return m_AnesthesiaMachineLeafCompartments; }

  std::vector<SEGasCompartment*>const& GetInhalerCompartments() { return m_InhalerCompartments; }
  std::vector<SEGasCompartment*>const& GetInhalerLeafCompartments() { return m_InhalerLeafCompartments; }

  std::vector<SELiquidCompartment*>const& GetInhalerAerosolCompartments() { return m_InhalerAerosolCompartments; }
  std::vector<SELiquidCompartment*>const& GetInhalerAerosolLeafCompartments() { return m_InhalerAerosolLeafCompartments; }

  std::vector<SEGasCompartment*>const& GetMechanicalVentilationCompartments() { return m_MechanicalVentilationCompartments; }
  std::vector<SEGasCompartment*>const& GetMechanicalVentilationLeafCompartments() { return m_MechanicalVentilationLeafCompartments; }

  std::vector<SELiquidCompartment*>const& GetMechanicalVentilationAerosolCompartments() { return m_MechanicalVentilationAerosolCompartments; }
  std::vector<SELiquidCompartment*>const& GetMechanicalVentilationAerosolLeafCompartments() { return m_MechanicalVentilationAerosolCompartments; }

  std::vector<SEGasCompartment*>const& GetMechanicalVentilatorCompartments() { return m_MechanicalVentilatorCompartments; }
  std::vector<SEGasCompartment*>const& GetMechanicalVentilatorLeafCompartments() { return m_MechanicalVentilatorLeafCompartments; }

  std::vector<SELiquidCompartment*>const& GetMechanicalVentilatorAerosolCompartments() { return m_MechanicalVentilatorAerosolCompartments; }
  std::vector<SELiquidCompartment*>const& GetMechanicalVentilatorAerosolLeafCompartments() { return m_MechanicalVentilatorAerosolCompartments; }

  std::vector<SEGasCompartment*>const& GetNasalCannulaCompartments() { return m_NasalCannulaCompartments; }
  std::vector<SEGasCompartment*>const& GetNasalCannulaLeafCompartments() { return m_NasalCannulaLeafCompartments; }

  std::vector<SEGasCompartment*>const& GetNonRebreatherMaskCompartments() { return m_NonRebreatherMaskCompartments; }
  std::vector<SEGasCompartment*>const& GetNonRebreatherMaskLeafCompartments() { return m_NonRebreatherMaskLeafCompartments; }

  std::vector<SEGasCompartment*>const& GetSimpleMaskCompartments() { return m_SimpleMaskCompartments; }
  std::vector<SEGasCompartment*>const& GetSimpleMaskLeafCompartments() { return m_SimpleMaskLeafCompartments; }


  SELiquidCompartment& GetExtracellularFluid(SETissueCompartment& t) { return *m_ExtracellularFluid[&t]; }
  SELiquidCompartment& GetIntracellularFluid(SETissueCompartment& t) { return *m_IntracellularFluid[&t]; }
  std::map<SETissueCompartment*, SELiquidCompartment*>const& GetExtracellularFluid() { return m_ExtracellularFluid; }
  std::map<SETissueCompartment*, SELiquidCompartment*>const& GetIntracellularFluid() { return m_IntracellularFluid; }

protected:
  // I don't want these exposed in Pulse, you should be calling the Substance manager
  virtual void AddGasCompartmentSubstance(SESubstance& sub);
  virtual void AddLiquidCompartmentSubstance(SESubstance& sub);
  
  virtual bool AllowGasSubstance(SESubstance& s, SEGasCompartment& cmpt) const;
  virtual bool AllowLiquidSubstance(SESubstance& s, SELiquidCompartment& cmpt) const;

  PulseData& m_data;

  bool m_UpdateActiveAirwayGraph;
  bool m_UpdateActiveAerosolGraph;

  SELiquidCompartmentGraph*   m_CombinedCardiovascularGraph;
  SELiquidCompartmentGraph*   m_CardiovascularGraph;
  SELiquidCompartmentGraph*   m_RenalGraph;

  SEGasCompartmentGraph*     m_RespiratoryGraph;
  SEGasCompartmentGraph*     m_CombinedRespiratoryAnesthesiaGraph;
  SEGasCompartmentGraph*     m_CombinedRespiratoryInhalerGraph;
  SEGasCompartmentGraph*     m_CombinedRespiratoryNasalCannulaGraph;
  SEGasCompartmentGraph*     m_CombinedRespiratorySimpleMaskGraph;
  SEGasCompartmentGraph*     m_CombinedRespiratoryNonRebreatherMaskGraph;
  SEGasCompartmentGraph*     m_CombinedRespiratoryMechanicalVentilationGraph;
  SEGasCompartmentGraph*     m_CombinedRespiratoryMechanicalVentilatorGraph;
  SEGasCompartmentGraph*     m_AnesthesiaMachineGraph;
  SEGasCompartmentGraph*     m_MechanicalVentilatorGraph;

  SELiquidCompartmentGraph*  m_AerosolGraph;
  SELiquidCompartmentGraph*  m_CombinedAerosolInhalerGraph;
  SELiquidCompartmentGraph*  m_CombinedAerosolMechanicalVentilationGraph;
  SELiquidCompartmentGraph*  m_CombinedAerosolMechanicalVentilatorGraph;

  std::vector<SELiquidCompartment*>  m_AerosolCompartments;
  std::vector<SELiquidCompartment*>  m_AerosolLeafCompartments;
  std::vector<SELiquidCompartment*>  m_ChymeCompartments;
  std::vector<SELiquidCompartment*>  m_ChymeLeafCompartments;
  std::vector<SEGasCompartment*>     m_PulmonaryCompartments;
  std::vector<SEGasCompartment*>     m_PulmonaryLeafCompartments;
  std::vector<SEThermalCompartment*> m_TemperatureCompartments;
  std::vector<SEThermalCompartment*> m_TemperatureLeafCompartments;
  std::vector<SETissueCompartment*>  m_TissueCompartments;
  std::vector<SETissueCompartment*>  m_TissueLeafCompartments;
  std::vector<SELiquidCompartment*>  m_UrineCompartments;
  std::vector<SELiquidCompartment*>  m_UrineLeafCompartments;
  std::vector<SELiquidCompartment*>  m_VascularCompartments;
  std::vector<SELiquidCompartment*>  m_VascularLeafCompartments;
  std::vector<SEGasCompartment*>     m_AnesthesiaMachineCompartments;
  std::vector<SEGasCompartment*>     m_AnesthesiaMachineLeafCompartments;
  std::vector<SEGasCompartment*>     m_InhalerCompartments;
  std::vector<SEGasCompartment*>     m_InhalerLeafCompartments;
  std::vector<SELiquidCompartment*>  m_InhalerAerosolCompartments;
  std::vector<SELiquidCompartment*>  m_InhalerAerosolLeafCompartments;
  std::vector<SEGasCompartment*>     m_MechanicalVentilationCompartments;
  std::vector<SEGasCompartment*>     m_MechanicalVentilationLeafCompartments;
  std::vector<SELiquidCompartment*>  m_MechanicalVentilationAerosolCompartments;
  std::vector<SELiquidCompartment*>  m_MechanicalVentilationAerosolLeafCompartments;
  std::vector<SEGasCompartment*>     m_MechanicalVentilatorCompartments;
  std::vector<SEGasCompartment*>     m_MechanicalVentilatorLeafCompartments;
  std::vector<SELiquidCompartment*>  m_MechanicalVentilatorAerosolCompartments;
  std::vector<SELiquidCompartment*>  m_MechanicalVentilatorAerosolLeafCompartments;
  std::vector<SEGasCompartment*>     m_NasalCannulaCompartments;
  std::vector<SEGasCompartment*>     m_NasalCannulaLeafCompartments;
  std::vector<SEGasCompartment*>     m_NonRebreatherMaskCompartments;
  std::vector<SEGasCompartment*>     m_NonRebreatherMaskLeafCompartments;
  std::vector<SEGasCompartment*>     m_SimpleMaskCompartments;
  std::vector<SEGasCompartment*>     m_SimpleMaskLeafCompartments;

  std::map<SETissueCompartment*, SELiquidCompartment*> m_ExtracellularFluid;
  std::map<SETissueCompartment*, SELiquidCompartment*> m_IntracellularFluid;
};