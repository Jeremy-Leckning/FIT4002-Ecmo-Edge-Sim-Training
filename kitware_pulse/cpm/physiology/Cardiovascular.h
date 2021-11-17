/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#pragma once
#include "PulsePhysiologySystems.h"
#include "system/physiology/SECardiovascularSystem.h"
#include "substance/SESubstanceTransport.h"
class SEPatient;
class SEHemorrhage;
class SELiquidCompartment;
class SEGasCompartment;
class SELiquidSubstanceQuantity;
class SELiquidCompartmentGraph;
class SELiquidCompartmentLink;
class SEFluidCircuit;
class SEFluidCircuitNode;
class SEFluidCircuitPath;
class SEFluidCircuitCalculator;

/**
* @brief 
* The %Cardiovascular system utilizes circuit methodology to characterize the intravascular fluid dynamics throughout the body.
* @copydoc Physiology_CardiovascularSystemData
* @details
* The %Cardiovascular system utilizes circuit methodology to evaluate the hemodynamics throughout the human body.
* The cardiovascular system consists of a representation of the human vasculature. The heart model is the driving force that creates blood flow
* through the cardiovascular system. The resulting blood flow is utilized by other physiologic systems as a means of transporting the oxygen, carbon dioxide
* and other substances throughout the human body. The system may be modified to mimic real world insults and interventions. Due to its interconnectedness
* with other systems, if alterations are made to the cardiovascular system then the feedback will be felt in the other physiologic systems.
*
*/
class PULSE_DECL Cardiovascular : public PulseCardiovascularSystem
{
  friend class PulseController;
  friend class PBPulsePhysiology;//friend the serialization class
  friend class PulseEngineTest;
public:
  Cardiovascular(PulseData& data);
  virtual ~Cardiovascular();

  void Clear();

  // Set members to a stable homeostatic state
  void Initialize();
  // Set pointers and other member varialbes common to both homeostatic initialization and loading a state
  void SetUp();

  void AtSteadyState();
  void PreProcess();
  void Process(bool solve_and_transport=true);
  void PostProcess(bool solve_and_transport=true);

protected:
  void ComputeExposedModelParameters() override;
  
  // Initialize
  void TuneCircuit();
  /**/void TunePaths(double systemicResistanceScale, double systemicComplianceScale, double aortaResistanceScale, double aortaComplianceScale, double rightHeartResistanceScale, double venaCavaComplianceScale);
  /**/void TuneTissue(double time_s, DataTrack& track, std::ofstream& circuitFile);

  //Condition Methods
  void ChronicRenalStenosis();
  void ChronicAnemia();
  void ChronicHeartFailure();
  void ChronicPericardialEffusion();

  // PreProcess:
  void HeartDriver();
  /**/void AdjustVascularTone();
  /****/void MetabolicToneResponse();
  /**/void BeginCardiacCycle();
  /**/void CalculateHeartElastance();
  /**/void UpdateHeartRhythm();
  void ProcessActions();
  //Action methods
  /**/void CPR();
  /****/void CalculateAndSetCPRcompressionForce();
  /**/void Hemorrhage();
  /**/void InternalHemorrhagePressureApplication();
  /**/void PericardialEffusion();
  /**/void PericardialEffusionPressureApplication();
  /**/void CardiacArrest();
  /**/void TraumaticBrainInjury();
  //Respiratory effects
  void CalculatePleuralCavityVenousEffects();

  // Process:
  void CalculateVitalSigns();
  /**/void CalculateHeartRate();
  /**/void RecordAndResetCardiacCycle();

  // Serializable member variables (Set in Initialize and in schema)
  //Driver
  bool   m_StartSystole;
  bool   m_HeartFlowDetected;
  bool   m_EnterCardiacArrest;// Can't go into cardiac arrest during the middle of a cycle
  double m_CardiacCyclePeriod_s;
  double m_CurrentCardiacCycleDuration_s; // How long have we been in this heart beat
  double m_LeftHeartElastanceModifier;// from Heart Failure and such
  double m_LeftHeartElastance_mmHg_Per_mL;
  double m_LeftHeartElastanceMax_mmHg_Per_mL;
  double m_LeftHeartElastanceMin_mmHg_Per_mL;
  double m_RightHeartElastance_mmHg_Per_mL;
  double m_RightHeartElastanceMax_mmHg_Per_mL;
  double m_RightHeartElastanceMin_mmHg_Per_mL;
  //CPR
  double m_CompressionTime_s;
  double m_CompressionRatio;
  double m_CompressionPeriod_s;
  // Vitals and Averages
  double m_CurrentCardiacCycleTime_s;
  double m_CardiacCycleDiastolicVolume_mL; // Maximum left heart volume for the current cardiac cycle
  double m_CardiacCycleAortaPressureLow_mmHg; // The current low for this cycle - Reset at the start of systole
  double m_CardiacCycleAortaPressureHigh_mmHg; // The current high for this cycle - Reset at the start of systole
  double m_CardiacCyclePulmonaryArteryPressureLow_mmHg;
  double m_CardiacCyclePulmonaryArteryPressureHigh_mmHg;
  double m_LastCardiacCycleMeanArterialCO2PartialPressure_mmHg;
  double m_CardiacCycleStrokeVolume_mL; // Total volume of the left heart flow for the current cardiac cycle
  SERunningAverage* m_CardiacCycleArterialPressure_mmHg;
  SERunningAverage* m_CardiacCycleArterialCO2PartialPressure_mmHg;
  SERunningAverage* m_CardiacCyclePulmonaryCapillariesWedgePressure_mmHg;
  SERunningAverage* m_CardiacCyclePulmonaryCapillariesFlow_mL_Per_s;
  SERunningAverage* m_CardiacCyclePulmonaryShuntFlow_mL_Per_s;
  SERunningAverage* m_CardiacCyclePulmonaryArteryPressure_mmHg;
  SERunningAverage* m_CardiacCycleCentralVenousPressure_mmHg;
  SERunningAverage* m_CardiacCycleSkinFlow_mL_Per_s;
  
  // Stateless member variable (Set in SetUp())
  bool                             m_TuneCircuit = true;
  std::string                      m_TuningFile;

  // Hemorrhage
  struct HemorrhageTrack
  {
    SELiquidCompartment* Compartment=nullptr;
    std::vector<SEFluidCircuitNode*> Nodes;
    std::map<SEFluidCircuitPath*, SELiquidCompartmentLink*> Paths2Links;
    short NumNodesWithVolume=0;
  };
  std::map<SEHemorrhage*, HemorrhageTrack*>m_HemorrhageTrack;

  double                           m_minIndividialSystemicResistance_mmHg_s_Per_mL;
  
  SEFluidCircuitCalculator*        m_circuitCalculator;
  SELiquidTransporter*             m_transporter;

  SEFluidCircuit*                  m_CirculatoryCircuit;
  SELiquidCompartmentGraph*        m_CirculatoryGraph;

  SEFluidCircuitNode*              m_MainPulmonaryArteries;
  SEFluidCircuitNode*              m_LeftHeart2;
  SEFluidCircuitNode*              m_Ground;

  SEFluidCircuitPath*              m_AortaCompliance;
  SEFluidCircuitPath*              m_AortaResistance;
  SEFluidCircuitPath*              m_VenaCavaCompliance;
  SEFluidCircuitPath*              m_RightHeartResistance;

  SEFluidCircuitPath*              m_LeftPulmonaryArteriesToVeins;
  SEFluidCircuitPath*              m_LeftPulmonaryArteriesToCapillaries;
  SEFluidCircuitPath*              m_RightPulmonaryArteriesToVeins;
  SEFluidCircuitPath*              m_RightPulmonaryArteriesToCapillaries;

  SEFluidCircuitPath*              m_InternalHemorrhageToAorta;
  SEFluidCircuitPath*              m_pAortaToBone;
  SEFluidCircuitPath*              m_pAortaToBrain;
  SEFluidCircuitPath*              m_pBrainToVenaCava;
  SEFluidCircuitPath*              m_pAortaToLiver;
  SEFluidCircuitPath*              m_pAortaToLeftKidney;
  SEFluidCircuitPath*              m_pAortaToLargeIntestine;
  SEFluidCircuitPath*              m_pAortaToMuscle;
  SEFluidCircuitPath*              m_pMuscleToVenaCava;
  SEFluidCircuitPath*              m_pAortaToMyocardium;
  SEFluidCircuitPath*              m_pMyocardiumToVenaCava;
  SEFluidCircuitPath*              m_pAortaToRightKidney;
  SEFluidCircuitPath*              m_pAortaToSkin;
  SEFluidCircuitPath*              m_pAortaToSmallIntestine;
  SEFluidCircuitPath*              m_pAortaToSplanchnic;
  SEFluidCircuitPath*              m_pAortaToSpleen;

  SEFluidCircuitPath*              m_pGndToPericardium;
  SEFluidCircuitPath*              m_pPericardiumToGnd;
  SEFluidCircuitPath*              m_pRightHeartToGnd;
  SEFluidCircuitPath*              m_pRightHeart;
  SEFluidCircuitPath*              m_pLeftHeartToGnd;
  SEFluidCircuitPath*              m_pLeftHeart;
  SEFluidCircuitPath*              m_LeftHeartToAorta;

  SEFluidCircuitPath*              m_pBrainResistanceUpstream;
  SEFluidCircuitPath*              m_pBrainResistanceDownstream;

  SEFluidCircuitPath*              m_leftRenalArteryPath;
  SEFluidCircuitPath*              m_rightRenalArteryPath;

  SEFluidCircuitPath*              m_pGndToAbdominalCavity;
  SEFluidCircuitPath*              m_pAbdominalCavityToGnd;
  
  SELiquidCompartment*             m_AbdominalCavity;
  SELiquidCompartment*             m_Aorta;
  SELiquidSubstanceQuantity*       m_AortaCO2;
  SELiquidCompartment*             m_Brain;
  SELiquidCompartment*             m_Groundcmpt;
  SELiquidCompartment*             m_LeftHeart;
  SELiquidCompartment*             m_LeftPulmonaryCapillaries;
  SELiquidCompartment*             m_LeftPulmonaryArteries;
  SELiquidCompartment*             m_LeftPulmonaryVeins;
  SELiquidCompartment*             m_Pericardium;
  SELiquidCompartment*             m_RightHeart;
  SELiquidCompartment*             m_RightPulmonaryCapillaries;
  SELiquidCompartment*             m_RightPulmonaryArteries;
  SELiquidCompartment*             m_RightPulmonaryVeins;
  SELiquidCompartment*             m_VenaCava;

  SEGasCompartment*                m_leftPleuralCavity;
  SEGasCompartment*                m_rightPleuralCavity;
  SEGasCompartment*                m_PleuralCavity;
  SEGasCompartment*                m_Ambient;

  std::vector<SEFluidCircuitPath*> m_systemicResistancePaths;
  std::vector<SEFluidCircuitPath*> m_systemicCompliancePaths;
};
