import React from "react";
import PropTypes from "prop-types";
import "./LoginFields.scss";
import {InputField,Button} from "../../../../../components"; 
import loginIcon from "../../../../../shared/assets/play-circle-fill.svg";

const LoginFields = ({
    loginPlaceholder,
    passwordPlaceholder,
    onSubmit,
}) => {
  return (
    <div className="login-fields">
        <form className="login-fields__form" onSubmit={onSubmit}>
            <InputField placeholder={loginPlaceholder} onChange={(e) => console.log(e)}/>
            <InputField placeholder={passwordPlaceholder}/>
        </form>
        <Button value="Submit" isGreen iconSrc={loginIcon} onClick={() => window.open('/Landing',"_self")}/>
        <Button value="Forgot Password ?" isGrey/>
    </div>
  );
};

LoginFields.propTypes = {
    loginPlaceholder: PropTypes.string,
    passwordPlaceholder: PropTypes.string,
    onSubmit: PropTypes.func,
};

LoginFields.defaultProps = {
    loginPlaceholder: 'insert login placeholder',
    passwordPlaceholder: 'insert password placeholder',
    onSubmit: () => {},
}

export default LoginFields;
