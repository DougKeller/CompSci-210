/*
 * Circle.cpp  - Definitions for Circle class
 *
 * YOUR NAME
 * YOUR EMAIL
 */

#include "Circle.h"
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

Circle::Circle(string s, int xval, int yval, int r){
    myname = s;
    x = xval;
    y = yval;
    radius = r;
}


void Circle::setX(int input) {
    x = input;
}

void Circle::setY(int input) {
    y = input;
}

void Circle::setRadius(int input) {
    if(input < 0) {
        radius = 0 - input;
    }
    else radius = input;
}

int Circle::getX() const {
    return x;
}

int Circle::getY() const {
    return y;
}

int Circle::getRadius() const {
    return radius;
}

double Circle::distanceTo(const Circle &otherguy){
    int xval = otherguy.x - x;
    int yval = otherguy.y - y;
    double distance = sqrt(xval * xval + yval * yval);
    return distance;
}

bool Circle::intersects(const Circle &otherguy){
    int rTotal = radius + otherguy.radius;
    if (rTotal > distanceTo(otherguy))
        return true;
    else 
        return false;
}

void Circle::collideMessage(const Circle &otherguy){
    cout << "distance: " << distanceTo(otherguy) << endl;
    if(intersects(otherguy))
        cout << "*BOOM*" << endl;
    else
        cout << "....missed!" << endl;
    
}

void Circle::printme() const {
    cout << myname << "(x=" << x << ",y=" << y << ",r=" << radius << ")\n";
}

