/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#include "HowTo-RunThreaded.h"

#include "patient/actions/SEHemorrhage.h"
#include "patient/actions/SESubstanceCompoundInfusion.h"
#include "substance/SESubstanceManager.h"
#include "substance/SESubstanceCompound.h"

#include "system/physiology/SEBloodChemistrySystem.h"
#include "system/physiology/SECardiovascularSystem.h"
#include "system/physiology/SERespiratorySystem.h"

#include "properties/SEScalar0To1.h"
#include "properties/SEScalarFrequency.h"
#include "properties/SEScalarMass.h"
#include "properties/SEScalarPressure.h"
#include "properties/SEScalarTime.h"
#include "properties/SEScalarVolume.h"
#include "properties/SEScalarVolumePerTime.h"

void HowToDynamicHemorrhage()
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
    pThread.GetLogger()->Info("Enter Interger for Action to Perform : [1]Status, [2]Hemorrhage, [3]IVFluids, [4]Quit");
    std::cin >> action;
    switch (action)
    {
    case 1:
      pThread.Status();
      break;
    case 2:
      pThread.GetLogger()->Info("Enter Hemorrhage Severity [0-1] : ");
      std::cin >> severity;
      pThread.GetLogger()->Info(std::stringstream() << severity);
      pThread.SetHemorrhageSeverity(severity);
      break;
    case 3:
      pThread.GetLogger()->Info("Enter IV Fluids Rate in mL/min : ");
      std::cin >> rate;
      pThread.GetLogger()->Info(std::stringstream() << rate);
      pThread.SetIVFluidsFlow_mL_Per_min(rate);
      break;
    case 4:
      active = false;
    }
  } while (active);
}

PulseThread::PulseThread(const std::string& logfile) : m_thread()
{
  // Create our engine with the standard patient
  m_pe = CreatePulseEngine();
  m_pe->GetLogger()->SetLogFile(logfile);
  const SESubstanceCompound* saline = m_pe->GetSubstanceManager().GetCompound("Saline");

  if (!m_pe->SerializeFromFile("./states/StandardMale@0s.json"))
  {
    m_pe->GetLogger()->Error("Could not load state, check the error");
    return;
  }

  // Create and initialize our actions
  m_infusion = new SESubstanceCompoundInfusion(*saline);
  m_hemorrhage = new SEHemorrhage();
  m_hemorrhage->SetCompartment(pulse::VascularCompartment::RightLeg);//the location of the hemorrhage  

  // Start advancing time in a seperate thread
  m_runThread = true;
  m_thread = std::thread(&PulseThread::AdvanceTime, this);
}

PulseThread::~PulseThread()
{
  m_runThread = false;
  std::this_thread::sleep_for(std::chrono::seconds(2));
  SAFE_DELETE(m_infusion);
  SAFE_DELETE(m_hemorrhage);
}

void PulseThread::SetHemorrhageSeverity(double s)
{
  m_hemorrhage->GetSeverity().SetValue(s);
  m_mutex.lock();
  m_pe->ProcessAction(*m_hemorrhage);
  m_mutex.unlock();
}

void PulseThread::SetIVFluidsFlow_mL_Per_min(double rate)
{
  // For this example, I am always resetting the bag volume on every change, but you may want to allow the bag to run out..
  m_infusion->GetBagVolume().SetValue(500, VolumeUnit::mL);//the total volume in the bag of Saline
  m_infusion->GetRate().SetValue(100, VolumePerTimeUnit::mL_Per_min);//The rate to admnister the compound in the bag in this case saline
  m_mutex.lock();
  m_pe->ProcessAction(*m_infusion);
  m_mutex.unlock();
}

void PulseThread::AdvanceTime()
{
  while(m_runThread)
  {
    m_mutex.lock();
    m_pe->AdvanceModelTime(1, TimeUnit::s);
    m_mutex.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(25));// let other things happen
  }
}

void PulseThread::Status()
{// On demand call to print vitals to the screen
  m_mutex.lock();
  m_pe->GetLogger()->Info("");
  m_pe->GetLogger()->Info(std::stringstream() <<"Simulation Time : " << m_pe->GetSimulationTime(TimeUnit::s) << "s");
  m_pe->GetLogger()->Info(std::stringstream() <<"Cardiac Output : " << m_pe->GetCardiovascularSystem()->GetCardiacOutput(VolumePerTimeUnit::mL_Per_min) << VolumePerTimeUnit::mL_Per_min);
  m_pe->GetLogger()->Info(std::stringstream() <<"Blood Volume : " << m_pe->GetCardiovascularSystem()->GetBloodVolume(VolumeUnit::mL) << VolumeUnit::mL);
  m_pe->GetLogger()->Info(std::stringstream() <<"Mean Arterial Pressure : " << m_pe->GetCardiovascularSystem()->GetMeanArterialPressure(PressureUnit::mmHg) << PressureUnit::mmHg);
  m_pe->GetLogger()->Info(std::stringstream() <<"Systolic Pressure : " << m_pe->GetCardiovascularSystem()->GetSystolicArterialPressure(PressureUnit::mmHg) << PressureUnit::mmHg);
  m_pe->GetLogger()->Info(std::stringstream() <<"Diastolic Pressure : " << m_pe->GetCardiovascularSystem()->GetDiastolicArterialPressure(PressureUnit::mmHg) << PressureUnit::mmHg);
  m_pe->GetLogger()->Info(std::stringstream() <<"Heart Rate : " << m_pe->GetCardiovascularSystem()->GetHeartRate(FrequencyUnit::Per_min) << "bpm");
  m_pe->GetLogger()->Info(std::stringstream() <<"Respiration Rate : " << m_pe->GetRespiratorySystem()->GetRespirationRate(FrequencyUnit::Per_min) << "bpm");
  m_pe->GetLogger()->Info("");
  m_mutex.unlock();
}