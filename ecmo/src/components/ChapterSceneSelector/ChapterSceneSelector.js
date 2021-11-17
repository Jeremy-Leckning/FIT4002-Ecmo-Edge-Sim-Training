import React, {useState} from "react";
import "./ChapterSceneSelector.scss";
import Card from '../Card';
import { ScrollingList, TextBody } from "..";

const ChapterSceneSelector = ({listData, isTextbook, isScenario, buttonLinkTo}) => {

    // TODO: can use selectedIndex to filter relevant chapter or scenario
    const [selectedIndex, setSelectedIndex] = useState(null)
    const handleSelectFromList = (index) => {
        setSelectedIndex(index)
    }

    const handleNextButtonOnClick = () => {
        console.log('next button clicked')
    }
    
    return (
        <div className='chapter-scene-selector'>
            <section className='chapter-scene-selector__description'>
                <Card bgColour='#0A2A5A' textColour='white' headerLabel={`${isTextbook ? 'Chapter' : ''}${isScenario ? 'Scenario' : ''} X`}
                    childComponent={<TextBody
                            body='A 26 year-old man with severe acute respiratory distress syndrome (ARDS - i.e. lung failure) due to COVID-19 is currently receiving VV-ECMO for respiratory failure. You are asked to review him because an arterial blood gas (ABG) from his right radial arterial line shows that he has an SaO2 of 80%, which is consistent with the SpO2 monitor on his left index finger (i.e. the patient is hypoxaemic - low oxygen in the blood).'
                        />}
                />
            </section>
            <section className='chapter-scene-selector__list-of'>
                <Card 
                    bgColour='#0A2A5A'
                    textColour='white'
                    headerLabel={`Select ${isTextbook ? 'Chapter' : ''}${isScenario ? 'Scenario' : ''}`}
                    buttonLabel='Next'
                    buttonOnClick={handleNextButtonOnClick}
                    buttonLinkTo={buttonLinkTo}
                    childComponent={<ScrollingList listData={listData} handleOnClick={handleSelectFromList}/>}
                />
            </section>
        </div>
    )
};

export default ChapterSceneSelector;