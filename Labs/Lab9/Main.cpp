/*
 * Main.cpp  - Test cases for templates lab
 *
 * Do not modify this file
 */

#include <iostream>
#include "Templates.h"
using namespace std;

int main() {
    const int ARRAYLEN = 6;
    double d_arr[ARRAYLEN] = {0.6,1.5,2.4,3.3,4.2,5.1};
    string s_arr[ARRAYLEN] = {"princess","tomato","in","the","salad","kingdom"};

    cout << "---- Part 1: templated print array ----\n";
    print_array(d_arr, ARRAYLEN);
    print_array(s_arr, ARRAYLEN);

#if LAB_PART > 1
    cout << "---- Part 2: sum array ----\n";
    cout << "d_arr sum: " << sum_array(d_arr, 6) << endl;
    try {
        cout << "s_arr sum: " << sum_array(s_arr, 6) << endl;
    }
    catch(const exception& ex) {
        cout << "Main caught exception in sum string array: "
             << ex.what() << endl;
    }
#endif

#if LAB_PART > 2
    cout << "---- Part 3: overloading template functions ----\n";
    printpair(5, s_arr[5]);
    printpair('b', s_arr[2]);
#endif

#if LAB_PART > 3
    cout << "---- Part 4: multiple templated types ----\n";
    printmapping(d_arr, s_arr, 6);
#endif

#if LAB_PART > 4
    cout << "---- Part 5: class template ----\n";
    cout << "Vertex<double> ";
    Vertex<double> dvert;
    dvert.setX(-44.1);
    dvert.setY(99.22);
    cout << dvert << endl;

    cout << "Vertex<char> ";
    Vertex<char> cvert;
    cvert.setX('c');
    cvert.setY('N');
    cout << cvert << endl;
#endif

#if LAB_PART > 5
    cout << "---- Part 6: inheritance with class templates ----\n";
    Vertex3D<int> tvert;
    tvert.setZ(44);
    tvert.setY(66);
    cout << tvert << endl;
#endif

    return 0;
}

