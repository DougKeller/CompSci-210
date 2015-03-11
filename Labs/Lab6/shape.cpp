/*
	shape.cpp

	shape class containing all shapes including
	shape, rectangle, and triangle.

        Douglas Keller
        dwk24@zips.uakron.edu
 */
#include "shape.h"

using namespace std;

Shape::Shape(int a, int b, int c){
    sides[0] = a;
    sides[1] = b;
    sides[2] = c;
}

Shape::~Shape(){
    
}

Rectangle::Rectangle(int w, int h){
    sides[0] = h;
    sides[1] = w;
}

Rectangle::~Rectangle(){
    
}

int Rectangle::getHeight(){
    return sides[0];
}

int Rectangle::getWidth(){
    return sides[1];
}

Triangle::Triangle(int a, int b, int c){
    sides[0] = a;
    sides[1] = b;
    sides[2] = c;
}

Triangle::~Triangle(){
    
}

int Triangle::getSideOne(){
    return sides[0];
}

int Triangle::getSideTwo(){
    return sides[1];
}

int Triangle::getSideThree(){
    return sides[2];
}

// Create a dynamically created Shape object (using new operator). 
// Use .push_back(...) member function of vector to add the shape pointer to the vector.
void Container::addShape(int x, int y, int z) {
    shapes.push_back(new Shape(x, y, z));
}

// Create a dynamically created Rectangle object (using new operator).
// Use .push_back(...) member function of vector to add the rectangle pointer to the vector.
void Container::addRectangle(int w, int h) {
    shapes.push_back(new Rectangle(w, h));
}

// Create a dynamically created Triangle object (using new operator).
// Use .push_back(...) member function of vector to add the triangle pointer to the vector.
void Container::addTriangle(int a, int b, int c) {
    shapes.push_back(new Triangle(a, b, c));
}