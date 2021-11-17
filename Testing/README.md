## Installation

If you already have Python with pip installed, you can simply run:

```sh
pip install robotframework
```

## Dependencies

This project is tested with Selenium Library and Requests Library. Simply run:

```sh
pip install selenium robotframework-selenium2library webdrivermanager
pip install robotframework-requests
```

Chrome driver is needed for selenium web driver. Download chromedriver and include it in you ENV PATH. Ensure to choose the right version of chromedriver for your chrome.
https://sites.google.com/chromium.org/driver/getting-started

## Example

Below is a simple example test case for testing login to some system. You can find more examples with links to related demo projects from http://robotframework.org.

```sh
*** Settings ***
Documentation A test suite with a single test for valid login.
...
... This test has a workflow that is created using keywords in
... the imported resource file.
Resource resource.robot

*** Test Cases ***
Valid Login
Open Browser To Login Page
Input Username demo
Input Password mode
Submit Credentials
Welcome Page Should Be Open
[Teardown] Close Browser
```

## Usage

Run the command below to execute the test cases for this project:

```sh
cd Testing
npm install
robot unit_tests
```

## Documentation

[Robot Framework User Guide](http://robotframework.org/robotframework/#user-guide)  
[Standard libraries](http://robotframework.org/robotframework/#standard-libraries)  
[Built-in tools](http://robotframework.org/robotframework/#built-in-tools)  
[Test Plan](http://robotframework.org/robotframework/#built-in-tools)  

## License

Robot Framework is open source software provided under the Apache License 2.0. Robot Framework documentation and other similar content use the Creative Commons Attribution 3.0 Unported license. Most libraries and tools in the ecosystem are also open source, but they may use different licenses.
