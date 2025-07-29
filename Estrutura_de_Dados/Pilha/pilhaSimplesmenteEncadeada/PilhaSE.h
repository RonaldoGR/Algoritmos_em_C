#ifndef PilhaSE
#define PilhaSE


#define SUCESSO 0
#define PILHA_VAZIA 1
#define FALTOU_MEMORIA 2



typedef struct {
	int cod;
	float peso;
} Dado;

typedef struct nodo Nodo;

struct nodo {
	Dado info;
	Nodo *prox;
};

typedef struct {
	Nodo *topo;
} Pilha;



void criaPilha (Pilha *p);
int empilha (Pilha *p, Dado d);
int desempilha (Pilha *p, Dado *d);
int consultaTop (Pilha *p, Dado *d);
int estaVazia (Pilha *p);
void exibe (Pilha *p);


#endif
