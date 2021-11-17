import React, {useState} from "react";
import "./ScrollingList.scss";
const ScrollingList = ( {listData, handleOnClick} ) => {
    

    const [selectedIndex, setSelectedIndex] = useState(null)
    const handleListItemOnClick = (idx) => {
        setSelectedIndex(idx)
        handleOnClick(idx)
    }
    
    return (
    <div className='scrolling-list' >
        <ul className='scrolling-list__ul'>
            {listData.map((element, idx) => 
                <li 
                    key={idx}
                    className= {idx === selectedIndex ? 'scrolling-list__ul__li--selected' : 'scrolling-list__ul__li'}
                    onClick={() => handleListItemOnClick(idx)}
                >{element}</li>
            )}
        </ul>
    </div>
)}

export default ScrollingList;