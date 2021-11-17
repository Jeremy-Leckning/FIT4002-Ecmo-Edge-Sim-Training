/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#pragma once
#include "substance/SESubstanceManager.h"
class SELiquidCompartment;
class SETissueCompartment;

class PULSE_DECL SizeIndependentDepositionEfficencyCoefficient
{
  friend class PulseSubstances;
 public:
   SizeIndependentDepositionEfficencyCoefficient() {};
  ~SizeIndependentDepositionEfficencyCoefficient() {}

  double GetAirway() const { return m_airway; }
  double GetCarina() const { return m_carina; }
  double GetDeadSpace() const { return m_deadSpace; }
  double GetAlveoli() const { return m_alveoli; }

protected:
  double m_airway =0;
  double m_carina=0;
  double m_deadSpace=0;
  double m_alveoli=0;
};

/**
* @brief Manages and initializes all systems with substances needed by %Pulse
*/
class PULSE_DECL PulseSubstances : public SESubstanceManager
{
  friend class PulseEngineTest;
public:
  PulseSubstances(PulseData& data);
  virtual ~PulseSubstances() = default;

  virtual void Clear();
  virtual bool LoadSubstanceDirectory(const std::string& data_dir=".");

  virtual bool Setup();
  virtual void InitializeSubstances();

  virtual void AddActiveSubstance(const SESubstance& substance);
  virtual bool IsActive(const SESubstance& sub) const;

  inline SESubstance&  GetO2()      { return *m_O2; }
  inline SESubstance&  GetCO()      { return *m_CO; }
  inline SESubstance&  GetCO2()     { return *m_CO2; }
  inline SESubstance&  GetN2()      { return *m_N2; }
  inline SESubstance&  GetHb()      { return *m_Hb; }
  inline SESubstance&  GetHbO2()    { return *m_HbO2; }
  inline SESubstance&  GetHbCO2()   { return *m_HbCO2; }
  inline SESubstance&  GetHbCO()    { return *m_HbCO; }
  inline SESubstance&  GetHbO2CO2() { return *m_HbO2CO2; }
  inline SESubstance&  GetHCO3()    { return *m_HCO3; }
  inline SESubstance&  GetEpi()     { return *m_epi; }

  inline SESubstance&  GetAcetoacetate(){ return *m_acetoacetate; }
  inline SESubstance&  GetAlbumin()     { return *m_albumin; }
  inline SESubstance&  GetBicarbonate() { return *m_HCO3; }
  inline SESubstance&  GetCalcium()     { return *m_calcium; }
  inline SESubstance&  GetChloride()    { return *m_chloride; }
  inline SESubstance&  GetCreatinine()  { return *m_creatinine; }
  inline SESubstance&  GetGlobulin()    { return *m_globulin; }
  inline SESubstance&  GetGlucose()     { return *m_glucose; }
  inline SESubstance&  GetInsulin()     { return *m_insulin; }
  inline SESubstance&  GetLactate()     { return *m_lactate; }
  inline SESubstance&  GetPotassium()   { return *m_potassium; }
  inline SESubstance&  GetTristearin()  { return *m_tristearin; }
  inline SESubstance&  GetSodium()      { return *m_sodium; }
  inline SESubstance&  GetUrea()        { return *m_urea; }

  void CalculateGenericClearance(double volumeCleared_mL, SELiquidCompartment& cmpt, SESubstance& sub, SEScalarMass* cleared = nullptr);
  void CalculateGenericClearance(double volumeCleared_mL, SETissueCompartment& cmpt, SESubstance& sub, SEScalarMass* cleared = nullptr);
  void CalculateGenericExcretion(double VascularFlow_mL_Per_s, SETissueCompartment& cmpt, SESubstance& sub, double FractionExcreted, double timestep_s, SEScalarMass* excreted = nullptr);

  const SizeIndependentDepositionEfficencyCoefficient& GetSizeIndependentDepositionEfficencyCoefficient(const SESubstance& substance);

  double GetSubstanceMass(SESubstance&, const std::vector<SELiquidCompartment*>&, const MassUnit& unit);
  double GetSubstanceMass(SESubstance&, const std::vector<SETissueCompartment*>&, const MassUnit& unit);

  void WriteBloodGases();
  void WritePulmonaryGases();
  void ProbeBloodGases(SELiquidCompartment& cmpt, const std::string& prefix="");

  virtual void InitializeGasCompartments();
  virtual void InitializeLiquidCompartmentGases();
  virtual void InitializeLiquidCompartmentNonGases();

protected:
  virtual void InitializeBloodGases(SETissueCompartment& tissue, SELiquidCompartment& vascular);
  virtual void InitializeBloodGases(SELiquidCompartment& cmpt, double Hb_total_mM, double O2_sat, double O2_mmol_Per_L, double CO2_sat, double CO2_mmol_Per_L, double HCO3_mmol_Per_L, double pH, bool distribute = true);

  void   SetSubstanceMolarity(SESubstance&, const std::vector<SELiquidCompartment*>&, const SEScalarAmountPerVolume& molarity);  
  void   SetSubstanceMolarity(SESubstance&, const std::vector<SETissueCompartment*>&, const SEScalarAmountPerVolume& molarity);
  void   SetSubstanceMolarity(SESubstance&, const std::vector<SETissueCompartment*>&, const SEScalarAmountPerVolume& extracellular, const SEScalarAmountPerVolume& intracellular);
  
  void   SetSubstanceConcentration(SESubstance&, const std::vector<SELiquidCompartment*>&, const SEScalarMassPerVolume& concentration);
  void   SetSubstanceConcentration(SESubstance&, const std::vector<SETissueCompartment*>&, const SEScalarMassPerVolume& concentration);
  void   SetSubstanceConcentration(SESubstance&, const std::vector<SETissueCompartment*>&, const SEScalarMassPerVolume& extracellular, const SEScalarMassPerVolume& intracellular);

  // Common Substances
  //Substances
  SESubstance*  m_O2;
  SESubstance*  m_CO;
  SESubstance*  m_CO2;
  SESubstance*  m_N2;
  SESubstance*  m_Hb;
  SESubstance*  m_HbO2;
  SESubstance*  m_HbCO2;
  SESubstance*  m_HbCO;
  SESubstance*  m_HbO2CO2;
  SESubstance*  m_HCO3;
  SESubstance*  m_epi;

  SESubstance*  m_acetoacetate;
  SESubstance*  m_albumin;
  SESubstance*  m_calcium;
  SESubstance*  m_chloride;
  SESubstance*  m_creatinine;
  SESubstance*  m_globulin;
  SESubstance*  m_glucose;
  SESubstance*  m_insulin; 
  SESubstance*  m_lactate;
  SESubstance*  m_tristearin;
  SESubstance*  m_potassium;
  SESubstance*  m_sodium;
  SESubstance*  m_urea;

  bool          m_isCOActive;

  std::map<const SESubstance*, SizeIndependentDepositionEfficencyCoefficient*> m_SIDECoefficients;

  PulseData&    m_data;
};

