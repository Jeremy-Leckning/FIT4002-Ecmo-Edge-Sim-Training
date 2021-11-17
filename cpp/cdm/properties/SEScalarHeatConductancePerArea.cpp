/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#include "stdafx.h"
#include "properties/SEScalarHeatConductancePerArea.h"

const HeatConductancePerAreaUnit HeatConductancePerAreaUnit::W_Per_m2_K("W/m^2 K");
const HeatConductancePerAreaUnit HeatConductancePerAreaUnit::W_Per_m2_C("W/m^2 degC");
const HeatConductancePerAreaUnit HeatConductancePerAreaUnit::BTU_Per_hr_ft2_C("BTU/hr ft^2 degC");

bool HeatConductancePerAreaUnit::IsValidUnit(const std::string& unit)
{
  if (W_Per_m2_K.GetString().compare(unit) == 0)
    return true;
  if (W_Per_m2_C.GetString().compare(unit) == 0)
    return true;
  if (BTU_Per_hr_ft2_C.GetString().compare(unit) == 0)
    return true;
  return false;
}

const HeatConductancePerAreaUnit& HeatConductancePerAreaUnit::GetCompoundUnit(const std::string& unit)
{
  if (W_Per_m2_K.GetString().compare(unit) == 0)
    return W_Per_m2_K;
  if (W_Per_m2_C.GetString().compare(unit) == 0)
    return W_Per_m2_C;
  if (BTU_Per_hr_ft2_C.GetString().compare(unit) == 0)
    return BTU_Per_hr_ft2_C;
  throw CommonDataModelException(unit + " is not a valid HeatConductancePerArea unit");
}
