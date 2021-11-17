// The following how-to functions demonstrate various ways of interacting with the Pulse engine
#include "Controller.h"
#include "engine/SEEngineTracker.h"
#include "engine/SEDataRequest.h"
#include "properties/SEScalarTime.h"


int main(int argc, char* argv[])
{
    // HowToEngineUse();
    // HowToMechanicalVentilation();
    RealTimeSimulation(); 


    // Our functions
    // test for data grabs from DB (Using chapters link for now)
    // putToDB();
    // getFromDB();

  // To do ECMO simulation


    

     
}

HowToTracker::HowToTracker(PhysiologyEngine& engine) : m_Engine(engine)
{
  m_dT_s = m_Engine.GetTimeStep(TimeUnit::s);
}

HowToTracker::~HowToTracker(){}

bool HowToTracker::AdvanceModelTime(double time_s)
{  
  // This samples the engine at each time step
  int count = static_cast<int>(time_s / m_dT_s);
  for (int i = 0; i < count; i++)
  {    
    if(!m_Engine.AdvanceModelTime())  // Compute 1 time step
      return false;

    // Pull Track will pull data from the engine and append it to the file
    m_Engine.GetEngineTracker()->TrackData(m_Engine.GetSimulationTime(TimeUnit::s));
  }
  return true;
}