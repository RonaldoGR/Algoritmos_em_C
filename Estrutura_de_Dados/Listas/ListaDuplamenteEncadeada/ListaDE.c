#include <stdio.h>
#include <stdlib.h>
#include "ListaDE_H.h"


void criaLista (ListaDE *lista) {
	lista->inicio = NULL;
	lista->fim = NULL;
	lista->n = 0;
}

int estaVazia (ListaDE *lista) {
	if(lista->n == 0) {
		return LISTA_VAZIA;
	}
	return SUCESSO;
}

int quantidadeDeNodos (ListaDE lista) {	
		return lista.n;
}

void exibeLista(ListaDE lista) {
		if(estaVazia(&lista)) {
			printf("A lista está vazia\n");
			return;
		}
	
	Nodo *inicioLista = lista.inicio;
	
	
	printf("+----------- DADOS DA LISTA --------------+\n");
	printf("Inicio: %d\n", lista.inicio);
	printf("Fim: %d\n", lista.fim);
	printf("\n");
	while (inicioLista != NULL) {

			printf("+------------------------+\n");
			printf("| Endereço Atual: %2d|\n", inicioLista);
			printf("| Codigo: %15d|\n", inicioLista->info.cod);
			printf("| Peso: %17.2f|\n", inicioLista->info.peso);
			printf("| Nodo anterior: %8d|\n", inicioLista->ant);
			printf("| Próximo nodo: %9d|\n", inicioLista->prox);
			printf("+------------------------+\n");
			printf("\n");
		    
	    inicioLista = inicioLista->prox;
	} 
	printf("+----------------------------------------+\n");
	printf("\n");

}



int incluiNoInicio (ListaDE *lista, Dado dado) {
	Nodo *novoNodo = (Nodo *) malloc(sizeof(Nodo));
	
	if(novoNodo == NULL) {
		return FALTOU_MEMORIA;
	}
	
	novoNodo->info = dado;
	novoNodo->ant = NULL;
	novoNodo->prox = lista->inicio;
	
	if(lista->n == 0) {
		lista->fim = novoNodo;
	} else {
		lista->inicio->ant = novoNodo;
	}
	
	lista->inicio = novoNodo;
	lista->n++;
	return SUCESSO;
}

int excluiDoInicio (ListaDE *lista, Dado *dado){
	
	if (lista->n == 0) {
		return LISTA_VAZIA;
	}
	
	*dado = lista->inicio->info;
	Nodo *aux = lista->inicio;
	lista->inicio = lista->inicio->prox;
	
	if(lista->n == 1) {
		lista->fim = NULL;
	} else {
   	 	lista->inicio->ant = NULL;
	}
	
	lista->n--;
	free(aux);
	return SUCESSO;
}


int incluiNoFim(ListaDE *lista, Dado dado) {
	Nodo *novoNodo = (Nodo *) malloc (sizeof(Nodo));
	if (novoNodo == NULL){
		return FALTOU_MEMORIA;
	}
	
	novoNodo->info = dado;
	novoNodo->ant = lista->fim;
	novoNodo->prox = NULL;
	
	if (lista->n == 0) {	
		lista->inicio = novoNodo;
		lista->fim = novoNodo;
	}else {
		lista->fim->prox = novoNodo;
		lista->fim = novoNodo;
	}
	
	lista->n++;
	return SUCESSO;
}


int excluiDoFim(ListaDE *lista, Dado *dado) {
	if(estaVazia(lista) == LISTA_VAZIA) {
		return LISTA_VAZIA;
	}
	
	*dado = lista->fim->info;
	Nodo *nodoFim = lista->fim;
	
	if(lista->n == 1){
		lista->inicio = lista->inicio->prox; 
		lista->fim = lista->fim->prox;
	} else {
		lista->fim = lista->fim->ant;
		lista->fim->prox = NULL;
	}
	
	lista->n--;
	free(nodoFim);
	return SUCESSO;
}

int excluiNodo(ListaDE *lista, int codigo, Dado *dado) {
	if(estaVazia(lista) == LISTA_VAZIA) {
		return LISTA_VAZIA;
	}

	if (lista->inicio->info.cod == codigo) {
		excluiDoInicio(lista, dado);
		return SUCESSO;
	}
	
	if(lista->fim->info.cod == codigo) {
		excluiDoFim(lista, dado);
		return SUCESSO;
	}
	
	Nodo *nodoAtual = lista->inicio;
	Nodo *nodoAnterior = lista->inicio->ant;
	
	while(nodoAtual != NULL){
		
		if (nodoAtual->info.cod == codigo) {
			*dado = nodoAtual->info;
			nodoAnterior->prox = nodoAtual->prox;
			lista->n--;
			free(nodoAtual);
			return SUCESSO;
		}
		
		nodoAnterior = nodoAtual;
		nodoAtual = nodoAtual->prox;
	}
	return CODIGO_INEXISTENTE;
}


int consultaPorCodigo(ListaDE *lista, int codigo, Dado *dado) {
	
	if(lista->inicio->info.cod == codigo) {
		*dado = lista->inicio->info;
		return SUCESSO;
	}
	
	if(lista->fim->info.cod == codigo) {
		*dado = lista->fim->info;
		return SUCESSO;
	}
	
	Nodo *nodoAtual = lista->inicio;
	
	while(nodoAtual != NULL) {
		
		if (nodoAtual->info.cod == codigo) {
			*dado = nodoAtual->info;
			return SUCESSO;
		}
		nodoAtual = nodoAtual->prox;
	}
	return CODIGO_INEXISTENTE;
}



int incluiDepois(ListaDE *lista, int codigo, Dado dado) {
	
	if(estaVazia(lista) == LISTA_VAZIA){
		return CODIGO_INEXISTENTE;
	}
	
	if(lista->inicio->info.cod == codigo) {
		incluiNoFim(lista, dado);
		return SUCESSO;
	}
	
	if(lista->fim->info.cod == codigo) {
		incluiNoFim(lista, dado);
		return SUCESSO;
	}
	
	Nodo *novoNodo = (Nodo *) malloc (sizeof(Nodo));
	if (novoNodo == NULL) {
		return FALTOU_MEMORIA;
	}
	
	novoNodo->info = dado;
	
	Nodo *nodoAtual = lista->inicio;
	Nodo *nodoAnterior = lista->inicio->ant;
	
	while(nodoAtual != NULL){
		
		if (nodoAtual->info.cod == codigo) {
			novoNodo->ant = nodoAtual;
			novoNodo->prox = nodoAtual->prox;
			nodoAtual->prox = novoNodo;
			lista->n++;
			return SUCESSO;
		}
		nodoAnterior = nodoAtual;
		nodoAtual = nodoAtual->prox;
	}
	
	return CODIGO_INEXISTENTE;
}


