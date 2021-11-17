import React from "react";
// import PropTypes from "prop-types";
import "./LoginContainer.scss";
import LoginFields from "../LoginFields";
import { Footer } from "../../../../../components";

const LoginContainer = () => {

  return (
    <div className="login-container">
        <LoginFields loginPlaceholder="Login ID" passwordPlaceholder="Password" />
        <Footer className="login-container__footer" style={{}}/>
    </div>
  );
};

LoginContainer.propTypes = {
};
LoginContainer.defaultProps = {
}

export default LoginContainer;
