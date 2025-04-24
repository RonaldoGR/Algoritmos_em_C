#ifndef filacf_h
#define filacf_h

#define SUCESSO    0
#define FILA_VAZIA 1
#define FILA_CHEIA 2
#define DADO_INEXISTENTE 3 
#define MAX_NODOS  5

typedef struct {
	int cod;
	float peso;
} Dado;


typedef struct {
        Dado v[MAX_NODOS];
        int frente;
        int re;
        } FilaCF;

void criaFila(FilaCF *f);
int insere(FilaCF *f,Dado dado);
int retira(FilaCF *f,Dado *dado);
int estaCheia(FilaCF f);
int estaVazia(FilaCF f);
int consulta(FilaCF f);
void exibeFila(FilaCF f);
int pesquisa(FilaCF *f, int codigo);
int tamanhoFila(FilaCF *f);

#endif
