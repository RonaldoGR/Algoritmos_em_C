#include <stdio.h>

//Compactar um vetor retirando os valores nulos e menores que 0

int main (void) {

  int d[5],i, tamanho = 0;
  int aux[5]; 

  for (i = 0; i < 5; i++) {
    printf("D[%i] = ", i);
    scanf("%i", &d[i]);
    if (d[i] > 0) {
      aux[tamanho] = d[i];
      tamanho++;
      }
    }

  printf("\n");

  for (i = 0; i < tamanho; i++) {
    printf("D[%i] = %i \n", i, aux[i]);
  }

}
