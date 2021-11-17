/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#pragma once
#include "patient/assessments/SEPatientAssessment.h"
class SEPatient;
class SERespiratorySystem;

class CDM_DECL SEPulmonaryFunctionTest : public SEPatientAssessment
{
  friend class PBPatientAssessment;//friend the serialization class
public:

  SEPulmonaryFunctionTest(Logger* logger);
  virtual ~SEPulmonaryFunctionTest();

  virtual void Clear();

  bool SerializeToString(std::string& output, SerializationFormat m) const;
  bool SerializeToFile(const std::string& filename) const;

  virtual int GetNumberOfPlotPoints(){ return m_NumberOfPlotPoints; }
  virtual void SetNumberOfPlotPoints(int n){ m_NumberOfPlotPoints = n; }

  virtual bool HasExpiratoryReserveVolume() const;
  virtual SEScalarVolume& GetExpiratoryReserveVolume();
  virtual double GetExpiratoryReserveVolume(const VolumeUnit& unit) const;

  virtual bool HasForcedVitalCapacity() const;
  virtual SEScalarVolume&  GetForcedVitalCapacity();
  virtual double GetForcedVitalCapacity(const VolumeUnit& unit) const;

  virtual bool HasForcedExpiratoryVolume() const;
  virtual SEScalarVolume&  GetForcedExpiratoryVolume();
  virtual double GetForcedExpiratoryVolume(const VolumeUnit& unit) const;

  virtual bool HasForcedExpiratoryFlow() const;
  virtual SEScalarVolumePerTime&  GetForcedExpiratoryFlow();
  virtual double GetForcedExpiratoryFlow(const VolumePerTimeUnit& unit) const;

  virtual bool HasFunctionalResidualCapacity() const;
  virtual SEScalarVolume&  GetFunctionalResidualCapacity();
  virtual double GetFunctionalResidualCapacity(const VolumeUnit& unit) const;

  virtual bool HasInspiratoryCapacity() const;
  virtual SEScalarVolume&  GetInspiratoryCapacity();
  virtual double GetInspiratoryCapacity(const VolumeUnit& unit) const;

  virtual bool HasInspiratoryReserveVolume() const;
  virtual SEScalarVolume& GetInspiratoryReserveVolume();
  virtual double GetInspiratoryReserveVolume(const VolumeUnit& unit) const;

  virtual bool HasMaximumVoluntaryVentilation() const;
  virtual SEScalarVolume& GetMaximumVoluntaryVentilation();
  virtual double GetMaximumVoluntaryVentilation(const VolumeUnit& unit) const;

  virtual bool HasPeakExpiratoryFlow() const;
  virtual SEScalarVolumePerTime&  GetPeakExpiratoryFlow();
  virtual double GetPeakExpiratoryFlow(const VolumePerTimeUnit& unit) const;

  virtual bool HasResidualVolume() const;
  virtual SEScalarVolume&  GetResidualVolume();
  virtual double GetResidualVolume(const VolumeUnit& unit) const;

  virtual bool HasSlowVitalCapacity() const;
  virtual SEScalarVolume&  GetSlowVitalCapacity();
  virtual double GetSlowVitalCapacity(const VolumeUnit& unit) const;

  virtual bool HasTotalLungCapacity() const;
  virtual SEScalarVolume&  GetTotalLungCapacity();
  virtual double GetTotalLungCapacity(const VolumeUnit& unit) const;

  virtual bool HasVitalCapacity() const;
  virtual SEScalarVolume&  GetVitalCapacity();
  virtual double GetVitalCapacity(const VolumeUnit& unit) const;

  virtual bool HasLungVolumePlot() const;
  virtual SEFunctionVolumeVsTime&  GetLungVolumePlot();
  virtual const SEFunctionVolumeVsTime* GetLungVolumePlot() const;

protected:

  int                      m_NumberOfPlotPoints;
  SEScalarVolume*          m_ExpiratoryReserveVolume;
  SEScalarVolume*          m_ForcedVitalCapacity;
  SEScalarVolume*          m_ForcedExpiratoryVolume;
  SEScalarVolumePerTime*   m_ForcedExpiratoryFlow;
  SEScalarVolume*          m_FunctionalResidualCapacity;
  SEScalarVolume*          m_InspiratoryCapacity;
  SEScalarVolume*          m_InspiratoryReserveVolume;
  SEScalarVolume*          m_MaximumVoluntaryVentilation;
  SEScalarVolumePerTime*   m_PeakExpiratoryFlow;
  SEScalarVolume*          m_ResidualVolume;
  SEScalarVolume*          m_SlowVitalCapacity;
  SEScalarVolume*          m_TotalLungCapacity;
  SEScalarVolume*          m_VitalCapacity;
  
  SEFunctionVolumeVsTime*  m_LungVolumePlot;
};  