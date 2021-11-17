import React, {} from "react";
import "./ExplanationCard.scss";
import { useParams } from "react-router-dom";
import { Card, ExplanationList } from "..";
import {PATH} from '../../shared/constant'

const defaultData = {
    headerLabel:'Scenario Explanation',
    subheaderLabel:'There are many possible causes for this patient’s hypoxaemia. We must first exclude ECMO circuit anomalies as a cause for hypoxaemia before considering patient-side investigations.',
    childComponent:<></>,
    buttonLabel:'Continue',
    bgColour:'#CFDCF0',
    cardPadding:'40px 80px',
    
    buttonLinkTo: `${PATH.TRAINING.AccessInsufficiencyScenario}`,
};

const ExplanationCard = ({descriptionData=defaultData}) => {
  const pageNum = useParams();
  console.log(pageNum)


  return (
    <div className="explanation-card-wrapper">
        <div className="explanation-card-wrapper__card-container">
            <Card 
                headerLabel={descriptionData.headerLabel}
                subheaderLabel={descriptionData.subheaderLabel}
                childComponent={<ExplanationList/>}
                buttonLabel={descriptionData.buttonLabel}
                bgColour={descriptionData.bgColour}
                cardPadding={descriptionData.cardPadding}
                buttonLinkTo={descriptionData.buttonLinkTo}
            />
        </div>
    </div>
  );
};


export default ExplanationCard;