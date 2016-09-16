#include "SortedType.hpp"

SortedType::SortedType()
{
  mLength = 0;
}

bool SortedType::IsFull() const
{
  return ( mLength == kMax_Items );
}

int SortedType::LengthIs() const
{
  return mLength;
}

void SortedType::RetrieveItem(ItemType& item, bool& found)
{
  /* function: Implement binary search to retrieve item
     Pre: Key member(s) of item is/are initialized.
     Post: If found, item's key matches an element's ket in the
           list and a copy of that element has been stored in item,
           otherwise, item is unchanged */
  
  int midpoint, first;
  midpoint = first = 0;
  int last = mLength - 1;

  bool moreToSearch = (first <= last);
  found = false;

  while ( moreToSearch && !found ) {  //binary search
    
    switch ( item.ComparedTo(info[midpoint])) {
      
      case LESS    :
	last =  midpoint - 1;
	moreToSearch = (first <= last);
	break;
      case GREATER :
        first = midpoint + 1;
        moreToSearch = (location < length);
        break;
      case EQUAL   :
        found = true;
        item = info[midpoint]; //copy not direct access
        break;
    }
  }
}

void SortedType::InsertItem(ItemType item)
{
  /* Pre: List has been initialized, list is not full,
          Item is not in list and list is sorted by key
          member using the function ComparedTo
  // Post: item is in the list and list is still sorted.
  
  int location = 0;
  bool moreToSearch = (location < mLength);
  
  while (moreToSearch) {
    switch (item.ComparedTo(info[location])) {
      case LESS:
	moreToSearch = false;
	break;
      case GREATER:
	location++;
	moreToSearch = (location < length);
	break;
    }
  }
  
  for (int index = length; index > location; index--)
    info[index] = info[index - 1];
  
  info[location] = item;
  length++; 
}

void SortedType::DeleteItem(ItemType item)
{
  /* Pre: item's key has been initialized.
	  list is sorted by key member using the function
	  ComparedTo
          one and only one element in the list has a key 
	  that matches item's key.
     Post: No element in the list has a key that matches item's. 
	   List is still sorted */
  
  int location = 0;
  
  //search through the list for item to be deleted key
  while ( item.ComparedTo(info[location] != EQUAL ) {
    location++;
  }
  
  for (int index = location + 1; index < length; index++)
    info[index - 1] = info[index];
  
  length--;   
}

void SortedType::ResetList()
{
  // Post: mCurrentPos has been initialized.

  mCurrPos = -1;
}

void SortedType::GetNextItem(ItemType& item)
{
  /* Pre: No transformer operation has been executed since last call.
     Post: Item is current item
           mCurrPos has been updated. */

  mCurrPos++;
  item = info[mCurrPos];
}



