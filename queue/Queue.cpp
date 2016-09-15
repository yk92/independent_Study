#include "Queue.hpp"

template <typename T>
Queue<T>::Queue()
{
  mFront = new Node();
  mBack = mFront;
} 

template <typename T>
Queue<T>::Queue(const Queue<T>& other)
{
  mFront = new Node();
  mBack = mFront;
  Node* temp  = other.mFront;

  while ( temp != other.mBack ) {
    Enqueue(temp->data);
    temp = temp->next;
  }
}

template <typename T>
Queue::~Queue()
{
  while ( !IsEmpty() ) { Dequeue(); }
}

template <typename T>
void Queue<T>::Enqueue(T data)
{
  mBack->data = data;
  mBack->next = new Node();
  mBack = mBack->next;
}

template <typename T>
T Queue<T>::Dequeue()
{
  assert( !IsEmpty() );
  
  Node* temp = mFront;
  T data = mFront->data;
  mFront = mFront->next;
  
  delete temp;
  return data;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
  if ( this != other ) {
    Node* temp = other.mFront;
  
    while ( !IsEmpty() ) { Dequeue(); }
    while ( temp != other.mBack ) {
      Enqueue( temp->data );
      temp = temp->next;
    }
  }
  
  return *this;
}

template <typename T>
T Queue<T>::Front() const
{
  return mFront->data;
}
