#include <iostream>
#include "functions_c.h"
#define MAX_LINE_LENGTH 500

//видалення елементу за індексом
void RemoveElementByIndex(char* array,int index)
{
    if(index<0)
        index = 0;
    while(array[index]!=0)
    {
        array[index] = array[index+1];
        index++;
    }
}
//пошук позиції вказаного символу
int FindPosition(const char* array, int start_position,char elem)
{
    if(strlen(array)<start_position)
        return -1;
    else {
        int i = start_position;
        while (array[i] != elem && array[i] != '\n')
            i++;
        if (array[i] == elem)
            return i;
        else
            return -1;
    }
}
//копіювання масиву з позиції довжиною length
void Copy(const char* array, char* buff, int start_position, int length)
{
    int i = 0;
    while(i<length)
    {
        buff[i] = array[start_position+i];
        i++;
    }

}
//Обрахунок кількості слів з числами
int WordsWithNumbers(const char* str)
{
    int counter = 0;
    bool numCheck = false;
    for(int i = 0; i<strlen(str); i++)
    {
        if(isdigit(str[i]))
            numCheck = true;
        if((str[i] == ' ' || i == strlen(str)-1) && numCheck)
        {
            counter++;
            numCheck=false;
        }
    }
    return counter;
}
//вставлення на позицію кількості слів з числами
void InsertAmount(char* array, int position, int amount)
{
    int i = -1;
    char result[MAX_LINE_LENGTH] = "";
    char temp[MAX_LINE_LENGTH]="";
    Copy(array, temp,position, (int)strlen(array)-position);
    while (i!=position)
    {
        i++;
        if(i==position)
        {
            strcat(result,("-"+to_string(amount)+"-").c_str());
        }
        else {
            result[i] = array[i];
        }
    }

    strcat(result,temp);
    strcpy(array,result);


}

//Вивід вмісту файлу
void ShowFile_C(const char* name)
{
    FILE* file;
    file = fopen(name,"r");
    char line[MAX_LINE_LENGTH];
    cout<<"Content of "<<name<<endl;
    while(fgets(line,MAX_LINE_LENGTH,file))
    {
        cout<<'#'<<line;
    }
    cout<<endl;
    fclose(file);
}
//Додавання нових рядків
void AddText_C(const char* name)
{
    char choose;
    cout<<"Do you want to add lines? y/n:";
    cin>>choose;
    if(choose == 'y')
    {
        FILE* file;
        file = fopen(name,"a");
        cout<<"Click double enter to finish writing"<<endl;
        char line[MAX_LINE_LENGTH] = " ";
        fflush(stdin);
        while(strcmp(line,"")!=0) {
            cout<<"#";
            gets(line);
            if(strcmp(line,"")!=0) {
                fputs(line, file);
                fputs("\n", file);
            }
        }
        fclose(file);
        cout<<endl;
        ShowFile_C(name);
    }
}
//Запис у файл
void WriteInFile_C(const char* name)
{
    FILE* file;
    file = fopen(name,"w");
    char line[MAX_LINE_LENGTH] = " ";
    cout<<"Click double enter to finish writing"<<endl;
    while(strcmp(line,"")!=0) {
        cout<<"#";
        gets(line);
        if(strcmp(line,"")!=0) {
            fputs(line, file);
            fputs("\n", file);
        }
    }
    fclose(file);
}
//Пошук неправильних рядків та запис у окремий файл
void FindAndCopy_C(const char* name)
{
    FILE* main, *to_correct;
    main = fopen(name,"r");
    to_correct = fopen("to_correct.txt","w");
    char line[MAX_LINE_LENGTH] = " ";
    while(fgets(line,MAX_LINE_LENGTH,main))
    {
        bool is_incorrect = false;
        bool is_opened = false;

        int i = -1;
        while (!is_incorrect && line[i]!='\n') {
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
            fputs(line,to_correct);

    }
    fclose(main);
    fclose(to_correct);
}
//зачистка рядка від зайвих фігурних дужок
void ClearFileFromExcessiveBraces_C(const char* name)
{
    FILE* oFile, *tFile;
    oFile = fopen(name,"r");
    char oFileName[] = "temp.txt";
    tFile = fopen(oFileName,"w");
    char line[MAX_LINE_LENGTH] = " ";

    while(fgets(line,MAX_LINE_LENGTH,oFile)) {
        if(strcmp(line,"")!=0) {
            bool is_opened = false;
            int i = 0,
                open_position = -1;
            while (line[i] != '\n') {
                if (line[i] == '{' && !is_opened) {
                    is_opened = true;
                    open_position = i;
                } else if (line[i] == '{' && is_opened) {
                    RemoveElementByIndex(line,open_position);
                    is_opened = false;
                    i -= 2;
                } else if (line[i] == '}' && !is_opened) {
                    RemoveElementByIndex(line,i-1);
                    i--;
                } else if (line[i] == '}' && is_opened)
                    is_opened = false;
                ++i;
            }
            if (is_opened)
                RemoveElementByIndex(line,open_position);
            fputs(line, tFile);
            memset(line,0,sizeof(line));
        }

    }
    fclose(oFile);
    remove(name);
    fclose(tFile);
    rename(oFileName,name);
}
//пошук слів з числами та запис кількості у фігурних дужках
void FindNumberInBraces_C(const char* name)
{
    FILE* oFile, *tFile;
    oFile = fopen(name,"r");
    char oFileName[] = "temp.txt";
    tFile = fopen(oFileName,"w");
    char line[MAX_LINE_LENGTH] = " ";

    while(fgets(line,MAX_LINE_LENGTH,oFile)) {
        if(strcmp(line,"")!=0) {
            int open_position = 0, close_position = 0;
            while (open_position != -1 && close_position != -1) {
                open_position = FindPosition(line,open_position,'{');
                close_position = FindPosition(line,close_position,'}');

                if (open_position != -1 && close_position != -1) {
                    char temp[MAX_LINE_LENGTH]="";
                    Copy(line,temp,open_position+1,close_position-open_position-1);
                    int amount = WordsWithNumbers(temp);
                    if (amount != 0) {
                        InsertAmount(line,open_position+1,amount);
                        close_position += 4;
                    } else
                        close_position++;
                    open_position = close_position;

                }
            }
            fputs(line,tFile);
        }
    }
    fclose(oFile);
    remove(name);
    fclose(tFile);
    rename(oFileName,name);
}