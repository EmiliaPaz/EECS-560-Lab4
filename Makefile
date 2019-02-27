Lab4: main.o Executive.o ItemNotFoundException.o
	g++ -std=c++11 -g -Wall main.o Executive.o ItemNotFoundException.o -o Lab4
main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
Executive.o: Executive.h Executive.cpp HashTable_Open.h HashTable_Open.hpp LinkedList.h LinkedList.hpp Node.h Node.hpp HashTable_Closed.h HashTable_Closed.hpp ItemNotFoundException.h ItemNotFoundException.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp
ItemNotFoundException.o: ItemNotFoundException.h ItemNotFoundException.cpp
	g++ -std=c++11 -g -Wall -c ItemNotFoundException.cpp
clean:
	rm *.o Lab4
