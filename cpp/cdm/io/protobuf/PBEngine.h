/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#pragma once
CDM_BIND_DECL(LogMessagesData)
CDM_BIND_DECL(ActionListData)
CDM_BIND_DECL(ActionMapData)
CDM_BIND_DECL(ConditionListData)
CDM_BIND_DECL(DataRequestedListData)
CDM_BIND_DECL2(DataRequest)
CDM_BIND_DECL2(DataRequested)
CDM_BIND_DECL2(DataRequestManager)
CDM_BIND_DECL2(DecimalFormat)
CDM_BIND_DECL2(DynamicStabilization)
CDM_BIND_DECL2(DynamicStabilizationEngineConvergence)
CDM_BIND_DECL2(EngineInitialization)
CDM_BIND_DECL2(TimedStabilization)
CDM_BIND_DECL2(PatientConfiguration)
class LogMessages;
class SEAction;
class SEActionManager;
class SEConditionManager;
class SESubstanceManager;
class SEEnvironmentActionCollection;
class SEEquipmentActionCollection;
class SEPatientActionCollection;

class CDM_DECL PBEngine
{
public:

  static void Load(const CDM_BIND::LogMessagesData& src, LogMessages& dst);
  static CDM_BIND::LogMessagesData* Unload(const LogMessages& src);
  static void Serialize(const CDM_BIND::LogMessagesData& src, LogMessages& dst);
  static void Serialize(const LogMessages& src, CDM_BIND::LogMessagesData& dst); 
  static bool SerializeToString(const LogMessages& src, std::string& output, SerializationFormat m, Logger* logger);
  static bool SerializeFromString(const std::string& src, LogMessages& dst, SerializationFormat m, Logger* logger);

  static void Load(const CDM_BIND::PatientConfigurationData& src, SEPatientConfiguration& dst, const SESubstanceManager& subMgr);
  static CDM_BIND::PatientConfigurationData* Unload(const SEPatientConfiguration& src);
  static void Serialize(const CDM_BIND::PatientConfigurationData& src, SEPatientConfiguration& dst, const SESubstanceManager& subMgr);
  static void Serialize(const SEPatientConfiguration& src, CDM_BIND::PatientConfigurationData& dst);
  static bool SerializeToString(const SEPatientConfiguration& src, std::string& output, SerializationFormat m);
  static bool SerializeToFile(const SEPatientConfiguration& src, const std::string& filename);
  static bool SerializeFromString(const std::string& src, SEPatientConfiguration& dst, SerializationFormat m, const SESubstanceManager& subMgr);
  static bool SerializeFromFile(const std::string& filename, SEPatientConfiguration& dst, const SESubstanceManager& subMgr);

  static void Load(const CDM_BIND::ConditionListData& src, SEConditionManager& dst, const SESubstanceManager& subMgr);
  static CDM_BIND::ConditionListData* Unload(const SEConditionManager& src);
  static void Serialize(const CDM_BIND::ConditionListData& src, SEConditionManager& dst, const SESubstanceManager& subMgr);
  static void Serialize(const SEConditionManager& src, CDM_BIND::ConditionListData& dst);

  static bool SerializeToString(const SEConditionManager& src, std::string& output, SerializationFormat m);
  static bool SerializeToFile(const SEConditionManager& src, const std::string& filename);
  static bool SerializeFromString(const std::string& src, SEConditionManager& dst, SerializationFormat m, const SESubstanceManager& subMgr);
  static bool SerializeFromFile(const std::string& filename, SEConditionManager& dst, const SESubstanceManager& subMgr);

  static void Load(const CDM_BIND::ActionListData& src, SEActionManager& dst);
  static CDM_BIND::ActionListData* Unload(const SEActionManager& src);
  static void Serialize(const CDM_BIND::ActionListData& src, SEActionManager& dst);
  static void Serialize(const SEActionManager& src, CDM_BIND::ActionListData& dst);
  static void Serialize(const SEEquipmentActionCollection& src, CDM_BIND::ActionListData& dst);
  static void Serialize(const SEEnvironmentActionCollection& src, CDM_BIND::ActionListData& dst);
  static void Serialize(const SEPatientActionCollection& src, CDM_BIND::ActionListData& dst);

  static void Load(const CDM_BIND::ActionListData& src, std::vector<SEAction*>& dst, const SESubstanceManager& subMgr);
  static void Serialize(const CDM_BIND::ActionListData& src, std::vector<SEAction*>& dst, const SESubstanceManager& subMgr);
  static bool SerializeFromString(const std::string& src, std::vector<SEAction*>& dst, SerializationFormat m, const SESubstanceManager& subMgr);

  static void Load(const CDM_BIND::ActionMapData& src, std::map<int, std::vector<const SEAction*>>& dst, const SESubstanceManager& subMgr);
  static void Serialize(const CDM_BIND::ActionMapData& src, std::map<int, std::vector<const SEAction*>>& dst, const SESubstanceManager& subMgr);
  static bool SerializeFromString(const std::string& src, std::map<int,std::vector<const SEAction*>>& dst, SerializationFormat m, const SESubstanceManager& subMgr);

  static bool SerializeToString(const SEActionManager& src, std::string& output, SerializationFormat m);
  static bool SerializeToFile(const SEActionManager& src, const std::string& filename);
  static bool SerializeFromString(const std::string& src, SEActionManager& dst, SerializationFormat m);
  static bool SerializeFromFile(const std::string& filename, SEActionManager& dst);

  static void Load(const CDM_BIND::DataRequestData& src, SEDataRequest& dst);
  static CDM_BIND::DataRequestData* Unload(const SEDataRequest& src);
  static void Serialize(const CDM_BIND::DataRequestData& src, SEDataRequest& dst);
  static void Serialize(const SEDataRequest& src, CDM_BIND::DataRequestData& dst);
  static void Copy(const SEDataRequest& src, SEDataRequest& dst);

  CDM_BIND::DataRequestedData* Unload(const SEDataRequested& src);
  static void Serialize(const SEDataRequested& src, CDM_BIND::DataRequestedData& dst);
  static bool SerializeToString(const SEDataRequested& src, std::string& dst, SerializationFormat m);
  static void Serialize(const std::vector<SEDataRequested*>& src, CDM_BIND::DataRequestedListData& dst);
  static bool SerializeToString(const std::vector<SEDataRequested*>& src, std::string& dst, SerializationFormat m);

  static void Load(const CDM_BIND::DataRequestManagerData& src, SEDataRequestManager& dst, const SESubstanceManager& subMgr);
  static CDM_BIND::DataRequestManagerData* Unload(const SEDataRequestManager& src);
  static void Serialize(const CDM_BIND::DataRequestManagerData& src, SEDataRequestManager& dst, const SESubstanceManager& subMgr);
  static void Serialize(const SEDataRequestManager& src, CDM_BIND::DataRequestManagerData& dst);
  static void Copy(const SEDataRequestManager& src, SEDataRequestManager& dst, const SESubstanceManager& subMgr);

  static bool SerializeToString(const SEDataRequestManager& src, std::string& output, SerializationFormat m);
  static bool SerializeToFile(const SEDataRequestManager& src, const std::string& filename);
  static bool SerializeFromString(const std::string& src, SEDataRequestManager& dst, SerializationFormat m, const SESubstanceManager& subMgr);
  static bool SerializeFromFile(const std::string& filename, SEDataRequestManager& dst, const SESubstanceManager& subMgr);

  static void Load(const CDM_BIND::DecimalFormatData& src, SEDecimalFormat& dst);
  static CDM_BIND::DecimalFormatData* Unload(const SEDecimalFormat& src);
  static void Serialize(const CDM_BIND::DecimalFormatData& src, SEDecimalFormat& dst);
  static void Serialize(const SEDecimalFormat& src, CDM_BIND::DecimalFormatData& dst);

  static void Load(const CDM_BIND::DynamicStabilizationData& src, SEDynamicStabilization& dst);
  static CDM_BIND::DynamicStabilizationData* Unload(const SEDynamicStabilization& src);
  static void Serialize(const CDM_BIND::DynamicStabilizationData& src, SEDynamicStabilization& dst);
  static void Serialize(const SEDynamicStabilization& src, CDM_BIND::DynamicStabilizationData& dst);

  static bool SerializeToString(const SEDynamicStabilization& src, std::string& output, SerializationFormat m);
  static bool SerializeToFile(const SEDynamicStabilization& src, const std::string& filename);
  static bool SerializeFromString(const std::string& src, SEDynamicStabilization& dst, SerializationFormat m);
  static bool SerializeFromFile(const std::string& filename, SEDynamicStabilization& dst);

  static void Load(const CDM_BIND::DynamicStabilizationEngineConvergenceData& src, SEDynamicStabilizationEngineConvergence& dst);
  static CDM_BIND::DynamicStabilizationEngineConvergenceData* Unload(const SEDynamicStabilizationEngineConvergence& src);
  static void Serialize(const CDM_BIND::DynamicStabilizationEngineConvergenceData& src, SEDynamicStabilizationEngineConvergence& dst);
  static void Serialize(const SEDynamicStabilizationEngineConvergence& src, CDM_BIND::DynamicStabilizationEngineConvergenceData& dst);

  static void Load(const CDM_BIND::EngineInitializationData& src, SEEngineInitialization& dst, const SESubstanceManager& subMgr);
  static CDM_BIND::EngineInitializationData* Unload(const SEEngineInitialization& src);
  static void Serialize(const CDM_BIND::EngineInitializationData& src, SEEngineInitialization& dst, const SESubstanceManager& subMgr);
  static void Serialize(const SEEngineInitialization& src, CDM_BIND::EngineInitializationData& dst);
  static bool SerializeToString(const SEEngineInitialization& src, std::string& output, SerializationFormat m);
  static bool SerializeFromString(const std::string& src, SEEngineInitialization& dst, SerializationFormat m, const SESubstanceManager& subMgr);
  static bool SerializeFromString(const std::string& src, std::vector<SEEngineInitialization*>& dst, SerializationFormat m, const SESubstanceManager& subMgr);
  static void Copy(const SEEngineInitialization& src, SEEngineInitialization& dst, const SESubstanceManager& subMgr);

  static void Load(const CDM_BIND::TimedStabilizationData& src, SETimedStabilization& dst);
  static CDM_BIND::TimedStabilizationData* Unload(const SETimedStabilization& src);
  static void Serialize(const CDM_BIND::TimedStabilizationData& src, SETimedStabilization& dst);
  static void Serialize(const SETimedStabilization& src, CDM_BIND::TimedStabilizationData& dst);

  static bool SerializeToString(const SETimedStabilization& src, std::string& output, SerializationFormat m);
  static bool SerializeToFile(const SETimedStabilization& src, const std::string& filename);
  static bool SerializeFromString(const std::string& src, SETimedStabilization& dst, SerializationFormat m);
  static bool SerializeFromFile(const std::string& filename, SETimedStabilization& dst);
};
