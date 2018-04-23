#include "matriz.h"

void busca_profundidade_m(t_grafo_m *mat){
	printf("A busca em profundidade no grafo tipo matriz ainda não foi desenvlvida :(\n");
}

void busca_largura_m(t_grafo_m *mat){
	printf("A busca em largura no grafo tipo matriz ainda não foi desenvlvida :(\n");
}

t_grafo_m * cria_grafo_m(int n_vertices,int n_arestas,char dir){ // criando um grafo do tipo matriz

	t_grafo_m *mat = (t_grafo_m*)malloc(sizeof(t_grafo_m)); // alocando a estrutura grafo_m
	mat->no = (int**) malloc(sizeof(int*)*n_vertices);		// alocando a matriz


	for (int i = 0; i < n_vertices; ++i){
		mat->no[i] = (int*) malloc(sizeof(int)*n_vertices);
	}

	for (int i = 0; i < n_vertices; ++i){
		for (int j = 0; j < n_vertices; j++){	//setando para -1 os nós
			mat->no[i][j] = false;  
		}
	}

	mat->n_vertices = n_vertices; // setando informações gerais recebidas por parâmetro
	mat->n_arestas = n_arestas;

	if(dir == 'D'){
		mat->dir = true;	 // grafo direcionado == true
	}else{
		mat->dir = false; // grafo direcionado == false
	}


	return mat;
}
void imprime_matriz(t_grafo_m *mat, int trans){  // imprime a matriz transposta se trans == true

	if(trans == false){ // imprimir grafo não transposto

		for (int i = 0; i < mat->n_vertices; ++i){
			for (int j = 0; j < mat->n_vertices; j++){
				if(mat->no[i][j] < 0){
					printf(". ");
				}else{
					printf("%d ", mat->no[i][j]);
				}
			}
			printf("\n");
		}

	}else if(mat->dir == true){ // só imprimimos o grafo transposto se ele for direcionado;

		for (int i = 0; i < mat->n_vertices; ++i){
			for (int j = 0; j < mat->n_vertices; j++){
				if(mat->no[j][i] < 0){
					printf(". ");
				}else{
					printf("%d ", mat->no[j][i]);
				}
			}
			printf("\n");
		}

	}
	

}

void add_aresta_m(t_grafo_m *mat, int v1 , int v2, int peso){ // função que adiciona uma aresta
	mat->no[v1][v2] = peso;

	if(mat->dir == false){ // se o grafo não for dígrafo precisamos colocar no outro nó
		mat->no[v2][v1] = peso;
	}
}


void infos_m(t_grafo_m *mat){ // função de debug // mostra informações gerais do grafo;
	
	printf("!---------------------!\n");
	printf("Grafo\n");
	printf("Nº vértices: %d\n",mat->n_vertices);
	printf("Nº arestas: %d\n",mat->n_arestas);
	printf("Direcionado: %d\n", mat->dir);
	printf("!---------------------!\n");

}
void adjacentes_m(t_grafo_m *mat, int id){ // imprime os nós adjacentes do nó "ID"
	for (int i = 0; i < mat->n_vertices; ++i){ // toda linha representa um nó
		
		if(mat->no[id][i] != false){ // CUIDADO, no == true implica em no == 1, podem existir pesos diferentes;
			printf("%d ", i);
		}
	}
	printf("\n");
}

void rm_aresta_m(t_grafo_m *mat, int v1 , int v2){ //remove uma aresta

	mat->no[v1][v2] = false;

	if(mat->dir == false){ // se o grafo não for dígrafo precisamos colocar no outro nó
		mat->no[v2][v1] = false;
	}

}

void menor_aresta_m(t_grafo_m *mat){
	int v1,v2; // coordenadas do menor nó

	v1 = v2 = -1; // setados para invalidos


	

	for (int i = 0; i < mat->n_vertices; i++){   // acha o primeiro nó valido
		for (int j = 0; j < mat->n_vertices; j++){
			if(mat->no[i][j] != false){
				v1 = i;
				v2 = j;
				break;
			}
		}
		if(v1 != false){
			break;
		}
	}


	for (int i = 0; i < mat->n_vertices; i++){

		for (int j = 0; j < mat->n_vertices; j++){

			if(mat->no[i][j] != false && mat->no[v1][v2] > mat->no[i][j]){ // CUIDADO COM == TRUE, arestas podem ter pesos
				v1 = i;
				v2 = j;
			}
		}
	}


	printf("%d %d\n", v1,v2);

}

void ordenacao_topologica_m (t_grafo_m *mat){
	printf("Ordenacao topologica não foi implementada para grafos do tipo matriz !\n");
}