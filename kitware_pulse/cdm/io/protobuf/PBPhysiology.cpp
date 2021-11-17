/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#include "stdafx.h"
PUSH_PROTO_WARNINGS()
#include "pulse/cdm/bind/Physiology.pb.h"
POP_PROTO_WARNINGS()
#include "io/protobuf/PBPhysiology.h"
#include "io/protobuf/PBPatientNutrition.h"
#include "io/protobuf/PBProperties.h"
#include "system/physiology/SEBloodChemistrySystem.h"
#include "system/physiology/SECardiovascularSystem.h"
#include "system/physiology/SEDrugSystem.h"
#include "system/physiology/SEEndocrineSystem.h"
#include "system/physiology/SEEnergySystem.h"
#include "system/physiology/SEGastrointestinalSystem.h"
#include "system/physiology/SEHepaticSystem.h"
#include "system/physiology/SENervousSystem.h"
#include "system/physiology/SEPupillaryResponse.h"
#include "system/physiology/SERenalSystem.h"
#include "system/physiology/SERespiratorySystem.h"
#include "system/physiology/SETissueSystem.h"

void PBPhysiology::Load(const CDM_BIND::BloodChemistrySystemData& src, SEBloodChemistrySystem& dst)
{
  dst.Clear();
  PBPhysiology::Serialize(src, dst);
}
void PBPhysiology::Serialize(const CDM_BIND::BloodChemistrySystemData& src, SEBloodChemistrySystem& dst)
{
  if (src.has_blooddensity())
    PBProperty::Load(src.blooddensity(), dst.GetBloodDensity());
  if (src.has_bloodph())
    PBProperty::Load(src.bloodph(), dst.GetBloodPH());
  if (src.has_bloodspecificheat())
    PBProperty::Load(src.bloodspecificheat(), dst.GetBloodSpecificHeat());
  if (src.has_bloodureanitrogenconcentration())
    PBProperty::Load(src.bloodureanitrogenconcentration(), dst.GetBloodUreaNitrogenConcentration());
  if (src.has_carbondioxidesaturation())
    PBProperty::Load(src.carbondioxidesaturation(), dst.GetCarbonDioxideSaturation());
  if (src.has_carbonmonoxidesaturation())
    PBProperty::Load(src.carbonmonoxidesaturation(), dst.GetCarbonMonoxideSaturation());
  if (src.has_hematocrit())
    PBProperty::Load(src.hematocrit(), dst.GetHematocrit());
  if (src.has_hemoglobincontent())
    PBProperty::Load(src.hemoglobincontent(), dst.GetHemoglobinContent());
  if (src.has_oxygensaturation())
    PBProperty::Load(src.oxygensaturation(), dst.GetOxygenSaturation());
  if (src.has_phosphate())
    PBProperty::Load(src.phosphate(), dst.GetPhosphate());
  if (src.has_plasmavolume())
    PBProperty::Load(src.plasmavolume(), dst.GetPlasmaVolume());
  if (src.has_pulseoximetry())
    PBProperty::Load(src.pulseoximetry(), dst.GetPulseOximetry());
  if (src.has_redbloodcellcount())
    PBProperty::Load(src.redbloodcellcount(), dst.GetRedBloodCellCount());
  if (src.has_shuntfraction())
    PBProperty::Load(src.shuntfraction(), dst.GetShuntFraction());
  if (src.has_strongiondifference())
    PBProperty::Load(src.strongiondifference(), dst.GetStrongIonDifference());
  if (src.has_totalproteinconcentration())
    PBProperty::Load(src.totalproteinconcentration(), dst.GetTotalProteinConcentration());
  if (src.has_volumefractionneutralphospholipidinplasma())
    PBProperty::Load(src.volumefractionneutralphospholipidinplasma(), dst.GetVolumeFractionNeutralPhospholipidInPlasma());
  if (src.has_volumefractionneutrallipidinplasma())
    PBProperty::Load(src.volumefractionneutrallipidinplasma(), dst.GetVolumeFractionNeutralLipidInPlasma());
  if (src.has_whitebloodcellcount())
    PBProperty::Load(src.whitebloodcellcount(), dst.GetWhiteBloodCellCount());

  if (src.has_arterialcarbondioxidepressure())
    PBProperty::Load(src.arterialcarbondioxidepressure(), dst.GetArterialCarbonDioxidePressure());
  if (src.has_arterialoxygenpressure())
    PBProperty::Load(src.arterialoxygenpressure(), dst.GetArterialOxygenPressure());
  if (src.has_pulmonaryarterialcarbondioxidepressure())
    PBProperty::Load(src.pulmonaryarterialcarbondioxidepressure(), dst.GetPulmonaryArterialCarbonDioxidePressure());
  if (src.has_pulmonaryarterialoxygenpressure())
    PBProperty::Load(src.pulmonaryarterialoxygenpressure(), dst.GetPulmonaryArterialOxygenPressure());
  if (src.has_pulmonaryvenousoxygenpressure())
    PBProperty::Load(src.pulmonaryvenousoxygenpressure(), dst.GetPulmonaryVenousOxygenPressure());
  if (src.has_pulmonaryvenouscarbondioxidepressure())
    PBProperty::Load(src.pulmonaryvenouscarbondioxidepressure(), dst.GetPulmonaryVenousCarbonDioxidePressure());
  if (src.has_venouscarbondioxidepressure())
    PBProperty::Load(src.venouscarbondioxidepressure(), dst.GetVenousCarbonDioxidePressure());
  if (src.has_venousoxygenpressure())
    PBProperty::Load(src.venousoxygenpressure(), dst.GetVenousOxygenPressure());
}

CDM_BIND::BloodChemistrySystemData* PBPhysiology::Unload(const SEBloodChemistrySystem& src)
{
  CDM_BIND::BloodChemistrySystemData* dst = new CDM_BIND::BloodChemistrySystemData();
  PBPhysiology::Serialize(src, *dst);
  return dst;
}
void PBPhysiology::Serialize(const SEBloodChemistrySystem& src, CDM_BIND::BloodChemistrySystemData& dst)
{
  if (src.HasBloodDensity())
    dst.set_allocated_blooddensity(PBProperty::Unload(*src.m_BloodDensity));
  if (src.HasBloodPH())
    dst.set_allocated_bloodph(PBProperty::Unload(*src.m_BloodPH));
  if (src.HasBloodSpecificHeat())
    dst.set_allocated_bloodspecificheat(PBProperty::Unload(*src.m_BloodSpecificHeat));
  if (src.HasBloodUreaNitrogenConcentration())
    dst.set_allocated_bloodureanitrogenconcentration(PBProperty::Unload(*src.m_BloodUreaNitrogenConcentration));
  if (src.HasCarbonDioxideSaturation())
    dst.set_allocated_carbondioxidesaturation(PBProperty::Unload(*src.m_CarbonDioxideSaturation));
  if (src.HasCarbonMonoxideSaturation())
    dst.set_allocated_carbonmonoxidesaturation(PBProperty::Unload(*src.m_CarbonMonoxideSaturation));
  if (src.HasHematocrit())
    dst.set_allocated_hematocrit(PBProperty::Unload(*src.m_Hematocrit));
  if (src.HasHemoglobinContent())
    dst.set_allocated_hemoglobincontent(PBProperty::Unload(*src.m_HemoglobinContent));
  if (src.HasOxygenSaturation())
    dst.set_allocated_oxygensaturation(PBProperty::Unload(*src.m_OxygenSaturation));
  if (src.HasPhosphate())
    dst.set_allocated_phosphate(PBProperty::Unload(*src.m_Phosphate));
  if (src.HasPlasmaVolume())
    dst.set_allocated_plasmavolume(PBProperty::Unload(*src.m_PlasmaVolume));
  if (src.HasPulseOximetry())
    dst.set_allocated_pulseoximetry(PBProperty::Unload(*src.m_PulseOximetry));
  if (src.HasRedBloodCellCount())
    dst.set_allocated_redbloodcellcount(PBProperty::Unload(*src.m_RedBloodCellCount));
  if (src.HasShuntFraction())
    dst.set_allocated_shuntfraction(PBProperty::Unload(*src.m_ShuntFraction));
  if (src.HasStrongIonDifference())
    dst.set_allocated_strongiondifference(PBProperty::Unload(*src.m_StrongIonDifference));
  if (src.HasTotalProteinConcentration())
    dst.set_allocated_totalproteinconcentration(PBProperty::Unload(*src.m_TotalProteinConcentration));
  if (src.HasVolumeFractionNeutralPhospholipidInPlasma())
    dst.set_allocated_volumefractionneutralphospholipidinplasma(PBProperty::Unload(*src.m_VolumeFractionNeutralPhospholipidInPlasma));
  if (src.HasVolumeFractionNeutralLipidInPlasma())
    dst.set_allocated_volumefractionneutrallipidinplasma(PBProperty::Unload(*src.m_VolumeFractionNeutralLipidInPlasma));
  if (src.HasWhiteBloodCellCount())
    dst.set_allocated_whitebloodcellcount(PBProperty::Unload(*src.m_WhiteBloodCellCount));

  if (src.HasArterialCarbonDioxidePressure())
    dst.set_allocated_arterialcarbondioxidepressure(PBProperty::Unload(*src.m_ArterialCarbonDioxidePressure));
  if (src.HasArterialOxygenPressure())
    dst.set_allocated_arterialoxygenpressure(PBProperty::Unload(*src.m_ArterialOxygenPressure));
  if (src.HasPulmonaryArterialCarbonDioxidePressure())
    dst.set_allocated_pulmonaryarterialcarbondioxidepressure(PBProperty::Unload(*src.m_PulmonaryArterialCarbonDioxidePressure));
  if (src.HasPulmonaryArterialOxygenPressure())
    dst.set_allocated_pulmonaryarterialoxygenpressure(PBProperty::Unload(*src.m_PulmonaryArterialOxygenPressure));
  if (src.HasPulmonaryVenousCarbonDioxidePressure())
    dst.set_allocated_pulmonaryvenouscarbondioxidepressure(PBProperty::Unload(*src.m_PulmonaryVenousCarbonDioxidePressure));
  if (src.HasPulmonaryVenousOxygenPressure())
    dst.set_allocated_pulmonaryvenousoxygenpressure(PBProperty::Unload(*src.m_PulmonaryVenousOxygenPressure));
  if (src.HasVenousCarbonDioxidePressure())
    dst.set_allocated_venouscarbondioxidepressure(PBProperty::Unload(*src.m_VenousCarbonDioxidePressure));
  if (src.HasVenousOxygenPressure())
    dst.set_allocated_venousoxygenpressure(PBProperty::Unload(*src.m_VenousOxygenPressure));
}

void PBPhysiology::Load(const CDM_BIND::CardiovascularSystemData& src, SECardiovascularSystem& dst)
{
  dst.Clear();
  PBPhysiology::Serialize(src, dst);
}
void PBPhysiology::Serialize(const CDM_BIND::CardiovascularSystemData& src, SECardiovascularSystem& dst)
{
  if (src.has_arterialpressure())
    PBProperty::Load(src.arterialpressure(), dst.GetArterialPressure());
  if (src.has_bloodvolume())
    PBProperty::Load(src.bloodvolume(), dst.GetBloodVolume());
  if (src.has_cardiacindex())
    PBProperty::Load(src.cardiacindex(), dst.GetCardiacIndex());
  if (src.has_cardiacoutput())
    PBProperty::Load(src.cardiacoutput(), dst.GetCardiacOutput());
  if (src.has_centralvenouspressure())
    PBProperty::Load(src.centralvenouspressure(), dst.GetCentralVenousPressure());
  if (src.has_cerebralbloodflow())
    PBProperty::Load(src.cerebralbloodflow(), dst.GetCerebralBloodFlow());
  if (src.has_cerebralperfusionpressure())
    PBProperty::Load(src.cerebralperfusionpressure(), dst.GetCerebralPerfusionPressure());
  if (src.has_diastolicarterialpressure())
    PBProperty::Load(src.diastolicarterialpressure(), dst.GetDiastolicArterialPressure());
  if (src.has_heartejectionfraction())
    PBProperty::Load(src.heartejectionfraction(), dst.GetHeartEjectionFraction());
  if (src.has_heartrate())
    PBProperty::Load(src.heartrate(), dst.GetHeartRate());
  dst.SetHeartRhythm((eHeartRhythm)src.heartrhythm());
  if (src.has_heartstrokevolume())
    PBProperty::Load(src.heartstrokevolume(), dst.GetHeartStrokeVolume());
  if (src.has_intracranialpressure())
    PBProperty::Load(src.intracranialpressure(), dst.GetIntracranialPressure());
  if (src.has_meanarterialpressure())
    PBProperty::Load(src.meanarterialpressure(), dst.GetMeanArterialPressure());
  if (src.has_meanarterialcarbondioxidepartialpressure())
    PBProperty::Load(src.meanarterialcarbondioxidepartialpressure(), dst.GetMeanArterialCarbonDioxidePartialPressure());
  if (src.has_meanarterialcarbondioxidepartialpressuredelta())
    PBProperty::Load(src.meanarterialcarbondioxidepartialpressuredelta(), dst.GetMeanArterialCarbonDioxidePartialPressureDelta());
  if (src.has_meancentralvenouspressure())
    PBProperty::Load(src.meancentralvenouspressure(), dst.GetMeanCentralVenousPressure());
  if (src.has_meanskinflow())
    PBProperty::Load(src.meanskinflow(), dst.GetMeanSkinFlow());
  if (src.has_pulmonaryarterialpressure())
    PBProperty::Load(src.pulmonaryarterialpressure(), dst.GetPulmonaryArterialPressure());
  if (src.has_pulmonarycapillarieswedgepressure())
    PBProperty::Load(src.pulmonarycapillarieswedgepressure(), dst.GetPulmonaryCapillariesWedgePressure());
  if (src.has_pulmonarydiastolicarterialpressure())
    PBProperty::Load(src.pulmonarydiastolicarterialpressure(), dst.GetPulmonaryDiastolicArterialPressure());
  if (src.has_pulmonarymeanarterialpressure())
    PBProperty::Load(src.pulmonarymeanarterialpressure(), dst.GetPulmonaryMeanArterialPressure());
  if (src.has_pulmonarymeancapillaryflow())
    PBProperty::Load(src.pulmonarymeancapillaryflow(), dst.GetPulmonaryMeanCapillaryFlow());
  if (src.has_pulmonarymeanshuntflow())
    PBProperty::Load(src.pulmonarymeanshuntflow(), dst.GetPulmonaryMeanShuntFlow());
  if (src.has_pulmonarysystolicarterialpressure())
    PBProperty::Load(src.pulmonarysystolicarterialpressure(), dst.GetPulmonarySystolicArterialPressure());
  if (src.has_pulmonaryvascularresistance())
    PBProperty::Load(src.pulmonaryvascularresistance(), dst.GetPulmonaryVascularResistance());
  if (src.has_pulmonaryvascularresistanceindex())
    PBProperty::Load(src.pulmonaryvascularresistanceindex(), dst.GetPulmonaryVascularResistanceIndex());
  if (src.has_pulsepressure())
    PBProperty::Load(src.pulsepressure(), dst.GetPulsePressure());
  if (src.has_systemicvascularresistance())
    PBProperty::Load(src.systemicvascularresistance(), dst.GetSystemicVascularResistance());
  if (src.has_systolicarterialpressure())
    PBProperty::Load(src.systolicarterialpressure(), dst.GetSystolicArterialPressure());
  if (src.has_totalhemorrhagerate())
    PBProperty::Load(src.totalhemorrhagerate(), dst.GetTotalHemorrhageRate());
  if (src.has_totalhemorrhagedvolume())
    PBProperty::Load(src.totalhemorrhagedvolume(), dst.GetTotalHemorrhagedVolume());
}

CDM_BIND::CardiovascularSystemData* PBPhysiology::Unload(const SECardiovascularSystem& src)
{
  CDM_BIND::CardiovascularSystemData* dst = new CDM_BIND::CardiovascularSystemData();
  PBPhysiology::Serialize(src, *dst);
  return dst;
}
void PBPhysiology::Serialize(const SECardiovascularSystem& src, CDM_BIND::CardiovascularSystemData& dst)
{
  if (src.HasArterialPressure())
    dst.set_allocated_arterialpressure(PBProperty::Unload(*src.m_ArterialPressure));
  if (src.HasBloodVolume())
    dst.set_allocated_bloodvolume(PBProperty::Unload(*src.m_BloodVolume));
  if (src.HasCardiacIndex())
    dst.set_allocated_cardiacindex(PBProperty::Unload(*src.m_CardiacIndex));
  if (src.HasCardiacOutput())
    dst.set_allocated_cardiacoutput(PBProperty::Unload(*src.m_CardiacOutput));
  if (src.HasCentralVenousPressure())
    dst.set_allocated_centralvenouspressure(PBProperty::Unload(*src.m_CentralVenousPressure));
  if (src.HasCerebralBloodFlow())
    dst.set_allocated_cerebralbloodflow(PBProperty::Unload(*src.m_CerebralBloodFlow));
  if (src.HasCerebralPerfusionPressure())
    dst.set_allocated_cerebralperfusionpressure(PBProperty::Unload(*src.m_CerebralPerfusionPressure));
  if (src.HasDiastolicArterialPressure())
    dst.set_allocated_diastolicarterialpressure(PBProperty::Unload(*src.m_DiastolicArterialPressure));
  if (src.HasHeartEjectionFraction())
    dst.set_allocated_heartejectionfraction(PBProperty::Unload(*src.m_HeartEjectionFraction));
  if (src.HasHeartRate())
    dst.set_allocated_heartrate(PBProperty::Unload(*src.m_HeartRate));
  dst.set_heartrhythm((CDM_BIND::eHeartRhythm)src.m_HeartRhythm);
  if (src.HasHeartStrokeVolume())
    dst.set_allocated_heartstrokevolume(PBProperty::Unload(*src.m_HeartStrokeVolume));
  if (src.HasIntracranialPressure())
    dst.set_allocated_intracranialpressure(PBProperty::Unload(*src.m_IntracranialPressure));
  if (src.HasMeanArterialPressure())
    dst.set_allocated_meanarterialpressure(PBProperty::Unload(*src.m_MeanArterialPressure));
  if (src.HasMeanArterialCarbonDioxidePartialPressure())
    dst.set_allocated_meanarterialcarbondioxidepartialpressure(PBProperty::Unload(*src.m_MeanArterialCarbonDioxidePartialPressure));
  if (src.HasMeanArterialCarbonDioxidePartialPressureDelta())
    dst.set_allocated_meanarterialcarbondioxidepartialpressuredelta(PBProperty::Unload(*src.m_MeanArterialCarbonDioxidePartialPressureDelta));
  if (src.HasMeanCentralVenousPressure())
    dst.set_allocated_meancentralvenouspressure(PBProperty::Unload(*src.m_MeanCentralVenousPressure));
  if (src.HasMeanSkinFlow())
    dst.set_allocated_meanskinflow(PBProperty::Unload(*src.m_MeanSkinFlow));
  if (src.HasPulmonaryArterialPressure())
    dst.set_allocated_pulmonaryarterialpressure(PBProperty::Unload(*src.m_PulmonaryArterialPressure));
  if (src.HasPulmonaryCapillariesWedgePressure())
    dst.set_allocated_pulmonarycapillarieswedgepressure(PBProperty::Unload(*src.m_PulmonaryCapillariesWedgePressure));
  if (src.HasPulmonaryDiastolicArterialPressure())
    dst.set_allocated_pulmonarydiastolicarterialpressure(PBProperty::Unload(*src.m_PulmonaryDiastolicArterialPressure));
  if (src.HasPulmonaryMeanArterialPressure())
    dst.set_allocated_pulmonarymeanarterialpressure(PBProperty::Unload(*src.m_PulmonaryMeanArterialPressure));
  if (src.HasPulmonaryMeanCapillaryFlow())
    dst.set_allocated_pulmonarymeancapillaryflow(PBProperty::Unload(*src.m_PulmonaryMeanCapillaryFlow));
  if (src.HasPulmonaryMeanShuntFlow())
    dst.set_allocated_pulmonarymeanshuntflow(PBProperty::Unload(*src.m_PulmonaryMeanShuntFlow));
  if (src.HasPulmonarySystolicArterialPressure())
    dst.set_allocated_pulmonarysystolicarterialpressure(PBProperty::Unload(*src.m_PulmonarySystolicArterialPressure));
  if (src.HasPulmonaryVascularResistance())
    dst.set_allocated_pulmonaryvascularresistance(PBProperty::Unload(*src.m_PulmonaryVascularResistance));
  if (src.HasPulmonaryVascularResistanceIndex())
    dst.set_allocated_pulmonaryvascularresistanceindex(PBProperty::Unload(*src.m_PulmonaryVascularResistanceIndex));
  if (src.HasPulsePressure())
    dst.set_allocated_pulsepressure(PBProperty::Unload(*src.m_PulsePressure));
  if (src.HasSystemicVascularResistance())
    dst.set_allocated_systemicvascularresistance(PBProperty::Unload(*src.m_SystemicVascularResistance));
  if (src.HasSystolicArterialPressure())
    dst.set_allocated_systolicarterialpressure(PBProperty::Unload(*src.m_SystolicArterialPressure));
  if (src.HasTotalHemorrhageRate())
    dst.set_allocated_totalhemorrhagerate(PBProperty::Unload(*src.m_TotalHemorrhageRate));
  if (src.HasTotalHemorrhagedVolume())
    dst.set_allocated_totalhemorrhagedvolume(PBProperty::Unload(*src.m_TotalHemorrhagedVolume));
}


void PBPhysiology::Load(const CDM_BIND::DrugSystemData& src, SEDrugSystem& dst)
{
  dst.Clear();
  PBPhysiology::Serialize(src, dst);
}
void PBPhysiology::Serialize(const CDM_BIND::DrugSystemData& src, SEDrugSystem& dst)
{
  if (src.has_bronchodilationlevel())
    PBProperty::Load(src.bronchodilationlevel(), dst.GetBronchodilationLevel());
  if (src.has_heartratechange())
    PBProperty::Load(src.heartratechange(), dst.GetHeartRateChange());
  if (src.has_meanbloodpressurechange())
    PBProperty::Load(src.meanbloodpressurechange(), dst.GetMeanBloodPressureChange());
  if (src.has_neuromuscularblocklevel())
    PBProperty::Load(src.neuromuscularblocklevel(), dst.GetNeuromuscularBlockLevel());
  if (src.has_pulsepressurechange())
    PBProperty::Load(src.pulsepressurechange(), dst.GetPulsePressureChange());
  if (src.has_pupillaryresponse())
    PBPhysiology::Load(src.pupillaryresponse(), dst.GetPupillaryResponse());
  if (src.has_respirationratechange())
    PBProperty::Load(src.respirationratechange(), dst.GetRespirationRateChange());
  if (src.has_sedationlevel())
    PBProperty::Load(src.sedationlevel(), dst.GetSedationLevel());
  if (src.has_tidalvolumechange())
    PBProperty::Load(src.tidalvolumechange(), dst.GetTidalVolumeChange());
  if (src.has_tubularpermeabilitychange())
    PBProperty::Load(src.tubularpermeabilitychange(), dst.GetTubularPermeabilityChange());
}

CDM_BIND::DrugSystemData* PBPhysiology::Unload(const SEDrugSystem& src)
{
  CDM_BIND::DrugSystemData* dst = new CDM_BIND::DrugSystemData();
  PBPhysiology::Serialize(src, *dst);
  return dst;
}
void PBPhysiology::Serialize(const SEDrugSystem& src, CDM_BIND::DrugSystemData& dst)
{
  if (src.HasBronchodilationLevel())
    dst.set_allocated_bronchodilationlevel(PBProperty::Unload(*src.m_BronchodilationLevel));
  if (src.HasHeartRateChange())
    dst.set_allocated_heartratechange(PBProperty::Unload(*src.m_HeartRateChange));
  if (src.HasMeanBloodPressureChange())
    dst.set_allocated_meanbloodpressurechange(PBProperty::Unload(*src.m_MeanBloodPressureChange));
  if (src.HasNeuromuscularBlockLevel())
    dst.set_allocated_neuromuscularblocklevel(PBProperty::Unload(*src.m_NeuromuscularBlockLevel));
  if (src.HasPulsePressureChange())
    dst.set_allocated_pulsepressurechange(PBProperty::Unload(*src.m_PulsePressureChange));
  if (src.HasPupillaryResponse())
    dst.set_allocated_pupillaryresponse(PBPhysiology::Unload(*src.m_PupillaryResponse));
  if (src.HasRespirationRateChange())
    dst.set_allocated_respirationratechange(PBProperty::Unload(*src.m_RespirationRateChange));
  if (src.HasSedationLevel())
    dst.set_allocated_sedationlevel(PBProperty::Unload(*src.m_SedationLevel));
  if (src.HasTidalVolumeChange())
    dst.set_allocated_tidalvolumechange(PBProperty::Unload(*src.m_TidalVolumeChange));
  if (src.HasTubularPermeabilityChange())
    dst.set_allocated_tubularpermeabilitychange(PBProperty::Unload(*src.m_TubularPermeabilityChange));
}


void PBPhysiology::Load(const CDM_BIND::EndocrineSystemData& src, SEEndocrineSystem& dst)
{
  dst.Clear();
  PBPhysiology::Serialize(src, dst);
}
void PBPhysiology::Serialize(const CDM_BIND::EndocrineSystemData& src, SEEndocrineSystem& dst)
{
  if (src.has_insulinsynthesisrate())
    PBProperty::Load(src.insulinsynthesisrate(), dst.GetInsulinSynthesisRate());
}

CDM_BIND::EndocrineSystemData* PBPhysiology::Unload(const SEEndocrineSystem& src)
{
  CDM_BIND::EndocrineSystemData* dst = new CDM_BIND::EndocrineSystemData();
  PBPhysiology::Serialize(src, *dst);
  return dst;
}
void PBPhysiology::Serialize(const SEEndocrineSystem& src, CDM_BIND::EndocrineSystemData& dst)
{
  if (src.HasInsulinSynthesisRate())
    dst.set_allocated_insulinsynthesisrate(PBProperty::Unload(*src.m_InsulinSynthesisRate));
}

void PBPhysiology::Load(const CDM_BIND::EnergySystemData& src, SEEnergySystem& dst)
{
  dst.Clear();
  PBPhysiology::Serialize(src, dst);
}
void PBPhysiology::Serialize(const CDM_BIND::EnergySystemData& src, SEEnergySystem& dst)
{
  if (src.has_achievedexerciselevel())
    PBProperty::Load(src.achievedexerciselevel(), dst.GetAchievedExerciseLevel());
  if (src.has_coretemperature())
    PBProperty::Load(src.coretemperature(), dst.GetCoreTemperature());
  if (src.has_creatinineproductionrate())
    PBProperty::Load(src.creatinineproductionrate(), dst.GetCreatinineProductionRate());
  if (src.has_exercisemeanarterialpressuredelta())
    PBProperty::Load(src.exercisemeanarterialpressuredelta(), dst.GetExerciseMeanArterialPressureDelta());
  if (src.has_fatiguelevel())
    PBProperty::Load(src.fatiguelevel(), dst.GetFatigueLevel());
  if (src.has_ketoneproductionrate())
    PBProperty::Load(src.ketoneproductionrate(), dst.GetKetoneProductionRate());
  if (src.has_lactateproductionrate())
    PBProperty::Load(src.lactateproductionrate(), dst.GetLactateProductionRate());
  if (src.has_skintemperature())
    PBProperty::Load(src.skintemperature(), dst.GetSkinTemperature());
  if (src.has_sweatrate())
    PBProperty::Load(src.sweatrate(), dst.GetSweatRate());
  if (src.has_totalmetabolicrate())
    PBProperty::Load(src.totalmetabolicrate(), dst.GetTotalMetabolicRate());
  if (src.has_totalworkratelevel())
    PBProperty::Load(src.totalworkratelevel(), dst.GetTotalWorkRateLevel());
}

CDM_BIND::EnergySystemData* PBPhysiology::Unload(const SEEnergySystem& src)
{
  CDM_BIND::EnergySystemData* dst = new CDM_BIND::EnergySystemData();
  PBPhysiology::Serialize(src, *dst);
  return dst;
}
void PBPhysiology::Serialize(const SEEnergySystem& src, CDM_BIND::EnergySystemData& dst)
{
  if (src.HasAchievedExerciseLevel())
    dst.set_allocated_achievedexerciselevel(PBProperty::Unload(*src.m_AchievedExerciseLevel));
  if (src.HasCoreTemperature())
    dst.set_allocated_coretemperature(PBProperty::Unload(*src.m_CoreTemperature));
  if (src.HasCreatinineProductionRate())
    dst.set_allocated_creatinineproductionrate(PBProperty::Unload(*src.m_CreatinineProductionRate));
  if (src.HasExerciseMeanArterialPressureDelta())
    dst.set_allocated_exercisemeanarterialpressuredelta(PBProperty::Unload(*src.m_ExerciseMeanArterialPressureDelta));
  if (src.HasFatigueLevel())
    dst.set_allocated_fatiguelevel(PBProperty::Unload(*src.m_FatigueLevel));
  if (src.HasKetoneProductionRate())
    dst.set_allocated_ketoneproductionrate(PBProperty::Unload(*src.m_KetoneProductionRate));
  if (src.HasLactateProductionRate())
    dst.set_allocated_lactateproductionrate(PBProperty::Unload(*src.m_LactateProductionRate));
  if (src.HasSkinTemperature())
    dst.set_allocated_skintemperature(PBProperty::Unload(*src.m_SkinTemperature));
  if (src.HasSweatRate())
    dst.set_allocated_sweatrate(PBProperty::Unload(*src.m_SweatRate));
  if (src.HasTotalMetabolicRate())
    dst.set_allocated_totalmetabolicrate(PBProperty::Unload(*src.m_TotalMetabolicRate));
  if (src.HasTotalWorkRateLevel())
    dst.set_allocated_totalworkratelevel(PBProperty::Unload(*src.m_TotalWorkRateLevel));
}

void PBPhysiology::Load(const CDM_BIND::GastrointestinalSystemData& src, SEGastrointestinalSystem& dst)
{
  dst.Clear();
  PBPhysiology::Serialize(src, dst);
}
void PBPhysiology::Serialize(const CDM_BIND::GastrointestinalSystemData& src, SEGastrointestinalSystem& dst)
{
  if (src.has_waterabsorptionrate())
    PBProperty::Load(src.waterabsorptionrate(), dst.GetWaterAbsorptionRate());
  if (src.has_stomachcontents())
    PBPatientNutrition::Load(src.stomachcontents(), dst.GetStomachContents());
}

CDM_BIND::GastrointestinalSystemData* PBPhysiology::Unload(const SEGastrointestinalSystem& src)
{
  CDM_BIND::GastrointestinalSystemData* dst = new CDM_BIND::GastrointestinalSystemData();
  PBPhysiology::Serialize(src, *dst);
  return dst;
}
void PBPhysiology::Serialize(const SEGastrointestinalSystem& src, CDM_BIND::GastrointestinalSystemData& dst)
{
  if (src.HasWaterAbsorptionRate())
    dst.set_allocated_waterabsorptionrate(PBProperty::Unload(*src.m_WaterAbsorptionRate));
  if (src.HasStomachContents())
    dst.set_allocated_stomachcontents(PBPatientNutrition::Unload(*src.m_StomachContents));
}


void PBPhysiology::Load(const CDM_BIND::HepaticSystemData& src, SEHepaticSystem& dst)
{
  dst.Clear();
  PBPhysiology::Serialize(src, dst);
}
void PBPhysiology::Serialize(const CDM_BIND::HepaticSystemData& src, SEHepaticSystem& dst)
{

}

CDM_BIND::HepaticSystemData* PBPhysiology::Unload(const SEHepaticSystem& src)
{
  CDM_BIND::HepaticSystemData* dst = new CDM_BIND::HepaticSystemData();
  PBPhysiology::Serialize(src, *dst);
  return dst;
}
void PBPhysiology::Serialize(const SEHepaticSystem& src, CDM_BIND::HepaticSystemData& dst)
{

}

void PBPhysiology::Load(const CDM_BIND::NervousSystemData& src, SENervousSystem& dst)
{
  dst.Clear();
  PBPhysiology::Serialize(src, dst);
}
void PBPhysiology::Serialize(const CDM_BIND::NervousSystemData& src, SENervousSystem& dst)
{
  dst.SetBaroreceptorFeedback((eSwitch)src.baroreceptorfeedback());
  dst.SetChemoreceptorFeedback((eSwitch)src.chemoreceptorfeedback());
  if (src.has_baroreceptorheartratescale())
    PBProperty::Load(src.baroreceptorheartratescale(), dst.GetBaroreceptorHeartRateScale());
  if (src.has_baroreceptorheartelastancescale())
    PBProperty::Load(src.baroreceptorheartelastancescale(), dst.GetBaroreceptorHeartElastanceScale());
  if (src.has_baroreceptorresistancescale())
    PBProperty::Load(src.baroreceptorresistancescale(), dst.GetBaroreceptorResistanceScale());
  if (src.has_baroreceptorcompliancescale())
    PBProperty::Load(src.baroreceptorcompliancescale(), dst.GetBaroreceptorComplianceScale());
  if (src.has_chemoreceptorheartratescale())
    PBProperty::Load(src.chemoreceptorheartratescale(), dst.GetChemoreceptorHeartRateScale());
  if (src.has_chemoreceptorheartelastancescale())
    PBProperty::Load(src.chemoreceptorheartelastancescale(), dst.GetChemoreceptorHeartElastanceScale());
  if (src.has_lefteyepupillaryresponse())
    PBPhysiology::Load(src.lefteyepupillaryresponse(), dst.GetLeftEyePupillaryResponse());
  if (src.has_righteyepupillaryresponse())
    PBPhysiology::Load(src.righteyepupillaryresponse(), dst.GetRightEyePupillaryResponse());
}

CDM_BIND::NervousSystemData* PBPhysiology::Unload(const SENervousSystem& src)
{
  CDM_BIND::NervousSystemData* dst = new CDM_BIND::NervousSystemData();
  PBPhysiology::Serialize(src, *dst);
  return dst;
}
void PBPhysiology::Serialize(const SENervousSystem& src, CDM_BIND::NervousSystemData& dst)
{
  dst.set_baroreceptorfeedback((CDM_BIND::eSwitch)src.m_BaroreceptorFeedback);
  dst.set_chemoreceptorfeedback((CDM_BIND::eSwitch)src.m_ChemoreceptorFeedback);
  if (src.HasBaroreceptorHeartRateScale())
    dst.set_allocated_baroreceptorheartratescale(PBProperty::Unload(*src.m_BaroreceptorHeartRateScale));
  if (src.HasBaroreceptorHeartElastanceScale())
    dst.set_allocated_baroreceptorheartelastancescale(PBProperty::Unload(*src.m_BaroreceptorHeartElastanceScale));
  if (src.HasBaroreceptorResistanceScale())
    dst.set_allocated_baroreceptorresistancescale(PBProperty::Unload(*src.m_BaroreceptorResistanceScale));
  if (src.HasBaroreceptorComplianceScale())
    dst.set_allocated_baroreceptorcompliancescale(PBProperty::Unload(*src.m_BaroreceptorComplianceScale));
  if (src.HasChemoreceptorHeartRateScale())
    dst.set_allocated_chemoreceptorheartratescale(PBProperty::Unload(*src.m_ChemoreceptorHeartRateScale));
  if (src.HasChemoreceptorHeartElastanceScale())
    dst.set_allocated_chemoreceptorheartelastancescale(PBProperty::Unload(*src.m_ChemoreceptorHeartElastanceScale));
  if (src.HasLeftEyePupillaryResponse())
    dst.set_allocated_lefteyepupillaryresponse(PBPhysiology::Unload(*src.m_LeftEyePupillaryResponse));
  if (src.HasRightEyePupillaryResponse())
    dst.set_allocated_righteyepupillaryresponse(PBPhysiology::Unload(*src.m_RightEyePupillaryResponse));
}

void PBPhysiology::Load(const CDM_BIND::PupillaryResponseData& src, SEPupillaryResponse& dst)
{
  dst.Clear();
  PBPhysiology::Serialize(src, dst);
}
void PBPhysiology::Serialize(const CDM_BIND::PupillaryResponseData& src, SEPupillaryResponse& dst)
{
  if (src.has_reactivitymodifier())
    PBProperty::Load(src.reactivitymodifier(), dst.GetReactivityModifier());
  if (src.has_shapemodifier())
    PBProperty::Load(src.shapemodifier(), dst.GetShapeModifier());
  if (src.has_sizemodifier())
    PBProperty::Load(src.sizemodifier(), dst.GetSizeModifier());
}
CDM_BIND::PupillaryResponseData* PBPhysiology::Unload(const SEPupillaryResponse& src)
{
  CDM_BIND::PupillaryResponseData* dst = new CDM_BIND::PupillaryResponseData();
  PBPhysiology::Serialize(src, *dst);
  return dst;
}
void PBPhysiology::Serialize(const SEPupillaryResponse& src, CDM_BIND::PupillaryResponseData& dst)
{
  if (src.HasReactivityModifier())
    dst.set_allocated_reactivitymodifier(PBProperty::Unload(*src.m_ReactivityModifier));
  if (src.HasShapeModifier())
    dst.set_allocated_shapemodifier(PBProperty::Unload(*src.m_ShapeModifier));
  if (src.HasSizeModifier())
    dst.set_allocated_sizemodifier(PBProperty::Unload(*src.m_SizeModifier));
}

void PBPhysiology::Load(const CDM_BIND::RenalSystemData& src, SERenalSystem& dst)
{
  dst.Clear();
  PBPhysiology::Serialize(src, dst);
}
void PBPhysiology::Serialize(const CDM_BIND::RenalSystemData& src, SERenalSystem& dst)
{
  if (src.has_glomerularfiltrationrate())
    PBProperty::Load(src.glomerularfiltrationrate(), dst.GetGlomerularFiltrationRate());
  if (src.has_filtrationfraction())
    PBProperty::Load(src.filtrationfraction(), dst.GetFiltrationFraction());

  if (src.has_leftafferentarterioleresistance())
    PBProperty::Load(src.leftafferentarterioleresistance(), dst.GetLeftAfferentArterioleResistance());
  if (src.has_leftbowmanscapsuleshydrostaticpressure())
    PBProperty::Load(src.leftbowmanscapsuleshydrostaticpressure(), dst.GetLeftBowmansCapsulesHydrostaticPressure());
  if (src.has_leftbowmanscapsulesosmoticpressure())
    PBProperty::Load(src.leftbowmanscapsulesosmoticpressure(), dst.GetLeftBowmansCapsulesOsmoticPressure());
  if (src.has_leftefferentarterioleresistance())
    PBProperty::Load(src.leftefferentarterioleresistance(), dst.GetLeftEfferentArterioleResistance());
  if (src.has_leftglomerularcapillarieshydrostaticpressure())
    PBProperty::Load(src.leftglomerularcapillarieshydrostaticpressure(), dst.GetLeftGlomerularCapillariesHydrostaticPressure());
  if (src.has_leftglomerularcapillariesosmoticpressure())
    PBProperty::Load(src.leftglomerularcapillariesosmoticpressure(), dst.GetLeftGlomerularCapillariesOsmoticPressure());
  if (src.has_leftglomerularfiltrationcoefficient())
    PBProperty::Load(src.leftglomerularfiltrationcoefficient(), dst.GetLeftGlomerularFiltrationCoefficient());
  if (src.has_leftglomerularfiltrationrate())
    PBProperty::Load(src.leftglomerularfiltrationrate(), dst.GetLeftGlomerularFiltrationRate());
  if (src.has_leftglomerularfiltrationsurfacearea())
    PBProperty::Load(src.leftglomerularfiltrationsurfacearea(), dst.GetLeftGlomerularFiltrationSurfaceArea());
  if (src.has_leftglomerularfluidpermeability())
    PBProperty::Load(src.leftglomerularfluidpermeability(), dst.GetLeftGlomerularFluidPermeability());
  if (src.has_leftfiltrationfraction())
    PBProperty::Load(src.leftfiltrationfraction(), dst.GetLeftFiltrationFraction());
  if (src.has_leftnetfiltrationpressure())
    PBProperty::Load(src.leftnetfiltrationpressure(), dst.GetLeftNetFiltrationPressure());
  if (src.has_leftnetreabsorptionpressure())
    PBProperty::Load(src.leftnetreabsorptionpressure(), dst.GetLeftNetReabsorptionPressure());
  if (src.has_leftperitubularcapillarieshydrostaticpressure())
    PBProperty::Load(src.leftperitubularcapillarieshydrostaticpressure(), dst.GetLeftPeritubularCapillariesHydrostaticPressure());
  if (src.has_leftperitubularcapillariesosmoticpressure())
    PBProperty::Load(src.leftperitubularcapillariesosmoticpressure(), dst.GetLeftPeritubularCapillariesOsmoticPressure());
  if (src.has_leftreabsorptionfiltrationcoefficient())
    PBProperty::Load(src.leftreabsorptionfiltrationcoefficient(), dst.GetLeftReabsorptionFiltrationCoefficient());
  if (src.has_leftreabsorptionrate())
    PBProperty::Load(src.leftreabsorptionrate(), dst.GetLeftReabsorptionRate());
  if (src.has_lefttubularreabsorptionfiltrationsurfacearea())
    PBProperty::Load(src.lefttubularreabsorptionfiltrationsurfacearea(), dst.GetLeftTubularReabsorptionFiltrationSurfaceArea());
  if (src.has_lefttubularreabsorptionfluidpermeability())
    PBProperty::Load(src.lefttubularreabsorptionfluidpermeability(), dst.GetLeftTubularReabsorptionFluidPermeability());
  if (src.has_lefttubularhydrostaticpressure())
    PBProperty::Load(src.lefttubularhydrostaticpressure(), dst.GetLeftTubularHydrostaticPressure());
  if (src.has_lefttubularosmoticpressure())
    PBProperty::Load(src.lefttubularosmoticpressure(), dst.GetLeftTubularOsmoticPressure());

  if (src.has_renalbloodflow())
    PBProperty::Load(src.renalbloodflow(), dst.GetRenalBloodFlow());
  if (src.has_renalplasmaflow())
    PBProperty::Load(src.renalplasmaflow(), dst.GetRenalPlasmaFlow());
  if (src.has_renalvascularresistance())
    PBProperty::Load(src.renalvascularresistance(), dst.GetRenalVascularResistance());

  if (src.has_rightafferentarterioleresistance())
    PBProperty::Load(src.rightafferentarterioleresistance(), dst.GetRightAfferentArterioleResistance());
  if (src.has_rightbowmanscapsuleshydrostaticpressure())
    PBProperty::Load(src.rightbowmanscapsuleshydrostaticpressure(), dst.GetRightBowmansCapsulesHydrostaticPressure());
  if (src.has_rightbowmanscapsulesosmoticpressure())
    PBProperty::Load(src.rightbowmanscapsulesosmoticpressure(), dst.GetRightBowmansCapsulesOsmoticPressure());
  if (src.has_rightefferentarterioleresistance())
    PBProperty::Load(src.rightefferentarterioleresistance(), dst.GetRightEfferentArterioleResistance());
  if (src.has_rightglomerularcapillarieshydrostaticpressure())
    PBProperty::Load(src.rightglomerularcapillarieshydrostaticpressure(), dst.GetRightGlomerularCapillariesHydrostaticPressure());
  if (src.has_rightglomerularcapillariesosmoticpressure())
    PBProperty::Load(src.rightglomerularcapillariesosmoticpressure(), dst.GetRightGlomerularCapillariesOsmoticPressure());
  if (src.has_rightglomerularfiltrationcoefficient())
    PBProperty::Load(src.rightglomerularfiltrationcoefficient(), dst.GetRightGlomerularFiltrationCoefficient());
  if (src.has_rightglomerularfiltrationrate())
    PBProperty::Load(src.rightglomerularfiltrationrate(), dst.GetRightGlomerularFiltrationRate());
  if (src.has_rightglomerularfiltrationsurfacearea())
    PBProperty::Load(src.rightglomerularfiltrationsurfacearea(), dst.GetRightGlomerularFiltrationSurfaceArea());
  if (src.has_rightglomerularfluidpermeability())
    PBProperty::Load(src.rightglomerularfluidpermeability(), dst.GetRightGlomerularFluidPermeability());
  if (src.has_rightfiltrationfraction())
    PBProperty::Load(src.rightfiltrationfraction(), dst.GetRightFiltrationFraction());
  if (src.has_rightnetfiltrationpressure())
    PBProperty::Load(src.rightnetfiltrationpressure(), dst.GetRightNetFiltrationPressure());
  if (src.has_rightnetreabsorptionpressure())
    PBProperty::Load(src.rightnetreabsorptionpressure(), dst.GetRightNetReabsorptionPressure());
  if (src.has_rightperitubularcapillarieshydrostaticpressure())
    PBProperty::Load(src.rightperitubularcapillarieshydrostaticpressure(), dst.GetRightPeritubularCapillariesHydrostaticPressure());
  if (src.has_rightperitubularcapillariesosmoticpressure())
    PBProperty::Load(src.rightperitubularcapillariesosmoticpressure(), dst.GetRightPeritubularCapillariesOsmoticPressure());
  if (src.has_rightreabsorptionfiltrationcoefficient())
    PBProperty::Load(src.rightreabsorptionfiltrationcoefficient(), dst.GetRightReabsorptionFiltrationCoefficient());
  if (src.has_rightreabsorptionrate())
    PBProperty::Load(src.rightreabsorptionrate(), dst.GetRightReabsorptionRate());
  if (src.has_righttubularreabsorptionfiltrationsurfacearea())
    PBProperty::Load(src.righttubularreabsorptionfiltrationsurfacearea(), dst.GetRightTubularReabsorptionFiltrationSurfaceArea());
  if (src.has_righttubularreabsorptionfluidpermeability())
    PBProperty::Load(src.righttubularreabsorptionfluidpermeability(), dst.GetRightTubularReabsorptionFluidPermeability());
  if (src.has_righttubularhydrostaticpressure())
    PBProperty::Load(src.righttubularhydrostaticpressure(), dst.GetRightTubularHydrostaticPressure());
  if (src.has_righttubularosmoticpressure())
    PBProperty::Load(src.righttubularosmoticpressure(), dst.GetRightTubularOsmoticPressure());

  if (src.has_urinationrate())
    PBProperty::Load(src.urinationrate(), dst.GetUrinationRate());
  if (src.has_urineosmolality())
    PBProperty::Load(src.urineosmolality(), dst.GetUrineOsmolality());
  if (src.has_urineosmolarity())
    PBProperty::Load(src.urineosmolarity(), dst.GetUrineOsmolarity());
  if (src.has_urineproductionrate())
    PBProperty::Load(src.urineproductionrate(), dst.GetUrineProductionRate());
  if (src.has_urinespecificgravity())
    PBProperty::Load(src.urinespecificgravity(), dst.GetUrineSpecificGravity());
  if (src.has_urinevolume())
    PBProperty::Load(src.urinevolume(), dst.GetUrineVolume());
  if (src.has_urineureanitrogenconcentration())
    PBProperty::Load(src.urineureanitrogenconcentration(), dst.GetUrineUreaNitrogenConcentration());
}

CDM_BIND::RenalSystemData* PBPhysiology::Unload(const SERenalSystem& src)
{
  CDM_BIND::RenalSystemData* dst = new CDM_BIND::RenalSystemData();
  PBPhysiology::Serialize(src, *dst);
  return dst;
}
void PBPhysiology::Serialize(const SERenalSystem& src, CDM_BIND::RenalSystemData& dst)
{
  if (src.HasGlomerularFiltrationRate())
    dst.set_allocated_glomerularfiltrationrate(PBProperty::Unload(*src.m_GlomerularFiltrationRate));
  if (src.HasFiltrationFraction())
    dst.set_allocated_filtrationfraction(PBProperty::Unload(*src.m_FiltrationFraction));

  if (src.HasLeftAfferentArterioleResistance())
    dst.set_allocated_leftafferentarterioleresistance(PBProperty::Unload(*src.m_LeftAfferentArterioleResistance));
  if (src.HasLeftBowmansCapsulesHydrostaticPressure())
    dst.set_allocated_leftbowmanscapsuleshydrostaticpressure(PBProperty::Unload(*src.m_LeftBowmansCapsulesHydrostaticPressure));
  if (src.HasLeftBowmansCapsulesOsmoticPressure())
    dst.set_allocated_leftbowmanscapsulesosmoticpressure(PBProperty::Unload(*src.m_LeftBowmansCapsulesOsmoticPressure));
  if (src.HasLeftEfferentArterioleResistance())
    dst.set_allocated_leftefferentarterioleresistance(PBProperty::Unload(*src.m_LeftEfferentArterioleResistance));
  if (src.HasLeftGlomerularCapillariesHydrostaticPressure())
    dst.set_allocated_leftglomerularcapillarieshydrostaticpressure(PBProperty::Unload(*src.m_LeftGlomerularCapillariesHydrostaticPressure));
  if (src.HasLeftGlomerularCapillariesOsmoticPressure())
    dst.set_allocated_leftglomerularcapillariesosmoticpressure(PBProperty::Unload(*src.m_LeftGlomerularCapillariesOsmoticPressure));
  if (src.HasLeftGlomerularFiltrationCoefficient())
    dst.set_allocated_leftglomerularfiltrationcoefficient(PBProperty::Unload(*src.m_LeftGlomerularFiltrationCoefficient));
  if (src.HasLeftGlomerularFiltrationRate())
    dst.set_allocated_leftglomerularfiltrationrate(PBProperty::Unload(*src.m_LeftGlomerularFiltrationRate));
  if (src.HasLeftGlomerularFiltrationSurfaceArea())
    dst.set_allocated_leftglomerularfiltrationsurfacearea(PBProperty::Unload(*src.m_LeftGlomerularFiltrationSurfaceArea));
  if (src.HasLeftGlomerularFluidPermeability())
    dst.set_allocated_leftglomerularfluidpermeability(PBProperty::Unload(*src.m_LeftGlomerularFluidPermeability));
  if (src.HasLeftFiltrationFraction())
    dst.set_allocated_leftfiltrationfraction(PBProperty::Unload(*src.m_LeftFiltrationFraction));
  if (src.HasLeftNetFiltrationPressure())
    dst.set_allocated_leftnetfiltrationpressure(PBProperty::Unload(*src.m_LeftNetFiltrationPressure));
  if (src.HasLeftNetReabsorptionPressure())
    dst.set_allocated_leftnetreabsorptionpressure(PBProperty::Unload(*src.m_LeftNetReabsorptionPressure));
  if (src.HasLeftPeritubularCapillariesHydrostaticPressure())
    dst.set_allocated_leftperitubularcapillarieshydrostaticpressure(PBProperty::Unload(*src.m_LeftPeritubularCapillariesHydrostaticPressure));
  if (src.HasLeftPeritubularCapillariesOsmoticPressure())
    dst.set_allocated_leftperitubularcapillariesosmoticpressure(PBProperty::Unload(*src.m_LeftPeritubularCapillariesOsmoticPressure));
  if (src.HasLeftReabsorptionFiltrationCoefficient())
    dst.set_allocated_leftreabsorptionfiltrationcoefficient(PBProperty::Unload(*src.m_LeftReabsorptionFiltrationCoefficient));
  if (src.HasLeftReabsorptionRate())
    dst.set_allocated_leftreabsorptionrate(PBProperty::Unload(*src.m_LeftReabsorptionRate));
  if (src.HasLeftTubularReabsorptionFiltrationSurfaceArea())
    dst.set_allocated_lefttubularreabsorptionfiltrationsurfacearea(PBProperty::Unload(*src.m_LeftTubularReabsorptionFiltrationSurfaceArea));
  if (src.HasLeftTubularReabsorptionFluidPermeability())
    dst.set_allocated_lefttubularreabsorptionfluidpermeability(PBProperty::Unload(*src.m_LeftTubularReabsorptionFluidPermeability));
  if (src.HasLeftTubularHydrostaticPressure())
    dst.set_allocated_lefttubularhydrostaticpressure(PBProperty::Unload(*src.m_LeftTubularHydrostaticPressure));
  if (src.HasLeftTubularOsmoticPressure())
    dst.set_allocated_lefttubularosmoticpressure(PBProperty::Unload(*src.m_LeftTubularOsmoticPressure));

  if (src.HasRenalBloodFlow())
    dst.set_allocated_renalbloodflow(PBProperty::Unload(*src.m_RenalBloodFlow));
  if (src.HasRenalPlasmaFlow())
    dst.set_allocated_renalplasmaflow(PBProperty::Unload(*src.m_RenalPlasmaFlow));
  if (src.HasRenalVascularResistance())
    dst.set_allocated_renalvascularresistance(PBProperty::Unload(*src.m_RenalVascularResistance));

  if (src.HasRightAfferentArterioleResistance())
    dst.set_allocated_rightafferentarterioleresistance(PBProperty::Unload(*src.m_RightAfferentArterioleResistance));
  if (src.HasRightBowmansCapsulesHydrostaticPressure())
    dst.set_allocated_rightbowmanscapsuleshydrostaticpressure(PBProperty::Unload(*src.m_RightBowmansCapsulesHydrostaticPressure));
  if (src.HasRightBowmansCapsulesOsmoticPressure())
    dst.set_allocated_rightbowmanscapsulesosmoticpressure(PBProperty::Unload(*src.m_RightBowmansCapsulesOsmoticPressure));
  if (src.HasRightEfferentArterioleResistance())
    dst.set_allocated_rightefferentarterioleresistance(PBProperty::Unload(*src.m_RightEfferentArterioleResistance));
  if (src.HasRightGlomerularCapillariesHydrostaticPressure())
    dst.set_allocated_rightglomerularcapillarieshydrostaticpressure(PBProperty::Unload(*src.m_RightGlomerularCapillariesHydrostaticPressure));
  if (src.HasRightGlomerularCapillariesOsmoticPressure())
    dst.set_allocated_rightglomerularcapillariesosmoticpressure(PBProperty::Unload(*src.m_RightGlomerularCapillariesOsmoticPressure));
  if (src.HasRightGlomerularFiltrationCoefficient())
    dst.set_allocated_rightglomerularfiltrationcoefficient(PBProperty::Unload(*src.m_RightGlomerularFiltrationCoefficient));
  if (src.HasRightGlomerularFiltrationRate())
    dst.set_allocated_rightglomerularfiltrationrate(PBProperty::Unload(*src.m_RightGlomerularFiltrationRate));
  if (src.HasRightGlomerularFiltrationSurfaceArea())
    dst.set_allocated_rightglomerularfiltrationsurfacearea(PBProperty::Unload(*src.m_RightGlomerularFiltrationSurfaceArea));
  if (src.HasRightGlomerularFluidPermeability())
    dst.set_allocated_rightglomerularfluidpermeability(PBProperty::Unload(*src.m_RightGlomerularFluidPermeability));
  if (src.HasRightFiltrationFraction())
    dst.set_allocated_rightfiltrationfraction(PBProperty::Unload(*src.m_RightFiltrationFraction));
  if (src.HasRightNetFiltrationPressure())
    dst.set_allocated_rightnetfiltrationpressure(PBProperty::Unload(*src.m_RightNetFiltrationPressure));
  if (src.HasRightNetReabsorptionPressure())
    dst.set_allocated_rightnetreabsorptionpressure(PBProperty::Unload(*src.m_RightNetReabsorptionPressure));
  if (src.HasRightPeritubularCapillariesHydrostaticPressure())
    dst.set_allocated_rightperitubularcapillarieshydrostaticpressure(PBProperty::Unload(*src.m_RightPeritubularCapillariesHydrostaticPressure));
  if (src.HasRightPeritubularCapillariesOsmoticPressure())
    dst.set_allocated_rightperitubularcapillariesosmoticpressure(PBProperty::Unload(*src.m_RightPeritubularCapillariesOsmoticPressure));
  if (src.HasRightReabsorptionFiltrationCoefficient())
    dst.set_allocated_rightreabsorptionfiltrationcoefficient(PBProperty::Unload(*src.m_RightReabsorptionFiltrationCoefficient));
  if (src.HasRightReabsorptionRate())
    dst.set_allocated_rightreabsorptionrate(PBProperty::Unload(*src.m_RightReabsorptionRate));
  if (src.HasRightTubularReabsorptionFiltrationSurfaceArea())
    dst.set_allocated_righttubularreabsorptionfiltrationsurfacearea(PBProperty::Unload(*src.m_RightTubularReabsorptionFiltrationSurfaceArea));
  if (src.HasRightTubularReabsorptionFluidPermeability())
    dst.set_allocated_righttubularreabsorptionfluidpermeability(PBProperty::Unload(*src.m_RightTubularReabsorptionFluidPermeability));
  if (src.HasRightTubularHydrostaticPressure())
    dst.set_allocated_righttubularhydrostaticpressure(PBProperty::Unload(*src.m_RightTubularHydrostaticPressure));
  if (src.HasRightTubularOsmoticPressure())
    dst.set_allocated_righttubularosmoticpressure(PBProperty::Unload(*src.m_RightTubularOsmoticPressure));

  if (src.HasUrinationRate())
    dst.set_allocated_urinationrate(PBProperty::Unload(*src.m_UrinationRate));
  if (src.HasUrineOsmolality())
    dst.set_allocated_urineosmolality(PBProperty::Unload(*src.m_UrineOsmolality));
  if (src.HasUrineOsmolarity())
    dst.set_allocated_urineosmolarity(PBProperty::Unload(*src.m_UrineOsmolarity));
  if (src.HasUrineProductionRate())
    dst.set_allocated_urineproductionrate(PBProperty::Unload(*src.m_UrineProductionRate));
  if (src.HasUrineSpecificGravity())
    dst.set_allocated_urinespecificgravity(PBProperty::Unload(*src.m_UrineSpecificGravity));
  if (src.HasUrineVolume())
    dst.set_allocated_urinevolume(PBProperty::Unload(*src.m_UrineVolume));
  if (src.HasUrineUreaNitrogenConcentration())
    dst.set_allocated_urineureanitrogenconcentration(PBProperty::Unload(*src.m_UrineUreaNitrogenConcentration));
}

void PBPhysiology::Load(const CDM_BIND::RespiratorySystemData& src, SERespiratorySystem& dst)
{
  dst.Clear();
  PBPhysiology::Serialize(src, dst);
}
void PBPhysiology::Serialize(const CDM_BIND::RespiratorySystemData& src, SERespiratorySystem& dst)
{
  if (src.has_alveolararterialgradient())
    PBProperty::Load(src.alveolararterialgradient(), dst.GetAlveolarArterialGradient());
  if (src.has_alveolardeadspace())
    PBProperty::Load(src.alveolardeadspace(), dst.GetAlveolarDeadSpace());
  if (src.has_anatomicdeadspace())
    PBProperty::Load(src.anatomicdeadspace(), dst.GetAnatomicDeadSpace());
  if (src.has_carricoindex())
    PBProperty::Load(src.carricoindex(), dst.GetCarricoIndex());
  if (src.has_chestwallcompliance())
    PBProperty::Load(src.chestwallcompliance(), dst.GetChestWallCompliance());
  if (src.has_elasticworkofbreathing())
    PBProperty::Load(src.elasticworkofbreathing(), dst.GetElasticWorkOfBreathing());
  if (src.has_endtidalcarbondioxidefraction())
    PBProperty::Load(src.endtidalcarbondioxidefraction(), dst.GetEndTidalCarbonDioxideFraction());
  if (src.has_endtidalcarbondioxidepressure())
    PBProperty::Load(src.endtidalcarbondioxidepressure(), dst.GetEndTidalCarbonDioxidePressure());
  if (src.has_endtidaloxygenfraction())
    PBProperty::Load(src.endtidaloxygenfraction(), dst.GetEndTidalOxygenFraction());
  if (src.has_endtidaloxygenpressure())
    PBProperty::Load(src.endtidaloxygenpressure(), dst.GetEndTidalOxygenPressure());
  if (src.has_expiratoryflow())
    PBProperty::Load(src.expiratoryflow(), dst.GetExpiratoryFlow());
  if (src.has_expiratorypulmonaryresistance())
    PBProperty::Load(src.expiratorypulmonaryresistance(), dst.GetExpiratoryPulmonaryResistance());
  if (src.has_fractionofinsipredoxygen())
    PBProperty::Load(src.fractionofinsipredoxygen(), dst.GetFractionOfInsipredOxygen());
  if (src.has_imposedpowerofbreathing())
    PBProperty::Load(src.imposedpowerofbreathing(), dst.GetImposedPowerOfBreathing());
  if (src.has_imposedworkofbreathing())
    PBProperty::Load(src.imposedworkofbreathing(), dst.GetImposedWorkOfBreathing());
  if (src.has_inspiratoryexpiratoryratio())
    PBProperty::Load(src.inspiratoryexpiratoryratio(), dst.GetInspiratoryExpiratoryRatio());
  if (src.has_inspiratoryflow())
    PBProperty::Load(src.inspiratoryflow(), dst.GetInspiratoryFlow());
  if (src.has_inspiratorypulmonaryresistance())
    PBProperty::Load(src.inspiratorypulmonaryresistance(), dst.GetInspiratoryPulmonaryResistance());
  if (src.has_intrapleuralpressure())
    PBProperty::Load(src.intrapleuralpressure(), dst.GetIntrapleuralPressure());
  if (src.has_intrapulmonarypressure())
    PBProperty::Load(src.intrapulmonarypressure(), dst.GetIntrapulmonaryPressure());
  if (src.has_lungcompliance())
    PBProperty::Load(src.lungcompliance(), dst.GetLungCompliance());
  if (src.has_maximalinspiratorypressure())
    PBProperty::Load(src.maximalinspiratorypressure(), dst.GetMaximalInspiratoryPressure());
  if (src.has_meanairwaypressure())
    PBProperty::Load(src.meanairwaypressure(), dst.GetMeanAirwayPressure());
  if (src.has_oxygenationindex())
    PBProperty::Load(src.oxygenationindex(), dst.GetOxygenationIndex());
  if (src.has_oxygensaturationindex())
    PBProperty::Load(src.oxygensaturationindex(), dst.GetOxygenSaturationIndex());
  if (src.has_patientpowerofbreathing())
    PBProperty::Load(src.patientpowerofbreathing(), dst.GetPatientPowerOfBreathing());
  if (src.has_patientworkofbreathing())
    PBProperty::Load(src.patientworkofbreathing(), dst.GetPatientWorkOfBreathing());
  if (src.has_peakinspiratorypressure())
    PBProperty::Load(src.peakinspiratorypressure(), dst.GetPeakInspiratoryPressure());
  if (src.has_physiologicdeadspace())
    PBProperty::Load(src.physiologicdeadspace(), dst.GetPhysiologicDeadSpace());
  if (src.has_positiveendexpiratorypressure())
    PBProperty::Load(src.positiveendexpiratorypressure(), dst.GetPositiveEndExpiratoryPressure());
  if (src.has_pulmonarycompliance())
    PBProperty::Load(src.pulmonarycompliance(), dst.GetPulmonaryCompliance());
  if (src.has_pulmonaryelastance())
    PBProperty::Load(src.pulmonaryelastance(), dst.GetPulmonaryElastance());
  if (src.has_resistiveexpiratoryworkofbreathing())
    PBProperty::Load(src.resistiveexpiratoryworkofbreathing(), dst.GetResistiveExpiratoryWorkOfBreathing());
  if (src.has_resistiveinspiratoryworkofbreathing())
    PBProperty::Load(src.resistiveinspiratoryworkofbreathing(), dst.GetResistiveInspiratoryWorkOfBreathing());
  if (src.has_respirationrate())
    PBProperty::Load(src.respirationrate(), dst.GetRespirationRate());
  if (src.has_respiratorymusclefatigue())
    PBProperty::Load(src.respiratorymusclefatigue(), dst.GetRespiratoryMuscleFatigue());
  if (src.has_respiratorymusclepressure())
    PBProperty::Load(src.respiratorymusclepressure(), dst.GetRespiratoryMusclePressure());
  if (src.has_saturationandfractionofinspiredoxygenratio())
    PBProperty::Load(src.saturationandfractionofinspiredoxygenratio(), dst.GetSaturationAndFractionOfInspiredOxygenRatio());
  if (src.has_specificventilation())
    PBProperty::Load(src.specificventilation(), dst.GetSpecificVentilation());
  if (src.has_tidalvolume())
    PBProperty::Load(src.tidalvolume(), dst.GetTidalVolume());
  if (src.has_totalalveolarventilation())
    PBProperty::Load(src.totalalveolarventilation(), dst.GetTotalAlveolarVentilation());
  if (src.has_totaldeadspaceventilation())
    PBProperty::Load(src.totaldeadspaceventilation(), dst.GetTotalDeadSpaceVentilation());
  if (src.has_totallungvolume())
    PBProperty::Load(src.totallungvolume(), dst.GetTotalLungVolume());
  if (src.has_totalpowerofbreathing())
    PBProperty::Load(src.totalpowerofbreathing(), dst.GetTotalPowerOfBreathing());
  if (src.has_totalpulmonaryventilation())
    PBProperty::Load(src.totalpulmonaryventilation(), dst.GetTotalPulmonaryVentilation());
  if (src.has_totalworkofbreathing())
    PBProperty::Load(src.totalworkofbreathing(), dst.GetTotalWorkOfBreathing());
  if (src.has_transairwaypressure())
    PBProperty::Load(src.transairwaypressure(), dst.GetTransairwayPressure());
  if (src.has_transalveolarpressure())
    PBProperty::Load(src.transalveolarpressure(), dst.GetTransalveolarPressure());
  if (src.has_transchestwallpressure())
    PBProperty::Load(src.transchestwallpressure(), dst.GetTransChestWallPressure());
  if (src.has_transmusclepressure())
    PBProperty::Load(src.transmusclepressure(), dst.GetTransMusclePressure());
  if (src.has_transpulmonarypressure())
    PBProperty::Load(src.transpulmonarypressure(), dst.GetTranspulmonaryPressure());
  if (src.has_transrespiratorypressure())
    PBProperty::Load(src.transrespiratorypressure(), dst.GetTransrespiratoryPressure());
  if (src.has_transthoracicpressure())
    PBProperty::Load(src.transthoracicpressure(), dst.GetTransthoracicPressure());
}

CDM_BIND::RespiratorySystemData* PBPhysiology::Unload(const SERespiratorySystem& src)
{
  CDM_BIND::RespiratorySystemData* dst = new CDM_BIND::RespiratorySystemData();
  PBPhysiology::Serialize(src, *dst);
  return dst;
}
void PBPhysiology::Serialize(const SERespiratorySystem& src, CDM_BIND::RespiratorySystemData& dst)
{
  if (src.HasAlveolarArterialGradient())
    dst.set_allocated_alveolararterialgradient(PBProperty::Unload(*src.m_AlveolarArterialGradient));
  if (src.HasAlveolarDeadSpace())
    dst.set_allocated_alveolardeadspace(PBProperty::Unload(*src.m_AlveolarDeadSpace));
  if (src.HasAnatomicDeadSpace())
    dst.set_allocated_anatomicdeadspace(PBProperty::Unload(*src.m_AnatomicDeadSpace));
  if (src.HasCarricoIndex())
    dst.set_allocated_carricoindex(PBProperty::Unload(*src.m_CarricoIndex));
  if (src.HasChestWallCompliance())
    dst.set_allocated_chestwallcompliance(PBProperty::Unload(*src.m_ChestWallCompliance));
  if (src.HasElasticWorkOfBreathing())
    dst.set_allocated_elasticworkofbreathing(PBProperty::Unload(*src.m_ElasticWorkOfBreathing));
  if (src.HasEndTidalCarbonDioxideFraction())
    dst.set_allocated_endtidalcarbondioxidefraction(PBProperty::Unload(*src.m_EndTidalCarbonDioxideFraction));
  if (src.HasEndTidalCarbonDioxidePressure())
    dst.set_allocated_endtidalcarbondioxidepressure(PBProperty::Unload(*src.m_EndTidalCarbonDioxidePressure));
  if (src.HasEndTidalOxygenFraction())
    dst.set_allocated_endtidaloxygenfraction(PBProperty::Unload(*src.m_EndTidalOxygenFraction));
  if (src.HasEndTidalOxygenPressure())
    dst.set_allocated_endtidaloxygenpressure(PBProperty::Unload(*src.m_EndTidalOxygenPressure));
  if (src.HasExpiratoryFlow())
    dst.set_allocated_expiratoryflow(PBProperty::Unload(*src.m_ExpiratoryFlow));
  if (src.HasExpiratoryPulmonaryResistance())
    dst.set_allocated_expiratorypulmonaryresistance(PBProperty::Unload(*src.m_ExpiratoryPulmonaryResistance));
  if (src.HasFractionOfInsipredOxygen())
    dst.set_allocated_fractionofinsipredoxygen(PBProperty::Unload(*src.m_FractionOfInsipredOxygen));
  if (src.HasImposedPowerOfBreathing())
    dst.set_allocated_imposedpowerofbreathing(PBProperty::Unload(*src.m_ImposedPowerOfBreathing));
  if (src.HasImposedWorkOfBreathing())
    dst.set_allocated_imposedworkofbreathing(PBProperty::Unload(*src.m_ImposedWorkOfBreathing));
  if (src.HasInspiratoryExpiratoryRatio())
    dst.set_allocated_inspiratoryexpiratoryratio(PBProperty::Unload(*src.m_InspiratoryExpiratoryRatio));
  if (src.HasInspiratoryFlow())
    dst.set_allocated_inspiratoryflow(PBProperty::Unload(*src.m_InspiratoryFlow));
  if (src.HasInspiratoryPulmonaryResistance())
    dst.set_allocated_inspiratorypulmonaryresistance(PBProperty::Unload(*src.m_InspiratoryPulmonaryResistance));
  if (src.HasIntrapleuralPressure())
    dst.set_allocated_intrapleuralpressure(PBProperty::Unload(*src.m_IntrapleuralPressure));
  if (src.HasIntrapulmonaryPressure())
    dst.set_allocated_intrapulmonarypressure(PBProperty::Unload(*src.m_IntrapulmonaryPressure));
  if (src.HasLungCompliance())
    dst.set_allocated_lungcompliance(PBProperty::Unload(*src.m_LungCompliance));
  if (src.HasMaximalInspiratoryPressure())
    dst.set_allocated_maximalinspiratorypressure(PBProperty::Unload(*src.m_MaximalInspiratoryPressure));
  if (src.HasMeanAirwayPressure())
    dst.set_allocated_meanairwaypressure(PBProperty::Unload(*src.m_MeanAirwayPressure));
  if (src.HasOxygenationIndex())
    dst.set_allocated_oxygenationindex(PBProperty::Unload(*src.m_OxygenationIndex));
  if (src.HasOxygenSaturationIndex())
    dst.set_allocated_oxygensaturationindex(PBProperty::Unload(*src.m_OxygenSaturationIndex));
  if (src.HasPatientPowerOfBreathing())
    dst.set_allocated_patientpowerofbreathing(PBProperty::Unload(*src.m_PatientPowerOfBreathing));
  if (src.HasPatientWorkOfBreathing())
    dst.set_allocated_patientworkofbreathing(PBProperty::Unload(*src.m_PatientWorkOfBreathing));
  if (src.HasPeakInspiratoryPressure())
    dst.set_allocated_peakinspiratorypressure(PBProperty::Unload(*src.m_PeakInspiratoryPressure));
  if (src.HasPhysiologicDeadSpace())
    dst.set_allocated_physiologicdeadspace(PBProperty::Unload(*src.m_PhysiologicDeadSpace));
  if (src.HasPositiveEndExpiratoryPressure())
    dst.set_allocated_positiveendexpiratorypressure(PBProperty::Unload(*src.m_PositiveEndExpiratoryPressure));
  if (src.HasPulmonaryCompliance())
    dst.set_allocated_pulmonarycompliance(PBProperty::Unload(*src.m_PulmonaryCompliance));
  if (src.HasPulmonaryElastance())
    dst.set_allocated_pulmonaryelastance(PBProperty::Unload(*src.m_PulmonaryElastance));
  if (src.HasResistiveExpiratoryWorkOfBreathing())
    dst.set_allocated_resistiveexpiratoryworkofbreathing(PBProperty::Unload(*src.m_ResistiveExpiratoryWorkOfBreathing));
  if (src.HasResistiveInspiratoryWorkOfBreathing())
    dst.set_allocated_resistiveinspiratoryworkofbreathing(PBProperty::Unload(*src.m_ResistiveInspiratoryWorkOfBreathing));
  if (src.HasRespirationRate())
    dst.set_allocated_respirationrate(PBProperty::Unload(*src.m_RespirationRate));
  if (src.HasRespiratoryMuscleFatigue())
    dst.set_allocated_respiratorymusclefatigue(PBProperty::Unload(*src.m_RespiratoryMuscleFatigue));
  if (src.HasRespiratoryMusclePressure())
    dst.set_allocated_respiratorymusclepressure(PBProperty::Unload(*src.m_RespiratoryMusclePressure));
  if (src.HasSaturationAndFractionOfInspiredOxygenRatio())
    dst.set_allocated_saturationandfractionofinspiredoxygenratio(PBProperty::Unload(*src.m_SaturationAndFractionOfInspiredOxygenRatio));
  if (src.HasSpecificVentilation())
    dst.set_allocated_specificventilation(PBProperty::Unload(*src.m_SpecificVentilation));
  if (src.HasTidalVolume())
    dst.set_allocated_tidalvolume(PBProperty::Unload(*src.m_TidalVolume));
  if (src.HasTotalAlveolarVentilation())
    dst.set_allocated_totalalveolarventilation(PBProperty::Unload(*src.m_TotalAlveolarVentilation));
  if (src.HasTotalDeadSpaceVentilation())
    dst.set_allocated_totaldeadspaceventilation(PBProperty::Unload(*src.m_TotalDeadSpaceVentilation));
  if (src.HasTotalLungVolume())
    dst.set_allocated_totallungvolume(PBProperty::Unload(*src.m_TotalLungVolume));
  if (src.HasTotalPowerOfBreathing())
    dst.set_allocated_totalpowerofbreathing(PBProperty::Unload(*src.m_TotalPowerOfBreathing));
  if (src.HasTotalPulmonaryVentilation())
    dst.set_allocated_totalpulmonaryventilation(PBProperty::Unload(*src.m_TotalPulmonaryVentilation));
  if (src.HasTotalWorkOfBreathing())
    dst.set_allocated_totalworkofbreathing(PBProperty::Unload(*src.m_TotalWorkOfBreathing));
  if (src.HasTransairwayPressure())
    dst.set_allocated_transairwaypressure(PBProperty::Unload(*src.m_TransairwayPressure));
  if (src.HasTransalveolarPressure())
    dst.set_allocated_transalveolarpressure(PBProperty::Unload(*src.m_TransalveolarPressure));
  if (src.HasTransChestWallPressure())
    dst.set_allocated_transchestwallpressure(PBProperty::Unload(*src.m_TransChestWallPressure));
  if (src.HasTransMusclePressure())
    dst.set_allocated_transmusclepressure(PBProperty::Unload(*src.m_TransMusclePressure));
  if (src.HasTranspulmonaryPressure())
    dst.set_allocated_transpulmonarypressure(PBProperty::Unload(*src.m_TranspulmonaryPressure));
  if (src.HasTransrespiratoryPressure())
    dst.set_allocated_transrespiratorypressure(PBProperty::Unload(*src.m_TransrespiratoryPressure));
  if (src.HasTransthoracicPressure())
    dst.set_allocated_transthoracicpressure(PBProperty::Unload(*src.m_TransthoracicPressure));
}


void PBPhysiology::Load(const CDM_BIND::TissueSystemData& src, SETissueSystem& dst)
{
  dst.Clear();
  PBPhysiology::Serialize(src, dst);
}
void PBPhysiology::Serialize(const CDM_BIND::TissueSystemData& src, SETissueSystem& dst)
{
  if (src.has_carbondioxideproductionrate())
    PBProperty::Load(src.carbondioxideproductionrate(), dst.GetCarbonDioxideProductionRate());
  if (src.has_extracellularfluidvolume())
    PBProperty::Load(src.extracellularfluidvolume(), dst.GetExtracellularFluidVolume());
  if (src.has_extravascularfluidvolume())
    PBProperty::Load(src.extravascularfluidvolume(), dst.GetExtravascularFluidVolume());
  if (src.has_intracellularfluidph())
    PBProperty::Load(src.intracellularfluidph(), dst.GetIntracellularFluidPH());
  if (src.has_intracellularfluidvolume())
    PBProperty::Load(src.intracellularfluidvolume(), dst.GetIntracellularFluidVolume());
  if (src.has_oxygenconsumptionrate())
    PBProperty::Load(src.oxygenconsumptionrate(), dst.GetOxygenConsumptionRate());
  if (src.has_respiratoryexchangeratio())
    PBProperty::Load(src.respiratoryexchangeratio(), dst.GetRespiratoryExchangeRatio());
}

CDM_BIND::TissueSystemData* PBPhysiology::Unload(const SETissueSystem& src)
{
  CDM_BIND::TissueSystemData* dst = new CDM_BIND::TissueSystemData();
  PBPhysiology::Serialize(src, *dst);
  return dst;
}
void PBPhysiology::Serialize(const SETissueSystem& src, CDM_BIND::TissueSystemData& dst)
{
  if (src.HasCarbonDioxideProductionRate())
    dst.set_allocated_carbondioxideproductionrate(PBProperty::Unload(*src.m_CarbonDioxideProductionRate));
  if (src.HasExtracellularFluidVolume())
    dst.set_allocated_extracellularfluidvolume(PBProperty::Unload(*src.m_ExtracellularFluidVolume));
  if (src.HasExtravascularFluidVolume())
    dst.set_allocated_extravascularfluidvolume(PBProperty::Unload(*src.m_ExtravascularFluidVolume));
  if (src.HasIntracellularFluidPH())
    dst.set_allocated_intracellularfluidph(PBProperty::Unload(*src.m_IntracellularFluidPH));
  if (src.HasIntracellularFluidVolume())
    dst.set_allocated_intracellularfluidvolume(PBProperty::Unload(*src.m_IntracellularFluidVolume));
  if (src.HasOxygenConsumptionRate())
    dst.set_allocated_oxygenconsumptionrate(PBProperty::Unload(*src.m_OxygenConsumptionRate));
  if (src.HasRespiratoryExchangeRatio())
    dst.set_allocated_respiratoryexchangeratio(PBProperty::Unload(*src.m_RespiratoryExchangeRatio));
}
