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
void rm_aresta_l(t_grafo_l *lis, int v1 , int v2){// remoção considerando que o nó exite

	printf("%d %d\n",v1,v2);

	t_aresta *aux ,*ant;
	aux = lis->no[v1];
	ant = lis->no[v1];

	if(lis->no[v1]->v2 == v2){ // removendo o primeiro
		lis->no[v1] = lis->no[v1]->prox;
	}else{
		aux = aux->prox;
		while(aux != NULL && aux->v2 != v2){ 
			ant = aux;
			aux = aux->prox;
		}


		ant->prox = aux->prox;
		free(aux);
	}
	

	if(lis->dir == false){

		int s = v1;
		v1 = v2; // trocando os indicesz
		v2 = s;

		aux = lis->no[v1];
		ant = lis->no[v1];

		if(lis->no[v1]->v2 == v2){ // removendo o primeiro
			lis->no[v1] = lis->no[v1]->prox;
		}else{
			aux = aux->prox;
			while(aux != NULL && aux->v2 != v2){ 
				ant = aux;
				aux = aux->prox;
			}


			ant->prox = aux->prox;
			free(aux);
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

	}else{

		while(aux->prox != NULL && aux->prox->v2 < v2){ // inserção em lista ordenada
			aux = aux->prox;
		}

		novo->prox = aux->prox;
		aux->prox = novo;
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

		}else{

			while(aux->prox != NULL && aux->prox->v2 < v2){ // inserção em lista ordenada
				aux = aux->prox;
			}

			novo->prox = aux->prox;
			aux->prox = novo;
		}
			
	}

}

void imprime_lista(t_grafo_l *lis, int trans){ // 
	if(trans == true && lis->dir == true){
		int mat[lis->n_vertices][lis->n_vertices];
		t_aresta *aux;

		for (int i = 0; i <  lis->n_vertices; ++i){
			for (int j = 0; j <  lis->n_vertices; ++j){
				mat[i][j] = false;
			}
		}

		for (int i = 0; i < lis->n_vertices; ++i){
			aux = lis->no[i];
			while(aux != NULL){
				mat[aux->v2][i] = aux->peso;
				aux = aux->prox;
			}
		}
		for (int i = 0; i <  lis->n_vertices; ++i){
			printf("%d. ", i);
			for (int j = 0; j <  lis->n_vertices; ++j){
				if(mat[i][j] != false){
					printf("%d(%d) ", j,mat[i][j]);
				}
				
			}
			printf("\n");
		}

	}else{
		for (int i = 0; i < lis->n_vertices; ++i){
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

void menor_aresta_l(t_grafo_l *lis){
	int menor = 0;

	t_aresta *aux,*aux_m;

	aux = lis->no[0];
	aux_m = lis->no[0];

	for (int i = 0; i < lis->n_vertices; ++i){
		aux = lis->no[i];
		while(aux != NULL){
			if(aux_m->peso == 0){ // desconsiderando pesos em arestas negativas
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

void adjacentes_l(t_grafo_l *lis, int id){
	t_aresta *aux;

	aux = lis->no[id];

	while(aux != NULL){
		printf("%d ", aux->v2);
		aux = aux->prox;
	}
}