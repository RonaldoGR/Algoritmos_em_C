#include <stdio.h>
#include <stdlib.h>
#include "ListaSE_H.h"


void criaLista(ListaSE *lista) {
	lista->inicio = NULL;	
}

int estaVazia(ListaSE *lista) {
	if (lista->inicio == NULL) {
		return LISTA_VAZIA;
	}
	return SUCESSO;
}



void exibeLista(ListaSE lista) {
	
	if(estaVazia(&lista)) {
		printf("A lista está vazia\n");
		return;
	}
	
	Nodo *inicioLista = lista.inicio;
	
	
	printf("+----------- DADOS DA LISTA --------------+\n");
	printf("Inicio: %d\n", lista.inicio);
	printf("\n");
	while (inicioLista != NULL) {
		
		if(inicioLista->prox == NULL) {
				printf("+-----------------------+\n");
				printf("| Endereço: %d\t|\n", inicioLista);
				printf("| Codigo: %d\t\t|\n", inicioLista->info.cod);
				printf("| Peso: %.2f\t\t|\n", inicioLista->info.peso);
				printf("| Próximo nodo: %d\t|\n", inicioLista->prox);
				printf("+-----------------------+\n");
				printf("\n");
		} else {
				printf("+-----------------------+\n");
				printf("| Endereço: %d\t|\n", inicioLista);
				printf("| Codigo: %d\t\t|\n", inicioLista->info.cod);
				printf("| Peso: %.2f\t\t|\n", inicioLista->info.peso);
				printf("| Próximo nodo: %d|\n", inicioLista->prox);
				printf("+-----------------------+\n");
				printf("\n");
		    }
	
	    inicioLista = inicioLista->prox;
	} 
	printf("+----------------------------------------+\n");
	printf("\n");
}

int incluiNoInicio(ListaSE *lista, Dado dado) {
	
	Nodo *novoNodo = (Nodo *) malloc(sizeof(Nodo));
	if(novoNodo == NULL) {
		return FALTOU_MEMORIA;
	}
	
	novoNodo->info = dado;
	novoNodo->prox = lista->inicio;
	lista->inicio = novoNodo;
	
	return SUCESSO;	
}



int incluiNoFim(ListaSE *lista, Dado dado) {
	Nodo *novoNodo = (Nodo *) malloc(sizeof(Nodo));
	if(novoNodo == NULL) {
		return FALTOU_MEMORIA;
	}
	
	novoNodo->info = dado;
	
	Nodo *nodoInicio = lista->inicio;
	
	while(nodoInicio != NULL) {
		
		if(nodoInicio->prox == NULL) {
			nodoInicio->prox = novoNodo;
			novoNodo->prox = NULL;
			return SUCESSO;
		}
		nodoInicio = nodoInicio->prox;
	}
	
}



int incluiDepois(ListaSE *lista, int codigo, Dado dado) {
	Nodo *novoNodo = (Nodo *) malloc(sizeof(Nodo));
	if(novoNodo == NULL) {
		return FALTOU_MEMORIA;
	}
	
	novoNodo->info = dado;
	
	Nodo *nodoInicio = lista->inicio;
	
	while(nodoInicio != NULL) {
		
		if(nodoInicio->info.cod == codigo) {
			novoNodo->prox = nodoInicio->prox;
			nodoInicio->prox = novoNodo;
			return SUCESSO;
		} 
		nodoInicio = nodoInicio->prox;
	}
	return CODIGO_INEXISTENTE;
}


int excluiDoInicio(ListaSE *lista, Dado *dado) {
	if (estaVazia(lista) == LISTA_VAZIA) {
		return LISTA_VAZIA;
	}
	
	*dado = lista->inicio->info;
	Nodo *nodoInicio = lista->inicio;
	lista->inicio = lista->inicio->prox;
	free(nodoInicio);
	return SUCESSO;
	
	
}


int excluiDoFim(ListaSE *lista, Dado *dado) {
	
	if (estaVazia(lista) == LISTA_VAZIA) {
		return LISTA_VAZIA;
	}
	
	Nodo *nodoInicio = lista->inicio;
	Nodo *nodoTemp = NULL;
	
	if(nodoInicio->prox == nodoTemp) {
		*dado = nodoInicio->info;
		lista->inicio = NULL;
		free(nodoInicio);
		return SUCESSO;
	}
	
	
	while (nodoInicio != NULL) {
		
		if(nodoInicio->prox == NULL) {
			*dado = nodoInicio->info;
			nodoTemp->prox = NULL;
			free(nodoInicio);
			return SUCESSO;		
		}
		nodoTemp = nodoInicio;	
		nodoInicio = nodoInicio->prox;
	}
}



int excluiNodo(ListaSE *lista, int codigo, Dado *dado) {

	if (estaVazia(lista) == LISTA_VAZIA) {
		return LISTA_VAZIA;
	}

	if(lista->inicio->info.cod == codigo) {
		*dado = lista->inicio->info;
		excluiDoInicio(lista, dado);
		return SUCESSO;
	}
	
	Nodo *nodoAtual = lista->inicio;
	Nodo *nodoAnterior = NULL;

	
	while(nodoAtual != NULL) {
		
		if(nodoAtual->info.cod == codigo) {
			*dado = nodoAtual->info;
			nodoAnterior->prox = nodoAtual->prox;
			free(nodoAtual);
			return SUCESSO;		
		}
		nodoAnterior = nodoAtual;
		nodoAtual = nodoAtual->prox;
	}
	return CODIGO_INEXISTENTE;
}



int quantidadeDeNodos (ListaSE lista) {
	int quantidade = 0;
	Nodo *nodoInicio = lista.inicio;

	while (nodoInicio != NULL) {
		quantidade++;
		nodoInicio = nodoInicio->prox;
	}
	
	return quantidade;
}


int consultaPorCodigo(ListaSE *lista, int codigo, Dado *dado) {
	
	Nodo *nodoInicio = lista->inicio;

	while (nodoInicio != NULL) {
		if(nodoInicio->info.cod == codigo) {
			*dado = nodoInicio->info;
			return SUCESSO;
		}
		nodoInicio = nodoInicio->prox;
	}
	return CODIGO_INEXISTENTE;
}