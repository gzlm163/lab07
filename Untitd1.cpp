#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  ifstream file("file.txt");
  if (file.is_open() == 0) {
    cout << "Error of open" << endl;
  } else {
    string text;
    
    getline(file, text);
    
    file.close();

    int letters[26];
    int combinations[26][26];

    char previousLetter;
    
    previousLetter = ' ';

    for (int firstIndex = 0; firstIndex < 26; ++firstIndex) {
      letters[firstIndex] = 0;
      
      for (int secondIndex = 0; secondIndex < 26; ++secondIndex) {
        combinations[firstIndex][secondIndex] = 0;
      }
    }

    for (int positionIndex = 0; position < text.length(); ++positionIndex) {
      char currentLetter;
      
      currentLetter = text[positionIndex];
      
      if (isalpha(currentLetter)) {
        int letterNumber;
        
        currentLetter = tolower(currentLetter);
        
        letterNumber = currentLetter - 'a';
        ++letters[letterNumber];
        
        if (isalpha(previousLetter)) {
          char previousLetterLower;
          int previousLetterNumber;
          
          previousLetterLower = tolower(previousLetter);
          
          previousLetterNumber = previousLetterLower - 'a';
          ++combinations[previousLetterNumber][letterNumber];
        }
        
        previousLetter = currentLetter;
        
      } else {
        previousLetter = ' ';
        }
    }

    for (int letterIndex = 0; letterIndex < 26; ++letterIndex) {
      if (letters[letterIndex] > 0) {
        char currentLetter;
        
        currentLetter = 'a' + letterIndex;
        
        cout << "Number of letters " << currentLetter << " = " << letters[letterIndex] << endl;
      }
    }
    
    cout << endl;
    
    for (int firstLetterIndex = 0; firstLetterIndex < 26; ++firstLetterIndex) {
      for (int secondLetterIndex = 0; secondLetterIndex < 26; ++secondLetterIndex) {
        if (combinations[firstLetterIndex][secondLetterIndex] > 0) {
          char firstLetter;
          char secondLetter;
          
          firstLetter = 'a' + firstLetterIndex;
          secondLetter = 'a' + secondLetterIndex;
          
          cout << "Combination of letters " << firstLetter << secondLetter << " = " << combinations[firstLetterIndex][secondLetterIndex] << endl;
        }
      }
    }
  }

  return 0;
}
