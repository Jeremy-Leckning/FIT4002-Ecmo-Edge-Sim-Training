import React, {} from "react";
import {Header, Footer, ChapterSceneSelector} from "../../../components";
import "./ChapterSelect.scss";
import { PATH } from '../../../shared/constant'

const defaultList = [
  'Chapter 1',
  'Chapter 2',
  'Chapter 3',
  'Chapter 4',
  'Chapter 5',
  'Chapter 6',
  'Chapter 7',
  'Chapter 8',
  'Chapter 9',
  'Chapter 10',
  'Chapter 11',
  'Chapter 12',
  'Chapter 13',
  'Chapter 14',
  'Chapter 15',
  'Chapter 16',
  'Chapter 17',
  'Chapter 18',
  'Chapter 19',
  'Chapter 20',
  'Chapter 21',
  'Chapter 22',
  'Chapter 23',
  'Chapter 23',
];

const ChapterSelect = ({listData=defaultList}) => {
  return (
    <div className="chapter-select-wrapper">
        <Header title="Chapters"/>
        <ChapterSceneSelector listData={listData} isTextbook isScenario={false} buttonLinkTo={`${PATH.TEXTBOOK.PAGE1}/01`}/>
        <Footer/>
    </div>
  );
};


export default ChapterSelect;