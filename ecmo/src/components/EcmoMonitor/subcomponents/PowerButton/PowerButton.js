import React, { Component } from "react";
import Power_button from "../../../../shared/assets/Power_button.png";

class PowerButton extends Component {
  render() {
    return (
      <div>
        <button>
          <img
            src={Power_button}
            alt="power_button"
            onClick={() => {
              console.log("clicked power button");
            }}
          />
        </button>
      </div>
    );
  }
}

export default PowerButton;
