CC=g++
CFLAGS=-lcurl -std=c++11

default:
	make all

all:
	$(CC) -o main main.cpp request.cpp game.cpp jsonParser.cpp $(CFLAGS)

clean:
	rm -f request.o game.o jsonParser.o main
