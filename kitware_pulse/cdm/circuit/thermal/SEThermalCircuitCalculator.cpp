/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#include "stdafx.h"
#include "circuit/thermal/SEThermalCircuitCalculator.h"

#include "properties/SEScalarHeatCapacitance.h"
#include "properties/SEScalarPower.h"
#include "properties/SEScalarHeatInductance.h"
#include "properties/SEScalarTemperature.h"
#include "properties/SEScalarEnergy.h"
#include "properties/SEScalarHeatResistance.h"


SEThermalCircuitCalculator::SEThermalCircuitCalculator(Logger* logger) : SECircuitCalculator<SEThermalCircuit, SEThermalCircuitNode,SEThermalCircuitPath, SEThermalBlackBox, HeatCapacitanceUnit, PowerUnit, HeatInductanceUnit, TemperatureUnit, EnergyUnit, HeatResistanceUnit>(
  HeatCapacitanceUnit::J_Per_K, PowerUnit::W, HeatInductanceUnit::K_s_Per_W, TemperatureUnit::K, EnergyUnit::J,HeatResistanceUnit::K_Per_W,logger)
{

}
SEThermalCircuitCalculator::SEThermalCircuitCalculator(const HeatCapacitanceUnit& c, const PowerUnit& f, const HeatInductanceUnit& i, const TemperatureUnit& p, const EnergyUnit& q, const HeatResistanceUnit& r, Logger* logger) : SECircuitCalculator<SEThermalCircuit, SEThermalCircuitNode, SEThermalCircuitPath, SEThermalBlackBox, HeatCapacitanceUnit, PowerUnit, HeatInductanceUnit, TemperatureUnit, EnergyUnit, HeatResistanceUnit>(c, f, i, p, q, r, logger)
{

}
SEThermalCircuitCalculator::~SEThermalCircuitCalculator()
{
  
}
