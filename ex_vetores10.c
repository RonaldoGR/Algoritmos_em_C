/* Ler um vetor Q de 10 posições (aceitar somente números positivos). 
Escreva a seguir o valor do maior elemento de Q e a respectiva posição que ele ocupa no vetor. */ 

#include <stdio.h>
#include <stdlib.h>

int main (void) {
 int q[10], i, maior;

  for (i = 0; i < 10; i++) {
    do {
      printf("Q[%i] = ", i);
      scanf("%i", &q[i]);
      if (q[i] < 0) {
        printf("Somente valores positivos!\n");
        getchar();
        getchar();
        system("clear");
      } 
    } while (q[i] < 0);

    if(i == 0) maior = q[i];
    if(q[i] > maior) maior = q[i];
  }
  system("clear");
  printf("O maior valor foi %i \n", maior);

  for(i = 0; i < 10; i++) {
    if(q[i] == maior) printf("A sua posicao foi %i\n", i);
  }
}