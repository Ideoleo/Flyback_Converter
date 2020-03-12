/*
 * PID_service.hpp
 *
 *  Created on: Aug 7, 2019
 *      Author: MKoza1
 */

#ifndef PID_SERVICE_HPP_
#define PID_SERVICE_HPP_
#include <cstdint>
#include <cstdio>

class PID{

public:

	PID(float time_, float Kp_, float Ki_, float Kd_);
	~PID();

	void Proportional_fun();
	void Error_fun(float);
	void Integral_fun();
	void Derivative_fun();
	float PID_Control(float Voltage);
	void PID_Set(float,float,float,float);


private:


	float time;
	float time_d;
	float time_i;
	float max;
	float min;
	float Kp, Ki, Kd;
	float Proportional,Integral,Derivative;
	float PreError;
	float Set_Voltage;
	float ErrorSum;

};




#endif /* PID_SERVICE_HPP_ */
