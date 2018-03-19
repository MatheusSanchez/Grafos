#ifndef B_PADRAO
#define B_PADRAO

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false -1

#endif

#ifndef GRAFOS_L
#define GRAFOS_L


typedef struct aresta{

	int peso;
	int v2;
	struct aresta* prox;

}t_aresta;

typedef struct grafo_l{

	t_aresta **no;

	int n_vertices;
	int n_arestas;
	int dir;

}t_grafo_l;

t_grafo_l * cria_grafo_l(int n_vertices,int n_arestas,char dir);
void infos_l(t_grafo_l *lis);
void add_aresta_l(t_grafo_l *list, int v1 , int v2, int peso);
void imprime_lista(t_grafo_l *lis, int trans);

#endif 