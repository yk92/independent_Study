#include "my_vector.hpp"

using namespace myVect;

/** Exchanges the contents of this vector with another
    @param other The other vector
*/
void swap(vector<Item_Type>& other) {
  std::swap(mNum_Items, other.mNum_Items);
  std::swap(mCurr_Cap, other.mCurr_Cap);
  std::swap(mData, other.mData);
}

/** Operator [] access vector at index
    @param index The index to access vector at
*/
Item_Type& operator[](size_t index) {
  //Verify that the index is legal
  if (index < 0 || index >= mNum_Items) {
    throw std::out_of_range ("index to operator[] is out of range");
  }

  return mData[index];
}

/** push_back function Adds a new item to end of vector
    @param the_value Value of item to add
*/
void push_back(const Item_Type& the_value) {
  //make sure there is space for the new item.
  if (mNum_Items == mCurr_Cap) {
    reserve(2 * mCurr_Cap);
  }
  // Insert the new item
  mData[mNum_Items] = the_value;
  mNum_Items++;
}

/** The insert function inserts a new value at index
    @param index The index at which to insert the new value
    @param the_value The value to insert at index
*/
void insert(size_t indez, const Item_Type& the_value) {
  //validate index
  if (index > mNum_Items) {
    throw std::out_of_range ("index to insert is out of range");
  }
  //Ensure that there is space for the new item
  if (mNum_Items == mCurr_Cap) {
    reserve(2 * mCurr_Cap);
  }

  //Move the data from index to mNum_Items - 1 down/
  for (size_t i = mNum_Items; i > index; i--) {
    mData[i] = mData[i - 1];
  }

  //Insert the new item.
  mData[index] = the_value;
  mNum_Items++;
}

/** erase function removes an item and moves up any items after it
    @param index The index of item to remove
*/
void erase(size_t index) {
  //Validate the index.
  if (index > mNum_Items) {
    throw std::out_of_range ("index to insert is out of range");
  }
  //Move items below the removed one up.
  for (size_t = index + 1; i < mNum_Items; i++) {
    mData[i + 1] = mData[i];
  }
  mNum_Items--;
}

void reserve(size_t new_capacity) {
  if (new_capacity > mCurr_Cap) {
    if (new_capacity > 2 * mCurr_Cap)
       mCurr_Cap = new_capacity;
    else
      mCurr_Cap *= 2;
    Item_Type* new_data = new Item_Type[mCurr_Cap];
    //copy the data over.
    for (size_t i = 0; i < mNum_Items; i++)
       new_data[i] = mData[i];
    //free the memory occupied by the old copy.
    delete[] mData;
    // now point to the new data
    the_data = new_data;
  }
}


