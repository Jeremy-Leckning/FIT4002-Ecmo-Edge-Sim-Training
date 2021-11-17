import React, {} from "react";
import {Header, Footer, ExplanationCard} from "../../../components";
import "./ScenarioExplanationPage.scss";


const defaultList = [

];

const ScenarioExplanationPage = ({listData=defaultList}) => {


  return (
    <div className="scenario-description-wrapper">
        <Header/>
        <ExplanationCard />
        <Footer/>
    </div>
  );
};


export default ScenarioExplanationPage;
