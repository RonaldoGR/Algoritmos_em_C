/*
  Escreva um programa em C que solicita o total gasto pelo cliente de uma loja,
  imprime as opções de pagamento, 
  solicita a opção desejada e imprime o valor total das prestações (se houverem).

  OPÇÃO 1: à vista com 10% de desconto
  OPÇÃO 2: em duas vezes (preço da etiqueta)
  OPÇÃO 3: em até 10 vezes com 3% de juros (somente para compras acima de R$ 100,00)

  EX.: compra (valor, op);
*/

#include <stdio.h>
#include <stdlib.h>

void compra (float valor, int op);

int main (void) {
  int op;
  float valor;

  printf("Digite o total gasto pelo cliente: ");
  scanf("%f", &valor);

  do {
    printf("Escolha o método de pagamento\n");
    printf("OPÇÃO 1 - à vista com 10 por cento de desconto.\n");
    printf("OPÇÃO 2 - em duas vezes (preço da etiqueta).\n");
    printf("OPÇÃO 3 - em até 10x com 3 por cento de juros. \n");
    scanf("%i", &op);
    if (op > 3 || op < 1) {
      printf("Somente opções de 1 a 3!\n");
      getchar();
      getchar();
    }
    if (op == 3 && valor < 100.1 ) {
      printf("Essa opção é somente para valores acima de R$100,00\n");
      getchar();
      getchar();
    }
    system("clear");
  } while ((op > 3 || op < 1) || (op == 3 && valor < 100.1));

  compra(valor, op);
}

void compra (float valor, int op) {
  float desconto, parcela, juros;
  if (op == 1) {
    desconto = valor * 10 / 100;
    valor -= desconto;
    printf("O valor a ser pago será: %.2f\n", valor);
  }
  else if (op == 2) {
    parcela = valor / 2;
    printf("O pagamento será feito por 2 parcelas de: %.2f\n", parcela);
  }
  else {
    juros = valor * 3 / 100;
    valor += juros;
    parcela = valor / 10;
    printf("O pagamento terá %.2f de juros e será realizado em 10 parcelas de %.2f\n", juros, parcela);
  }

}