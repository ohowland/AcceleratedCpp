sent : main_sent.o gen_sentence.o split.h nrand.o
	g++ -Wall main_sent.o gen_sentence.o nrand.o -o sent

xref : main_xref.o xref.o split.h 
	g++ -Wall main_xref.o xref.o -o xref

main_sent.o : gen_sentence.o split.h nrand.o
	g++ -Wall -c main_sent.cpp

gen_sentence.o : split.h nrand.o
	g++ -Wall -c gen_sentence.cpp

main_xref.o : xref.o split.h
	g++ -Wall -c main_xref.cpp

nrand.o : nrand.cpp nrand.h
	g++ -Wall -c nrand.cpp

clobber:
	rm -f *.o core *.exe sent xref
