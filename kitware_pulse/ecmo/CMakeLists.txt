### Modify the list of files to include or exclude files used for the executable
add_executable_ex(ecmoDriver
    Controller.cpp
    Controller.h
    RealTimeSimulation.cpp
    RealTimeSimulation.h
)

find_package(CURL REQUIRED)

include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(ecmoDriver ${CURL_LIBRARIES})
target_link_libraries(ecmoDriver CommonPulseModels)