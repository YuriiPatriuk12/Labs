#include "MainFunctions.h"
#include <ctime>

//допоміжна функція введення та перевірки значень
bool CheckAndSetEnteredTime(int buf[])
{
    int h,m;
    Time t;
    cout<<"Enter hours:";
    cin>>h;
    cout<<"Enter minutes:";
    cin>>m;
    if(t.CheckHours(h)&&t.CheckMinutes(m))
    {
        buf[0] = h;
        buf[1] = m;
        return true;
    }
    else {
        cout<<"Error! Incorrect time!"<<endl;
        return false;
    }
}
//сортування масиву
void BubbleSort(Exercise array[], int size)
{
    Exercise temp;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size-i-1; ++j) {
            if(array[j].GetTime().GetHours() > array[j+1].GetTime().GetHours() || (array[j].GetTime().GetHours() == array[j+1].GetTime().GetHours() && array[j].GetTime().GetMinutes() > array[j+1].GetTime().GetMinutes()))
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }

        }
    }
}
//коректування годин та хвилин
void CorrectTime(int &h, int &m)
{
    while (m >= 60) {
        m -= 60;
        h++;
    }
}

//запис у файл елементів класу Exercise
void WriteInFile(const string& main_file)
{
    ofstream outFile(main_file,ios::binary);
    Exercise ex;
    char check = 0;
    int temp[2];
    while(check !='n') {
        cout<<"Enter name of exercise: ";
        char* line;
        line = (char*)calloc(40, sizeof(char));
        gets(line);
        ex.SetName(line);

        do {
            cout << "Enter time of start of exercise"<<endl;
        }while(!CheckAndSetEnteredTime(temp));
        ex.SetTime(temp[0],temp[1]);
        do {
            cout<<"Enter duration of exercise"<<endl;
        }while(!CheckAndSetEnteredTime(temp));
        ex.SetDuration(temp[0],temp[1]);

        outFile.write((char*)&ex, sizeof(Exercise));

        do {
            cout<<endl;
            cout << "Do you want to continue? y/n: ";
            cin >> check;
        }while(check!='y' && check!='n');
        fflush(stdin);
    }
    outFile.close();

}
//вставлення в кінець файлу елементів класу Exercise
void AppendInFile(const string& main_file)
{
    char answer=' ';
    cout<<"Do you want to append? y/n: ";
    cin>>answer;
    fflush(stdin);
    if(answer=='y') {
        ofstream outFile(main_file, ios::app | ios::binary);
        Exercise ex;
        char check = 0;
        int temp[2];
        while (check != 'n') {
            cout << "Enter name of exercise: ";
            char *line;
            line = (char *) calloc(40, sizeof(char));
            gets(line);
            ex.SetName(line);

            do {
                cout << "Enter time of start of exercise" << endl;
            } while (!CheckAndSetEnteredTime(temp));
            ex.SetTime(temp[0], temp[1]);
            do {
                cout << "Enter duration of exercise" << endl;
            } while (!CheckAndSetEnteredTime(temp));
            ex.SetDuration(temp[0], temp[1]);

            outFile.write((char *) &ex, sizeof(Exercise));

            do {
                cout << endl;
                cout << "Do you want to continue? y/n: ";
                cin >> check;
            } while (check != 'y' && check != 'n');
            cout<<endl;
            fflush(stdin);
        }
        outFile.close();
    }
}
//вивід елементів класу Exercise, що містяться у файлі
void ShowFile(const string& main_file)
{
    ifstream iFile(main_file,ios::binary);
    cout<<"Content of "<<main_file<<endl;
    Exercise ex;
    iFile.read((char*)&ex,sizeof(ex));
    do{
        ex.ShowExercise();
        cout<<endl;
        iFile.read((char*)&ex,sizeof(ex));
    }while(!iFile.eof());
    iFile.close();
}
//пошук найближчого до поточного часу завдання
void FindClosestExercise(const string& main_file)
{
    ifstream iFile(main_file, ios::binary);
    Exercise exercise;
    bool is_found = false;
    time_t curr_time = time(nullptr);
    const tm calendar_time = *localtime(addressof(curr_time));
    while(!iFile.eof() && !is_found)
    {
        iFile.read((char*)&exercise,sizeof(exercise));
        if(calendar_time.tm_hour<exercise.GetTime().GetHours())
            is_found = true;
        else if(calendar_time.tm_hour == exercise.GetTime().GetHours()) {
            if (calendar_time.tm_min < exercise.GetTime().GetMinutes())
                is_found = true;
        }
    }
    if(is_found)
    {
        cout<<"Closest exercise: "<<endl;
        exercise.ShowExercise();
    }
    else
        cout<<"Closest wasn't found"<<endl;
    iFile.close();
    cout<<endl;

}
//пошук запис у файл вільного часу
void FindFreeTime(const string& main_file, const string& result_file)
{
    ifstream iFile(main_file, ios::binary);
    iFile.seekg(0,ios::end);
    int amount_of_all = iFile.tellg()/sizeof(Exercise);
    iFile.seekg(0,ios::beg);


    Exercise ex;
    int complete_amount=0;
    Exercise* exercises = (Exercise*) malloc(sizeof(Exercise));
    for (int i = 0; i < amount_of_all; ++i) {
        iFile.read((char*)&ex, sizeof(Exercise));
        if(ex.GetTime().GetHours()>=13) {
            complete_amount++;
            Exercise* temp = new Exercise[complete_amount];
            if(complete_amount>1)
                copy(exercises,exercises+complete_amount-1,temp);
            delete[] exercises;
            exercises = temp;
            exercises[complete_amount-1] = ex;
        }
    }
    iFile.close();
    BubbleSort(exercises,complete_amount);

    ofstream oFile(result_file,ios::binary);

    int i = 0, hour_end, minutes_end, hour_start, minutes_start;
    Time start, end, duration;
    if(exercises[i].GetTime().GetHours()>13 || exercises[i].GetTime().GetMinutes()>0)
    {
        start.SetTime(13,0);
        end.SetTime(exercises[i].GetTime().GetHours(),exercises[i].GetTime().GetMinutes());
        duration.SetTime(exercises[i].GetTime().GetHours()-13, exercises[i].GetTime().GetMinutes());
        oFile.write((char*)&start,sizeof(Time));
        oFile.write((char*)&end,sizeof(Time));
        oFile.write((char*)&duration,sizeof(Time));
    }

    while(i<complete_amount-1)
    {
        hour_end = exercises[i].GetTime().GetHours() + exercises[i].GetDuration().GetHours();
        minutes_end = exercises[i].GetTime().GetMinutes() + exercises[i].GetDuration().GetMinutes();
        hour_start = exercises[i+1].GetTime().GetHours();
        minutes_start = exercises[i+1].GetTime().GetMinutes();
        CorrectTime(hour_end,minutes_end);

        if(hour_start>hour_end || (hour_start==hour_end && minutes_start>minutes_end))
        {
            start.SetTime(hour_end,minutes_end);
            end.SetTime(hour_start,minutes_start);
            if(minutes_start-minutes_end<0) {
                duration.SetTime(hour_start - hour_end - 1,minutes_start - minutes_end + 60);
            }
            else {
                duration.SetTime(hour_start - hour_end, minutes_start - minutes_end);
            }
            oFile.write((char*)&start,sizeof(Time));
            oFile.write((char*)&end,sizeof(Time));
            oFile.write((char*)&duration,sizeof(Time));
        }
        i++;
    }
    int end_hour = exercises[i].GetTime().GetHours()+exercises[i].GetDuration().GetHours();
    int end_minutes = exercises[i].GetTime().GetMinutes()+exercises[i].GetDuration().GetMinutes();
    CorrectTime(end_hour,end_minutes);
    if(end_hour<23 || end_minutes<59)
    {

        start.SetTime(end_hour,end_minutes);
        end.SetTime(23,59);
        duration.SetTime(23-end_hour,59-end_minutes);
        oFile.write((char*)&start,sizeof(Time));
        oFile.write((char*)&end,sizeof(Time));
        oFile.write((char*)&duration,sizeof(Time));
    }

    oFile.close();
}
//виведення вільного часу
void ShowFreeTime(const string& main_file)
{
    ifstream iFile(main_file,ios::binary);
    Time start, end, duration;
    iFile.read((char *) &start, sizeof(Time));
    iFile.read((char *) &end, sizeof(Time));
    iFile.read((char *) &duration, sizeof(Time));
    cout<<"Free time: "<<endl;
    do {
        cout << start.GetHours() << ':';
        if (start.GetMinutes() < 10)
            cout << 0;
        cout << start.GetMinutes() << '-' << end.GetHours() << ':';
        if (end.GetMinutes() < 10)
            cout << 0;
        cout << end.GetMinutes() << endl;
        cout << "Duration: ";
        if (duration.GetHours() < 10)
            cout << 0;
        cout << duration.GetHours() << ':';
        if (duration.GetMinutes() < 10)
            cout << 0;
        cout << duration.GetMinutes() << endl;
        iFile.read((char *) &start, sizeof(Time));
        iFile.read((char *) &end, sizeof(Time));
        iFile.read((char *) &duration, sizeof(Time));
    }while(!iFile.eof());

    iFile.close();
}
