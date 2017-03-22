CC = g++
CFLAG = -Wall -c

main: main.o Picture.o
	$(CC) -Wall main.o Picture.o -o main

main.o: Picture.o 
	$(CC) $(CFLAG) main.cpp

Picture.o:
	$(CC) $(CFLAG) Picture.cpp Ptr.hpp Pic.h
