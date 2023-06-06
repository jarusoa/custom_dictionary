// Linkedlist.cpp
#include <iostream>
#include <cstdlib>
#include "Linkedlist.h"
#include "Node.h"
using namespace std;

Linkedlist::Linkedlist(){ // Constructor makes the head null and the size 0.
    Linkedlist::head = NULL;
    Linkedlist::size = 0;
} // end constructor

void Linkedlist::insert(string value){
    Node* node = new Node(value);
    if(head == NULL){ // if the head is NULL we make the new node with the data as the head and increase size by 1.
        head = node;
        size ++;
        return;
    } // end if 
    if(head->data == value){ // if the head contains the value we are trying to insert, dont insert as we only want unique numbers.
        return;
    } // end if
    // We will traverse the linked list until NULL and insert at the end
    // If we find a node on the way that already contains that value we will exit and not insert.
    Node* currentNode = head;
    while(currentNode->next != NULL){
        if(currentNode->data == value){ // if the number already exists in the list then dont add it. (keep unqiue numbers)
            return;
        } // end if
        currentNode = currentNode->next;
    } // end while
    if(currentNode->data == value){ // if the number already exists in the list then dont add it. (keep unqiue numbers)
        return;
    } // end if
    currentNode->next = node; // So now you arrived at the node before NULL, you can insert after this node
    size ++; // increase size by 1
} // end insert

void Linkedlist::remove(int index){
    if(index + 1 > size){ // if the index is too big for our linked list, simply exit
        return;
    }
    if(index == 0){ // if they delete the first index 
        Node* currentNode = head;
        head = head->next;
        size --;
        delete currentNode;
        return;
    } // end if

    else{
    Node* currentNode = head; // make a node so we can traverse the list to given node to be deleted
    Node* prevNode;
    for(int i = 0; i != index; i++){ // traverse the list and put the prev node into a node pointer and the current is where we are.
        prevNode = currentNode;
        currentNode = currentNode->next;
    } // end for
    
    prevNode->next = currentNode->next; // set the pointer for the prev node to the next of the deleted one
    size --;
    delete currentNode; // delete the node
    } // end else
} // end remove

void Linkedlist::print(){ // traverse the list and print every node until we hit the end of its size.
     if(size == 0){
        return;
    } // end if
    Node* currentNode = head;
    for(int i = 0; i < size; i++){
        if(i + 1 == size){
            cout<< currentNode->data;
        } // end if
        else{
            cout<< currentNode->data << "\n";
        } // end else
        currentNode = currentNode->next;
    } // end for
    cout<< "\n";
} // end getValues

