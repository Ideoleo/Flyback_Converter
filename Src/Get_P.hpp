/*
 * GetP.hpp
 *
 *  Created on: 16 paź 2019
 *      Author: admin
 */

#ifndef GETP_HPP_
#define GETP_HPP_

#include "Command_Interface.hpp"
#include <string>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


class GetP : public CommandInterface{

public:

	GetP();
	~GetP();
	virtual std::string Execute(const std::vector<std::string>&);


private:




};



#endif /* GETP_HPP_ */
