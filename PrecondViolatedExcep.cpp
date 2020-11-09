/***************************************************************************
*
*	Author: Michael Thomas
*
*	Program: PrecondViolatedExcep.cpp
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
#include "PrecondViolatedExcep.h"

PrecondViolatedExcep::PrecondViolatedExcep(const string& message): logic_error("Precondition Violated Exception: " + message)
{	
	
} 