#include "Polynomial.h"

int main() {
    Polynomial p1;
    Polynomial p2(7,-9,1,-14);
    Polynomial p3(p2);
    p1.ShowCoefficients();
    p2.ShowCoefficients();
    p3.ShowCoefficients();

    double n = 0;
    cout<<"Enter n:";
    cin>>n;
    p1 += n;
    p2 -= n;
    p1.ShowCoefficients();
    p2.ShowCoefficients();
    if(p1==p2)
        cout<<"P1 = P2"<<endl;
    else
        cout<<"P1 != P2"<<endl;

    double x = 0;
    cout<<"Enter x:";
    cin>>x;
    double p3_result = p3.CalculatePolynomial(x);
    cout<<"Result: "<<p3_result<<endl;

    return 0;
}
