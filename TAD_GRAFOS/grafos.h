#ifndef GRAFOS
#define GRAFOS

#include <stdio.h>
#include "lista_adjacencia.h"
#include "matriz.h"

typedef struct t_aresta{

	int v1;
	int v2;
	int peso;	

}aresta;

typedef struct t_grafo{

	t_grafo_m *mat;
	
}grafo;

int tipo_grafo(grafo *g);
void le_aresta();
grafo* cria_grafo(int n_vertices, int n_arestas, char dir, char t_grafo);
void infos(grafo *g);
void imprime_grafo(grafo *g,int trans);
void add_aresta(grafo *g);
void rm_aresta(grafo *g);
void menor_aresta(grafo *g);
#endif