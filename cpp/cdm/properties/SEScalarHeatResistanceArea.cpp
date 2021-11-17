/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#include "stdafx.h"
#include "properties/SEScalarHeatResistanceArea.h"

const HeatResistanceAreaUnit HeatResistanceAreaUnit::rsi("rsi");
const HeatResistanceAreaUnit HeatResistanceAreaUnit::clo("clo");
const HeatResistanceAreaUnit HeatResistanceAreaUnit::rValue("rValue");
const HeatResistanceAreaUnit HeatResistanceAreaUnit::tog("tog");

bool HeatResistanceAreaUnit::IsValidUnit(const std::string& unit)
{
  if (rsi.GetString().compare(unit) == 0)
    return true;
  if (clo.GetString().compare(unit) == 0)
    return true;
  if (rValue.GetString().compare(unit) == 0)
    return true;
  if (tog.GetString().compare(unit) == 0)
    return true;
  return false;
}

const HeatResistanceAreaUnit& HeatResistanceAreaUnit::GetCompoundUnit(const std::string& unit)
{
  if (rsi.GetString().compare(unit) == 0)
    return rsi;
  if (clo.GetString().compare(unit) == 0)
    return clo;
  if (rValue.GetString().compare(unit) == 0)
    return rValue;
  if (tog.GetString().compare(unit) == 0)
    return tog;
  throw CommonDataModelException(unit + " is not a valid HeatResistanceArea unit");
}
