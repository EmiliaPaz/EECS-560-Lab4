/*
  File Name: Executive.h
  Author: Emilia Paz Ojeda
  KUID: 2889275
  Email Address: emilia.paz@ku.edu
  Description: Header file for the executive class that creates a hash table
  Last Changed: February 4th, 2019
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "HashTable_Open.h"
#include "HashTable_Closed.h"


class Executive
{
    public:
        /*
            pre:    none
            post:   initialiazes every variable
            param:  file name
        */
        Executive(char* fileName);
        /*
            pre:    variables initialized
            post:   destroys everything located in the heap
            param:  none
        */
        ~Executive();
        /*
            pre:    none
            post:   prints the menu and implements the correct option
            param:  none
        */
        void printMenu();

        void printGrid(float** grid, int m);

        void deleteGrid(float** grid);

    private:


} ;

#endif
