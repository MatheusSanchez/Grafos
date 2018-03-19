#include <string.h>
#include "grafos.h"

#define matriz true

void menu(char *op,grafo *g){

	
	if(strcmp(op,"IG") == 0){
		
		imprime_grafo(g,false);
	}else if(strcmp(op,"VA") == 0){
		adjacentes(g);
	}else if(strcmp(op,"AA") == 0){
		add_aresta(g);
	}else if(strcmp(op,"RA") == 0){
		rm_aresta(g);
	}else if(strcmp(op,"IT") == 0){

		imprime_grafo(g,true);
	}else if(strcmp(op,"MP") == 0){

		menor_aresta(g);
	}


}
void le_aresta(aresta *aux){


	scanf("%d %d %d",&(aux->v1),&(aux->v2),&(aux->peso));
	
	/*printf("Adicionando aresta Aresta\n");
	printf("V1 %d V2 %d Peso %d\n",aux->v1,aux->v2,aux->peso);*/
}


grafo* cria_grafo(int n_vertices, int n_arestas, char dir, char t_grafo){ // função para criar os grafos de ambos os tipos

	grafo *g = malloc(sizeof(grafo));

	if(t_grafo == 'M'){ // grafo do tipo matriz
		g->lis = NULL;
		g->mat = cria_grafo_m(n_vertices,n_arestas,dir);
		
	}else{
		g->mat = NULL;

		g->lis = cria_grafo_l(n_vertices,n_arestas,dir);
		
	}
	return g;
}

void infos(grafo *g){
	// se o tipo do grafo for matriz imprima infos matriz se não imprima infos lista
	
	tipo_grafo(g) == matriz ? infos_m(g->mat) : infos_l(g->lis); 

}


void imprime_grafo(grafo *g, int trans){ // imprime o grafo transposto se trans == true

	// se o tipo do grafo for matriz imprima matriz se não imprima lista
	tipo_grafo(g) == matriz ? imprime_matriz(g->mat,trans):imprime_lista(g->lis,trans);

}

void add_aresta(grafo *g){ 
	aresta aux;

	le_aresta(&aux);
	tipo_grafo(g) == matriz  ? add_aresta_m(g->mat,aux.v1,aux.v2,aux.peso) : add_aresta_l(g->lis,aux.v1,aux.v2,aux.peso);
	
}

void rm_aresta(grafo *g){ 

	aresta aux;
	scanf("%d %d",&aux.v1,&aux.v2);

	tipo_grafo(g) == matriz ? rm_aresta_m(g->mat,aux.v1,aux.v2) : printf("Colocando Aresta na lista\n");
}

int tipo_grafo(grafo *g){ // retorna true caso o tipo do grafo seja matriz
	if(g->mat != NULL){
		return true;
	}else{
		return false;
	}
}
void adjacentes(grafo *g){
	int id;
	scanf("%d",&id);
	tipo_grafo(g) == matriz ? adjacentes_m(g->mat,id):printf("LISTA\n");  
}

void menor_aresta(grafo *g){
	tipo_grafo(g) == matriz ? menor_aresta_m(g->mat):printf("LISTA\n");  
}
