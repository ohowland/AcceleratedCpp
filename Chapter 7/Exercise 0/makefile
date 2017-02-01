sent : main_sent.o split.o nrand.o
	g++ -Wall main_sent.o split.o nrand.o -o sent

xref : main_xref.o xref.o split.o
	g++ -Wall main_xref.o split.o xref.o -o xref

main_sent.o : split.o nrand.o
	g++ -Wall -c main_sent.cpp

main_xref.o : xref.o split.o
	g++ -Wall -c main_xref.cpp

split.o : split.cpp split.h
	g++ -Wall -c split.cpp

nrand.o : nrand.cpp nrand.h
	g++ -Wall -c nrand.cpp

clobber:
	rm -f *.o core *.exe sent xref
