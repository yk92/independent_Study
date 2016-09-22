namespace myVect {
  
  template<typename Item_Type>
    class Vector {

      private:
        //Data fields

        /** The initial capacity of the array */
        static const size_t kInitial_Capacity = 10;

        /** The current capacity of the array */
        size_t mCurr_Cap;

        /** The current number of items of the array */
        size_t mNum_Items;

        /** The array to contain the data */
        Item_Type* mData;

      public:
        // Member functions
        /** Constructs an empty vector with the default initial capacity */
        Vector<Item_Type>() : mCurr_Cap(kInitial_Capacity),
          mData(new Item_Type[kInitial_Capacity]), mNum_Items(0) { }

        /** Exchanges the contents of this vector with another
          @param other The other vector
        */
        void swap(Vector<Item_Type& other);
        
        /** Operator[] function
            @param index The index to operate on
        */
        Item_Type& operator&[](size_t index);

        /** push_back function adds new value to end of vector
            @param the_value The new value to be added
        */
        void push_back(const Item_Type& the_value);

        /** insert function - inserts a new item into vector at index
            @param index The index to insert item at
            @param the_value The value to insert at index
        */
        void insert(size_t index, const Item_Type& the_value);

        /** erase function - erases an item at index
            @param index The index for item to erase
        */
        void erase(size_t index);

        /** reserve function - creates new array double the size of current
                               and copies items to new array
            @param new_capacity The capacity of new array
        */
        void reserve(size_t new_capacity);
        
        /** make a copy of a vector
            @param other The vector to be copied
        */
        Vector<Item_Type>(const Vector<Item_Type>& other);

        /** Assign the contents of one vector to another
            @param other The vector to be assigned to this vector
            @return This vector with a copy of the other vector's contents
        */
        Vector<Item_Type>& operator=(const Vector<Item_Type>& other);

        /** Destructor for Vector object */
        ~Vector() { delete[] mData; }
    };
};
  
