import React, { Component } from "react";
import "./PatientVitals.scss";
import { Waveform } from "../../components";


class PatientVitals extends Component {
  render() {
    return (
      <div className="vitals-container">
        <div>
          <h4>HR </h4>
          <h5>bpm</h5>
          <h3 style={{ color: "rgba(16, 199, 0, 1)" }}>90</h3>
        </div>
        <div>
          <h4>ABP</h4>
          <h5>mmHg</h5>
          <h3 style={{ color: "rgba(255, 0, 0, 1)" }}>95/55</h3>
        </div>
        <div>
          <h4>
            S<sub>P</sub>0<sub>2</sub>
          </h4>
          <h5>%</h5>
          <h3 style={{ color: "rgba(181, 185, 0, 1)" }}>83</h3>
        </div>
        <div>
          <h4>Temp</h4>
          <h5>°C</h5>
          <h3 style={{ color: "rgba(255, 255, 255, 1)" }}>36.5</h3>
          </div>
         <div id="waveform">
             <Waveform id="chart"> </Waveform>
          </div>
      </div>
    );
  }
}

export default PatientVitals;
