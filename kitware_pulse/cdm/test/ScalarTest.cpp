/* Distributed under the Apache License, Version 2.0.
   See accompanying NOTICE file for details.*/

// Testing some basic circuit functionality testing
#include "CommonDataModelTest.h"
#include "properties/SEScalarAmount.h"
#include "properties/SEScalarAmountPerVolume.h"
#include "properties/SEScalarLength.h"
#include "properties/SEScalar0To1.h"
#include "properties/SEScalarFrequency.h"
#include "properties/SEScalarInversePressure.h"
#include "properties/SEScalarMass.h"
#include "properties/SEScalarMassPerMass.h"
#include "properties/SEScalarMassPerTime.h"
#include "properties/SEScalarMassPerVolume.h"
#include "properties/SEScalarPressure.h"
#include "properties/SEScalarPressureTimePerVolume.h"
#include "properties/SEScalarTemperature.h"
#include "properties/SEScalarTime.h"
#include "properties/SEScalarVolume.h"
#include "properties/SEScalarVolumePerPressure.h"
#include "properties/SEScalarVolumePerTime.h"

#include "utils/DataTrack.h"
#include "engine/SEDecimalFormat.h"

void CommonDataModelTest::ScalarTest(const std::string& sOutputDirectory)
{
  std::ofstream file;
  SEDecimalFormat fixed;
  fixed.SetNotation(eDecimalFormat_Type::FixedMantissa);
  fixed.SetPrecision(8);
  SEDecimalFormat sci;
  sci.SetNotation(eDecimalFormat_Type::SignificantDigits);
  sci.SetPrecision(4);

  DataTrack track;
  track.SetFormatting("Fixed", fixed);
  track.SetFormatting("Scientific", sci);
  track.CreateFile("TrackText.csv", file);
  for (int i = 0; i < 10; i++)
  {
    double d = std::sqrt(i)+100;
    track.Probe("Fixed", d);
    track.Probe("Scientific", d);
    track.StreamProbesToFile(i, file);
    std::cout << d << std::endl;
  }


  CCompoundUnit g_Per_m3("g/m^3");
  CCompoundUnit ug_Per_mL("ug/mL"); 
  Convert(1, g_Per_m3, ug_Per_mL);
  
  SEScalarLength d;
  d.SetValue(1, LengthUnit::m);
  std::cout << d << std::endl;
  std::cout << d.GetValue(LengthUnit::m) << std::endl;
  std::cout << d.GetValue(LengthUnit::cm) << std::endl;

  SEScalarTemperature t;
  t.SetValue(5,TemperatureUnit::C);
  std::cout<<t.GetValue(TemperatureUnit::K)<<std::endl;
  t.SetValue(5,TemperatureUnit::K);
  std::cout<<t.GetValue(TemperatureUnit::C)<<std::endl;


  SEScalarPressureTimePerVolume r;
  r.SetValue(0, PressureTimePerVolumeUnit::GetCompoundUnit("mmHg s/mL"));

  SEScalarVolume v;
  v.SetValue(1,VolumeUnit::L);
  double m3 = v.GetValue(VolumeUnit::m3);//0.0010000000000000000
  v.IncrementValue(-2*6,VolumeUnit::m3);
  m3 = v.GetValue(VolumeUnit::m3);//m3 = -1.9990000000000001

  SEScalarPressure p;
  p.SetValue(1,PressureUnit::Pa);

  //
  //if(!p.IsValidUnit("Pa"))
  //  std::cerr<<"Pa should be a valid Pressure unit"<<std::endl;
  //if(p.IsValidUnit("Pap"))
  //  std::cerr<<"Pap should NOT be a valid Pressure unit"<<std::endl;
  //p.SetValue(5,PressureUnit::Pa);
  //std::cout<<"Testing Scalar "<<p.GetValue(PressureUnit::Pa)<<PressureUnit::Pa<<std::endl;
  //std::cout<<"Testing Scalar "<<p.GetValue(PressureUnit::mmHg)<<PressureUnit::mmHg<<std::endl;
  //std::cout<<"Testing Scalar "<<p.GetValue(PressureUnit::cmH2O)<<PressureUnit::cmH2O<<std::endl;

  file.close();
}