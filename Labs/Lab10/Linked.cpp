/*
 * Linked.cpp  - Demonstration of STL linked list using insertion sort
 *
 * Douglas Keller
 * dwk24@zips.uakron.edu
 */

#include <iostream>
#include <list>
using namespace std;

template <class T>
void printlist(list<T> lst) {
    class list<T>::iterator it = lst.begin();
    
    for(; it != lst.end(); it++)
        cout << *it << " ";
    
    cout << endl;
    

}

template <class T>
void insertionsort(list<T>& lst) {
    class list<T>::iterator sortedend = lst.begin(), next = sortedend, it;
    next++;
    T nextValue;
    
    while(next != lst.end()){
        
        //checks if next value is > or < last sorted value
        if(*sortedend > *next){
            nextValue = *next;
            lst.erase(next);
            //iterates it to the position suitable for nextValue
            for(it = lst.begin(); *it <= nextValue; it++);
            lst.insert(it, nextValue);
        } else 
            sortedend++;

        next = sortedend;
        next++;
    }

}

int main() {
    list<int> numbers;
    list<int>::iterator it; // iterator

    // populate list "randomly"
    int j = 1;
    for (int i = 1; i < 10; ++i) {
        numbers.push_back(j);
        j = (j + 3037) % 2099; // prime numbers yay!
    }

    printlist(numbers);
       // uncomment for part 2:
        insertionsort(numbers);
        printlist(numbers);
     
    return 0;
}

