#include <stdio.h>
#include "lista.h"


int main(){
	int quant, valor, i;
	
	PLista L, Lbuscar, L2;
	
	L = criarLista();
	L2 = criarLista();
	
	printf("Digite a quantidade : ");
	scanf("%i", &quant);
	
	for(i = 0; i < quant; i++){
		
		printf("Digite um valor : ");
		scanf("%i", &valor);
		
		L = insereLista(L, valor);
			
	}
	
	
		valor = 0;
			
			imprimeLista(L);
		
			printf("Busque um valor : ");
	 		scanf("%i", &valor);
	 
	 		Lbuscar = L;
	 		Lbuscar = buscaLista(Lbuscar, valor);
	  
	 			
	 
			if(Lbuscar != NULL){
				printf("Valor buscado é: %i \n", Lbuscar->info);
			}else{
			 	printf("\nValor não foi encontrado ");
			}
			
			valor = 0 ;
			
			printf("\n Digite um valor para retirar: ");
			scanf("%i", &valor);
	
			L = retiraLista(L, valor);
				
			if(L != NULL){
				imprimeLista(L); //imprimir depois q retirar
			}else{
				printf("Valor não foi encontrado !");
			}
		
			valor = 0;
			quant = 0;
			printf("Digite a quantidade de valores da lista nova ");
			scanf("%i", &quant);
	
			for( i = 0; i < quant; i++){
				printf("digite : ");
				scanf("%i", &valor);
					
				L2 = insereOrdenado(L2, valor);
					
			}
			
			PLista L3;
			L3 = L2;
			imprimeLista(L3);
					 
				 
			if(ComparaLista(L, L2)){
			 	printf("Lista igual ");
				 	
			}else{
				printf("Lista diferente");
			}
			
	
	
	
	liberaLista(L);
	liberaLista(L2);
	liberaLista(L3);
	liberaLista(Lbuscar);
	return 0;
}


