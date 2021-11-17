import React, { Component } from "react";
import "./PatientDetails.scss";

class PatientDetails extends Component {
  render() {
    return (
      <div className="patient-container">
        Patient Details
        <div className="details-container">
          Sex: {this.props.sex}
          <br></br>
          Weight: {this.props.weight}
          <br></br>
          Age: {this.props.age}
          <br></br>
          Height: {this.props.height}
          <br></br>
          Medical History: {this.props.medicalHistory}
          <br></br>
          Allergies: {this.props.allergies}
          <br></br>
          Medications: {this.props.medications}
          <br></br>
          Other Notes: {this.props.notes}
          <br></br>
        </div>
      </div>
    );
  }
}

export default PatientDetails;
