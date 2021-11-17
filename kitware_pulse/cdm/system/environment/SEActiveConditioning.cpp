/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/
#include "stdafx.h"
#include "system/environment/SEActiveConditioning.h"
#include "properties/SEScalarArea.h"
#include "properties/SEScalar0To1.h"
#include "properties/SEScalarPower.h"
#include "properties/SEScalarTemperature.h"

SEActiveConditioning::SEActiveConditioning(Logger* logger) : Loggable(logger)
{
  m_Power = nullptr;
  m_SurfaceArea = nullptr;
  m_SurfaceAreaFraction = nullptr;
}

SEActiveConditioning::~SEActiveConditioning()
{

  SAFE_DELETE(m_Power);
  SAFE_DELETE(m_SurfaceArea);
  SAFE_DELETE(m_SurfaceAreaFraction);
}

void SEActiveConditioning::Clear()
{
  INVALIDATE_PROPERTY(m_Power);
  INVALIDATE_PROPERTY(m_SurfaceArea);
  INVALIDATE_PROPERTY(m_SurfaceAreaFraction);
}

const SEScalar* SEActiveConditioning::GetScalar(const std::string& name)
{
  if (name.compare("Power") == 0)
    return &GetPower();
  if (name.compare("SurfaceArea") == 0)
    return &GetSurfaceArea();
  if (name.compare("SurfaceAreaFraction") == 0)
    return &GetSurfaceAreaFraction();
  return nullptr;
}

bool SEActiveConditioning::HasPower() const
{
  return m_Power == nullptr ? false : m_Power->IsValid();
}
SEScalarPower& SEActiveConditioning::GetPower()
{
  if (m_Power == nullptr)
    m_Power = new SEScalarPower();
  return *m_Power;
}
double SEActiveConditioning::GetPower(const PowerUnit& unit) const
{
  if (m_Power == nullptr)
    return SEScalar::dNaN();
  return m_Power->GetValue(unit);
}

bool SEActiveConditioning::HasSurfaceArea() const
{
  return m_SurfaceArea == nullptr ? false : m_SurfaceArea->IsValid();
}
SEScalarArea& SEActiveConditioning::GetSurfaceArea()
{
  if (m_SurfaceArea == nullptr)
    m_SurfaceArea = new SEScalarArea();
  return *m_SurfaceArea;
}
double SEActiveConditioning::GetSurfaceArea(const AreaUnit& unit) const
{
  if (m_SurfaceArea == nullptr)
    return SEScalar::dNaN();
  return m_SurfaceArea->GetValue(unit);
}

bool SEActiveConditioning::HasSurfaceAreaFraction() const
{
  return m_SurfaceAreaFraction == nullptr ? false : m_SurfaceAreaFraction->IsValid();
}
SEScalar0To1& SEActiveConditioning::GetSurfaceAreaFraction()
{
  if (m_SurfaceAreaFraction == nullptr)
    m_SurfaceAreaFraction = new SEScalar0To1();
  return *m_SurfaceAreaFraction;
}
double SEActiveConditioning::GetSurfaceAreaFraction() const
{
  if (m_SurfaceAreaFraction == nullptr)
    return SEScalar::dNaN();
  return m_SurfaceAreaFraction->GetValue();
}

void SEActiveConditioning::ToString(std::ostream &str) const
{
  str << "Active Conditioning :";
  str << "\n\tPower :";                HasPower() ? str << *m_Power : str << "NaN";
  str << "\n\tSurfaceArea :";          HasSurfaceArea() ? str << *m_SurfaceArea : str << "NaN";
  str << "\n\tSurfaceAreaFraction :";  HasSurfaceAreaFraction() ? str << *m_SurfaceAreaFraction : str << "NaN";
  str << std::flush;
}