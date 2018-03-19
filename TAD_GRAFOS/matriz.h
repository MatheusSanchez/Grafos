#ifndef B_PADRAO

#include <stdio.h>
#include <stdlib.h>

#define true 1;
#define false -1;

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
void imprime_matriz(t_grafo_m *mat);
void infos_m(t_grafo_m *g);

#endif