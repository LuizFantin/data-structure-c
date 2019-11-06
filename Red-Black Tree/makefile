all: arvoreRubroNegra

arvoreRubroNegra: mainRN.o rubroNegra.o
	gcc -o arvoreRubroNegra rubroNegra.o mainRN.o

rubroNegra.o: rubroNegra.c rubroNegra.h
	gcc -c rubroNegra.c -o rubroNegra.o

mainRN.o: mainRN.c rubroNegra.h
	gcc -c mainRN.c -o mainRN.o
