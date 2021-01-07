.PHONY: all test

all: bin/big_integer

clean:
	rm -rf bin/big_integer *.o

build/src/main.o: src/main.cpp
	g++ -std=c++17 -Wall -Werror -c -o build/src/main.o src/main.cpp

build/src/big_integer.o: src/big_integer.cpp
	g++ -std=c++17 -Wall -Werror -c -o build/src/big_integer.o src/big_integer.cpp

bin/big_integer: build/src/main.o build/src/big_integer.o
	g++ -o bin/big_integer build/src/main.o build/src/big_integer.o