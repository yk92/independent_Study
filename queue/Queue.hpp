#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cassert>

template <typename T>
class Queue
{
public:
  Queue();
  Queue(const Queue& other);
  ~Queue();

  void Enqueue(T data);
  T Dequeue();
  
  bool IsEmpty() const { ( mFront == mBack ) ? return true : return false; }
  T Front() const;

  Queue& operator=(const Queue& other);

private:
  struct Node
  {
    T data;
    Node* next;
  };

  Node* mFront;
  Node* mBack;
};

#endif
