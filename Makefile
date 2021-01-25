.PHONY: all test

all: bin/big_integer bin/test

clean:
	rm -rf bin/big_integer bin/test *.o

build/src/main.o: src/main.cpp
	g++ -std=c++17 -Wall -Werror -c -o build/src/main.o src/main.cpp

build/src/big_integer.o: src/big_integer.cpp
	g++ -std=c++17 -Wall -Werror -c -o build/src/big_integer.o src/big_integer.cpp

build/test/test.o:
	g++ -std=c++17 -Wall -Werror -c -o build/test/test.o test/test.cpp

bin/big_integer: build/src/main.o build/src/big_integer.o
	g++ -o bin/big_integer build/src/main.o build/src/big_integer.o

bin/test: build/test/test.o build/src/big_integer.o
	g++ -o bin/test build/test/test.o build/src/big_integer.o