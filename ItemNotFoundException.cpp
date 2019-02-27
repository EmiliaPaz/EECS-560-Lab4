/*
  File Name: Browser.h
  Author: Emilia Paz Ojeda
  KUID: 2889275
  Email Address: e155p319@ku.edu
  Assignment: Lab 3
  Description: Cpp file for the exception handling
  Last Changed: February 4th, 2019
*/



#include <iostream>
#include <string>
#include "ItemNotFoundException.h"

ItemNotFoundException::ItemNotFoundException(std::string msg) :runtime_error(msg)
{

}
