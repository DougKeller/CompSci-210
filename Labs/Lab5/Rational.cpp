/*
 * Rational.cpp  - Definitions for Rational class
 *
 * Demonstration of static class members and operator overloading
 *
 * Douglas Keller
 * dwk24@zips.uakron.edu
 */

#include "Rational.h"
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

int Rational::obcount = 0;


Rational::Rational(int n, int d) {
    set(n, d);
    obcount++;
}

Rational::Rational(const Rational & rat){
    num = rat.num;
    den = rat.den;
    obcount++;
}

Rational::~Rational(){
    obcount--;
}

int Rational::getCount(){
    return obcount;
}

////////////////////////////////////////////////
// Utilities: do not add or change anything below this line

void Rational::setNum(int n) {
    num = n;
    reduce();
}
void Rational::setDen(int d){
    if(d != 0) {
        den = d;
        reduce();
    }
}
void Rational::set(int n, int d) {
    if(d != 0) {
        num = n;
        den = d;
        reduce();
    }
}

int Rational::getNum() const {
    return num;
}
int Rational::getDen() const {
    return den;
}

void Rational::reduce() {
    if(den < 0) {
        den *= -1;
        num *= -1;
    }
    int fact = gcf( (num < 0 ? -num : num), den);
    num = num / fact;
    den = den / fact;
}

int Rational::lcd(Rational otherguy) const {
    return lcd(den, otherguy.den);
}
int Rational::lcd(int a, int b) const {
    int fact = gcf(a,b);
    return (a / fact) * b;
}

int Rational::gcf(int a, int b) const {
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


std::ostream& operator<<(std::ostream& stream, const Rational& rat){
    stream << "[" << rat.getNum() << "/" << rat.getDen() << "]";
}

const Rational Rational::operator * (const Rational& rat) const{
    int newNum = num * rat.num;
    int newDen = den * rat.den;
    return Rational(newNum, newDen);
}

const Rational Rational::operator + (const Rational& rat) const{
    int newDen = lcd(rat);
    int newNum = num * newDen / den + rat.num * newDen / rat.den;
    return Rational(newNum, newDen);
}

const bool Rational::operator == (const Rational& rat) const{
    int denom = lcd(rat);
    int numA = num * denom / den;
    int numB = rat.num * denom / rat.den;
    
    return numA == numB;
}

const bool Rational::operator < (const Rational& rat) const{
    int denom = lcd(rat);
    int numA = num * denom / den;
    int numB = rat.num * denom / rat.den;
    
    return numA < numB;
}

const bool Rational::operator > (const Rational& rat) const{
    int denom = lcd(rat);
    int numA = num * denom / den;
    int numB = rat.num * denom / rat.den;
    
    return numA > numB;
}


const Rational Rational::operator ++ (){
    num += den;
    return *this;
}
const Rational Rational::operator ++ (int i){
    Rational rat = Rational(*this);
    num += den;
    return rat;
}

Rational::operator double (){
    return (double)num / den;
}

