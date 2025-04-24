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
      printf("\n0. Fim  \n1.Insere  \n2.Retira  \n3.Quantidade de nodos  \n4. Exibe situação da fila  \n5.Consulta frente \n6.Pesquisa dado\n");  
      printf("Operacao: ");    
      scanf("%d", &op);
      printf("\n");

      switch(op){
            case 1:
               if(estaCheia(fi) == FILA_CHEIA){
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
                 if(estaVazia(fi) == 1) {
                    printf("A pilha está vazia não tem como retirar dados.\n");
                    break;
                 }
                 dado = fi.v[fi.frente];
                 retira(&fi, &dado);   
                 printf("Dado retirado com sucesso!\n");
                 printf("Código: %d\n", dado.cod);
                 printf("Peso: %.2f\n", dado.peso);
                 break;
            case 3:  
                 int nodos;
                 if (estaVazia(fi) == 1) nodos = 0;
                 else if (fi.re >= fi.frente) nodos = (fi.re - fi.frente ) + 1;
                 else nodos = (MAX_NODOS - fi.frente) + (fi.re + 1); // se houve uma volta
                 
                 printf("Quantidade de nodos na fila: %d\n", nodos);
                 break;
            case 4:
                 if (estaVazia(fi) == FILA_VAZIA) printf("A fila está vazia\n");
                 else if (estaCheia(fi) == FILA_CHEIA)printf("A fila está cheia\n");
                 else printf("A fila possui 1 ou mais nodos\n"); 
                 break;
            case 5:
               consulta(fi);
               break;     
            case 6:
               int codigo;
               printf("Digite o código que deseja pesquisar na fila: ");
               scanf("%d", &codigo);
               if(pesquisa(&fi, codigo) == DADO_INEXISTENTE) printf("\nDado não encontrado\n");
               break;   
            default:
               break;   
      }
      exibeFila(fi);            
    } while (op!=0);  
    
  return 0;
}
