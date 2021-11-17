import React from "react";
import Button from "@material-ui/core/Button";
import { makeStyles } from "@material-ui/core/styles";
import MenuBookIcon from "@material-ui/icons/MenuBook";

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

export default function ScenarioButton() {
  const classes = useStyles();
  return (
    <Button
      classes={{
        root: classes.root,
        label: classes.label,
      }}
    >
      Scenario
      <MenuBookIcon style={{ width: 40, height: 36 }}></MenuBookIcon>
    </Button>
  );
}
