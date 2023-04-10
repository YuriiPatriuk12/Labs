#include "MainFunctions.h"

int main() {

    string name = "exercises.dat";
    string result = "free_time.dat";
    WriteInFile(name);
    AppendInFile(name);
    ShowFile(name);
    FindClosestExercise(name);
    FindFreeTime(name,result);
    ShowFreeTime(result);

    return 0;
}
