#include <stdio.h>
#include <stdlib.h>
#include "filacf.h"


int main()
{
  int op, dado;
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
                 printf("Digite o dado que deseja inserir: ");
                 scanf("%d", &dado);   
                 insere(&fi, dado);   
                 break;
            case 2:
                 if(estaVazia(fi)) {
                    printf("A pilha está vazia não tem como retirar dados.\n");
                    break;
                 }
                 dado = fi.v[fi.frente];
                 retira(&fi, &dado);   
                 printf("Dado %d retirado com sucesso!\n", &dado);
                 break;
            case 3:  

                 break;
            case 4:
                 
                 break;
      }
      exibeFila(fi);            
    } while (op!=0);  
    
  return 0;
}
