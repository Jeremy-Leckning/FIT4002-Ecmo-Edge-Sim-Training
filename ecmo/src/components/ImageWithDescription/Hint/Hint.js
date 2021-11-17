import React from "react";
import Button from "@material-ui/core/Button";
import { makeStyles } from "@material-ui/core/styles";
import Tooltip from "@material-ui/core/Tooltip";

const useStyles = makeStyles({
  root: {
    background: "rgba(255, 92, 0, 1)",
    borderRadius: 10,
    height: 28,
    width: 91,
    boxShadow: "0 3px 5px 2px rgba(255, 105, 135, .3)",
  },
  label: {
    color: "white",
    fontSize: 20,
    textTransform: "capitalize",
  },
});

export default function Hint(props) {
  const classes = useStyles();
  return (
    <Tooltip title={<h2> {props.hint}</h2>} arrow>
      <Button
        classes={{
          root: classes.root,
          label: classes.label,
        }}
      >
        Hint
      </Button>
    </Tooltip>
  );
}
