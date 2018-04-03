#include <string.h>
#include "grafos.h"

#define matriz true 

void menu(char *op,grafo *g){ // seleciona a operação e chama a função respectiva

	
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
	}else if(strcmp(op,"BU") == 0){
		busca(g);
	}


}
void le_aresta(aresta *aux){ // função auxiliar que realiza a leitura de uma aresta

	//scanf("%d %d %d",&(aux->v1),&(aux->v2),&(aux->peso)); // leitura geral
	scanf("%d %d",&(aux->v1),&(aux->v2));	// leitura ex 2, sem peso	
	(aux->peso) = 1;
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
void busca(grafo *g){ 
	aresta aux;
	le_aresta(&aux);
	printf("PAR %d %d\n", aux.v1,aux.v2);
	tipo_grafo(g) == matriz ? busca_profundidade_m(g->mat) : busca_profundidade_l(g->lis,aux.v1,aux.v2); 

}

void infos(grafo *g){ // informações do grafo atual

	// se o tipo do grafo for matriz imprima infos matriz se não imprima infos lista
	
	tipo_grafo(g) == matriz ? infos_m(g->mat) : infos_l(g->lis); 
	imprime_grafo(g,false);

}


void imprime_grafo(grafo *g, int trans){ // imprime o grafo transposto se trans == true

	// se o tipo do grafo for matriz imprima matriz se não imprima lista
	tipo_grafo(g) == matriz ? imprime_matriz(g->mat,trans):imprime_lista(g->lis,trans);

}

void add_aresta(grafo *g){  // adiciona uma aresta ao grafo
	aresta aux;
	le_aresta(&aux); // leitura da aresta que vai ser adicionada
	tipo_grafo(g) == matriz  ? add_aresta_m(g->mat,aux.v1,aux.v2,aux.peso) : add_aresta_l(g->lis,aux.v1,aux.v2,aux.peso);
	
}

void rm_aresta(grafo *g){ // remove uma aresta 

	aresta aux;
	scanf("%d %d",&aux.v1,&aux.v2); // leitura da aresta que vai ser removida
//	printf("%d %d\n",aux.v1 ,aux.v2);
	tipo_grafo(g) == matriz ? rm_aresta_m(g->mat,aux.v1,aux.v2) : rm_aresta_l(g->lis,aux.v1,aux.v2);
}

int tipo_grafo(grafo *g){ // retorna true caso o tipo do grafo seja matriz

	if(g->mat != NULL){
		return true;
	}else{
		return false;
	}

}
void adjacentes(grafo *g){ // acha os vertices adjacentes do vertice "Id"

	int id;
	scanf("%d",&id); // lendo "Id"
	tipo_grafo(g) == matriz ? adjacentes_m(g->mat,id):adjacentes_l(g->lis,id);  
}

void menor_aresta(grafo *g){ // acha a menor aresta
	tipo_grafo(g) == matriz ? menor_aresta_m(g->mat):menor_aresta_l(g->lis);  
}
