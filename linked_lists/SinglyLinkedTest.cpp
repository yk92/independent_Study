#include "SLinkedList.hpp"
#include <iostream>

int main()
{
  SLinkedList<int> intList;
  intList.addFront(5);
  intList.addFront(10);

  if (intList.empty())
    std::cout << "Empty List..." << std::endl;

  std::cout << "the front element is " << intList.front();

  return 0;
}
