#include "UnsortedType.hpp"

UnsortedType::UnsortedType()
{
  mLength = 0;
}

bool UnsortedType::IsFull() const
{
  return ( mLength == kMax_Items );
}

int UnsortedType::LengthIs() const
{
  return mLength;
}

void UnsortedType::RetrieveItem(ItemType& item, bool& found)
{
  /* Pre: Key member(s) of item is/are initialized.
     Post: If found, item's key matches an element's ket in the
           list and a copy of that element has been stored in item,
           otherwise, item is unchanged */
  
  bool moreToSearch;
  int location = 0;
  found = false;

  moreToSearch = (location < mLength);

  while ( moreToSearch && !found ) {  //linear search
    
    switch ( item.ComparedTo(info[location])) {
      
      case LESS    :
      case GREATER :
        location++;
        moreToSearch = (location < length);
        break;
      case EQUAL   :
        found = true;
        item = info[location]; //copy not direct access
        break;
    }
  }
}

void UnsortedType::InsertItem(ItemType item)
{
  // Post: item is in the list.
  
  info[mLength] = item;
  mLength++;
}

void UnsortedType::DeleteItem(ItemType item)
{
  /* Pre: item's key has been initialized.
          an element in the list has a key that matches item's.
     Post: No element in the list has a key that matches item's. */
  
  int location = 0;
  
  //search through the list for item to be deleted key
  while ( item.ComparedTo(info[location] != EQUAL ) {
    location++;
  }
  
  //swap the last item with the item to be deleted
  info[location] = info[mLength - 1];
  
  //decrement list length
  mLength--;
}

void UnsortedType::ResetList()
{
  // Post: mCurrentPos has been initialized.

  mCurrPos = -1;
}

void UnsortedType::GetNextItem(ItemType& item)
{
  /* Pre: No transformer operation has been executed since last call.
     Post: Item is current item
           mCurrPos has been updated. */

  mCurrPos++;
  item = info[mCurrPos];
}



