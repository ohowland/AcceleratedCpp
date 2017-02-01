CC = g++
CFLAGS = -Wall -c

main : main.o PF_Student.o grade.o median.o 
	$(CC) -Wall main.o PF_Student.o grade.o median.o -o main 

main.o : PF_Student.o
	$(CC) $(CFLAGS) main.cpp

PF_Student.o : grade.o
	$(CC) $(CFLAGS) PF_Student.cpp

grade.o : median.o
	$(CC) $(CFLAGS) grade.cpp

median.o : median.cpp median.h
	$(CC) $(CFLAGS) median.cpp
clobber:
	rm -f *.o core *.exe main 
