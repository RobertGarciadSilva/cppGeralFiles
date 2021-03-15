CC=g++
CFLAGS=-I.
DEPS = Aresta.hpp Grafo.hpp

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tp02: Aresta.o Grafo.o tp02.o 
	$(CC) -o tp02 Grafo.o Aresta.o tp02.o 
