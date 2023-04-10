#include <iostream>
#include "functions.h"
#include <fstream>

//Обрахунок кількості слів з числами
int WordsWithNumbers(const string& str)
{
    int counter = 0;
    bool numCheck = false;
    for(int i = 0; i<str.length(); i++)
    {
        if(isdigit(str[i]))
            numCheck = true;
        if((str[i] == ' ' || i==str.length()-1) && numCheck)
        {
            counter++;
            numCheck=false;
        }
    }

    return counter;
}
//Вивід вмісту файлу
void ShowFile(const string& name){
    ifstream iFile(name);
    string line;
    cout<<"Content of "<<name<<endl;
    while(!iFile.eof())
    {
        getline(iFile,line);
        cout<<'#'<<line<<endl;
    }
    cout<<endl;
    iFile.close();
}
//Додання нових рядків
void AddText(const string& name)
{
    char choose;
    cout<<"Do you want to add lines? y/n:";
    cin>>choose;
    if(choose == 'y')
    {
        ofstream outFile;
        outFile.open(name,ios::app);
        cout<<"Click double enter to finish writing"<<endl;
        string line=" ";
        fflush(stdin);
        while(!line.empty()) {
            cout<<"#";
            getline(cin, line);
            if(!line.empty())
                outFile << line << endl;
        }
        outFile.close();
        cout<<endl;
        ShowFile(name);
    }
}
//Запис у файл
void WriteInFile(const string& name)
{
    ofstream outFile(name);
    cout<<"Click double enter to finish writing"<<endl;
    string line=" ";
    while(!line.empty()) {
        cout<<"#";
        getline(cin, line);
        if(!line.empty())
            outFile << line << endl;
    }
    outFile.close();

}
//Пошук неправильних рядків та запис у окремий файл
void FindAndCopy(const string& name)
{
    ifstream inFile(name);
    ofstream additionalFile("to_correct.txt");
    string line;
    while(!inFile.eof())
    {
        bool is_incorrect = false;
        bool is_opened = false;
        getline(inFile,line);
        if(!line.empty()) {
            int i = -1;
            int size = (int) line.length();
            while (!is_incorrect && i < size) {
                ++i;
                if (line[i] != '{' && line[i] != '}')
                    continue;
                if (line[i] == '{' && !is_opened)
                    is_opened = true;
                else if (line[i] == '{' && is_opened || line[i] == '}' && !is_opened)
                    is_incorrect = true;
                else if (line[i] == '}' && is_opened)
                    is_opened = false;
            }
            if (is_incorrect || is_opened)
                additionalFile << line << endl;
        }
    }
    inFile.close();
    additionalFile.close();
}
//зачистка рядка від зайвих фігурних дужок
void ClearFileFromExcessiveBraces(const string& name)
{
    ifstream iFile(name);
    string oFileName = "temp.txt";
    ofstream oFile(oFileName);
    string line;

    while(!iFile.eof()) {
        getline(iFile, line);
        if(!line.empty()) {
            bool is_opened = false;
            int i = 0,
                    open_position = -1,
                    size = (int) line.length();
            while (i < size) {
                if (line[i] == '{' && !is_opened) {
                    is_opened = true;
                    open_position = i;
                } else if (line[i] == '{' && is_opened) {
                    line.erase(open_position, 1);
                    size = (int) line.length();
                    is_opened = false;
                    i -= 2;
                } else if (line[i] == '}' && !is_opened) {
                    line.erase(i, 1);
                    size = (int) line.length();
                    i--;
                } else if (line[i] == '}' && is_opened)
                    is_opened = false;
                ++i;
            }
            if (is_opened)
                line.erase(open_position);
            oFile << line << endl;
        }

    }
    iFile.close();
    remove(name.c_str());
    oFile.close();
    rename(oFileName.c_str(),name.c_str());
}
//пошук слів з числами та запис кількості у фігурних дужках
void FindNumberInBraces(const string& name)
{
    ifstream iFile(name);
    string oFileName = "temp.txt";
    ofstream oFile(oFileName);
    string line;

    while(!iFile.eof()) {
        getline(iFile, line);
        if(!line.empty()) {
            int open_position = 0, close_position = 0;
            while (open_position != string::npos && close_position != string::npos) {
                open_position = (int) line.find('{', open_position);
                close_position = (int) line.find('}', close_position);

                if (open_position != string::npos && close_position != string::npos) {
                    string temp = line.substr(open_position + 1, close_position - open_position - 1);
                    int amount = WordsWithNumbers(temp);
                    if (amount != 0) {
                        line.insert(open_position + 1, '-' + to_string(amount) + '-');
                        close_position += 4;
                    } else
                        close_position++;
                    open_position = close_position;
                }
            }
            oFile << line << endl;
        }
    }
    iFile.close();
    remove(name.c_str());
    oFile.close();
    rename(oFileName.c_str(),name.c_str());
}
