#First make file. Exciting!

OBJS = split_test.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

test : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o test

split_test.o : split_test.cpp split.h
	$(CC) $(CFLAGS) split_test.cpp

clobber:
	rm -f *.o core *.exe test
