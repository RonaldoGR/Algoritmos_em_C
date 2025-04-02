// 2.1 Escreva uma funça o em C chamada duplaCrescente que classifique 2 valores inteiros passados como
// argumento em ordem crescente.
// Entrada: Dois nu meros inteiros
// Saída: Os dois inteiros em ordem crescente.
// Retorno: Nenhum

#include <stdio.h>

void duplaCrescente(int *p1, int *p2);

int main (void) {
    int n1, n2;
    
    do {
        printf("Digite um número: ");
        scanf("%i", &n1);
        printf("Digite outro número: ");
        scanf("%i", &n2);
        duplaCrescente(&n1, &n2);
    }while (n1 != n2);
    return 0;
}

void duplaCrescente(int *p1, int *p2) {
        if (*p1 > *p2) printf("%i %i\n", *p2, *p1);
        else if (*p1 < *p2) printf("%i %i\n", *p1, *p2);
        else return;
}