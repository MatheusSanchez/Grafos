

#include "grafos.h"

int main(){

	int n_vertices;
	int n_arestas;
	
	char t_grafo,op[3]; // tipo do grafo: matriz ou lista e operação
	char dir; // grafo digrafo

	scanf("%c %c %d %d",&dir,&t_grafo,&n_vertices,&n_arestas);

	grafo *g = cria_grafo(n_vertices,n_arestas,dir,t_grafo); // criamos um grafo e passamos o tipo de estrutura que ele será representado
	
	//infos(g); // da informações gerais do grafo

	while(n_arestas > 0){ // lendo e adicionando todas as arestas
		add_aresta(g);
		n_arestas--;
	}
	getchar();
	
	while(scanf("%s",op) != EOF){ // lendo e executando todas as operações

		op[2] = '\0';
		//printf("operacao %s\n", op);

		getchar();	
		menu(op,g); 
	
	}

	
}

