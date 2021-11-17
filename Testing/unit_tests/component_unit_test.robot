*** Settings ***
Documentation     A test suite containing tests related to web application functionality.
...
...               These tests are data-driven by their nature. They use a single
...               keyword, specified with Test Template setting, that is called
...               with different arguments to cover different scenarios.
Suite Setup       Open Browser To App Page
Suite Teardown    Close Browser
# Test Setup        Go To App Page
Resource          component_resource.robot

*** Test Cases ***

TEXTBOOK Button in landing page
    Open Browser To App Page
    App Page Should Be Open
    Go To Landing Page
    Click Button   Textbook
    Page Should Contain   Chapters
    Location Should Be     ${TEXTBOOK_URL}
    Click Button   Next
    Page Should Contain   Scenario
    Click Button   Begin
    Page Should Contain   Scenario Explanation
    [Teardown]    Close Browser

TRAINING Button in landing page
    Open Browser To App Page
    App Page Should Be Open
    Go To Landing Page
    Click Button   Training
    Page Should Contain   Scenario
    Location Should Be    ${TRAINING_URL}
    Click Button    Next
    Location Should Be    http://${SERVER}/training/scenario-description
    Click Button    Begin
    Page Should Contain   Scenario Explanation
    Location Should Be    http://${SERVER}/training/scenario-explanation
    #Click Button    Continue
    #Page Should Contain   Stage 1
    #Click Button    OK
    #Page Should Contain   Scenario 1
    #Click Button    Check Flows
    #Click Button    OK
    [Teardown]    Close Browser

MODEL Button in landing page
    Open Browser To App Page
    App Page Should Be Open
    Go To Landing Page
    Click Button   Model
    Page Should Contain   ECMO Unity Freeplay
    [Teardown]    Close Browser

Valid Login
    Open Browser To App Page
    #Input Username    demo
    #Input Password    mode
    #Submit Credentials
    Click Button   Submit
    Landing Page Should Be Open
    [Teardown]    Close Browser
   
Front-End End-to-End Testing
    Open Browser To App Page
    App Page Should Be Open
    Open Browser To Landing Page
    Landing Page Should Be Open
    Open Browser To Textbook Page
    Textbook Page Should Be Open
    Open Browser To Training Page
    Training Page Should Be Open
    Open Browser To Model Page
    Model Page Should Be Open
    [Teardown]    Close Browser