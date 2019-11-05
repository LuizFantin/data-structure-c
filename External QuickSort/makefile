all: quicksortExterno

quicksortExterno: main.o quickSortExt.o
	gcc -o quicksortExterno quickSortExt.o main.o

quickSortExt.o: quickSortExt.c quickSortExt.h
	gcc -c quickSortExt.c -o quickSortExt.o

main.o: main.c quickSortExt.h
	gcc -c main.c -o main.o
