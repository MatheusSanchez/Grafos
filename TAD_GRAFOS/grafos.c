#include "grafos.h"


void le_aresta(aresta *aux){


	scanf("%d %d %d",&(aux->v1),&(aux->v2),&(aux->peso));
	
	printf("Adicionando aresta Aresta\n");
	printf("V1 %d V2 %d Peso %d\n",aux->v1,aux->v2,aux->peso);
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


void imprime_grafo(grafo *g, int trans){ // imprime o grafo transposto se trans == true
	// se o tipo do grafo for matriz imprima matriz se não imprima lista
	tipo_grafo(g) ? imprime_matriz(g->mat,trans):printf("IMPRIME LISTA\n");  

}

void add_aresta(grafo *g){ 
	aresta aux;
	le_aresta(&aux);

	tipo_grafo(g) ? add_aresta_m(g->mat,aux.v1,aux.v2,aux.peso) : printf("Colocando Aresta na lista\n");
		

}

void rm_aresta(grafo *g){ 

	aresta aux;
	scanf("%d %d",&aux.v1,&aux.v2);

	tipo_grafo(g) ? rm_aresta_m(g->mat,aux.v1,aux.v2) : printf("Colocando Aresta na lista\n");
}

int tipo_grafo(grafo *g){ // retorna true caso o tipo do grafo seja matriz
	if(g->mat != NULL){
		return true;
	}else{
		return false;
	}
}
void adjacentes(grafo *g, int id){

	tipo_grafo(g) ? adjacentes_m(g->mat,id):printf("LISTA\n");  
}

void menor_aresta(grafo *g){
	tipo_grafo(g) ? menor_aresta_m(g->mat):printf("LISTA\n");  
}
