/*
	CS 2: Lab 6
	
	Main function for testing
 *      Douglas Keller
 *      dwk24@zips.uakron.edu
 */
 
#include "shape.h"

// Change according to which part of lab
// you are working on.
#define PART 3

using namespace std;

void testPartOne();
void testPartTwo();
void testPartThree();

int main() {

	#if PART > 0
	testPartOne();
	#endif

	#if PART > 1
	testPartTwo();
	#endif

	return 0;
}

void testPartOne () {
	
	#if PART > 2
	cout << "-- Part 1 & 3 Testing: --" << endl;
	#else
	cout << "-- Part 1 Testing: --" << endl;
	#endif
	
	{
		Shape * s = new Shape();
		Rectangle * r = new Rectangle();
		Triangle * t = new Triangle();
		
		if (s->getX() == 0 && s->getY() == 0 && s->getZ() == 0) {
			cout << "Pass: Shape coordinates are (0, 0, 0)"  << endl;
		}
		else {
			cout << "Fail: Shape coordinates are ("  << s->getX() 
				<< ", " << s->getY() << ", " << s->getZ() 
				<< ") not (0, 0, 0)"<< endl;
		}
		
		int perimeter = s->getPerimeter();
		if (perimeter == 0) {
			cout << "Pass: Perimeter of Shape is " << perimeter << endl;
		}
		else {
			cout << "Fail: Perimeter of Shape is " << perimeter << " not 0" << endl;
		}
		
		perimeter = r->getPerimeter();
		if (perimeter == 4) {
			cout << "Pass: Perimeter of Rectangle is " << perimeter << endl;
		}
		else {
			cout << "Fail: Perimeter of Rectangle is " << perimeter << " not 4" << endl;
		}
		
		perimeter = t->getPerimeter();
		if (perimeter == 3) {
			cout << "Pass: Perimeter of Triangle: " << perimeter << endl;
		}
		else {
			cout << "Fail: Perimeter of Triangle is " << perimeter << " not 3" << endl;
		}
		
		delete s;
		delete r;
		delete t;
	}
	{
		Shape * s = new Shape(1, 2, 0);
		Rectangle * r = new Rectangle(4, 5);
		Triangle * t = new Triangle(3, 4, 5);
		
		if (s->getX() == 1 && s->getY() == 2 && s->getZ() == 0) {
			cout << "Pass: Shape coordinates are (1, 2, 0)"  << endl;
		}
		else {
			cout << "Fail: Shape coordinates are ("  << s->getX() 
				<< ", " << s->getY() << ", " << s->getZ() 
				<< ") not (1, 2, 0)"<< endl;
		}
		
		int perimeter = s->getPerimeter();
		if (perimeter == 0) {
			cout << "Pass: Perimeter of Shape is " << perimeter << endl;
		}
		else {
			cout << "Fail: Perimeter of Shape is " << perimeter << " not 0" << endl;
		}
		
		perimeter = r->getPerimeter();
		if (perimeter == 18) {
			cout << "Pass: Perimeter of Rectangle is " << perimeter << endl;
		}
		else {
			cout << "Fail: Perimeter of Rectangle is " << perimeter << " not 18" << endl;
		}
		
		perimeter = t->getPerimeter();
		if (perimeter == 12) {
			cout << "Pass: Perimeter of Triangle is 12" << endl;
		}
		else {
			cout << "Fail: Perimeter of Triangle is " << perimeter << " not 12" << endl;
		}
		
		delete s;
		delete r;
		delete t;
	}
}

void testPartTwo () {
	cout << "-- Part 2 Testing: --" << endl;
	
	Container * c = new Container();
	
	if (c->getSize() == 0) {
		cout << "Pass: Container size is 0" << endl;
	}
	else {
		cout << "Fail: Container size is " << c->getSize() << " not 0" << endl;
	}
	
	c->addShape();

	if (c->getSize() == 1) {
		cout << "Pass: Container size is 1" << endl;
	}
	else {
		cout << "Fail: Container size is " << c->getSize() << " not 1" << endl;
	}
	
	c->addRectangle(8, 12);
	c->addTriangle(2, 2, 2);
	c->addTriangle();
	c->addRectangle();
	
	if (c->getSize() == 5) {
		cout << "Pass: Container size is 5" << endl;
	}
	else {
		cout << "Fail: Container size is " << c->getSize() << " not 5" << endl;
	}
	
	Rectangle* s = (Rectangle*)c->get(1);
	int w = s->getWidth();
	int h = s->getHeight();
	if (w == 8 && h == 12) {
		cout << "Pass: Width and Height of Rectangle at location 1 is 8, 12" << endl;
	}
	else {
		cout << "Fail: Width and Height of Rectangle at location 2 is " << w << ", " << h << " not 8, 12" << endl;
	}
	
	Shape* s1 = c->get(2);
	int perimeter = s1->getPerimeter();
	if (perimeter == 6) {
		cout << "Pass: Perimeter of Triangle at location 2 is 5" << endl;
	}
	else {
		cout << "Fail: Perimeter of Triangle at location 2 is " << perimeter << " not 6" << endl;
	}
	Shape* s2 = c->get(4);
	perimeter = s2->getPerimeter();
	if (perimeter == 4) {
		cout << "Pass: Perimeter of Rectangle at location 4 is 4" << endl;
	}
	else {
		cout << "Fail: Perimeter of Rectangle at location 4 is " << perimeter << " not 4" << endl;
	}
	
	delete c;
	delete s;
	delete s1;
	delete s2;
}
