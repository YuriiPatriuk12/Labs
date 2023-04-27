#include <iostream>
#include <cmath>
using namespace std;

class TVector
{
public:
    bool isParallel() const;
    bool isPerpendicular() const;
    virtual double getLength() const = 0;
    virtual bool isZero() const = 0;
};

class TwoDimensionalVector : public TVector
{
    double X;
    double Y;
public:
    TwoDimensionalVector();
    TwoDimensionalVector(double, double);
    bool isParallel(const TwoDimensionalVector&) const;
    bool isPerpendicular(const TwoDimensionalVector&) const;
    double getLength() const override;
    bool isZero() const override;
};

class ThreeDimensionalVector : public TVector
{
    double X;
    double Y;
    double Z;
public:
    ThreeDimensionalVector();
    ThreeDimensionalVector(double, double, double);
    bool isParallel(const ThreeDimensionalVector&) const;
    bool isPerpendicular(const ThreeDimensionalVector&) const;
    double getLength() const override;
    bool isZero() const override;
};

