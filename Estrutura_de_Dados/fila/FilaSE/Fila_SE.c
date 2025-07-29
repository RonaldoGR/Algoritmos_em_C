#include <stdio.h>
#include <stdlib.h>
#include "Fila_SE.h"



void criaFila (FilaSE *fila) {
	fila->frente = NULL;
	fila->re = NULL;
}


int estaVazia(FilaSE *fila) {
	if(fila->frente == NULL) {
		return FILA_VAZIA;
	}
	return SUCESSO;
}



int insere(FilaSE *fila, Dado dado) {
	
	
	Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));
	
	if(nodo == NULL) {
		return FALTOU_MEMORIA;
	}
	
	
	nodo->info = dado;
	nodo->prox = NULL;
	
	if(estaVazia(fila)) {
		fila->frente = nodo;
		fila->re = nodo;
		return SUCESSO;
	} 
	
	fila->re->prox = nodo;
	fila->re = nodo;


	return SUCESSO;		
}
	





int retira(FilaSE *fila, Dado *dado) {

	
	if(estaVazia(fila)) {
		return FILA_VAZIA;
	}
	
	Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));
	if(nodo == NULL) {
		return FALTOU_MEMORIA;
	}
	
	
	dado->cod = fila->frente->info.cod;
	dado->peso = fila->frente->info.peso;
	
	nodo = fila->frente;
	fila->frente = fila->frente->prox;
	
	free(nodo);	
	return SUCESSO;

}




int consultaFrente(FilaSE *fila, Dado *dado) {
	if(estaVazia(fila)) {
		return FILA_VAZIA;
	}
	 dado->cod = fila->frente->info.cod;
	 dado->peso = fila->frente->info.peso;
	 
	 return SUCESSO;
	
}


void exibe(FilaSE fila) {
	if(estaVazia(&fila)) {
		printf("A fila está vazia\n");
		return;
	} 
		
	Nodo *nodoFrente = fila.frente;
	printf("+----------- DADOS DA FILA --------------+\n");
	printf("Inicio: %d\n", fila.frente);
	printf("Fim...: %d\n", fila.re);
	printf("\n");
	while(nodoFrente != NULL) {
		if(nodoFrente->prox == NULL) {
				printf("+-----------------------+\n");
				printf("| Endereço: %d\t|\n", nodoFrente);
				printf("| Codigo: %d\t\t|\n", nodoFrente->info.cod);
				printf("| Peso: %.2f\t\t|\n", nodoFrente->info.peso);
				printf("| Próximo nodo: %d\t|\n", nodoFrente->prox);
				printf("+-----------------------+\n");
				printf("\n");
		} else {
				printf("+-----------------------+\n");
				printf("| Endereço: %d\t|\n", nodoFrente);
				printf("| Codigo: %d\t\t|\n", nodoFrente->info.cod);
				printf("| Peso: %.2f\t\t|\n", nodoFrente->info.peso);
				printf("| Próximo nodo: %d|\n", nodoFrente->prox);
				printf("+-----------------------+\n");
				printf("\n");
		}
		
		nodoFrente = nodoFrente->prox;
	}	
	printf("+----------------------------------------+\n");
	printf("\n");
}
