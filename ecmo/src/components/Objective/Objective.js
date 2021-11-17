import React, { Component } from "react";
import "./Objective.scss";

class Objective extends Component {
  render() {
    return (
      <div className="objective-container">
        Objective
        <div className="objective-details-container">{this.props.title}</div>
      </div>
    );
  }
}

export default Objective;
