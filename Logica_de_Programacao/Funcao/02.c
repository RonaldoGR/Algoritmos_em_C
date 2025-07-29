// Crie um programa em C que leia três notas (aceitar somente valores de zero a dez)
// e uma função que receba esses valores e escreva a média dos valores e o maior deles


#include <stdio.h>
#include <stdlib.h>

void media ( float n[3]);

int main (void) {
  float n[3];
  int i;
  for (i = 0; i < 3; i++) {
    do {
      printf("Digite a %iª nota: ", i+1);
      scanf("%f", &n[i]);
      if (n[i] > 10 || n[i] < 0) {
        printf("Somente valores entre 0 e 10!\n");
        getchar();
        getchar();
      }
      system("clear");
    } while (n[i] > 10 || n[i] < 0);
  }
  media(n);
}

void media ( float n[3]) {
  float maior = 0, soma = 0, media_nota;
  int i;
  for (i = 0; i < 3; i++) {
    if (i == 0) maior = n[i];
    if(n[i] > maior) maior = n[i];
    soma += n[i];
  }
  media_nota = soma / 3;
  printf("Média das notas: %.2f\n", media_nota);
  printf("Maior nota: %.2f\n", maior);
}