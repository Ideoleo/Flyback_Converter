/*
 * Set_P.cpp
 *
 *  Created on: Aug 26, 2019
 *      Author: MKoza1
 */


#include "Set_P.hpp"
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

SetP::SetP(PID* const p_pid)
:p_pid(p_pid){


}

SetP::~SetP(){


}



std::string SetP::Execute(const std::vector<std::string>& vdata){

	std::string pString;
	char buffer[100] = {};

	if(vdata.size() >= 5)
	{

		sscanf(vdata[1].c_str(),"%f",&SetVoltage);
		sscanf(vdata[2].c_str(),"%f",&Kp);
		sscanf(vdata[3].c_str(),"%f",&Ki);
		sscanf(vdata[4].c_str(),"%f",&Kd);

		snprintf(buffer,100,"\n\n\rSet Voltage: %.2f\n\rKp: %.2f\n\rKi: %.2f\n\rKd: %.2f\n\r",SetVoltage,Kp,Ki,Kd);

		p_pid -> PID_Set(SetVoltage, Kp, Ki, Kd);

		return std::string(buffer);
	}

	else{

		return("\n\rNot enough arguments\n\r");

	}
}

std::string SetP::Set_To_Get(){

	char buffer[100] = {};
	snprintf(buffer,100,"\n\n\rSet Voltage: %.2f\n\rKp: %.2f\n\rKi: %.2f\n\rKd: %.2f\n\r",SetVoltage,Kp,Ki,Kd);
	return std::string(buffer);

}


