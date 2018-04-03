#include "lista_adjacencia.h"

t_grafo_l * cria_grafo_l(int n_vertices,int n_arestas,char dir){

	t_grafo_l *lis = (t_grafo_l*)malloc(sizeof(t_grafo_l)); // alocando a estrutura grafo_l
	
	lis->no = (t_aresta**) malloc(sizeof(t_aresta*)*n_vertices);		// alocando a lista

	lis->n_vertices = n_vertices;
	lis->n_arestas = n_arestas;

	if(dir == 'D'){
		lis->dir = true;	 
	}else{
		lis->dir = false;
	}


	for (int i = 0; i < n_vertices; ++i){
		
		lis->no[i] = NULL;
	}

	return lis;
}

void infos_l(t_grafo_l *lis){ // função de debug

	printf("!---------------------!\n");
	printf("Grafo\n");
	printf("Nº vértices: %d\n",lis->n_vertices);
	printf("Nº arestas: %d\n",lis->n_arestas);
	printf("Direcionado: %d\n", lis->dir);
	printf("!---------------------!\n");

}
void rm_aresta_l(t_grafo_l *lis, int v1 , int v2){// remoção de aresta


	t_aresta *aux ,*ant;
	aux = lis->no[v1];
	ant = lis->no[v1];

	if(lis->no[v1]->v2 == v2){ // removendo o primeiro
		lis->no[v1] = lis->no[v1]->prox;
	}else{
		aux = aux->prox;
		while(aux != NULL && aux->v2 != v2 && aux->v2 < v2){  // aux->v2 > v2
			ant = aux;										// os nós são inseridos ordenados
			aux = aux->prox;								// logo podemos parar de processar se o nó tem valor maior
		}

		if(aux != NULL && aux->v2 == v2){
			ant->prox = aux->prox;
			free(aux);
		
		}
		
		
	}
	

	if(lis->dir == false){

		int s = v1;
		v1 = v2; // trocando os indices
		v2 = s;

		aux = lis->no[v1];
		ant = lis->no[v1];

		if(lis->no[v1]->v2 == v2){ // removendo o primeiro
			lis->no[v1] = lis->no[v1]->prox;
		}else{
			aux = aux->prox;
			while(aux != NULL && aux->v2 != v2 && aux->v2 < v2){ // aux->v2 > v2
				ant = aux;										 	
				aux = aux->prox;								
			}
		
			if(aux != NULL && aux->v2 == v2){
				ant->prox = aux->prox;
				free(aux);
			}
			
		}

	}


}

void add_aresta_l(t_grafo_l *lis, int v1 , int v2, int peso){


	t_aresta *aux = lis->no[v1];
	t_aresta *novo = (t_aresta*)malloc(sizeof(t_aresta)); // alocando o novo nó

	novo->peso = peso;
	novo->v2 = v2;
	novo->prox = NULL;

	if(aux == NULL || aux->v2 > v2){ // primeiro nó

		lis->no[v1] = novo;
		lis->no[v1]->prox = aux;

	}else if(aux->v2 == v2){ // erro conceitual 1

		lis->no[v1]->peso = novo->peso;
		free(novo);

	}else{

		while(aux->prox != NULL && aux->prox->v2 < v2){ // inserção em lista ordenada
			aux = aux->prox;
		}
		if(aux->prox != NULL && aux->prox->v2 == v2){		// erro conceitual, um nó pode ter duas arestas para o mesmo nó com pesos diferentes;
															// entretando há casos no run codes;
			aux->prox->peso = novo->peso;
			free(novo);
		}else{
			novo->prox = aux->prox;
			aux->prox = novo;	
		}
	
		
	}

	if(lis->dir == false && v1 != v2){ // fazendo as arestas da volta para o caso de grafo não direcionado
		
		int s = v1;
		v1 = v2;		// invertendo a coordenada
		v2 = s; 	

		t_aresta *aux = lis->no[v1];
		t_aresta *novo = (t_aresta*)malloc(sizeof(t_aresta)); // alocando o novo nó

		novo->peso = peso;
		novo->v2 = v2;
		novo->prox = NULL;

		if(aux == NULL || aux->v2 > v2){ // primeiro nó

			lis->no[v1] = novo;
			lis->no[v1]->prox = aux;

		}else if(aux->v2 == v2){ //  erro conceitual, um nó pode ter duas arestas para o mesmo nó com pesos diferentes;
								// mas existem casos no run codes assim;
			lis->no[v1]->peso = novo->peso;
			free(novo);

		}else{

			while(aux->prox != NULL && aux->prox->v2 < v2){ // inserção em lista ordenada
				aux = aux->prox;
			}
			if(aux->prox != NULL && aux->prox->v2 == v2){		// erro conceitual
															
				aux->prox->peso = novo->peso;
				free(novo);
			}else{
				novo->prox = aux->prox;
				aux->prox = novo;	
			}
		}
			
	}

}

void imprime_lista(t_grafo_l *lis, int trans){ // 
	if(trans == true && lis->dir == true){ // grafo transposto
		
		int mat[lis->n_vertices][lis->n_vertices]; // vamos passar par auma matriz para facilitar
		t_aresta *aux;

		for (int i = 0; i <  lis->n_vertices; ++i){
			for (int j = 0; j <  lis->n_vertices; ++j){ // pré setando os valores
				mat[i][j] = false;
			}
		}

		for (int i = 0; i < lis->n_vertices; ++i){
			aux = lis->no[i];
			while(aux != NULL){ // passando para matriz
				mat[aux->v2][i] = aux->peso;
				aux = aux->prox;
			}
		}
		for (int i = 0; i <  lis->n_vertices; ++i){ // imprimindo a trasposta
			printf("%d. ", i);
			for (int j = 0; j <  lis->n_vertices; ++j){
				if(mat[i][j] != false){
					printf("%d(%d) ", j,mat[i][j]);
				}
				
			}
			printf("\n");
		}

	}else if(trans == false){
		for (int i = 0; i < lis->n_vertices; ++i){ // imprimindo grafo normal
			t_aresta *aux;
			aux = lis->no[i];

			printf("%d. ", i); // nodo i

			while(aux != NULL){	// arestas do nodo i
				printf("%d(%d) ", aux->v2,aux->peso);
				aux = aux->prox;
			}
			printf("\n");
		}

	}
}

void menor_aresta_l(t_grafo_l *lis){ // achando a menor aresta
	int menor = 0;

	t_aresta *aux,*aux_m;

	aux = lis->no[0];
	aux_m = lis->no[0];

	for (int i = 0; i < lis->n_vertices; ++i){
		aux = lis->no[i];
		while(aux != NULL){
			if(aux_m->peso == 0){ // desconsiderando pesos negativos se o peso for == 0 podemos parar o processamento
				break;
			}
			if(aux_m->peso > aux->peso){
				aux_m = aux;
				menor = i;
			}
			aux = aux->prox;
		}
	}


	printf("%d %d\n",menor,aux_m->v2);

}

void adjacentes_l(t_grafo_l *lis, int id){ // imprimindo os nós adjacentrs
	t_aresta *aux;

	aux = lis->no[id];

	while(aux != NULL){
		printf("%d ", aux->v2);
		aux = aux->prox;
	}
	printf("\n");
}

void busca_profundidade_l(t_grafo_l *lis,int ori,int dest){
	int visitados[lis->n_vertices];
	int resp[lis->n_vertices];

	for (int i = 0; i < lis->n_vertices; ++i){
		visitados[i] = -1;				//vertices nao visitados
		resp[i] = -1;
	}
	int cont = 0;

	visitados[ori] = cont;
	resp[cont] = ori;

	if(ori != dest){
		busca_p_l(lis,ori,visitados,cont,dest,resp);
	}else{
		for (int i = 0; i < lis->n_vertices; ++i){
			if(resp[i] != -1){
				printf("%d ", resp[i]);
			}
		}
	}
	

	
	printf("\n");

}

int busca_p_l(t_grafo_l *lis,int ini,int *visitados,int cont,int dest,int *resp){

	visitados[ini] = cont;
	resp[cont] = ini;
	t_aresta *aux = lis->no[ini];

	while(aux != NULL){
	
		if(aux->v2 != dest){
			if( visitados[aux->v2] == -1){
				printf("%d %d\n", aux->v2,cont);
				if(busca_p_l(lis,aux->v2,visitados,cont+1,dest,resp) == 1){
					return 1;
				}else{
					printf("Retorno %d \n", aux->v2);
					
					//visitados[aux->v2] = -1;		
				}
				
			}
		}else{
		
			for (int i = 0; i < lis->n_vertices; ++i){
				if(resp[i] != -1){
					printf("%d ", resp[i]);
				}
			}
			return 1;
		}
		aux = aux->prox;

		
	}
	printf("no %d -1\n", ini);
	resp[ini] = -1;
	
	return 0;

}