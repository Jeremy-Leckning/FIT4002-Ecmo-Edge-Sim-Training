*** Settings ***
Documentation       A resource file with reusable keywords and variables.
...
...                 The system specific keywords created here form our own
...                 domain specific language. They utilize keywords provided
...                 by the imported SeleniumLibrary.
Library             SeleniumLibrary
Library             ReactLibrary

*** Variables ***
${SERVER}         localhost:3000
${DELAY}          0
${APP_URL}        http://${SERVER}/
${LANDING_URL}    http://${SERVER}/Landing
${TEXTBOOK_URL}   http://${SERVER}/textbook/chapter-select
${TRAINING_URL}   http://${SERVER}/training/scenario-select
${MODEL_URL}      http://${SERVER}/freeplay

*** Keywords ***
Open Browser To Textbook Page
    ${chrome_options}=  Evaluate  sys.modules['selenium.webdriver'].ChromeOptions()  sys, selenium.webdriver
    Call Method    ${chrome_options}    add_argument    test-type
    Call Method    ${chrome_options}    add_argument    --disable-extensions
    Call Method    ${chrome_options}    add_argument    --headless
    Call Method    ${chrome_options}    add_argument    --disable-gpu
    Call Method    ${chrome_options}    add_argument    --no-sandbox
    ${EXCLUDES}    Create list     enable-logging  
    Call Method    ${chrome_options}    add_experimental_option    excludeSwitches  ${EXCLUDES}

    Create Webdriver    Chrome    chrome_options=${chrome_options}
    Open Browser            ${TEXTBOOK_URL}    Chrome    options=${chrome_options}
    Maximize Browser Window
    Set Selenium Speed      ${DELAY}
    Textbook Page Should Be Open

Open Browser To Training Page
    ${chrome_options}=  Evaluate  sys.modules['selenium.webdriver'].ChromeOptions()  sys, selenium.webdriver
    Call Method    ${chrome_options}    add_argument    test-type
    Call Method    ${chrome_options}    add_argument    --disable-extensions
    Call Method    ${chrome_options}    add_argument    --headless
    Call Method    ${chrome_options}    add_argument    --disable-gpu
    Call Method    ${chrome_options}    add_argument    --no-sandbox
    ${EXCLUDES}    Create list     enable-logging  
    Call Method    ${chrome_options}    add_experimental_option    excludeSwitches  ${EXCLUDES}

    Create Webdriver    Chrome    chrome_options=${chrome_options}
    Open Browser            ${TRAINING_URL}    Chrome    options=${chrome_options}
    Maximize Browser Window
    Set Selenium Speed      ${DELAY}
    Training Page Should Be Open

Open Browser To Model Page
    ${chrome_options}=  Evaluate  sys.modules['selenium.webdriver'].ChromeOptions()  sys, selenium.webdriver
    Call Method    ${chrome_options}    add_argument    test-type
    Call Method    ${chrome_options}    add_argument    --disable-extensions
    Call Method    ${chrome_options}    add_argument    --headless
    Call Method    ${chrome_options}    add_argument    --disable-gpu
    Call Method    ${chrome_options}    add_argument    --no-sandbox
    ${EXCLUDES}    Create list     enable-logging  
    Call Method    ${chrome_options}    add_experimental_option    excludeSwitches  ${EXCLUDES}

    Create Webdriver    Chrome    chrome_options=${chrome_options}
    Open Browser            ${MODEL_URL}    Chrome    options=${chrome_options}
    Maximize Browser Window
    Set Selenium Speed      ${DELAY}
    Model Page Should Be Open
    
Open Browser To App Page
    ${chrome_options}=  Evaluate  sys.modules['selenium.webdriver'].ChromeOptions()  sys, selenium.webdriver
    Call Method    ${chrome_options}    add_argument    test-type
    Call Method    ${chrome_options}    add_argument    --disable-extensions
    Call Method    ${chrome_options}    add_argument    --headless
    Call Method    ${chrome_options}    add_argument    --disable-gpu
    Call Method    ${chrome_options}    add_argument    --no-sandbox
    ${EXCLUDES}    Create list     enable-logging  
    Call Method    ${chrome_options}    add_experimental_option    excludeSwitches  ${EXCLUDES}

    Create Webdriver    Chrome    chrome_options=${chrome_options}
    Open Browser            ${APP_URL}    Chrome    options=${chrome_options}
    Maximize Browser Window
    Set Selenium Speed      ${DELAY}
    App Page Should Be Open

Open Browser To Landing Page
    ${chrome_options}=  Evaluate  sys.modules['selenium.webdriver'].ChromeOptions()  sys, selenium.webdriver
    Call Method    ${chrome_options}    add_argument    test-type
    Call Method    ${chrome_options}    add_argument    --disable-extensions
    Call Method    ${chrome_options}    add_argument    --headless
    Call Method    ${chrome_options}    add_argument    --disable-gpu
    Call Method    ${chrome_options}    add_argument    --no-sandbox
    ${EXCLUDES}    Create list     enable-logging  
    Call Method    ${chrome_options}    add_experimental_option    excludeSwitches  ${EXCLUDES}

    Create Webdriver    Chrome    chrome_options=${chrome_options}
    Open Browser            ${LANDING_URL}    Chrome    options=${chrome_options}
    Maximize Browser Window
    Set Selenium Speed      ${DELAY}
    Landing Page Should Be Open





Open Browser To airbnb
    ${chrome_options}=  Evaluate  sys.modules['selenium.webdriver'].ChromeOptions()  sys, selenium.webdriver
    Call Method    ${chrome_options}    add_argument    test-type
    Call Method    ${chrome_options}    add_argument    --disable-extensions
    Call Method    ${chrome_options}    add_argument    --headless
    Call Method    ${chrome_options}    add_argument    --disable-gpu
    Call Method    ${chrome_options}    add_argument    --no-sandbox
    ${EXCLUDES}    Create list     enable-logging  
    Call Method    ${chrome_options}    add_experimental_option    excludeSwitches  ${EXCLUDES}

    Create Webdriver    Chrome    chrome_options=${chrome_options}
    Open Browser            https://airbnb.com    Chrome    options=${chrome_options}
    Maximize Browser Window
    Set Selenium Speed      ${DELAY}
    

App Page Should Be Open
    Title Should Be         ECMO

Landing Page Should Be Open
    Title Should Be         ECMO

Textbook Page Should Be Open
    Title Should Be         ECMO

Training Page Should Be Open
    Title Should Be         ECMO

Model Page Should Be Open
    Title Should Be         ECMO


Go To App Page
    ${chrome_options}=  Evaluate  sys.modules['selenium.webdriver'].ChromeOptions()  sys, selenium.webdriver
    Call Method    ${chrome_options}    add_argument    test-type
    Call Method    ${chrome_options}    add_argument    --disable-extensions
    Call Method    ${chrome_options}    add_argument    --headless
    Call Method    ${chrome_options}    add_argument    --disable-gpu
    Call Method    ${chrome_options}    add_argument    --no-sandbox
    ${EXCLUDES}    Create list     enable-logging  
    Call Method    ${chrome_options}    add_experimental_option    excludeSwitches  ${EXCLUDES}

    Create Webdriver    Chrome    chrome_options=${chrome_options}
    Go To    ${APP_URL}
    Wait for react
    App Page Should Be Open

Go To Landing Page
    ${chrome_options}=  Evaluate  sys.modules['selenium.webdriver'].ChromeOptions()  sys, selenium.webdriver
    Call Method    ${chrome_options}    add_argument    test-type
    Call Method    ${chrome_options}    add_argument    --disable-extensions
    Call Method    ${chrome_options}    add_argument    --headless
    Call Method    ${chrome_options}    add_argument    --disable-gpu
    Call Method    ${chrome_options}    add_argument    --no-sandbox
    ${EXCLUDES}    Create list     enable-logging  
    Call Method    ${chrome_options}    add_experimental_option    excludeSwitches  ${EXCLUDES}

    Create Webdriver    Chrome    chrome_options=${chrome_options}
    Go To    ${LANDING_URL}
    #Wait for react
    Page Should Contain Button    Textbook
    Page Should Contain Button    Training
    Page Should Contain Button    Model

Go To Model Page
    ${chrome_options}=  Evaluate  sys.modules['selenium.webdriver'].ChromeOptions()  sys, selenium.webdriver
    Call Method    ${chrome_options}    add_argument    test-type
    Call Method    ${chrome_options}    add_argument    --disable-extensions
    Call Method    ${chrome_options}    add_argument    --headless
    Call Method    ${chrome_options}    add_argument    --disable-gpu
    Call Method    ${chrome_options}    add_argument    --no-sandbox
    ${EXCLUDES}    Create list     enable-logging  
    Call Method    ${chrome_options}    add_experimental_option    excludeSwitches  ${EXCLUDES}

    Create Webdriver    Chrome    chrome_options=${chrome_options}
    Go To    ${MODEL_URL}
    Wait for react
    App Page Should Be Open

Go To Training Page
    ${chrome_options}=  Evaluate  sys.modules['selenium.webdriver'].ChromeOptions()  sys, selenium.webdriver
    Call Method    ${chrome_options}    add_argument    test-type
    Call Method    ${chrome_options}    add_argument    --disable-extensions
    Call Method    ${chrome_options}    add_argument    --headless
    Call Method    ${chrome_options}    add_argument    --disable-gpu
    Call Method    ${chrome_options}    add_argument    --no-sandbox
    ${EXCLUDES}    Create list     enable-logging  
    Call Method    ${chrome_options}    add_experimental_option    excludeSwitches  ${EXCLUDES}

    Create Webdriver    Chrome    chrome_options=${chrome_options}
    Go To    ${TRAINING_URL}
    Wait for react
    Landing Page Should Be Open

Go To Textbook Page
    ${chrome_options}=  Evaluate  sys.modules['selenium.webdriver'].ChromeOptions()  sys, selenium.webdriver
    Call Method    ${chrome_options}    add_argument    test-type
    Call Method    ${chrome_options}    add_argument    --disable-extensions
    Call Method    ${chrome_options}    add_argument    --headless
    Call Method    ${chrome_options}    add_argument    --disable-gpu
    Call Method    ${chrome_options}    add_argument    --no-sandbox
    ${EXCLUDES}    Create list     enable-logging  
    Call Method    ${chrome_options}    add_experimental_option    excludeSwitches  ${EXCLUDES}

    Create Webdriver    Chrome    chrome_options=${chrome_options}
    Go To    ${TEXTBOOK_URL}
    Wait for react
    Landing Page Should Be Open

Open Browser To Google
    ${chrome_options}=  Evaluate  sys.modules['selenium.webdriver'].ChromeOptions()  sys, selenium.webdriver
    Call Method    ${chrome_options}    add_argument    test-type
    Call Method    ${chrome_options}    add_argument    --disable-extensions
    Call Method    ${chrome_options}    add_argument    --headless
    Call Method    ${chrome_options}    add_argument    --disable-gpu
    Call Method    ${chrome_options}    add_argument    --no-sandbox
    ${EXCLUDES}    Create list     enable-logging  
    Call Method    ${chrome_options}    add_experimental_option    excludeSwitches  ${EXCLUDES}
    
    Create Webdriver    Chrome    chrome_options=${chrome_options}
    Open Browser            http://google.co.th    Chrome    options=${chrome_options}
    Maximize Browser Window
    Set Selenium Speed      ${DELAY}