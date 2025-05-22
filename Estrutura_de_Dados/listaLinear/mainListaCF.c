/*--------------------------------
Arquivo: mainListaCF.c
----------------------------------*/

#include <stdio.h>
#include <locale.h>
#include "ListaCF.h"


int main() {
	ListaCF lista;
	Dado dado;
	int cod, nodos;
	
	setlocale(LC_ALL, "Portuguese");
	
	criaLista(&lista);
	do {
		printf("0-Fim\n");
		printf("1-Inclui no fim\n");
		printf("2-Exibe lista\n");		
		printf("3-Quantidade de nodos\n");
		printf("4-Exibe situacao da lista\n");
		printf("5-Exclui do fim\n");
		printf("6-Inclui no inicio\n");
		printf("7-Exclui do inicio\n");
		printf("8-Consulta por codigo\n");	
		printf("9-Inclui antes\n");		
		printf("10-Exclui nodo\n\n");	
		printf("Informe a operacao: ");
		scanf("%d",&cod);
		
		switch (cod)
			{
			case 1 : 
					 printf("Informe o codigo: ");
					 scanf("%d",&dado.cod);
					 printf("Informe o peso: ");
					 scanf("%f",&dado.peso);
					 if (incluiNoFim(&lista,dado)==LISTA_CHEIA)
					 	printf("ERRO: Lista Cheia!\n");
					 else
					    printf("Dados Incluidos com SUCESSO!\n");		
					 break;
			case 2 : 
					 exibe(lista);
					 break;
			case 3 :
					printf("Quantidade de nodos: %d\n", quantidadeDeNodos(&lista));
				    break;
			case 4 :
					if(estaCheia(&lista) == LISTA_CHEIA){
						printf("A lista está cheia\n");
						break;
					}
					if(estaVazia(&lista) == LISTA_VAZIA){
						printf("A lista está vazia\n");
						break;
					}
					printf("A lista possui 1 ou mais nodos\n");
					break;
			case 5 : { 
					Dado d;
					if (estaVazia(&lista) == LISTA_VAZIA) {
						printf("A lista está vazia não possui dados para remover\n");
						break;
					}
				    excluiDoFim(&lista, &d);
				    printf("\n--- Dado---\nCodigo:%d\nPeso:%.2f\nExcluído com sucesso!\n", d.cod, d.peso);
					break;
				}
			case 6 :
					printf("Informe o codigo: ");
					scanf("%d",&dado.cod);
					printf("Informe o peso: ");
					scanf("%f",&dado.peso);
					if (incluiNoInicio(&lista,dado)==LISTA_CHEIA) {
						printf("ERRO: Lista Cheia!\n");
						break;	
					}			
			 	    printf("Dados Incluidos com SUCESSO!\n");
				    break;   
			case 7 : { 
					Dado d;
					if (estaVazia(&lista) == LISTA_VAZIA) {
						printf("A lista está vazia não possui dados para remover\n");
						break;
					}
				    excluiDoInicio(&lista, &d);
				    printf("\n--- Dado---\nCodigo:%d\nPeso:%.2f\nExcluído com sucesso!\n", d.cod, d.peso);
					break;
				}
					
					break;
			case 8 : {
					int codigo;
					printf("Digite o código que deseja consultar: ");
					scanf("%d", &codigo);
					if(consultaPorCodigo(&lista, codigo) == CODIGO_INEXISTENTE){
						printf("Código não encontrado\n");
						break;
					}
				    break;
				}
			case 9 : {
						int codigo, resultado;
						printf("Digite o código que você deseja incluir antes: ");
						scanf("%d", &codigo);
						printf("Digite o dado que você deseja incluir\n");
						printf("Informe o codigo: ");
						scanf("%d",&dado.cod);
						printf("Informe o peso: ");
						scanf("%f",&dado.peso);
						resultado = incluiAntes(&lista, codigo, dado);
						if ( resultado == CODIGO_INEXISTENTE){
							printf("A lista não possui o codigo informado\n");
							break;
						}
						if (resultado == LISTA_CHEIA){
							printf("A lista está cheia e não é possível inserir mais dados\n");
							break;
						}
					break;
				   }
			case 10 : {
						Dado nodo;
						int codigo, resultado;
						printf("Digite o código que você deseja excluir: ");
						scanf("%d", &codigo);
					
						resultado = excluiNodo(&lista, codigo, &nodo);
						if ( resultado == CODIGO_INEXISTENTE){
							printf("A lista não possui o codigo informado\n");
							break;
						}
						 printf("\n--- Dado---\nCodigo:%d\nPeso:%.2f\nExcluído com sucesso!\n", nodo.cod, nodo.peso);
					   break;
					}
			}
		if (cod != 2)
			exibe(lista);

	} while (cod !=0);

	return 0;
}