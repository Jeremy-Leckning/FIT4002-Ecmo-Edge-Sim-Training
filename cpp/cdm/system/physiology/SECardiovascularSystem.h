/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#pragma once
#include "system/SESystem.h"

// Keep enums in sync with appropriate schema/cdm/PhysiologyEnums.proto file !!
enum class eHeartRhythm { NormalSinus = 0, Asystolic };
extern const std::string& eHeartRhythm_Name(eHeartRhythm m);

class CDM_DECL SECardiovascularSystem : public SESystem
{
  friend class PBPhysiology;//friend the serialization class
public:

  SECardiovascularSystem(Logger* logger);
  virtual ~SECardiovascularSystem();

  virtual void Clear();// Deletes all members
  
  virtual const SEScalar* GetScalar(const std::string& name);

  virtual bool HasArterialPressure() const;
  virtual SEScalarPressure& GetArterialPressure();
  virtual double GetArterialPressure(const PressureUnit& unit) const;
  
  virtual bool HasBloodVolume() const;
  virtual SEScalarVolume& GetBloodVolume();
  virtual double GetBloodVolume(const VolumeUnit& unit) const;

  virtual bool HasCardiacIndex() const;
  virtual SEScalarVolumePerTimeArea& GetCardiacIndex();
  virtual double GetCardiacIndex(const VolumePerTimeAreaUnit& unit) const;

  virtual bool HasCardiacOutput() const;
  virtual SEScalarVolumePerTime& GetCardiacOutput();
  virtual double GetCardiacOutput(const VolumePerTimeUnit& unit) const;

  virtual bool HasCentralVenousPressure() const;
  virtual SEScalarPressure& GetCentralVenousPressure();
  virtual double GetCentralVenousPressure(const PressureUnit& unit) const;

  virtual bool HasCerebralBloodFlow() const;
  virtual SEScalarVolumePerTime& GetCerebralBloodFlow();
  virtual double GetCerebralBloodFlow(const VolumePerTimeUnit& unit) const;

  virtual bool HasCerebralPerfusionPressure() const;
  virtual SEScalarPressure& GetCerebralPerfusionPressure();
  virtual double GetCerebralPerfusionPressure(const PressureUnit& unit) const;
  
  virtual bool HasDiastolicArterialPressure() const;
  virtual SEScalarPressure& GetDiastolicArterialPressure();
  virtual double GetDiastolicArterialPressure(const PressureUnit& unit) const;

  virtual bool HasHeartEjectionFraction() const;
  virtual SEScalar0To1& GetHeartEjectionFraction();
  virtual double GetHeartEjectionFraction() const;

  virtual bool HasHeartRate() const;
  virtual SEScalarFrequency& GetHeartRate();
  virtual double GetHeartRate(const FrequencyUnit& unit) const;

  virtual eHeartRhythm GetHeartRhythm() const;
  virtual void SetHeartRhythm(eHeartRhythm Rhythm);

  virtual bool HasHeartStrokeVolume() const;
  virtual SEScalarVolume& GetHeartStrokeVolume();
  virtual double GetHeartStrokeVolume(const VolumeUnit& unit) const;

  virtual bool HasIntracranialPressure() const;
  virtual SEScalarPressure& GetIntracranialPressure();
  virtual double GetIntracranialPressure(const PressureUnit& unit) const;

  virtual bool HasMeanArterialPressure() const;
  virtual SEScalarPressure& GetMeanArterialPressure();
  virtual double GetMeanArterialPressure(const PressureUnit& unit) const;

  virtual bool HasMeanArterialCarbonDioxidePartialPressure() const;
  virtual SEScalarPressure& GetMeanArterialCarbonDioxidePartialPressure();
  virtual double GetMeanArterialCarbonDioxidePartialPressure(const PressureUnit& unit) const;

  virtual bool HasMeanArterialCarbonDioxidePartialPressureDelta() const;
  virtual SEScalarPressure& GetMeanArterialCarbonDioxidePartialPressureDelta();
  virtual double GetMeanArterialCarbonDioxidePartialPressureDelta(const PressureUnit& unit) const;
  
  virtual bool HasMeanCentralVenousPressure() const;
  virtual SEScalarPressure& GetMeanCentralVenousPressure();
  virtual double GetMeanCentralVenousPressure(const PressureUnit& unit) const;

  virtual bool HasMeanSkinFlow() const;
  virtual SEScalarVolumePerTime& GetMeanSkinFlow();
  virtual double GetMeanSkinFlow(const VolumePerTimeUnit& unit) const;

  virtual bool HasPulmonaryArterialPressure() const;
  virtual SEScalarPressure& GetPulmonaryArterialPressure();
  virtual double GetPulmonaryArterialPressure(const PressureUnit& unit) const;

  virtual bool HasPulmonaryCapillariesWedgePressure() const;
  virtual SEScalarPressure& GetPulmonaryCapillariesWedgePressure();
  virtual double GetPulmonaryCapillariesWedgePressure(const PressureUnit& unit) const;

  virtual bool HasPulmonaryDiastolicArterialPressure() const;
  virtual SEScalarPressure& GetPulmonaryDiastolicArterialPressure();
  virtual double GetPulmonaryDiastolicArterialPressure(const PressureUnit& unit) const;

  virtual bool HasPulmonaryMeanArterialPressure() const;
  virtual SEScalarPressure& GetPulmonaryMeanArterialPressure();
  virtual double GetPulmonaryMeanArterialPressure(const PressureUnit& unit) const;

  virtual bool HasPulmonaryMeanCapillaryFlow() const;
  virtual SEScalarVolumePerTime& GetPulmonaryMeanCapillaryFlow();
  virtual double GetPulmonaryMeanCapillaryFlow(const VolumePerTimeUnit& unit) const;

  virtual bool HasPulmonaryMeanShuntFlow() const;
  virtual SEScalarVolumePerTime& GetPulmonaryMeanShuntFlow();
  virtual double GetPulmonaryMeanShuntFlow(const VolumePerTimeUnit& unit) const;

  virtual bool HasPulmonarySystolicArterialPressure() const;
  virtual SEScalarPressure& GetPulmonarySystolicArterialPressure();
  virtual double GetPulmonarySystolicArterialPressure(const PressureUnit& unit) const;

  virtual bool HasPulmonaryVascularResistance() const;
  virtual SEScalarPressureTimePerVolume& GetPulmonaryVascularResistance();
  virtual double GetPulmonaryVascularResistance(const PressureTimePerVolumeUnit& unit) const;

  virtual bool HasPulmonaryVascularResistanceIndex() const;
  virtual SEScalarPressureTimePerVolumeArea& GetPulmonaryVascularResistanceIndex();
  virtual double GetPulmonaryVascularResistanceIndex(const PressureTimePerVolumeAreaUnit& unit) const;

  virtual bool HasPulsePressure() const;
  virtual SEScalarPressure& GetPulsePressure();
  virtual double GetPulsePressure(const PressureUnit& unit) const;

  virtual bool HasSystemicVascularResistance() const;
  virtual SEScalarPressureTimePerVolume& GetSystemicVascularResistance();
  virtual double GetSystemicVascularResistance(const PressureTimePerVolumeUnit& unit) const;

  virtual bool HasSystolicArterialPressure() const;
  virtual SEScalarPressure& GetSystolicArterialPressure();
  virtual double GetSystolicArterialPressure(const PressureUnit& unit) const;

  virtual bool HasTotalHemorrhageRate() const;
  virtual SEScalarVolumePerTime& GetTotalHemorrhageRate();
  virtual double GetTotalHemorrhageRate(const VolumePerTimeUnit& unit) const;

  virtual bool HasTotalHemorrhagedVolume() const;
  virtual SEScalarVolume& GetTotalHemorrhagedVolume();
  virtual double GetTotalHemorrhagedVolume(const VolumeUnit& unit) const;

protected:

  SEScalarPressure*                      m_ArterialPressure;
  SEScalarVolume*                        m_BloodVolume;
  SEScalarVolumePerTimeArea*             m_CardiacIndex;
  SEScalarVolumePerTime*                 m_CardiacOutput;
  SEScalarPressure*                      m_CentralVenousPressure;
  SEScalarVolumePerTime*                 m_CerebralBloodFlow;
  SEScalarPressure*                      m_CerebralPerfusionPressure;
  SEScalarPressure*                      m_DiastolicArterialPressure;
  SEScalar0To1*                          m_HeartEjectionFraction;
  SEScalarFrequency*                     m_HeartRate;
  eHeartRhythm                           m_HeartRhythm;
  SEScalarVolume*                        m_HeartStrokeVolume;
  SEScalarPressure*                      m_IntracranialPressure;
  SEScalarPressure*                      m_MeanArterialPressure;
  SEScalarPressure*                      m_MeanArterialCarbonDioxidePartialPressure;
  SEScalarPressure*                      m_MeanArterialCarbonDioxidePartialPressureDelta;
  SEScalarPressure*                      m_MeanCentralVenousPressure;
  SEScalarVolumePerTime*                 m_MeanSkinFlow;
  SEScalarPressure*                      m_PulmonaryArterialPressure;
  SEScalarPressure*                      m_PulmonaryCapillariesWedgePressure;
  SEScalarPressure*                      m_PulmonaryDiastolicArterialPressure;
  SEScalarPressure*                      m_PulmonaryMeanArterialPressure;
  SEScalarVolumePerTime*                 m_PulmonaryMeanCapillaryFlow;
  SEScalarVolumePerTime*                 m_PulmonaryMeanShuntFlow;
  SEScalarPressure*                      m_PulmonarySystolicArterialPressure;
  SEScalarPressureTimePerVolume*         m_PulmonaryVascularResistance;
  SEScalarPressureTimePerVolumeArea*     m_PulmonaryVascularResistanceIndex;
  SEScalarPressure*                      m_PulsePressure;
  SEScalarPressure*                      m_SystolicArterialPressure;
  SEScalarPressureTimePerVolume*         m_SystemicVascularResistance;
  SEScalarVolumePerTime*                 m_TotalHemorrhageRate;
  SEScalarVolume*                        m_TotalHemorrhagedVolume;
};