#include <stdio.h>
#include <stdlib.h>
#include "filacf.h"


int main()
{
  int op;
  Dado dado;
  FilaCF fi;
  
  criaFila(&fi);
  
  do {
      printf("\n0. Fim  1.Insere  2.Retira  3.Exibe Situacao da Lista  4. Consulta  5.Exibe\n");
      printf("Operacao: ");    
      scanf("%d", &op);

      switch(op){
            case 1:
               if(estaCheia(fi)){
                    printf("A pilha está cheia não tem como inserir dados\n");
                    break;
                 }
                 printf("-- Digite o dado que deseja inserir -- \n");
                 printf("C�digo: ");
                 scanf("%d", &dado.cod);
                 printf("Peso: ");
                 scanf("%f", &dado.peso);
                 insere(&fi, dado);   
                 break;
            case 2:
                 if(estaVazia(fi)) {
                    printf("A pilha está vazia não tem como retirar dados.\n");
                    break;
                 }
                 dado = fi.v[fi.frente];
                 retira(&fi, &dado);   
                 printf("Dado retirado com sucesso!\n");
                 printf("Código: %d\n", fi.v[fi.frente].cod);
                 printf("Peso: %.2f\n", fi.v[fi.frente].peso);
                 break;
            case 3:  
                 int nodosDisponiveis;
                 int nodos;
                 
                 if (fi.re >= fi.frente) nodosDisponiveis = fi.frente - fi.re  + 1;
                 else nodosDisponiveis = MAX_NODOS - fi.frente - (fi.re + 1);
                 nodos = MAX_NODOS - nodosDisponiveis;
                 printf("Quantidade de nodos na fila: %d\n", nodos);
                 break;
            case 4:
                 
                 break;
      }
      exibeFila(fi);            
    } while (op!=0);  
    
  return 0;
}
