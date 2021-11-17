import React, { Component } from "react";
import "./SimulationTime.scss";
import Timer from "react-compound-timer";

class SimulationTime extends Component {
  render() {
    var today = new Date(),
      date =
        today.getDate() +
        "/" +
        (today.getMonth() + 1) +
        "/" +
        today.getFullYear();

    return (
      <div className="simulationTime-container">
        <div style={{ fontSize: 10 }}> In-simulation time </div>
        <div style={{ fontSize: 16, fontWeight: "bold" }}>
          <Timer initialTime={0} lastUnit="m">
            <Timer.Minutes /> mins <Timer.Seconds /> s
          </Timer>
        </div>

        <div style={{ fontSize: 14 }}> {date} </div>
      </div>
    );
  }
}

export default SimulationTime;
