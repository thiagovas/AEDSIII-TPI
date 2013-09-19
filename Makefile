# The option -c in gcc: Compile and assemble, but do not link
CC=gcc

all: build clearafter

build: main.o graph.o vector.o heap.o pair.o queue.o
	$(CC) main.o graph.o vector.o heap.o pair.o queue.o -o tp1

main.o: graph.h pair.h queue.o
	$(CC) -c main.c -o main.o

graph.o: vector.h
	$(CC) -c graph.c -o graph.o

vector.o:
	$(CC) -c vector.c -o vector.o

heap.o: pair.h
	$(CC) -c heap.c -o heap.o

pair.o:
	$(CC) -c pair.c -o pair.o

queue.o: pair.h vector.h
	$(CC) -c queue.c -o queue.o

#Clear temporary files after compiling
clearafter:
	#Option -r: Remove recursive and
	#Option -f: ignore nonexistent files, never prompt
	rm -rf *.o
	rm -rf *~ #Remove temporary files

clear: clearafter
	rm -f tp1
