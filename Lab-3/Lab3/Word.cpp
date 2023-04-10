#include "Word.h"

Word::Word() {
    word = "";
}

void Word::SetWord(string received_word) {
    word = received_word;
}

string Word::GetWord() {
    return word;
}

int Word::GetSize() {
    return (int)word.size();
}

void Word::ShowWord() const {
    cout<<"Word: "<<word<<" Size: "<<word.size()<<endl;
}
