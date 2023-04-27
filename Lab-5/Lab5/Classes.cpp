#include "Classes.h"

//Two-dimensional vector
TwoDimensionalVector::TwoDimensionalVector()
{
    X=Y=0;
}
TwoDimensionalVector::TwoDimensionalVector(double x, double y)
{
    X = x;
    Y = y;
}
bool TwoDimensionalVector::isParallel (const TwoDimensionalVector& vector) const{
    if(this->isZero() || vector.isZero())
    {
        cout<<"One of the vectors is zero!"<<endl;
        return false;
    }
    double n;
    if(X!=0) n = vector.X / X;
    else n = vector.Y / Y;

    if(X*n == vector.X && Y*n == vector.Y) return true;
    return false;

}
bool TwoDimensionalVector::isPerpendicular(const TwoDimensionalVector& vector) const {
    return vector.X*X + vector.Y*Y == 0;
}
double TwoDimensionalVector::getLength() const{
    return sqrt(pow(X,2)+pow(Y,2));
}
bool TwoDimensionalVector::isZero() const
{
    return X==0 && Y==0;
}

//Three-dimensional vector
ThreeDimensionalVector::ThreeDimensionalVector() {
    X=Y=Z=0;
}
ThreeDimensionalVector::ThreeDimensionalVector(double x, double y, double z)
{
    X = x;
    Y = y;
    Z = z;
}
bool ThreeDimensionalVector::isParallel (const ThreeDimensionalVector& vector) const{
    if(this->isZero() || vector.isZero())
    {
        cout<<"One of the vectors is zero!"<<endl;
        return false;
    }
    double n;
    if(X!=0) n = vector.X / X;
    else if(Y!=0) n = vector.Y / Y;
    else n = vector.Z / Z;

    if(X*n == vector.X && Y*n == vector.Y && Z*n == vector.Z) return true;
    return false;

}
bool ThreeDimensionalVector::isPerpendicular(const ThreeDimensionalVector& vector) const {
    return vector.X*X + vector.Y*Y + vector.Z*Z == 0;
}
double ThreeDimensionalVector::getLength() const{
    return sqrt(pow(X,2)+pow(Y,2)+pow(Z,2));
}
bool ThreeDimensionalVector::isZero() const
{
    return X==0 && Y==0 && Z==0;
}

