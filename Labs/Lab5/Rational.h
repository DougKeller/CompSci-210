/*
 * Rational.h  - Specification for Rational class.
 *               This file should contain only prototypes.
 */

// this ifndef is a global "catch" so this file is included only once
#ifndef CS2_RATIONAL_H
#define CS2_RATIONAL_H 

#include <iostream>
#include <string>

class Rational {
private:
    static int obcount;
    int num, den;

    // private utilities
    void reduce();
    int lcd(Rational) const;
    int lcd(int,int) const;
    int gcf(int, int) const;

public:
    Rational(int, int);
    Rational(const Rational &);
    ~Rational();

    static int getCount();
    // operators
    const Rational operator * (const Rational&) const;
    const Rational operator + (const Rational&) const;
    const bool operator == (const Rational&) const;
    const bool operator < (const Rational&) const;
    const bool operator > (const Rational&) const;
    const Rational operator ++ ();
    const Rational operator ++ (int);

    operator double ();

    // setters/getters
    void setNum(int);
    void setDen(int);
    void set(int, int);
    int getNum() const;
    int getDen() const;
};

std::ostream& operator<<(std::ostream&, const Rational&);

#endif // CS2_RATIONAL_H 
