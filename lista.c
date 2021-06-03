struct lista{
	int info;
	struct lista* prox;
};

//criar lista
PLista criarLista(){
	return NULL;
}

//lista vazia

int lst_vazia(PLista L){
	
	return(L == NULL);

}

//imprime lista
void imprimeLista(PLista L){
    PLista p;
    
    printf("\n");
    for(p = L; p != NULL; p = p->prox){
    	printf("Valores = %d\n ", p->info);
	}
}

//insere valores na lista

PLista insereLista(PLista L, int valor){
	PLista novo = (PLista)malloc(sizeof(Lista));
	novo->info = valor;
	novo->prox = L;
	
	return novo;
}

PLista buscaLista(PLista L, int valor){
	PLista p;
	
	for(p = L; p != NULL; p = p -> prox){
		if(p->info == valor)
			return p;	
	}		
	
		return NULL;
}

Lista* retiraLista(Lista* L, int valor){
	Lista* anterior = NULL;
	Lista* HeadList = L;
	
	
	
	
	while(HeadList->info != valor && HeadList != NULL){
		anterior = HeadList;
		HeadList = HeadList->prox;
	}
	
	if(HeadList == NULL){
		return L;
	}
	
	if(anterior == NULL){  //não saiu da cabeça da lista
		L = HeadList->prox;
	}else{
		anterior->prox = HeadList->prox;
	}
	
	free(HeadList);
	
	return L;
	
}

void liberaLista(PLista L){
	PLista p = L;
	
	while(p != NULL){
		PLista t = p->prox;
		free(p);
		p = t;
	}
}

PLista insereOrdenado(PLista L, int valor){
	PLista novo = (PLista)malloc(sizeof(Lista));
	
	novo->info= valor;
	
	PLista anterior = NULL;
	PLista HeadList = L;
	
	while(HeadList != NULL && HeadList->info < valor){
		anterior = HeadList;
		HeadList = HeadList->prox;
	}
	
	if(anterior == NULL){
		novo->prox = L;
		L = novo;
	}else{
		novo->prox =  anterior->prox;
	}
	
	return L;
	
	
}

int ComparaLista(PLista L1, PLista L2){
	PLista Head1;
	PLista Head2;
	
	for(Head1 = L1,Head2 = L2; Head1 != NULL && Head2 != NULL; Head1 = Head1->prox, Head2 = Head2->prox){
		if(Head1->info != Head2 -> info){
			return 0;
		}
	}
		 return Head1 == Head2;
}

PLista LiberaRec(PLista L){
	//liberando a lista recursivamente
	if(!lst_vazia(L)){
		LiberaRec(L->prox);
		free(L);
	}
	
	
}

PLista RetiraRec(PLista L, int valor){
	if(!lst_vazia(L)){
		if(L->info == valor){
			PLista Head = L;
			L = L->prox;
			free(Head);
		}else{
			//passando a "cabeça da lista" para o proximo elemento
			L->prox = RetiraRec(L->prox, valor);
		}
	}
	
	return L;
}

int ComparaRec(PLista L, PLista L2){
	if(L == NULL && L2 == NULL){
		return 1; //lista são iguais
	}else if(L == NULL || L2 == NULL){
		return 0; //lista são diferentes
	}else{
		//se a cabeça da lista e a sublista forem iguais 
		//se L e L2 não forem nulos
		return (L-> info == L2->info) && ComparaRec(L->prox, L2->prox);
	}
}
