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
	printf("AE\n");
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
	if(trans == true){
		printf("Lista Transposta\n");
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


/*
t_grafo_l* cria_grafo_l(int n_vertices,char dir){

	t_grafo_l *g = (t_grafo_l*)malloc(sizeof(t_grafo_l));

	g->n_vertices = n_vertices;
	g->dir = dir;

	g->lista = (t_no_l*) malloc(sizeof(t_no_l)*n_vertices);

	for (int i = 0; i < n_vertices; ++i){
		g->lista[i].aresta = NULL;
	}

	return g;

}

void adiciona_aresta_l(t_grafo_l* g,t_coordenada_l *aux){

	t_aresta *nova_aresta = malloc(sizeof(t_aresta));
	nova_aresta->next = NULL;
	nova_aresta->peso = aux->peso;
	nova_aresta->id = aux->v2;

	t_aresta *aresta_aux = g->lista[aux->v1].aresta;
	
	if(aresta_aux == NULL){
		g->lista[aux->v1].aresta = nova_aresta;
	}else{

		while(aresta_aux->next != NULL && aresta_aux->next->id < nova_aresta->id){
			aresta_aux = aresta_aux->next;
		}
		nova_aresta->next = aresta_aux->next;
		aresta_aux->next = nova_aresta;

	}
	
	if(g->dir == 'D'){

		t_aresta *nova_aresta = malloc(sizeof(t_aresta));
		nova_aresta->next = NULL;
		nova_aresta->peso = aux->peso;
		nova_aresta->id = aux->v1;

		t_aresta *aresta_aux = g->lista[aux->v2].aresta;
		
		if(aresta_aux == NULL){
			g->lista[aux->v2].aresta = nova_aresta;
		}else{

			while(aresta_aux->next != NULL && aresta_aux->next->id < nova_aresta->id){
				aresta_aux = aresta_aux->next;
			}
			nova_aresta->next = aresta_aux->next;
			aresta_aux->next = nova_aresta;

		}

	}



}
void remove_aresta_l(t_grafo_l* g,t_coordenada_l *aux){

	t_aresta *aresta = g->lista[aux->v1].aresta;
	t_aresta *aresta_aux;
	if(aresta->id == aux->v2){
		g->lista[aux->v1].aresta = aresta->next;
		free(aresta);
	}else{

		while(aresta->next->id != aux->v2){
			aresta = aresta->next;
		}

		aresta_aux = aresta->next;
		aresta->next = aresta->next->next;

		free(aresta_aux);
	}


}

void le_coordenada_l(t_coordenada_l *aux){
	scanf("%d %d %d",&(aux->v1),&(aux->v2),&(aux->peso));
}
void exibe_grafo_l(t_grafo_l* g,int n_vertices,int transposta){
	t_aresta *aux;
	if(transposta == 0){
		for (int i = 0; i < n_vertices; ++i){
			aux = g->lista[i].aresta;

			printf("%d.", i);

			while(aux != NULL){
				printf(" %d(%d)", aux->id,aux->peso);
				aux = aux->next;
			}
			printf("\n");
		}
	}else{
		int **matriz = malloc(sizeof(int*)*g->n_vertices);

		for (int i = 0; i < n_vertices; ++i){
			matriz[i] = calloc(g->n_vertices,sizeof(int));
		}

		for (int i = 0; i < n_vertices; ++i){
			aux = g->lista[i].aresta;

			while(aux != NULL){
				matriz[i][aux->id] = aux->peso;
				aux = aux->next;
			}
		}


		for (int i = 0; i < n_vertices; ++i){
			printf("%d.", i);
			for (int j = 0; j < n_vertices; j++){
				if(matriz[i][j] > 0){
					printf(" %d(%d)", j,matriz[i][j]);	
				}		
			}
			printf("\n");
		}
	}


}

void aresta_menor_l(t_grafo_l* g,int n_vertices){

	int **matriz = malloc(sizeof(int*)*g->n_vertices);
	t_aresta *aux;
	int menor,ind,ind2;

		for (int i = 0; i < n_vertices; ++i){
			matriz[i] = calloc(g->n_vertices,sizeof(int));
		}

		for (int i = 0; i < n_vertices; ++i){
			aux = g->lista[i].aresta;

			while(aux != NULL){
				menor = aux->peso;
				ind = i;
				ind2 = aux->id;
				matriz[i][aux->id] = aux->peso;
				aux = aux->next;
			}
		}

		for (int i = 0; i < n_vertices; ++i){
			for (int j = 0; j < n_vertices; j++){
				if(matriz[i][j] != 0 && matriz[i][j] < menor){
					ind = i;
					ind2 = j;
					menor = matriz[i][j];	
				}
			}	
		}
		
		printf("%d %d\n",ind,ind2);
}
*/