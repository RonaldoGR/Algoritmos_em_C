/* Exercício bem completo com as principais formas de exibir uma matriz e a soma de seus valores,
  abordando loops, condicionais, contadores, acumuladores, funções, etc.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define TAMANHO 4

void matrizCompleta (int m[TAMANHO][TAMANHO]);
void trianguloSuperior (int m[TAMANHO][TAMANHO]);
void trianguloInferior (int m[TAMANHO][TAMANHO]);
void diagonalPrincipal (int m[TAMANHO][TAMANHO]);
void diagonalSecundaria (int m[TAMANHO][TAMANHO]);
void acimaDP (int m[TAMANHO][TAMANHO]);
void abaixoDP (int m[TAMANHO][TAMANHO]);
void acimaDS (int m[TAMANHO][TAMANHO]);
void abaixoDS (int m[TAMANHO][TAMANHO]);


int main (void) {
  int i, j, somaDS, somaDP, somaTOTAL, somaTS, somaTI, operacao;
  char op;

  int m[TAMANHO][TAMANHO] = {
    {4,4,4,4},
    {5,5,5,5},
    {6,6,6,6},
    {7,7,7,7}
  };


  do {
    somaDS = 0;
    somaDP = 0;
    somaTOTAL = 0;
    somaTS = 0;
    somaTI = 0;


    for (i = 0; i < TAMANHO ; i++) {
      for (j = 0; j < TAMANHO; j++) {
          if (i + j == 3) somaDS += m[i][j];
          if (i == j) somaDP += m[i][j];
          if (i <= j) somaTS += m[i][j];
          if (i >= j) somaTI += m[i][j];
          somaTOTAL += m[i][j];
    }
   } 
  
   do {
      printf("Escolha qual opção você deseja realizar: \n");
      printf("1 --- MATRIZ COMPLETA E A SOMA DE TODOS OS SEUS ELEMENTOS\n");
      printf("2 --- DIAGONAL PRINCIPAL E A SUA SOMA\n");
      printf("3 --- SOMENTE OS ELEMENTOS ACIMA DA DIAGONAL PRINCIPAL\n");
      printf("4 --- SOMENTE OS ELEMENTOS ABAIXO DA DIAGONAL PRINCIPAL\n");
      printf("5 --- DIAGONAL SECUNDÁRIA E A SUA SOMA\n");
      printf("6 --- SOMENTE OS ELEMENTOS ACIMA DA DIAGONAL SECUNDÁRIA\n");
      printf("7 --- SOMENTE OS ELEMENTOS ABAIXO DIAGONAL SECUNDÁRIA\n");
      printf("8 --- TRIÂNGULO SUPERIOR E A SUA SOMA\n");
      printf("9 --- TRIÂNGULO INFERIOR E A SUA SOMA\n");
      scanf("%i", &operacao);
      if (operacao < 1 || operacao > 9) {
        printf("Somente opções entre 1 e 9!\n");
        getchar();
        getchar();
        system("clear");
      }
   } while (operacao < 1 || operacao > 9);

  switch (operacao) {
    case 1:
      matrizCompleta(m);
      printf("SOMA TOTAL DA MATRIZ: %i\n", somaTOTAL);
      break;
    case 2:
      diagonalPrincipal(m);
      printf("SOMA DA DIAGONAL PRINCIPAL: %i\n", somaDP);
      break;
    case 3:
      acimaDP(m);
      break;
    case 4:
      abaixoDP(m);
      break;
    case 5:
      diagonalSecundaria(m);
      printf("SOMA DA DIAGONAL SECUNDÁRIA: %i\n", somaDS);
      break;
    case 6:
      acimaDS(m);
      break;
    case 7:
      abaixoDS(m);
      break;
    case 8:
      trianguloSuperior(m);
      printf("SOMA DO TRIÂNGULO SUPERIOR: %i\n", somaTS);
      break;
    case 9:
      trianguloInferior(m);
      printf("SOMA DO TRIÂNGULO INFERIOR: %i\n", somaTI);
      break;
    default:
      printf("Operação inválida!\n");
      break;  

  }

    printf("\n");
    do {
      printf("Deseja realizar a operação novamente? (S/N)\n");
      scanf(" %c", &op);
      if (tolower(op) != 's' && tolower(op) != 'n') {
        printf("Somente 'S/s' ou 'N/n'!\n");
        getchar();
        getchar();
        system("clear");
      } 
    } while (tolower(op) != 's' && tolower(op) != 'n');
  system("clear");  
} while (tolower(op) == 's');
     
  } 



void matrizCompleta (int m[TAMANHO][TAMANHO]) {
  int i, j;

  printf("\n");
  printf("--------- MATRIZ COMPLETA ---------- \n");
  for (i = 0; i < TAMANHO ; i++){
    for (j = 0; j < TAMANHO; j++) {
        printf("[%i]", m[i][j]);
    }
    printf("\n");
  } 
  printf("\n");
}




void trianguloSuperior (int m[TAMANHO][TAMANHO]) {
  int i, j;
  printf("------------ TRIÂNGULO SUPERIOR -------------\n");
  for (i = 0; i < TAMANHO; i++){
    for (j = 0; j < TAMANHO; j++) {
        if ( i <= j) printf("[%i]", m[i][j]);
        else printf("   ");
    }
    printf("\n");
  }
  printf("\n"); 
}


void diagonalPrincipal (int m[TAMANHO][TAMANHO]) {
  int i, j;
  printf("-------------- DIAGONAL PRINCIPAL --------------\n");
  for (i = 0; i < TAMANHO ; i++){
    for (j = 0; j < TAMANHO; j++) {
        if (i == j) printf("[%i]", m[i][j]);
        else printf("   ");
    }
    printf("\n");
  } 
  printf("\n");
}

void diagonalSecundaria (int m[TAMANHO][TAMANHO]) {
  int i, j;
  printf("-------------- DIAGONAL SECUNDÁRIA --------------\n");
    for (i = 0; i < TAMANHO ; i++){
      for (j = 0; j < TAMANHO; j++) {
        if (i + j == 3) printf("[%i]", m[i][j]);
        else printf("   ");
    }
    printf("\n");
  } 
  printf("\n");
}

void trianguloInferior (int m[TAMANHO][TAMANHO]) {
    int i, j;
  printf("------------ TRIÂNGULO INFERIOR -------------\n");
  for (i = 0; i < TAMANHO; i++){
    for (j = 0; j < TAMANHO; j++) {
        if ( i >= j) printf("[%i]", m[i][j]);
    }
    printf("\n");
  }
  printf("\n"); 
}

void acimaDP (int m[TAMANHO][TAMANHO]) {
    int i, j;
  printf("------------ ACIMA DA DIAGONAL PRINCIPAL -------------\n");
  for (i = 0; i < TAMANHO; i++){
    for (j = 0; j < TAMANHO; j++) {
        if ( i < j) printf("[%i]", m[i][j]);
        else printf("   ");
    }
    printf("\n");
  }
  printf("\n"); 
}

void abaixoDP (int m[TAMANHO][TAMANHO]) {
        int i, j;
  printf("------------ ABAIXO DA DIAGONAL PRINCIPAL -------------\n");
  for (i = 0; i < TAMANHO; i++){
    for (j = 0; j < TAMANHO; j++) {
        if ( i > j) printf("[%i]", m[i][j]);
        else printf("   ");
    }
    printf("\n");
  }
  printf("\n"); 
}


void acimaDS (int m[TAMANHO][TAMANHO]) {
  int i, j;
  printf("------------ ACIMA DA DIAGONAL SECUNDÁRIA -------------\n");
  for (i = 0; i < TAMANHO; i++){
    for (j = 0; j < TAMANHO; j++) {
        if ( i + j < 3) printf("[%i]", m[i][j]);
        else printf("   ");
    }
    printf("\n");
  }
  printf("\n"); 

}


void abaixoDS (int m[TAMANHO][TAMANHO]) {
  int i, j;
  printf("------------ ABAIXO DA DIAGONAL PRINCIPAL -------------\n");
  for (i = 0; i < TAMANHO; i++){
    for (j = 0; j < TAMANHO; j++) {
        if ( i + j > 3) printf("[%i]", m[i][j]);
        else printf("   ");
    }
    printf("\n");
  }
  printf("\n"); 

}