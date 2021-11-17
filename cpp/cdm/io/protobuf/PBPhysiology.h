/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#pragma once
   // Forward Declaire SE and Protobuf Physiology Types
CDM_BIND_DECL2(BloodChemistrySystem)
CDM_BIND_DECL2(CardiovascularSystem)
CDM_BIND_DECL2(EndocrineSystem)
CDM_BIND_DECL2(DrugSystem)
CDM_BIND_DECL2(EnergySystem)
CDM_BIND_DECL2(GastrointestinalSystem)
CDM_BIND_DECL2(HepaticSystem)
CDM_BIND_DECL2(NervousSystem)
CDM_BIND_DECL2(PupillaryResponse)
CDM_BIND_DECL2(RenalSystem)
CDM_BIND_DECL2(RespiratorySystem)
CDM_BIND_DECL2(TissueSystem)


class CDM_DECL PBPhysiology
{
public:

  // Blood Chemistry                                                                           
  static void Load(const CDM_BIND::BloodChemistrySystemData& src, SEBloodChemistrySystem& dst);     
  static CDM_BIND::BloodChemistrySystemData* Unload(const SEBloodChemistrySystem& src);             
  static void Serialize(const CDM_BIND::BloodChemistrySystemData& src, SEBloodChemistrySystem& dst);
  static void Serialize(const SEBloodChemistrySystem& src, CDM_BIND::BloodChemistrySystemData& dst);

  // Cardiovascular
  static void Load(const CDM_BIND::CardiovascularSystemData& src, SECardiovascularSystem& dst);
  static CDM_BIND::CardiovascularSystemData* Unload(const SECardiovascularSystem& src);
  static void Serialize(const CDM_BIND::CardiovascularSystemData& src, SECardiovascularSystem& dst);
  static void Serialize(const SECardiovascularSystem& src, CDM_BIND::CardiovascularSystemData& dst);

  // Drug
  static void Load(const CDM_BIND::DrugSystemData& src, SEDrugSystem& dst);
  static CDM_BIND::DrugSystemData* Unload(const SEDrugSystem& src);
  static void Serialize(const CDM_BIND::DrugSystemData& src, SEDrugSystem& dst);
  static void Serialize(const SEDrugSystem& src, CDM_BIND::DrugSystemData& dst);

  // Endocrine
  static void Load(const CDM_BIND::EndocrineSystemData& src, SEEndocrineSystem& dst);
  static CDM_BIND::EndocrineSystemData* Unload(const SEEndocrineSystem& src);
  static void Serialize(const CDM_BIND::EndocrineSystemData& src, SEEndocrineSystem& dst);
  static void Serialize(const SEEndocrineSystem& src, CDM_BIND::EndocrineSystemData& dst);

  // Energy
  static void Load(const CDM_BIND::EnergySystemData& src, SEEnergySystem& dst);
  static CDM_BIND::EnergySystemData* Unload(const SEEnergySystem& src);
  static void Serialize(const CDM_BIND::EnergySystemData& src, SEEnergySystem& dst);
  static void Serialize(const SEEnergySystem& src, CDM_BIND::EnergySystemData& dst);

  // Gastrointestinal
  static void Load(const CDM_BIND::GastrointestinalSystemData& src, SEGastrointestinalSystem& dst);
  static CDM_BIND::GastrointestinalSystemData* Unload(const SEGastrointestinalSystem& src);
  static void Serialize(const CDM_BIND::GastrointestinalSystemData& src, SEGastrointestinalSystem& dst);
  static void Serialize(const SEGastrointestinalSystem& src, CDM_BIND::GastrointestinalSystemData& dst);

  // Hepatic
  static void Load(const CDM_BIND::HepaticSystemData& src, SEHepaticSystem& dst);
  static CDM_BIND::HepaticSystemData* Unload(const SEHepaticSystem& src);
  static void Serialize(const CDM_BIND::HepaticSystemData& src, SEHepaticSystem& dst);
  static void Serialize(const SEHepaticSystem& src, CDM_BIND::HepaticSystemData& dst);

  /// Nervous
  static void Load(const CDM_BIND::NervousSystemData& src, SENervousSystem& dst);
  static CDM_BIND::NervousSystemData* Unload(const SENervousSystem& src);
  static void Serialize(const CDM_BIND::NervousSystemData& src, SENervousSystem& dst);
  static void Serialize(const SENervousSystem& src, CDM_BIND::NervousSystemData& dst);

  // Pupillary Response
  static void Load(const CDM_BIND::PupillaryResponseData& src, SEPupillaryResponse& dst);
  static CDM_BIND::PupillaryResponseData* Unload(const SEPupillaryResponse& src);
  static void Serialize(const CDM_BIND::PupillaryResponseData& src, SEPupillaryResponse& dst);
  static void Serialize(const SEPupillaryResponse& src, CDM_BIND::PupillaryResponseData& dst);

  // Renal
  static void Load(const CDM_BIND::RenalSystemData& src, SERenalSystem& dst);
  static CDM_BIND::RenalSystemData* Unload(const SERenalSystem& src);
  static void Serialize(const CDM_BIND::RenalSystemData& src, SERenalSystem& dst);
  static void Serialize(const SERenalSystem& src, CDM_BIND::RenalSystemData& dst);

  // Respiratory
  static void Load(const CDM_BIND::RespiratorySystemData& src, SERespiratorySystem& dst);
  static CDM_BIND::RespiratorySystemData* Unload(const SERespiratorySystem& src);
  static void Serialize(const CDM_BIND::RespiratorySystemData& src, SERespiratorySystem& dst);
  static void Serialize(const SERespiratorySystem& src, CDM_BIND::RespiratorySystemData& dst);

  // Tissue
  static void Load(const CDM_BIND::TissueSystemData& src, SETissueSystem& dst);
  static CDM_BIND::TissueSystemData* Unload(const SETissueSystem& src);
  static void Serialize(const CDM_BIND::TissueSystemData& src, SETissueSystem& dst);
  static void Serialize(const SETissueSystem& src, CDM_BIND::TissueSystemData& dst);

};