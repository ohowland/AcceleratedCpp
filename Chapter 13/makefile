CC = g++
CFLAGS = -Wall -c

main : main_core.o Student_info.o Core.o grade.o median.o 
	$(CC) -Wall main_core.o Student_info.o Core.o grade.o median.o -o main 

main_core.o : Student_info.o Core.o 
	$(CC) $(CFLAGS) main_core.cpp

Student_info.o : Core.o 
	$(CC) $(CFLAGS) Student_info.cpp

Core.o : grade.o 
	$(CC) $(CFLAGS) Core.cpp 

grade.o : median.o
	$(CC) $(CFLAGS) grade.cpp

median.o :
	$(CC) $(CFLAGS) median.cpp

clobber:
	rm -f *.o core *.exe main 
