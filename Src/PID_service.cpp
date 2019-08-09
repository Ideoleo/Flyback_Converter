/*
 * PID_service.cpp
 *
 *  Created on: Aug 7, 2019
 *      Author: MKoza1
 */

#include "PID_service.hpp"

float PIDControl;
uint8_t Set_VoltageME;

PID::PID(float time_,float max_,float min_, uint8_t Kp_, uint8_t Ki_, uint8_t Kd_)
:time(time_),max(max_),min(min_),Kp(Kp_),Ki(Ki_),Kd(Kd_){


}

PID::~PID(){


}

/*
void PIDConf::Error_fun(uint16_t Set_Voltage, float Voltage){

	Error = (Set_Voltage - Voltage);

}

void PIDConf::Proportional_fun(){

	Proportional = Kp*Error;

}

void PIDConf::Integral_fun(){


}

*/

float PID::PID_Control(uint16_t Set_Voltage, float Voltage){

	Set_VoltageME = 2;
	float Error = (Set_Voltage - Voltage);

	//------------P--------------//
	Proportional = Kp * Error;

	//------------I--------------//
	ErrorSum = (ErrorSum + Error)*time;
	Integral = Ki * ErrorSum;

	//------------D-------------//
	Derivative = Kd * ((Error - PreError)/time);

	PIDControl = Proportional + Integral + Derivative;

	if(PIDControl > max)
			PIDControl = max;

	else if(PIDControl < min)
			PIDControl = min;

	PreError = Error;

	return PIDControl;

}







