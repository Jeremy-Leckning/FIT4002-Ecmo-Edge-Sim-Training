import React, { Component } from "react";
import "./ActivityLog.scss";

class ActivityLog extends Component {
  render() {
    return (
      <div className="activityLog-container">
        Activity Log{" "}
        <div className="activity-container">
          {this.props.activity.map( log => (
            <li>{log}</li>
          ))}
        </div>
      </div>
    );
  }
}

export default ActivityLog;
