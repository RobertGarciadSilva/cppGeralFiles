CC=g++
CFLAGS=-I.
DEPS = Grafo.hpp

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tp01: Grafo.o tp1.o 
	$(CC) -o tp01 Grafo.o tp1.o 
