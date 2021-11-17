var scenario_1= 
 {scenarios:[
     {
        id: 1, 
        title:"Scneario 1", 
        description: "",
        learning_objectives: "",
        vv_ecmo_circuit:{
            fresh_gas_flow: 10,
            gas_blender: 1.0
        },
        vv_ecmo_circuit_buttons:{
            oxygenator: 0,
            pump: 0,
            gas_flow_meter: 0, 
            clamps: 0,
            return_line: 0,
            drainage_line:0
        },
        patient_vitals: {
            heart_rate: 99,
            ambulatory_blood_pressure: "120/80",
            disulfur_dioxide: 85,
            temperature: 36.5,
        },
        patient_details:{
            sex: 'M',
            age: '54',
            height:'182',
            weight: '84',
            medical_history: 'None',
            allergies: 'None',
            medications:'None',
            other_notes: '-'
        },
        ecmo_monitor: {
            ecmo_flow: 0.83,
            ecmo_pump: 2500,
            p_ven: 10,
            p_art: 50,
            disulfur_dioxide: 0.0,
            power_button: 0,
            flow_meter_zero_button: 0,
            ecmo_rmp_toggle: 0,  
        },
        objective:[{
            id: '1',
            description: 'Check colour differential of the ECMO lines',
            action:[
                {
                    id:'',
                    description:''
                }
            ], //for buttons and 4 actions buttons
            hint:'Check the colour of return line'},
        {
            id: '2',
            description: 'Check gas flow',
            action:[
                {
                    id:'',
                    description:''
                }
            ], //for buttons and 4 actions buttons
            hint:'Check the gas flow meter'},
        {
            id: '3',
            description: 'Check the gas blender setting',
            action:[
                {
                    id:'',
                    description:''
                }
            ], //for buttons and 4 actions buttons
            hint:'Check the gas blender'},
        {
            id: '4',
            description: 'Perform flow calibration',
            action:[
                {
                    id:'',
                    description:''
                }
            ], //for buttons and 4 actions buttons
            hint:[
                {
                    step : 1,
                    description: 'Claim the drainage and return lines',
                    action: 'Click on the "Clamps'
                },
                {
                    step : 2,
                    description: 'Set the ECMO RPM to 0',
                    action: 'Click on the ECMO "Zero" button'
                },
                {
                    step : 3,
                    description: 'Set the ECMO Flow to 0',
                    action: 'Click on the ECMO "Zero" button'
                },
                {
                    step : 4,
                    description: 'Set the ECMO RPM to 1000',
                    action: 'Click on the ECMO RPM dial'
                },
                {
                    step : 5,
                    description: 'Unclaim the drainage and return lines',
                    action: 'Click on the "Clamps'
                },
                {
                    step : 6,
                    description: 'Adjust the ECMO RPM until ECMO flow is 4.5 L/min',
                    action: 'Click on the ECMO RPM dial' 
                }]
        }],
        activity_log:[{
            id: '0',
            date: '23/5/2021', // from local time
            time: '14:10:25', // hh:mm:ss
            description: 'Senario Commenced',
        }, {
            id: '1',
            date: '23/5/2021', // from local time
            time: '14:11:25', // hh:mm:ss
            description: 'Checked drainage line',
        },{
            id: '2',
            date: '23/5/2021', // from local time
            time: '14:15:25', // hh:mm:ss
            description: 'Colour differential checked - There is appropriate colour differential',
        },
        {
            id: '3',
            date: '23/5/2021', // from local time
            time: '14:20:25', // hh:mm:ss
            description: 'Fresh gas flow checked - Gas tuning is correctly fitted',
        },
        {
            id: '4',
            date: '23/5/2021', // from local time
            time: '14:23:25', // hh:mm:ss
            description: 'Gas blender checked -FiO2=1.0',
        },
        {
            id: '5',
            date: '23/5/2021', // from local time
            time: '14:23:25', // hh:mm:ss
            description: 'Drainage and return lines clamped',
        },
        {
            id: '6',
            date: '23/5/2021', // from local time
            time: '14:23:25', // hh:mm:ss
            description: 'ECMO RPM set to 0',
        },
        {
            id: '5',
            date: '23/5/2021', // from local time
            time: '14:23:25', // hh:mm:ss
            description: 'ECMO flowmeter zeroed',
        },
        {
            id: '6',
            date: '23/5/2021', // from local time
            time: '14:23:25', // hh:mm:ss
            description: 'ECMO RPM set to 1000',
        },
        {
            id: '7',
            date: '23/5/2021', // from local time
            time: '14:23:25', // hh:mm:ss
            description: 'Drainage and return lines unclamped',
        },
        {
            id: '8',
            date: '23/5/2021', // from local time
            time: '14:23:25', // hh:mm:ss
            description: 'ECMO RPM set to 2000',
        },
        {
            id: '9',
            date: '23/5/2021', // from local time
            time: '14:23:25', // hh:mm:ss
            description: 'Flow calibration complete - ECMO FLow = 4.5',
        },
        {
            id: '10',
            date: '23/5/2021', // from local time
            time: '14:23:25', // hh:mm:ss
            description: 'Initial checks completed',
        }],

        complications:{
            bleeding: 0,
            kinked_ret_line:0,
            blood_vessel_suction:0,
            oxygenator_mem_throm:0,
            pericade_tamponade:0,
        }
    
}]};

module.exports={scenario_1};
