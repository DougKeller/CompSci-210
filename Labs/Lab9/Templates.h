/*
 * Templates.h  - Demonstration of template functions and classes
 *
 * Douglas Keller
 * dwk24@zips.uakron.edu
 */

#ifndef CSLAB_TEMPLATES_H
#define CSLAB_TEMPLATES_H

// update this number as you begin each lab portion
#define LAB_PART 6


#include <iostream>
using namespace std;


/* Parameterized 2D coordinate class */
template<class T>
class Vertex {
private:
    T xpos, ypos;
public:
    Vertex() {
        xpos = ypos = 0;
    }

    T getX() const { return xpos; }
    T getY() const { return ypos; }
    void setX(T val) { xpos = val; }
    void setY(T val) { ypos = val; }

    virtual ostream& printTo(ostream& outs) const {
        outs << "(" << getX() << "," << getY() << ")";
        return outs;
    }

};

/* Parameterized operator << to accompany coordinate class */
template <class T>
ostream & operator<< (ostream& outs, const Vertex<T>& thing) {
    return thing.printTo(outs);
}

/* Parameterized 3D coordinate derived from parent coordinate */
template <class T>
class Vertex3D : public Vertex<T>{
private:
    T zpos;
    public:
        Vertex3D(){
            zpos = 0;
        }
        T getZ() const { return zpos; }
        
        void setZ(T val) { zpos = val; }
        
        virtual ostream& printTo(ostream& outs) const {
        outs << "(" << this->getX() << "," << this->getY() << "," << getZ() << ")";
        return outs;
    } 
};


/* Print contents of an array of arbitrary type */
template <class T>
void print_array(T arr[], int len) {
    for(int i=0;i<len;++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* Add the values of any numeric array and return their sum */
template <class T>
T sum_array(T arr[], int len) {
    T sum = 0;
    for(int i = 0; i < len; i++)
        sum += arr[i];
    
    return sum;
    
}

/* Overloaded functions to print a (contrived)
   pair of values:
     A label (int or char)
     A second value of arbitrary type
 */
template <class T>
void printpair(char label, T a) {
    cout << char(toupper(label)) << " : " << a << endl;
}

template<class T>
void printpair(int label, T a) {
    cout << label << " : " << a << endl;
}

/* Print a mapping of corresponding values between
   parallel arrays of arbitrary types */
template <class T1, class T2>
void printmapping(T1 a[], T2 b[], int len) {
    cout << "{";
    for(int i=0;i<len;++i) {
        cout << a[i] << ":" << b[i] << ",";
    }
    cout << '\b' << "}" << endl;  // backspace to overwrite final comma
}

#endif     // CSLAB_TEMPLATES_H

