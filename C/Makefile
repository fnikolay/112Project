CC= gcc -O2 -Wall -Wextra -std=gnu99
CFLAGS=-I.

DEPS = list.h
OBJS =  list.o radixsort.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all:radixsort quicksort mergesort heapsort

radixsort: $(OBJS)
	gcc -o $@ $^ $(CFLAGS)

quicksort : quicksort.c
	$(CC) -o quicksort quicksort.c

mergesort: mergesort.c
	$(CC) -o mergesort mergesort.c

heapsort: heapsort.c
	$(CC) -o heapsort heapsort.c

.PHONY: clean

clean:
	rm -f *.o

spotless: clean
	rm radixsort
	rm quicksort
	rm mergesort
	rm heapsort
