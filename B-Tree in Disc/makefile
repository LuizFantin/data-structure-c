all: artmgmt

artmgmt: arvoreB.o main.o 
	gcc -o artmgmt main.o arvoreB.o

arvoreB.o: arvoreB.c arvoreB.h
	gcc -c arvoreB.c -o arvoreB.o

main.o: main.c arvoreB.h
	gcc -c main.c -o main.o
