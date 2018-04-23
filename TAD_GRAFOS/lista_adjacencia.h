#ifndef B_PADRAO
#define B_PADRAO

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false -1

#endif

#ifndef GRAFOS_L
#define GRAFOS_L


typedef struct aresta{ // lista de arestar de um vértice

	int peso;
	int v2;
	struct aresta* prox;

}t_aresta;

typedef struct grafo_l{ // grafo do tipo lista, contém n listas + informações gerais do grafo

	t_aresta **no;

	int n_vertices;
	int n_arestas;
	int dir;

}t_grafo_l;

t_grafo_l * cria_grafo_l(int n_vertices,int n_arestas,char dir);
void infos_l(t_grafo_l *lis);
void add_aresta_l(t_grafo_l *list, int v1 , int v2, int peso);
void imprime_lista(t_grafo_l *lis, int trans);
void rm_aresta_l(t_grafo_l *lis, int v1 , int v2);
void menor_aresta_l(t_grafo_l *lis);
void adjacentes_l(t_grafo_l *lis, int id);
void busca_largura_l(t_grafo_l *lis,int ori,int dest);
void busca_l_l(int *pre, int ori, int fim);
void busca_profundidade_l(t_grafo_l *lis,int ori,int dest);
void busca_p_l(t_grafo_l *lis,int *prede,int ori,int dest, int *cor,int *dis,int time, int *pilha, int *ind);
void ordenacao_topologica_l(t_grafo_l *lis);
#endif 