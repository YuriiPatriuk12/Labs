#include "Exercise.h"

Time Exercise::GetTime() const
{
    return time;
}
Time Exercise::GetDuration() const
{
    return duration;
}
char* Exercise::GetName() {
    return name;
}
void Exercise::SetTime(int h, int m)
{
    time.SetHours(h);
    time.SetMinutes(m);
}
void Exercise::SetDuration(int h, int m)
{
    duration.SetHours(h);
    duration.SetMinutes(m);
}
void Exercise::SetName(const char* n)
{
    strcpy(name,n);
}
Exercise::Exercise()
{
    time = Time();
    duration = Time();
}
Exercise::Exercise(Exercise& obj)
{
    strcpy(name,obj.name);
    time = obj.time;
    duration = obj.duration;
}

void Exercise::ShowExercise()
{
    cout<<name<<endl;
    cout<<"Time: ";time.ShowTime();
    cout<<"Duration: ";duration.ShowTime();
}





