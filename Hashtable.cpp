// Hashtable.cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include "Hashtable.h"
#include "Linkedlist.h"
#include "TimeInterval.h"
#include "Node.h"
using namespace std;


int Hashtable::hash(string key){ // serves to hash a certain key to get an index, in our case an integer
    char x = key.at(0);
    if(islower(x)){
        int index  = (key.at(0)) - 97; // ASCII value - 97 starts with "a"  at index 0 and so on.
        return index;
    }
    else{
        int index  = (key.at(0)) - 65; // ACII value - 65 starts with "A"  at index 0 and so on.
        return index;
    }
} // end hash

void Hashtable::insert(string value){ // find index is hashtable and inserts into linkedlist.
    int index = Hashtable::hash(value);
    table[index].insert(value);
} // end insert

void Hashtable::remove(string value){ // removes a specific number using linked list object's remove method that removes a index
    // Remove a value by finding where its at with a counter index and then removing that index from the linkedlist.
    int index = Hashtable::hash(value);
    if(index > (sizeof(table)/sizeof(Linkedlist) - 1)){
        return;
    }
    Node* currentNode = table[index].head;
    int index2 = 0;
    while(currentNode->data != value){
        currentNode = currentNode->next;
        index2 = index2 + 1;
        if(index2 + 1 > table[index].size ){
            return;
        }
    } // end while
    table[index].remove(index2);
} // end remove

void Hashtable::case1(string value){
    int index = Hashtable::hash(value);
    Node* currentNode = table[index].head; // start at the head

    while(currentNode != NULL){

        if(strcasecmp((currentNode->data).c_str(),value.c_str()) == 0){ // if we find the value
            cout << "True" << "\n";
            TimeInterval time;
            if(value.length() > 2){ // if the word has more than two letters we will search for words that have the first two letters
            time.start(); // start time
            Node* currentNode = table[index].head; // start back at the head
            value[0] = tolower(value[0]);
            int word = value.at(0) + value.at(1); // grab the first two letters according to their ASCII values and add so we can find words simular
                //TimeInterval time;
                //time.start();
                while(currentNode != NULL){ // while we have nodes to search
                    if(currentNode->data.length() > 2){ // if the node we are looking at has more than two letters
                        if(currentNode->data.at(0) +  currentNode->data.at(1)  == word && strcasecmp((currentNode->data).c_str(),value.c_str()) != 0){ // if we find a word that has the same two letters according to ASCII values and it isnt the actual word
                        cout << currentNode->data << "\n"; // Print suggested word
                        } // end if
                    } // end if
                    currentNode = currentNode->next;
                } // end while
                time.stop(); // stop time
                cout << "Operation time: " << time.GetInterval();
                cout << "\n";
                return;
            } // end if
            return;
        } // end if
        currentNode = currentNode->next;
        } // end while
        Hashtable::case2(value,index); // if we didnt find the matching word we will check for mispelling using case2 function.
    } // end case1

void Hashtable::case2(string value, int index){
    double lowestscore = 0; // holds the lowest score (most simular) index 
    double score; // the score we will get everytime we check the nodes data with our user input.
    string word; // store the suggested word if one is returned.
    string response; // get response from user on the suggested word

    value[0] = tolower(value[0]); // make input lower case for comparsion purposes
    
    // Calculate the score for all strings starting with our inputs letter and keep the lowest one if its below 0;
    Node* currentNode = table[index].head;
    while(currentNode != NULL){
        score = getScore(currentNode->data,value);
        if(score < lowestscore){
            lowestscore = score;
            word = currentNode->data;
        } // end if
        currentNode = currentNode->next;
    } // end while

    if(lowestscore <= -3){ // lowest threshold for reccomending a word, in testing seems to make the most sense and not recommend a word unless it has a certain degree of simularity
        cout << "do you mean " << word << "? ";
        cin >> response;
        if(response == "yes"){ // if the user identifies the suggested word as the word they meant to type
            case1(word);
        } // end if
        if(response == "no"){ // if the user didn't mean the suggested word
            cout << "False";
	    cout << "\n";
        } // end if 
    } // end if

    if(lowestscore > -3){ // NO RESEMBLANCE
        cout << "False";
	cout << "\n";
    } // end if
    
    
} // end case2

double Hashtable::getScore(string string1, string string2){
double score = 0; // this will hold out final score for the comparsion, (lower is more similar while a higher score is more different)
int match = 0; // this integer will find how many chracters match while not counting location or repetition. 
vector<char> v; // vector to hold past matched letters

// length comparsion score
// matching characters
// matching postions

if(string1.size() < string2.size()){ // if the first string is less (in length) we will swap values to keep length comparsion and other for loops functioning correctly.
    string1.swap(string2);
}

    // LENGTH COMPARSION
    score = score + (string1.size() - string2.size()); // we add the difference of the two strings to score as the bigger the difference the less similar the words are

    // MATCHING CHARACTERS REGARDLESS OF POSITION
    for(int i = 0; i < string1.size(); i ++){ // for the length of string 1 
        for(int j = 0; j < string2.size(); j ++){ // for the length of string 2
            if(string2[j] == string1[i]){ // if string2 character is within string1, POSITION DOESNT MATTER
                char x = string2[j]; // put string 2 char in x 
                if(find(v.begin(),v.end(),x) != v.end()){ } // end find // IMPORTANT:: finds whether we have already had that letter add to match, as we dont want to make its score less (increase similarity) for a letter more than once.
                
                else{ // if we havent decreased the score for that letter that matched 
                    match ++; // increase match by 1
                    v.push_back(string2[j]); // push the letter into our vector so we dont decrease score(increase similarity) more than once for that letter.  
                } // end else
            } // end if
        } // end for
    } // end for

    score = score  - match; // for the amount of letters that matched regardless of position, we will decrease the score by that much

    // MATCHING POSITIONS
    for(int i = 0; i < string2.size(); i++){
        if(string2[i] == string1[i]){
            score --; // for every exact match in postion we will descrease the score (increase similarity)
        } // end if
    } // end for

    return score;


} // end getScore

void Hashtable::print(int index){
    table[index].print();
} // end getValues



