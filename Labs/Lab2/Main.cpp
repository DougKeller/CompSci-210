 /********************************************************************
  * Lab 13 : Main.cpp
  *
  * Author: Douglas Keller
  *         dwk24@zips.uakron.edu
  *
  * Purpose: Main program file for demonstrating classes and objects.
  *          For use with Rational class.
  *
  ********************************************************************/

#include "Rational.h"

int main() {

    // Part 1

    Rational r1(1,2);
    Rational r2(5,10);
    Rational r3(10, 30);


    // Part 2
    
    r1.printOut();
    r2.printOut();
    r3.printOut();
    

    // Part 3
    
    r1.reduce();
    r1.printOut();

    r2.reduce();
    r2.printOut();

    r3.reduce();
    r3.printOut();
    

    return 0;
}

