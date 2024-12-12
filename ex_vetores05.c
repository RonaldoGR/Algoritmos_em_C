/* Ler um vetor A de 10 elementos e um valor V. Conte e escreva quantas vezes o valor V ocorre no vetor A.  */ 

#include <stdio.h>
#include <stdlib.h>

int main (void) {
 int a[10], v, i, c = 0;
  printf("Digite o valor de V: ");
  scanf("%i", &v);
  system("clear");

  for (i = 0; i < 10; i++) {
    printf("A[%i] = ", i);
    scanf("%i", &a[i]);
    if(a[i] == v) c++;  
  }
  getchar();
  getchar();
  system("clear");
  printf("O valor de V apareceu %i vezes.\n", c);
}