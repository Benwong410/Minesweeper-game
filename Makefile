.PHONY: clean

main: gcd.cpp
	g++ -c main.cpp

clean:
	rm *.o calc
