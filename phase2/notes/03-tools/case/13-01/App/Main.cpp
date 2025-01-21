#include <iostream>
#include "./../Headers/Fraction.h"
using namespace std;
int main() {
    // Create two fraction objects
    Fraction f1(1, 2); // Represents 1/2
    Fraction f2(2, 3); // Represents 2/3

    // Add two fractions
    Fraction result = f1.Add(f2);
    cout << "sum of " << f1 << " and " 
         << f2 << " is " 
         << result << "." << endl; // Expected output: 7/6 (in reduced form)
    // Create a third fraction
    Fraction f3(3, 4); // Represents 3/4
    // Add three fractions
    Fraction result2 = f1.Add(f2.Add(f3));
    cout << "sum of " << f1 << ", " 
         << f2 << " and " << f3 << " is " 
         << result2 << "." << endl; // Expected output: 23/12 (in reduced form)

    return 0;
}