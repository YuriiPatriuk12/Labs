#include <iostream>
#include "functions.h"
#include "functions_c.h"

int main(int argc, char *argv[]) {
    string name = "main.txt";
    string secondName = "to_correct.txt";

    if(argc==3 && strcmp(argv[1],"-mode")==0){
        if(strcmp(argv[2], "FilePointer")==0)
        {
            WriteInFile_C(name.c_str());
            ShowFile_C(name.c_str());
            AddText_C(name.c_str());
            FindAndCopy_C(name.c_str());
            ShowFile_C(secondName.c_str());
            ClearFileFromExcessiveBraces_C(secondName.c_str());
            ShowFile_C(secondName.c_str());
            FindNumberInBraces_C(secondName.c_str());
            cout<<"---------Results---------"<<endl;
            ShowFile_C(name.c_str());
            ShowFile_C(secondName.c_str());
        }
        else if(strcmp(argv[2], "FileStream")==0)
        {
            WriteInFile(name);
            ShowFile(name);
            AddText(name);
            FindAndCopy(name);
            ShowFile(secondName);
            ClearFileFromExcessiveBraces(secondName);
            ShowFile(secondName);
            FindNumberInBraces(secondName);
            cout<<"---------Results---------"<<endl;
            ShowFile(name);
            ShowFile(secondName);
        }
    }

    cout<<"---------Finish---------"<<endl;
    system("pause");
    return 0;
}
