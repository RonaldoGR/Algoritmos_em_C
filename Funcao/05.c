// Escreva uma função em C que leia um valor em graus celsius e transforme em Fahrenheit. Ex.: temperatura (valor);

#include <stdio.h>
#include <stdlib.h> 

float temperatura (float valor);

int main (void) {
  float valor;
  printf("Digite a temperatura em ºC: ");
  scanf("%f", &valor);
  float resultado = temperatura(valor);
  printf("A temperatura em Fahrenheit será: %.2fºF\n", resultado);
}

float temperatura (float valor) {
  float fahrenheit = (valor * 1.8) + 32;
  return fahrenheit;
}