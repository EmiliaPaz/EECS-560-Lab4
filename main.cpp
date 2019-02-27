/*
  File Name: main.cpp
  Author: Emilia Paz Ojeda
  KUID: 2889275
  Email Address: emilia.paz@ku.edu
  Description: gets the command line arguments and creates an object of the executive class
  Last Changed: February 4th
*/

#include <iostream>
#include "Executive.h"

int main(int argc, char* argv[])
{
    Executive *exec = new Executive(argv[1]);
    delete exec;
}
