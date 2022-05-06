.PHONY: clean

main: board.o main.o
	g++ -c main.cpp -o main

board.o: board.cpp board.h
	g++ c-board.cpp

main.o: main.cpp
	g++ c- main.cpp

clean:
	rm *.o main
