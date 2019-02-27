/*
  File Name: LinkedList.hpp
  Author: Emilia Paz Ojeda
  KUID: 2889275
  Email Address: emilia.paz@ku.edu
  Description:  Methods to interact with the linked list
  Last Changed: February 4th, 2019
*/


#include "LinkedList.h"  // Header file
#include "Node.h"

////////////////////////////////////////////////////////////////////////////////
//////////                     Constructor                            //////////
////////////////////////////////////////////////////////////////////////////////
template<class T>
LinkedList<T>::LinkedList()
{
    headPtr = nullptr ;
    nItems = 0;
}


////////////////////////////////////////////////////////////////////////////////
//////////                     Destructor                             //////////
////////////////////////////////////////////////////////////////////////////////
template<class T>
LinkedList<T>::~LinkedList()
{
    clear();
}


////////////////////////////////////////////////////////////////////////////////
//////////                      Methods                               //////////
////////////////////////////////////////////////////////////////////////////////
template<class T>
void LinkedList<T>::insert(const T& newEntry)
{
    // Create a new node containing the new entry
    Node<T>* newNodePtr = new Node<T>(newEntry);

    if(isEmpty())
    {
        headPtr = newNodePtr;
        nItems++;
    }
    else
    {
        // Save head pointer in a temporaty pointer
        Node<T> * temptPtr = headPtr ;
        // Change head pointer to the new entry pointer
        headPtr = newNodePtr;
        // Set second node to the temporary pointer (old head pointer)
        headPtr->setNext(temptPtr);
        nItems++;
    }
}


template<class T>
bool LinkedList<T>::remove(T item)
{
    bool itemRemoved=false;
    if(!isEmpty())
    {
        if(headPtr->getItem()==item)
        {
            // Save pointer to node to remove
            Node<T>* itemPtr = headPtr;
            // New head
            headPtr = headPtr->getNext();
            // delete node
            delete itemPtr;
            itemRemoved = true;
            nItems--;
        }
        else
        {
            // Node pointer to loop throught the list to find the item
            Node<T>* nodePtr = headPtr;
            int i=1;
            while (itemRemoved==false && i<nItems)
            {
                // Found item
                if (nodePtr->getNext()->getItem()==item)
                {
                    // Save pointer to node to remove
                    Node<T>* itemPtr = nodePtr->getNext();
                    // Assign correct next node
                    nodePtr->setNext(itemPtr->getNext());
                    // Delete node
                    delete itemPtr;
                    nItems--;
                    itemRemoved = true;
                }
                else
                {
                    nodePtr = nodePtr->getNext();
                    i++;
                }
            }
        }
    }
    return itemRemoved;
}


template<class T>
void LinkedList<T>::print()
{
    // Node pointer to loop through the linked list
    if(isEmpty())
    {
        cout << "\n";
    }
    else
    {
        // One node
        std::cout << " -> " << headPtr->getItem();
        // More than one node
        if(nItems>1)
        {
            Node<T>* nodePtr = headPtr->getNext() ;
            for(int i=1; i<nItems; i++)
            {
                std::cout << " -> " << nodePtr->getItem();
                nodePtr = nodePtr->getNext();
            }
        }
        std::cout << "\n";
    }
}


template<class T>
T LinkedList<T>::smallest() throw(ItemNotFoundException)
{
    if(!isEmpty())
    {
        // head value is the first smallest value
        int smallest = getEntry(0) ;
        // get smallest value
        for (int i=1; i<getSize(); i++)
        {
          if(smallest>getEntry(i))
          {
              smallest = getEntry(i) ;
          }
        }
        return smallest;
    }
    else
    {
        throw ItemNotFoundException("Empty list \n");
    }
}

template<class T>
T LinkedList<T>::largest() throw(ItemNotFoundException)
{
    if(!isEmpty())
    {
        // head value is the first smallest value
        int largest = getEntry(0) ;
        // get smallest value
        for (int i=1; i<getSize(); i++)
        {
          if(largest<getEntry(i))
          {
              largest = getEntry(i) ;
          }
        }
        return largest;
    }
    else
    {
        throw ItemNotFoundException("Empty list \n");
    }
}


////////////////////////////////////////////////////////////////////////////////
//////////                   Helper Methods                           //////////
////////////////////////////////////////////////////////////////////////////////
template<class T>
bool LinkedList<T>::isEmpty() const
{
  return(nItems==0);
}


template<class T>
void LinkedList<T>::clear()
{
    Node<T>* curPtr = nullptr;
    while (!isEmpty())
    {
        // Remove the first node in the chain
        curPtr = headPtr; // Save pointer to node
        headPtr = headPtr->getNext();
        delete curPtr;
        curPtr = nullptr;
        nItems--;
    }
}


template<class T>
T LinkedList<T>::getEntry(int position) const throw(ItemNotFoundException)
{
    bool ableToGet = (position >= 0) && (position < nItems);
    // Valid position
    if (ableToGet)
    {
     Node<T>* nodePtr = headPtr ;
     for(int i=0 ; i<position ; i++)
     {
       nodePtr = nodePtr->getNext() ;
     }
     return nodePtr->getItem();
    }
    // Invalid position
    else
    {
     throw ItemNotFoundException("Position doesn't exist in Get Entry \n");
    }
}


template<class T>
int LinkedList<T>::getSize() const
{
    return nItems;
}


template<class T>
bool LinkedList<T>::findEntry(T item)
{
    Node<T>* tempPtr = headPtr;
    for(int i=0; i<nItems; i++)
    {
        if(tempPtr->getItem()==item)
        {
            return true;
        }
        tempPtr = tempPtr->getNext();
    }
    return false;
}
