// 2.3 Escreva uma funça o chamada duplaClassificada que classifique 2 valores inteiros conforme o co digo
// passado como argumento (0-ordem crescente 1-ordem decrescente).
// Entrada: Um co digo que identifica a ordem de classificaça o (0-ordem crescente 1-ordem decrescente).
// Entrada: Dois valores inteiros.
// Saída: Os 2 valores de entrada na ordem desejada
// Retorno: Nenhum
// Escreva um programa para ler uma quantidade indeterminada de duplas de valores. Escrever cada dupla em
// ordem crescente se a soma dos elementos da dupla for par e em ordem decrescente se a soma for í mpar. Os
// valores em ordem (conforme o caso) devem ser obtidos atrave s da chamada a funça o duplaClassificada. O
// programa termina quando os dois valores informados forem iguais (nesta situaça o os valores na o devem ser
// impressos).
// [Entrada] [Saída]
// 1 2 2 1
// 4 3 4 3
// 2 4 2 4
// 10 2 2 10
// 1 3 1 3
// 5 3 3 5
// 2 2 


#include <stdio.h>

void duplaClassificada (int ordem, int *p1, int *p2);

int main (void) {
    int n1, n2, ordem; 


    do {
        printf("Digite um número: ");
        scanf("%i", &n1);
        printf("Digite outro número: ");
        scanf("%i", &n2);
        if (n1 == n2) break;
        printf("Digite a ordem que deseja classificar: 0 - crescente | 1 - decrescente: ");
        scanf("%i", &ordem);
        duplaClassificada(ordem, &n1, &n2);    
    }while (n1 != n2);

      

    return 0;
}


void duplaClassificada (int ordem, int *p1, int *p2) {
    int aux;
    switch (ordem)
    {
    case 0:
        if (*p1 > *p2) {
            aux = *p1;
            *p1 = *p2;
            *p2 = aux;
        }
        printf("%i %i\n", *p1, *p2);
        break;
    case 1:
        if (*p1 < *p2) {
             aux = *p1;
            *p1 = *p2;
            *p2 = aux;
        }
        printf("%i %i\n", *p1, *p2);
    default:
        break;
    }

}