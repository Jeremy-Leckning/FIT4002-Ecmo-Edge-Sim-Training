import React from "react";
import PropTypes from "prop-types";
import "./Button.scss";
import classNames from "classnames";


const Button = ({
    value,
    isIcon,
    iconSrc,
    isGrey,
    isGreen,
    isMatteBlue,
    onClick,
    textColor,
    backgroundColor,
}) => {

    const customClasses = classNames({
        "button-wrapper__button--grey": isGrey,
        "button-wrapper__button--green": isGreen,
        "button-wrapper__button--matte-blue": isMatteBlue,

      });


    return (
        <div className="button-wrapper">
            <button className={`button-wrapper__button ${customClasses}`} onClick={onClick} style={{color:textColor, backgroundColor:backgroundColor}}>{value}</button>
        </div>
    );
};

Button.propTypes = {
    value: PropTypes.string,
    isIcon: PropTypes.bool,
    iconSrc: PropTypes.string,
    onClick: PropTypes.func,
};

Button.defaultProps = {
    value: 'insert button value',
    isIcon: false,
    iconSrc: '',
    onClick: () => {},
    isGrey: false,
    isGreen: false,
}

export default Button;