import React, { Component } from "react";
import "./Login.scss";
import {LoginContainer, WelcomeBox} from "./subcomponents";

class Login extends Component {
  onSubmit = (e) => {
    console.log(e)
  };

  render() {
    return (
      <div className="login-page">
        <div className="login-page__wrapper-container">
          <WelcomeBox headerLabel="DOJO" primaryLabel="Welcome to ECMO Training" secondaryLabel="Login and Start Dojo" />
          <LoginContainer />
        </div>

        {/* <form className="login__form" onSubmit={this.onSubmit}>
          hello
        </form> */}
      </div>
    );
  }
}

export default Login;
