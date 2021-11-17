import React, {} from "react";
import {Header, Footer, ChapterSceneSelector} from "../../../components";
import "./ScenarioSelectPage.scss";
import { PATH } from '../../../shared/constant'

const defaultList = [
  'Scenario 1',
  'Scenario 2',
  'Scenario 3',
  'Scenario 4',
  'Scenario 5',
  'Scenario 6',
  'Scenario 7',
  'Scenario 8',
  'Scenario 9',
  'Scenario 10',
  'Scenario 11',
  'Scenario 12',
  'Scenario 13',
  'Scenario 14',
  'Scenario 15',
  'Scenario 16',
  'Scenario 17',
  'Scenario 18',
  'Scenario 19',
  'Scenario 20',
  'Scenario 21',
  'Scenario 22',
  'Scenario 23',
  'Scenario 23',
];

const ScenarioSelectPage = ({listData=defaultList}) => {


  return (
    <div className="scenario-select-wrapper">
        <Header title="Scenarios"/>
        <ChapterSceneSelector listData={listData} isScenario isTextbook={false} buttonLinkTo={PATH.TRAINING.ScenarioDescriptionPage}/>
        <Footer/>
    </div>
  );
};


export default ScenarioSelectPage;