#include <iostream>
#include <iomanip>

using namespace std;

class Word {
    string word;
public:
    Word();
    void SetWord(string);
    string GetWord();
    int GetSize();
    void ShowWord() const;
};

