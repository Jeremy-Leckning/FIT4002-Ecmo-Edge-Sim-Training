import React from "react";
import Button from "@material-ui/core/Button";
import { makeStyles } from "@material-ui/core/styles";

const useStyles = makeStyles({
  root: {
    background: "rgba(32, 71, 130, 1)",
    borderRadius: 5,
    height:    65,
    width: 300,
    boxShadow: "0 3px 5px 2px rgba(255, 105, 135, .3)",
  },
  label: {
    color: "white",
    fontSize: 15,
    textTransform: "capitalize",
    display: "flex",
    flexDirection: "column",
  },
});

export default function UserActionButton({title, onClick}) {
  const classes = useStyles();
  return (
    <Button
      classes={{
        root: classes.root,
        label: classes.label,
      }}
      onClick={onClick}
    >
      {title}
    </Button>
  );
}
