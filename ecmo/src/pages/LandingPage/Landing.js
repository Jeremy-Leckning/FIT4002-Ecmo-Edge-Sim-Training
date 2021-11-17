import React, { Component } from "react";
import "./Landing.scss";
import {Header, Footer} from "../../components";
import textbook from "../../shared/assets/Textbook.png";
import training from "../../shared/assets/Training.png";
import model from "../../shared/assets/Model.png";
import Button from "@material-ui/core/Button";
import { Link } from 'react-router-dom';

import {PATH} from '../../shared/constant'
class Landing extends Component {

  render() {
    const title = "Welcome"
    const data = [
      {
        "link": PATH.TEXTBOOK.CHAPTERSELECT,
        "value": "Textbook",
        "imgSrc": textbook,
        "imgAlt": "textbook"
      },
      {
        "link": PATH.TRAINING.ScenarioSelectPage,
        "value": "Training",
        "imgSrc": training,
        "imgAlt": "training"
      },
      {
        "link": PATH.FREEPLAY,
        "value": "Model",
        "imgSrc": model,
        "imgAlt": "Model"
      },
    ];
    return (
      <div className="landing-page">
        <Header title={title}/>
        <div className="landing-page__main-wrapper">
          {data.map((element, index) => 
            <Link to={element.link}>
              <div className="landing-page__main-wrapper__option">
                  <Button className="button" variant="contained" color="primary">
                    {element.value}
                  </Button>
                  <img className="img-logo" src={element.imgSrc} alt={element.imgAlt} />
              </div>
            </Link>
          )}
        </div>
        <Footer />
      </div>
    );
  }
}

export default Landing;