
add_library_ex(CommonDataModelTests
  H_FILES
    CommonDataModelTest.h
  CPP_FILES
    AdvancedCircuitTest.cpp
    BasicCircuitTest.cpp
    BlackBoxTest.cpp
    CommonDataModelTest.cpp
    GasCompartmentTest.cpp
    LiquidCompartmentTest.cpp
    ReadPatientDirectory.cpp
    ReadSubstanceDirectory.cpp
    ScalarTest.cpp
    SubstanceTransport.cpp
    ThermalCompartmentTest.cpp
    TissueCompartmentTest.cpp
    UnitsTest.cpp
  PUBLIC_DEPENDS
    CommonDataModel
  INSTALL_HEADER_DIR
    test/
)