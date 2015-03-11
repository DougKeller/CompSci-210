/*
 * Main.cpp
 *
 * Demonstration of static class members and operator overloading
 * using rational numbers.
 */

#include "Rational.h"
#include <iostream>
using namespace std;

void printcount() {
    cout << "object count: " << Rational::getCount() << endl;
}

// passing by value here (copy constructor called automatically)
void testoutput( Rational a,  Rational b) {
    double d = 0.12345;

    /*** uncomment for part 2a ***/
    cout << "------ running with: " << a << b << " ------" << endl;
    printcount();

    /*** uncomment for parts 2b and 2c ***/
    cout << a << " * " << b << " = " << (a * b) << endl;
    cout << a << " + " << b << " = " << (a + b) << endl;

    /*** uncomment for part 2d ***/
    cout << a;
    cout << (a<b ? " < " : (a==b ? " == " : " > "));
    cout << b << endl;

    /*** uncomment for part 2e ***/
    
    Rational p(a), q(b);
    cout << "++p: before=" << p;
    cout << " during=" << ++p;
    cout << " after=" << p << endl;
    cout << "q++: before=" << q;
    cout << " during=" << q++;
    cout << " after=" << q << endl;
    

    /*** uncomment for part 2f ***/
    cout << a << " + " << d << " = " << (a + d) << endl;
    cout << d << " * " << b << " = " << (d * b) << endl;

    printcount();
}

int main() {

    cout << "Initializing rat0. ";
    Rational rat0 = Rational(3,18);
    printcount();

    cout << "Allocating dynamic p_rat. ";
    Rational *p_rat = new Rational(2,62);
    printcount();
    cout << "     count seen by rat0: " << rat0.getCount() << endl;

    cout << "Deleting dynamic p_rat. ";
    delete p_rat;
    printcount();
    cout << "     count seen by rat0: " << rat0.getCount() << endl;

    cout << "(sending 2 references into functions)" << endl;
    Rational rat1(3,8), rat2(3,4);
    testoutput(rat1, rat2);

    rat2 = Rational(6,16);
    testoutput(rat1, rat2);

    rat1 = Rational(5,12);
    rat2 = Rational(6,-9);
    testoutput(rat1, rat2);
    cout << "(exiting functions)" << endl;

    printcount();

    return 0;
}

