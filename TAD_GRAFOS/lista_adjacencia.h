#ifndef B_PADRAO
#define B_PADRAO

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false -1

#endif

#ifndef GRAFOS_L
#define GRAFOS_L

typedef struct no_l t_no_l;

typedef struct grafo_l{

	int n_vertices;
	char dir;
	struct no_l *lista;

}t_grafo_l;



typedef struct aresta{
	struct aresta *next;
	int peso;
	int id;

}t_aresta;

struct no_l{
	int id;
	t_aresta *aresta;
};


typedef struct coordenada_l{
	int v1;	
	int v2;
	int peso;	
}t_coordenada_l;



t_grafo_l* cria_grafo_l(int n_vertices,char dir);
void adiciona_aresta_l(t_grafo_l* g,t_coordenada_l *aux);
void le_coordenada_l(t_coordenada_l *aux);
void exibe_grafo_l(t_grafo_l* g,int n_vertices,int transposta);
void remove_aresta_l(t_grafo_l* g,t_coordenada_l *aux);
void aresta_menor_l(t_grafo_l* g,int n_vertices);
#endif 