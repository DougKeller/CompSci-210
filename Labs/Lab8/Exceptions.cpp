/*
 * Exceptions.cpp  - Demonstration of exceptions
 *
 * Douglas Keller
 * dwk24@zips.uakron.edu
 */

#include <iostream>
#include <cmath>
#include "Lab8_helper.h"
using namespace std;

// the classic example, division by zero
double divide(double n, double d){
        if(d == 0)
            throw -100;
        else
            return n / d;

}

// triangles don't have negative side lengths
double hypotenuse(double a, double b) {
    if(a < 0 || b < 0)
        throw invalid_argument("negative triangle side");
    else
        return sqrt((a*a) + (b*b));
}

int main() {
    double din1, din2;
    bool repeat = true;

    /*
     *  Part 1: throwing primitive exceptions, and catching exceptions
     */
    cout << "-------- Part 1: Divide by zero --------\n";
    cout << "Numerator: ";
    din1 = input_double();
    cout << "Denominator: ";
    din2 = input_double();

    try{
        cout << din1 << "/" << din2 << "=" << divide(din1,din2) << endl;
    } catch (int x){
        cout << "Exception caught on division: " << x << endl;
    }


    /*
     *  Part 2: standard exception class, and catch specific exception type
     */
    cout << "-------- Part 2: Finding the hypotenuse --------\n";
    while(repeat){
        repeat = false;
        cout << "Leg A: ";
        din1 = input_double();
        cout << "Leg B: ";
        din2 = input_double();


        try{
        cout << "Hypotenuse of " << din1 << "," << din2
            << " is " << hypotenuse(din1,din2) << endl;
        } catch(const invalid_argument &a){
            printexception(a);
            repeat = true;
        }
    
    }



    /*
     *  Part 3: bad allocation (no memory left)
     */
    cout << "-------- Part 3,4: Creating a memory leak... --------\n";
    int *intarr;
    int loopcount = 0;
    try{
        while(true) {
            ++ loopcount;
            intarr = new int[9999];
        }
    } catch (const exception &e){
        printexception(e);
        cout << "Loop count was " << loopcount << endl;
    } catch (...){
        cout << "Part 4: Other exception caught";
        throw;
    }




    cout << "(Program ending normally)" << endl;
    return 0;
}

