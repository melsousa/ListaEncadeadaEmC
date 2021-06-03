// tad lista

#include <stdlib.h>

typedef struct lista Lista;
typedef Lista* PLista;

PLista criarLista();

int lst_vazia(PLista L);

void imprimeLista(PLista L);

PLista insereLista(PLista L, int valor);

PLista buscaLista(PLista L, int valor);

Lista* retiraLista(Lista* L, int valor);

void liberaLista(PLista L);

PLista insereOrdenado(PLista L, int valor);

int ComparaLista(PLista L1, PLista L2);



#ifndef lista_c
	#define lista_c
	#include "lista.c"
#endif






