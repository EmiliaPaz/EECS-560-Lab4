/*
  File Name: LinkedList.h
  Author: Emilia Paz Ojeda
  KUID: 2889275
  Email Address: emilia.paz@ku.edu
  Description: Header file for Linked List.
  Last Changed: February 4th, 2019
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"
#include "ItemNotFoundException.h"

template<class T>
class LinkedList
{
  public:
    /*
        pre:    none
        post:   initialiazes every variable
        param:  none
    */
    LinkedList() ;

    /*
        pre:    variables initialized
        post:   destroys everything located in the heap
        param:  none
    */
    ~LinkedList();

    /*
        pre:    none
        post:   If the insertion is successful, newEntry is inserted at the beginning of the list
        param:  T value of entry
    */
    void insert(const T& newEntry);

    /*
        pre:    none
        post:   If item is in the list the removal is successful
        param:  item of node to remove
    */
    bool remove(T item);

    /*
        pre:    none
        post:   if successful returns the smallest item, else throws an error
        param:  none
    */
    T smallest() throw(ItemNotFoundException);

    /*
        pre:    none
        post:   if successful returns the largest item, else throws an error
        param:  none
    */
    T largest() throw(ItemNotFoundException);

    /*
        pre:    none
        post:   prints the items of the list
        param:  none
    */
    void print();

    /*
        pre:    none
        post:   returns wheter the list is empty or not
        param:  none
    */
    bool isEmpty() const;

    /*
        pre:    none
        post:   removes all the nodes
        param:  none
    */
    void clear();

    /*
        pre:    none
        post:   if successful returns the entry at the given position, else throws an error
        param:  position of the desired entry
    */
    T getEntry(int position) const throw(ItemNotFoundException) ;

    /*
        pre:    none
        post:   returns the number of nodes
        param:  none
    */
    int getSize() const;

    /*
        pre:    none
        post:   returns wether the entry exists or not
        param:  none
    */
    bool findEntry(T item);

  private:
    Node<T> * headPtr ;   // Pointer to first node in the chain, contains the first entry in the list
    int nItems ;          // Current # of items in the list
} ;

#include "LinkedList.hpp"
#endif
