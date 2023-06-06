// Linkedlist.h
#ifndef LINKEDLIST_H_EXISTS
#define LINKEDLIST_H_EXISTS
#include "Node.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class Linkedlist{
    public:
    Node* head; // Every linkedlist contains a pointer to the head which is how we will get to and traverse the list.
    int size; // a size integer to keep track of the size of the linked list.
    Linkedlist(); // constructor
    void insert(string value); // inserting a new node into the linkedlist.
    void remove(int index); // removing a node from the linkedlist using an index.
    void print(); // printing the linkedlist.
}; // end Linkedlist.h
#endif

