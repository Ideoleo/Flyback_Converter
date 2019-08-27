/*
 * Set_P.hpp
 *
 *  Created on: Aug 26, 2019
 *      Author: MKoza1
 */
#ifndef SET_P_HPP_
#define SET_P_HPP_

#include "Command_Interface.hpp"
#include "PID_service.hpp"
#include "Console_service.hpp"
#include <cstdint>
#include <cstdio>
#include <string>

using namespace std;

class SetP : public CommandInterface{

public:

	SetP(PID* const);
	virtual ~SetP();
	virtual std::string Execute(const std::vector<std::string>&);


private:


	PID* const p_pid;
	float Kp,Ki,Kd,Time,SetVoltage;

};


#endif /* SET_P_HPP_ */
