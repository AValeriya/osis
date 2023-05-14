CC=gcc
	CFLAGS=-lpthread

all: sort

sort: sort.c
	$(CC) sort.c $(CFLAGS) -o sort

clean:
	rm -f sort

run: sort
	./sort
