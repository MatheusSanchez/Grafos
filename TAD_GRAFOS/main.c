

#include "grafos.h"

int main(){

	int n_vertices;
	int n_arestas;
	
	char t_grafo,op[3]; // tipo do grafo: matriz ou lista
	char dir; // di

	scanf("%c %c %d %d",&dir,&t_grafo,&n_vertices,&n_arestas);

	grafo *g = cria_grafo(n_vertices,n_arestas,dir,t_grafo);
	//infos(g);

	while(n_arestas > 0){
		add_aresta(g);
		n_arestas--;

	}
	getchar();
	
	while(scanf("%s",op) != EOF){
		op[2] = '\0';
		//printf("operacao %s\n", op);

		getchar();
		
		menu(op,g);
	
	}

	
}

