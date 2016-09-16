#include "ItemType.hpp"

/* File ItemType.hpp must be provided by the user of this class.
   ItemType.hpp must contain the following definitions:
  
   kMax_Items: the maximum number of items on the list
   ItemType: the definition of the objects on the list
   RelationType: {LESS, GREATER, EQUAL}

   Member function ComparedTo(ItemType item) - which returns:
   
   LESS, if self "comes before" item
   GREATER, if self "comes after" item
   EQUAL, if self and item are the same

*/

class SortedType
{
public:
  SortedType();
  bool IsFull() const;
  int LengthIs() const;
  void RetrieveItem(ItemType& item, bool& found);
  void InsertItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetList();
  void GetNextItem(ItemType& item);
private:
  int mLength;
  ItemType info[kMax_Items];
  int mCurrPos;
};
