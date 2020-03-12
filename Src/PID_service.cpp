/*
 * PID_service.cpp
 *
 *  Created on: Aug 7, 2019
 *      Author: MKoza1
 */

#include "PID_service.hpp"
#include "main.h"

float PIDControl;

PID::PID(float time_, float Kp_, float Ki_, float Kd_)
:time(time_),Kp(Kp_),Ki(Ki_),Kd(Kd_){

	Set_Voltage = 5;
	ErrorSum = 0;
	max = 192;
	min = 0;
	time_d = 0.003;


}

PID::~PID(){


}


float PID::PID_Control(float Voltage){

	float Error = (Set_Voltage - Voltage);


	//------------P--------------//
	Proportional = Kp * Error;

	//------------I--------------//

	if((PIDControl > min) && (PIDControl < max)){

	ErrorSum += Error*time;
	Integral = Ki * ErrorSum;

	}

	//------------D-------------//

	Derivative = Kd * ((Error - PreError)/time_d);


	PIDControl = Proportional + Integral + Derivative;

	if(PIDControl > max)
			PIDControl = max;

	else if(PIDControl < min)
			PIDControl = min + 1;

	PreError = Error;


	return PIDControl;

}

void PID::PID_Set(float Set_Voltage_,float Kup, float Kui, float Kud){

	Set_Voltage = Set_Voltage_;
	Kp = Kup;
	Ki = Kui;
	Kd = Kud;


}






