

#include "grafos.h"

int main(){

	int n_vertices;
	int n_arestas;
	
	char t_grafo; // tipo do grafo: matriz ou lista
	char dir; // di

	scanf("%c %c %d %d",&dir,&t_grafo,&n_vertices,&n_arestas);

	grafo *g = cria_grafo(n_vertices,n_arestas,dir,t_grafo);
	infos(g);
	

	while(n_arestas > 0){
		add_aresta(g);

		n_arestas--;
	}
	
	imprime_grafo(g,false);	
	rm_aresta(g);
	printf("\n");
	imprime_grafo(g,false);	
	menor_aresta(g);
}

