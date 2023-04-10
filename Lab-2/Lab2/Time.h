#include <iostream>
using namespace std;

struct Time {
private:
    int hour;
    int min;
public:
    Time();
    Time(int, int);
    int GetHours() const;
    int GetMinutes() const;
    void SetHours(int h);
    void SetMinutes(int m);
    void SetTime(int h, int m);
    void ShowTime() const;
    bool CheckHours(int) const;
    bool CheckMinutes(int) const;

};
