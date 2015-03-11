/*
 * Shape.h  - Interface and definitions for Shape class
 *
 * Demonstration of advanced inheritance features.
 * Base (parent) of Rectangle and Circle
 *
 * Douglas Keller
 * dwk24@zips.uakron.edu
 */

#ifndef LAB_DEF_SHAPE
#define LAB_DEF_SHAPE

#include <iostream>
using namespace std;


class Shape {
private:
    // disallow copy constructor
    Shape(const Shape &) {}
    static int numinstances;
    int myid;
    double posx, posy, posz;

protected:    
    const int getId() const { return myid; }
    
public:
    Shape(const double inx, const double iny, const double inz) {
        myid = numinstances;
        ++numinstances;
        posx = inx;
        posy = iny;
        posz = inz;
    }
    // destructor must be public to be used without overriding
    ~Shape() { --numinstances; }

    const double getX() const { return posx; }
    const double getY() const { return posy; }
    const double getZ() const { return posz; }
    void setPosition(double inx, double iny, double inz) {
        posx = inx;
        posy = iny;
        posz = inz;
    }

    static const int getNumInstances() {
        return numinstances;
    }

    virtual ostream& printTo(ostream& outs) const = 0;
    virtual double getArea() const = 0;

};

// static member data must also be declared as global
int Shape::numinstances;

ostream& operator<<(ostream& outs, const Shape& shap) {
    return shap.printTo(outs);
}

#endif  // LAB_DEF_SHAPE

