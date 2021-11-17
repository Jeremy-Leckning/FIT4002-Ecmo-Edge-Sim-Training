/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#include "stdafx.h"
#include "compartment/tissue/SETissueCompartment.h"
#include "compartment/fluid/SELiquidCompartment.h"
#include "compartment/fluid/SELiquidCompartmentLink.h"
#include "substance/SESubstanceManager.h"
#include "properties/SEScalar0To1.h"
#include "properties/SEScalarMass.h"
#include "properties/SEScalarMassPerMass.h"
#include "properties/SEScalarVolumePerTime.h"
#include "properties/SEScalarPressure.h"
#include "properties/SEScalarVolume.h"

SETissueCompartment::SETissueCompartment(const std::string& name, Logger* logger) : SECompartment(name, logger)
{
  m_AcidicPhospohlipidConcentration = nullptr;
  m_MatrixVolume = nullptr;
  m_NeutralLipidsVolumeFraction = nullptr;
  m_NeutralPhospholipidsVolumeFraction = nullptr;
  m_TissueToPlasmaAlbuminRatio = nullptr;
  m_TissueToPlasmaAlphaAcidGlycoproteinRatio = nullptr;
  m_TissueToPlasmaLipoproteinRatio = nullptr;
  m_TotalMass = nullptr;
}

SETissueCompartment::~SETissueCompartment()
{
  Clear();
}

void SETissueCompartment::Clear()
{
  SECompartment::Clear();
  SAFE_DELETE(m_AcidicPhospohlipidConcentration);
  SAFE_DELETE(m_MatrixVolume);
  SAFE_DELETE(m_NeutralLipidsVolumeFraction);
  SAFE_DELETE(m_NeutralPhospholipidsVolumeFraction);
  SAFE_DELETE(m_TissueToPlasmaAlbuminRatio);
  SAFE_DELETE(m_TissueToPlasmaAlphaAcidGlycoproteinRatio);
  SAFE_DELETE(m_TissueToPlasmaLipoproteinRatio);
  SAFE_DELETE(m_TotalMass);
}

const SEScalar* SETissueCompartment::GetScalar(const std::string& name)
{
  if (name.compare("AcidicPhospohlipidConcentration") == 0)
    return &GetAcidicPhospohlipidConcentration();
  if (name.compare("MatrixVolume") == 0)
    return &GetMatrixVolume();  
  if (name.compare("NeutralLipidsVolumeFraction") == 0)
    return &GetNeutralLipidsVolumeFraction();
  if (name.compare("NeutralPhospholipidsVolumeFraction") == 0)
    return &GetNeutralPhospholipidsVolumeFraction();
  if (name.compare("TissueToPlasmaAlbuminRatio") == 0)
    return &GetTissueToPlasmaAlbuminRatio();
  if (name.compare("TissueToPlasmaAlphaAcidGlycoproteinRatio") == 0)
    return &GetTissueToPlasmaAlphaAcidGlycoproteinRatio();
  if (name.compare("TissueToPlasmaLipoproteinRatio") == 0)
    return &GetTissueToPlasmaLipoproteinRatio();
  if (name.compare("TotalMass") == 0)
    return &GetTotalMass();
  return nullptr;
}

void SETissueCompartment::StateChange()
{
 
}

bool SETissueCompartment::HasAcidicPhospohlipidConcentration() const
{
  return m_AcidicPhospohlipidConcentration == nullptr ? false : m_AcidicPhospohlipidConcentration->IsValid();
}
SEScalarMassPerMass& SETissueCompartment::GetAcidicPhospohlipidConcentration()
{
  if (m_AcidicPhospohlipidConcentration == nullptr)
    m_AcidicPhospohlipidConcentration = new SEScalarMassPerMass();
  return *m_AcidicPhospohlipidConcentration;
}
double SETissueCompartment::GetAcidicPhospohlipidConcentration(const MassPerMassUnit& unit) const
{
  if (m_AcidicPhospohlipidConcentration == nullptr)
    return SEScalar::dNaN();
  return m_AcidicPhospohlipidConcentration->GetValue(unit);
}

bool SETissueCompartment::HasMatrixVolume() const
{
  return m_MatrixVolume == nullptr ? false : m_MatrixVolume->IsValid();
}
SEScalarVolume& SETissueCompartment::GetMatrixVolume()
{
  if (m_MatrixVolume == nullptr)
    m_MatrixVolume = new SEScalarVolume();
  return *m_MatrixVolume;
}
double SETissueCompartment::GetMatrixVolume(const VolumeUnit& unit) const
{
  if (m_MatrixVolume == nullptr)
    return SEScalar::dNaN();
  return m_MatrixVolume->GetValue(unit);
}

bool SETissueCompartment::HasNeutralLipidsVolumeFraction() const
{
  return m_NeutralLipidsVolumeFraction == nullptr ? false : m_NeutralLipidsVolumeFraction->IsValid();
}
SEScalar0To1& SETissueCompartment::GetNeutralLipidsVolumeFraction()
{
  if (m_NeutralLipidsVolumeFraction == nullptr)
    m_NeutralLipidsVolumeFraction = new SEScalar0To1();
  return *m_NeutralLipidsVolumeFraction;
}
double SETissueCompartment::GetNeutralLipidsVolumeFraction() const
{
  if (m_NeutralLipidsVolumeFraction == nullptr)
    return SEScalar::dNaN();
  return m_NeutralLipidsVolumeFraction->GetValue();
}

bool SETissueCompartment::HasNeutralPhospholipidsVolumeFraction() const
{
  return m_NeutralPhospholipidsVolumeFraction == nullptr ? false : m_NeutralPhospholipidsVolumeFraction->IsValid();
}
SEScalar0To1& SETissueCompartment::GetNeutralPhospholipidsVolumeFraction()
{
  if (m_NeutralPhospholipidsVolumeFraction == nullptr)
    m_NeutralPhospholipidsVolumeFraction = new SEScalar0To1();
  return *m_NeutralPhospholipidsVolumeFraction;
}
double SETissueCompartment::GetNeutralPhospholipidsVolumeFraction() const
{
  if (m_NeutralPhospholipidsVolumeFraction == nullptr)
    return SEScalar::dNaN();
  return m_NeutralPhospholipidsVolumeFraction->GetValue();
}

bool SETissueCompartment::HasTissueToPlasmaAlbuminRatio() const
{
  return m_TissueToPlasmaAlbuminRatio == nullptr ? false : m_TissueToPlasmaAlbuminRatio->IsValid();
}
SEScalar& SETissueCompartment::GetTissueToPlasmaAlbuminRatio()
{
  if (m_TissueToPlasmaAlbuminRatio == nullptr)
    m_TissueToPlasmaAlbuminRatio = new SEScalar();
  return *m_TissueToPlasmaAlbuminRatio;
}
double SETissueCompartment::GetTissueToPlasmaAlbuminRatio() const
{
  if (m_TissueToPlasmaAlbuminRatio == nullptr)
    return SEScalar::dNaN();
  return m_TissueToPlasmaAlbuminRatio->GetValue();
}

bool SETissueCompartment::HasTissueToPlasmaAlphaAcidGlycoproteinRatio() const
{
  return m_TissueToPlasmaAlphaAcidGlycoproteinRatio == nullptr ? false : m_TissueToPlasmaAlphaAcidGlycoproteinRatio->IsValid();
}
SEScalar& SETissueCompartment::GetTissueToPlasmaAlphaAcidGlycoproteinRatio()
{
  if (m_TissueToPlasmaAlphaAcidGlycoproteinRatio == nullptr)
    m_TissueToPlasmaAlphaAcidGlycoproteinRatio = new SEScalar();
  return *m_TissueToPlasmaAlphaAcidGlycoproteinRatio;
}
double SETissueCompartment::GetTissueToPlasmaAlphaAcidGlycoproteinRatio() const
{
  if (m_TissueToPlasmaAlphaAcidGlycoproteinRatio == nullptr)
    return SEScalar::dNaN();
  return m_TissueToPlasmaAlphaAcidGlycoproteinRatio->GetValue();
}

bool SETissueCompartment::HasTissueToPlasmaLipoproteinRatio() const
{
  return m_TissueToPlasmaLipoproteinRatio == nullptr ? false : m_TissueToPlasmaLipoproteinRatio->IsValid();
}
SEScalar& SETissueCompartment::GetTissueToPlasmaLipoproteinRatio()
{
  if (m_TissueToPlasmaLipoproteinRatio == nullptr)
    m_TissueToPlasmaLipoproteinRatio = new SEScalar();
  return *m_TissueToPlasmaLipoproteinRatio;
}
double SETissueCompartment::GetTissueToPlasmaLipoproteinRatio() const
{
  if (m_TissueToPlasmaLipoproteinRatio == nullptr)
    return SEScalar::dNaN();
  return m_TissueToPlasmaLipoproteinRatio->GetValue();
}

bool SETissueCompartment::HasTotalMass() const
{
  return m_TotalMass == nullptr ? false : m_TotalMass->IsValid();
}
SEScalarMass& SETissueCompartment::GetTotalMass()
{
  if (m_TotalMass == nullptr)
    m_TotalMass = new SEScalarMass();  
  return *m_TotalMass;
}
double SETissueCompartment::GetTotalMass(const MassUnit& unit) const
{
  if (m_TotalMass == nullptr)
    return SEScalar::dNaN();
  return m_TotalMass->GetValue(unit);
}