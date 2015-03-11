/*
 * Rectangle.cpp
 *
 * Demonstration of classes using a simple
 * rectangle object.
 *
 * Douglas Keller
 * dwk24@zips.uakron.edu
 */

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

class Rectangle {
private:
    int height;
    int width;
    int perimeter;
    char *name;
    void calculatePerimeter();
    void setName(const char * const);

public:
    Rectangle();
    Rectangle(int, int);
    Rectangle(const char * const);
    ~Rectangle();
    
    void setWidth(int);
    void setHeight(int);
    int getWidth() const;
    int getHeight() const;

    int getPerimeter() const;
    void printout();
};

Rectangle::Rectangle() {
    setName("Rectangle");
    setHeight(1);
    setWidth(1);
}

Rectangle::Rectangle(int w, int h){
    setName("Rectangle");
    setHeight(h);
    setWidth(w);
}

Rectangle::Rectangle(const char * const n){
    setName(n);
    setHeight(1);
    setWidth(1);
}

Rectangle::~Rectangle(){
    delete[] name;
}

void Rectangle::setName(const char * const n){
    int length = strlen(n);
    name = new char[length + 1];
    strncpy(name, n, length);
    
}

void Rectangle::setWidth(int w) {
    width = (w < 1) ? 1 : w;
    calculatePerimeter();
}

void Rectangle::setHeight(int h) {
    height = (h < 1) ? 1 : h;
    calculatePerimeter();
}

int Rectangle::getWidth() const{
    return width;
}

int Rectangle::getHeight() const{
    return height;
}

int Rectangle::getPerimeter() const{
    return perimeter;
}

void Rectangle::calculatePerimeter(){
    perimeter = 2 * (getWidth() + getHeight());
}

void Rectangle::printout() {
    cout << name << "{" << width << "," << height << "}";
}

int main() {

    Rectangle r1("Doug's Rectangle ");

    /*
     * Part 1
     */
    cout << "--------- Part 1: Overloaded constructor ---------\n";
    const int TESTWIDTH_1  = 3;
    const int TESTHEIGHT_1 = 10;

    /*** modify this line: ***/
    Rectangle r2(TESTWIDTH_1, TESTHEIGHT_1);    // use overloaded constructor

    // Test cases. Do not modify.
    cout << "Test Case 1 (getwidth == 1): ";
    if (r1.getWidth() == 1) {
        cout << "Pass\n";
    } else {
        cout << "Fail\n";
    }
    cout << "Test Case 2 (getheight == 1): ";
    if (r1.getHeight() == 1) {
        cout << "Pass\n";
    } else {
        cout << "Fail\n";
    }
    cout << "Test Case 3 (getwidth == " << TESTWIDTH_1 << "): ";
    if (r2.getWidth() == TESTWIDTH_1) {
        cout << "Pass\n";
    } else {
        cout << "Fail\n";
    }
    cout << "Test Case 4 (getheight == " << TESTHEIGHT_1 << "): ";
    if (r2.getHeight() == TESTHEIGHT_1) {
        cout << "Pass\n";
    } else {
        cout << "Fail\n";
    }


    /*
     * Part 2
     */
    cout << "--------- Part 2: Setter parameter validation ---------\n";
    
    r1.setWidth(-5);
    r1.setHeight(-400);

    cout << "Test Case 1 (getwidth > 0): ";
    if (r1.getWidth() > 0) {
        cout << "Pass\n";
    } else {
        cout << "Fail\n";
    }
    cout << "Test Case 2 (getheight > 0): ";
    if (r1.getHeight() > 0) {
        cout << "Pass\n";
    } else {
        cout << "Fail\n";
    }


    /*
     * Part 3
     */
    cout << "--------- Part 3: Const functions ---------\n";
    const int TESTWIDTH_3  = 16;
    const int TESTHEIGHT_3 = 112;
    const int TESTPERIM_3  = 256;

    r1.setWidth(TESTWIDTH_3);
    r1.setHeight(TESTHEIGHT_3);

    cout << "Test Case 1 (getperimeter of ";
    r1.printout();
    cout << " == " << TESTPERIM_3 << "): ";
    if (r1.getPerimeter() == TESTPERIM_3) {
        cout << "Pass\n";
    } else {
        cout << "Fail\n";
    }


    /*
     * Part 4
     */
    cout << "--------- Part 4: Private functions ---------\n";
    const int TESTWIDTH_4  = 256;
    const int TESTHEIGHT_4 = 512;

    r1.setWidth(TESTWIDTH_4);
    r1.setHeight(TESTHEIGHT_4);

    cout << "Test Case 1: perimeter of ";
    r1.printout();
    cout << " is " << r1.getPerimeter() << endl;

    /*
     * Part 5
     */
    cout << "--------- Part 5: Destructors ---------\n";
    cout << "(if rectangles have names, then this part passed)" << endl;

    return 0;
}

