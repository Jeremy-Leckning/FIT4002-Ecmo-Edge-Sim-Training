import { React, Component } from "react";
import Popup from "reactjs-popup";
import Button from "@material-ui/core/Button";
import { makeStyles } from "@material-ui/core/styles";
import "./ScreenPopUp.scss";

const useStyles = makeStyles({
  root: {
    background: "rgba(32, 71, 130, 1)",
    borderRadius: 10,
    padding: 10,
    width: 110,
    boxShadow: "0 3px 6px rgba(0,0,0,0.16), 0 3px 6px rgba(0,0,0,0.23)",
  },
  label: {
    color: "white",
    fontSize: 20,
    textTransform: "capitalize",
    display: "flex",
    flexDirection: "column",
  },
});

const contentStyle = {
  background: "white",
  borderRadius: "1%",
  borderWidth: "5px",
  border: "10px solid rgba(32, 71, 130, 1)",
};

const overlayStyle = { background: "rgba(0,0,0,0.3)" };

class ScreenPopUp extends Component {
  constructor(props) {
    super(props);
    this.state = {
      show: true,
    };
    this.handleshow = this.handleshow.bind(this);
  }


  handleshow() {
    this.setState((prevState) => ({
      show: !prevState.show,
    }));
    console.log(this.state.show);
  }
  // { this.state.show ?  : null }  need to make button disappear on click
  render() {
    return (
      <Popup
        trigger={
          <Button
            onClick={this.handleshow}
            style={{ width: "120px", height: "50px" }}
            variant="contained"
          >
            {this.props.button}
          </Button>
        }
        {...{ contentStyle, overlayStyle }}
        modal
        nested
      >
        {/* <Popup trigger={<button> Hello </button>} modal nested> */}
        {(close) => (
          <div className="modal">
            {/* <button className="close" onClick={close}>
                  &times;
                </button> */}
            <div className="header"> {this.props.title} </div>
            <div className="content">{this.props.content}</div>
            <div className="actions">
              {/* <Popup
                trigger={<button className="button"> Trigger </button>}
                position="top center"
                nested
              >
                <span>
                  Lorem ipsum dolor sit amet, consectetur adipisicing elit. Beatae
                  magni omnis delectus nemo, maxime molestiae dolorem numquam
                  mollitia, voluptate ea, accusamus excepturi deleniti ratione
                  sapiente! Laudantium, aperiam doloribus. Odit, aut.
                </span>
              </Popup> */}
              <button
                className="button"
                onClick={() => {
                  close();
                }}
              >
                Close
              </button>
            </div>
          </div>
        )}
      </Popup>
    );
  }
}

export default ScreenPopUp;
