// Written by Micah Looi
// Translated from MATLAB Model - EinlyLimModel_Pump_Wrapper

// This file is no longer in use. Refer to ecmoModel.cpp instead
#include <cmath>

/** 
 * Pressure drop across oxygenator
 * **/

double pi = 3.1415926;
double pump_iter = 0;

double pd_oxygenator(double Q_pump)
{
    // some constant
    double cP = 2.7; //blood viscosity
    double cr = 6;
    double cf = -4.2659;
    double ca = -0.099;
    double cb = 1.8024;
    double pd_oxygenator = 0;

    // switch port checkpoint, three options
    double u_switch1 = 1;                             // when oxymemthrom is 0
    double OxyMemThrom_switch2 = 0;                   // constant for OxygenatorMembraneThrombosis
    double sub_pd_oxy = exp(0.035 * pump_iter) * 0.5; // subsystem, does the saturation means average over seconds??????

    if (sub_pd_oxy >= 16.5)
    {
        sub_pd_oxy = 16.5; //Saturation
    }

    double u_switch3 = sub_pd_oxy + 1.5;

    double f_u = cb * exp(ca * cP * u_switch1); // using switch 1 value for now
    double pow_func = pow(Q_pump, f_u);
    double x = ((cr * cP) + cf) * (pow_func); //constant * power function  checkpoint
    double pd_oxygenator_val = x / 2.2;       //  output for PD across oxygenator

    return pd_oxygenator_val;
}

/** 
 * Pressure drop across tubing
 * **/

double pd_tubing(double Q_pump)
{
    double cP = 2.7 * 0.001; //blood_visc
    double pi = 3.1415926;
    double tube_radius = 0.0047625;

    double tube_1_length = 1.8;
    double tube_2_length = 0.8;
    double tube_3_length = 1.8;

    //tube 1
    double pd_tube_1 = Q_pump * ((8 * cP * tube_1_length) / (pi * pow(tube_radius, 4))); // Hagen-poiseuille function
    double pd_tube_1_mmHg = pd_tube_1 / 133.322;  // convert Pa to mmHg

    //tube 2
    double pd_tube_2 = Q_pump * ((8 * cP * tube_2_length) / (pi * pow(tube_radius, 4)));
    double pd_tube_2_mmHg = pd_tube_1 / 133.322;

    // tube 3
    double pd_tube_3 = Q_pump * ((8 * cP * tube_3_length) / (pi * pow(tube_radius, 4)));
    double pd_tube_3_mmHg = pd_tube_1 / 133.322;

    double pd_tube_total = pd_tube_1_mmHg + pd_tube_2_mmHg + pd_tube_3_mmHg;

    return pd_tube_total;
}

// sub- function for pd cannula in when patient has blood vessel suction complication
double pd_cannula_blood_vessel_suction(double p_ra)
{
    double BV_PD = exp(pow((p_ra + (-1.3) / 1.3), 2) * -1) * 6000;
}

// sub-function for pd across canula (for both cannula in and out)
double pd_cannula(double Q_pump, double cP, double cann_length, double fr_length)
{
    double hagen_p_func = (8 * cP * (cann_length - fr_length)) / (pi * pow((0.0047625 - 0.00096), 4));
    double C_PD_val_1 = hagen_p_func * Q_pump;

    double velocity_func = 4 / (pi * pow((fr_length / 3000 - 0.00096), 2));
    double RE_func = ((fr_length / 6000 - 0.00096) * 1060) / cP;
    double darcy_w_func = (1060 * 8 * fr_length) / (pow(pi, 2) * pow((fr_length / 3000 - 0.00096), 5)); // check if fr_length == fr

    // from velocity to darcy friction factor
    double darcy_friction = 0.316 / pow((velocity_func * Q_pump * RE_func), 0.25);
    double C_PD_val_2 = darcy_friction * darcy_w_func * pow(Q_pump, 2); // multiply5 checkpoint
    double C_PD = (C_PD_val_1 + C_PD_val_2) / 133.322;
}

// sub-function for pd cannula out when patient has kinked return line complication
double pd_cannula_out_kinked(double Q_pump, double cP, double cann_length, double fr_length)
{
    double hagen_p_func = (8 * cP * (cann_length - fr_length)) / (pi * pow((0.0047625 - 0.00096), 4));
    double C_PD_val_1 = hagen_p_func * Q_pump;

    double velocity_func = 4 / (pi * pow((fr_length / 3000 - 0.00096), 2));
    double RE_func = ((fr_length / 6000 - 0.00096) * 1060) / cP;
    double darcy_w_func = (1060 * 8 * fr_length) / (pow(pi, 2) * pow((fr_length / 3000 - 0.00096), 5)); // check if fr_length == fr

    // from velocity to darcy friction factor
    double darcy_friction = 0.316 / pow((velocity_func * Q_pump * RE_func), 0.25);

    double ramp = 1 + 1.4 * pump_iter;
    if (ramp >= 5)
    { // saturation
        ramp = 5;
    }
    double C_PD_val_2 = darcy_friction * darcy_w_func * pow(Q_pump, 2) * ramp; // multiply5 checkpoint
    double C_PD = (C_PD_val_1 + C_PD_val_2) / 133.322;
}

/** 
 * Pressure drop across cannula in and out
 * **/

double pd_cannula_total(double Q_pump, double p_ra, int blood_vessel_suc, int kinked_return_line)
{
    double cP = 2.7 * 0.001; //blood_visc

    //cannula_in constant
    double cann_in_length = 0.4;
    double cann_in_size = 17;
    double fr_in_length = 0.18;

    //cannula_out constant
    double cann_out_length = 0.3;
    double cann_out_size = 21;
    double fr_out_length = 0.15;

    /** 
     * cannula_in formula
     * **/
    double cann_in_pd = 0;
    if (blood_vessel_suc == 1)
    { //patient complication blood vessel suction
        cann_in_pd = pd_cannula_blood_vessel_suction(p_ra) + pd_cannula(Q_pump, cP, cann_in_length, fr_in_length);
    }
    else
    { //normal patient
        cann_in_pd = pd_cannula(Q_pump, cP, cann_in_length, fr_in_length);
    }

    double cann_out_pd = 0;
    if (kinked_return_line == 1) //with kinked
    {
        cann_out_pd = pd_cannula_out_kinked(Q_pump, cP, cann_out_length, fr_out_length);
    }
    else
    { // normal patient
        cann_out_pd = pd_cannula(Q_pump, cP, cann_out_length, fr_out_length);
    }

    double cann_pd = cann_in_pd + cann_out_pd;

    return cann_pd;
}