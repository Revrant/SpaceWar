/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 04 Space Wars
Date Last Modified: 02/13/2017
File Summary:
------------------------------------------*/
#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
private:
  T m_value;
  Node<T>* m_next;
public:
  Node(T value);
  ~Node();
  T getValue();
  void setNext(Node* next);
  void setValue(T value);
  Node<T>* getNext();
};
#include "Node.cpp"
#endif
