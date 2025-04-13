// Defina o tipo Cheque para armazenar o numero, o valor e a situaça o (0-Em branco, 1-Emitido, 2-    Compensado) de um cheque.
//     Implemente as seguintes operaçoes:

//     Inclua as definiçoes e proto tipos no arquivo Cheque.h
//     A implementaçao das funçoes no arquivo Cheque.c

//     criaCheque
//     Saída: um cheque
//     Entrada: Numero do cheque
//     Descriçao: Atribui os valores iniciais. O valor e a situaçao do cheque devem ser zerados.

//     exibeCheque
//     Entrada: Um cheque
//     Descriçao: Exibe um uma unica linha as 3 informaçoes contidas no cheque.

//     obtemSituacao
//     Entrada: um cheque
//     Retorno: O codigo da situaçao do cheque

//     obtemValor
//     Entrada: um cheque
//     Retorno: O valor do cheque

//     obtemNumero
//     Entrada: um cheque
//     Retorno: O numero do cheque

//     compensaCheque
//     Entrada/Saída: um cheque
//     Retorno: Codigo 0 (sucesso), 1 (erro)
//     Descriçao: Altera a situaça o do cheque para 2 (compensado). O cheque so pode ser compensado se a situaçao for igual a 1 (emitido)

//     emiteCheque
//     Entrada/Saída: um cheque
//     Entrada: Valor do cheque
//     Retorno: Codigo 0 (sucesso), 1 (erro)
//     Descrição: Atribui um valor ao cheque e altera a situaçao para o co digo 1 (Emitido). O cheque so pode ser
//     emitido se a situaçao for igual a 0 (em branco)

//     Escreva um programa para ler dois numeros e criar dois cheques armazenando-os em 2 variaveis (usar
//     criaCheque).

//     Ler 2 valores e emitir os 2 cheques (usar emiteCheque).

//     Escrever na tela os dados dos 2 cheques (usar exibeCheque)

//     Compensar o que possui maior valor (usar obtemValor para obter o valor de cada cheque e compensaCheque
//     para fazer a compensaçao.

//     Escreva somente a codigo da situaça o dos 2 cheques (usar obtemSituacao).

//     Escreva somente a numero dos 2 cheques (usar obtemNumero).

#include <stdio.h>
#include <stdlib.h>
#include "Cheque.h"

int main(void)
{
    int n1, n2;
    float v1, v2;

    printf("Digite o primeiro número: ");
    scanf("%d", &n1);
    system("clear");
    printf("Digite o segundo número: ");
    scanf("%d", &n2);
    system("clear");

    Cheque cheque1 = criaCheque(n1);
    Cheque cheque2 = criaCheque(n2);

    printf("Digite o primeiro valor: ");
    scanf("%f", &v1);
    cheque1 = emiteCheque(cheque1, v1);
    system("clear");
    printf("Digite o segundo valor: ");
    scanf("%f", &v2);
    cheque2 = emiteCheque(cheque2, v2);
    system("clear");

    exibeCheque(&cheque1);
    printf("\n");
    exibeCheque(&cheque2);
    printf("\n");

    float valorCheque1 = obtemValor(cheque1);
    float valorCheque2 = obtemValor(cheque2);

    if (valorCheque1 > valorCheque2)
    {
        cheque1 = compensaCheque(cheque1);
    }
    else
    {
        cheque2 = compensaCheque(cheque2);
    }

    int situacao1 = obtemSituacao(cheque1);
    int situacao2 = obtemSituacao(cheque2);
    printf("Situação Cheque 1: %d\nSituação Cheque 2: %d\n", situacao1, situacao2);

    n1 = obtemNumero(cheque1);
    n2 = obtemNumero(cheque2);
    printf("\n");

    printf("Número do Cheque 1: %d\nNúmero do Cheque 2: %d\n", n1, n2);

    return 0;
}