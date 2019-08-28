/*
 * Console_service.hpp
 *
 *  Created on: Jul 17, 2019
 *      Author: MKoza1
 */

#ifndef CONSOLE_SERVICE_HPP_
#define CONSOLE_SERVICE_HPP_
#include <fstream>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <vector>
#include "cmsis_os.h"
#include "main.h"
#include "Command_Interface.hpp"
#include "PWM_service.hpp"
#include <map>
#include <utility>


class UartCom{

public:

	UartCom(uint8_t Enter_,const std::map<string,CommandInterface*>&);
	~UartCom();

	void UART_Rec_Sign(uint8_t Data_RC);
	void UART_Build_String();
	std::vector<std::string> UART_Tok(char* MEMDataToSend,const char* const StrFind);
	void UART_Class_VPRINT(std::vector<std::string> vdata);
	void UART_Printf(const char* Txt, float Value1, float Value2);
	void UART_Printf(const char* Txt, float Value1);
	void UART_Printf(const char* Txt, const char* str);
	void UART_Printf(const char* Txt);
	void UART_Interface();

private:

	char DataToSend[256];
	char MEMDataToSend[128];
	uint8_t i;
	const uint8_t Enter;
	osMessageQId Console_Rx_Handle;
	std::map<std::string,CommandInterface*> Command_map;
	std::map<string,CommandInterface*>::iterator it;


};




#endif /* CONSOLE_SERVICE_HPP_ */
