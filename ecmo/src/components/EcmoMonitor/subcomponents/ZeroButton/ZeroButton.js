import React, { Component } from "react";
import Zero_button from "../../../../shared/assets/Zero_button.png";

class ZeroButton extends Component {
  render() {
    return (
      <div>
        <button>
          <img
            src={Zero_button}
            alt="zero_button"
            onClick={() => {
              console.log("clicked zero button");
            }}
          />
        </button>
      </div>
    );
  }
}

export default ZeroButton;
