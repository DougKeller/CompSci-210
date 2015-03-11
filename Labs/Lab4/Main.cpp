/*
 * Main.cpp
 *
 * Demonstration 2 of objects and classes, using Circle.cpp
 *
 * Douglas Keller
 * dwk24@zips.uakron.edu
 */

#include "Circle.h"
using namespace std;

int main() {
    Circle c1("StaticGuy");
    Circle *pc2 = new Circle("PointerGuy", 4, 5, 29);
    
    //the following works for references
    c1.printme();
    
    //the following works for pointers
    pc2->printme();

    pc2->collideMessage(c1);
    
    pc2->setRadius(2);
    c1.printme();
    pc2->printme();
    
    pc2->collideMessage(c1);

    
    delete pc2;
    return 0;
}

