// 2.2 Escreva uma funça o em C chamada classificaCrescente que classifique 2 valores inteiros passados como
// argumento em ordem crescente.
// Entrada/Saída: Dois nu meros inteiros
// Saída: Nenhuma
// Retorno: Nenhum

#include <stdio.h>

void classificaCrescente (int *pq, int *p2);

int main (void) {

    int n1, n2;
    
    do {
        printf("Digite um número: ");
        scanf("%i", &n1);
        printf("Digite outro número: ");
        scanf("%i", &n2);
        classificaCrescente(&n1, &n2);
        if (n1 != n2)  printf("%i %i\n", n1, n2);
        else break;
       
    }while (n1 != n2);
    
    return 0;
}

void classificaCrescente (int *p1, int *p2) {
    int aux;
    if (*p1 > *p2) {
        aux = *p1;
        *p1 = *p2;
        *p2 = aux;
    }
}