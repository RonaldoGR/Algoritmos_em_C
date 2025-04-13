/* Ler um vetor U de 10 elementos. Troque a seguir o 1º elemento com o último, o 2º com o penúltimo, etc. até o 5o. com o 6o. e escreva o vetor U assim modificado. */ 

#include <stdio.h>
#include <stdlib.h>

int main (void) {
 int u[10], aux, i;

  for (i = 0; i < 10; i++) {
    printf("U[%i] = ", i);
    scanf("%i", &u[i]);
    system("clear");
  }

  for(i = 0; i < 5; i++) {
    aux = u[i];
    u[i] = u[9-i];
    u[9-i] = aux;
  }
  for(i = 0; i < 10; i++) {
    printf("U[%i] = %i\n", i, u[i]);
  }
}