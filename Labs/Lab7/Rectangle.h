/*
 * Rectangle.h  - Interface and definitions for Rectangle class
 *
 * Demonstration of advanced inheritance features.
 * Inherits from Shape class.
 *
 * Douglas Keller
 * dwk24@zips.uakron.edu
 */

#ifndef LAB_DEF_RECT
#define LAB_DEF_RECT

#include <iostream>

#include "Shape.h"
using namespace std;


class Rectangle : public Shape {
private:
    double dimx, dimy;
public:
    Rectangle(double indimx, double indimy, int  x = 0, int y = 0, int z = 0) : Shape::Shape(x, y, z)
    {
        setWidth(indimx);
        setHeight(indimy);
    }

    Rectangle(const Rectangle& inrect) : Shape::Shape(inrect.getX(), inrect.getY(), inrect.getZ())
    {
        setWidth(inrect.getWidth());
        setHeight(inrect.getHeight());
    }

    const double getWidth() const { return dimx; }
    const double getHeight() const { return dimy; }
    void setWidth(double inw) {
        dimx = (inw < 0 ? (0 - inw) : inw);
    }
    void setHeight(double inh) {
        dimy = (inh < 0 ? (0 - inh) : inh);
    }
    
    virtual ostream& printTo(ostream& outs) const {
        outs << "RECT_" << getId()
            << "{pos(" << getX() << "," << getY() << "," << getZ()
            << ");dims(" << getWidth() << "," << getHeight() << ")}";
        return outs;
    }
    
    virtual double getArea() const{
        return dimx * dimy;
    }

};

#endif // LAB_DEF_RECT

