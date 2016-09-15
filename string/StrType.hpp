//Header file for class StrType, a specification for the String ADT

#include <fstream>
#include <iostream>
const int kMax_Chars = 100;

enum InType {ALPHA_NUM, ALPHA, NON_WHITE, NOT_NEW};

class StrType
{
public:
//Assumptions:

/*
InType is a data type consisting of the following constants:
ALPHA - only alphabetic chars are stored
ALPHA_NUM - only alphanumeric chars are stored
NON_WHITE - all nonwhitespace chars are stored
NOT_NEW - all chars excluding the newline char are stored

If skip is true, chars not allowed are skipped until the first allowed char is found.
Reading and storing begins with this character and continues until a character not
allowed is encountered. This character is read but not stored.

If skip is false, reading and storing begins with the current char in the stream.
*/

  void MakeEmpty();
  void GetString(bool skip, InType charsAllowed);
  /* Post: If the number of allowable characters exceeds kMax_Chars,
           the remaining allowable chars have been read and discarded */

  void GetStringFile(bool skip, InType charsAllowed, std::ifstream& inFile);
/* Post: If the number of allowable chars exceeds kMax_Chars the
         remaining allowable chars have been read and discarded */

  void PrintToScreen(bool newLine);
  void PrintToFile(bool newLine, std::ofstream& outFile);
  int LengthIs();
  void CopyString(StrType& newString);
  bool operator<(StrType otherString) const;
  bool operator==(StrType otherString) const;

private:
  char letters[kMax_Chars + 1];
};
