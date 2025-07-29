#ifndef Cheque_H
#define Cheque_H


typedef struct {
    int numero;
    int situacao;
    float valor;
} Cheque;

Cheque criaCheque (int numero);
void exibeCheque (Cheque* cheque);
int obtemSituacao (Cheque cheque);
float obtemValor (Cheque cheque);
int obtemNumero (Cheque cheque);
Cheque compensaCheque (Cheque cheque);
Cheque emiteCheque (Cheque cheque, float valor);



#endif