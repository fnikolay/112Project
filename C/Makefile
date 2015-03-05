CC= gcc -g -O0 -Wall -Wextra -std=gnu99
CFLAGS=-I.

DEPS = list.h
OBJS =  list.o radix.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all:radix quicksort mergesort

radix: $(OBJS)
	gcc -o $@ $^ $(CFLAGS)

quicksort : quicksort.c
	gcc -std=c99 -pedantic -Wall -o quicksort quicksort.c

mergesort: mergesort.c
	gcc -std=c99 -pedantic -Wall -o mergesort mergesort.c

heap: heap.c
	gcc -std=c99 -pedantic -Wall -o heap heap.c

.PHONY: clean

clean:
	rm -f *.o

spotless: clean
	rm radix
	rm quicksort
	rm mergesort
	rm heap
