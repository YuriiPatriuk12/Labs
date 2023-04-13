#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Polynomial {
    double a, b, c, d;
public:
    Polynomial();
    Polynomial(double,double,double,double);
    Polynomial(Polynomial&);
    double GetA() const;
    double GetB() const;
    double GetC() const;
    double GetD() const;
    double CalculatePolynomial(double) const;
    void ShowCoefficients() const;
    Polynomial operator +=(double);
    Polynomial operator -=(double);
    bool operator ==(const Polynomial&) const;

};