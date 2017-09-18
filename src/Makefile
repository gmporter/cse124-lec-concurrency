CC=g++
CFLAGS=-ggdb -std=c++11 -Wall -pedantic -pthread

all: example-nolocks example-locks

example-nolocks: main-nolocks.cpp
	$(CC) $(CFLAGS) -o example-nolocks main-nolocks.cpp

example-locks: main-locks.cpp
	$(CC) $(CFLAGS) -o example-locks main-locks.cpp

clean:
	rm -rf example-nolocks example-locks
