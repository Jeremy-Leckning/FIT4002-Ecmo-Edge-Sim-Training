/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#pragma once
struct error_functor;
class SESubstance;
class SESubstanceManager;
class SELiquidCompartment;
class SELiquidSubstanceQuantity;

/**
* @brief
* The %SaturationCalculator class holds the blood gas distribution model.
*/
class PULSE_DECL SaturationCalculator : public Loggable
{
  friend class PulseController;
  friend error_functor;
  friend class PulseEngineTest;
public:
  SaturationCalculator(PulseData& data);
  virtual ~SaturationCalculator();

  bool Setup();

  void SetBodyState(const SEScalarMassPerVolume& AlbuminConcentration, const SEScalar0To1& Hematocrit, const SEScalarTemperature& Temperature, const SEScalarAmountPerVolume& StrongIonDifference, const SEScalarAmountPerVolume& Phosphate);
  void CalculateBloodGasDistribution(SELiquidCompartment& cmpt);
  void CalculateCarbonMonoxideSpeciesDistribution(SELiquidCompartment& cmpt);

protected:
  // Stewart Model + Dash-Bassingthwaighte Model + Henderson-Hasselbach Model
  void CalculateHemoglobinSaturations(double O2PartialPressureGuess_mmHg, double CO2PartialPressureGuess_mmHg, double pH, double temperature_C, double  hematocrit, double& OxygenSaturation, double& CarbonDioxideSaturation, double CO2_scaling_factor);
  bool DistributeHemoglobinBySaturation();

  PulseData& m_data;
  // All properties are stateless and are set by either the Initialize method or SetBodyState method
  SESubstance* m_O2;
  SESubstance* m_Hb;
  SESubstance* m_HbO2;
  SESubstance* m_HbO2CO2;
  SESubstance* m_CO2;
  SESubstance* m_CO;
  SESubstance* m_HbCO;
  SESubstance* m_HCO3;
  SESubstance* m_HbCO2;
  // Used for conversions
  double m_O2_g_Per_mol;
  double m_CO2_g_Per_mol;
  double m_HCO3_g_Per_mol;
  double m_Hb_g_Per_mol;
  double m_HbO2_g_Per_mol;
  double m_HbCO2_g_Per_mol;
  double m_HbO2CO2_g_Per_mol;
  // This is the current compartment and the quantities we are balancing
  SELiquidCompartment*       m_cmpt;
  SELiquidSubstanceQuantity* m_subO2Q;
  SELiquidSubstanceQuantity* m_subCO2Q;
  SELiquidSubstanceQuantity* m_subCOQ;
  SELiquidSubstanceQuantity* m_subHbCOQ;
  SELiquidSubstanceQuantity* m_subHCO3Q;
  SELiquidSubstanceQuantity* m_subHbQ;
  SELiquidSubstanceQuantity* m_subHbO2Q;
  SELiquidSubstanceQuantity* m_subHbCO2Q;
  SELiquidSubstanceQuantity* m_subHbO2CO2Q;
  // The current state of the body to balance to
  double m_albumin_g_per_L;
  double m_hematocrit;
  double m_temperature_C;
  // Here is the stuff that will need to go into the CDM
  double m_StrongIonDifference_mmol_Per_L; // BloodChemistrySystemData mmol/L
  double m_Phosphate_mmol_Per_L; //BloodChemistryData mmol/L
};
