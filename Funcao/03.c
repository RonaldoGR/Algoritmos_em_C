// Escreva um programa em C para ler 2 valores e uma opção.
//Deverá ser criada uma função para fazer um cálculo e retornar uma resposta.
// Opção:       Operação aritmética: 
//   1 ------------ SOMA
//   2 ------------ SUBTRAÇÃO
//   3 ------------ MULTIPLICAÇÃO
//   4 ------------ DIVISÃO
//   EX.: calculo (v1, v2, op);


#include <stdio.h>
#include <stdlib.h>

float resultado (float v1, float v2, int op);

int main (void) {
  float v1, v2;
  int op;
    printf("Digite o primeiro valor: ");
    scanf("%f", &v1);
    printf("Digite o segundo valor: ");
    scanf("%f", &v2);
    
  do {
      printf("Qual operação você deseja realizar ?\n");
      printf("1 - SOMA \n");
      printf("2 - SUBTRAÇÃO\n");
      printf("3 - MULTIPLICAÇÃO\n");
      printf("4 - DIVISÃO\n");
      scanf("%i", &op);
      if(op > 4 || op < 1) {
        printf("Somente os valores exibidos!\n");
        getchar();
        getchar();
      }
    system("clear");
  } while (op > 4 || op < 1);

  float calculo = resultado(v1, v2, op);
  if (op == 4 && v2 == 0) {
    printf("Não é possível dividir por 0!\n");
  } 
  else if (v1 == 0 && op == 4 ) {
    printf("Não é possível 0 ser divido!\n");
  }
  else {
     printf("RESULTADO DA OPERAÇÃO: %.2f\n", calculo);
  }
}

float resultado (float v1, float v2, int op) {
  switch (op) {
    case 1:
      return  v1 + v2;
    case 2: 
     return v1 - v2;    
    case 3: 
      return v1 * v2;
    case 4:
     return v1 / v2;
    default:
    return 0.0; 
  }
}