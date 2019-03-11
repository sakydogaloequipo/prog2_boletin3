INCLUDES =-I TAD\

LIBINCLUDES =-L TAD\

INC = $(INCLUDES) $(LIBINCLUDES)

ejecutable: main.o cola.o pila.o listas.o
		gcc -Wall -o ejecutable main.o cola.o pila.o listas.o 

cola.o: TAD\cola.c TAD\cola.h
		gcc -c TAD\cola.c

pila.o: TAD\pila.c TAD\pila.h

		gcc -c TAD\pila.c

listas.o: TAD\listas.c TAD\listas.h
		gcc -c TAD\listas.c
		
clean:
	rm *.o
	rm *.exe
