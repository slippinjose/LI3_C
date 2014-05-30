CC = gcc
CFLAGS = -O2 -ansi

authors: authors.o Estatistica.o Indice.o Catalogo.o
	$(CC) $(CFLAGS) -o authors authors.o Estatistica.o Indice.o Catalogo.o

authors.o: authors.c Estatistica.h Indice.h
	$(CC) $(CFLAGS) -c authors.c

Indice.o: Indice.c Indice.h
	$(CC) $(CFLAGS) -c Indice.c

Estatistica.o: Estatistica.c Estatistica.h
	$(CC) $(CFLAGS) -c Estatistica.c

Catalogo.o: Catalogo.c Catalogo.h
	$(CC) $(CFLAGS) -c Catalogo.c

clean: 
	rm  -rf *.o 
