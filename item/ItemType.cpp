#include <fstream>
#include "ItemType.hpp"

ItemType::ItemType()
{
  mValue = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const
{
  if (mValue < otherItem.mValue)
    return LESS;
  else if (mValue > otherItem.mValue)
    return GREATER;
  else return EQUAL;
}

void ItemType::Initialize(int number)
{
  mValue = number;
}

void ItemType::Print(std::ofstream& out) const
{
  out << mValue << " ";
}


