#ifndef B_PADRAO
#define B_PADRAO
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false -1

#endif

#ifndef GRAFOS_M
#define GRAFOS_M


typedef struct grafo{

	int **no;

	int n_vertices;
	int n_arestas;
	int dir;

}t_grafo_m;


t_grafo_m * cria_grafo_m(int n_vertices,int n_arestas,char dir);
void imprime_matriz(t_grafo_m *mat, int trans);
void infos_m(t_grafo_m *mat);
void add_aresta_m(t_grafo_m *mat, int v1 , int v2, int peso);
void adjacentes_m(t_grafo_m *mat, int id);
void rm_aresta_m(t_grafo_m *mat, int v1 , int v2);
void menor_aresta_m(t_grafo_m *mat);

#endif