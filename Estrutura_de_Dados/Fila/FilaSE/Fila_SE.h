#ifndef Fila_SE
#define Fila_SE


#define SUCESSO 0
#define FILA_VAZIA 1
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
 Nodo *frente;
 Nodo *re;
} FilaSE;

void criaFila (FilaSE *fila);
int estaVazia(FilaSE *fila);
int insere(FilaSE *fila, Dado dado);
int retira(FilaSE *fila, Dado *dado);
int consultaFrente(FilaSE *fila, Dado *dado);
void exibe(FilaSE fila);





#endif