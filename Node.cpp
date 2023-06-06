// Node.cpp
#include <iostream>
#include <cstdlib>
#include "Node.h"
using namespace std;
// Two constructors, one to make data 0, and the other to create a node with a given integer data.
Node::Node(){ 
    Node::data = "";
    Node::next = NULL;
} // end constructor 1
Node::Node(string data){
    Node::data = data;
    Node::next = NULL;
} // end constructor 2


