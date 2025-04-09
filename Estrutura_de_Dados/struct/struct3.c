// Defina o tipo Conta para armazenar o numero de uma conta e seu respectivo saldo.
// Implemente as seguintes operaçoes:

// criaConta
// Saída: Uma conta
// Entrada: Numero da conta
// Descriçao: Atribui os valores iniciais. O saldo deve ser
// zerado.

// depositaNaConta
// Entrada/Saída: Uma conta
// Entrada: valor do deposito.
// Descriça o: Atualiza o atributo saldo com o valor do
// deposito.

// retiraDaConta
// Entrada/Saída: Uma conta
// Entrada: valor da retirada.
// Descriçao: Atualiza o atributo saldo com o valor da
// retirada.

// obtemSaldo
// Entrada: uma conta
// Retorno: O saldo da conta

// Escreva um programa para controlar a conta corrente e a conta poupançado do sr. Silva. As contas sao integradas
// de forma que quando nao houver saldo suficiente na conta corrente uma transferencia automatica da conta
// poupança cobrira um eventual saldo (o valor da transferencia deve ser igual ao valor necessario para cobrir o
// saldo negativo). O programa deve ler o numero e o saldo inicial da conta corrente e da poupança criando duas
// variaveis do tipo Conta (cada uma representa uma conta). A seguir ler uma quantidade indeterminada de
// duplas de dados representando respectivamente o codigo da operaçao

// (1. Deposito conta corrente
//  2. Deposito poupança
//   3.Retirada conta corrente
//   4.Retirada poupança
//    5.Fim)

//  e o valor do movimento.
//  O programa termina ao ser informado um codigo igual a 5 (nesta situaça o o valor do movimento nao deve ser lido).
// - Cada conta deve ser armazenada em uma variavel do tipo Conta.
// - A cada operaçao executada o programa deve exibir o saldo atualizado das duas contas.
// - A operaçao de retirada da conta poupança so devera ocorrer se houver saldo disponível, caso contrario a
// mensagem "Saldo insuficiente" devera ser exibida.
// - As operaçoes de deposito e retirada devem ser realizadas com chamadas as funçoes depositaNaConta e
// retiraDaConta.
// - A operaça o de retirada da conta corrente devera ser executada da seguinte forma:
// se saldo na conta corrente for insuficiente então
//  se saldo na poupança for suficiente para cobrir o valor que falta então
//     transferir o valor que falta para a conta corrente e executar a retirada
//  senão
//     exibir a mensagem "Saldo insuficiente"
//  fim_se
// senão
//  executar a retirada
// fim_se

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int numero;
    float saldo;
} Conta;

Conta criaConta(int numero);
Conta depositaNaConta(Conta conta, float deposito);
Conta retiraDaConta(Conta conta, float retirada);
float obtemSaldo(Conta conta);

int main(void)
{
    Conta contaCorrente, contaPoupanca;
    int op, numeroConta, numeroPoupanca;
    float deposito, retirada, movimentoConta;

    do {
        printf("Digite um número para criar a sua conta: ");
        scanf("%d", &numeroConta);
        if (numeroConta <= 0) {
            printf("Somente valores positivos serão aceitos.\n");
            getchar();
            getchar();
        } 
    } while (numeroConta <= 0);
    
    contaCorrente = criaConta(numeroConta);

    do {
        printf("Digite um número para criar a sua conta poupança: ");
        scanf("%d", &numeroPoupanca);
        if (numeroPoupanca <= 0) {
            printf("Somente valores positivos serão aceitos.\n");
            getchar();
            getchar();
        } 
    } while (numeroPoupanca <= 0);
    
    contaPoupanca = criaConta(numeroPoupanca);
    

   
    do
    {
        printf("Digite uma opção para realizar:\n");
        printf("1 --- Depósito Conta Corrente\n");
        printf("2 --- Depósito na Conta Poupança\n");
        printf("3 --- Retirada na Conta Corrente\n");
        printf("4 --- Retirada na Conta Poupança\n");
        printf("5 --- Fim\n");
        printf("\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Digite o valor que deseja depositar na Conta Corrente: ");
            scanf("%f", &deposito);
            contaCorrente = depositaNaConta(contaCorrente, deposito);
            printf("Saldo atualizado da Conta Corrente: %.2f\n", obtemSaldo(contaCorrente));
            printf("Saldo atualizado da Conta Poupança: %.2f\n", obtemSaldo(contaPoupanca));
            printf("\n");
            break;
        case 2:
            printf("Digite o valor que deseja depositar na Conta Poupança: ");
            scanf("%f", &deposito);
            contaPoupanca = depositaNaConta(contaPoupanca, deposito);
            printf("Saldo atualizado da Conta Corrente: %.2f\n", obtemSaldo(contaCorrente));
            printf("Saldo atualizado da Conta Poupança: %.2f\n", obtemSaldo(contaPoupanca));
            printf("\n");
            break;
        case 3:

            printf("Digite o valor que deseja retirar da Conta Corrente: ");
            scanf("%f", &retirada);

            if (retirada < contaCorrente.saldo) {
                contaCorrente = retiraDaConta(contaCorrente, retirada);
                printf("Saldo atualizado da Conta Corrente: %.2f\n", obtemSaldo(contaCorrente));
                printf("Saldo atualizado da Conta Poupança: %.2f\n", obtemSaldo(contaPoupanca));
                printf("\n");
                break;
            }


            if (retirada > contaCorrente.saldo) {
                if (contaPoupanca.saldo >= (retirada - contaCorrente.saldo)) {
                    movimentoConta = retirada - contaCorrente.saldo;
                    contaPoupanca.saldo -= movimentoConta;
                    contaCorrente.saldo += movimentoConta;
                     
                    contaCorrente = retiraDaConta(contaCorrente, retirada);
                    printf("Saldo atualizado da Conta Corrente: %.2f\n", obtemSaldo(contaCorrente));
                    printf("Saldo atualizado da Conta Poupança: %.2f\n", obtemSaldo(contaPoupanca));
                    printf("\n");
                    break;
                } else {
                    printf("Saldo insuficiente para realizar retiradas.\n");
                    printf("\n");
                    break;
                }    
             }
            break;

        case 4:
            printf("Digite o valor que deseja retirar da Conta Poupança: ");
            scanf("%f", &retirada);

            if (contaPoupanca.saldo > retirada) {
                contaPoupanca = retiraDaConta(contaPoupanca, retirada);
                printf("Saldo atualizado da Conta Corrente: %.2f\n", obtemSaldo(contaCorrente));
                printf("Saldo atualizado da Conta Poupança: %.2f\n", obtemSaldo(contaPoupanca));
                printf("\n");
                break;
            } else {
                printf("Saldo insuficiente para realizar retiradas.\n");
                printf("\n");
                break;
            }
            printf("\n");
            break;

        case 5:
            printf("Encerrando o programa...\n");
            break;

        default:
            break;
        }

    } while (op != 5);

    return 0;
}

Conta criaConta(int numero)
{
    Conta conta;
    conta.numero = numero;
    conta.saldo = 0;
    return conta;
}

Conta depositaNaConta(Conta conta, float deposito)
{
    conta.saldo += deposito;
    return conta;
}

Conta retiraDaConta(Conta conta, float retirada)
{
    conta.saldo -= retirada;
    return conta;
}

float obtemSaldo(Conta conta)
{
    return conta.saldo;
}