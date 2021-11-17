/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#include <mutex>
#include <thread>

#include "CommonDataModel.h"
#include "PulsePhysiologyEngine.h"

// This class will run Pulse in it's own thread and accept changes to hemorrage and iv flow as the engine is running

// Forward declare what we will use in our thread
class SEHemorrhage;
class SESubstanceCompoundInfusion;
class PhysiologyEngine;

/**
 * Vitals 
 */
class Vitals 
{
public: 
  Vitals(std::string id) {this->id = id;};

  std::string getVitalsJsonStr()
  {
    std::stringstream jsonString;
    std::stringstream ecgString;

    jsonString << "{\"user_id\": \"" << id << "\",";
    jsonString << "\"simulation_time\": \"" << simulationTime << "\",";
    jsonString << "\"pulse_rate\":" << heartRate << ",";
    ecgString << "\"ecg_mV\":[";
    for (int i = 0; i < 50; i++) 
    {
      ecgString << ecg_mV[i];
      if (i < 49) {
        ecgString << ", ";
      } else {
        ecgString << "],";
      }
    }
    jsonString << ecgString.str();

    jsonString << "\"systolic_bp\":" << systolicPressure << ",";
    jsonString << "\"diastolic_bp\":" << diastolicPressure << ",";
    jsonString << "\"mean_arterial_bp\": " << meanArterialBloodPressure << ",";
    jsonString << "\"spo2\":" << bloodOxygenSaturation << ",";
    jsonString << "\"etco2\": " << endTidalCarbonDioxideSaturation * 100 << ",";
    jsonString << "\"respiration_rate\": " << respirationRatePerMin << ",";
    jsonString << "\"core_temperature\":" << coreTemperatureDegC;
    
    jsonString << "}";

    return jsonString.str();
  }

  void setVitals(double heartRate, double sysPressure, double diasPressure, double meanABP, double spO2, double etCO2, double respirationRate, double temperature)
  {
    this->heartRate = heartRate;
    this->systolicPressure = sysPressure;
    this->diastolicPressure = diasPressure;
    this->meanArterialBloodPressure = meanABP;
    this->bloodOxygenSaturation = spO2;
    this->endTidalCarbonDioxideSaturation = etCO2;
    this->respirationRatePerMin = respirationRate;
    this->coreTemperatureDegC = temperature;
  }

  void appendECG(int i, double value) { if (i < 50) { ecg_mV[i] = value;}};

  // void appendspO2(int i, double value) { if (i < 50) { bloodOxygenSaturation[i] = value;}};

  std::string getId() {return id;};
  double getSimulationTime() {return simulationTime;};
  void setSimulationTime(double time) {simulationTime = time;};

protected: 
  std::string id;
  double simulationTime;
  double ecg_mV[50];
  double bloodOxygenSaturation;
  double heartRate;
  double systolicPressure;
  double diastolicPressure;
  double meanArterialBloodPressure;
  double endTidalCarbonDioxideSaturation;
  double respirationRatePerMin;
  double coreTemperatureDegC;
  
};

class PulseThread
{
public:
  PulseThread(const std::string& logfile);
  virtual ~PulseThread();

  void Status();

  Logger* GetLogger() { return m_pe->GetLogger(); }

protected:
  void AdvanceTime();
  
  std::unique_ptr<PhysiologyEngine> m_pe;

  std::thread m_thread;
  std::mutex  m_mutex;
  bool m_runThread;
  Vitals vitals = Vitals("1");
};