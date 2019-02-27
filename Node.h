/*
  File Name: Node.h
  Author: Emilia Paz Ojeda
  KUID: 2889275
  Email Address: emilia.paz@ku.edu
  Description: Header file of Node. Methos to create the node, and get and set its values and next pointers
  Last Changed: January 29th, 2019
*/

#ifndef NODE_H
#define NODE_H
#include <string>

template<class T>
class Node
{
  public:
    /*
        pre:    none
        post:   initialiazes every variable
        param:  none
    */
    Node() ;

    /*
        pre:    non
        post:   sets the item
        param:  item to create the Node
    */
    Node(const T item) ;

    /*
        pre:    none
        post:   sets the item and the pointer to the next node
        param:  item to create the node, pointer to the next node
    */
    Node(const T item, Node<T>* nextNodePtr) ;

    /*
        pre:    none
        post:   sets the item of the node
        param:  item to set the node
    */
    void setItem(const T& item) ;

    /*
        pre:    node exists
        post:   gets the item of the node
        param:  none
    */
    T getItem() const ;

    /*
        pre:    none
        post:   sets the pointer to the next node
        param:  pointer to set the next node
    */
    void setNext(Node<T> * next) ;

    /*
        pre:    node exists
        post:   gets the pointer of the next node
        param:  none
    */
    Node<T> * getNext() const ;
  private:
    T m_item;
    Node<T> * m_next ;
} ;

#include "Node.hpp"
#endif
