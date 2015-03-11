/********************************************************************
  * Lab 12: Structs.cpp
  *
  * Author: Douglas Keller
  *         dwk24@zips.uakron.edu
  *
  * Purpose: Demonstrate the use of structs
  *
  ********************************************************************/

#include <iostream>
using namespace std;


struct Place
{
    string student_address, student_city, student_state;
};

 /**** Part 1: Declaration of structure ****/

    /* YOUR CODE HERE */

struct Student
{
    string name;
    int student_id;
    double total_mark;
    Place residence;
};

    
    // function prototypes


int main() {


    /**** Part 2: Definition of structure ****/
    cout << "---- Part 2: Structure definition ----\n\n";

    Student student1;

    /**** Part 3: Accessing structure members ****/
    cout << "\n---- Part 3: Structure Access ----\n\n";

    /* YOUR CODE HERE */
    cout << "Enter the student name: ";
    cin >> student1.name;
    
    cout << "Enter student Id: ";
    cin >> student1.student_id;
    
    cout << "Enter total marks of the student: ";
    cin >> student1.total_mark;
    
    void print_structure(Student s);
    print_structure(student1);
   

    /**** Part 4: Comparing structure variables ****/
    cout << "\n---- Part 4: Structure Comparison ----\n\n";

    /* YOUR CODE HERE */
    Student student2;
       
    cout << "Enter the student name: ";
    cin >> student2.name;
    
    cout << "Enter student Id: ";
    cin >> student2.student_id;
    
    cout << "Enter total marks of the student: ";
    cin >> student2.total_mark;
    
    if(student1.name == student2.name && student1.student_id == student2.student_id && student1.total_mark == student2.total_mark)
    {
        cout << "\n     Equal values!" << endl;
    } else {
        cout << "\n     Unequal values!" << endl;
    }


    /**** Part 5: Pointer to structure ****/
    cout << "\n---- Part 5: Structure data using pointer ----\n\n";
   
    Student *stdPtr = &student1;
    
    cout << "Enter the student name: ";
    cin >> stdPtr->name;
    
    cout << "Enter student Id: ";
    cin >> stdPtr->student_id;
    
    cout << "Enter total marks of the student: ";
    cin >> stdPtr->total_mark;
    
    void print_structure_using_pointer(Student *p);
    print_structure_using_pointer(stdPtr);
    

    /**** Part 6: Nested structure ****/
    
    cout << "\n---- Part 6: Nested Structure ----\n\n";
    
    cout << "Enter the student address: ";
    cin >> student1.residence.student_address;
    
    cout << "Enter the student city: ";
    cin >> student1.residence.student_city;
    
    cout << "Enter the student state: ";
    cin >> student1.residence.student_state;

    void print_nested_structure(Student *p);
    print_nested_structure(stdPtr);

    return 0;
}



void print_structure(Student s) {
    cout << "\n     Student name: " << s.name << endl;
    cout <<   "     Student id:   " << s.student_id << endl;
    cout <<   "     Student mark: " << s.total_mark << endl;
}

void print_structure_using_pointer(Student *p)
{
    cout << "\n     Student name: " << p->name << endl;
    cout <<   "     Student id:   " << p->student_id << endl;
    cout <<   "     Student mark: " << p->total_mark << endl;
}

void print_nested_structure(Student *p) {
    print_structure_using_pointer(p);
    
    cout << "\n     Student Address: " << p->residence.student_address << endl;
    cout <<   "     Student City:    " << p->residence.student_city << endl;
    cout <<   "     Student State:   " << p->residence.student_state << endl;
}
