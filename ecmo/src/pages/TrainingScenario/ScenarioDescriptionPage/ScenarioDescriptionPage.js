import React, {} from "react";
import {Header, Footer, ImageWithDescription} from "../../../components";
import "./ScenarioDescriptionPage.scss";


const defaultList = [

];

const ScenarioDescriptionPage = ({listData=defaultList}) => {


  return (
    <div className="scenario-description-wrapper">
        <Header/>
        <ImageWithDescription/>
        <Footer/>
    </div>
  );
};


export default ScenarioDescriptionPage;
