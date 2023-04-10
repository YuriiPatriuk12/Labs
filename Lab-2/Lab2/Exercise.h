#include "Time.h"
#include <cstring>
#define MAX_SIZE 256

struct Exercise{
private:
    char name[MAX_SIZE];
    Time time;
    Time duration;
public:
    Time GetTime() const;
    Time GetDuration() const;
    char* GetName();
    void SetTime(int, int);
    void SetDuration(int, int);
    void SetName(const char* n);
    Exercise();
    Exercise(Exercise&);
    void ShowExercise();
};