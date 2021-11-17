/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#include "stdafx.h"
#include "substance/SESubstancePharmacodynamics.h"
#include "system/physiology/SEPupillaryResponse.h"
#include "properties/SEScalarNegative1To1.h"
#include "properties/SEScalarMassPerVolume.h"

SESubstancePharmacodynamics::SESubstancePharmacodynamics(Logger* logger) : Loggable(logger)
{
  m_Bronchodilation = nullptr;
  m_DiastolicPressureModifier = nullptr;
  m_EC50 = nullptr;
  m_EMaxShapeParameter = nullptr;
  m_HeartRateModifier = nullptr;
  m_NeuromuscularBlock = nullptr;
  m_PupillaryResponse = nullptr;
  m_RespirationRateModifier = nullptr;
  m_Sedation = nullptr;
  m_SystolicPressureModifier = nullptr;
  m_TidalVolumeModifier = nullptr;
  m_TubularPermeabilityModifier = nullptr;
}

SESubstancePharmacodynamics::~SESubstancePharmacodynamics() 
{
  SAFE_DELETE(m_Bronchodilation);
  SAFE_DELETE(m_DiastolicPressureModifier);
  SAFE_DELETE(m_EC50);
  SAFE_DELETE(m_EMaxShapeParameter);
  SAFE_DELETE(m_HeartRateModifier);
  SAFE_DELETE(m_NeuromuscularBlock);
  SAFE_DELETE(m_PupillaryResponse);
  SAFE_DELETE(m_RespirationRateModifier);
  SAFE_DELETE(m_Sedation);
  SAFE_DELETE(m_SystolicPressureModifier);
  SAFE_DELETE(m_TidalVolumeModifier);
  SAFE_DELETE(m_TubularPermeabilityModifier);
}

void SESubstancePharmacodynamics::Clear()
{
  INVALIDATE_PROPERTY(m_Bronchodilation);
  INVALIDATE_PROPERTY(m_DiastolicPressureModifier);
  INVALIDATE_PROPERTY(m_EC50);
  INVALIDATE_PROPERTY(m_EMaxShapeParameter);
  INVALIDATE_PROPERTY(m_HeartRateModifier);
  INVALIDATE_PROPERTY(m_NeuromuscularBlock);
  if(m_PupillaryResponse!=nullptr)
    m_PupillaryResponse->Clear();
  INVALIDATE_PROPERTY(m_RespirationRateModifier);
  INVALIDATE_PROPERTY(m_Sedation);
  INVALIDATE_PROPERTY(m_SystolicPressureModifier);
  INVALIDATE_PROPERTY(m_TidalVolumeModifier);
  INVALIDATE_PROPERTY(m_TubularPermeabilityModifier);
}

bool SESubstancePharmacodynamics::IsValid() const
{
  if (!HasBronchodilation())
    return false;
  if (!HasDiastolicPressureModifier())
    return false;
  if (!HasEC50())
    return false;
  if (!HasEMaxShapeParameter())
    return false;
  if (!HasHeartRateModifier())
    return false;
  if (!HasNeuromuscularBlock())
    return false;
  if (!HasPupillaryResponse())
    return false;
  if (!HasRespirationRateModifier())
    return false;
  if (!HasSedation())
    return false;
  if (!HasSystolicPressureModifier())
    return false;
  if (!HasTidalVolumeModifier())
    return false;
  if (!HasTubularPermeabilityModifier())
    return false;
  return true;
}

const SEScalar* SESubstancePharmacodynamics::GetScalar(const std::string& name)
{
  if (name.compare("Bronchodilation") == 0)
    return &GetBronchodilation();
  if (name.compare("DiastolicPressureModifier") == 0)
    return &GetDiastolicPressureModifier();
  if (name.compare("EC50") == 0)
    return &GetEC50();
  if (name.compare("EMaxShapeParameter") == 0)
    return &GetEMaxShapeParameter();
  if (name.compare("HeartRateModifier") == 0)
    return &GetHeartRateModifier();
  if (name.compare("NeuromuscularBlock") == 0)
    return &GetNeuromuscularBlock();
  if (name.compare("RespirationRateModifier") == 0)
    return &GetRespirationRateModifier();
  if (name.compare("Sedation") == 0)
    return &GetSedation();
  if (name.compare("SystolicPressureModifier") == 0)
    return &GetSystolicPressureModifier();
  if (name.compare("TidalVolumeModifier") == 0)
    return &GetTidalVolumeModifier();
  if (name.compare("TubularPermeabilityModifier") == 0)
    return &GetTubularPermeabilityModifier();

  return GetPupillaryResponse().GetScalar(name);
}

void SESubstancePharmacodynamics::CalculateDerived()
{
  
}

bool SESubstancePharmacodynamics::HasBronchodilation() const
{
  return (m_Bronchodilation == nullptr) ? false : m_Bronchodilation->IsValid();
}
SEScalarNegative1To1& SESubstancePharmacodynamics::GetBronchodilation()
{
  if (m_Bronchodilation == nullptr)
    m_Bronchodilation = new SEScalarNegative1To1();
  return *m_Bronchodilation;
}
double SESubstancePharmacodynamics::GetBronchodilation() const
{
  if (m_Bronchodilation == nullptr)
    return SEScalar::dNaN();
  return m_Bronchodilation->GetValue();
}

bool SESubstancePharmacodynamics::HasDiastolicPressureModifier() const
{
  return (m_DiastolicPressureModifier == nullptr) ? false : m_DiastolicPressureModifier->IsValid();
}
SEScalarNegative1To1& SESubstancePharmacodynamics::GetDiastolicPressureModifier()
{
  if (m_DiastolicPressureModifier == nullptr)
    m_DiastolicPressureModifier = new SEScalarNegative1To1();
  return *m_DiastolicPressureModifier;
}
double SESubstancePharmacodynamics::GetDiastolicPressureModifier() const
{
  if (m_DiastolicPressureModifier == nullptr)
    return SEScalar::dNaN();
  return m_DiastolicPressureModifier->GetValue();
}

bool SESubstancePharmacodynamics::HasEC50() const
{
  return (m_EC50 == nullptr) ? false : m_EC50->IsValid();
}
SEScalarMassPerVolume& SESubstancePharmacodynamics::GetEC50()
{
  if (m_EC50 == nullptr)
    m_EC50 = new SEScalarMassPerVolume();
  return *m_EC50;
}
double SESubstancePharmacodynamics::GetEC50(const MassPerVolumeUnit& unit) const
{
  if (m_EC50 == nullptr)
    return SEScalar::dNaN();
  return m_EC50->GetValue(unit);
}

bool SESubstancePharmacodynamics::HasEMaxShapeParameter() const
{
  return (m_EMaxShapeParameter == nullptr) ? false : m_EMaxShapeParameter->IsValid();
}
SEScalar& SESubstancePharmacodynamics::GetEMaxShapeParameter()
{
  if (m_EMaxShapeParameter == nullptr)
    m_EMaxShapeParameter = new SEScalar();
  return *m_EMaxShapeParameter;
}
double SESubstancePharmacodynamics::GetEMaxShapeParameter() const
{
  if (m_EMaxShapeParameter == nullptr)
    return SEScalar::dNaN();
  return m_EMaxShapeParameter->GetValue();
}

bool SESubstancePharmacodynamics::HasHeartRateModifier() const
{
  return (m_HeartRateModifier == nullptr) ? false : m_HeartRateModifier->IsValid();
}
SEScalarNegative1To1& SESubstancePharmacodynamics::GetHeartRateModifier()
{
  if (m_HeartRateModifier == nullptr)
    m_HeartRateModifier = new SEScalarNegative1To1();
  return *m_HeartRateModifier;
}
double SESubstancePharmacodynamics::GetHeartRateModifier() const
{
  if (m_HeartRateModifier == nullptr)
    return SEScalar::dNaN();
  return m_HeartRateModifier->GetValue();
}

bool SESubstancePharmacodynamics::HasNeuromuscularBlock() const
{
  return (m_NeuromuscularBlock == nullptr) ? false : m_NeuromuscularBlock->IsValid();
}
SEScalarNegative1To1& SESubstancePharmacodynamics::GetNeuromuscularBlock()
{
  if (m_NeuromuscularBlock == nullptr)
    m_NeuromuscularBlock = new SEScalarNegative1To1();
  return *m_NeuromuscularBlock;
}
double SESubstancePharmacodynamics::GetNeuromuscularBlock() const
{
  if (m_NeuromuscularBlock == nullptr)
    return SEScalar::dNaN();
  return m_NeuromuscularBlock->GetValue();
}

bool SESubstancePharmacodynamics::HasPupillaryResponse() const
{
  return (m_PupillaryResponse != nullptr);
}
SEPupillaryResponse& SESubstancePharmacodynamics::GetPupillaryResponse()
{
  if (m_PupillaryResponse == nullptr)
    m_PupillaryResponse = new SEPupillaryResponse(GetLogger());
  return *m_PupillaryResponse;
}
const SEPupillaryResponse* SESubstancePharmacodynamics::GetPupillaryResponse() const
{
  return m_PupillaryResponse;
}
void SESubstancePharmacodynamics::RemovePupillaryResponse()
{
  SAFE_DELETE(m_PupillaryResponse);
}

bool SESubstancePharmacodynamics::HasRespirationRateModifier() const
{
  return (m_RespirationRateModifier == nullptr) ? false : m_RespirationRateModifier->IsValid();
}
SEScalarNegative1To1& SESubstancePharmacodynamics::GetRespirationRateModifier()
{
  if (m_RespirationRateModifier == nullptr)
    m_RespirationRateModifier = new SEScalarNegative1To1();
  return *m_RespirationRateModifier;
}
double SESubstancePharmacodynamics::GetRespirationRateModifier() const
{
  if (m_RespirationRateModifier == nullptr)
    return SEScalar::dNaN();
  return m_RespirationRateModifier->GetValue();
}

bool SESubstancePharmacodynamics::HasSedation() const
{
  return (m_Sedation == nullptr) ? false : m_Sedation->IsValid();
}
SEScalarNegative1To1& SESubstancePharmacodynamics::GetSedation()
{
  if (m_Sedation == nullptr)
    m_Sedation = new SEScalarNegative1To1();
  return *m_Sedation;
}
double SESubstancePharmacodynamics::GetSedation() const
{
  if (m_Sedation == nullptr)
    return SEScalar::dNaN();
  return m_Sedation->GetValue();
}

bool SESubstancePharmacodynamics::HasSystolicPressureModifier() const
{
  return (m_SystolicPressureModifier == nullptr) ? false : m_SystolicPressureModifier->IsValid();
}
SEScalarNegative1To1& SESubstancePharmacodynamics::GetSystolicPressureModifier()
{
  if (m_SystolicPressureModifier == nullptr)
    m_SystolicPressureModifier = new SEScalarNegative1To1();
  return *m_SystolicPressureModifier;
}
double SESubstancePharmacodynamics::GetSystolicPressureModifier() const
{
  if (m_SystolicPressureModifier == nullptr)
    return SEScalar::dNaN();
  return m_SystolicPressureModifier->GetValue();
}

bool SESubstancePharmacodynamics::HasTidalVolumeModifier() const
{
  return (m_TidalVolumeModifier == nullptr) ? false : m_TidalVolumeModifier->IsValid();
}
SEScalarNegative1To1& SESubstancePharmacodynamics::GetTidalVolumeModifier()
{
  if (m_TidalVolumeModifier == nullptr)
    m_TidalVolumeModifier = new SEScalarNegative1To1();
  return *m_TidalVolumeModifier;
}
double SESubstancePharmacodynamics::GetTidalVolumeModifier() const
{
  if (m_TidalVolumeModifier == nullptr)
    return SEScalar::dNaN();
  return m_TidalVolumeModifier->GetValue();
}

bool SESubstancePharmacodynamics::HasTubularPermeabilityModifier() const
{
  return (m_TubularPermeabilityModifier == nullptr) ? false : m_TubularPermeabilityModifier->IsValid();
}
SEScalarNegative1To1& SESubstancePharmacodynamics::GetTubularPermeabilityModifier()
{
  if (m_TubularPermeabilityModifier == nullptr)
    m_TubularPermeabilityModifier = new SEScalarNegative1To1();
  return *m_TubularPermeabilityModifier;
}
double SESubstancePharmacodynamics::GetTubularPermeabilityModifier() const
{
  if (m_TubularPermeabilityModifier == nullptr)
    return SEScalar::dNaN();
  return m_TubularPermeabilityModifier->GetValue();
}