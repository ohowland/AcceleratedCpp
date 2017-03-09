CC = g++
CFLAGS = -Wall -c

main : main_core.o Student_info.o Core.o grade.o median.o 
	$(CC) -Wall main_core.o Student_info.o Core.o grade.o median.o -o main 

ex131 : ex13-1.o Core.o grade.o median.o
	$(CC) -Wall ex13-1.o Core.o grade.o median.o -o ex131
	
ex13-1.o : Core.o
	$(CC) $(CFLAGS) ex13-1.cpp

ex132 : ex13-2.o Core.o grade.o median.o
	$(CC) -Wall ex13-2.o Core.o grade.o median.o -o ex132

ex13-2.o : Core.o
	$(CC) $(CFLAGS) ex13-2.cpp

ex133 : ex13-3.o Student_info.o Core.o grade.o median.o
	$(CC) -Wall ex13-3.o Student_info.o Core.o grade.o median.o -o ex133 

ex13-3.o: Student_info.o
	$(CC) $(CFLAGS) ex13-3.cpp

main_core.o : Student_info.o 
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
