 /********************************************************************
  * Lab 13 : Rational.cpp
  *
  * Author: Douglas Keller
  *         dwk24@zips.uakron.edu
  *
  * Purpose: Implementation file containing definitions for Rational class
  *
  ********************************************************************/

#include <iostream>
#include "Rational.h"
using namespace std;

/* Default constructor already provided */
Rational::Rational() {
    numerator = 1;
    denominator = 1;
}

/* Implement overloaded (int, int) constructor */

Rational::Rational(int num, int den){
    numerator = num;
    denominator = den;
}

/* Implement printOut() member function */

void Rational::printOut(){
    cout << numerator << "/" << denominator << endl;
}

/* Implement reduce() member function */

void Rational:: reduce(){
    int x = gcf(numerator, denominator);
    numerator = numerator / x;
    denominator = denominator / x;
}


/*
  Greatest common factor is already 
  implemented for you, so do not modify it.

  This function uses recursion,
  you will learn about it later.
 */
int gcf(int a, int b) {
    int result = 0;

    if (a < b) {
        result = gcf(b, a);
    }
    else if (b == 0) {
        result = a;
    }
    else {
        result = gcf(b, (a % b));
    }
    return result;
}

