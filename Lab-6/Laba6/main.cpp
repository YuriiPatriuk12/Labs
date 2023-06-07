#include "MainFunctions.h"
int main() {
    int size = 0;
    cout<<"Enter size of hash table:";
    cin>>size;
    string type;
    cout<<"Enter variable type(int,string,float):";
    cin>>type;

    if(type == "string")
        stringMenuCode(size);
    else if(type == "int")
        intMenuCode(size);
    else if(type == "float")
        floatMenuCode(size);
    else
    {
        cout<<"Incorrect entered type"<<endl;
        return 0;
    }

    return 0;
}
