#include "Console_service.hpp"
#include <cstdarg>
#include "Set_P.hpp"
using namespace std;




extern UART_HandleTypeDef huart3;

UartCom::UartCom(uint8_t Enter_, const std::map<string,CommandInterface*>& Command_map)	//Konstruktor
:Enter(Enter_),Command_map(Command_map)
{
	i = 0;

	osMessageQDef(Console_Rx, 16, uint32_t);
	Console_Rx_Handle = osMessageCreate(osMessageQ(Console_Rx), NULL);


}

UartCom::~UartCom(){				//Destruktor

}


void UartCom::UART_Rec_Sign(uint8_t RC_Data){

	osMessagePut(Console_Rx_Handle, RC_Data, 0);

}

void UartCom::UART_Build_String(){


	osEvent evt;
	uint32_t Uart_rec_value;


	evt = osMessageGet(Console_Rx_Handle, osWaitForever);
	Uart_rec_value = evt.value.v;


	 if (Uart_rec_value == Enter){

			 std::vector<std::string>* vec_data;		//wektor dla tokenow

			 DataToSend[i] = 0;

			 i = 0;

			vec_data = UART_Tok(DataToSend, " ");	//podziel na tokeny

			if(vec_data->size() > 0){


					it = Command_map.find((*vec_data)[0]);

					if(it != Command_map.end()){

							Output = it->second->Execute(*vec_data);



					}
					else{

						printf("\n\rCannot find this function\n\r");
						printf("\n\r");

					}



				}

			delete vec_data;
		 }

		 else{

			 DataToSend[i] = Uart_rec_value;		//wpisz kolejne znaki do bufora
			 HAL_UART_Transmit(&huart3, reinterpret_cast<uint8_t*>(&DataToSend[i]), 1, HAL_MAX_DELAY); // Console Echo
			 i++;

		 }


}

void String_From_Func(){




}

std::vector<std::string>* UartCom::UART_Tok(char* MEMDataToSend, const char* const StrFind){

	std::vector<std::string>* vdata = new std::vector<std::string>;
	char *WordToFind;
	WordToFind = strtok(MEMDataToSend,StrFind);


	while(WordToFind != NULL){
		char* test = new char[10];
		delete[] test;
		string temp(WordToFind,4);
		vdata->push_back (temp);
		WordToFind = strtok(NULL,StrFind);

	}

	return vdata;


}

void UartCom::UART_Class_VPRINT(std::vector<std::string> vdata){

	for(unsigned int i = 0; i < vdata.size(); i++){

			UART_Printf("%s \n\r",vdata[i].c_str());

		}

}


void UartCom::UART_Interface(){

	while(1){

		UART_Build_String();

	}


}


void UartCom::UART_Printf(const char* Txt, float Value1, float Value2){


	static uint8_t data[50];
	uint16_t size = 0;


	size = sprintf(reinterpret_cast<char*>(data),Txt,Value1,Value2);
	HAL_UART_Transmit(&huart3, data, size, HAL_MAX_DELAY);

}

void UartCom::UART_Printf(const char* Txt, float Value1){



	static uint8_t data[50];
	uint16_t size = 0;


	size = sprintf(reinterpret_cast<char*>(data),Txt,Value1);
	HAL_UART_Transmit(&huart3, data, size, HAL_MAX_DELAY);

}

void UartCom::UART_Printf(const char* Txt, const char* str){


	static uint8_t data[50];
	uint16_t size = 0;


	size = sprintf(reinterpret_cast<char*>(data),Txt,str);
	HAL_UART_Transmit(&huart3, data, size, HAL_MAX_DELAY);

}

void UartCom::UART_Printf(const char* Txt){


	static uint8_t data[150];
	uint16_t size = 0;


	size = sprintf(reinterpret_cast<char*>(data),Txt);
	HAL_UART_Transmit(&huart3, data, size, HAL_MAX_DELAY);

}



