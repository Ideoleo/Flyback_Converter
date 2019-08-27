/*
 * Command_Interface.hpp
 *
 *  Created on: Aug 26, 2019
 *      Author: MKoza1
 */

#ifndef COMMAND_INTERFACE_HPP_
#define COMMAND_INTERFACE_HPP_

#include <fstream>
#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class CommandInterface{

public:

	virtual ~CommandInterface() = default;
	virtual std::string Execute(const std::vector<std::string>&) = 0;



private:





};


#endif /* COMMAND_INTERFACE_HPP_ */
