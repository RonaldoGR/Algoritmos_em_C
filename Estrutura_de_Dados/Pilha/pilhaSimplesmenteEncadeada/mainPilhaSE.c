#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "PilhaSE.h"


int main (void) {
	
	int op;
	Pilha pilha;
	setlocale(LC_ALL, "Portuguese");
	
	criaPilha(&pilha);
	
	do {
		
		printf(" -------- MENU -------- \n");
		printf("0 --->\t  Fim\n");
		printf("1 --->\t Empilha\n");
		printf("2 --->\t Desempilha\n");
		printf("3 --->\t Quantidade de nodos\n");
		printf("4 --->\t Exibe situacao da lista\n");
		printf("5 --->\t Consulta topo\n");
		printf("-----------------------------\n");
		printf("\n");
		printf("Digite uma operação: ");
		scanf("%d", &op);
		
		switch (op) {
			case 0:
				printf("Saindo...\n");
				break;
			
			case 1: {
				
				Dado dado;
				printf("Digite o código: ");
				scanf("%d", &dado.cod);
				printf("Digite o peso: ");
				scanf("%f", &dado.peso);
				printf("\n");
				empilha(&pilha, dado);
				break;
			}
			case 2: {
				Dado dadoDesempilhado;
				if(estaVazia(&pilha) == PILHA_VAZIA) {
					printf("A pilha está vazia\n");
					printf("\n");
					break;
				}
				desempilha(&pilha, &dadoDesempilhado);
				printf("Dado desempilhado com sucesso!\n");
				printf("+ ---------------- +\n");
				printf("| Código |  %d      |\n", dadoDesempilhado.cod);
				printf("+ ---------------- +\n");
				printf("| Peso\t|  %.2f   |\n", dadoDesempilhado.peso);
				printf("+ ---------------- +\n");
				printf("\n");
				break;	
			}
			
			case 3: {
				int quantidadeDeNodos = 0;
			
				if(estaVazia(&pilha)){
					printf("Quantidade de nodos: %d\n", quantidadeDeNodos);
					printf("\n");
					break;
				}	
					
				Nodo *nodoTopo = pilha.topo;	
					
					
				 while(nodoTopo != NULL) {
				 	quantidadeDeNodos++;
				 	nodoTopo = nodoTopo->prox;
				 }
				 
				 printf("Quantidade de nodos: %d\n", quantidadeDeNodos);
				 printf("\n");
				 break;
			}
			case 4:
				if (estaVazia(&pilha) == PILHA_VAZIA){
					printf("A pilha está vazia\n");
					printf("\n");
					break;
				}
				printf("A pilha possui 1 ou mais nodos\n");
				printf("\n");
				break;	 
			case 5: {
				Dado dadoDoTopo;
				if (consultaTopo(&pilha,&dadoDoTopo) == PILHA_VAZIA){
					printf("A pilha está vazia\n");
					break;
				}
				
				printf("--- DADOS DO TOPO --- \n");
				printf("Códio: %d\n", dadoDoTopo.cod);
				printf("Peso: %.2f\n", dadoDoTopo.peso);
				printf("----------------------\n");
				break;
			}
			default:
				break;		
		}	
		exibe(&pilha);	
	} while (op != 0);
	return 0;
}