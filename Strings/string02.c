#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void) {
  char time1[30], time2[30];
  int gols1, gols2;

  printf("Digite o nome do primeiro time: ");
  scanf("%s", time1);
  printf("Digite o nome do segundo time: ");
  scanf("%s", time2);
  printf("Digite a quantidade de gols do primeiro time: ");
  scanf("%i", &gols1);
  printf("Digite a quantidade de gols do segundo time: ");
  scanf("%i", &gols2);

  if(gols1 > gols2) printf("O vencedor foi: %s com %d gols\n", time1, gols1);
  else if (gols1 < gols2) printf("O vencedor foi: %s com %d gols\n", time2,gols2);
  else printf("O resultado foi empate com %d gol(s) para cada lado!\n", gols1);
}