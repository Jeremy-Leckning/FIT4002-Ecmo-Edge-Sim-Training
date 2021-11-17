/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

// Note that this project is set with the following Additional Include Paths: ../include;../include/cdm;../include/cdm/bind
// This will build an executable that is intended to execute a how-to method

#include <mutex>
#include <thread>

#include "CommonDataModel.h"
#include "PulsePhysiologyEngine.h"

class PhysiologyEngine;


// The following how-to functions are defined in their own file
void RealTimeSimulation();

class SEDataRequest;

/// This class is here to demonstrate executing the engine
/// and populating a csv file with data from the engine 
/// This class will handle advancing time on the engine
class HowToTracker
{
private:
  double m_dT_s;  // Cached Engine Time Step
  PhysiologyEngine& m_Engine;
public:
  HowToTracker(PhysiologyEngine& engine);
  ~HowToTracker();

  // This class will operate on seconds
  bool AdvanceModelTime(double time_s);
};