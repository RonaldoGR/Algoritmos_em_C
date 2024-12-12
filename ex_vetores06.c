/* Ler um vetor B de 10 elementos e um valor X. Escreva as posições do vetor B em que aparece um valor igual a X. */ 

#include <stdio.h>
#include <stdlib.h>

int main (void) {
 int b[10], x, i;

  printf("Digite o valor de X: ");
  scanf("%i", &x);
  system("clear");

  for (i = 0; i < 10; i++) {
    printf("B[%i] = ", i);
    scanf("%i", &b[i]);
  }
  system("clear");
  printf("O valor de X apareceu nas posicoes: \n");
  printf("\n");
  for (i = 0; i < 10; i++) {
    if(b[i] == x) printf("B[%i] = %i\n", i, b[i]);
  }
}