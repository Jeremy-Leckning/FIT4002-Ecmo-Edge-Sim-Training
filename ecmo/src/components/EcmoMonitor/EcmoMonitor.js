import React, { Component } from "react";
import "./EcmoMonitor.scss";
import {
  KnobInput,
  ZeroButton,
  PowerButton,
  DisplayMonitor,
} from "./subcomponents";

class SimulationTime extends Component {
  render() {
    return (
        <div>
            <div class="row" id="monitorMain">
                <div class="column" id="monitorColumn">
                    <DisplayMonitor></DisplayMonitor>
                </div>
                <div class="column" id="buttonColumn">
                    <center>
                        <div id="monitorPower">
                            <PowerButton></PowerButton>
                        </div>
                        <ZeroButton></ZeroButton>
                        <KnobInput></KnobInput>
                    </center>
                </div>
            </div>
      </div>
    );
  }
}

export default SimulationTime;
