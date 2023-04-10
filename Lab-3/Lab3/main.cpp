#include "MainFunctions.h"

int main() {
    int size_of_array = GetSize();
    Word words[size_of_array];

    FillArray(words,size_of_array);
    PrintArray(words,size_of_array);
    FindMax(words,size_of_array);

    return 0;
}
