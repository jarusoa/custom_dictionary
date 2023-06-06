// Node.h
#ifndef NODE_H_EXISTS
#define NODE_H_EXISTS
#include <iostream>
#include <cstdlib>
using namespace std;

class Node{ // Node serves to be used in our Linkedlist class and will contain integer data,a pointer, and constructors.
    public:
    string data;
    Node* next;
    Node();
    Node(string data);
}; // end Node.h
#endif

