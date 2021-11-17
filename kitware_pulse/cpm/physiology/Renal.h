/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#pragma once
#include "PulsePhysiologySystems.h"
#include "system/physiology/SERenalSystem.h"
class SEPatient;
class SESubstance;
class SEFluidCircuit;
class SEFluidCircuitNode;
class SEFluidCircuitPath;
class SELiquidCompartment;
class SELiquidSubstanceQuantity;
class SETissueCompartment;
class SEUrinalysis;

/**
 * @brief @copydoc Physiology_RenalSystemData
 */  
class PULSE_DECL Renal : public PulseRenalSystem
{
  friend class PulseController;
  friend class PBPulsePhysiology;//friend the serialization class
  friend class PulseEngineTest;
public:
  Renal(PulseData& data);
  virtual ~Renal();

  void Clear();

  // Set members to a stable homeostatic state
  void Initialize();
  // Set pointers and other member varialbes common to both homeostatic initialization and loading a state
  void SetUp();

  void AtSteadyState();
  void PreProcess();
  void Process(bool solve_and_transport=true);
  void PostProcess(bool solve_and_transport=true);

  // Assessments
  bool CalculateUrinalysis(SEUrinalysis& u) const;

protected:
  void ComputeExposedModelParameters() override;

  struct ActiveTransport
  {
  public:
    double leftGlucoseReabsorptionMass_mg;
    double rightGlucoseReabsorptionMass_mg;
    double leftLactateExcretedMass_mg;
    double rightLactateExcretedMass_mg;
  };

  // Initialization
  void CalculateFilterability(SESubstance& sub);
  //Conditions
  void ConsumeMeal(double elapsedTime_s);

  //Preprocess
  void CalculateUltrafiltrationFeedback();
  void   CalculateColloidOsmoticPressure(SEScalarMassPerVolume& albuminConcentration, SEScalarPressure& osmoticPressure);
  void CalculateReabsorptionFeedback();
  void   CalculateOsmoreceptorFeedback();
  void   CalculateFluidPermeability();
  void CalculateTubuloglomerularFeedback();  
  void UpdateBladderVolume();
  void ProcessActions();
  void   Urinate();

  //Process
  void CalculateActiveTransport();
  void   CalculateGlomerularTransport(SESubstance& sub);
  void   CalculateReabsorptionTransport(SESubstance& sub);
  void   CalculateSecretion();
  void   CalculateExcretion(SESubstance& sub);
  void   CalculateAutomaticClearance(SESubstance& sub);
  void   CalculateGluconeogenesis();
  void CalculateVitalSigns();

  // Serializable member variables (Set in Initialize and in schema)
  bool   m_Urinating;
  //Tubuloglomerular Feedback
  double m_leftAfferentResistance_mmHg_s_Per_mL;
  double m_rightAfferentResistance_mmHg_s_Per_mL;
  double m_leftSodiumFlowSetPoint_mg_Per_s;
  double m_rightSodiumFlowSetPoint_mg_Per_s;
  //Events
  SERunningAverage* m_urineProductionRate_mL_Per_min_runningAvg;
  SERunningAverage* m_urineOsmolarity_mOsm_Per_L_runningAvg;
  SERunningAverage* m_sodiumConcentration_mg_Per_mL_runningAvg;
  SERunningAverage* m_sodiumExcretionRate_mg_Per_min_runningAvg;
  SERunningAverage* m_leftSodiumFlow_mg_Per_s_runningAvg;
  SERunningAverage* m_rightSodiumFlow_mg_Per_s_runningAvg;
  SERunningAverage* m_leftRenalArterialPressure_mmHg_runningAvg;
  SERunningAverage* m_rightRenalArterialPressure_mmHg_runningAvg;
  
  // Stateless member variable (Set in SetUp())
  //Circuits
  SEFluidCircuit*     m_RenalCircuit;
  //Nodes
  SEFluidCircuitNode* m_leftGlomerularNode;
  SEFluidCircuitNode* m_leftBowmansNode;
  SEFluidCircuitNode* m_leftPeritubularNode;
  SEFluidCircuitNode* m_leftTubulesNode;
  SEFluidCircuitNode* m_leftRenalArteryNode;
  SEFluidCircuitNode* m_rightGlomerularNode;
  SEFluidCircuitNode* m_rightBowmansNode;
  SEFluidCircuitNode* m_rightPeritubularNode;
  SEFluidCircuitNode* m_rightTubulesNode;
  SEFluidCircuitNode* m_rightRenalArteryNode;
  SEFluidCircuitNode* m_bladderNode;
  SEFluidCircuitNode* m_leftNetGlomerularCapillariesNode;
  SEFluidCircuitNode* m_leftNetBowmansCapsulesNode;
  SEFluidCircuitNode* m_leftNetPeritubularCapillariesNode;
  SEFluidCircuitNode* m_leftNetTubulesNode;
  SEFluidCircuitNode* m_rightNetGlomerularCapillariesNode;
  SEFluidCircuitNode* m_rightNetBowmansCapsulesNode;
  SEFluidCircuitNode* m_rightNetPeritubularCapillariesNode;
  SEFluidCircuitNode* m_rightNetTubulesNode;
  //Paths
  SEFluidCircuitPath* m_leftGlomerularOsmoticSourcePath;
  SEFluidCircuitPath* m_leftBowmansOsmoticSourcePath;
  SEFluidCircuitPath* m_leftReabsorptionResistancePath;
  SEFluidCircuitPath* m_leftTubulesOsmoticSourcePath;
  SEFluidCircuitPath* m_leftPeritubularOsmoticSourcePath;
  SEFluidCircuitPath* m_leftUreterPath;
  SEFluidCircuitPath* m_leftGlomerularFilterResistancePath;
  SEFluidCircuitPath* m_leftAfferentArteriolePath;
  SEFluidCircuitPath* m_rightReabsorptionResistancePath;
  SEFluidCircuitPath* m_rightGlomerularOsmoticSourcePath;
  SEFluidCircuitPath* m_rightBowmansOsmoticSourcePath;
  SEFluidCircuitPath* m_rightTubulesOsmoticSourcePath;
  SEFluidCircuitPath* m_rightPeritubularOsmoticSourcePath;
  SEFluidCircuitPath* m_rightUreterPath;
  SEFluidCircuitPath* m_rightGlomerularFilterResistancePath;
  SEFluidCircuitPath* m_rightAfferentArteriolePath;
  SEFluidCircuitPath* m_bladderToGroundPressurePath;
  SEFluidCircuitPath* m_urethraPath;
  SEFluidCircuitPath* m_leftTubulesPath;
  SEFluidCircuitPath* m_rightTubulesPath;
  SEFluidCircuitPath* m_leftEfferentArteriolePath;
  SEFluidCircuitPath* m_rightEfferentArteriolePath;
 
  //Substances
  SESubstance* m_sodium;
  SESubstance* m_urea;
  SESubstance* m_glucose;
  SESubstance* m_lactate;
  SESubstance* m_potassium;
  //Compartments
  SELiquidCompartment* m_aorta;
  SELiquidCompartment* m_venaCava;
  SELiquidCompartment* m_bladder;
  SETissueCompartment* m_rightKidneyTissue;
  SETissueCompartment* m_leftKidneyTissue;  
  SELiquidCompartment* m_leftUreter;
  SELiquidCompartment* m_leftPeritubular;
  SELiquidCompartment* m_rightUreter;
  SELiquidCompartment* m_rightPeritubular;  
  SELiquidCompartment* m_leftGlomerular;
  SELiquidCompartment* m_leftBowmans;
  SELiquidCompartment* m_rightGlomerular;
  SELiquidCompartment* m_rightBowmans;
  SELiquidCompartment* m_leftTubules;
  SELiquidCompartment* m_rightTubules;
  SELiquidCompartment* m_ground;
  // Compartment Substance Quantites
  SELiquidSubstanceQuantity* m_aortaLactate;

  SELiquidSubstanceQuantity* m_leftPeritubularGlucose;
  SELiquidSubstanceQuantity* m_leftPeritubularPotassium;
  SELiquidSubstanceQuantity* m_leftUreterPotassium;
  SELiquidSubstanceQuantity* m_leftUreterLactate;

  SELiquidSubstanceQuantity* m_rightPeritubularGlucose;
  SELiquidSubstanceQuantity* m_rightPeritubularPotassium;
  SELiquidSubstanceQuantity* m_rightUreterPotassium;
  SELiquidSubstanceQuantity* m_rightUreterLactate;

  SELiquidSubstanceQuantity* m_bladderGlucose;
  SELiquidSubstanceQuantity* m_bladderPotassium;
  SELiquidSubstanceQuantity* m_bladderSodium;
  SELiquidSubstanceQuantity* m_bladderUrea;
  SELiquidSubstanceQuantity* m_leftTubulesSodium;
  SELiquidSubstanceQuantity* m_rightTubulesSodium;

  SELiquidSubstanceQuantity* m_leftKidneyIntracellularLactate;
  SELiquidSubstanceQuantity* m_rightKidneyIntracellularLactate;

  // Configuration 
  double m_defaultOpenResistance_mmHg_s_Per_mL;
  double m_defaultClosedResistance_mmHg_s_Per_mL;
  //   Ultrafiltration
  double m_CVOpenResistance_mmHg_s_Per_mL;
  //   Tubuloglomerular Feedback
  double m_maxLeftAfferentResistance_mmHg_s_Per_mL;
  double m_minLeftAfferentResistance_mmHg_s_Per_mL;
  double m_maxRightAfferentResistance_mmHg_s_Per_mL;
  double m_minRightAfferentResistance_mmHg_s_Per_mL;
  //   Osmoreceptor Feedback
  double m_leftReabsorptionPermeabilityModificationFactor;
  double m_rightReabsorptionPermeabilityModificationFactor;
  double m_sodiumPlasmaConcentrationSetpoint_mg_Per_mL;
  //   Secretion
  double m_baselinePotassiumConcentration_g_Per_dL;
  //   Reabsorption
  double m_leftReabsorptionPermeabilitySetpoint_mL_Per_s_mmHg_m2;
  double m_rightReabsorptionPermeabilitySetpoint_mL_Per_s_mmHg_m2;

  // Utility/ScratchPads
  SEScalarMass* m_spCleared;
  ActiveTransport m_SubstanceTransport;
};
