

#include "grafos.h"

int main(){

	int n_vertices;
	int n_arestas;
	
	char t_grafo,op[3]; // tipo do grafo: matriz ou lista e operação
	char dir; // grafo digrafo

	//scanf("%c %c %d %d",&dir,&t_grafo,&n_vertices,&n_arestas); // leitura padrao
	//leitura do ex dois 2
	scanf("%d %d",&n_vertices,&n_arestas);

	dir = 'D'; // grafo direcionado
	t_grafo = 'L'; // representação por matriz;
	op[0] = 'B';
	op[1] = 'U';
	op[2] = '\0';
	grafo *g = cria_grafo(n_vertices,n_arestas,dir,t_grafo); // criamos um grafo e passamos o tipo de estrutura que ele será representado
	
	//infos(g); // da informações gerais do grafo

	// leitura padrão na função le_aresta alterada para fins do ex2;
	while(n_arestas > 0){ // lendo e adicionando todas as arestas
		add_aresta(g);
		n_arestas--;
	}
	//getchar();

	//leitura geral de operações
	/*
	while(scanf("%s",op) != EOF){ // lendo e executando todas as operações

		op[2] = '\0';
		//printf("operacao %s\n", op);

		getchar();	
		menu(op,g); 
	
	}*/
	infos(g); 
	// leitura especifica do ex 2

	while(getchar() != EOF){ // lendo e executando todas as operações
		menu(op,g); 
	
	}

	
}

