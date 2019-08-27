/*
 * PID_service.cpp
 *
 *  Created on: Aug 7, 2019
 *      Author: MKoza1
 */

#include "PID_service.hpp"

float PIDControl = 1;
uint8_t Set_VoltageME;

PID::PID(float time_, float Kp_, float Ki_, float Kd_)
:time(time_),Kp(Kp_),Ki(Ki_),Kd(Kd_){

	ErrorSum = 0;
	max = 50;
	min = 0;


}

PID::~PID(){


}


float PID::PID_Control(float Set_Voltage, float Voltage){

	Set_VoltageME = 5;
	float Error = (Set_Voltage - Voltage);


	//------------P--------------//
	Proportional = Kp * Error;

	//------------I--------------//

	if((PIDControl > min) && (PIDControl < max)){

	ErrorSum = ErrorSum + (Error*time);
	Integral = Ki * ErrorSum;

	}

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

void PID::PID_Set(float Set_Voltage,float Kup, float Kui, float Kud, float time_in){

	Kp = Kup;
	Ki = Kui;
	Kd = Kud;
	time = time_in;

	printf("Kp: %lu Ki: %lu Kd: %lu \n\r",Kp,Ki,Kd);

}






