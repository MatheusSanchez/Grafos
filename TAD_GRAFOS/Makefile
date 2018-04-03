# Compilador gcc
CP = gcc
# Parâmetros de compilação
P_CO = -c -lm -Wall -g3 -std=gnu99

main: matriz.o lista_adjacencia.o grafos.o main.o 
	$(CP) grafos.o matriz.o lista_adjacencia.o main.o -o main -lm

all: matriz.o lista_adjacencia.o main.o grafos.o
	$(CP) grafos.o matriz.o lista_adjacencia.o main.o -o main -lm 

grafos.o: grafos.c matriz.o lista_adjacencia.o
	$(CP) $(P_CO) grafos.c	

matriz.o: matriz.c
	$(CP) $(P_CO) matriz.c	

lista_adjacencia.o: lista_adjacencia.c
	$(CP) $(P_CO) lista_adjacencia.c	

main.o: main.c grafos.o
	$(CP) $(P_CO) main.c

run: main
	./main 

clean: 
	rm -rf *o main

clean_all:	
	rm -rf *o

zip: 
	zip trab main.c lista_adjacencia.c lista_adjacencia.h matriz.c matriz.h grafos.c grafos.h Makefile
