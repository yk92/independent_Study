#include "SLinkedList.hpp"
#include <cstddef>

template<class ItemType>
SLinkedList<ItemType>::SLinkedList()
  : head(NULL) { }

template<class ItemType>
bool SLinkedList<ItemType>::empty() const
{
  return head == NULL;
}

template<class ItemType>
const ItemType& SLinkedList<ItemType>::front() const
{
  return head->elem;
}

template<class ItemType>
SLinkedList<ItemType>::~SLinkedList()
{
  while ( !empty() )
    removeFront();
}

template<class ItemType>
void SLinkedList<ItemType>::addFront(const ItemType& item)
{
  Node<ItemType>* temp = new Node<ItemType>;
  temp->elem = item;
  temp->next = head;
  head = temp;
}

template<class ItemType>
void SLinkedList<ItemType>::removeFront()
{
  Node<ItemType>* old = head;
  head = old->next;
  delete old;
}

/* Missing overloaded operators, copy constructor, etc */


