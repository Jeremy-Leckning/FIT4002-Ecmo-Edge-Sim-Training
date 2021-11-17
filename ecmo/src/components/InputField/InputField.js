import React, {useState} from "react";
import PropTypes from "prop-types";
import "./InputField.scss";

const InputField = ({
    placeholder,
    value,
    onChange,
    onSubmit,
}) => {
    const [inputValue, setInputValue] = useState(value);
    const handleChange = (e) => {
        setInputValue(e.target.value)
    }

    return (
        <div className="input-field">
            <input className="input-field__input" placeholder={placeholder} value={inputValue} onChange={handleChange}/>
        </div>
    );
};

InputField.propTypes = {
    loginPlaceholder: PropTypes.string,
    value: PropTypes.string,
    onChange: PropTypes.func,
    onSubmit: PropTypes.func,
};

InputField.defaultProps = {
    placeholder: 'insert login placeholder',
    value: '',
    onChange: () => {},
    onSubmit: () => {},
}

export default InputField;
