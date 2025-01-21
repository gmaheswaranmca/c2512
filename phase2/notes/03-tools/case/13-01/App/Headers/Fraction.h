#pragma once
#include <iostream>
using namespace std;
// a/b , here a = numerator , b = denominator
class Fraction { 
    private:
        int numerator;
        int denominator;
    public:
        Fraction(int numerator, int denominator); 
        Fraction Add(const Fraction& other);
        friend ostream& operator<<(ostream& output, const Fraction& fraction);
};

ostream& operator<<(ostream& output, const Fraction& fraction);