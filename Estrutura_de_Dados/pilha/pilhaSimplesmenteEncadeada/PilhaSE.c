#include <stdio.h>
#include <stdlib.h>
#include "PilhaSE.h"


void criaPilha (Pilha *p) {
		p->topo = NULL; 
}

int empilha (Pilha *p, Dado d) {
	Nodo *nodo;
	nodo = (Nodo *) malloc(sizeof (Nodo));
	if(nodo == NULL) {
		return FALTOU_MEMORIA;
	}
	
	nodo->info.cod = d.cod;
	nodo->info.peso = d.peso;
	nodo->prox = p->topo;
	p->topo = nodo;
	return SUCESSO;
		
}


int desempilha (Pilha *p, Dado *d) {
	Nodo *nodo;
	if(nodo == NULL){
		return FALTOU_MEMORIA;
	}
	
	
	if (estaVazia(p) == PILHA_VAZIA) {
		return PILHA_VAZIA;
	}
	
	
	d->cod = p->topo->info.cod;
	d->peso = p->topo->info.peso;
	nodo = p->topo;
	p->topo = p->topo->prox;
	free(nodo);

	return SUCESSO;
}


int consultaTopo(Pilha *p, Dado *d) {
	
	if (estaVazia(p) == PILHA_VAZIA){
		return PILHA_VAZIA;
	} 
	
	d->cod = p->topo->info.cod;
	d->peso = p->topo->info.peso;
	
	return SUCESSO;
}


int estaVazia (Pilha *p) {
	if (p->topo == NULL) {
		return PILHA_VAZIA;
	}
	return SUCESSO;
}


void exibe(Pilha *p) {

	if(estaVazia(p) == PILHA_VAZIA) {
		printf("A pilha está vazia\n");
		return;
	}


	int contador = 1;
	Nodo *nodoTopo;

	nodoTopo = p->topo;
	printf("------- PILHA ------\n");
	printf("\n");
	while (nodoTopo != NULL) {
			printf(" -- %dº NODO -- \n", contador);
			if (nodoTopo->info.cod >= 10) {
				printf("+-----------------+\n");
				printf("| Código |  %d    |\n", nodoTopo->info.cod);
				printf("+-----------------+\n");
			} else {
				printf("+----------------+\n");
				printf("| Código |  %d    |\n", nodoTopo->info.cod);
				printf("+----------------+\n");
			}	
			if (nodoTopo->info.peso >= 100) {
							printf("+ -----------------+\n");
							printf("| Peso\t|  %.2f  |\n", nodoTopo->info.peso);
							printf("+ -----------------+\n");
							printf("\n");
			} else if (nodoTopo->info.peso < 10) {
				printf("+----------------+\n");
				printf("| Peso\t|  %.2f  |\n", nodoTopo->info.peso);
				printf("+----------------+\n");
				printf("\n");	
			} else {
				printf("+----------------+\n");
				printf("| Peso\t|  %.2f |\n", nodoTopo->info.peso);
				printf("+----------------+\n");
				printf("\n");	
			}

		contador++;
		nodoTopo = nodoTopo->prox;
	}
}