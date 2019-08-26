/*
 * PID_service.hpp
 *
 *  Created on: Aug 7, 2019
 *      Author: MKoza1
 */

#ifndef PID_SERVICE_HPP_
#define PID_SERVICE_HPP_
#include <cstdint>

class PID{

public:

	PID(float time_,float max_,float min_, float Kp_, float Ki_, float Kd_);
	~PID();

	void Proportional_fun();
	void Error_fun(float);
	void Integral_fun();
	void Derivative_fun();
	float PID_Control(float Set_Voltage, float Voltage);


private:


	float time;
	float max;
	float min;
	float Kp, Ki, Kd;
	float Proportional,Integral,Derivative;
	float PreError;
	double ErrorSum;

};




#endif /* PID_SERVICE_HPP_ */
