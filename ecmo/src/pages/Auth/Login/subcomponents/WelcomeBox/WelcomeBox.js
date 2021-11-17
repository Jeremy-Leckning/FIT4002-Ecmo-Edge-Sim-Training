import React from "react";
import PropTypes from "prop-types";
import "./WelcomeBox.scss";

const WelcomeBox = ({
    headerLabel,
    primaryLabel,
    secondaryLabel,
}) => {

  return (
    <div className="welcome-box">
        <div className="welcome-box__logo">
            <span className="welcome-box__logo__label">{headerLabel}</span>
        </div>
        <div className="welcome-box__primary-label">
            {primaryLabel}
        </div>
        <div className="welcome-box__secondary-label">
            {secondaryLabel}
        </div>
    </div>
  );
};

WelcomeBox.propTypes = {
    headerLabel: PropTypes.string,
    primaryLabel: PropTypes.string,
    secondaryLabel: PropTypes.string,
};

WelcomeBox.defaultProps = {
    headerLabel: 'insert header label',
    primaryLabel: 'insert primary label',
    secondaryLabel: 'insert secondary label',
}

export default WelcomeBox;
