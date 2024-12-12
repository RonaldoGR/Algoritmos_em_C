/* Ler um vetor que contenha as notas de uma turma de 10 alunos. 
Calcular a média da turma e contar quantos alunos obtiveram nota acima da média.
Escrever a média e o resultado da contagem. */ 

#include <stdio.h>
#include <stdlib.h>

int main (void) {
 float notas[10], media, soma = 0;
 int i, acima_da_media = 0;

  for (i = 0; i < 10; i++) {
    printf("Digite a %iª nota: ", i+1);
    scanf("%f", &notas[i]);
    soma += notas[i];
    system("clear");
  }
  media = soma / 10;
  for (i = 0; i < 10; i++) {
      if(notas[i] > media) acima_da_media++;
  }
  printf("A media foi %.2f e %i alunos obteram a nota acima da media\n", media, acima_da_media);
}