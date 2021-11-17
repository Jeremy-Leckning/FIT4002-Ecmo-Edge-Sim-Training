/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#include "stdafx.h"
#include "system/physiology/SEEnergySystem.h"
#include "properties/SEScalarArea.h"
#include "properties/SEScalarPower.h"
#include "properties/SEScalarTemperature.h"
#include "properties/SEScalarMass.h"
#include "properties/SEScalarMassPerTime.h"
#include "properties/SEScalar0To1.h"
#include "properties/SEScalarVolumePerTime.h"
#include "properties/SEScalarAmountPerTime.h"
#include "properties/SEScalarPressure.h"

SEEnergySystem::SEEnergySystem(Logger* logger) : SESystem(logger)
{
  m_AchievedExerciseLevel = nullptr;
  m_CoreTemperature = nullptr;
  m_CreatinineProductionRate = nullptr;
  m_ExerciseMeanArterialPressureDelta = nullptr;
  m_FatigueLevel = nullptr;
  m_KetoneProductionRate = nullptr;
  m_LactateProductionRate = nullptr;
  m_SkinTemperature=nullptr;
  m_SweatRate = nullptr;
  m_TotalMetabolicRate = nullptr;
  m_TotalWorkRateLevel = nullptr;
}

SEEnergySystem::~SEEnergySystem()
{
  SAFE_DELETE(m_AchievedExerciseLevel);
  SAFE_DELETE(m_CoreTemperature);
  SAFE_DELETE(m_CreatinineProductionRate);
  SAFE_DELETE(m_ExerciseMeanArterialPressureDelta);
  SAFE_DELETE(m_FatigueLevel);
  SAFE_DELETE(m_KetoneProductionRate);
  SAFE_DELETE(m_LactateProductionRate);
  SAFE_DELETE(m_SkinTemperature);
  SAFE_DELETE(m_SweatRate);
  SAFE_DELETE(m_TotalMetabolicRate);
  SAFE_DELETE(m_TotalWorkRateLevel);
}

void SEEnergySystem::Clear()
{
  SESystem::Clear();

  INVALIDATE_PROPERTY(m_AchievedExerciseLevel);
  INVALIDATE_PROPERTY(m_CoreTemperature);
  INVALIDATE_PROPERTY(m_CreatinineProductionRate);
  INVALIDATE_PROPERTY(m_ExerciseMeanArterialPressureDelta);
  INVALIDATE_PROPERTY(m_FatigueLevel);
  INVALIDATE_PROPERTY(m_KetoneProductionRate);
  INVALIDATE_PROPERTY(m_LactateProductionRate);
  INVALIDATE_PROPERTY(m_SkinTemperature);
  INVALIDATE_PROPERTY(m_SweatRate);
  INVALIDATE_PROPERTY(m_TotalMetabolicRate);
  INVALIDATE_PROPERTY(m_TotalWorkRateLevel);
}

const SEScalar* SEEnergySystem::GetScalar(const std::string& name)
{
  if (name.compare("AchievedExerciseLevel") == 0)
    return &GetAchievedExerciseLevel();
  if (name.compare("CoreTemperature") == 0)
    return &GetCoreTemperature();
  if (name.compare("CreatinineProductionRate") == 0)
    return &GetCreatinineProductionRate();
  if (name.compare("ExerciseMeanArterialPressureDelta") == 0)
    return &GetExerciseMeanArterialPressureDelta();
  if (name.compare("FatigueLevel") == 0)
    return &GetFatigueLevel();
  if (name.compare("KetoneProductionRate") == 0)
    return &GetKetoneProductionRate();
  if (name.compare("LactateProductionRate") == 0)
    return &GetLactateProductionRate();
  if (name.compare("SkinTemperature") == 0)
    return &GetSkinTemperature();
  if (name.compare("SweatRate") == 0)
    return &GetSweatRate();
  if (name.compare("TotalMetabolicRate") == 0)
    return &GetTotalMetabolicRate();
  if (name.compare("TotalWorkRateLevel") == 0)
    return &GetTotalWorkRateLevel();
  return nullptr;
}

bool SEEnergySystem::HasAchievedExerciseLevel() const
{
  return m_AchievedExerciseLevel == nullptr ? false : m_AchievedExerciseLevel->IsValid();
}
SEScalar0To1& SEEnergySystem::GetAchievedExerciseLevel()
{
  if (m_AchievedExerciseLevel == nullptr)
    m_AchievedExerciseLevel = new SEScalar0To1();
  return *m_AchievedExerciseLevel;
}
double SEEnergySystem::GetAchievedExerciseLevel() const
{
  if (m_AchievedExerciseLevel == nullptr)
    return SEScalar::dNaN();
  return m_AchievedExerciseLevel->GetValue();
}

bool SEEnergySystem::HasCoreTemperature() const
{
  return m_CoreTemperature == nullptr ? false : m_CoreTemperature->IsValid();
}
SEScalarTemperature& SEEnergySystem::GetCoreTemperature()
{
  if (m_CoreTemperature == nullptr)
    m_CoreTemperature = new SEScalarTemperature();
  return *m_CoreTemperature;
}
double SEEnergySystem::GetCoreTemperature(const TemperatureUnit& unit) const
{
  if (m_CoreTemperature == nullptr)
    return SEScalar::dNaN();
  return m_CoreTemperature->GetValue(unit);
}

bool SEEnergySystem::HasCreatinineProductionRate() const
{
  return m_CreatinineProductionRate == nullptr ? false : m_CreatinineProductionRate->IsValid();
}
SEScalarAmountPerTime& SEEnergySystem::GetCreatinineProductionRate()
{
  if (m_CreatinineProductionRate == nullptr)
    m_CreatinineProductionRate = new SEScalarAmountPerTime();
  return *m_CreatinineProductionRate;
}
double SEEnergySystem::GetCreatinineProductionRate(const AmountPerTimeUnit& unit) const
{
  if (m_CreatinineProductionRate == nullptr)
    return SEScalar::dNaN();
  return m_CreatinineProductionRate->GetValue(unit);
}

bool SEEnergySystem::HasExerciseMeanArterialPressureDelta() const
{
  return m_ExerciseMeanArterialPressureDelta == nullptr ? false : m_ExerciseMeanArterialPressureDelta->IsValid();
}
SEScalarPressure& SEEnergySystem::GetExerciseMeanArterialPressureDelta()
{
  if (m_ExerciseMeanArterialPressureDelta == nullptr)
    m_ExerciseMeanArterialPressureDelta = new SEScalarPressure();
  return *m_ExerciseMeanArterialPressureDelta;
}
double SEEnergySystem::GetExerciseMeanArterialPressureDelta(const PressureUnit& unit) const
{
  if (m_ExerciseMeanArterialPressureDelta == nullptr)
    return SEScalar::dNaN();
  return m_ExerciseMeanArterialPressureDelta->GetValue(unit);
}

bool SEEnergySystem::HasFatigueLevel() const
{
  return m_FatigueLevel == nullptr ? false : m_FatigueLevel->IsValid();
}
SEScalar0To1& SEEnergySystem::GetFatigueLevel()
{
  if (m_FatigueLevel == nullptr)
    m_FatigueLevel = new SEScalar0To1();
  return *m_FatigueLevel;
}
double SEEnergySystem::GetFatigueLevel() const
{
  if (m_FatigueLevel == nullptr)
    return SEScalar::dNaN();
  return m_FatigueLevel->GetValue();
}

bool SEEnergySystem::HasKetoneProductionRate() const
{
  return m_KetoneProductionRate == nullptr ? false : m_KetoneProductionRate->IsValid();
}
SEScalarAmountPerTime& SEEnergySystem::GetKetoneProductionRate()
{
  if (m_KetoneProductionRate == nullptr)
    m_KetoneProductionRate = new SEScalarAmountPerTime();
  return *m_KetoneProductionRate;
}
double SEEnergySystem::GetKetoneProductionRate(const AmountPerTimeUnit& unit) const
{
  if (m_KetoneProductionRate == nullptr)
    return SEScalar::dNaN();
  return m_KetoneProductionRate->GetValue(unit);
}

bool SEEnergySystem::HasLactateProductionRate() const
{
  return m_LactateProductionRate == nullptr ? false : m_LactateProductionRate->IsValid();
}
SEScalarAmountPerTime& SEEnergySystem::GetLactateProductionRate()
{
  if (m_LactateProductionRate == nullptr)
    m_LactateProductionRate = new SEScalarAmountPerTime();
  return *m_LactateProductionRate;
}
double SEEnergySystem::GetLactateProductionRate(const AmountPerTimeUnit& unit) const
{
  if (m_LactateProductionRate == nullptr)
    return SEScalar::dNaN();
  return m_LactateProductionRate->GetValue(unit);
}

bool SEEnergySystem::HasSkinTemperature() const
{
  return m_SkinTemperature == nullptr ? false : m_SkinTemperature->IsValid();
}
SEScalarTemperature& SEEnergySystem::GetSkinTemperature()
{
  if (m_SkinTemperature == nullptr)
    m_SkinTemperature = new SEScalarTemperature();
  return *m_SkinTemperature;
}
double SEEnergySystem::GetSkinTemperature(const TemperatureUnit& unit) const
{
  if (m_SkinTemperature == nullptr)
    return SEScalar::dNaN();
  return m_SkinTemperature->GetValue(unit);
}

bool SEEnergySystem::HasSweatRate() const
{
  return m_SweatRate == nullptr ? false : m_SweatRate->IsValid();
}
SEScalarMassPerTime& SEEnergySystem::GetSweatRate()
{
  if (m_SweatRate == nullptr)
    m_SweatRate = new SEScalarMassPerTime();
  return *m_SweatRate;
}
double SEEnergySystem::GetSweatRate(const MassPerTimeUnit& unit) const
{
  if (m_SweatRate == nullptr)
    return SEScalar::dNaN();
  return m_SweatRate->GetValue(unit);
}

bool SEEnergySystem::HasTotalMetabolicRate() const
{
  return m_TotalMetabolicRate==nullptr?false:m_TotalMetabolicRate->IsValid();
}
SEScalarPower& SEEnergySystem::GetTotalMetabolicRate()
{
  if(m_TotalMetabolicRate==nullptr)
    m_TotalMetabolicRate = new SEScalarPower();
  return *m_TotalMetabolicRate;
}
double SEEnergySystem::GetTotalMetabolicRate(const PowerUnit& unit) const
{
  if (m_TotalMetabolicRate == nullptr)
    return SEScalar::dNaN();
  return m_TotalMetabolicRate->GetValue(unit);
}

bool SEEnergySystem::HasTotalWorkRateLevel() const
{
  return m_TotalWorkRateLevel == nullptr ? false : m_TotalWorkRateLevel->IsValid();
}
SEScalar0To1& SEEnergySystem::GetTotalWorkRateLevel()
{
  if (m_TotalWorkRateLevel == nullptr)
    m_TotalWorkRateLevel = new SEScalar0To1();
  return *m_TotalWorkRateLevel;
}
double SEEnergySystem::GetTotalWorkRateLevel() const
{
  if (m_TotalWorkRateLevel == nullptr)
    return SEScalar::dNaN();
  return m_TotalWorkRateLevel->GetValue();
}
