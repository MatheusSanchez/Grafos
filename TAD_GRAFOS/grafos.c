#include "grafos.h"


void le_aresta(){

	aresta aux;
	scanf("%d %d %d",&aux.v1,&aux.v2,&aux.peso);
	

	printf("Aresta\n");
	printf("V1 %d V2 %d Peso %d\n",aux.v1,aux.v2,aux.peso);
}


grafo* cria_grafo(int n_vertices, int n_arestas, char dir, char t_grafo){ // função para criar os grafos de ambos os tipos

	grafo *g = malloc(sizeof(grafo));

	if(t_grafo == 'M'){ // grafo do tipo matriz
		g->mat = cria_grafo_m(n_vertices,n_arestas,dir);
	}else{
		printf("Grafo tipo Lista\n"); // grafo do tipo lista

	}
	return g;
}

void infos(grafo *g){
	// se o tipo do grafo for matriz imprima infos matriz se não imprima infos lista
	tipo_grafo(g) ? infos_m(g->mat) : printf("INFOS LISTA\n"); 

}

int tipo_grafo(grafo *g){ // retorna true caso o tipo do grafo seja matriz
	if(g->mat != NULL){
		return true;
	}else{
		return false;
	}
}

void imprime_grafo(grafo *g){
	// se o tipo do grafo for matriz imprima matriz se não imprima lista
	tipo_grafo(g) ? imprime_matriz(g->mat):printf("IMPRIME LISTA\n");  

}