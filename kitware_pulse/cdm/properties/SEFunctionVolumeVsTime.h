/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#pragma once
#include "properties/SEFunction.h"

class CDM_DECL SEFunctionVolumeVsTime : public SEFunction
{
  friend class PBProperty;//friend the serialization class
public:

  SEFunctionVolumeVsTime();
  virtual ~SEFunctionVolumeVsTime();

  virtual void Clear();

  double                       GetIndependentValue(size_t index) = delete;
  virtual double               GetTimeValue(size_t index, const TimeUnit& unit);
  virtual std::vector<double>& GetTime();
  virtual const TimeUnit*      GetTimeUnit();
  virtual void                 SetTimeUnit(const TimeUnit& unit);

  double                       GetDependentValue(size_t index) = delete;
  virtual double               GetVolumeValue(size_t index, const VolumeUnit& unit);
  virtual std::vector<double>& GetVolume();
  virtual const VolumeUnit*    GetVolumeUnit();
  virtual void                 SetVolumeUnit(const VolumeUnit& unit);

protected:

  const TimeUnit*   m_TimeUnit;
  const VolumeUnit* m_VolumeUnit;
};