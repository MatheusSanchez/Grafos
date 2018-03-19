# Compilador gcc
CP = gcc
# Parâmetros de compilação
P_CO = -c -lm -Wall -g3

main: matriz.o lista_adjacencia.o main.o grafos.o
	$(CP) grafos.o matriz.o lista_adjacencia.o main.o -o main -lm

all: matriz.o lista_adjacencia.o main.o grafos.o
	$(CP) grafos.o matriz.o lista_adjacencia.o main.o -o main -lm && make clean 

matriz.o: matriz.c
	$(CP) $(P_CO) matriz.c	

lista_adjacencia.o: lista_adjacencia.c
	$(CP) $(P_CO) lista_adjacencia.c	

grafos.o: grafos.c
	$(CP) $(P_CO) grafos.c	

main.o: main.c grafos.o
	$(CP) $(P_CO) main.c

run: main
	./main < entrada.txt

clean: 
	rm -rf *o main

clean_all:	
	rm -rf *o