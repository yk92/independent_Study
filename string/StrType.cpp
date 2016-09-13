#include <cctype>
#include <cstring>

/* Prototypes of auxiliary functions.

   Note: If skip is true, nonallowable leading chars
         are skipped. If end-of-file is encountered
         while skipping chars, the empty string is 
         returned. If the number of allowable chars
         exceeds kMax_Chars, the rest are read and
         discarded.
/*

void GetAlphaNum(bool skip, char letters[], std::ifstream& inFile);
//Post: letters array contains only alphanumeric chars

void GetAlpha(bool skip, char letters[], std::ifstream& inFile);
//Post: letters array contains only alphabetic chars

void GetNonWhite(bool skip, char letters[], std::ifstream& inFile);
//Post: letters array contains only nonwhitespace chars

void GetTilNew(bool skip, char letters[], std::ifstream& inFile);
//Post: letters array contains everything up to newline char

void StrType::GetStringFile(bool skip, InType charsAllowed, std::ifstream& inFile)
{
  switch (charsAllowed) {
    
    case ALPHA_NUM : GetAlphaNum(skip, letters, inFile);
		     break;
    case ALPHA     : GetAlpha(skip, letters, inFile);
		     break;
    case NON_WHITE : GetNonWhite(skip, letters, inFile);
		     break;
    case NOT_NEW   : GetTilNew(skip, letters, inFile);
                     break; 
  }
}

void GetAlphaNum(bool skip, char letters[], std::ifstream& inFile)
/* Post: If skip is true, non alphanumeric letters are skipped
	 Alphanumeric chars are read and stored until a non-alpha
	 char is read or kMax_Chars chars have been stored.
	 If the stream is not in the fail state the last char read
	 was a non-alphanumeric char.
*/
{
  using namespace std;
  char letter;
  int count = 0;
  
  if (skip) {
    //skip non-alphanumeric chars
    inFile.get(letter);
    while (!isalnum(letter) && inFile)
      inFile.get(letter);
  }
  else
    inFile.get(letter);
  if (!inFile || !isalnum(letter))
    //no legal char found - empty string returned
    letters[0] = '\0';
  else {
    //read and collect letters
    do {
      letters[count] = letter;
      count++;
      inFile.get(letter);
    } while (isalnum(letter) && inFile && (count < kMax_Chars));

    letters[count] = '\0';
  
    //skip extra chars if necessary
    if (count == kMax_Chars && isalnum(letter))
      do {
        inFile.get(letter);
      } while (isalnum(letter) && inFile);
  }
}

void GetTilNew(bool skip, char letters[], std::ifstream& inFile)
/* Post: If skip is true, newline chars are skipped.
         All chars are read and stored until a newline
         char is read or KMax_Chars chars have been
         stored. If the stream is not in fail state, the
         last char read was a newline char.
*/
{
  using namespace std;
  char letter;
  int count = 0;
  
  if (skip) {
    //skip newlines
    inFile.get(letter);
    while ((letter == '\n') && inFile)
      inFile.get(letter);
  }
  else
    inFile.get(letter);
  
  if (!inFile || letter == '\n')
    letters[0] = '\0';
  else {
    //read and collect chars
    do {
      letters[count] = letter;
      count++;
      inFile.get(letter);
    } while ((letter != '\n') && inFile && (count < kMax_Chars));
  
    letters[count] = '\0';
  
    if (count == kMax_Chars && letter != '\n')
      do {
        inFile.get(letter);
      } while ((letter != '\n') && inFile);
  }
}

// STILL NEED TO WRITE GetAlpha and GetNonWhite *************

//STILL NEED TO WRITE GetString

void StrType::PrintToScreen(bool newLine)
// Post: letters has been sent to the output stream.
{
  using namespace std;
  if (newLine) 
    cout << endl;
  cout << letters;
}

void StrType::PrintToFile(bool newLine, std::ofstream& outFile)
// Post: letters has been sent to file
{
  using namespace std;
  if (newLine)
    outFile << endl;
  outFile << letters;
}

void StrType::CopyString(StrType& newString)
// Post: letters has been copied to newString.letters
{
  std::strcpy(newString.letters, letters);
}

int StrType::LengthIs()
//Post: Function value = length of letters string
{
  return std::strlen(letters);
}

    
