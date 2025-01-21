#include <iostream>
#include "./../Headers/Fraction.h"
#include "./../../LibSun/Headers/Gcd.h"
#include "./../../LibSun/Headers/Arithmetic.h"
using namespace std;
Fraction::Fraction(int numerator, int denominator) : 
    numerator(numerator), denominator(denominator) { 
    
}
Fraction Fraction::Add(const Fraction& other) {
    Fraction third(0, 1);
    third.numerator = findSum(
                            findProduct(this->numerator,other.denominator),
                            findProduct(other.numerator, this->denominator)
                        );
    third.denominator = findProduct(this->denominator, other.denominator);

    //
    int gcd = findGCD(third.numerator, third.denominator);
    third.numerator = findQuotient(third.numerator, gcd);
    third.denominator = findQuotient(third.denominator, gcd);
    //
    return third;
}

ostream& operator<<(ostream& output, const Fraction& fraction) { //non member op <<
    output << fraction.numerator << "/" << fraction.denominator;
    return output;
}