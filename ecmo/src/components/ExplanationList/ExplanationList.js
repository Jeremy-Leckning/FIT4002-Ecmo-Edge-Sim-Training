
import React, {} from "react";
import "./ExplanationList.scss";

const defaultListData = [
    {
        label: 'Stage 1',
        description: 'Perform initial troubleshooting checks of the ECMO circuit:',
        bulletPoints: ['Line colour differential', 'Gas blender setting', 'Gas flow', 'Flowmeter calibration']
    },
    {
        label: 'Stage 2',
        description: 'Consider access insufficiency as a cause for hypoxaemia:',
        bulletPoints: ['Check for line chattering', 'Observe flow rate', 'Perform a ramp test', 'Consider pump speed increase',]
    },
    {
        label: 'Stage 3',
        description: 'Consider the cause of this patient’s hypoxaemia:',
        bulletPoints: ['What would be your next steps?', 'Can you arrive at a diagnosis?']
    }
];

const ExplanationList = ({descriptionData=defaultListData}) => {


  return (
    <div className="explanation-list-wrapper">
        {descriptionData.map((element, idx) => (
            <div className="explanation-list-wrapper__list-element" key={`explanation-list-wrapper__list-element-${idx}`}>
                <div className="explanation-list-wrapper__list-element__label">
                    {element.label}
                </div>
                <div className="explanation-list-wrapper__list-element__description">
                    {element.description}
                    <section className="explanation-list-wrapper__list-element__description__bullet-points">
                        <ul>
                            {element.bulletPoints.map((bulletPoint, bulletPointIndex) => (
                                <li key={bulletPointIndex}>
                                    {bulletPoint}
                                </li>
                            ))}
                        </ul>
                    </section>
                </div>
            </div>
        ))}
    </div>
  );
};


export default ExplanationList;
