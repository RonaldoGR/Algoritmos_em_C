#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Escreva	um	programa	em	C	para	ler	um	inteiro	Q	(máximo	10).	A	seguir	ler	um	vetor	Z	de	Q	elementos	e	
// um	 valor	 Y.	 Copiar	 todos	 os	 elementos	maiores	 que	 Y	 que	 estão	no	 vetor	 Z	 para	 um	 vetor	W	 (sem	 deixar	
// elementos	vazios	entre	os	valores	copiados).	Escrever	o	vetor	W após	o	término	cópia.

int main (void) {
    int Q, i, Y, contador = 0;

    srand(time(NULL));


    printf("Digite o tamanho do vetor: ");
    scanf("%d", &Q);
    int Z[Q];
    for (i = 0; i < Q; i++) {
        printf("Z[%d] = ", i);
        Z[i] =  rand() % 10 + 1;
        printf("%d\n", Z[i]);
    
    }
    
    printf("\n");
    printf("Digite o valor de Y: ");
    scanf("%d", &Y);

    int W[Q];

    for(i = 0; i < Q; i++) {
        if(Z[i] > Y){
            W[contador] = Z[i];
            contador++;
        } 
    }

    for (i = 0; i < contador; i++) {
        printf("W[%d] = %d\n", i, W[i]);
    }
    
    return 0;
}