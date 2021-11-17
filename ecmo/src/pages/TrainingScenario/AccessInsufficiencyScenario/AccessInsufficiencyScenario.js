import React, { useState, useEffect } from "react";
import "./AccessInsufficiencyScenario.scss";
import {
  Header,
  Footer,
  EcmoMonitor,
  PatientVitals,
  Objective,
  PatientDetails,
  ActivityLog,
  // ScenarioButton,
  SimulationTime,
  Hint,
  UserActionButton,
  PopupScenario,
} from "../../../components";
import Circuit from "../../../shared/assets/Circuit.png";
// import { Waveform } from "../../../components";
import swal from "sweetalert";

const mockScenarioActionButtons = [
  {
    buttonValue: "Check flows",
    logOutput: "ECMO Flow: -3000 rpm",
    hint: "Check ECMO pre oxygenator pressure - these should be very negative and oscillatory",
    text: "Flow checked. The Ecmo flow value is -3000rpm",
    step: 0,
  },
  {
    buttonValue: "Check ECMO pre oxygenator pressure",
    logOutput: "Pre-oxygenator pressure: <Something very negative>",
    hint: "Check plasma free haemoglobin - will come back as slightly elevated.",
    text: "ECMO pre oxygenator pressure checked. The pre-oxygenator value is abnormally negative",
    step: 1,
  },
  {
    buttonValue: "Check plasma free haemoglobin",
    logOutput: "Plasma Free haemoglobin: <Slightly elevated value>",
    hint: "Check cannula positioning",
    text: "Plasma free haemoglobin checked. Value seems slightly elevated. At this point you should suspect Access Insufficiency",
    step: 2,
  },
  {
    buttonValue: "Check cannula positioning",
    logOutput: "Cannula positioning is good",
    hint: "Finish scenario",
    text: "Access Insufficiency suspected",
    step: 3,
  },
];

const index = 0;

export default function AccessInsufficiencyScenario() {
  useEffect(() => {
    swal({
      title: "Stage 1",
      text: "Something's wrong with the patient. Perform initial circuit checks",
    });
  }, []);

  const [actionButtons, setActionButtons] = useState(mockScenarioActionButtons);
  const [activityLog, setActivityLog] = useState([
    new Date().getHours() +
      ":" +
      new Date().getMinutes() +
      ":" +
      new Date().getSeconds() +
      " Scenario Commenced",
  ]);
  const [hint, setHint] = useState(
    "Check ecmo flow - these should be low, and oscillatory"
  );
  const [index, setIndex] = useState(0);

  const handleActionButtonClick = (buttonValue) => {
    const activityLogCopy = [...activityLog];
    const getLogOutput = actionButtons.find(
      (button) => button.buttonValue === buttonValue
    );

    if (index !== getLogOutput.step) {
      swal({
        text: "Not the correct step. Check the hint section if you are unsure.",
        icon: "error",
      });
    } else {
      if (activityLog.indexOf(getLogOutput.logOutput) !== -1) {
        // value exists in the log already
      } else {
        // ------- ADD TIME IN ACTIVITY LOG --------------
        // var time = new Date().getHours() + ':' + new Date().getMinutes() + ':' + new Date().getSeconds() + " ";
        // var output = time + getLogOutput.logOutput;
        activityLogCopy.push(getLogOutput.logOutput);
        setActivityLog(activityLogCopy);
        setHint(getLogOutput.hint);
        setIndex(index + 1);

        swal({
          text: getLogOutput.text,
          icon: "success",
        });
      }
    }
  };

  return (
    <div>
      <Header title="Scenario 1" />
      <div class="row" id="main">
        {/* Left Main Column */}
        <div class="column left">
          <div class="row" id="circuitContainer">
            <img
              id="circuitImage"
              src={Circuit}
              alt="Circuit"
              onClick={() => {
                console.log("Circuit");
              }}
            />
          </div>

          <div class="row" id="monitorContainer">
            <EcmoMonitor></EcmoMonitor>
          </div>
        </div>
        {/* Middle Main Column*/}
        <div class="column middle">
          <div id="vitals">
            <PatientVitals></PatientVitals>
          </div>
        </div>
        {/* Right Main Column */}
        <div class="column right">
          <div class="row">
            <div class="container">
              <div class="row" id="objective">
                <Objective title="Circuit check"></Objective>
              </div>
              <div class="row">
                <div class="column">
                  <div class="row">
                    <div class="container">
                      <div class="column">
                        <div class="row">
                          <div class="column" id="details">
                            <PatientDetails
                              sex="M"
                              weight="84kg"
                              medicalHistory="None"
                              allergies="None"
                              medications="None"
                              notes="-"
                              age="26"
                              height="182cm"
                            ></PatientDetails>
                          </div>
                          <div class="column" id="additionalInfo">
                            <div class="row" id="scenario">
                              <PopupScenario></PopupScenario>
                            </div>
                            <div class="row" id="time">
                              <SimulationTime></SimulationTime>
                            </div>
                          </div>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
          <div class="row" id="activity">
            <ActivityLog activity={activityLog}></ActivityLog>
          </div>
          <div class="row">
            <div class="container">
              <div class="column" id="interaction">
                <div class="row" id="hint">
                  <Hint hint={hint}></Hint>
                </div>
                {actionButtons.map((actionBtn, idx) => (
                  <div class="row" id="actionbtn" key={idx}>
                    <UserActionButton
                      title={actionBtn.buttonValue}
                      onClick={() =>
                        handleActionButtonClick(actionBtn.buttonValue)
                      }
                    ></UserActionButton>
                  </div>
                ))}
              </div>
            </div>
          </div>
        </div>
      </div>

      <Footer />
    </div>
  );
}
