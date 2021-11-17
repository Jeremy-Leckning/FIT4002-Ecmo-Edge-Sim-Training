import { React } from "react";
import Popup from "reactjs-popup";
import Button from "@material-ui/core/Button";
import { makeStyles } from "@material-ui/core/styles";
import MenuBookIcon from "@material-ui/icons/MenuBook";
import "./PopupScenario.scss";

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

function PopupScenario() {
  const classes = useStyles();
  return (
    <Popup
      trigger={
        <Button
          classes={{
            root: classes.root,
            label: classes.label,
          }}
        >
          Scenario
          <MenuBookIcon style={{ width: 40, height: 36 }}></MenuBookIcon>
        </Button>
      }
      {...{ contentStyle, overlayStyle }}
      modal
      nested
    >
      {(close) => (
        <div className="modal">
          <div className="header"> “Kicking” of the ECMO lines. </div>
          <div className="content">
            Kicking is visible and palpable shaking of the circuit tubing
            draining to the pump. It indicates access insufficiency (not an
            earthquake).
            <br /> <br />
            Access insufficiency occurs when the suction pressure at the access
            cannula can draw in blood flow greater than venous return. <br />
            When this occurs inflow is interrupted due to partial or complete
            occlusion of the inlet ports of the access cannula by the walls of
            the collapsible vein. <br /> After a few seconds, ongoing venous
            return fills up the vein again and the cannula ports reopen to
            function once more. <br />
            This cycle repeats itself resulting in unstable, fluctuating ECMO
            flows (shown in L/min on the ECMO console) despite a stable pump
            speed (rpm).
          </div>
          <div className="actions">
            <button
              className="button"
              onClick={() => {
                console.log("modal closed");
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

export default PopupScenario;
