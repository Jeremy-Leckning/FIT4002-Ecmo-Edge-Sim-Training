/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/
#pragma once
#include "blackbox/SEBlackBox.h"
#include "compartment/SECompartment.h"
#include "compartment/SECompartmentNodes.h"
#include "circuit/thermal/SEThermalCircuitNode.h"
class SEThermalCircuitNode;
class SEThermalCompartmentLink;

class CDM_DECL SEThermalCompartment : public SECompartment
{
  friend class PBCompartment;//friend the serialization class
  friend class SECompartmentManager;
  template<typename CompartmentType, typename CompartmentLinkType> friend class SECompartmentGraph;
protected:
  SEThermalCompartment(const std::string& name, Logger* logger);
public:
  virtual ~SEThermalCompartment();

  virtual void Clear();

  virtual const SEScalar* GetScalar(const std::string& name);

  virtual bool HasChildren() const { return !m_Children.empty(); }
  virtual const std::vector<SEThermalCompartment*>& GetChildren() { return m_Children; }
  virtual const std::vector<SEThermalCompartment*>& GetLeaves() { return m_Leaves; }

  virtual bool HasNodeMapping() const { return m_Nodes.HasMapping(); }
  virtual  SECompartmentNodes<THERMAL_COMPARTMENT_NODE>& GetNodeMapping() { return m_Nodes; }
  virtual void MapNode(SEThermalCircuitNode& node);

  virtual void StateChange();

  virtual bool HasHeatTransferRateIn() const;
  virtual const SEScalarPower& GetHeatTransferRateIn() const;
  virtual double GetHeatTransferRateIn(const PowerUnit& unit) const;

  virtual bool HasHeatTransferRateOut() const;
  virtual const SEScalarPower& GetHeatTransferRateOut() const;
  virtual double GetHeatTransferRateOut(const PowerUnit& unit) const;

  virtual bool HasHeat() const;
  virtual SEScalarEnergy& GetHeat();
  virtual double GetHeat(const EnergyUnit& unit) const;

  virtual bool HasTemperature() const;
  virtual SEScalarTemperature& GetTemperature();
  virtual double GetTemperature(const TemperatureUnit& unit) const;

  virtual void AddLink(SEThermalCompartmentLink& link);
  virtual void RemoveLink(SEThermalCompartmentLink& link);
  virtual void RemoveLinks();
  virtual const std::vector<SEThermalCompartmentLink*>& GetLinks();

  virtual bool HasChild(const std::string& name);
  virtual void AddChild(SEThermalCompartment& child);

  virtual bool HasBlackBox() const { return m_BlackBox != nullptr; }
  virtual SEThermalBlackBox* GetBlackBox() { return m_BlackBox; }
  virtual const SEThermalBlackBox* GetBlackBox() const { return m_BlackBox; }
  virtual void SetBlackBox(SEThermalBlackBox* bb) { m_BlackBox = bb; }

protected:
  virtual double CalculateInFlow_W() const;
  virtual double CalculateOutFlow_W() const;

  mutable SEScalarPower*       m_HeatTransferRateIn;
  mutable SEScalarPower*       m_HeatTransferRateOut;
  SEScalarEnergy*              m_Heat;
  SEScalarTemperature*         m_Temperature;

  std::vector<SEThermalCompartmentLink*> m_Links;
  std::vector<SEThermalCompartmentLink*> m_IncomingLinks;
  std::vector<SEThermalCompartmentLink*> m_OutgoingLinks;

  std::vector<SEThermalCompartment*> m_Children;
  std::vector<SEThermalCompartment*> m_Leaves;
  SECompartmentNodes<THERMAL_COMPARTMENT_NODE>  m_Nodes;

  SEThermalBlackBox* m_BlackBox = nullptr;
};