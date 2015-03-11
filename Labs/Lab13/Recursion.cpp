/*
 * Recursion.cpp  - Practice writing and converting recursion
 *
 * Douglas Keller
 * dwk24@zips.uakron.edu
 */

#include <iostream>
using namespace std;

// prototypes
template <class T>
void printarray(const T[], int);
void chew_system_stack();

/*
 * Recursive version of fibonacci
 */
int fibrecurse(int n) {
    if(n < 1)
        return 0;
    if(n == 1)
        return 1;
    
    return fibrecurse(n - 1) + fibrecurse(n - 2);
}

/*
 * Iterative (loop) version of fibonacci
 */
int fibiterate(int n) {
    
    if(n < 1)
        return 0;

    int prev = 0, curr = 1;
    
    for(int i = 1; i < n; i++){
        int temp = curr;
        
        curr = prev + curr;
        
        prev = temp;
    }

    return curr;
}

/*
 * Recursive quicksort
 */
template <class T>
void quicksort(T ar[], int first, int last) {
    if(first >= last)
        return;
   
    int bound = first;
    T pivot = ar[first];
    
    for(int i = first + 1; i <= last; i++){
        if(ar[i] < pivot){
            bound++;
            swap(ar[i], ar[bound]);
        } 
    }
    
    swap(ar[first], ar[bound]);
    
    quicksort(ar, first, bound - 1);
    quicksort(ar, bound + 1, last);
}

int main() {
    const int FIBLOOPS = 10;
    const int ARSIZ = 16;
    int ar[ARSIZ];

    cout << "Recursive fib: ";
    for(int i=0;i<FIBLOOPS;++i) {
        cout << fibrecurse(i) << " ";
    }
    cout << endl;
    cout << "Iterative fib: ";
    for(int i=0;i<FIBLOOPS;++i) {
        cout << fibiterate(i) << " ";
    }
    cout << endl;

    cout << "Quicksort:" << endl;
    // populate random array
    for(int i=0;i<ARSIZ;++i) {
        ar[i] = (i * 3037) % 2099;  // prime numbers! again!
    }
    printarray(ar, ARSIZ);
    quicksort(ar, 0, ARSIZ-1);
    printarray(ar, ARSIZ);

    //cout << "Chewing system stack:" << endl;
    chew_system_stack();

    return 0;
}

/*  utility functions, do not modify  */
template <class T>
void printarray(const T ar[], int s) {
    for(int i=0;i<s;++i) {
        cout << ar[i] << " ";
    }
    cout << endl;
}

void printstackpointer() {
    void * stack_pointer;
    // inline assembly language to get stack pointer
    __asm__ __volatile__("movl  %%esp,%%eax"
                             :"=a"(stack_pointer)
                             );
    cout << stack_pointer << endl;
}

void chew_system_stack() {
    // Feel free to play with this, but please
    // do NOT enable this for your final commit!
    //printstackpointer();
    //chew_system_stack();
}
/* end utilities */

