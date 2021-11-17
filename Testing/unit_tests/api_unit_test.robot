*** Settings ***
Library               RequestsLibrary
Library               Collections
Library               String

*** Variables ***
${API_GATEWAY}         https://0mvd56hduf.execute-api.ap-southeast-2.amazonaws.com

*** Test Cases ***
Textbook Chapters Put Request 
    ${body}=    Create Dictionary   chapter_title=introduction    object_type=chapter   chapter_number=1    id=01
    ${response}=    PUT    ${API_GATEWAY}/textbook/chapters   json=${body}
    Status Should Be                 200
   

Textbook Chapters Get Request 
    ${response}=    GET  ${API_GATEWAY}/textbook/chapters
    Status Should Be                 200

Textbook Chapters Get Request with Chapter ID
    ${body}=    Create Dictionary   chapter_title=introduction    object_type=chapter   chapter_number=1    id=01
    ${get_response}=    GET    ${API_GATEWAY}/textbook/chapters/01
    Status Should Be                 200
    Should Be Equal As Strings    ${get_response.json()}[Item]    ${body}

Textbook Chapters Delete Request 
    ${response}=    DELETE  ${API_GATEWAY}/textbook/chapters/01
    Status Should Be                 200
    ${get_response}=    GET    ${API_GATEWAY}/textbook/chapters/01
    Should Be Equal As Strings    ${get_response.json()}    {}


Textbook Pages Get Request 
    ${response}=    GET   ${API_GATEWAY}/textbook/pages
    Status Should Be                 200

Textbook Pages Get Request with Page ID
    ${response}=    GET    ${API_GATEWAY}/textbook/pages/01
    Status Should Be                  200

Textbook Pages Put Request
    ${body}=    Create Dictionary   object_type=page    id=02 
    ${response}=    PUT    ${API_GATEWAY}/textbook/pages  json=${body}
    Status Should Be                  200   ${response}
    ${get_response}=    GET    ${API_GATEWAY}/textbook/pages/02
    Should Be Equal As Strings    ${get_response.json()}[Item]    ${body}

Textbook Pages Delete Request 
    ${response}=    DELETE    ${API_GATEWAY}/textbook/pages/02
    Status Should Be                  200
    ${get_response}=    GET    ${API_GATEWAY}/textbook/pages/02  
    Should Be Equal As Strings    ${get_response.json()}    {}                 

Scenario PUT Request 
    ${body}=    Create Dictionary   id=00 
    ${response}=    GET    ${API_GATEWAY}/scenario/00   json=${body}
    Status Should Be                 200

Scenario Get Request
    ${response}=    GET    ${API_GATEWAY}/scenario
    Status Should Be                 200

Scenario Get Request with Scenario ID
    ${response}=    GET    ${API_GATEWAY}/scenario/00
    Status Should Be                 200

Scenario Delete Request
    ${response}=    GET    ${API_GATEWAY}/scenario/00
    Status Should Be                 200
