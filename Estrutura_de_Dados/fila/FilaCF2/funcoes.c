#include <stdio.h>
#include <stdlib.h>
#include "filacf.h"


void criaFila(FilaCF *f){
     f->frente = 0;
     f->re = -1;
}

int insere(FilaCF *f,Dado dado){
   if (estaCheia(*f)) {
          return FILA_CHEIA;
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
     f->frente = (f->frente + 1) % MAX_NODOS;
     return SUCESSO;     

}

int estaCheia(FilaCF f){
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
	printf("Dado da frente: %d %.2f\n", f.v[f.frente].cod, f.v[f.frente].peso);
	return SUCESSO;

}


int pesquisa(FilaCF *f, int codigo) {
     FilaCF temp;
     int tamanho, resultado = DADO_INEXISTENTE;
    

     criaFila(&temp);

	if (estaVazia(*f)) {
		return FILA_VAZIA;
	}

     if (f->re >= f->frente) tamanho = f->frente - f->re  + 1;
     else tamanho = MAX_NODOS - f->frente - f->re + 1;

	 
     Dado aux;
     
	 for (int i = 0; i < tamanho; i++) {
          retira(f, &aux);
	 	if (aux.cod == codigo) {
               printf("Dado encontrado: %d %.2f\n", aux.cod, aux.peso);
			resultado = SUCESSO;
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
     int i;
     for (i=f.frente; i<=f.re; i++) {
          printf("%d\n", f.v[i].cod);
          printf("%.2f\n", f.v[i].peso);
     }
     printf("\nFr= %d - Re= %d\n\n",f.frente, f.re);      
}



