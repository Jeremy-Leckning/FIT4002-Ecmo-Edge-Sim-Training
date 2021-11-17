/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#include "CommonDataModelTest.h"

#include "substance/SESubstanceManager.h"
#include "substance/SESubstance.h"
#include "utils/TimingProfile.h"
#include "utils/testing/SETestReport.h"
#include "utils/testing/SETestCase.h"
#include "utils/testing/SETestSuite.h"
#include "compartment/tissue/SETissueCompartment.h"
#include "compartment/fluid/SELiquidCompartment.h"
#include "compartment/SECompartmentManager.h"

#include "properties/SEScalar0To1.h"
#include "properties/SEScalarMass.h"
#include "properties/SEScalarMassPerMass.h"
#include "properties/SEScalarMassPerVolume.h"
#include "properties/SEScalarPressure.h"
#include "properties/SEScalarTime.h"
#include "properties/SEScalarVolume.h"
#include "properties/SEScalarVolumePerTime.h"
#include "utils/GeneralMath.h"

void CommonDataModelTest::TissueCompartmentTest(const std::string& rptDirectory)
{
  TimingProfile pTimer;

  m_Logger->SetLogFile(rptDirectory + "/TissueCompartmentTest.log");
  SESubstanceManager subMgr(m_Logger);
  subMgr.LoadSubstanceDirectory();

  m_PercentTolerance = 0.2;
  m_OutDirectory = rptDirectory;

  SETestReport testReport(m_Logger);
  SETestSuite&  testSuite = testReport.CreateTestSuite();
  testSuite.SetName("TissuCompartmenteTest");

  // Tissues do not support hierarchies, and LiquidCompartments run the gambit for Extracelluar/Intracellular
  // So I am only going to Create a tissue cmpt and test serialization

  pTimer.Start("Serialization");
  SETestCase& testCase = testSuite.CreateTestCase();
  testCase.SetName("CompartmentTissueTest");

  double AcidicPhospohlipidConcentration_mg_Per_g = 20;
  double MatrixVolume_mL = 5000;
  double NeutralLipidsVolumeFraction = 0.6;
  double NeutralPhospholipidsVolumeFraction = 0.77;
  double TissueToPlasmaAlbuminRatio = 1.0;
  double TissueToPlasmaAlphaAcidGlycoproteinRatio = 0.8;
  double TissueToPlasmaLipoproteinRatio = 0.54;
  
  SECompartmentManager cmptMgr(subMgr);
  SETissueCompartment* tissue = &cmptMgr.CreateTissueCompartment("Tissue");
  tissue->GetAcidicPhospohlipidConcentration().SetValue(AcidicPhospohlipidConcentration_mg_Per_g, MassPerMassUnit::mg_Per_g);
  tissue->GetMatrixVolume().SetValue(MatrixVolume_mL, VolumeUnit::mL);
  tissue->GetNeutralLipidsVolumeFraction().SetValue(NeutralLipidsVolumeFraction);
  tissue->GetNeutralPhospholipidsVolumeFraction().SetValue(NeutralPhospholipidsVolumeFraction);
  tissue->GetTissueToPlasmaAlbuminRatio().SetValue(TissueToPlasmaAlbuminRatio);
  tissue->GetTissueToPlasmaAlphaAcidGlycoproteinRatio().SetValue(TissueToPlasmaAlphaAcidGlycoproteinRatio);
  tissue->GetTissueToPlasmaLipoproteinRatio().SetValue(TissueToPlasmaLipoproteinRatio);
  cmptMgr.StateChange();

  TestCompartmentSerialization(cmptMgr, m_OutDirectory + "/TestTissueSerialization.json");
  tissue = cmptMgr.GetTissueCompartment("Tissue");
  const SETissueCompartment* cTissue = cmptMgr.GetTissueCompartment("Tissue");

  if (GeneralMath::PercentTolerance(tissue->GetAcidicPhospohlipidConcentration().GetValue(MassPerMassUnit::mg_Per_g), AcidicPhospohlipidConcentration_mg_Per_g) > m_PercentTolerance)
  {
    m_ss << cTissue->GetName() << " AcidicPhospohlipidConcentration is not correct : " << tissue->GetAcidicPhospohlipidConcentration().GetValue(MassPerMassUnit::mg_Per_g) << " expected " << AcidicPhospohlipidConcentration_mg_Per_g;
    testCase.AddFailure(m_ss);
  }
  if (GeneralMath::PercentTolerance(cTissue->GetAcidicPhospohlipidConcentration(MassPerMassUnit::mg_Per_g), AcidicPhospohlipidConcentration_mg_Per_g) > m_PercentTolerance)
  {
    m_ss << cTissue->GetName() << " const AcidicPhospohlipidConcentration is not correct : " << cTissue->GetAcidicPhospohlipidConcentration(MassPerMassUnit::mg_Per_g) << " expected " << AcidicPhospohlipidConcentration_mg_Per_g;
    testCase.AddFailure(m_ss);
  }

  if (GeneralMath::PercentTolerance(tissue->GetMatrixVolume().GetValue(VolumeUnit::mL), MatrixVolume_mL) > m_PercentTolerance)
  {
    m_ss << cTissue->GetName() << " MatrixVolume_mL is not correct : " << tissue->GetMatrixVolume().GetValue(VolumeUnit::mL) << " expected " << MatrixVolume_mL;
    testCase.AddFailure(m_ss);
  }
  if (GeneralMath::PercentTolerance(cTissue->GetMatrixVolume(VolumeUnit::mL), MatrixVolume_mL) > m_PercentTolerance)
  {
    m_ss << cTissue->GetName() << " const MatrixVolume_mL is not correct : " << cTissue->GetMatrixVolume(VolumeUnit::mL) << " expected " << MatrixVolume_mL;
    testCase.AddFailure(m_ss);
  }

  if (GeneralMath::PercentTolerance(tissue->GetNeutralLipidsVolumeFraction().GetValue(), NeutralLipidsVolumeFraction) > m_PercentTolerance)
  {
    m_ss << cTissue->GetName() << " NeutralLipidsVolumeFraction is not correct : " << tissue->GetNeutralLipidsVolumeFraction().GetValue() << " expected " << NeutralLipidsVolumeFraction;
    testCase.AddFailure(m_ss);
  }
  if (GeneralMath::PercentTolerance(cTissue->GetNeutralLipidsVolumeFraction(), NeutralLipidsVolumeFraction) > m_PercentTolerance)
  {
    m_ss << cTissue->GetName() << " const NeutralLipidsVolumeFraction is not correct : " << cTissue->GetNeutralLipidsVolumeFraction() << " expected " << NeutralLipidsVolumeFraction;
    testCase.AddFailure(m_ss);
  }

  if (GeneralMath::PercentTolerance(tissue->GetNeutralPhospholipidsVolumeFraction().GetValue(), NeutralPhospholipidsVolumeFraction) > m_PercentTolerance)
  {
    m_ss << cTissue->GetName() << " NeutralPhospholipidsVolumeFraction is not correct : " << tissue->GetNeutralPhospholipidsVolumeFraction().GetValue() << " expected " << NeutralPhospholipidsVolumeFraction;
    testCase.AddFailure(m_ss);
  }
  if (GeneralMath::PercentTolerance(cTissue->GetNeutralPhospholipidsVolumeFraction(), NeutralPhospholipidsVolumeFraction) > m_PercentTolerance)
  {
    m_ss << cTissue->GetName() << " const NeutralPhospholipidsVolumeFraction is not correct : " << cTissue->GetNeutralPhospholipidsVolumeFraction() << " expected " << NeutralPhospholipidsVolumeFraction;
    testCase.AddFailure(m_ss);
  }

  if (GeneralMath::PercentTolerance(tissue->GetTissueToPlasmaAlbuminRatio().GetValue(), TissueToPlasmaAlbuminRatio) > m_PercentTolerance)
  {
    m_ss << cTissue->GetName() << " TissueToPlasmaAlbuminRatio is not correct : " << tissue->GetTissueToPlasmaAlbuminRatio().GetValue() << " expected " << TissueToPlasmaAlbuminRatio;
    testCase.AddFailure(m_ss);
  }
  if (GeneralMath::PercentTolerance(cTissue->GetTissueToPlasmaAlbuminRatio(), TissueToPlasmaAlbuminRatio) > m_PercentTolerance)
  {
    m_ss << cTissue->GetName() << " const TissueToPlasmaAlbuminRatio is not correct : " << cTissue->GetTissueToPlasmaAlbuminRatio() << " expected " << TissueToPlasmaAlbuminRatio;
    testCase.AddFailure(m_ss);
  }

  if (GeneralMath::PercentTolerance(tissue->GetTissueToPlasmaAlphaAcidGlycoproteinRatio().GetValue(), TissueToPlasmaAlphaAcidGlycoproteinRatio) > m_PercentTolerance)
  {
    m_ss << cTissue->GetName() << " TissueToPlasmaAlphaAcidGlycoproteinRatio is not correct : " << tissue->GetTissueToPlasmaAlphaAcidGlycoproteinRatio().GetValue() << " expected " << TissueToPlasmaAlphaAcidGlycoproteinRatio;
    testCase.AddFailure(m_ss);
  }
  if (GeneralMath::PercentTolerance(cTissue->GetTissueToPlasmaAlphaAcidGlycoproteinRatio(), TissueToPlasmaAlphaAcidGlycoproteinRatio) > m_PercentTolerance)
  {
    m_ss << cTissue->GetName() << " const TissueToPlasmaAlphaAcidGlycoproteinRatio is not correct : " << cTissue->GetTissueToPlasmaAlphaAcidGlycoproteinRatio() << " expected " << TissueToPlasmaAlphaAcidGlycoproteinRatio;
    testCase.AddFailure(m_ss);
  }

  if (GeneralMath::PercentTolerance(tissue->GetTissueToPlasmaLipoproteinRatio().GetValue(), TissueToPlasmaLipoproteinRatio) > m_PercentTolerance)
  {
    m_ss << cTissue->GetName() << " TissueToPlasmaLipoproteinRatio is not correct : " << tissue->GetTissueToPlasmaLipoproteinRatio().GetValue() << " expected " << TissueToPlasmaLipoproteinRatio;
    testCase.AddFailure(m_ss);
  }
  if (GeneralMath::PercentTolerance(cTissue->GetTissueToPlasmaLipoproteinRatio(), TissueToPlasmaLipoproteinRatio) > m_PercentTolerance)
  {
    m_ss << cTissue->GetName() << " const TissueToPlasmaLipoproteinRatio is not correct : " << cTissue->GetTissueToPlasmaLipoproteinRatio() << " expected " << TissueToPlasmaLipoproteinRatio;
    testCase.AddFailure(m_ss);
  }

  testCase.GetDuration().SetValue(pTimer.GetElapsedTime_s("Serialization"), TimeUnit::s);

  testReport.SerializeToFile(rptDirectory + "/TissueCompartmentTestReport.json");
}