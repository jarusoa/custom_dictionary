# Dictionary Search and Suggestion Program

## Objective
This project implements a hash table and linked list data structure to create a dictionary application. The program allows users to search for words, suggesting a alternative word when the word is not found, and providing operations like inserting and removing words.

### Skills Learned
- Implementing and using hash tables and linked lists in C++.
- Understanding hashing algorithms and collision handling.
- Utilizing string manipulation and comparison techniques.
- Developing efficient algorithms for similarity scoring.
- Practical experience in I/O operations with files in C++.

### Tools Used
- C++ programming language.
- Custom-built hash table and linked list implementations.
- Simple Timer (`TimeInterval`) for measuring operation durations.

## Steps
### Compilation and Execution
To compile the program, run:
- make

To run the program, use:
- make run

The program will prompt the user to enter a word. After processing the word, it will display results or suggestions.

To clean up compiled files, use:
- make clean

## Features

### Search for a Word
The user provides a word when prompted. The program searches for the word in the dictionary file (Dictionary.txt).
![image](https://github.com/user-attachments/assets/48203fa6-b15e-44a5-b084-de8ac18772a1)


### Suggestion System
If the word is not found, it suggests a similar word based on a custom similarity score.
![image](https://github.com/user-attachments/assets/ab36a1f9-5dc6-4c42-b02f-f19db09a2fe0)

### Results
Depending on the answer from the user whether that simular word was the one they were trying to spell the program will output True or False
based on whether or not its in the dictionary, and any other simular words to that word as well based on the custom simularity score.
