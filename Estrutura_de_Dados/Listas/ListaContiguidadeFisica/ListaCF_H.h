/*--------------------------------
* Arquivo: ListaCF.h
*/

#ifndef ListaCF_H
#define ListaCF_H

#define MAX_NODOS 5

#define SUCESSO            0
#define LISTA_VAZIA        1
#define LISTA_CHEIA        2
#define CODIGO_INEXISTENTE 3


typedef struct {
	int cod;
	float peso;
} Dado;

typedef struct {
    int n;
	Dado v[MAX_NODOS];
} ListaCF;

/*--------------------------------
*  Protótipos das funções
*/
void criaLista(ListaCF *lt);
int  incluiNoFim(ListaCF *lt, Dado d);
int incluiNoInicio(ListaCF *lt, Dado d);
int incluiAntes (ListaCF *lt, int codigo, Dado d);
void exibe(ListaCF lt);
int quantidadeDeNodos(ListaCF *lt);
int estaCheia(ListaCF *lt);
int estaVazia(ListaCF *lt);
int excluiDoInicio(ListaCF *lt, Dado *d);
int excluiDoFim(ListaCF *lt, Dado *d);
int excluiNodo(ListaCF *lt,int codigo, Dado *nodo);
int consultaPorCodigo (ListaCF *lt, int codigo);


#endif
