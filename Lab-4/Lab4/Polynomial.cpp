#include "Polynomial.h"

Polynomial::Polynomial() {
    a = b = c = d = 1;
}

Polynomial::Polynomial(double a, double b, double c, double d) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}

Polynomial::Polynomial(Polynomial &Polynomial) {
    a = Polynomial.a;
    b = Polynomial.b;
    c = Polynomial.c;
    d = Polynomial.d;
}

double Polynomial::GetA() const {
    return a;
}

double Polynomial::GetB() const {
    return b;
}

double Polynomial::GetC() const {
    return c;
}

double Polynomial::GetD() const {
    return d;
}

double Polynomial::CalculatePolynomial(double x) const{
    double res = pow(x,3)*a + pow(x,2)*b + x*c + d;
    return res;
}

void Polynomial::ShowCoefficients() const {
    cout<<"Coefficients: "<<a<<setw(7)<<b<<setw(7)<<c<<setw(7)<<d<<endl;
}

Polynomial Polynomial::operator+=(double n) {
    this->a += n;
    this->b += n;
    this->c += n;
    this->d += n;
    return *this;
}

Polynomial Polynomial::operator-=(double n) {
    this->a -= n;
    this->b -= n;
    this->c -= n;
    this->d -= n;
    return *this;
}

bool Polynomial::operator==(const Polynomial& Polynomial) const{
    if(Polynomial.a == a && Polynomial.b == b && Polynomial.c == c && Polynomial.d == d)
        return true;
    return false;
}


