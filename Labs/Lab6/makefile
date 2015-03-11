##
# Lab 6 Makefile

all : main

main : main.o shape.o
	g++ -o main main.o shape.o 

main.o : main.cpp  shape.h
	g++ -c main.cpp 

shape.o : shape.cpp shape.h  
	g++ -c shape.cpp 

run : main
	./main

clean : 
	rm -f *.o main
# END OF MAKEFILE 

