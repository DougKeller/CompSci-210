/*
  shape.h

  Header file for shape class
 *Douglas Keller
 * dwk24@zips.uakron.edu
 */

#ifndef CS2_SHAPE_H
#define CS2_SHAPE_H

#include <iostream>
#include <vector>
using namespace std;

class Shape {
 private :
     int sides[3];
 public :
  Shape(int = 0, int = 0, int = 0);
  ~Shape();

  int getX() {
	return sides[0];
  }

  int getY() {
	return sides[1];
  }
  
  int getZ() {
	return sides[2];
  }
  
  // we will learn more about virtual functions later
  virtual int getPerimeter() {
	return 0;
  }
  
  void output();
};


class Rectangle : public Shape {
 private :
	int sides[2];
 public :
	Rectangle(int = 1, int = 1);
	~Rectangle();

	int getHeight();
	int getWidth();
	
	int getPerimeter() {
		return 2 * getWidth() + 2 * getHeight();
	}
};

class Triangle : public Shape {
 private :
        int sides[3];
 public :
	Triangle(int = 1, int = 1, int = 1);
	~Triangle();

	int getSideOne();
	int getSideTwo();
	int getSideThree();
	
	int getPerimeter() {
		return getSideOne() + getSideTwo() + getSideThree();
	}
};

class Container {
private :
	// a vector of shape objects
	vector<Shape*> shapes;
public :
  Container() {
  
  }
  ~Container() {
  
  }
  
  void addShape(int = 0, int = 0, int = 0);
  void addRectangle(int = 1, int = 1);
  void addTriangle(int = 1, int = 1, int = 1);
  
  int getSize () {
	return shapes.size();
  }
  
  Shape* get(int i = 0) {
	return shapes[i];
  }
};

#endif
