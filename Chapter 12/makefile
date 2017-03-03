CC = g++
CFLAGS = -Wall -c

main : main_split.o  
	$(CC) -Wall main_split.o -o main 

main_split.o : split.o
	$(CC) $(CFLAGS) main_split.cpp

split.o : split.cpp Vec.hpp Str.hpp
	$(CC) $(CFLAGS) split.cpp

clobber:
	rm -f *.o core *.exe main 
