// Criar um programa que receba um número inteiro e uma função que retorne 1 se o número digitado for positivo
//  e 0 se o número digitado for negativo.

#include <stdio.h>
#include <stdlib.h>

int posNeg (int n);

int main(void) {
  int n;
  printf("Digite um número: ");
  scanf("%i", &n);
  int resultado = posNeg(n);
  printf("RESULTADO: %i\n", resultado);
}

int posNeg (int n) {
  if (n >= 0) return 1;
  if (n < 0) return 0;
}