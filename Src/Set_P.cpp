/*
 * Set_P.cpp
 *
 *  Created on: Aug 26, 2019
 *      Author: MKoza1
 */


#include "Set_P.hpp"

SetP::SetP(PID* const p_pid)
:p_pid(p_pid){


}

SetP::~SetP(){


}



std::string SetP::Execute(const std::vector<std::string>& vdata){


	if(vdata.size() >= 5)
	{

		sscanf(reinterpret_cast<const char*>(vdata[1]),"%f",SetVoltage);

		SetVoltage = stof(vdata[1]);
		Kp = stof(vdata[2]);
		Ki = stof(vdata[3]);
		Kd = stof(vdata[4]);

		printf("\n\n\rSet Voltage: %.2f\n\rKp: %.2f\n\rKi: %.2f\n\rKd: %.2f\n\r",SetVoltage,Kp,Ki,Kd);

		p_pid -> PID_Set(SetVoltage, Kp, Ki, Kd);
	}

	else{

		return("\n\rNot enough arguments\n\r");

	}


}
