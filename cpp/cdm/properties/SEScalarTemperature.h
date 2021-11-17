/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#pragma once
#include "properties/SEScalar.h"

class CDM_DECL TemperatureUnit : public CCompoundUnit
{
public:
  TemperatureUnit(const std::string& u) : CCompoundUnit(u) {}
  virtual ~TemperatureUnit() {}

  static bool IsValidUnit(const std::string& unit);
  static const TemperatureUnit& GetCompoundUnit(const std::string& unit);

  static const TemperatureUnit F;
  static const TemperatureUnit C;
  static const TemperatureUnit K;
  static const TemperatureUnit R;
};

class CDM_DECL SEScalarTemperature : public SEScalarQuantity<TemperatureUnit>
{
public:
  SEScalarTemperature() {}
  virtual ~SEScalarTemperature() {}

  double GetValue(const TemperatureUnit& unit) const;// Zero is not Zero for all units, gotta remove that logic for this scalar type
};
