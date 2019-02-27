/*
  File Name: Executive.h
  Author: Emilia Paz Ojeda
  KUID: 2889275
  Email Address: emilia.paz@ku.edu
  Description: Header file for the executive class that creates a hash table
  Last Changed:
*/

#ifndef HASHTABLE_OPEN_H
#define HASHTABLE_OPEN_H
#include "LinkedList.h"

template<class T>
class HashTable_Open
{
    public:
        HashTable_Open(int size);
        ~HashTable_Open();
        bool insert(T key);
        bool remove(T key);
        int find(T key);
        void print();
        int hash(T key);
        void rehash();
        void find();
        bool isPrime(int n);

    private:
        int numBuckets;
        int numKeys;
        LinkedList<T> ** array;

};

#include "HashTable_Open.hpp"
#endif
