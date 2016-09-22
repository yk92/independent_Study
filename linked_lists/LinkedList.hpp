#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#define NULL 0;

template<class T>
struct Node
{
  T val;
  Node<T>* next;
};

template<class T>
class LinkedList
{
  public:
    LinkedList();
    ~LinkedList();
    void insertAtBack(const T& item);
    bool removeFromBack() const;
    void print();
    bool empty() const;
    int size() const;
    void clear();
    void insertAtFront(const T& item);
    bool removeFromFront() const;
  private:
    int mSize;
    Node<T> *first;
    Node<T> *last;
};

#endif
