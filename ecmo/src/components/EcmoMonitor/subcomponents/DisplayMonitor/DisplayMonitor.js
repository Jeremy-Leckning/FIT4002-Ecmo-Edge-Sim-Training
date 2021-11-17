import React, { Component } from "react";
import "./DisplayMonitor.scss";
// import KnobInput from "../KnobInput";

class DisplayMonitor extends Component {
  state = {
    value: 0,
  };

  changeValue(val) {
    this.setState({ value: val });
  }

  render() {
    return (
      <div className="monitor-container">
        <div>
          <div className="vertical-separator"></div>
          <div className="horizontal-separator"></div>
          <div className="horizontal-separator2"></div>

          <div className="top-left">
            <h4> ECMO FLOW </h4>
            <h5>l/min</h5>
            <h2>4.5</h2>
          </div>
          <div className="top-right">
            <h4> ECMO PUMP </h4>
            <h5>rpm</h5>
            <h2>0</h2>
          </div>
          <div className="bottom-right">
            <h4>
              S<sub>v</sub>O<sub>2</sub>
            </h4>
            <h5>%</h5>
            <h2>68.0</h2>
          </div>
          <div className="middle-left">
            <h4>
              P<sub>ven</sub>
            </h4>
            <h5>mmHg</h5>
            <h3>151</h3>
          </div>
          <div className="bottom-left">
            <h4>
              P<sub>art</sub>
            </h4>
            <h5>mmHg</h5>
            <h3>220</h3>
          </div>
        </div>
      </div>
    );
  }
}

export default DisplayMonitor;
