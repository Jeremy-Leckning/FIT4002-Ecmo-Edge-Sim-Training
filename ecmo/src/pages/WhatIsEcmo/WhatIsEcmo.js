import React, {useState} from "react";
import "./WhatIsEcmo.scss";
import {Header, Footer} from "../../components";
import ecmo_img from "../../shared/assets/ECMO.jpg";
import "./WhatIsEcmo.scss";
import EditIcon from "../../shared/icons/pencil.svg";
import SaveCheckmark from "../../shared/icons/check.svg";
import SwapIcon from "../../shared/icons/arrow-left-right.svg";
import BlankSVG from "../../shared/icons/blank.svg";


import parse from 'html-react-parser';

import { CKEditor } from '@ckeditor/ckeditor5-react';
import ClassicEditor from '@ckeditor/ckeditor5-build-classic';


import Slider, { SliderTooltip } from 'rc-slider';
import 'rc-slider/assets/index.css';
const { Handle } = Slider;
const handle = props => {
  const { value, dragging, index, ...restProps } = props;
  return (
    <SliderTooltip
      prefixCls="rc-slider-tooltip"
      overlay={`${value} %`}
      visible={dragging}
      placement="top"
      key={index}
    >
      <Handle value={value} {...restProps} />
    </SliderTooltip>
  );
};


const WhatIsEcmo = () => {
  const title="What is ECMO?";
  const defaultText="<p><strong>Extracorporeal membrane Oxygenation (ECMO)</strong> is an advance form of life support which temporarily replaces the functions of the heart and/or lungs for cardiac and respiratory failure patients.</p><p><strong>3 phases of ECMO:</strong></p><p><strong>Initiation:</strong> Patient is anticoagulated and blood vessel access is established via catheterisation.</p><p><strong>Maintenance: </strong>There is constant monitoring of the patient and ECMO flow. Team ready to troubleshoot complications as they arise.</p><p><strong>Separation:</strong> Patient may clinically improve and be weaned from ECMO; or there may be a decision to cease ECMO should the patient deteriorate.</p>";
  const [getContent, setContent] = useState(defaultText);
  const [isEditing, setEditing] = useState(false);
  const [mirrorLayout, setMirrorLayout] = useState(false);
  const [sliderValue, setSliderValue] = useState(50)

  const leftContent = () => (
    <div className="what-is-ecmo__body-wrapper__main-container__left-container__card">
      <header className="what-is-ecmo__body-wrapper__main-container__left-container__card__heading">The Cardiohelp system</header>
      <img
        className="what-is-ecmo__body-wrapper__main-container__left-container__card__ecmo-img"
        src={ecmo_img}
        alt="Ecmo machine"
      />
      <div className="what-is-ecmo__body-wrapper__main-container__left-container__card__next-button">
      {/* <Button value="Continue" textColor="white" backgroundColor='#204782'></Button> */}
      </div>
    </div>
  )

  const rightContent = () => {
    if (isEditing) {
      return (
        <CKEditor
          editor={ ClassicEditor }
          data={getContent}
          onReady={ editor => {
              // You can store the "editor" and use when it is needed.
              console.log( 'Editor is ready to use!', editor );
              editor.ui.view.editable.element.style.minHeight = "100%";
          } }
          onChange={ ( event, editor ) => {
              const data = editor.getData();
              setContent(data);
              console.log( { event, editor, data } );
          } }
          onBlur={ ( event, editor ) => {
              console.log( 'Blur.', editor );
          } }
          onFocus={ ( event, editor ) => {
              console.log( 'Focus.', editor );
          } }
          height={'100%'}
        />
      )
    }
    else {
      return (
        <div className="what-is-ecmo__body-wrapper__main-container__right-container__parsed-text">
          {parse(getContent)}
        </div>
      )
    }
  }

  return (
    <div className="what-is-ecmo">
        <Header title={title}/>

        
        <div className="what-is-ecmo__body-wrapper">
          <div className="what-is-ecmo__body-wrapper__toolbar">
            <div className="what-is-ecmo__body-wrapper__toolbar__button-icons" 
              style={{width:`${100-sliderValue}%`, marginLeft:`${sliderValue-0.5}%`}}
            >
              <img 
                src={isEditing ? SwapIcon : BlankSVG}
                alt='Swap'
                onClick={() => setMirrorLayout(!mirrorLayout)}
              />
              <img 
                src={isEditing ? SaveCheckmark : EditIcon}
                alt='Edit/Save'
                onClick={() => setEditing(!isEditing)}
              />
            </div>
            {isEditing &&
              <Slider
                value={sliderValue}
                onChange={(value) => {setSliderValue(value)}}
                handle={handle}
              />
            }
          </div>
          <div className="what-is-ecmo__body-wrapper__main-container">
            {sliderValue > 20 && <div className="what-is-ecmo__body-wrapper__main-container__left-container" style={{width:`${sliderValue}%`}}>
              {mirrorLayout ? rightContent() : leftContent()}
            </div>}
            {sliderValue < 80 && <div className="what-is-ecmo__body-wrapper__main-container__right-container" style={{width:`${100-sliderValue}%`}}>
                {mirrorLayout ? leftContent() : rightContent()}
            </div>}
          </div>
        </div>
        
        <div className="what-is-ecmo__footer-wrapper">
          
          <Footer />

        </div>
        
    </div>
  );
};


export default WhatIsEcmo;
