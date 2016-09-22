#include "LinkedList.hpp"
#include <iostream>

template<class T>
LinkedList<T>::LinkedList()
  : first(NULL), last(NULL), mSize(0) { }

template<class T>
LinkedList<T>::~LinkedList()
{

  Node<T>* temp = first;
 
  while ( !empty() ) {
    temp = temp->next;
    delete(first);
    first = temp;
  }
}

template<class T>
void LinkedList<T>::insertAtBack(const T& item)
{
  mSize++;
  Node<T>* newNode;
  newNode->val = item;
  newNode->next = NULL;

  Node<T>* temp = first;

  if (temp != NULL) {
    while ( temp->next != NULL )
      temp = temp->next;

    temp->next = newNode;
  } else { first = newNode; } 
}

template<class T>
bool LinkedList<T>::removeFromBack() const
{
  if (first == NULL)
    return false;

  if (first == last){
    std::cout << "First is equal to last" << std::endl;
    delete(first);
    first = last = NULL;
    return true;
  } else {
    
    Node<T>* temp = first;
    int nodeCnt = 0;

    while ( temp != NULL ) {
      nodeCnt++;
      temp = temp->next;
    }

    Node<T>* temp2 = first;

    for (int i = 1; i < nodeCnt - 1; i++)
      temp2 = temp->next;
    
    std::cout << temp2->val << std::endl;
    delete(temp2->next);

    last = temp2;
    last->next = NULL;
    mSize--;
    return true;
  }
}

template<class T>
void LinkedList<T>::print()
{
  Node<T>* temp = first;

  while (temp != NULL) {
    std::cout << temp->val;
    temp  = temp->next;
    std::cout << " ";
  }
}

template<class T>
bool LinkedList<T>::empty() const
{ return (first == NULL); }

template<class T>
int LinkedList<T>::size() const
{ return mSize; }

template<class T>
void LinkedList<T>::clear()
{
  Node<T>* temp = first;

  while (temp != NULL) {
    temp = temp->next;
    first = temp;
    delete(temp);
  }
}

template<class T>
void LinkedList<T>::insertAtFront(const T& item)
{
  mSize++;
  if(first == NULL)
    first->val = item;
  else {
    Node<T>* newNode;
    newNode->val = item;
    newNode->next = first;
    first = newNode;
  }
}

template<class T>
bool LinkedList<T>::removeFromFront() const
{
  if ( first == NULL )
    return false;
  else {
    Node<T>* temp;
    temp = first;
    first = first->next;

    delete(temp);
    mSize--;
    return true;
  }
}


