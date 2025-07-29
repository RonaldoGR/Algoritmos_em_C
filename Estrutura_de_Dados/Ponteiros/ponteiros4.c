// 2.4 Escreva uma funça o em C chamada calcDivisao que receba como entrada dois inteiros e retorne o valor
// da divisa o do primeiro pelo segundo. Retornar tambe m um co digo de erro indicando se foi ou na o possí vel
// calcular a divisa o.
// Entrada: Dois inteiros.
// Saída: O resultado da divisa o (float)
// Retorno: 0 se foi possí vel executar a divisa o e 1 caso o segundo para metro de entrada for igual a zero.
// Escreva um programa em C para ler um valor N. A seguir ler N duplas de valores. Para cada dupla calcular e
// escrever o resultado da divisa o do primeiro valor pelo segundo. Utilizar a funça o calcDivisao para obter o
// resultado. Caso a funça o retorne o co digo de erro igual a 1 deve ser impressa a mensagem “Divisa o por zero”.
// [Entrada] [Saída]
// 3
// 8 2 4
// 9 2 4.5
// 10 0 Divisão por zero


#include <stdio.h>
#include <stdlib.h>

int calcDivisao(int *p1, int *p2);

int main (void){
    int N, num1, num2;

    printf("Digite quantos valores deseja calcular: ");
    scanf("%i", &N);

    for (int i = 0; i < N; i++) {
        printf("Digite o primeiro valor: ");
        scanf("%i", &num1);
        printf("Digite o segundo valor: ");
        scanf("%i", &num2);
        calcDivisao(&num1, &num2);
        printf("\n");
    }
   
    return 0;
}

int calcDivisao(int *p1, int *p2) {
    float resultado;

    if (*p2 == 0 ) {
        printf("Divisão por zero\n");
        return 1;
    } 

    if (*p1 % *p2 == 0){
        printf("%i", (*p1 / *p2));
        return 0;
    } else {
        resultado = (float) *p1 / *p2;
        printf("%.1f\n", resultado);
        return 0;
    }
}