CC = g++
CFLAGS = -Wall -c

main : main.o Student_info.o grade.o median.o letter_grade.o 
	$(CC) -Wall main.o Student_info.o grade.o median.o letter_grade.o -o main 

main.o : Student_info.o
	$(CC) $(CFLAGS) main.cpp

Student_info.o : grade.o
	$(CC) $(CFLAGS) Student_info.cpp

grade.o : median.o
	$(CC) $(CFLAGS) grade.cpp

median.o : median.cpp median.h
	$(CC) $(CFLAGS) median.cpp

letter_grade.o : letter_grade.cpp letter_grade.h
	$(CC) $(CFLAGS) letter_grade.cpp

clobber:
	rm -f *.o core *.exe main 
