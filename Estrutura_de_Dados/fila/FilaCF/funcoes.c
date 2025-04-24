#include <stdio.h>
#include <stdlib.h>
#include "filacf.h"


void criaFila(FilaCF *f){
     f->frente = 0;
     f->re = -1;
}

int insere(FilaCF *f,Dado dado){
   if (estaCheia(*f) == FILA_CHEIA) {
          return FILA_CHEIA;
     }
    if (f->re == -1){
     f->re = f->frente;
     f->v[f->re] = dado;
     return SUCESSO;
    }
  
     f->re = (f->re + 1) % MAX_NODOS;
     f->v[f->re] = dado;
     return SUCESSO;
}

int retira(FilaCF *f,Dado *dado){
     if (estaVazia(*f)) {
          return FILA_VAZIA;
     }

     *dado = f->v[f->frente];

     if (f->frente == f->re) {
          f->frente = 0;
          f->re = -1;
     } else {
          f->frente = (f->frente + 1) % MAX_NODOS;
     }
     return SUCESSO;     

}

int estaCheia(FilaCF f){
     if (f.re == -1) {
          return SUCESSO;
     }

     if ((f.re + 1) % MAX_NODOS == f.frente) {
          return FILA_CHEIA;
     }
     return SUCESSO;
}

int estaVazia(FilaCF f){
     if (f.re == -1) {
          return FILA_VAZIA;
     }
     return SUCESSO;

}

int consulta(FilaCF f){
	if (estaVazia(f)){
		return FILA_VAZIA;
	}
	printf("-- Dado da frente -- \nCódigo: %d\nPeso: %.2f\n", f.v[f.frente].cod, f.v[f.frente].peso);
	return SUCESSO;

}


int pesquisa(FilaCF *f, int codigo) {
     FilaCF temp;
     int tamanho, resultado;
    

     criaFila(&temp);

	if (estaVazia(*f)) {
		return FILA_VAZIA;
	}

     
     tamanho = tamanhoFila(f);
	 
     Dado aux;
     
	 for (int i = 0; i < tamanho; i++) {
          retira(f, &aux);
	 	if (aux.cod == codigo) {
               printf("\n-- Dado encontrado --\nCódigo: %d\nPeso: %.2f\n", aux.cod, aux.peso);
			resultado = SUCESSO;
		}
          else {
               resultado = DADO_INEXISTENTE;
          }
          insere(&temp, aux);
	 }

      while (!estaVazia(temp)) {
          retira(&temp, &aux);
          insere(f, aux);
      }
	return resultado;
}

void exibeFila(FilaCF f){
     int i = f.frente;
          printf("\n-- EXIBINDO A FILA --\n");
          while (i != (f.re +1) % MAX_NODOS) {
               printf("\nCódigo: %d\n", f.v[i].cod);
               printf("Peso: %.2f\n", f.v[i].peso);
               i = (i + 1) % MAX_NODOS;
          }
     
     printf("FRENTE: %d\nRE: %d\n\n",f.frente, f.re);      
}



int tamanhoFila(FilaCF *f) {
     int tamanho;
     if(estaVazia(*f)){
          return FILA_VAZIA;
     }
     if (f->re >= f->frente) {
          tamanho = f->frente - f->re  + 1;
          return tamanho;
     }
     tamanho = MAX_NODOS - f->frente - f->re + 1;
     return tamanho;
}