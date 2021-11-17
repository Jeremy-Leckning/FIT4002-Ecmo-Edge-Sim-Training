import React from "react";
import { makeStyles } from "@material-ui/core/styles";
import AppBar from "@material-ui/core/AppBar";
import Toolbar from "@material-ui/core/Toolbar";
import Typography from "@material-ui/core/Typography";
import Avatar from "@material-ui/core/Avatar";
import HelpOutlineIcon from "@material-ui/icons/HelpOutline";
import logo from "../../shared/assets/logo_dojo.png";
import { green } from "@material-ui/core/colors";
import ArrowBackIcon from "@material-ui/icons/ArrowBack";
import { Link, useHistory } from "react-router-dom";

const useStyles = makeStyles((theme) => ({
  root: {
    flexGrow: 1,
  },
  menuButton: {
    marginRight: theme.spacing(2),
  },
  title: {
    flexGrow: 1,
  },

  green: {
    color: theme.palette.getContrastText(green[300]),
    backgroundColor: green[300],
  },
}));

export default function ButtonAppBar(props) {
  const classes = useStyles();
  let history = useHistory();
  return (
    <div className={classes.root}>
      <AppBar position="absolute">
        <Toolbar>
          <Link to="/Landing" style={{ textDecoration: "none" }}>
            <img style={{ height: 60, width: 60 }} src={logo} alt="Dojo logo" />
          </Link>

          <ArrowBackIcon
            style={{ height: 40, width: 80 }}
            onClick={() => history.goBack()}
          >
          </ArrowBackIcon>

          <Typography align="center" variant="h2" className={classes.title}>
            {props.title}
          </Typography>
          <HelpOutlineIcon style={{ fontSize: 40, paddingRight: "1%" }} />
          <Avatar className={classes.green} />
        </Toolbar>
      </AppBar>
    </div>
  );
}
