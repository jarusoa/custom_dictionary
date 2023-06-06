// Hashtable.h
#ifndef HASHTABLE_H_EXISTS
#define HASHTABLE_H_EXISTS
#include <iostream>
#include <cstdlib>
#include "Linkedlist.h"
#include "Node.h"
using namespace std;

class Hashtable{
    public:
    Linkedlist table[26]; // Create a array of linkedlists, which is esentially a Hashtable.
    int hash(string key); // Our hash function to get the index in our linkedlist.
    void insert(string value); // uses hash function to located index then inserts value into that linked list using linkedlist method.
    void remove(string value); // uses hash function to located index then removes value from that linked list using linkedlist method.
    void case1(string value); // case1 (Found word and suggest words)
    void case2(string value, int index);
    double getScore(string string1, string string2);
    void print(int index); // Prints a row of the Hashtable.
}; // end Hashtable
#endif

