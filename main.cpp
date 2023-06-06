// main.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "Hashtable.h"
#include "Linkedlist.h"
#include "Node.h"
using namespace std;


int main(){
Hashtable tab;
string word;
string line;
fstream fin;
////////////////////
fin.open("Dictionary.txt",ios::in);
if(!fin){
    cout << "Not existing";
}
while(fin >> line){
    tab.insert(line);
} // end while

fin.close();
////////////////////

cout << "Search word: ";
cin >> word;
tab.case1(word);

return 0;
} // end main

