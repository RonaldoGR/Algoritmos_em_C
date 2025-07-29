#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ListaSE_H.h"


int main(void) {
	int op;
	ListaSE lista;
	setlocale(LC_ALL, "Portuguese");
	
	criaLista(&lista);
	
	do {
		
		printf("+-----------------  MENU -----------------+\n");
		printf("\t0 --->\t  Fim\n");
		printf("\t1 --->\t Inclui no início\n");
		printf("\t2 --->\t Exibe lista\n");
		printf("\t3 --->\t Quantidade de nodos\n");
		printf("\t4 --->\t Exibe situacao da lista\n");
		printf("\t5 --->\t Exclui do início\n");
		printf("\t6 --->\t Inclui no fim\n");
		printf("\t7 --->\t Exclui do fim\n");
		printf("\t8 --->\t Consulta por código\n");
		printf("\t9 --->\t Inclui depois\n");
		printf("\t10 --->\t Exclui nodo\n");
		printf("+-----------------------------------------+\n");
		printf("\n\n");
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
				incluiNoInicio(&lista, dado);
				break;
			}
			case 2: {
				if(estaVazia(&lista)) {
					printf("A lista está vazia\n");
					break;
				}
				printf("+---- EXIBINDO A LISTA ----+\n");
				exibeLista(lista);
				printf("\n");
				break;	
			}
			
			case 3: {
				 int quantidade = quantidadeDeNodos(lista);
				 printf("Quantidade de nodos: %d\n", quantidade);
				 printf("\n");
				 break;
			}
			case 4:
				if (estaVazia(&lista) == LISTA_VAZIA){
					printf("A lista está vazia\n");
					printf("\n");
					break;
				}
				printf("A lista possui 1 ou mais nodos\n");
				printf("\n");
				break;	 
			case 5: {
				Dado dadoDoInicio;
				if (excluiDoInicio(&lista,&dadoDoInicio) == LISTA_VAZIA){
					printf("A lista está vazia\n");
					break;
				}
				
				printf("--- DADOS EXCLUÍDO DO INÍCIO DA LISTA! --- \n");
				printf("+-----------------------+\n");
				printf("| Códio: %d\t\t|\n", dadoDoInicio.cod);
				printf("| Peso: %.2f\t\t|\n", dadoDoInicio.peso);
				printf("+-----------------------+\n");
				break;
			}
			case 6: {
				Dado dado;
				printf("Digite o código: ");
				scanf("%d", &dado.cod);
				printf("Digite o peso: ");
				scanf("%f", &dado.peso);
				printf("\n");
				incluiNoFim(&lista, dado);
				
				break;
			}
			case 7: {
				Dado dadoDoFim;
				if (excluiDoFim(&lista,&dadoDoFim) == LISTA_VAZIA){
					printf("A lista está vazia\n");
					break;
				}
				
				printf("--- DADO EXCLUÍDO DO FIM DA LISTA! --- \n");
				printf("+-----------------------+\n");
				printf("| Códio: %d\t\t|\n", dadoDoFim.cod);
				printf("| Peso: %.2f\t\t|\n", dadoDoFim.peso);
				printf("+-----------------------+\n");
				break;
				break;
			} 
			case 8: {
				int codigo;
				Dado dadoConsultado;
				printf("Digite o código que deseja consultar: ");
				scanf("%d", &codigo);
				if(consultaPorCodigo(&lista, codigo, &dadoConsultado) == CODIGO_INEXISTENTE) {
					printf("Código inexistente.\n");
					break;
				} else {
					printf("--- DADOS DO NODO DA LISTA --- \n");
					printf("+-----------------------+\n");
					printf("| Códio: %d\t\t|\n", dadoConsultado.cod);
					printf("| Peso: %.2f\t\t|\n", dadoConsultado.peso);
					printf("+-----------------------+\n");
				}
				break;
			}
			case 9: {
				Dado dado;
				int codigo;
			
				printf("Digite o código do nodo que deseja incluir depois: ");
				scanf("%d", &codigo);
				printf("Digite o código: ");
				scanf("%d", &dado.cod);
				printf("Digite o peso: ");
				scanf("%f", &dado.peso);
				printf("\n");
				incluiDepois(&lista, codigo, dado);
				break;
			} 
			case 10: {
				int codigo;
				Dado dadoExcluido;
				printf("Digite o código do nodo que deseja excluir: ");
				scanf("%d", &codigo);
				if(excluiNodo(&lista, codigo, &dadoExcluido) == CODIGO_INEXISTENTE) {
					printf("Código inexistente.\n");
					break;
				} else {
					printf("--- DADO EXCLUÍDO DA LISTA --- \n");
					printf("+-----------------------+\n");
					printf("| Códio: %d\t\t|\n", dadoExcluido.cod);
					printf("| Peso: %.2f\t\t|\n", dadoExcluido.peso);
					printf("+-----------------------+\n");
				}
				break;
			}
			default:
				break;
			}
			exibeLista(lista);
		} while (op != 0);
	return 0;
}