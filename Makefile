
findtreasure: main.o treasureFind.o
	g++ main.o treasureFind.o -o findtreasure

main.o: main.cpp
	g++ -c main.cpp

treasureFind.o: treasureFind.cpp treasureFind.h
	g++ -c treasureFind.cpp

clean:
	rm *.o findtreasure