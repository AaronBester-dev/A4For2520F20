CC = gcc
CFLAGS = -std=c99 -Wall -pedantic


all: tree.o 

tree.o: tree.c
	$(CC) $(CFLAGS) -c tree.c -o tree.o

clean:
	rm -i tree.o 