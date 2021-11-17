
import React, {} from "react";
import "./ImageWithDescription.scss";

import scenarioDescriptionImg from "../../shared/assets/scenario-description-img.png";
import { Button } from "..";
import parse from 'html-react-parser';
import {PATH} from '../../shared/constant'
import { Link } from 'react-router-dom';

const defaultData = {
    imgSrc: scenarioDescriptionImg,
    scenarioNumber: '1',
    description: 'A 26 year-old man with severe acute respiratory distress syndrome (ARDS - i.e. lung failure) due to COVID-19 is currently receiving VV-ECMO for respiratory failure. You are asked to review him because an arterial blood gas (ABG) from his right radial arterial line shows that he has an SaO2 of 80%, which is consistent with the SpO2 monitor on his left index finger (i.e. the patient is hypoxaemic - low oxygen in the blood).',
    learningObjectives: `<p><i><strong>Learning Objectives</strong></i></p><ul><li>Demonstrate initial checks for an ECMO circuit</li><li>Investigate the causes of hypoxaemia</li></ul>`,
    buttonLinkTo: PATH.TRAINING.ScenarioExplanationPage,
};

const ImageWithDescription = ({descriptionData=defaultData}) => {


  return (
    <div className="image-with-description">
        <img src={descriptionData.imgSrc} className="image-with-description__img" alt='scenario-discription-img'></img>
        <div className="image-with-description__description-container">
            
            <div className="image-with-description__description-container__description-body">
                <label className="image-with-description__description-container__description-body__heading">
                    {`Scenario ${descriptionData.scenarioNumber}`}
                </label>
                <p className="image-with-description__description-container__description-body__description-text">
                    {descriptionData.description}
                </p>
                <p className="image-with-description__description-container__description-body__learning-objectives">
                    {parse(descriptionData.learningObjectives)}
                </p>
            </div>
            <Link to={descriptionData.buttonLinkTo}>
                <Button value='Begin' isMatteBlue/>
            </Link>
        </div>
    </div>
  );
};


export default ImageWithDescription;
