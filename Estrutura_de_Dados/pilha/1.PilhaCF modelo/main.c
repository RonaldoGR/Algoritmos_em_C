#include <stdio.h>
#include <stdlib.h>
#include "pilhacf.h"


int main(){
    int op, i, nodos;
    PilhaCF pl;
    Dado d;
    
    criaPilha(&pl);

    do {        
      printf("\n");       
      printf("0.Fim\n");
      printf("1. Empilha\n");                  
      printf("2. Desempilha\n");                
      printf("3. Quantidade de Nodos\n");    
      printf("4. Exibe Situacao da Pilha\n");
      printf("5. Exibe Pilha\n");
      printf("6.ConsultaTopo\n");
      printf("7.Pesquisa\n");
      printf("Operacao: ");    
      scanf("%d", &op);

      switch(op){
            case 0:
               printf("Fim\n");
               break;
            case 1:
                printf("Digite o código: ");
                scanf("%d", &d.cod);
                printf("Digite o peso: ");
                scanf("%f", &d.peso);
                empilha(&pl, d);
                break;
            case 2:
                 desempilha(&pl);
                 break;
            case 3:
               nodos = 0;
                for (i = pl.topo; i >= 0; i--) {
                         nodos++;
                     }
                     printf("Quantidade de nodos na pilha: %d\n", nodos); 
                 break;
            case 4:
                 if(estaVazia(pl)) printf("A pilha está vazia\n");
                 else if (estaCheia(pl)) printf("A pilha está cheia\n");
                 else printf("A pilha possui 1 ou mais nodos\n");   
                 break;
            case 6:
                 consultaTopo(pl);
                 break;   
            case 7:
                 printf("Digite o código que deseja verificar: ");
                 scanf("%d", &d.cod); 
                 pesquisa(pl, &d.cod);
                 break;   
      }
      exibePilha(pl);    
       
    } while (op!=0);  
                 
  return 0;
}
