#include <stdio.h>
#include <stdlib.h>

// Escreva	 uma	 função	 chamada	 exibeDivisores que	 exiba	 na	 tela	 os	 divisores	 do	 inteiro	 passado	 com	
// argumento.
// Escreva	 um	 programa	 em	 C	 para	 imprimir	 os	 números	 de	 1	 a	 20	 com	 seus	 respectivos	 divisores.	 Cada	
// conjunto	de	divisores	deve	ser	impresso	com	a	função	exibeDivisores.	A	saída	deve	ser	impressa	conforme	o	
// formato	abaixo.
void exibeDivisores(int num);

int main (void) {
    int i;

    for(i = 1; i <= 20; i++){
        printf("%i: ", i);
        exibeDivisores(i);
        printf("\n");
    } 
    
    return 0;
}

void exibeDivisores(int num) {
    int i;
    for (i = 1; i <= num; i++) {
        if (num % i == 0) {
            printf("%i ", i);
        }
    }
}