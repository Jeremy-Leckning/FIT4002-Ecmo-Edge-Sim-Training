/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#include "stdafx.h"
#include "properties/SEScalarLengthPerTimePressure.h"

const LengthPerTimePressureUnit LengthPerTimePressureUnit::m_Per_s_mmHg("m/s mmHg");
const LengthPerTimePressureUnit LengthPerTimePressureUnit::cm_Per_s_mmHg("cm/s mmHg");
const LengthPerTimePressureUnit LengthPerTimePressureUnit::m_Per_min_mmHg("m/min mmHg");
const LengthPerTimePressureUnit LengthPerTimePressureUnit::cm_Per_min_mmHg("cm/min mmHg");

bool LengthPerTimePressureUnit::IsValidUnit(const std::string& unit)
{
  if (m_Per_s_mmHg.GetString().compare(unit) == 0)
    return true;
  if (cm_Per_s_mmHg.GetString().compare(unit) == 0)
    return true;
  if (m_Per_min_mmHg.GetString().compare(unit) == 0)
    return true;
  if (cm_Per_min_mmHg.GetString().compare(unit) == 0)
    return true;
  return false;
}

const LengthPerTimePressureUnit& LengthPerTimePressureUnit::GetCompoundUnit(const std::string& unit)
{
  if (m_Per_s_mmHg.GetString().compare(unit) == 0)
    return m_Per_s_mmHg;
  if (cm_Per_s_mmHg.GetString().compare(unit) == 0)
    return cm_Per_s_mmHg;
  if (m_Per_min_mmHg.GetString().compare(unit) == 0)
    return m_Per_min_mmHg;
  if (cm_Per_min_mmHg.GetString().compare(unit) == 0)
    return cm_Per_min_mmHg;
  throw CommonDataModelException(unit + " is not a valid LengthPerTimePressure unit");
}
