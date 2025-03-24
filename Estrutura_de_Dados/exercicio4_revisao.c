#include <stdio.h>
#include <stdlib.h>

// 4 Escreva	uma	função	chamada	maiorNumero que	receba	como	entrada	dois	inteiros	positivos	e	retorne	o	
// maior	deles	ou	o	valor	-1	se	eles	forem	iguais.	Considere	que	os	valores	de	entrada	são	sempre	positivos	(não	
// é	necessário	validar).
// Escreva	 um	 programa	 em	 C	 para	 ler	 um	 valor	 N.	 A	 seguir	 ler	 N	 duplas	 de	 inteiros	 (considere	 que	 serão	
// informado	apenas	valores	positivos).	Para	cada	dupla	informada	exibir	o	maior	elemento	ou	a	frase	“Eles	são	
// iguais”.	Para	obter	o	maior	elemento	deve	ser	utilizada	a	função	maiorNumero.

int maiorNumero (int n1, int n2);
int main (void) {
    int N, i, n1, n2, resultado;

    printf("Digite a quantidade de dupla: ");
    scanf("%i", &N);
    for (i = 0; i < N; i++) {
        printf("Digite o primeiro valor: ");
        scanf("%i", &n1);
        printf("Digite o segundo valor: ");
        scanf("%i", &n2);
        maiorNumero(n1, n2);
    }
    
    return 0;
}

int maiorNumero (int n1, int n2) {
    if (n1 > n2) {
        printf("%i é maior.\n", n1);
        return n1;
    }
    else if (n1 < n2) {
        printf("%i é maior.\n", n2);
        return n2;
    }
    else {
        printf("Os numeros são iguais.\n");    
        return -1;
    }
}