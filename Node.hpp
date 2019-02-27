#include <iostream>

////////////////////////////////////////////////////////////////////////////////
//////////                   Constructors                             //////////
////////////////////////////////////////////////////////////////////////////////
template<class T>
Node<T>::Node()
{
  m_next = nullptr ;
}

template<class T>
Node<T>::Node(const T item)
{
  m_item = item ;
  m_next = nullptr ;
}

template<class T>
Node<T>::Node(const T item, Node<T>* nextNodePtr)
{
  m_item = item ;
  m_next = nextNodePtr ;
}


////////////////////////////////////////////////////////////////////////////////
//////////                       Methods                              //////////
////////////////////////////////////////////////////////////////////////////////
template<class T>
void Node<T>::setItem(const T& item)
{
  m_item = item ;
}

template<class T>
T Node<T>::getItem() const
{
  return(m_item) ;
}


template<class T>
void Node<T>::setNext(Node<T> * next)
{
  m_next = next ;
}

template<class T>
Node<T> * Node<T>::getNext() const
{
  return(m_next) ;
}
