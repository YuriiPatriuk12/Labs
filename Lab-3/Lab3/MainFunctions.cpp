#include "MainFunctions.h"
int FindAmountOfNumbers(Word word)
{
    int result = 0;
    for (int i = 0; i < word.GetSize(); ++i) {
        if(isdigit(word.GetWord()[i]))
            result++;
    }

    return result;
}

int GetSize()
{
    int result = 0;
    do {
        cout<<"Enter size of array: ";
        cin>>result;
        if(result<=0)
            cout<<"Incorrect size of array!"<<endl;
    }while(result<=0);
    return result;
}
void FillArray(Word words[], int size)
{
    string temp;
    fflush(stdin);
    for (int i = 0; i < size; ++i) {
        cout<<"Enter "<<i+1<<" word: ";
        getline(cin,temp);
        words[i].SetWord(temp);
    }
}
void PrintArray(Word words[], int size)
{
    for (int i = 0; i < size; ++i) {
        words[i].ShowWord();
    }
    cout<<endl;
}
void FindMax(Word words[], int size)
{
    int max = -1,
        index = 0;
    for (int i = 0; i < size; ++i) {
        int temp = FindAmountOfNumbers(words[i]);
        if(max < temp) {
            max = temp;
            index = i;
        }
    }
    cout<<"Word with most digits:"<<endl;
    words[index].ShowWord();
    cout<<"Amount of digits: "<<max<<endl;
}