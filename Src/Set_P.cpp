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


	SetVoltage = stof(vdata[1]);
	Kp = stof(vdata[2]);
	Ki = stof(vdata[3]);
	Kd = stof(vdata[4]);
	Time = stof(vdata[5]);

	p_pid -> PID_Set(SetVoltage, Kp, Ki, Kd, Time);


}
