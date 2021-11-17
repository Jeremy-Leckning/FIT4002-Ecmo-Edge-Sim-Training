import React from "react";
import "./Card.scss";
import Button from '../Button'
import { Link } from 'react-router-dom';

const Card = ({bgColour, cardPadding, headerLabel, subheaderLabel, childComponent, textColour, buttonLabel, buttonOnClick, buttonLinkTo}) => {

    return (
        <div className='card' style={{backgroundColor: `${bgColour}`, color: `${textColour}`, padding: `${cardPadding}`}}>
            {headerLabel && <label className='card__header'>{headerLabel}</label>}
            {subheaderLabel && <label className='card_subheader'>{subheaderLabel}</label>}

            {childComponent && childComponent}

            {buttonLabel && 
                <Link to={buttonLinkTo}>
                    <Button value={buttonLabel} onClick={buttonOnClick} isMatteBlue/>
                </Link>
            }
        </div>
    )
};

export default Card;