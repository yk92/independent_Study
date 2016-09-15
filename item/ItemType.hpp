#include <fstream>

const int kMax_Items = 5;
enum RelationType {LESS, GREATER, EQUAL};

class ItemType
{
public:
  ItemType();
  RelationType ComparedTo(ItemType) const;
  void Print(std::ofstream&) const;
  void Initialize(int number);
private:
  int mValue;
};
