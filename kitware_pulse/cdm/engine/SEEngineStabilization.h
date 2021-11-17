/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

#pragma once
class SECondition;
class SEConditionManager;
class SEEngineTracker;
class SEEngineConfiguration;

class CDM_DECL SEEngineStabilization : public Loggable
{
public:
  class Controller
  {
  public:
    virtual bool AdvanceTime() = 0;
    virtual SEEngineTracker* GetEngineTracker() = 0;
    virtual double GetTimeStep(const TimeUnit& unit) = 0;
  };
  SEEngineStabilization(Logger* logger);
  virtual ~SEEngineStabilization();

  virtual void Clear();

  virtual bool SerializeToString(std::string& output, SerializationFormat) const = 0;
  virtual bool SerializeToFile(const std::string& filename) const = 0;
  virtual bool SerializeFromString(const std::string& src, SerializationFormat) = 0;
  virtual bool SerializeFromFile(const std::string& filename) = 0;

  virtual bool StabilizeRestingState(Controller& engine)=0;
  virtual bool StabilizeFeedbackState(Controller& engine) = 0;
  virtual bool StabilizeConditions(Controller& engine, const SEConditionManager& conditions)=0;
  
  virtual void LogProgress(bool b);

  virtual void CancelStabilization();

  virtual void TrackStabilization(eSwitch state);
  virtual bool IsTrackingStabilization();

  virtual bool HasStabilizationDuration();
  virtual SEScalarTime& GetStabilizationDuration();

protected:

  bool m_Cancelled;
  bool m_LogProgress;
  eSwitch m_TrackingStabilization;
  double m_currentTime_s;
  std::stringstream m_ss;

  SEScalarTime* m_StabilizationDuration;
  std::vector<const SECondition*> m_Conditions;
};
