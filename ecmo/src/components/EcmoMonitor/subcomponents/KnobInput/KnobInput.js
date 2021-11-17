import React, { Component } from "react";
import { Knob } from "react-rotary-knob";
import * as skins from "react-rotary-knob-skin-pack";

class KnobInput extends Component {
  state = {
    value: 0,
  };

  changeValue(val) {
    this.setState({ value: val });
  }

  render() {
    return (
      <div>
        <center><h2>{this.state.value.toFixed(2)} rpm </h2></center>
        <Knob
          skin={skins.s5}
          style={{
            width: "105px",
            height: "105px",
            display: "inline-block",
          }}
          unlockDistance={0}
          onChange={(val) => {
            this.changeValue(val);
          }}
          min={0}
          max={4500}
          value={this.state.value}
        />
      </div>
    );
  }
}

export default KnobInput;
