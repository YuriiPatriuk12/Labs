#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

class OverflowException: public exception{
    char* message = (char*)"Overflow!";
public:
    char* what()
    {
        return message;
    }
};

class NotFoundException: public exception{
    char* message = (char*)"Element wasn't found!";
public:
    char* what()
    {
        return message;
    }
};

class NumbersFile
{
    string file;
    size_t size;
public:
    NumbersFile(string f, size_t size): file(f), size(size){};
    bool insertRange(size_t begin, size_t end, size_t power);
};

