# Pulse Engine

## Foreword
Pulse Engine is used to compute and simulate the human physiology. The current ecmoDriver program only does human physiology simulation. The ECMO compartment/model has yet to be fully integrated to the Pulse Engine, hence is still unable to simulate human physiology under ECMO treatment.  


## Installation
NOTE: If you are using Windows, you can follow the instructions in this link https://gitlab.kitware.com/physiology/engine/-/wikis/Using%20MSVC to build Pulse engine with CMAKE GUI and MSVC.

The ECMO extensions were done based on Kitware pulse Version 3.2.0 https://gitlab.kitware.com/physiology/engine/-/releases/REL_3_2_0 

Ensure you have installed the dependencies required as stated in the Pulse Engine repository

To use Pulse Engine, follow the instructions below:
1. Clone Pulse Engine repository.
~~~~~~~~~~~~~~~~~~~
$ mkdir Pulse
$ cd Pulse
$ git clone https://gitlab.kitware.com/physiology/engine
~~~~~~~~~~~~~~~~~~~

2. Navigate to Pulse/engine/src.
3. Locate and delete cpp directory. Replace with the cpp directory found in this repository.
4. To enable writes to DB for pulse engine, navigate to cpp/ecmo/RealTimeSimulation.cpp and uncomment line 108.
5. Return to Pulse directory
6. Build Pulse Engine
~~~~~~~~~~~~~~~~~~~
$ mkdir builds
$ cd builds
$ cmake -DCMAKE_BUILD_TYPE:STRING=Release -DPulse_DOWNLOAD_BASELINES:BOOL=ON ../engine
$ make -j4
~~~~~~~~~~~~~~~~~~~

## Quick Start
The ecmoDriver application is the main program that was built to serve real-time simulation and writing data to DynamoDB via the AWS API Gateway. 

Starting the human physiology simulation:
~~~~~~~~~~~~~~~~~~~
$ cd builds/install/bin
$ ./ecmoDriver
~~~~~~~~~~~~~~~~~~~

Source codes for ECMOSTP is in the directory: /engine/src/cpp/ecmo
- Controller contains the main function that initialises the program
- HowTo-RunThreaded class here does the main threading for real-time simulation and initialising pulse engine and pump

## Pulse Executables
After running the cmake builds, there will be a few executables in the builds/install/bin directory.
- Executables prepared by Pulse Kitware, can be used but not our main focus: HowToDriver, HydrocephalusDriver, MultiplexVentilationDriver, PulseScenarioDriver, PulseTestDriver, SensitivityAnalysisDriver
    - To change the examples to run in the HowToDriver Executable, uncomment the functions that are required in the EngineHowTo.cpp file main function. Clean build, and re-run the make commands.
- ecmoDriver (The program that we use to do the ECMO simulations)
    - This is built based on the files in /engine/src/cpp/howto directory

## Documentations
### Navigating the src folder
File hierarchy for the main folders we will be looking at when integrating the ECMO system into Pulse Engine
- engine/src/cpp
    - /cdm
    - /cpm
    - /ecmo

/cdm - Common Data Model
- Contains the building blocks of Pulse Engine
- /properties: unit and conversion files
- PhysiologyEngine.h: Header file for the physiology engine interface

### Pulse Engine Documentations
CDM structures used for ECMO
- cardiovascular: https://pulse.kitware.com/_c_d_m_tables.html#CardiovascularSystemTable
- blood chemistry: https://pulse.kitware.com/_c_d_m_tables.html#BloodChemistrySystemTable
- respiratory: https://pulse.kitware.com/_c_d_m_tables.html#RespiratorySystemTable
- tissue: https://pulse.kitware.com/_c_d_m_tables.html#TissueSystemTable
- complete blood count table: https://pulse.kitware.com/_c_d_m_tables.html#CompleteBloodCountTable


Refer to https://docs.google.com/document/d/1qY3ytWQOqq3ZufJ0RGzmwjml-S8Q3D3kn2p5Pxe9I8w/edit?usp=sharing for more details



## License
The Kitware Pulse Engine is licensed under Apache License. 