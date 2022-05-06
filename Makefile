.PHONY: clean

main: main.o mines.o
	g++ main.o mines.o -o main

main.o: main.cpp
	g++ -c main.cpp

mines.o: mines.cpp mines.h
	g++ -c mines.cpp

clean:
	rm *.o main
