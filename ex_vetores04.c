/* Ler um vetor Z de 10 elementos. Crie um vetor W, com todos os elementos de Z (na ordem inversa).Escrever o vetor W. */ 

#include <stdio.h>
#include <stdlib.h>

int main (void) {
  int z[10], w[10], i, c = 9;

  for (i = 0; i < 10; i++) {
    printf("Z[%i] = ", i);
    scanf("%i", &z[i]);
    w[c] = z[i];
    c--;
  }
  getchar();
  getchar();
  system("clear");
  printf("--- VETOR Z --- \n");
  printf("\n");
  for (i = 0; i < 10; i++) {
    printf("Z[%i] = %i\n", i, z[i]);  
  }
  printf("\n");
  printf("--- VETOR W ---\n");
  printf("\n");
  for (i = 0; i < 10; i++) {
    printf("W[%i] = %i\n", i, w[i]);  
  }
}