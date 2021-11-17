/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#pragma once
CDM_BIND_DECL2(PatientAction)
CDM_BIND_DECL2(AcuteRespiratoryDistressSyndromeExacerbation)
CDM_BIND_DECL2(AcuteStress)
CDM_BIND_DECL2(AirwayObstruction)
CDM_BIND_DECL2(AsthmaAttack)
CDM_BIND_DECL2(BrainInjury)
CDM_BIND_DECL2(Bronchoconstriction)
CDM_BIND_DECL2(CardiacArrest)
CDM_BIND_DECL2(ChestCompressionForce)
CDM_BIND_DECL2(ChestCompressionForceScale)
CDM_BIND_DECL2(ChestOcclusiveDressing)
CDM_BIND_DECL2(ChronicObstructivePulmonaryDiseaseExacerbation)
CDM_BIND_DECL2(ConsciousRespiration)
CDM_BIND_DECL2(ConsumeNutrients)
CDM_BIND_DECL2(Dyspnea)
CDM_BIND_DECL2(Exercise)
CDM_BIND_DECL2(ForcedExhale)
CDM_BIND_DECL2(ForcedInhale)
CDM_BIND_DECL2(ForcedPause)
CDM_BIND_DECL2(Hemorrhage)
CDM_BIND_DECL2(ImpairedAlveolarExchangeExacerbation)
CDM_BIND_DECL2(Intubation)
CDM_BIND_DECL2(LobarPneumoniaExacerbation)
CDM_BIND_DECL2(MechanicalVentilation)
CDM_BIND_DECL2(NeedleDecompression)
CDM_BIND_DECL2(PatientAssessmentRequest)
CDM_BIND_DECL2(PericardialEffusion)
CDM_BIND_DECL2(PulmonaryShuntExacerbation)
CDM_BIND_DECL2(RespiratoryFatigue)
CDM_BIND_DECL2(SubstanceBolus)
CDM_BIND_DECL2(SubstanceBolusState)
CDM_BIND_DECL2(SubstanceCompoundInfusion)
CDM_BIND_DECL2(SubstanceInfusion)
CDM_BIND_DECL2(SupplementalOxygen)
CDM_BIND_DECL2(TensionPneumothorax)
CDM_BIND_DECL2(Urinate)
CDM_BIND_DECL2(UseInhaler)
CDM_BIND_DECL(AnyPatientActionData)
class SESubstanceManager;

class CDM_DECL PBPatientAction
{
public:
  /** Create a new action based on the binding object, load that data into the new action, and return said action */
  static SEPatientAction* Load(const CDM_BIND::AnyPatientActionData& any, const SESubstanceManager& subMgr);
  /** Create a new bind object, unload the action, put that in the bind object, and return said bind object */
  static CDM_BIND::AnyPatientActionData* Unload(const SEPatientAction& action);
  static void Serialize(const CDM_BIND::PatientActionData& src, SEPatientAction& dst);
  static void Serialize(const SEPatientAction& src, CDM_BIND::PatientActionData& dst);

  static void Load(const CDM_BIND::AcuteRespiratoryDistressSyndromeExacerbationData& src, SEAcuteRespiratoryDistressSyndromeExacerbation& dst);
  static CDM_BIND::AcuteRespiratoryDistressSyndromeExacerbationData* Unload(const SEAcuteRespiratoryDistressSyndromeExacerbation& src);
  static void Serialize(const CDM_BIND::AcuteRespiratoryDistressSyndromeExacerbationData& src, SEAcuteRespiratoryDistressSyndromeExacerbation& dst);
  static void Serialize(const SEAcuteRespiratoryDistressSyndromeExacerbation& src, CDM_BIND::AcuteRespiratoryDistressSyndromeExacerbationData& dst);
  static void Copy(const SEAcuteRespiratoryDistressSyndromeExacerbation& src, SEAcuteRespiratoryDistressSyndromeExacerbation& dst);

  static void Load(const CDM_BIND::AcuteStressData& src, SEAcuteStress& dst);
  static CDM_BIND::AcuteStressData* Unload(const SEAcuteStress& src);
  static void Serialize(const CDM_BIND::AcuteStressData& src, SEAcuteStress& dst);
  static void Serialize(const SEAcuteStress& src, CDM_BIND::AcuteStressData& dst);
  static void Copy(const SEAcuteStress& src, SEAcuteStress& dst);

  static void Load(const CDM_BIND::AirwayObstructionData& src, SEAirwayObstruction& dst);
  static CDM_BIND::AirwayObstructionData* Unload(const SEAirwayObstruction& src);
  static void Serialize(const CDM_BIND::AirwayObstructionData& src, SEAirwayObstruction& dst);
  static void Serialize(const SEAirwayObstruction& src, CDM_BIND::AirwayObstructionData& dst);
  static void Copy(const SEAirwayObstruction& src, SEAirwayObstruction& dst);

  static void Load(const CDM_BIND::AsthmaAttackData& src, SEAsthmaAttack& dst);
  static CDM_BIND::AsthmaAttackData* Unload(const SEAsthmaAttack& src);
  static void Serialize(const CDM_BIND::AsthmaAttackData& src, SEAsthmaAttack& dst);
  static void Serialize(const SEAsthmaAttack& src, CDM_BIND::AsthmaAttackData& dst);
  static void Copy(const SEAsthmaAttack& src, SEAsthmaAttack& dst);

  static void Load(const CDM_BIND::BrainInjuryData& src, SEBrainInjury& dst);
  static CDM_BIND::BrainInjuryData* Unload(const SEBrainInjury& src);
  static void Serialize(const CDM_BIND::BrainInjuryData& src, SEBrainInjury& dst);
  static void Serialize(const SEBrainInjury& src, CDM_BIND::BrainInjuryData& dst);
  static void Copy(const SEBrainInjury& src, SEBrainInjury& dst);

  static void Load(const CDM_BIND::BronchoconstrictionData& src, SEBronchoconstriction& dst);
  static CDM_BIND::BronchoconstrictionData* Unload(const SEBronchoconstriction& src);
  static void Serialize(const CDM_BIND::BronchoconstrictionData& src, SEBronchoconstriction& dst);
  static void Serialize(const SEBronchoconstriction& src, CDM_BIND::BronchoconstrictionData& dst);
  static void Copy(const SEBronchoconstriction& src, SEBronchoconstriction& dst);

  static void Load(const CDM_BIND::CardiacArrestData& src, SECardiacArrest& dst);
  static CDM_BIND::CardiacArrestData* Unload(const SECardiacArrest& src);
  static void Serialize(const CDM_BIND::CardiacArrestData& src, SECardiacArrest& dst);
  static void Serialize(const SECardiacArrest& src, CDM_BIND::CardiacArrestData& dst);
  static void Copy(const SECardiacArrest& src, SECardiacArrest& dst);

  static void Load(const CDM_BIND::ChestCompressionForceData& src, SEChestCompressionForce& dst);
  static CDM_BIND::ChestCompressionForceData* Unload(const SEChestCompressionForce& src);
  static void Serialize(const CDM_BIND::ChestCompressionForceData& src, SEChestCompressionForce& dst);
  static void Serialize(const SEChestCompressionForce& src, CDM_BIND::ChestCompressionForceData& dst);
  static void Copy(const SEChestCompressionForce& src, SEChestCompressionForce& dst);

  static void Load(const CDM_BIND::ChestCompressionForceScaleData& src, SEChestCompressionForceScale& dst);
  static CDM_BIND::ChestCompressionForceScaleData* Unload(const SEChestCompressionForceScale& src);
  static void Serialize(const CDM_BIND::ChestCompressionForceScaleData& src, SEChestCompressionForceScale& dst);
  static void Serialize(const SEChestCompressionForceScale& src, CDM_BIND::ChestCompressionForceScaleData& dst);
  static void Copy(const SEChestCompressionForceScale& src, SEChestCompressionForceScale& dst);

  static void Load(const CDM_BIND::ChestOcclusiveDressingData& src, SEChestOcclusiveDressing& dst);
  static CDM_BIND::ChestOcclusiveDressingData* Unload(const SEChestOcclusiveDressing& src);
  static void Serialize(const CDM_BIND::ChestOcclusiveDressingData& src, SEChestOcclusiveDressing& dst);
  static void Serialize(const SEChestOcclusiveDressing& src, CDM_BIND::ChestOcclusiveDressingData& dst);
  static void Copy(const SEChestOcclusiveDressing& src, SEChestOcclusiveDressing& dst);

  static void Load(const CDM_BIND::ChronicObstructivePulmonaryDiseaseExacerbationData& src, SEChronicObstructivePulmonaryDiseaseExacerbation& dst);
  static CDM_BIND::ChronicObstructivePulmonaryDiseaseExacerbationData* Unload(const SEChronicObstructivePulmonaryDiseaseExacerbation& src);
  static void Serialize(const CDM_BIND::ChronicObstructivePulmonaryDiseaseExacerbationData& src, SEChronicObstructivePulmonaryDiseaseExacerbation& dst);
  static void Serialize(const SEChronicObstructivePulmonaryDiseaseExacerbation& src, CDM_BIND::ChronicObstructivePulmonaryDiseaseExacerbationData& dst);
  static void Copy(const SEChronicObstructivePulmonaryDiseaseExacerbation& src, SEChronicObstructivePulmonaryDiseaseExacerbation& dst);

  static void Load(const CDM_BIND::ConsciousRespirationData& src, SEConsciousRespiration& dst);
  static CDM_BIND::ConsciousRespirationData* Unload(const SEConsciousRespiration& src);
  static void Serialize(const CDM_BIND::ConsciousRespirationData& src, SEConsciousRespiration& dst);
  static void Serialize(const SEConsciousRespiration& src, CDM_BIND::ConsciousRespirationData& dst);
  static void Copy(const SEConsciousRespiration& src, SEConsciousRespiration& dst);

  static void Load(const CDM_BIND::ConsumeNutrientsData& src, SEConsumeNutrients& dst);
  static CDM_BIND::ConsumeNutrientsData* Unload(const SEConsumeNutrients& src);
  static void Serialize(const CDM_BIND::ConsumeNutrientsData& src, SEConsumeNutrients& dst);
  static void Serialize(const SEConsumeNutrients& src, CDM_BIND::ConsumeNutrientsData& dst);
  static void Copy(const SEConsumeNutrients& src, SEConsumeNutrients& dst);

  static void Load(const CDM_BIND::DyspneaData& src, SEDyspnea& dst);
  static CDM_BIND::DyspneaData* Unload(const SEDyspnea& src);
  static void Serialize(const CDM_BIND::DyspneaData& src, SEDyspnea& dst);
  static void Serialize(const SEDyspnea& src, CDM_BIND::DyspneaData& dst);
  static void Copy(const SEDyspnea& src, SEDyspnea& dst);

  static void Load(const CDM_BIND::ExerciseData& src, SEExercise& dst);
  static CDM_BIND::ExerciseData* Unload(const SEExercise& src);
  static void Serialize(const CDM_BIND::ExerciseData& src, SEExercise& dst);
  static void Serialize(const SEExercise& src, CDM_BIND::ExerciseData& dst);
  static void Copy(const SEExercise& src, SEExercise& dst);

  static void Load(const CDM_BIND::ForcedExhaleData& src, SEForcedExhale& dst);
  static CDM_BIND::ForcedExhaleData* Unload(const SEForcedExhale& src);
  static void Serialize(const CDM_BIND::ForcedExhaleData& src, SEForcedExhale& dst);
  static void Serialize(const SEForcedExhale& src, CDM_BIND::ForcedExhaleData& dst);
  static void Copy(const SEForcedExhale& src, SEForcedExhale& dst);

  static void Load(const CDM_BIND::ForcedInhaleData& src, SEForcedInhale& dst);
  static CDM_BIND::ForcedInhaleData* Unload(const SEForcedInhale& src);
  static void Serialize(const CDM_BIND::ForcedInhaleData& src, SEForcedInhale& dst);
  static void Serialize(const SEForcedInhale& src, CDM_BIND::ForcedInhaleData& dst);
  static void Copy(const SEForcedInhale& src, SEForcedInhale& dst);

  static void Load(const CDM_BIND::ForcedPauseData& src, SEForcedPause& dst);
  static CDM_BIND::ForcedPauseData* Unload(const SEForcedPause& src);
  static void Serialize(const CDM_BIND::ForcedPauseData& src, SEForcedPause& dst);
  static void Serialize(const SEForcedPause& src, CDM_BIND::ForcedPauseData& dst);
  static void Copy(const SEForcedPause& src, SEForcedPause& dst);

  static void Load(const CDM_BIND::HemorrhageData& src, SEHemorrhage& dst);
  static CDM_BIND::HemorrhageData* Unload(const SEHemorrhage& src);
  static void Serialize(const CDM_BIND::HemorrhageData& src, SEHemorrhage& dst);
  static void Serialize(const SEHemorrhage& src, CDM_BIND::HemorrhageData& dst);
  static void Copy(const SEHemorrhage& src, SEHemorrhage& dst);

  static void Load(const CDM_BIND::ImpairedAlveolarExchangeExacerbationData& src, SEImpairedAlveolarExchangeExacerbation& dst);
  static CDM_BIND::ImpairedAlveolarExchangeExacerbationData* Unload(const SEImpairedAlveolarExchangeExacerbation& src);
  static void Serialize(const CDM_BIND::ImpairedAlveolarExchangeExacerbationData& src, SEImpairedAlveolarExchangeExacerbation& dst);
  static void Serialize(const SEImpairedAlveolarExchangeExacerbation& src, CDM_BIND::ImpairedAlveolarExchangeExacerbationData& dst);
  static void Copy(const SEImpairedAlveolarExchangeExacerbation& src, SEImpairedAlveolarExchangeExacerbation& dst);

  static void Load(const CDM_BIND::IntubationData& src, SEIntubation& dst);
  static CDM_BIND::IntubationData* Unload(const SEIntubation& src);
  static void Serialize(const CDM_BIND::IntubationData& src, SEIntubation& dst);
  static void Serialize(const SEIntubation& src, CDM_BIND::IntubationData& dst);
  static void Copy(const SEIntubation& src, SEIntubation& dst);

  static void Load(const CDM_BIND::LobarPneumoniaExacerbationData& src, SELobarPneumoniaExacerbation& dst);
  static CDM_BIND::LobarPneumoniaExacerbationData* Unload(const SELobarPneumoniaExacerbation& src);
  static void Serialize(const CDM_BIND::LobarPneumoniaExacerbationData& src, SELobarPneumoniaExacerbation& dst);
  static void Serialize(const SELobarPneumoniaExacerbation& src, CDM_BIND::LobarPneumoniaExacerbationData& dst);
  static void Copy(const SELobarPneumoniaExacerbation& src, SELobarPneumoniaExacerbation& dst);

  static void Load(const CDM_BIND::MechanicalVentilationData& src, SEMechanicalVentilation& dst, const SESubstanceManager& subMgr);
  static CDM_BIND::MechanicalVentilationData* Unload(const SEMechanicalVentilation& src);
  static void Serialize(const CDM_BIND::MechanicalVentilationData& src, SEMechanicalVentilation& dst, const SESubstanceManager& subMgr);
  static void Serialize(const SEMechanicalVentilation& src, CDM_BIND::MechanicalVentilationData& dst);
  static void Copy(const SEMechanicalVentilation& src, SEMechanicalVentilation& dst, const SESubstanceManager& subMgr);

  static void Load(const CDM_BIND::NeedleDecompressionData& src, SENeedleDecompression& dst);
  static CDM_BIND::NeedleDecompressionData* Unload(const SENeedleDecompression& src);
  static void Serialize(const CDM_BIND::NeedleDecompressionData& src, SENeedleDecompression& dst);
  static void Serialize(const SENeedleDecompression& src, CDM_BIND::NeedleDecompressionData& dst);
  static void Copy(const SENeedleDecompression& src, SENeedleDecompression& dst);

  static void Load(const CDM_BIND::PatientAssessmentRequestData& src, SEPatientAssessmentRequest& dst);
  static CDM_BIND::PatientAssessmentRequestData* Unload(const SEPatientAssessmentRequest& src);
  static void Serialize(const CDM_BIND::PatientAssessmentRequestData& src, SEPatientAssessmentRequest& dst);
  static void Serialize(const SEPatientAssessmentRequest& src, CDM_BIND::PatientAssessmentRequestData& dst);
  static void Copy(const SEPatientAssessmentRequest& src, SEPatientAssessmentRequest& dst);

  static void Load(const CDM_BIND::PericardialEffusionData& src, SEPericardialEffusion& dst);
  static CDM_BIND::PericardialEffusionData* Unload(const SEPericardialEffusion& src);
  static void Serialize(const CDM_BIND::PericardialEffusionData& src, SEPericardialEffusion& dst);
  static void Serialize(const SEPericardialEffusion& src, CDM_BIND::PericardialEffusionData& dst);
  static void Copy(const SEPericardialEffusion& src, SEPericardialEffusion& dst);

  static void Load(const CDM_BIND::PulmonaryShuntExacerbationData& src, SEPulmonaryShuntExacerbation& dst);
  static CDM_BIND::PulmonaryShuntExacerbationData* Unload(const SEPulmonaryShuntExacerbation& src);
  static void Serialize(const CDM_BIND::PulmonaryShuntExacerbationData& src, SEPulmonaryShuntExacerbation& dst);
  static void Serialize(const SEPulmonaryShuntExacerbation& src, CDM_BIND::PulmonaryShuntExacerbationData& dst);
  static void Copy(const SEPulmonaryShuntExacerbation& src, SEPulmonaryShuntExacerbation& dst);

  static void Load(const CDM_BIND::RespiratoryFatigueData& src, SERespiratoryFatigue& dst);
  static CDM_BIND::RespiratoryFatigueData* Unload(const SERespiratoryFatigue& src);
  static void Serialize(const CDM_BIND::RespiratoryFatigueData& src, SERespiratoryFatigue& dst);
  static void Serialize(const SERespiratoryFatigue& src, CDM_BIND::RespiratoryFatigueData& dst);
  static void Copy(const SERespiratoryFatigue& src, SERespiratoryFatigue& dst);

  static void Load(const CDM_BIND::SubstanceBolusStateData& src, SESubstanceBolusState& dst);
  static CDM_BIND::SubstanceBolusStateData* Unload(const SESubstanceBolusState& src);
  static void Serialize(const CDM_BIND::SubstanceBolusStateData& src, SESubstanceBolusState& dst);
  static void Serialize(const SESubstanceBolusState& src, CDM_BIND::SubstanceBolusStateData& dst);
  static void Copy(const SESubstanceBolusState& src, SESubstanceBolusState& dst);

  static void Load(const CDM_BIND::SubstanceBolusData& src, SESubstanceBolus& dst);
  static CDM_BIND::SubstanceBolusData* Unload(const SESubstanceBolus& src);
  static void Serialize(const CDM_BIND::SubstanceBolusData& src, SESubstanceBolus& dst);
  static void Serialize(const SESubstanceBolus& src, CDM_BIND::SubstanceBolusData& dst);
  static void Copy(const SESubstanceBolus& src, SESubstanceBolus& dst);

  static void Load(const CDM_BIND::SubstanceCompoundInfusionData& src, SESubstanceCompoundInfusion& dst);
  static CDM_BIND::SubstanceCompoundInfusionData* Unload(const SESubstanceCompoundInfusion& src);
  static void Serialize(const CDM_BIND::SubstanceCompoundInfusionData& src, SESubstanceCompoundInfusion& dst);
  static void Serialize(const SESubstanceCompoundInfusion& src, CDM_BIND::SubstanceCompoundInfusionData& dst);
  static void Copy(const SESubstanceCompoundInfusion& src, SESubstanceCompoundInfusion& dst);

  static void Load(const CDM_BIND::SubstanceInfusionData& src, SESubstanceInfusion& dst);
  static CDM_BIND::SubstanceInfusionData* Unload(const SESubstanceInfusion& src);
  static void Serialize(const CDM_BIND::SubstanceInfusionData& src, SESubstanceInfusion& dst);
  static void Serialize(const SESubstanceInfusion& src, CDM_BIND::SubstanceInfusionData& dst);
  static void Copy(const SESubstanceInfusion& src, SESubstanceInfusion& dst);

  static void Load(const CDM_BIND::SupplementalOxygenData& src, SESupplementalOxygen& dst);
  static CDM_BIND::SupplementalOxygenData* Unload(const SESupplementalOxygen& src);
  static void Serialize(const CDM_BIND::SupplementalOxygenData& src, SESupplementalOxygen& dst);
  static void Serialize(const SESupplementalOxygen& src, CDM_BIND::SupplementalOxygenData& dst);
  static void Copy(const SESupplementalOxygen& src, SESupplementalOxygen& dst);

  static void Load(const CDM_BIND::TensionPneumothoraxData& src, SETensionPneumothorax& dst);
  static CDM_BIND::TensionPneumothoraxData* Unload(const SETensionPneumothorax& src);
  static void Serialize(const CDM_BIND::TensionPneumothoraxData& src, SETensionPneumothorax& dst);
  static void Serialize(const SETensionPneumothorax& src, CDM_BIND::TensionPneumothoraxData& dst);
  static void Copy(const SETensionPneumothorax& src, SETensionPneumothorax& dst);

  static void Load(const CDM_BIND::UrinateData& src, SEUrinate& dst);
  static CDM_BIND::UrinateData* Unload(const SEUrinate& src);
  static void Serialize(const CDM_BIND::UrinateData& src, SEUrinate& dst);
  static void Serialize(const SEUrinate& src, CDM_BIND::UrinateData& dst);
  static void Copy(const SEUrinate& src, SEUrinate& dst);

  static void Load(const CDM_BIND::UseInhalerData& src, SEUseInhaler& dst);
  static CDM_BIND::UseInhalerData* Unload(const SEUseInhaler& src);
  static void Serialize(const CDM_BIND::UseInhalerData& src, SEUseInhaler& dst);
  static void Serialize(const SEUseInhaler& src, CDM_BIND::UseInhalerData& dst);
  static void Copy(const SEUseInhaler& src, SEUseInhaler& dst);

};