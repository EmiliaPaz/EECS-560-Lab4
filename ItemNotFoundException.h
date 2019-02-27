/*
  File Name: Browser.h
  Author: Emilia Paz Ojeda
  KUID: 2889275
  Email Address: e155p319@ku.edu
  Assignment: Lab 3
  Description: Header file for the exception handling
  Last Changed: February 4th, 2019
*/


#ifndef ITEM_NOT_FOUND_EXCEPTION_H
#define ITEM_NOT_FOUND_EXCEPTION_H
#include <string>
#include <stdexcept>
using namespace std;


class ItemNotFoundException: public runtime_error
{
  public:
    /*
        pre:    none
        post:   if the exception happens, catches the message
        param:  string thaat is the message to show when the exception is catched
    */
    ItemNotFoundException(string msg) ;

} ;

#endif
