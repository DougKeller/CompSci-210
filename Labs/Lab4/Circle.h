/*
 * Circle.h  - Specification for Circle class.
 *             This file should contain only prototypes.
 * YOUR NAME
 * YOUR EMAIL
 */

// this ifndef is a global "catch" so this file is included only once
#ifndef CIRCLE_H
#define CIRCLE_H 

#include <string>
using namespace std;

class Circle {
private:
    int x, y, radius;
    string myname;
public:
    Circle(string, int xval = 0, int yval = 0, int r = 1);
    void setX(int);
    void setY(int);
    void setRadius(int);
    int getX() const;
    int getY() const;
    int getRadius() const;
    double distanceTo(const Circle &);
    bool intersects(const Circle &);
    void collideMessage(const Circle &);
    void printme() const;
};

#endif // CIRCLE_H

