#include "matriz.h"

t_grafo_m * cria_grafo_m(int n_vertices,int n_arestas,char dir){

	t_grafo_m *mat = (t_grafo_m*)malloc(sizeof(t_grafo_m)); // alocando a estrutura grafo_m
	mat->no = (int**) malloc(sizeof(int*)*n_vertices);		// alocando a matriz

	mat->n_vertices = n_vertices;
	mat->n_arestas = n_arestas;

	if(dir == 'D'){
		mat->dir = true;	
	}else{
		mat->dir = false;
	}


	for (int i = 0; i < n_vertices; ++i){
		mat->no[i] = (int*) malloc(sizeof(int)*n_vertices);
	}

	for (int i = 0; i < n_vertices; ++i){
		for (int j = 0; j < n_vertices; j++){
			mat->no[i][j] = -1;
		}
	}


	return mat;
}
void imprime_matriz(t_grafo_m *mat){

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

}
void infos_m(t_grafo_m *mat){

	printf("!---------------------!\n");
	printf("Grafo\n");
	printf("Nº vértices: %d\n",mat->n_vertices);
	printf("Nº arestas: %d\n",mat->n_arestas);
	printf("Direcionado: %d\n", mat->dir);
	printf("!---------------------!\n");

}

/*


t_grafo_m * cria_grafo_m(int n_vertices,char dir){

	t_grafo_m *g = (t_grafo_m*)malloc(sizeof(t_grafo_m));

	g->n_vertices = n_vertices;
	g->dir = dir;

	g->mat = (t_no**) malloc(sizeof(t_no*)*n_vertices);

	for (int i = 0; i < n_vertices; ++i){
		g->mat[i] = (t_no*) malloc(sizeof(t_no)*n_vertices);
	}
	for (int i = 0; i < n_vertices; ++i){
		for (int j = 0; j < n_vertices; j++){
			g->mat[i][j].peso = INT_MAX;
		}
	}

	

	return g;

}

void exibe_matriz(t_grafo_m* g,int n_vertices,int transposta){

	if(transposta == 0){
		for (int i = 0; i < n_vertices; ++i){
			for (int j = 0; j < n_vertices; j++){
				if(g->mat[j][i].peso == INT_MAX){
					printf(". ");
				}else{
					printf("%d ", g->mat[j][i].peso);	
				}
			}
			printf("\n");
		}
	}else{
		for (int i = 0; i < n_vertices; ++i){
			for (int j = 0; j < n_vertices; j++){
				if(g->mat[j][i].peso == INT_MAX){
					printf(". ");
				}else{
					printf("%d ", g->mat[j][i].peso);	
				}
			}
			printf("\n");
		}
	}
	

}

void v_adjacentes(t_grafo_m* g,int id_vertice, int n_vertices){


	for (int i = 0; i < n_vertices; ++i){
		if(g->mat[id_vertice][i].peso == 1){
			printf("%d ", i);
		}
	}
	printf("\n");

}

void le_coordenada(t_coordenada *aux){
	scanf("%d %d %d",&(aux->v1),&(aux->v2),&(aux->peso));
}

void remove_aresta(t_grafo_m* g,t_coordenada *aux){

	g->mat[aux->v1][aux->v2].peso = INT_MAX;

	if(g->dir == 'G'){		
		g->mat[aux->v2][aux->v1].peso = INT_MAX;	
	}
		
}

void adiciona_aresta(t_grafo_m* g,t_coordenada *aux){
	if(g->dir == 'G'){
		g->mat[aux->v1][aux->v2].peso = aux->peso;	
		g->mat[aux->v2][aux->v1].peso = aux->peso;	
	}else{
		g->mat[aux->v1][aux->v2].peso = aux->peso;	
	}
	
}
void aresta_menor(t_grafo_m* g,int n_vertices){

	int menor=0,ind=0,ind2=0;

	for (int i = 0; i < n_vertices; ++i){
			for (int j = 0; j < n_vertices; j++){
				if(g->mat[i][j].peso != INT_MAX && g->mat[i][j].peso < menor){
					ind = i;
					ind2 = j;
					menor = g->mat[i][j].peso;	
				}
			}	
	}

	printf("%d %d\n",ind,ind2 );

}
*/