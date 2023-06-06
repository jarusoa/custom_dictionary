main: main.o Node.o Linkedlist.o Hashtable.o
		g++ main.o Hashtable.o Linkedlist.o Node.o -o main

main.o: main.cpp Hashtable.h Linkedlist.h Node.h   
		g++ -c main.cpp

Hashtable.o: Hashtable.h Hashtable.cpp
		g++ -c Hashtable.cpp

Linkedlist.o: Linkedlist.h Linkedlist.cpp
		g++ -c Linkedlist.cpp

Node.o: Node.h Node.cpp
		g++ -c Node.cpp

clean:
		rm -f *.o
		rm -f ./main

run: main
		./main

