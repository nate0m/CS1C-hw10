CC = g++
FLAGS = -std=c++14 -Wall

all: hw10

hw10: hw10.cpp
	$(CC) $(FLAGS) hw10.cpp -o hw10.o

clean:
	rm hw10 *.o

tar:
	tar cf hw10.tar hw10.scr Makefile hw10.cpp
