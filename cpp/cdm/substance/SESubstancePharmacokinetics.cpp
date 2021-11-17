/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#include "stdafx.h"
#include "substance/SESubstancePharmacokinetics.h"
#include "substance/SESubstancePhysicochemicals.h"
#include "substance/SESubstanceTissuePharmacokinetics.h"
#include "properties/SEScalar0To1.h"

SESubstancePharmacokinetics::SESubstancePharmacokinetics(Logger* logger) : Loggable(logger)
{
  m_Physicochemicals = nullptr;
}

SESubstancePharmacokinetics::~SESubstancePharmacokinetics()
{
  SAFE_DELETE(m_Physicochemicals);
  DELETE_MAP_SECOND(m_TissueKinetics);
  m_TissueKinetics.clear();
}

void SESubstancePharmacokinetics::Clear()
{
  if(m_Physicochemicals!=nullptr)
    m_Physicochemicals->Clear();
  for (auto itr : m_TissueKinetics)
    itr.second->Clear();
}

bool SESubstancePharmacokinetics::IsValid() const
{
  if (HasPhysicochemicals())
    return true;
  if (HasTissueKinetics())
    return true;
  return false;
}

const SEScalar* SESubstancePharmacokinetics::GetScalar(const std::string& name)
{
  if (HasPhysicochemicals())
    return GetPhysicochemicals().GetScalar(name);  
  // I did not support for getting a specific tissue kinetic scalar due to lack of coffee
  return nullptr;
}

bool SESubstancePharmacokinetics::HasPhysicochemicals() const
{
  return m_Physicochemicals == nullptr ? false : m_Physicochemicals->IsValid();
}
SESubstancePhysicochemicals& SESubstancePharmacokinetics::GetPhysicochemicals()
{
  if (m_Physicochemicals == nullptr)
    m_Physicochemicals = new SESubstancePhysicochemicals(GetLogger());
  return *m_Physicochemicals;
}
const SESubstancePhysicochemicals* SESubstancePharmacokinetics::GetPhysicochemicals() const
{
  return m_Physicochemicals;
}


bool SESubstancePharmacokinetics::HasTissueKinetics() const
{
  return m_TissueKinetics.size() > 0;
}
bool SESubstancePharmacokinetics::HasTissueKinetics(const std::string& name) const
{
  auto idx = m_TissueKinetics.find(name);
  if (idx != m_TissueKinetics.end())
    return true;
  return false;
}
SESubstanceTissuePharmacokinetics& SESubstancePharmacokinetics::GetTissueKinetics(const std::string& name)
{
  auto idx = m_TissueKinetics.find(name);
  if (idx != m_TissueKinetics.end())
    return *(idx->second);
  SESubstanceTissuePharmacokinetics* fx = new SESubstanceTissuePharmacokinetics(name, GetLogger());
  m_TissueKinetics[name] = fx;
  return *fx;
}
const SESubstanceTissuePharmacokinetics* SESubstancePharmacokinetics::GetTissueKinetics(const std::string& name) const
{
  auto idx = m_TissueKinetics.find(name);
  if (idx != m_TissueKinetics.end())
    return (idx->second);
  return nullptr;
}
void SESubstancePharmacokinetics::RemoveTissueKinetics(const std::string& name)
{
  m_TissueKinetics.erase(name);
}
