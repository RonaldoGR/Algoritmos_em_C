/* Ler um vetor D de 10 elementos. Crie um vetor E, com todos os elementos de D (na mesma ordem).
 Escrever todo o vetor D e logo após todo o vetor E. */

#include <stdio.h>
#include <stdlib.h>

int main (void) {
  int d[10], e[10], i;

  for (i = 0; i < 10; i++) {
    printf("D[%i] = ", i);
    scanf("%i", &d[i]);
    e[i] = d[i];
  }
  getchar();
  getchar();
  system("clear");
  printf("------ VETOR D ------\n");
  for(i = 0; i < 10; i++) {
    printf("D[%i] = %i\n", i, d[i]);
  }
  printf("\n");
  printf("----------------------------\n");
  printf("\n");
  printf("------- VETOR E ---------\n");

  for (i = 0; i < 10; i++) {
    printf("E[%i] = %i\n", i, e[i]);
  }
}