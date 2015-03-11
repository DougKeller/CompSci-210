 /********************************************************************
  * Lab 13 : Rational.h
  *
  * Author: Douglas Keller
  *         dwk24@zips.uakron.edu
  *
  * Purpose: Header file containing prototypes for Rational class
  *
  ********************************************************************/

// this #ifndef check exists to prevent this from being included
// more than once, so multiple cpp files may use this header.
#ifndef LAB_RATIONAL_H
#define LAB_RATIONAL_H

class Rational
{
private:
    int numerator, denominator;
public:
    Rational();
    Rational(int, int);

    void printOut();
    void reduce();
};

// non-member function, provided already. do not modify.
int gcf(int, int);

#endif // LAB_RATIONAL_H

