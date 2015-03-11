/*
 * Circle.h  - Interface and definitions for Circle class
 *
 * Demonstration of advanced inheritance features.
 * Inherits from Shape class.
 *
 * Douglas Keller
 * dwk24@zips.uakron.edu
 */

#ifndef LAB_DEF_CIRC
#define LAB_DEF_CIRC

#include <iostream>
using namespace std;


const double PI = 3.14159;

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double inrad, int x = 0, int y = 0, int z = 0) : Shape::Shape(x, y, z)
    {
        setRadius(inrad);
    }

    Circle(const Circle& incirc) : Shape::Shape(incirc.getX(), incirc.getY(), incirc.getZ())
    {
        setRadius(incirc.getRadius());
    }

    const double getRadius() const { return radius; }
    void setRadius(double inrad) {
        radius = (inrad < 0 ? (0 - inrad) : inrad);
    }
    
    virtual ostream& printTo(ostream& outs) const {
        outs << "CIRC_" << getId()
            << "{pos(" << getX() << "," << getY() << "," << getZ()
            << ");radius(" << getRadius() << ")}";
        return outs;
    }
    
    virtual double getArea() const{
        return 3.14 * radius * radius;
    }

};

#endif // LAB_DEF_CIRC

