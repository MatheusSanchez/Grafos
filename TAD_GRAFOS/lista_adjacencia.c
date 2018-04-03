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

void busca_largura_l(t_grafo_l *lis,int ori,int dest){
	
	int cor[lis->n_vertices];
	int dis[lis->n_vertices];
	int prede[lis->n_vertices];
	int fila[lis->n_vertices];
	int i_fila = 0;
	int f_fila = 0;

	for (int i = 0; i < lis->n_vertices; ++i){
		cor[i] = 0; // não visitado
		dis[i] = -1; // não calculada
		prede[i] = -1; 
		fila[i] = -1;
	}

	cor[ori] = 1; // cinza
	dis[ori] = 0;
	prede[ori] = 0;
	fila[0] = ori;

	while(i_fila <= f_fila){

		int k = fila[i_fila];
		t_aresta *aux;
		aux = lis->no[k];

		while(aux != NULL){

			if(cor[aux->v2] == 0){ // white
				cor[aux->v2] = 1; //gray
				dis[aux->v2] = dis[k] + 1;
				prede[aux->v2] = k;
				f_fila++;
				fila[f_fila] = aux->v2;
			}
			aux = aux->prox;
		}

		i_fila++;
		cor[k] = -1;

	}

	/*printf("Visitados\n");
	for (int i = 0; i < lis->n_vertices; ++i){
		printf("%d ", cor[i]);
	}
	printf("\n");

	printf("Predecessores\n");
	for (int i = 0; i < lis->n_vertices; ++i){
		printf("%d ", prede[i]);
	}
	printf("\n");

	printf("Fila\n");
	for (int i = 0; i < lis->n_vertices; ++i){
		printf("%d ", fila[i]);
	}
	printf("\n");

	printf("Distancia\n");
	for (int i = 0; i < lis->n_vertices; ++i){
		printf("%d ", dis[i]);
	}
	printf("\n");*/

	if(prede[dest] != -1){
		busca_l_l(prede,ori,dest);
		printf("\n");
	}else{
		printf("\n");
	}
}

void busca_l_l(int *pre, int ori, int fim){
		
	if(fim == ori){
		printf("%d ",ori);
		return;
	}else{
		busca_l_l(pre,ori,pre[fim]);
		printf("%d ",fim);
	}	


}

void busca_profundidade_l(t_grafo_l *lis,int ori,int dest){
	printf("Salve\n");

}