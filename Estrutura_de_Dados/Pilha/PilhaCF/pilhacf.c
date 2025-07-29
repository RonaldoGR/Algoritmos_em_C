#include <stdio.h>
#include <stdlib.h>
#include "pilhacf.h"

void criaPilha(PilhaCF *pl){
     pl->topo= -1;
}

void exibePilha(PilhaCF pl){
     int f;
     printf("\n");
     printf("Exibindo a Pilha\n");
     printf("[dado]\n");
     for (f=pl.topo; f >= 0; f--) {
          printf("Nodo: %d\n", f+1);
          printf("Código: %d\n", pl.v[f].cod);    
          printf("Peso: %.2f\n", pl.v[f].peso);
          printf("\n");
     }     
}


int empilha(PilhaCF *pl, Dado d) {
     if (pl->topo == MAX_NODOS - 1){
          return PILHA_CHEIA;
     }
     pl->topo++;
     pl->v[pl->topo] = d;
     return SUCESSO;
}


int desempilha(PilhaCF *pl) {
     if (pl->topo == -1) {
          return PILHA_VAZIA;
     }
     printf("Dado desempilhado com sucesso.\n");
     printf("-- Dado -- \n");
     printf("Código: %d\n", pl->v[pl->topo].cod);
     printf("Peso: %.2fkg\n", pl->v[pl->topo].peso);
     pl->topo--;
     return SUCESSO;

}


int estaCheia(PilhaCF pl) {
     if (pl.topo == MAX_NODOS - 1) {
          return PILHA_CHEIA;
     }
     return SUCESSO;

}


int estaVazia(PilhaCF pl){
     if (pl.topo == - 1) {
          return PILHA_VAZIA;
     }
     return SUCESSO;

}


int consultaTopo(PilhaCF pl){
     int i;

     if (pl.topo == -1) {
          return PILHA_VAZIA;
     }
     printf("-- Dados no topo da pilha -- \n");
     printf("Código: %d\n", pl.v[pl.topo].cod);
     printf("Peso: %.2f\n", pl.v[pl.topo].peso);  
     return SUCESSO;
}



int pesquisa(PilhaCF pl, int *d){
    int i;

     if (pl.topo == -1) {
          return PILHA_VAZIA;
     }
  
    for (i = pl.topo; i >= 0 ; i--) {
     
          if (pl.v[i].cod == *d){
               printf("O código %d está na pilha.\n", *d);
               printf(" -- Dados -- \n");
               printf("Código: %d\n", pl.v[i].cod);
               printf("Peso: %.2f\n", pl.v[i].peso);
               return SUCESSO;
          }
    }
    printf("O código não está na pilha.\n");
    return DADO_INEXISTENTE;
}