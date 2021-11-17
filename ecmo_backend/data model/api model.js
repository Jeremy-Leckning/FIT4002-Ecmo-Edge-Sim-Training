const vv_ecmo_circuit= {
    vv_ecmo_circuit:{
        fresh_gas_flow: '',
        gas_blender: '',
       }
    }

const vv_ecmo_circuit_buttons={
    vv_ecmo_circuit_buttons:{
        oxygenator: '',
        pump: '',
        gas_flow_meter: '', 
        clamps: '',
        //return_line: '',
        //drainage_line:'',
    }
}

const patient_vitals = {
    patient_vitals: {
        heart_rate: '',
        ambulatory_blood_pressure: '',
        disulfur_dioxide: '',
        temperature: '',
    }
}

const patient_details = {
    patient_details:{
        sex: '',
        age: '',
        height:'',
        weight: '',
        medical_history: '',
        allergies: '',
        medications:'',
        other_notes: ''
    }
    
}; 
//button changes ecmo monitor values 
const ecmo_monitor = {
    ecmo_monitor: {
        ecmo_flow: '',
        ecmo_pump: '',
        p_ven: '',
        p_art: '',
        disulfur_dioxide: '',
        power_button: '',
        flow_meter_zero_button: '',
        ecmo_rmp_toggle: '',  
    }
}

const activity_log = {
    activity_log:[{
        id: '',
        date: '', // from local time
        time: '',
        description: '',
    }]
}


const objective = {
    objective:[{
        id: '',
        description: '',
        action:[
            {
                id:'',
                description:''
            }
        ], //for buttons and 4 actions buttons
        hint:''}
    ]
}

//assume a patient can have more than one complication, and the list will grow
const complications={
    complications:{
        bleeding: '',
        kinked_ret_line:'',
        blood_vessel_suction:'',
        oxygenator_mem_throm:'',
        pericade_tamponade:'',
    }
}
const scenarios = {
    scenarios:[{
        id: '', 
        title:'', 
        description: '',
        vv_ecmo_circuit:{
            fresh_gas_flow: '',
            gas_blender: '',
        },
        vv_ecmo_circuit_buttons:{
            oxygenator: '',
            pump: '',
            gas_flow_meter: '', 
            clamps: '',
            //return_line: '',
            //drainage_line:'',
        },
        patient_vitals: {
            heart_rate: '',
            ambulatory_blood_pressure: '',
            disulfur_dioxide: '',
            temperature: '',
        },
        patient_details:{
            sex: '',
            age: '',
            height:'',
            weight: '',
            medical_history: '',
            allergies: '',
            medications:'',
            other_notes: ''
        },
        ecmo_monitor: {
            ecmo_flow: '',
            ecmo_pump: '',
            p_ven: '',
            p_art: '',
            disulfur_dioxide: '',
            power_button: '',
            flow_meter_zero_button: '',
            ecmo_rmp_toggle: '',  
        },
        objective:[{
            id: '',
            description: '',
            action:[
                {
                    id:'',
                    description:''
                }
            ], //for buttons and 4 actions buttons
            hint:''}
        ],
        activity_log:[{
            id: '',
            date: '', // from local time
            time: '',
            description: '',
        }],
        complications:{
            bleeding: '',
            kinked_ret_line:'',
            blood_vessel_suction:'',
            oxygenator_mem_throm:'',
            pericade_tamponade:'',
        }
    
}]};
