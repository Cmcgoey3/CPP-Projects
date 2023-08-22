CC=g++
CFLAGS=-O2

all: recursiveFib dynamicFib

recursiveFib: recursiveFib.cpp
	$(CC) $(CFLAGS) -o recursiveFib recursiveFib.cpp

dynamicFib: dynamicFib.cpp
	$(CC) $(CFLAGS) -o dynamicFib dynamicFib.cpp

clean:
	rm -f recursiveFib dynamicFib
