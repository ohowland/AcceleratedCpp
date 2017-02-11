CXX = g++
CC = g++

Student_info.o : Student_info.cpp Vec.h Student_info.h

grade.o : grade.cpp Vec.h Student_info.h median.h

main2.o : main2.cpp grade.h median.h Student_info.h

main2 : main2.o grade.o Student_info.o

clobber:
	rm -f *.o core *.exe main2
