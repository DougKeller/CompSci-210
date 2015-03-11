/*
 * Lab8_helper.h
 *
 * Helper utilities for lab 8, so we don't need to print everything.
 *
 * Note that for "real" programs, put implementations in a .cpp file
 */

#ifndef LAB8_HELPER
#define LAB8_HELPER

#include <iostream>
#include <stdexcept>
#include <typeinfo>
using namespace std;


double input_double() {
    double inp;
    bool repeat = true;
    while(repeat) {
        repeat = false;
        cout << "input decimal: " << flush;
        cin >> inp;
        if(!(cin.good())){
            repeat = true;
            cin.clear();
        }
        cin.ignore(20000, '\n');
    }
    return inp;
}
// utility. only works for objects derived from std exception
void printexception(const exception& ex) {
    cout << "Exception: ";
    cout << "\"" << ex.what() << "\" of type ";
    cout << typeid(ex).name() << endl;
}

#endif // LAB8_HELPER

