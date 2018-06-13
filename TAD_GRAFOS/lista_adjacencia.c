#include "lista_adjacencia.h"


#define inf 0x3f3f3f3f

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
	int cor[lis->n_vertices];
	int prede[lis->n_vertices];
	int dis[lis->n_vertices];

	for (int i = 0; i < lis->n_vertices; ++i){
		cor[i] = 0; // não visitado
		prede[i] = -1; 
		dis[i] = -1;
	}

	cor[ori] = 1; // cinza
	prede[ori] = 0;
	int pilha[100];
	int ind = -1;

	for (int i = 0; i < lis->n_vertices; ++i){

		if(cor[i] != -1){
			//printf("i %d\n",i);
			busca_p_l(lis,prede,i,i,cor,dis,0,pilha,&ind);
		}
		
	}

	
	for (int i = ind; i >= 0; --i){
		printf("%d ", pilha[i]);
	}
	printf("\n");
	
	
	/*if(prede[dest] != -1){
		busca_l_l(prede,ori,dest);
		printf("\n");
	}else{
		printf("\n");
	}*/

}

void busca_p_l(t_grafo_l *lis,int *prede,int ori,int dest, int *cor,int *dis,int time, int *pilha, int *ind){
	

	t_aresta *aux;
	aux = lis->no[ori];
	cor[ori] = 1;
	dis[ori] = time;
	
	time++;
	

	/*if(ori == dest){
		return;
	}*/

	while(aux != NULL){
		if(cor[aux->v2] == 0){
			prede[aux->v2] = ori;
			busca_p_l(lis,prede,aux->v2,dest,cor ,dis,time,pilha,ind);
		}
		aux = aux->prox;
	}
	cor[ori] = -1;
	pilha[++(*ind)] = ori;

}

void ordenacao_topologica_l(t_grafo_l *lis){
	busca_profundidade_l(lis,0,0);
}

typedef struct lista_prioridade_t{

	int destino;
	int peso;
		
}lista_prioridade_t;

int comp (const void *v1, const void *v2){
	const lista_prioridade_t *elem1 = (lista_prioridade_t *)v1;
    const lista_prioridade_t *elem2 = (lista_prioridade_t *)v2;

	if (elem1->peso > elem2->peso) return  1;
	if (elem1->peso < elem2->peso) return -1;

	return 0;
}


void insert(lista_prioridade_t *lp,int destino,int peso, int * count){
	lp[*count].destino = destino;
	lp[*count].peso = peso;
	//qsort(lp, sizeof(lp)/sizeof(*lp), sizeof(lista_prioridade_t), comp);
	(*count)++;
}
void pop(lista_prioridade_t *lp,int * count){
	lp[0].destino = inf;
	lp[0].peso = inf;
	(*count)--;
	int i = 1;
	while(lp[i].destino != inf){
		lp[i-1].destino = lp[i].destino;
		lp[i-1].peso = lp[i].peso;
		i++;
	}
	lp[i-1].destino = inf;
	lp[i-1].peso = inf;
		
}


void print_geral(t_grafo_l *lis,int *vet_dist, int *vet_prede){


	printf("Vet Distancia\n");
	for (int i = 0; i < lis->n_vertices; ++i){
		printf("%d ",i);
	}
	printf("\n");
	for (int i = 0; i < lis->n_vertices; ++i){
		printf("%d ",vet_dist[i]);
	}

	printf("\n");
	printf("Vet prede\n");
	for (int i = 0; i < lis->n_vertices; ++i){
		printf("%d ",i);
	}
	printf("\n");
	for (int i = 0; i < lis->n_vertices; ++i){
		printf("%d ",vet_prede[i]);
	}
	printf("\n");


}

void dijkstra_l(t_grafo_l *lis){
	int origem,destino;
	//char c = '\n';
	while(!feof(stdin)){
		scanf("%d %d\n", &origem,&destino);	
		dijkstra_func(lis,origem,destino);		
		printf("\n");
		if(feof(stdin)){
			break;
		}
		
		
		
	}

}

void print_caminho(int* prede,int ini){
	if(prede[ini] == -1){
		printf("%d ", ini);
		return;
	}else{
		print_caminho(prede,prede[ini]);
		printf("%d ", ini);
	}

}

void dijkstra_func(t_grafo_l *lis,int origem,int destino){
		

	int vet_dist[lis->n_vertices];
	int vet_prede[lis->n_vertices];
	
	for (int i = 0; i < lis->n_vertices; ++i){
		vet_dist[i] = inf;
		vet_prede[i] = -1;
	}

	vet_dist[origem] = 0;
	vet_prede[origem] = -1;
	
	fila_t* fp = CriarFila();
	InserirFila(fp,origem,0);

	vet_dist[origem] = 0;
	vet_prede[origem] = -1;

	while(fp->inicio != NULL){
		no_t no = Front(fp);
		int u = no.ID;
		//printf("%d\n", u);
		t_aresta *aux = lis->no[u];
		RemoverFila(fp);
		//qsort(lp, sizeof(lp)/sizeof(*lp), sizeof(lista_prioridade_t), comp);


		while(aux != NULL){
			int v = aux->v2;
			int w = aux->peso;
			
			if(vet_dist[v] > vet_dist[u] + w) { // relaxa a aresta
                vet_dist[v] = vet_dist[u] + w; // atualiza a distancia
                vet_prede[v] = u; // atualiza o predecessor
                //printf("Incluindo vertice %d na p %d\n", v,count);
                InserirFila(fp,v,vet_dist[v]);
              	//insert(lp,v,vet_dist[v],&count);
              	
              	
            } 
            aux = aux->prox;
		}
		
		
	}
		

	if(vet_prede[destino] != -1){
		//printf("resp\n");
		print_caminho(vet_prede,destino);
		//printf("aqui");
		
		return;
	}
	
}

// ALOCA MEMORIA E SETA OS PONTEIROS PARA NULL
fila_t* CriarFila()
{
	fila_t* f = (fila_t*) malloc(sizeof(fila_t));
	f->inicio = NULL;
	f->fim = NULL;

	return f;
}

void InserirFila(fila_t* f, int ID, int peso)
{
	// CRIA O NOVO NO
	no_t* p = (no_t*) malloc(sizeof(no_t));
	p->ID = ID;
	p->peso = peso;
	p->prox = NULL;
	no_t* atual,*prox;
	
	
	if(f->inicio == NULL) // PRIMEIRO ELEMENTO NA FILA
	{
		f->inicio = p;
		f->fim = p;
	}else if(p->peso < f->inicio->peso){ // A fila ja possui elemento mas o elemento novo entra no começo da fila
		p->prox= f->inicio;
		f->inicio = p;
		return ;

	}else{ // JA TEM UM ELEMENTO NA FILA, e o peso do novo elemento é maior que o do inicio
		atual = f->inicio;
		prox = atual->prox;

		// percorrendo a fila enquanto nao chego no final
		while(prox != NULL){
			if(prox->peso > peso){ // se o peso do prox for maior que o do novo no
				// tenho que inserir p entre atual e prox
				atual->prox = p;
				p->prox = prox;
				return ;
			}else if(prox->peso == peso){ // se os pesos forem iguais, verifico pelo ID
				if(prox->ID > ID){ // se o ID do prox for maior que o do novo no
					// tenho que inserir p entre atual e prox
					atual->prox = p;
					p->prox = prox;
					return ;
				}else{ // senao, insiro o novo no na frente do prox
					atual = atual->prox;
					prox = prox->prox;
					atual->prox = p;
					p->prox = prox;
					return ;
				}
			}else{// se o peso do novo no for maior que o prox, ando na fila
				prox = prox->prox;
				atual = atual->prox;
			}

		}

		if(prox == NULL){ // se chegou aqui é porque o novo no entrará no fim da fila
			atual->prox = p;
			p->prox = NULL;
			f->fim = p;
			return ;

		}
	}
}

no_t Front(fila_t* f){
	return *f->inicio;
}

// REMOVENDO O PRIMEIRO ELEMENTO DA FILA
void RemoverFila(fila_t* f)
{
	no_t* aux = f->inicio;
	f->inicio = aux->prox;
	free(aux);

}
// DESALOCANDO TODA A MEMÓRIA DA FILA
void DestruirFila(fila_t* f)
{
	no_t* p;
	while(f->inicio != NULL)
	{
		p = f->inicio;
		f->inicio = f->inicio->prox;
		free(p);
	}
	free(f);
}
void atualizar(fila_t* f, int ID, int peso)
{

	no_t* atual, *prox, *found;

	found = NULL;
	atual = f->inicio;
	prox = atual->prox;
	// se o ID do inicio for igual ao que estou procurando
	// apenas atualizo o peso, já que ele vai continuar sendo o menor da fila
	if(atual->ID == ID){
		atual->peso = peso;
		return ;
	}

	while(prox != NULL){
		if(prox->ID == ID){ // ACHEI O VÉRTICE
		
			//Guardo o vértice em found
			found = prox;
			found->peso = peso; //atualizo o peso
			// tiro o found da fila
			atual->prox = found->prox; // o proximo do anterior recebe o proximo do encontrado
			// reinicio os ponteiros pro começo da fila
			atual = f->inicio;
			prox = atual->prox;
			// se o peso do primeiro vertice ja for maior que o peso novo
			if(peso < atual->peso){
				//coloco o vértice no inicio
				f->inicio = found;
				found->prox = atual;
				return ;
			}else if(peso == atual->peso){
				//COMPARO POR ID
				// se o ID do inicio da fila ja for maior que o novo
				//então o novo no é adicionado no fim da fila
				if(atual->ID > ID){
					f->inicio = found;
					found->prox = atual;
					return ;
				}

				// senão, anda na fila enquanto o peso do prox for igual ao novo
				while(prox != NULL && peso == prox->peso){
					if(ID < prox->ID){ // se o ID de prox for maior que o novo, insiro o found antes de prox
						atual->prox = found;
						found->prox = prox;
						return;
					}
					atual= atual->prox;
					prox = prox->prox;
				}
				if(prox != NULL){ // se eu sai do while e o prox é diferente de NULL
					// então é pq o peso de prox é maior que o peso de found
					// entao insiro found antes de prox
					atual->prox = found;
					found->prox = prox;
				}else{ // se prox  == NULL, insiro found como o ultimo elemento da fila
					atual->prox = found;
					found->prox = NULL;
					f->fim= found;
				}
			}
			// senao, então enquanto não chegar no fim da fila
			// e o peso novo for maior que o peso dos nos da fila
			while(prox != NULL && (prox->peso < found->peso)){
				// ando na fila
				atual = atual->prox;
				prox = prox->prox;
			}
			// se eu sai do while e o prox é diferente de NULL
			// então o peso do no PROX é > ou = ao novo peso
			if(prox != NULL){ //ACHEI O LUGAR
			
				// se for menor, então insiro o found antes de prox
				if(found->peso < prox->peso){
					atual->prox = found;
					found->prox = prox;
					return ;
				}else{ // SE NAO É MENOR ENTÃO É IGUAL
					if(found->ID < prox->ID){ // comparo por ID
		
						atual->prox = found;
						found->prox = prox;
						return ;
					}else{// ando mais um nó pra frente
						if(prox == f->fim){
							f->fim = found;
						}
						atual = atual->prox;
						prox= prox->prox;
						// e atualizo os ponteiros
						atual->prox = found;
						found->prox = prox;
						return ;

					}
				}
			}else{// se sai do while porque o prox é igual de NULL, então atual = f->fim
				atual->prox = found;
				f->fim = found;
				found->prox = NULL;
				return ;
			}
		}else{ // CONTINUO ANDANDO NA FILA
			atual = atual->prox;
			prox = prox->prox;
		}
	}

	if(atual->ID == ID){ // O VERTICE É O ULTIMO ELEMENTO DA FILA
	
		//Guardo o vértice em found
			found = prox;
			found->peso = peso; //atualizo o peso
			// tiro o found da fila
			atual->prox = found->prox; // o proximo do anterior recebe o proximo do encontrado
			found->prox = NULL;
			// reinicio os ponteiros pro começo da fila
			atual = f->inicio;
			prox = atual->prox;
			// se o peso do primeiro vertice ja for maior que o peso novo
			if(peso < atual->peso){
				//coloco o vértice no inicio
				f->inicio = found;
				found->prox = atual;
				return ;
			}
			// senao, então enquanto não chegar no fim da fila
			// e o peso novo for maior que o peso dos nos da fila
			while(prox != NULL && (prox->peso < found->peso)){
				// ando na fila
				atual = atual->prox;
				prox = prox->prox;
			}
			// se eu sai do while e o prox é diferente de NULL
			// então o peso do no PROX é > ou = ao novo peso
			if(prox != NULL){ //ACHEI O LUGAR
		
				// se for menor, então insiro o found antes de prox
				if(found->peso < prox->peso){
					atual->prox = found;
					found->prox = prox;
					return ;
				}else{ // SE NAO É MENOR ENTÃO É IGUAL
					if(found->ID < prox->ID){ // comparo por ID
					
						atual->prox = found;
						found->prox = prox;
						return ;
					}else{// ando mais um nó pra frente
						if(prox == f->fim){
							f->fim = found;
						}
						atual = atual->prox;
						prox= prox->prox;
						// e atualizo os ponteiros
						atual->prox = found;
						found->prox = prox;
						return ;

					}
				}
			}else{// se sai do while porque o prox é igual de NULL, então atual = f->fim
				atual->prox = found;
				f->fim = found;
				found->prox = NULL;
				return ;
			}
	}
}
int Custo(fila_t* f, int ID)
{
	no_t* atual;

	atual = f->inicio;

	while(atual != NULL)
	{
		if(atual->ID == ID)
			return atual->peso;
		atual = atual->prox;
	}
	return 0;

}

void ImprimirFila(fila_t* f){
	no_t* aux;
	aux = f->inicio;
	printf("FILA:");
	while(aux != NULL)
	{
		printf("ID = %d, Peso = %d;", aux->ID, aux->peso);
		aux = aux->prox;
	}
	printf("\n");


}