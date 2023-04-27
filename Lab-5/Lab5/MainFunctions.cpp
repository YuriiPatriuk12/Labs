#include "MainFunctions.h"

void sumOfParallelTwoDimensionalVectors(TwoDimensionalVector* vectors, int size)
{
    double two_dim_sum = 0;
    for(int i=1; i<size; i++)
    {
        if(vectors[0].isParallel(vectors[i])) {
            cout<<"vectors[0] is parallel to vectors["<<i<<']'<<endl;
            two_dim_sum += vectors[i].getLength();
        }
    }
    cout<<"Sum: "<<two_dim_sum<<endl<<endl;
}
void sumOfPerpendicularThreeDimensionalVectors(ThreeDimensionalVector* vectors, int size)
{
    double three_dim_sum = 0;
    for(int i=1; i<size; i++)
    {
        if(vectors[0].isPerpendicular(vectors[i])) {
            cout<<"vectors[0] is perpendicular to vectors["<<i<<']'<<endl;
            three_dim_sum += vectors[i].getLength();
        }
    }
    cout<<"Sum: "<<three_dim_sum<<endl;

}
