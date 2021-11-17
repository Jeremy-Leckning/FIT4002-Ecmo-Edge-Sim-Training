/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#include "RealTimeSimulation.h"
#include "curl.cpp"

#include "patient/actions/SEHemorrhage.h"
#include "patient/actions/SESubstanceCompoundInfusion.h"
#include "substance/SESubstanceManager.h"
#include "substance/SESubstanceCompound.h"

#include "system/physiology/SEBloodChemistrySystem.h"
#include "system/physiology/SECardiovascularSystem.h"
#include "system/physiology/SERespiratorySystem.h"
#include "system/physiology/SEEnergySystem.h"
#include "system/equipment/electrocardiogram/SEElectroCardioGram.h"

#include "properties/SEScalar0To1.h"
#include "properties/SEScalarFrequency.h"
#include "properties/SEScalarMass.h"
#include "properties/SEScalarPressure.h"
#include "properties/SEScalarTime.h"
#include "properties/SEScalarVolume.h"
#include "properties/SEScalarVolumePerTime.h"
#include "properties/SEScalarTemperature.h"
#include "properties/SEScalarElectricPotential.h"

void RealTimeSimulation()
{
  // Create the engine and have it run in it's own thread
  // This call will block while the engine stabilizes
  PulseThread pThread("./ThreadedDriver.csv");
  
  // When it comes back, the engine will be running, waiting for your input

  int action;
  double severity;
  double rate;
  bool active = true;
  do
  {
    pThread.GetLogger()->Info("Enter \"1\" to Quit");
    std::cin >> action;
    switch (action)
    {
    case 1:
      active = false;
    }
  } while (active);
}

PulseThread::PulseThread(const std::string& logfile) : m_thread()
{
// Create our engine with the standard patient
 m_pe = CreatePulseEngine();
 m_pe->GetLogger()->SetLogFile(logfile);

 if (!m_pe->SerializeFromFile("./states/StandardMale@0s.json"))
 {
   m_pe->GetLogger()->Error("Could not load state, check the error");
   return;
 }

 

 // Start advancing time in a seperate thread
 m_runThread = true;
 m_thread = std::thread(&PulseThread::AdvanceTime, this);
}

PulseThread::~PulseThread()
{
  m_runThread = true;
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

void PulseThread::AdvanceTime()
{
  while(m_runThread)
  { // This runs the model simulation for 1 second at 50Hz each iteration
    std::chrono::time_point<std::chrono::steady_clock> begin;
    begin = std::chrono::steady_clock::now();
    int timeStepInMs = m_pe->GetTimeStep(TimeUnit::s) * 1000;
    int refreshRate = 50; // in Hz
    // read from DB and serialize info for ECMO and patient
    // Call pe serialize to set patient vars/conditions
    // Call ecmo serialize to set vars
    
    for (int i = 0; i < refreshRate; i++) {
      m_mutex.lock();
      m_pe->AdvanceModelTime();
      m_mutex.unlock();
      if (i == 0) // Set simulation time for first refresh for this second
      {
        vitals.setSimulationTime(m_pe->GetSimulationTime(TimeUnit::s));
      }

      double ecg = m_pe->GetElectroCardioGram()->GetLead3ElectricPotential(ElectricPotentialUnit::mV);
      vitals.appendECG(i, ecg);

    //   double spO2 = m_pe->GetBloodChemistrySystem()->GetOxygenSaturation();
    //   vitals.appendspO2(i, spO2);
    }
    Status();
    m_pe->GetLogger()->Info(std::stringstream() << vitals.getVitalsJsonStr());

    //do write to DB here
    // Uncomment this line to enable writes to DB
    // putToDB(vitals.getId(), vitals.getSimulationTime(), vitals.getVitalsJsonStr());

    auto execTime = std::chrono::steady_clock::now() - begin;
    auto sleepDuration = std::chrono::milliseconds(timeStepInMs * 50) - execTime;
    std::this_thread::sleep_for(sleepDuration);// let other things happen
  }
}

void PulseThread::Status()
{// On demand call to print vitals to the screen
  m_mutex.lock();
  double simulationTime = m_pe->GetSimulationTime(TimeUnit::s);
  double heartRate = m_pe->GetCardiovascularSystem()->GetHeartRate(FrequencyUnit::Per_min);
  double diasBP = m_pe->GetCardiovascularSystem()->GetDiastolicArterialPressure(PressureUnit::mmHg);
  double sysBP = m_pe->GetCardiovascularSystem()->GetSystolicArterialPressure(PressureUnit::mmHg);
  double meanABP = m_pe->GetCardiovascularSystem()->GetMeanArterialPressure(PressureUnit::mmHg);
  double awRR = m_pe->GetRespiratorySystem()->GetRespirationRate(FrequencyUnit::Per_min);
  double spO2 = m_pe->GetBloodChemistrySystem()->GetOxygenSaturation();
  double etCO2 = m_pe->GetRespiratorySystem()->GetEndTidalCarbonDioxidePressure(PressureUnit::mmHg);
  double temperature = m_pe->GetEnergySystem()->GetCoreTemperature(TemperatureUnit::C);
  
  vitals.setVitals(heartRate, sysBP, diasBP, meanABP, spO2, etCO2, awRR, temperature);

  m_pe->GetLogger()->Info("");
  m_pe->GetLogger()->Info(std::stringstream() <<"Simulation Time : " << m_pe->GetSimulationTime(TimeUnit::s) << "s");
  m_pe->GetLogger()->Info("");
  m_mutex.unlock();
}