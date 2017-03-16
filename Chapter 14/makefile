CC = g++
CFLAGS = -Wall -c

mainh : main_handle.o Student_info.o Core.o grade.o median.o 
	$(CC) -Wall main_handle.o Student_info.o Core.o grade.o median.o -o main 

main_handle.o : Student_info.o Handle.o 
	$(CC) $(CFLAGS) main_handle.cpp

Student_info.o : Ptr.o Core.o 
	$(CC) $(CFLAGS) Student_info.cpp

Ptr.o : 
	$(CC) $(CFLAGS) Ptr.hpp

Handle.o :
	$(CC) $(CFLAGS) Handle.hpp

Core.o : grade.o 
	$(CC) $(CFLAGS) Core.cpp 

grade.o : median.o
	$(CC) $(CFLAGS) grade.cpp

median.o :
	$(CC) $(CFLAGS) median.cpp

clobber:
	rm -f *.o core *.exe main
