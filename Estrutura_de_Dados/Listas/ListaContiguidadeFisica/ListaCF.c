/*--------------------------------
* Arquivo: ListaCF.c
----------------------------------*/

#include <stdio.h>
#include "ListaCF_H.h"

/*-----------------
* S: uma lista
*/
void criaLista(ListaCF *lt) {
	lt->n = 0;
}

/*-----------------
* E/S: uma lista
* E: um dado
* R: SUCESSO ou LISTA_CHEIA
*/

int estaCheia(ListaCF *lt) {
	if (lt->n == MAX_NODOS){
		return LISTA_CHEIA;
	}
	return SUCESSO;
}

int estaVazia(ListaCF *lt) {
	if(lt->n == 0){
		return LISTA_VAZIA;
	}
	return SUCESSO;
}


int incluiNoFim(ListaCF *lt, Dado d) {
	if (estaCheia(lt) == LISTA_CHEIA)
		return LISTA_CHEIA;
	else {
		lt->v[lt->n] = d;
		lt->n++;
		return SUCESSO;
	}	
}


int incluiNoInicio(ListaCF *lt, Dado d) {
	int i;
	
	if (estaCheia(lt) == LISTA_CHEIA){
		return LISTA_CHEIA;
	}
	if(lt->n == 0){
		lt->v[lt->n] = d;
		lt->n++;
		return SUCESSO;
	}
	int j = lt->n-1;
	for (i = 0; i < lt->n; i++) {
			lt->v[lt->n-i] = lt->v[j];
			j--;
	}
	lt->v[0] = d;
	lt->n++;
	return SUCESSO;

}

int incluiAntes (ListaCF *lt, int codigo, Dado d){
	int i, j, l = 0, resultado = CODIGO_INEXISTENTE;
	if (estaVazia(lt) == LISTA_VAZIA) {
		resultado = CODIGO_INEXISTENTE;
	}
	if (estaCheia(lt) == LISTA_CHEIA) {
		resultado = LISTA_CHEIA;
	}
			
	for (i = 0; i < lt->n; i++){
		printf("codigo do vetor: %d\n", lt->v[i].cod);
		if(codigo == lt->v[i].cod){
			resultado = SUCESSO;
			int k = lt->n-1; // ultima posicao
	
			for (j = i; j < lt->n; j++) {
				lt->v[lt->n-l] = lt->v[k]; // proxima posicao recebe a ultima
				printf("n: %d\n", lt->n-l);
				printf("i: %d\n", i);
				printf("k: %d\n", k);
				l++;
				k--;
			}
			lt->v[i] = d;
			lt->n++;	
			return resultado;	
	    }
	}
	return resultado;
}




int quantidadeDeNodos(ListaCF *lt){
	if (estaVazia(lt) == LISTA_VAZIA){
		return 0;
	}
	if (lt->n == MAX_NODOS){
		return MAX_NODOS;
	}
	return lt->n;
}

int excluiDoFim(ListaCF *lt, Dado *d) {
	if(estaVazia(lt) == LISTA_VAZIA){
		return LISTA_VAZIA;
	}
	*d = lt->v[lt->n-1];
	lt->n--;
	return SUCESSO;
}

int excluiDoInicio(ListaCF *lt, Dado *d) {
	int i;
		if(estaVazia(lt) == LISTA_VAZIA){
		return LISTA_VAZIA;
	}
	
	*d = lt->v[0];
	
	for (i = 0; i < lt->n; i++) {
			lt->v[i] = lt->v[i + 1];
	}
	lt->n--;
	
	return SUCESSO;
}


int excluiNodo(ListaCF *lt, int codigo, Dado *nodo){
	int i, j, resultado = CODIGO_INEXISTENTE;
	if(estaVazia(lt) == LISTA_VAZIA){
		return resultado;
	}
	for (i = 0; i < lt->n; i++) {
		if (codigo == lt->v[i].cod) {
			*nodo = lt->v[i];
			resultado = SUCESSO;
			for (j = i; j < lt->n; j++){
				lt->v[j] = lt->v[j + 1];
			}
			lt->n--;
			return resultado;
		}
 	}
	return resultado;
}




int consultaPorCodigo (ListaCF *lt, int codigo){
	int i;
	for (i = 0; i < lt->n; i++){
		if(codigo == lt->v[i].cod){
			printf("\nCÓDIGO ENCONTRADO!\n");
			printf("\n----- DADO ----- \n");
			printf("Codigo:%d\n", lt->v[i].cod);
			printf("Peso:%.2f\n", lt->v[i].peso);
			printf("----------------\n\n");
			return SUCESSO;
		}
	}
	return CODIGO_INEXISTENTE;
}



void exibe(ListaCF lt) {
	int i;
	
	printf("-------------\n");
	printf("Lista:\n");
	for (i=0; i<lt.n; i++) 
		printf("   %d %.2f\n", lt.v[i].cod,lt.v[i].peso);
	printf("-------------\n\n");			
}
