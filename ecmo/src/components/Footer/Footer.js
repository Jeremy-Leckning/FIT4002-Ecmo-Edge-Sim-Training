import React from "react";
import logo_createlab from "../../shared/assets/logo_createlab.svg";
import logo_medtech from "../../shared/assets/logo_medtech.png";
import logo_monash from "../../shared/assets/logo_monash_2.png";
import "./Footer.scss";

const Footer = () => (
  <footer className="footer">
    <div className="footer__footer-wrapper">
      <img src={logo_monash} className="footer__footer-wrapper__monash-logo" alt="monash-logo"/>
      <img src={logo_createlab} className="footer__footer-wrapper__createlab-logo" alt="createlab-logo"/>
      <img src={logo_medtech} className="footer__footer-wrapper__medtech-logo" alt="medtech-logo"/>
    </div>
  </footer>
);

export default Footer;