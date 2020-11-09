/***************************************************************************
*
*	Author: Michael Thomas
*
*	Program: NotFoundException.h
*
*	Purpose: not found exception header file for BinaryNodeTree source code/class definitions
*
*	Version: 1.00	
*
*	Notes: 
*
*
*************************************************************************/
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

#ifndef NOT_FOUND_EXCEPTION

#define NOT_FOUND_EXCEPTION

using namespace std;

class NotFoundException {

public:

	NotFoundException(const string& message = "");

}; 
#endif