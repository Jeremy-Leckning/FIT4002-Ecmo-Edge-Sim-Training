
add_executable_ex(HowToDriver
  EngineHowTo.cpp
  EngineHowTo.h
  HowTo-AirwayObstruction.cpp
  HowTo-AnesthesiaMachine.cpp
  HowTo-Asthma.cpp
  HowTo-BolusDrug.cpp
  HowTo-BrainInjury.cpp
  HowTo-CombatMultitrauma.cpp
  HowTo-ConcurrentEngines.cpp
  HowTo-ConsumeNutrients.cpp
  HowTo-COPD.cpp
  HowTo-COVID19Ventilated.cpp
  HowTo-CPR.cpp
  HowTo-CreateAPatient.cpp
  HowTo-EngineUse.cpp
  HowTo-EnvironmentChange.cpp
  HowTo-Exercise.cpp
  HowTo-Hemorrhage.cpp
  HowTo-LobarPneumonia.cpp
  HowTo-MechanicalVentilation.cpp
  HowTo-PulmonaryFibrosis.cpp
  HowTo-PulmonaryFunctionTest.cpp
  HowTo-PulseEnginePool.cpp
  HowTo-RunScenario.cpp
  HowTo-RunThreaded.cpp
  HowTo-RunThreaded.h
  HowTo-Sandbox.cpp
  HowTo-SceanrioBase.cpp
  HowTo-Serialize.cpp
  HowTo-Smoke.cpp
  HowTo-TensionPneumothorax.cpp
  HowTo-TestSystemCapability.cpp
)
target_link_libraries(HowToDriver CommonPulseModels)