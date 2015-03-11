/*
 * ListQue.cpp  - Linked list implementation of a queue
 *
 * Douglas Keller
 * dwk24@zips.uakron.edu
 */

#ifndef LAB_LINKEDQUE
#define LAB_LINKEDQUE

template <class T>
class ListQue {
private:
    struct Node {
        T value;
        Node *next;
        
        Node (T v){
            value = v;
            next = NULL;
        }
    };
    ListQue(const ListQue<T>&);  // disable copy constructor
    Node *head, *tail;           // pointers to head and tail

public:
    ListQue() {
        head = tail = NULL;
    }
    
    virtual ~ListQue() {
        while(tail != NULL)
            pop();
    }

    void push(T val) {
        Node *newNode = new Node(val);
        if(isempty()){
            head = tail = newNode;
            return;
        }
        
        tail->next = newNode; //adds element to end of list
        tail = tail->next;
    }
    
    T pop() {
        Node *temp = head; //preserves pointer to original head while popping
        T value = head->value;
        head = head->next;
        delete temp;
        if(head == NULL) //sets tail to NULL if head is
            tail = NULL;
        return value;
    }
    
    bool isempty() {
        return head == NULL;
    }
};

#endif  // LAB_LINKEDQUE

