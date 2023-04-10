#include "Time.h"

Time::Time() {
    hour= 0;
    min = 0;
}
Time::Time(int hour, int min)
{
    if(CheckHours(hour) && CheckMinutes(min))
    {
        this->hour=hour;
        this->min=min;
    }
    else
    {
        cout<<"Incorrect time!"<<endl;
        this->hour=13;
        this->min=0;
    }
}
bool Time::CheckHours(int hours) const{
    if(hours>=24 || hours<0)
        return false;
    else
        return true;
}
bool Time::CheckMinutes(int minutes) const{
    if(minutes>60 || minutes<0)
        return false;
    else
        return true;
}
int Time::GetHours() const
{
    return hour;
}
int Time::GetMinutes() const
{
    return min;
}
void Time::SetHours(int h)
{
    hour = h;
}
void Time::SetMinutes(int m) {
    min = m;
}
void Time::SetTime(int h, int m)
{
    hour = h;
    min = m;
}

void Time::ShowTime() const{
    if(this->hour<10)
        cout<<0;
    cout<<hour<<':';
    if(this->min<10)
        cout<<0;
    cout<<min<<endl;
}

