/* Ler um vetor X de 10 elementos. 
A seguir copie todos os valores negativos de vetor X para o vetor R (sem deixar elementos vazios entre os valores copiados).
Escrever o vetor R. */ 

#include <stdio.h>
#include <stdlib.h>

int main (void) {
 int x[10], r[10], i, negativos = 0;

  for (i = 0; i < 10; i++) {
    printf("X[%i] = ", i);
    scanf("%i", &x[i]);
    if (x[i] < 0 ){
      r[negativos] = x[i];
      negativos++;
    }
  }
  printf("\n");
  printf("--- VETOR R ---\n");
  printf("\n");
  for (i = 0; i < negativos; i++) {
    printf("R[%i] = %i\n", i, r[i]);    
  }
}