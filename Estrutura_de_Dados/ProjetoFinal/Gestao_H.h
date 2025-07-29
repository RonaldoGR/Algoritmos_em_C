#ifndef Gestao_H
#define Gestao_H

#define SUCESSO 0
#define FALHA 1
#define FALTOU_MEMORIA 2
#define FALTOU_QUANTIDADE 3



typedef struct {
	int id;
	char nome[21];
	char email[51];
	char senha[21];
} Dado;


typedef struct usuario Usuario;

struct  usuario {
	Dado dados;
	Usuario *prox;
	Usuario *ant;
};


typedef struct {
	Usuario *primeiro;
	Usuario *ultimo;
	int quantidadeDeUsuarios;
} ListaUsuarios;


typedef struct adm ADM;

struct adm {
	Dado dados;
	ADM *prox;
	ADM *ant;
};

typedef struct {
	ADM *primeiro;
	ADM *ultimo;
	int quantidadeDeAdms;
}ListaADMs;

typedef struct {
	int sku;
	char nome[31];
	char descricao[51];
	int quantidade;
}Info;

typedef struct produto Produto;

 struct produto {
	Info info;
	Produto *prox;
	Produto *ant;
};

 typedef struct {
	Produto *primeiro;
	Produto *ultimo;
	int quantidadeDeProdutos;
} ListaProdutos;

typedef struct pedido Pedido;

 struct pedido {
	int usuario_id;
	int pedido_id;
	ListaProdutos *produtos;
	Pedido *prox;
};

typedef struct {
	Pedido *primeiroPedido;
} Historico;

typedef struct {
	Pedido *primeiroPedido;
	Pedido *ultimoPedido;
} FilaPedidos;


void criaHistorico(Historico *pedidosFinalizados);
void criaFilaDePedidos(FilaPedidos *pedidosEmAndamento);
void criaListaDeProdutos(ListaProdutos *listaP);
void criaListaUsuario (ListaUsuarios *listaUsuarios);
void criaListaADMs (ListaADMs *listaAdms);

Usuario* validarUsuario(ListaUsuarios *listaUsuarios, char *nome, char *senha);
ADM* validarAdministrador(ListaADMs *listaAdms, char *nome, char *senha);

int registrarAdm(ListaADMs *listaAdms, Dado dado);
int registrarUsuario(ListaUsuarios *listaUsuarios, Dado dado);
int cadastrarProduto(ListaProdutos *listaP, Info info); 
int adicionarPedido(FilaPedidos *filaPedidos, ListaProdutos *listaP, int id);
int adicionarProduto(ListaProdutos *listaProdutoCliente, ListaProdutos *listaP, int sku);

void copiarProduto(Produto *destino, Produto *origem);
ListaProdutos* copiarListaProdutos(ListaProdutos *listaProdutosCliente);
void esvaziarListaProdutos(ListaProdutos *listaProdutosCliente);
void devolverProdutosAoEstoque(ListaProdutos *listaProdutos, ListaProdutos *listaProdutosCliente);

void inicializarSistemaZerado(ListaProdutos *listaP, ListaUsuarios *listaUsuarios, ListaADMs *listaAdms,  FilaPedidos *pedidosEmAndamento, Historico *pedidosFinalizados);
void inicializarSistemaComDados(ListaProdutos *listaP, ListaUsuarios *listaUsuarios, ListaADMs *listaAdms,  FilaPedidos *pedidosEmAndamento, Historico *pedidosFinalizados);

void visualizarUsuarios(ListaUsuarios *listaUsuarios);
void visualizarAdms(ListaADMs listaAdms);
void visualizarProdutosADM(ListaProdutos listaP);
void visualizarProdutosUsuario(ListaProdutos listaP);
void visualizarHistorico(Historico *historico, int id);
void visualizarTodosHistoricos(Historico *historico);
void visualizarPedido(FilaPedidos *pedidosUsuario, int id);
void visualizarTodosPedidos(FilaPedidos *todosPedidos);

int removerProdutoEstoque(ListaProdutos *listaP, int sku, int quantidade, Info *info);
int removerProdutoPedido(ListaProdutos *listaP, int sku, Info *info); 
int verificarPedidoUsuario(FilaPedidos *filaPedidos, int id);
int cancelarPedido(FilaPedidos *filaPedidos, int id, int numeroPedido, Pedido *pedidoCancelado);
int finalizarPedido(FilaPedidos *filaPedidos, Historico *historico, int id, int numeroPedido, Pedido *pedidoFinalizado);
int removerUsuario(ListaUsuarios *listaUsuarios, int id, Dado *dado);
int removerAdm(ListaADMs *listaAdms, int id, Dado *dado);
int removerPedidoHistorico(Historico *historico, int id, Pedido *pedidoRemovido);
int removerHistoricoUsuario(Historico *historico, int id, Historico *historicoRemovido);

int alterarDadosUsuario(ListaUsuarios *listaUsuarios, int id);
int alterarSenha(ListaUsuarios *listaUsuarios, int id);

int IdUsuarioExisteNoArquivo(int idUsuario);
int IdAdmExisteNoArquivo(int idAdm);
int skuExisteNoArquivo(int skuBuscado);
int pedidoExisteNoArquivo(int idUsuario, int idPedido);

int gravarUsuarios(ListaUsuarios *listaUsuarios);
int gravarAdministradores(ListaADMs *listaAdms);
int gravarProdutos(ListaProdutos *listaProdutos);
int gravarHistorico(Historico *historicoPedidos);

int carregarUsuarios(ListaUsuarios *listaUsuarios, Dado dadoUsuario);
int carregarAdministradores(ListaADMs *listaAdms, Dado dadoAdm);
int carregarListaDeProdutos(ListaProdutos *listaProdutos, Info info);
int carregarHistoricoPedidos(Historico *historicoPedidos);
#endif