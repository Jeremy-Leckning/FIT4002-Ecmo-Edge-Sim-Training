import React, {useState, useEffect} from "react";
import {Header, Footer,Button} from "../../../components";
import "./ConfigurablePageA.scss";
import EditIcon from "../../../shared/icons/pencil.svg";
import SaveCheckmark from "../../../shared/icons/check.svg";
import SwapIcon from "../../../shared/icons/arrow-left-right.svg";
import BlankSVG from "../../../shared/icons/blank.svg";
import { PATH } from "../../../shared/constant";
import { useParams, Link, useHistory } from "react-router-dom";
import parse from 'html-react-parser';

import { CKEditor } from '@ckeditor/ckeditor5-react';
import ClassicEditor from '@ckeditor/ckeditor5-build-classic';


import Slider, { SliderTooltip } from 'rc-slider';
import 'rc-slider/assets/index.css';

import {Items} from "./mockdata"

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

const ConfigurablePageA = () => {
  
  const history = useHistory();

  
  const { pageNum } = useParams();

  const [getPageData] = Items.filter((item) => item.id === pageNum);
  const [pageData, setPageData] = useState(getPageData);

  useEffect(() => {
    // Call api

    // window.location.reload();

  }, [])


  const [getContent, setContent] = useState(pageData?.text_content);
  const [isEditing, setEditing] = useState(false);
  const [mirrorLayout, setMirrorLayout] = useState(pageData?.config_mirrored_view);
  const [sliderValue, setSliderValue] = useState(pageData?.config_mirrored_view ? pageData?.config_card_width : 99-pageData?.config_card_width)

  const refreshPage = () => {
    // window.location.reload();
    
    setTimeout(()=> history.go(0),1)
  }

  const cardContent = () => (
    <div className="card-content">
      {/* <header className="configurable-page-a__body-wrapper__main-container__left-container__card__heading">{pageData?.img_header_content_top_right}</header> */}
      <img
        className="card-content-img"
        src={pageData?.img_src_content_01}
        alt={pageData?.img_header_content_01}
        style={pageData?.img_src_content_02 ? {width:"66%"} : {maxWidth:"90%"}}
      />
      {pageData?.img_src_content_02 &&
        <img
          className="card-content-img"
          src={pageData?.img_src_content_02}
          alt={pageData?.img_header_content_02}
          style={pageData?.img_src_content_02 ? {width:"66%"} : {maxWidth:"90%"}}
        />
      }
      
    </div>
  )

  const textContent = () => {
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
          height={'100%'}
        />

      )
    }
    else {
      return (
        <div className="text-content">
          <div className="text-content__parsed-text" style={{textAlign:"justify"}}>
            {parse(getContent)}
          </div>
          <Link to={pageData?.button_link_to ? pageData?.button_link_to : PATH.TEXTBOOK.CHAPTERSELECT} >
            <Button value={pageData?.button_link_to ? "Continue" : "Finish"} textColor="white" backgroundColor="#204782" onClick={refreshPage}></Button>
          </Link>
        </div>
      )
    }
  }

  

  return (
    <div className="configurable-page-a">
        <Header title={pageData?.header_content}/>

        
        <div className="configurable-page-a__body-wrapper">
          <div className="configurable-page-a__body-wrapper__toolbar">
            <div className="configurable-page-a__body-wrapper__toolbar__button-icons" 
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
          <div className="configurable-page-a__body-wrapper__main-container">
            {sliderValue > 20 && <div className="configurable-page-a__body-wrapper__main-container__left-container" style={{width:`${sliderValue}%`}}>
              {mirrorLayout ? cardContent() : textContent()}
            </div>}
            {sliderValue < 80 && <div className="configurable-page-a__body-wrapper__main-container__right-container" style={{width:`${100-sliderValue}%`}}>
              {mirrorLayout ? textContent() : cardContent()}
            </div>}
          </div>
        </div>
        
        <div className="configurable-page-a__footer-wrapper">
          
          <Footer />

        </div>
        
    </div>
  );
};


export default ConfigurablePageA;