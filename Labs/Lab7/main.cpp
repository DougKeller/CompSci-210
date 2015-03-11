/*
 * Name: Douglas Keller
 * Email: dwk24@zips.uakron.edu
 */

#include "inherit.h"

int main() {
    const int NUMSHAPES = 4;
    const int NUMRECT = 4;
    const int NUMCIRC = 4;
    const int ARSIZE = NUMSHAPES + NUMRECT + NUMCIRC;

    int i = 0;   // reusable counter for loops

/*
 *  set up objects and containers
 */
#if LAB_PART < 1
    //for part 0
    Rectangle r1(2,3);
    Circle c1(4);

#elif LAB_PART < 2
    //for part 1
    Shape * shapeset[NUMSHAPES];
    Rectangle * rectset[NUMRECT];
    Circle * circset[NUMCIRC];

    //populate arrays with generic shapes
    for(i=0;i<NUMSHAPES;++i) {
        shapeset[i] = new Shape(1,2,3);
    }
    for(i=0;i<NUMRECT;++i) {
        rectset[i] = new Rectangle(i, i+1);
    }
    for(i=0;i<NUMCIRC;++i) {
        circset[i] = new Circle(i);
    }
#elif LAB_PART < 4
    //for parts 2,3
    Shape * shapeset[NUMSHAPES];
    Rectangle * rectset[NUMRECT];
    Circle * circset[NUMCIRC];

    // populate arrays with generic shapes
    for(i=0;i<NUMSHAPES;++i) {
        shapeset[i] = new Shape(1,2,3);
    }
    for(i=0;i<NUMRECT;++i) {
        rectset[i] = new Rectangle(i, i+1, 1,2,3);
    }
    for(i=0;i<NUMCIRC;++i) {
        circset[i] = new Circle(i, 1,2,3);
    }
#elif LAB_PART < 5
    //for part 4

    //array can hold pointers to any child of Shape class
    Shape * shapeset[ARSIZE];
    i = 0;

    //populate beginning of array with generic shapes
    for(;i<NUMSHAPES;++i) {
        shapeset[i] = new Shape(i, i+1, i+2);
    }

    //populate array with circles and rectangles
    for(;i< NUMSHAPES + NUMRECT;++i) {
        shapeset[i] = new Rectangle( i, i+2, i, i+1, i+2);
    }
    for(;i<ARSIZE;++i) {
        shapeset[i] = new Circle( (i*16) % 5, i, i+1, i+2);
    }
#else
    // for parts 5,6
    Shape * shapeset[ARSIZE];
    i = 0;

    // populate array with circles and rectangles
    for(;i<ARSIZE/2;++i) {
        shapeset[i] = new Rectangle( i, i+2, i, i+1, i+2);
    }
    for(;i<ARSIZE;++i) {
        shapeset[i] = new Circle( (i*16) % 5, i, i+1, i+2);
    }
#endif  // set up objects and containers

/*
 *  main contents
 */
#if LAB_PART < 1
    // for part 0
    cout << "ID of " << r1 << " is " << r1.getId() << endl;
    cout << "ID of " << c1 << " is " << c1.getId() << endl;

#elif LAB_PART < 4
    // for parts 1,2,3

    // print all shape data
    cout << "Shapes:" << endl;
    for(i=0;i<NUMSHAPES;++i) {
        cout << *(shapeset[i]) << endl;
    }
    cout << "Rectangles:" << endl;
    for(i=0;i<NUMRECT;++i) {
        cout << *(rectset[i]) << endl;
    }
    cout << "Circles:" << endl;
    for(i=0;i<NUMCIRC;++i) {
        cout << *(circset[i]) << endl;
    }

#elif LAB_PART < 6
    // for parts 4,5

    // print all shape data
    for(i=0;i<ARSIZE;++i) {
        Shape &s = *(shapeset[i]);
        cout << s << endl;
    }

#else
    // for part 6

    // print all shape data
    for(i=0;i<ARSIZE;++i) {
        Shape &s = *(shapeset[i]);
        cout << s << " area: " << s.getArea() << endl;
    }

#endif // main contents

/*
 *  clean up objects and containers
 */
#if LAB_PART < 1
    // nothing

#elif LAB_PART < 4
    // delete all dynamic shapes
    for(i=0;i<NUMSHAPES;++i) {
        delete shapeset[i];
        shapeset[i] = NULL;
    }
    // delete all dynamic rectangles
    for(i=0;i<NUMRECT;++i) {
        delete rectset[i];
        rectset[i] = NULL;
    }
    // delete all dynamic circles
    for(i=0;i<NUMCIRC;++i) {
        delete circset[i];
        circset[i] = NULL;
    }
#else
    // delete all dynamic objects
    for(i=0;i<ARSIZE;++i) {
        delete shapeset[i];
        shapeset[i] = NULL;
    }
#endif  // clean up objects and containers


    return 0;
}

