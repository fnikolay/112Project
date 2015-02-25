CC= gcc -g -O0 -Wall -Wextra -std=gnu99
CFLAGS=-I.

DEPS = list.h
OBJS =  list.o radix.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all:radix

radix: $(OBJS)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o
