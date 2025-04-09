#include <stdio.h>
#include "Cheque.h"

Cheque criaCheque (int numero) {
    Cheque cheque;
    cheque.numero = numero;
    cheque.situacao = 0;
    cheque.valor = 0.0;

    return cheque;
}


void exibeCheque (Cheque* cheque) {
    printf("Numero: %d\nSituação: %d\nValor: %.2f\n", cheque->numero, cheque->situacao, cheque->valor);
  
}


int obtemSituacao (Cheque cheque) {
    return cheque.situacao;
}



float obtemValor (Cheque cheque) {
    return cheque.valor;
}


int obtemNumero (Cheque cheque) {
    return cheque.numero;
}


Cheque compensaCheque (Cheque cheque) {
    if(cheque.situacao == 1)
        cheque.situacao = 2;
    else
        printf("É preciso estar com o cheque emitido para compensar. Código 1.\n");
    
    return cheque;    


}
Cheque emiteCheque (Cheque cheque, float valor) {
    cheque.valor = valor;
    if (cheque.situacao == 0)
        cheque.situacao = 1;
    else    
        printf("É preciso estar com o cheque em branco para emitir. Código 0.\n");
    return cheque;
}