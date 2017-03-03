CC = g++
CFLAGS = -Wall -c

main : main_frame.o frame.o split.o width.o Str.o 
	$(CC) -Wall main_frame.o frame.o split.o width.o Str.o -o main 

main_frame.o : frame.o Str.o
	$(CC) $(CFLAGS) main_frame.cpp

frame.o : width.o Str.o
	$(CC) $(CFLAGS) frame.cpp

width.o : Str.o
	$(CC) $(CFLAGS) width.cpp 

Str.o :
	$(CC) $(CFLAGS) Str.cpp

clobber:
	rm -f *.o core *.exe main 
