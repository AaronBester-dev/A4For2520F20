CFLAGS = -std=c99 -Wall -pedantic
CC = gcc

all: tree.o ttest

tree.o: tree.c
	$(CC) $(CFLAGS) -c tree.c -o tree.o

ttest.o: ttest.c
	$(CC) $(CFLAGS) -c ttest.c -o ttest.o

ttest: ttest.o tree.o
	$(CC) $(CFLAGS) ttest.o tree.o -o ttest

clean:
	rm -i tree.o ttest.o ttest