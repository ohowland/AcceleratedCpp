CC = g++
CFLAGS = -Wall -c

main : main.o Student_info.o grade.o median.o 
	$(CC) -Wall main.o Student_info.o grade.o median.o -o main 

main.o : Student_info.o
	$(CC) $(CFLAGS) main.cpp

Student_info.o : grade.o
	$(CC) $(CFLAGS) Student_info.cpp

grade.o : median.o
	$(CC) $(CFLAGS) grade.cpp

median.o : median.cpp median.h
	$(CC) $(CFLAGS) median.cpp
clobber:
	rm -f *.o core *.exe main 
