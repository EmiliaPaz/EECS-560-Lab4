/*
  File Name: Executive.h
  Author: Emilia Paz Ojeda
  KUID: 2889275
  Email Address: emilia.paz@ku.edu
  Description: Header file for the executive class that creates a hash table
  Last Changed:
*/

#ifndef HASHTABLE_CLOSED_H
#define HASHTABLE_CLOSED_H
#include "ItemNotFoundException.h"

template<class T>
class HashTable_Closed
{
    public:
        ///////////////  Constructors  ///////////////
        HashTable_Closed(int size, char t, int R_value, int k_value);
        ///////////////   Destructor   ///////////////
        ~HashTable_Closed();
        ///////////////    Methods     ///////////////
        bool insert(T key);
        bool remove(T key);
        bool find(T key);
        void print();
        /////////////// Helper Methods ///////////////
        int hash(T key);
        void rehash();
        bool isPrime(int n);


    private:
        int numBuckets;
        int numKeys;
        char type;
        int R;
        int k;
        T* array;
};

#include "HashTable_Closed.hpp"
#endif
