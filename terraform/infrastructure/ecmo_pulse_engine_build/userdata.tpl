#!/bin/bash

echo "$(date)   [INFO]  starting userdata script execution" &> /var/log/ecmo_pulse_engine_build_userdata.log

echo "$(date)   [INFO]  (executing) add-apt-repository -y ppa:ubuntu-toolchain-r/test" &> /var/log/ecmo_pulse_engine_build_userdata.log
echo "$(date)   [INFO]  $(sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test)" &> /var/log/ecmo_pulse_engine_build_userdata.log
echo "$(date)   [INFO]  (executing) apt-get update" &> /var/log/ecmo_pulse_engine_build_userdata.log
echo "$(date)   [INFO]  $(sudo apt-get update)" &> /var/log/ecmo_pulse_engine_build_userdata.log

echo "$(date)   [INFO]  (executing) apt-get -y install gcc" &> /var/log/ecmo_pulse_engine_build_userdata.log
echo "$(date)   [INFO]  $(sudo apt-get -y install gcc)" &> /var/log/ecmo_pulse_engine_build_userdata.log
echo "$(date)   [INFO]  (executing) apt-get -y install g++" &> /var/log/ecmo_pulse_engine_build_userdata.log
echo "$(date)   [INFO]  $(sudo apt-get -y install g++)" &> /var/log/ecmo_pulse_engine_build_userdata.log
echo "$(date)   [INFO]  (executing) apt-get -y install zlib1g-dev" &> /var/log/ecmo_pulse_engine_build_userdata.log
echo "$(date)   [INFO]  $(sudo apt-get -y install zlib1g-dev)" &> /var/log/ecmo_pulse_engine_build_userdata.log
echo "$(date)   [INFO]  (executing) apt-get -y install libcurl4-openssl-dev" &> /var/log/ecmo_pulse_engine_build_userdata.log
echo "$(date)   [INFO]  $(sudo apt-get -y install libcurl4-openssl-dev)" &> /var/log/ecmo_pulse_engine_build_userdata.log
echo "$(date)   [INFO]  (executing) apt-get -y install libqt4-dev qt4-dev-tools libncurses5-dev" &> /var/log/ecmo_pulse_engine_build_userdata.log
echo "$(date)   [INFO]  $(sudo apt-get -y install libqt4-dev qt4-dev-tools libncurses5-dev)" &> /var/log/ecmo_pulse_engine_build_userdata.log
echo "$(date)   [INFO]  (executing) apt-get -y install cmake" &> /var/log/ecmo_pulse_engine_build_userdata.log
echo "$(date)   [INFO]  $(sudo apt-get -y install cmake)" &> /var/log/ecmo_pulse_engine_build_userdata.log
echo "$(date)   [INFO]  (executing) apt-get -y install openjdk-8-jdk" &> /var/log/ecmo_pulse_engine_build_userdata.log
echo "$(date)   [INFO]  $(sudo apt-get -y install openjdk-8-jdk)" &> /var/log/ecmo_pulse_engine_build_userdata.log

echo "$(date)   [INFO]  (executing) export JAVA_HOME='/usr/lib/jvm/java-8-openjdk-amd64'" &> /var/log/ecmo_pulse_engine_build_userdata.log
echo "$(date)   [INFO]  $(export JAVA_HOME='/usr/lib/jvm/java-8-openjdk-amd64')" &> /var/log/ecmo_pulse_engine_build_userdata.log

echo "$(pwd)"&> /var/log/ecmo_pulse_engine_build_userdata.log

mkdir pulse
cd pulse
wget https://gitlab.kitware.com/physiology/engine/-/archive/master/engine-master.tar.gz
tar -zxvf engine-master.tar.gz
cp -a engine-master/. engine
rm -r engine-master engine-master.tar.gz
mkdir builds
cd builds
cmake -DCMAKE_BUILD_TYPE:STRING=Release ../engine
cmake -DCMAKE_BUILD_TYPE:STRING=Release -DPulse_DOWNLOAD_BASELINES:BOOL=ON ../engine
make -j4
cd pulse
cd install/bin
./PulseScenarioDriver VitalsMonitor.json
