CC=gcc
GC=g++
CFLAGS= -Wall
DEBUG= -g

all: check generate 
check: check_data.cpp
	$(GC) $(CFLAGS) $(DEBUG) -o check check_data.cpp

generate: generate_data.cpp
	$(GC) $(CFLAGS) $(DEBUG) -o generate_data generate_data.cpp

knuth_shuffle: knuth_shuffle.c
	$(CC) $(CFLAGS) -o knuth_shuffle knuth_shuffle.c

debug: knuth_shuffle.c
	$(CC) $(CFLAGS) $(DEBUG) -o knuth_shuffle knuth_shuffle.c

clean:
	rm -rf knuth_shuffle *.out