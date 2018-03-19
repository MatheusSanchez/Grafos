

#include "grafos.h"

int main(){

	int n_vertices;
	int n_arestas;
	
	char t_grafo; // tipo do grafo: matriz ou lista
	char dir; // di

	scanf("%c %c %d %d",&dir,&t_grafo,&n_vertices,&n_arestas);

	grafo *g = cria_grafo(n_vertices,n_arestas,dir,t_grafo);
	infos(g);
	imprime_grafo(g);

	while(n_vertices > 0){
		le_aresta();
		n_vertices--;
	}
	
		


}

