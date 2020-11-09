/***************************************************************************
*
*	Author: Michael Thomas
*
*	Program: NotFoundException.cpp
*
*	Purpose: not found exception source file for BinaryNodeTree source code/class definitions
*
*	Version: 1.00	
*
*	Notes: not found exception to be used in BinaryTreeInterface.h
*
*
*************************************************************************/
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include "NotFoundException.h"

using namespace std;

NotFoundException::NotFoundException(const string& message)
	{
		logic_error("Precondition Violated Exception: " + message);
	}

