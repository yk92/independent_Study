#ifndef DLINKED_LIST_HPP
#define DLINKED_LIST_HPP

#include <cstddef>
#include <iostream>

template<class ItemType>
struct Node{
  ItemType elem;
  Node<ItemType>* next;
  Node<ItemType>* prev;
};

template<class ItemType>
class DLinkedList {
  public:
    DLinkedList();
    ~DLinkedList();
    bool empty() const;
    const ItemType& front() const;
    const ItemType& back() const;
    const ItemType& getItem(const ItemType& item) const;
    void addFront(const ItemType& item);
    void addBack(const ItemType& item);
    void removeFront();
    void removeBack();
    void print();
  private:
    Node<ItemType>* head;
    Node<ItemType>* tail;
};



#endif

