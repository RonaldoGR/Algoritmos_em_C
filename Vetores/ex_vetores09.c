/* Ler 2 vetores: R de 5 elementos e S de 10 elementos. Gere um vetor X de 15 elementos cuja as 5 primeiras posiçõeses
 contenha os elementos de R e as 10 últimas posições os elementos de S. 
 Escrever o vetor X.*/

#include <stdio.h>
#include <stdlib.h>

int main (void) {
  int r[5], s[10], x[15], i;

  for (i = 0; i < 5; i++) {
    printf("R[%i] = ", i);
    scanf("%i", &r[i]);
    x[i] = r[i];
  }
  for (i = 0; i < 10; i++) {
    printf("S[%i] = ", i);
    scanf("%i", &s[i]);  
    x[i+5] = s[i];  
  }
  system("clear");
  for(i = 0; i < 15; i++) {
    printf("X[%i] = %i\n", i, x[i]);
  }
}