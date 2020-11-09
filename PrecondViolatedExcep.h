/***************************************************************************
*
*	Author: Michael Thomas
*
*	Program: PrecondViolatedExcep.h
*
*	Purpose: exception file for BinaryNodeTree source code/class definitions
*
*	Version: 1.00	
*
*	Notes: 
*
*
*************************************************************************/
#include <iostream>
#include <stdexcept>
#include <string>

#ifndef PRECOND_VIOLATED_EXCEP

#define PRECOND_VIOLATED_EXCEP

using namespace std;

class PrecondViolatedExcep: public logic_error {

public:

	PrecondViolatedExcep(const string& message = "");

}; 
#endif
