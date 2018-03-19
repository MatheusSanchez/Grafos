#include <stdlib.h>
#include <stdio.h>
#include "lista_adjacencia.h"

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