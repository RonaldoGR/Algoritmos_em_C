#include <stdio.h>

/* Ler um vetor D de 20 elementos. 
Compacte, a seguir o vetor D, retirando dele todos os valores nulos ou negativos. 
Escrever o vetor compactado. */

int main (void) {

  int d[20],i, tamanho = 0, c = 0;
  

  for (i = 0; i < 20; i++) {
    printf("D[%i] = ", i);
    scanf("%i", &d[i]);
    if (d[i] > 0) {
      tamanho++;
      }
    }

    int aux[tamanho];

  printf("\n");

  for (i = 0; i < 20; i++) {
    if (d[i] > 0) {
    	aux[c] = d[i];
    	c++;
	  }
  }
  
  for (i = 0; i < tamanho; i++) {
    printf("D[%i] = %i \n", i, aux[i]);
  }

}
