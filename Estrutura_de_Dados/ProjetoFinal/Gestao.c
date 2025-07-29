#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gestao_H.h"


void criaListaUsuario (ListaUsuarios *listaUsuarios) {
	listaUsuarios->primeiro = NULL;
	listaUsuarios->ultimo = NULL;
	listaUsuarios->quantidadeDeUsuarios = 0;
}

void criaListaADMs (ListaADMs *listaAdms) {
	listaAdms->primeiro = NULL;
	listaAdms->ultimo = NULL;
	listaAdms->quantidadeDeAdms = 0;
}

void criaListaDeProdutos(ListaProdutos *listaP) {
	listaP->primeiro = NULL;
	listaP->ultimo = NULL;
	listaP->quantidadeDeProdutos = 0;
}


void criaFilaDePedidos(FilaPedidos *pedidosEmAndamento) {
	pedidosEmAndamento->primeiroPedido = NULL;
	pedidosEmAndamento->ultimoPedido = NULL;
}


void criaHistorico(Historico *pedidosFinalizados) {
	pedidosFinalizados->primeiroPedido = NULL;
}


Usuario* validarUsuario(ListaUsuarios *listaUsuarios, char *nome, char *senha) {
    Usuario *aux = listaUsuarios->primeiro;

    while (aux != NULL) {
        if (strcmp(aux->dados.nome, nome) == 0 && strcmp(aux->dados.senha, senha) == 0 && aux->dados.id > 0) {
            return aux;
        }
        aux = aux->prox;
    }
	return NULL;
}



ADM* validarAdministrador(ListaADMs *listaAdms, char *nome, char *senha) {
    ADM *aux = listaAdms->primeiro;

    while (aux != NULL) {
        if (strcmp(aux->dados.nome, nome) == 0 && strcmp(aux->dados.senha, senha) == 0 && aux->dados.id > 0) {
            return aux;
        }
        aux = aux->prox;
    }
	return NULL;
}

int registrarAdm(ListaADMs *listaAdms, Dado dado) {
	ADM *novoAdm = (ADM *) malloc (sizeof(ADM));
	if (novoAdm == NULL){
		return FALTOU_MEMORIA;
	}
	
	novoAdm->dados = dado;
	novoAdm->ant = listaAdms->ultimo;
	novoAdm->prox = NULL;
	
	if (listaAdms->quantidadeDeAdms == 0) {	
		novoAdm->dados.id = 1;
		listaAdms->primeiro = novoAdm;
		listaAdms->ultimo = novoAdm;
	}else {
		novoAdm->dados.id = listaAdms->ultimo->dados.id + 1;
		listaAdms->ultimo->prox = novoAdm;
		listaAdms->ultimo = novoAdm;
	}
	
	listaAdms->quantidadeDeAdms++;
	return SUCESSO;
}

int registrarUsuario(ListaUsuarios *listaUsuarios, Dado dado) {
	Usuario *novoUsuario = (Usuario *) malloc (sizeof(Usuario));
	if (novoUsuario == NULL){
		return FALTOU_MEMORIA;
	}
	
	novoUsuario->dados = dado;
	novoUsuario->ant = listaUsuarios->ultimo;
	novoUsuario->prox = NULL;
	
	if (listaUsuarios->quantidadeDeUsuarios == 0) {	
		novoUsuario->dados.id = 1;
		listaUsuarios->primeiro = novoUsuario;
		listaUsuarios->ultimo = novoUsuario;
	}else {
		novoUsuario->dados.id = listaUsuarios->ultimo->dados.id + 1;
		listaUsuarios->ultimo->prox = novoUsuario;
		listaUsuarios->ultimo = novoUsuario;
	}
	
	listaUsuarios->quantidadeDeUsuarios++;
	return SUCESSO;
}

int cadastrarProduto(ListaProdutos *listaP, Info info) {
	Produto *novoProduto = (Produto *) malloc (sizeof(Produto));
	
	if(novoProduto == NULL) {
		return FALTOU_MEMORIA;
	}
	
	strcpy(novoProduto->info.nome, info.nome);
	strcpy(novoProduto->info.descricao, info.descricao);
	novoProduto->info.quantidade = info.quantidade;
    novoProduto->ant = listaP->ultimo;
	novoProduto->prox = NULL;
	
	if(listaP->ultimo == NULL) {
		novoProduto->info.sku = 1;
		listaP->primeiro = novoProduto;
		listaP->ultimo = novoProduto;
	} else {
		novoProduto->info.sku = listaP->ultimo->info.sku + 1;
		listaP->ultimo->prox = novoProduto;
		listaP->ultimo = novoProduto;
	}
	
	listaP->quantidadeDeProdutos++;
	return SUCESSO;
}

int adicionarPedido(FilaPedidos *filaPedidos, ListaProdutos *listaP, int id){
	Pedido *novoPedido = (Pedido *) malloc(sizeof(Pedido));
	if(novoPedido == NULL) {
		return FALTOU_MEMORIA;
	}
	
	if(listaP->quantidadeDeProdutos == 0){
		listaP = NULL;
		return FALTOU_QUANTIDADE;
	}
	
	novoPedido->produtos = copiarListaProdutos(listaP);
	novoPedido->prox = NULL;
	novoPedido->usuario_id = id;
	

		if(filaPedidos->primeiroPedido == NULL) {
			novoPedido->pedido_id = 1;
			filaPedidos->primeiroPedido = novoPedido;
			filaPedidos->ultimoPedido = novoPedido;
		} else {
			novoPedido->pedido_id = filaPedidos->ultimoPedido->pedido_id + 1;
			filaPedidos->ultimoPedido->prox = novoPedido;
			filaPedidos->ultimoPedido = novoPedido;
		}
	return SUCESSO;
}

int adicionarProduto(ListaProdutos *listaProdutoCliente, ListaProdutos *listaP, int sku){
	Produto *novoProduto = (Produto *) malloc (sizeof(Produto));
	
	if(novoProduto == NULL) {
		return FALTOU_MEMORIA;
	}
	
	if (listaP->primeiro == NULL) {
		free(novoProduto);
		return FALHA;
	}

	
	Produto *primeiroP = listaP->primeiro;
	Produto *anterior = listaP->primeiro->ant; 
	

		
	while(primeiroP != NULL) {
		if(sku == primeiroP->info.sku) {
			
			if (primeiroP->info.quantidade == 0) {
				free(novoProduto);
				return FALHA;
			}			
			
			copiarProduto(novoProduto, primeiroP);  
			 novoProduto->prox = NULL;  
			 
			if(listaProdutoCliente->quantidadeDeProdutos == 0) {
				listaProdutoCliente->primeiro = novoProduto;
				listaProdutoCliente->ultimo = novoProduto;
			}
			else {
				listaProdutoCliente->ultimo->prox = novoProduto;
				listaProdutoCliente->ultimo = novoProduto;
			}
			
			primeiroP->info.quantidade -= 1;
			
			if(primeiroP->info.quantidade == 0){
				
				if(anterior == NULL) { 
					listaP->primeiro = primeiroP->prox;
				} else {
					anterior->prox = primeiroP->prox; 
				}
				
				if(primeiroP == listaP->ultimo) {
					listaP->ultimo = anterior;
				}
				
				free(primeiroP);
			}
			
			listaProdutoCliente->quantidadeDeProdutos++;
			return SUCESSO;
		}
		
		anterior = primeiroP;
		primeiroP = primeiroP->prox;
	}
	
	free(novoProduto);
	return FALHA;

}

void copiarProduto(Produto *destino, Produto *origem) {
    destino->info.sku = origem->info.sku;
    destino->info.quantidade = 1; 
    strcpy(destino->info.nome, origem->info.nome);
    strcpy(destino->info.descricao, origem->info.descricao);
    destino->prox = NULL;
    destino->ant = NULL;
}


ListaProdutos* copiarListaProdutos(ListaProdutos *listaProdutosCliente) {
	ListaProdutos *copia = (ListaProdutos *) malloc(sizeof(ListaProdutos));
	if (copia == NULL){
		return NULL;
	}
	
	criaListaDeProdutos(copia);
	Produto *primeiroP = listaProdutosCliente->primeiro;
	
	while(primeiroP != NULL){
		Produto *novoProduto = (Produto *) malloc(sizeof(Produto));
		
		if(novoProduto == NULL){
			return NULL;
		}
		
		copiarProduto(novoProduto, primeiroP); 
		novoProduto->prox = NULL;
		novoProduto->ant = copia->ultimo;
		
		if(copia->ultimo != NULL) {
			copia->ultimo->prox = novoProduto;
			novoProduto->ant = copia->ultimo;
		} else {
			copia->primeiro = novoProduto;
			novoProduto->ant = NULL;
		}
		
		copia->ultimo = novoProduto;
		copia->quantidadeDeProdutos++;
		
		primeiroP = primeiroP->prox;
	}
	 
	return copia;
}

void esvaziarListaProdutos(ListaProdutos *listaProdutosCliente) {
	Produto *atual = listaProdutosCliente->primeiro;
    Produto *prox;

    while (atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
	
	listaProdutosCliente->primeiro = NULL;
	listaProdutosCliente->ultimo = NULL;
	listaProdutosCliente->quantidadeDeProdutos = 0;
}


void devolverProdutosAoEstoque(ListaProdutos *listaProdutos, ListaProdutos *listaProdutosCliente) {

	  Produto *primeiroP = listaProdutosCliente->primeiro;

     while (primeiroP != NULL) {
        int sku = primeiroP->info.sku;
        int encontrado = 0;

        Produto *produtoEstoque = listaProdutos->primeiro;
        
        while (produtoEstoque != NULL) {
            if (produtoEstoque->info.sku == sku) {
                produtoEstoque->info.quantidade += 1;
                encontrado = 1;
                break;
            }
            produtoEstoque = produtoEstoque->prox;
        }

 		if (encontrado == 0) {
            Produto *novoProduto = (Produto *) malloc(sizeof(Produto));
            	
            	
            
				if (novoProduto == NULL) {
					printf("Não foi possível devolver o produto número: %d. Falha no servidor.\n", primeiroP->info.sku);
					primeiroP = primeiroP->prox;
				} else {
	              copiarProduto(novoProduto, primeiroP);
		          novoProduto->info.quantidade = 1;
		          novoProduto->prox = NULL;

	               	if (listaProdutos->quantidadeDeProdutos == 0) {
		                listaProdutos->primeiro = novoProduto;
		                listaProdutos->ultimo = novoProduto;
		            } else {
		                listaProdutos->ultimo->prox = novoProduto;
		                listaProdutos->ultimo = novoProduto;
		            }

               listaProdutos->quantidadeDeProdutos++;
            }
        }

        primeiroP = primeiroP->prox;
    }

    esvaziarListaProdutos(listaProdutosCliente);
}






void inicializarSistemaZerado(ListaProdutos *listaP, ListaUsuarios *listaUsuarios, ListaADMs *listaAdms,  FilaPedidos *pedidosEmAndamento, Historico *pedidosFinalizados) {
    criaListaDeProdutos(listaP);
    criaListaUsuario(listaUsuarios);
    criaListaADMs(listaAdms);
    criaFilaDePedidos(pedidosEmAndamento);
    criaHistorico(pedidosFinalizados);
}


void inicializarSistemaComDados(ListaProdutos *listaP, ListaUsuarios *listaUsuarios, ListaADMs *listaAdms,  FilaPedidos *pedidosEmAndamento, Historico *pedidosFinalizados) {
	inicializarSistemaZerado(listaP, listaUsuarios, listaAdms, pedidosEmAndamento, pedidosFinalizados);
	
	Info info;
	Dado dadoUsuario;
	Dado dadoAdm;
	
	carregarListaDeProdutos(listaP, info);
	carregarUsuarios(listaUsuarios, dadoUsuario);
	carregarAdministradores(listaAdms, dadoAdm);
	carregarHistoricoPedidos(pedidosFinalizados);
}

void visualizarUsuarios(ListaUsuarios *listaUsuarios) {
	if(listaUsuarios->quantidadeDeUsuarios == 0) {
		printf("Não há usuários cadastrados no sistema.\n");
		return;
	}
	
	Usuario *primeiroUsuario = listaUsuarios->primeiro;
	
	
	printf("+----------------- LISTA DE CLIENTES --------------------+\n");
	while (primeiroUsuario != NULL) {
		printf("+---------------------------------------------------------+\n");
		printf("| ID:                         %27d |\n", primeiroUsuario->dados.id);
		printf("| Nome:                       %27s |\n", primeiroUsuario->dados.nome);
		printf("| E-mail:                     %27s |\n", primeiroUsuario->dados.email);
		printf("+---------------------------------------------------------+\n\n");
	    primeiroUsuario = primeiroUsuario->prox;
	} 
	printf("+---------------------------------------------------------+\n\n");
}

void visualizarAdms(ListaADMs listaAdms) {
	ADM *primeiroADM = listaAdms.primeiro;
	
	
	printf("+----------- ADMINISTRADORES DO SISTEMA --------------+\n");
	while (primeiroADM != NULL) {
		printf("+---------------------------------------------------------+\n");
		printf("| ID:                         %27d |\n", primeiroADM->dados.id);
		printf("| Nome:                       %27s |\n", primeiroADM->dados.nome);
		printf("| E-mail:                     %27s |\n", primeiroADM->dados.email);
		printf("+---------------------------------------------------------+\n");
		printf("\n");    
	    primeiroADM = primeiroADM->prox;
	} 
		printf("+---------------------------------------------------------+\n\n");
}

void visualizarProdutosADM(ListaProdutos listaP) {
	if(listaP.primeiro == NULL) {
		printf("Não há produtos cadastrados no sistema.\n");
		return;
	}
	
	Produto *primeiroProduto = listaP.primeiro;
	
	
	printf("+----------- LISTA DE PRODUTOS --------------+\n\n");
	while (primeiroProduto != NULL) {

	printf("+---------------------------------------------------------+\n");
	printf("| Produto Atual:              %27d |\n", primeiroProduto);
	printf("| SKU:                        %27d |\n", primeiroProduto->info.sku);
	printf("| Nome:                       %27s |\n", primeiroProduto->info.nome);
	printf("| Descrição:                 %22s |\n", primeiroProduto->info.descricao);
	printf("| Quantidade em estoque:      %27d |\n", primeiroProduto->info.quantidade);
	printf("| Produto anterior:           %27d |\n", primeiroProduto->ant);
	printf("| Próximo produto:            %27d |\n", primeiroProduto->prox);
	printf("+---------------------------------------------------------+\n");
		    
	    primeiroProduto = primeiroProduto->prox;
	} 
	printf("+---------------------------------------------------------+\n");
}

void visualizarProdutosUsuario(ListaProdutos listaP) {
	if(listaP.primeiro == NULL) {
		printf("Não há produtos cadastrados no sistema.\n");
		return;
	}
	
	Produto *primeiroProduto = listaP.primeiro;
	
	
	printf("+-------------------- LISTA DE PRODUTOS ----------------------+\n");
	while (primeiroProduto != NULL) {
		printf("+-----------------------------------------------------------+\n");
		printf("| Número do produto:            %27d |\n", primeiroProduto->info.sku);
	    printf("| Nome:                         %27s |\n", primeiroProduto->info.nome);
	    printf("| Descrição:                   %22s |\n", primeiroProduto->info.descricao);
		printf("+-----------------------------------------------------------+\n\n");   
	    primeiroProduto = primeiroProduto->prox;
	} 
	printf("+---------------------------------------------------------+\n\n");
}

void visualizarHistorico(Historico *historico, int id) {
	if(historico->primeiroPedido == NULL) {
		printf("Não há nenhum histórico registrado.\n");
		return;
	}
	
	int contador = 1;
	int encontrado = 0;
	Pedido *primeiroP = historico->primeiroPedido;	
	
	printf("+-------------- HISTÓRICO DE PEDIDOS --------------+\n\n");	
	
	while (primeiroP != NULL ) {
		if (id == primeiroP->usuario_id) {
			encontrado = 1;
			Produto *produtoP = primeiroP->produtos->primeiro;
			printf("+-- %dº PEDIDO --+\n", contador);
			printf("+---------------------------------------------------------+\n");
			printf("| ID do Pedido:               %27d |\n", primeiroP->pedido_id);
			while(produtoP != NULL){			
				printf("| Número do produto:          %27d |\n", produtoP->info.sku);
	    		printf("| Nome:                       %27s |\n", produtoP->info.nome);
	    		printf("| Descrição:                 %22s |\n", produtoP->info.descricao);
				produtoP = produtoP->prox;
			}
			printf("+---------------------------------------------------------+\n\n");
			contador++;
		}	
		primeiroP = primeiroP->prox;
	}
	if(encontrado == 0) {
			printf("Usuário não foi encontrado. Verifique o ID do usuário e tente novamente.\n");
	}
}

void visualizarTodosHistoricos(Historico *historico) {
	if(historico->primeiroPedido == NULL) {
		printf("Não há nenhum histórico registrado.\n");
		return;
	}
	
	int contador = 1;
	Pedido *primeiroH = historico->primeiroPedido;
		
	printf("+------- HISTÓRICO DE PEDIDOS -------+\n\n");
	
	while(primeiroH != NULL) {
		printf("+-- %dº PEDIDO --+\n", contador);
		printf("+-----------------------------------------------------------+\n");
		printf("| ID do Cliente:                %27d |\n", primeiroH->usuario_id);
		printf("| Número do pedido:             %27d |\n", primeiroH->pedido_id);
		Produto *produtoP = primeiroH->produtos->primeiro;
			while(produtoP != NULL){
				printf("| Número do produto:            %27d |\n", produtoP->info.sku);
	    		printf("| Nome:                         %27s |\n", produtoP->info.nome);
	    		printf("| Descrição:                   %22s |\n", produtoP->info.descricao);
				produtoP = produtoP->prox;
			}
		printf("+-----------------------------------------------------------+\n\n");
		contador++;
		primeiroH = primeiroH->prox;
	}	
}

void visualizarPedido(FilaPedidos *pedidosUsuario, int id){
	if(pedidosUsuario->primeiroPedido == NULL){
		printf("Usuário ou número de pedido não encontrado.\nVerifique as informações e tente novamente.\n");
		return;
	}

	Pedido *primeiroP = pedidosUsuario->primeiroPedido;
	Produto *produtoP = pedidosUsuario->primeiroPedido->produtos->primeiro;
		
	printf("+------------ PEDIDO EM ANDAMENTO -------------+\n\n");
	
	while(primeiroP != NULL) {

		 if(id == primeiroP->usuario_id ) {
		 	
		 	if(produtoP == NULL){
				printf("Usuário não possui produtos adicionados no pedido.\nAdicione produtos no carrinho para continuar.\n");
				return;
			}
		 	
		 	printf("+---------------------------------------------------------+\n");
			printf("| Número do Pedido:           %27d |\n", primeiroP->pedido_id);
				while(produtoP != NULL){
					printf("| Número do produto:          %27d |\n", produtoP->info.sku);
	    			printf("| Nome:                       %27s |\n", produtoP->info.nome);
	    			printf("| Descrição:                 %22s |\n", produtoP->info.descricao);
					produtoP = produtoP->prox;
				}
			printf("+---------------------------------------------------------+\n\n");
		 }
		primeiroP = primeiroP->prox;
	}
}

void visualizarTodosPedidos(FilaPedidos *todosPedidos){
	if(todosPedidos->primeiroPedido == NULL){
		printf("Não há pedidos em andamento no sistema.\n");
		return;
	}
	
	Pedido *primeiroP = todosPedidos->primeiroPedido;

	printf("+------------ PEDIDO EM ANDAMENTO -------------+\n\n");
	while(primeiroP != NULL) {
		printf("+-----------------------------------------------------------+\n");
		printf("| ID do usuário:                %27d |\n", primeiroP->usuario_id);
		printf("| Número do Pedido:             %27d |\n", primeiroP->pedido_id);
		Produto *produtoP = primeiroP->produtos->primeiro;
			while(produtoP != NULL){
				printf("| Número do produto:            %27d |\n", produtoP->info.sku);
	    		printf("| Nome:                         %27s |\n", produtoP->info.nome);
	    		printf("| Descrição:                   %22s |\n", produtoP->info.descricao);
				produtoP = produtoP->prox;
			}
		printf("+-----------------------------------------------------------+\n\n");
		primeiroP = primeiroP->prox;
	}
}

 int removerProdutoEstoque(ListaProdutos *listaP, int sku, int quantidade, Info *info) {
	if(listaP->quantidadeDeProdutos == 0){
		return FALHA;
	}
	
	Produto *produtoAux;
	
	
	if(listaP->primeiro->info.sku == sku) {
		
		strcpy(info->descricao, listaP->primeiro->info.descricao);
		strcpy(info->nome, listaP->primeiro->info.nome);
		
		if (listaP->primeiro->info.quantidade < quantidade) {
			return FALHA;
		}
		
		if (listaP->primeiro->info.quantidade - quantidade > 0){
			listaP->primeiro->info.quantidade -= quantidade;
			info->quantidade = listaP->primeiro->info.quantidade;
			return SUCESSO;
		} else {
			listaP->primeiro->info.quantidade -= quantidade;
			info->quantidade = listaP->primeiro->info.quantidade;
		}
	
	    produtoAux = listaP->primeiro;    

		listaP->primeiro = listaP->primeiro->prox;	
		
		if(listaP->quantidadeDeProdutos == 1) {
			listaP->ultimo = NULL;
		} else {
			listaP->primeiro->ant = NULL;
		}
		listaP->quantidadeDeProdutos--;
		free(produtoAux);
		return SUCESSO;
	}
	
	
	if(listaP->ultimo->info.sku == sku){
		
		strcpy(info->descricao, listaP->ultimo->info.descricao);
		strcpy(info->nome, listaP->ultimo->info.nome);
		
		if (listaP->ultimo->info.quantidade < quantidade) {
			return FALHA;
		}
		
		if (listaP->ultimo->info.quantidade - quantidade > 0){
			listaP->ultimo->info.quantidade -= quantidade;
			info->quantidade = listaP->ultimo->info.quantidade;
			return SUCESSO;
		} else {
			listaP->ultimo->info.quantidade -= quantidade;
			info->quantidade = listaP->ultimo->info.quantidade;
		}
	
		produtoAux = listaP->ultimo;
		
		if(listaP->quantidadeDeProdutos == 1) {
			listaP->primeiro = listaP->primeiro->prox;
			listaP->ultimo = listaP->ultimo->prox;
		} else {
			listaP->ultimo = listaP->ultimo->ant;
			listaP->ultimo->prox = NULL;
		}
		
		listaP->quantidadeDeProdutos--;
		free(produtoAux);
		return SUCESSO;
	}
	
	Produto *produtoAtual = listaP->primeiro;
	Produto *produtoAnterior = listaP->primeiro->ant;
	
	while (produtoAtual != NULL) {
		if (produtoAtual->info.sku == sku) {
			if (produtoAtual->info.quantidade < quantidade) {
				return FALHA;
			}
		
			strcpy(info->nome, produtoAtual->info.nome);
			strcpy(info->descricao, produtoAtual->info.descricao);
			
			if (produtoAtual->info.quantidade - quantidade > 0){
				produtoAtual->info.quantidade -= quantidade;
				info->quantidade = produtoAtual->info.quantidade;
				return SUCESSO;
			}else {
				produtoAtual->info.quantidade -= quantidade;
				info->quantidade = produtoAtual->info.quantidade;
			}
			
			produtoAnterior->prox = produtoAtual->prox;
			listaP->quantidadeDeProdutos--;
			free(produtoAtual);
			return SUCESSO;
		}
		produtoAnterior = produtoAtual;
		produtoAtual = produtoAtual->prox;
	}
	return FALHA;
} 


int removerProdutoPedido(ListaProdutos *listaP, int sku, Info *info) {
	if(listaP->quantidadeDeProdutos == 0){
		return FALHA;
	}
	
	Produto *produtoAux;
	
	
	if(listaP->primeiro->info.sku == sku ) {
		*info = listaP->primeiro->info;
	    produtoAux = listaP->primeiro;
		listaP->primeiro = listaP->primeiro->prox;	
		
		if(listaP->quantidadeDeProdutos == 1) {
			listaP->ultimo = NULL;
		} else {
			listaP->primeiro->ant = NULL;
		}
		listaP->quantidadeDeProdutos--;
		free(produtoAux);
		return SUCESSO;
	}
	
	
	if(listaP->ultimo->info.sku == sku ){
		*info = listaP->ultimo->info;
		produtoAux = listaP->ultimo;
		
		if(listaP->quantidadeDeProdutos == 1) {
			listaP->primeiro = listaP->primeiro->prox;
			listaP->ultimo = listaP->ultimo->prox;
		} else {
			listaP->ultimo = listaP->ultimo->ant;
			listaP->ultimo->prox = NULL;
		}
		listaP->quantidadeDeProdutos--;
		free(produtoAux);
		return SUCESSO;
	}
	
	Produto *produtoAtual = listaP->primeiro;
	Produto *produtoAnterior = listaP->primeiro->ant;
	
	while (produtoAtual != NULL) {
		if (produtoAtual->info.sku == sku) {
			*info = produtoAtual->info;
			produtoAnterior->prox = produtoAtual->prox;
			listaP->quantidadeDeProdutos--;
			free(produtoAtual);
			return SUCESSO;
		}
		produtoAnterior = produtoAtual;
		produtoAtual = produtoAtual->prox;
	}
	
	return FALHA;
} 

int verificarPedidoUsuario(FilaPedidos *filaPedidos, int id) {
	Pedido *pedidoAux = filaPedidos->primeiroPedido;
	while(pedidoAux != NULL) {
		if(pedidoAux->usuario_id == id) {
			return SUCESSO;
		}
		pedidoAux = pedidoAux->prox;
	}
	return FALHA;
}

int cancelarPedido(FilaPedidos *filaPedidos, int id, int numeroPedido, Pedido *pedidoCancelado){ 
	if(filaPedidos->primeiroPedido == NULL) {
		return FALTOU_QUANTIDADE;
	}
	
	Pedido *pedidoAtual = filaPedidos->primeiroPedido;
	Pedido *pedidoAnterior = NULL;
	
	while(pedidoAtual != NULL) {
		if(pedidoAtual->usuario_id == id && pedidoAtual->pedido_id == numeroPedido) {
		pedidoCancelado->pedido_id = pedidoAtual->pedido_id;
		pedidoCancelado->usuario_id = pedidoAtual->usuario_id;
		pedidoCancelado->produtos = copiarListaProdutos(pedidoAtual->produtos);
		pedidoCancelado->prox = NULL; // já que ele vai entrar na pilha

			if(pedidoAnterior == NULL) {
				filaPedidos->primeiroPedido = pedidoAtual->prox;
			} else {
				pedidoAnterior->prox = pedidoAtual->prox;
			}
			pedidoAtual->produtos = NULL;
			free(pedidoAtual);
			return SUCESSO;
		}

		pedidoAnterior = pedidoAtual;
		pedidoAtual = pedidoAtual->prox;
	}
	return FALHA;
}

int finalizarPedido(FilaPedidos *filaPedidos, Historico *historico, int id, int numeroPedido, Pedido *pedidoFinalizado) {
	
	if(filaPedidos->primeiroPedido == NULL) {
		return FALTOU_QUANTIDADE;
	}
	
	if(cancelarPedido(filaPedidos, id, numeroPedido, pedidoFinalizado) == FALHA) {
		return FALHA;
	}
	
	pedidoFinalizado->prox = historico->primeiroPedido;
	historico->primeiroPedido = pedidoFinalizado;
	return SUCESSO;
}

int removerUsuario(ListaUsuarios *listaUsuarios, int id, Dado *dado) {
		
	if(listaUsuarios->quantidadeDeUsuarios == 0){
		return FALHA;
	}
	
	Usuario *aux;
		
	if(listaUsuarios->primeiro->dados.id == id) {
		*dado = listaUsuarios->primeiro->dados;
	    aux = listaUsuarios->primeiro;
		listaUsuarios->primeiro = listaUsuarios->primeiro->prox;	
		
		if(listaUsuarios->quantidadeDeUsuarios == 1) {
			listaUsuarios->ultimo = NULL;
		} else {
			listaUsuarios->primeiro->ant = NULL;
		}
		listaUsuarios->quantidadeDeUsuarios--;
		free(aux);
		return SUCESSO;
	}	
		
	if(listaUsuarios->ultimo->dados.id == id ){
		*dado = listaUsuarios->ultimo->dados;
		aux = listaUsuarios->ultimo;
		
		if(listaUsuarios->quantidadeDeUsuarios == 1) {
			listaUsuarios->primeiro = listaUsuarios->primeiro->prox;
			listaUsuarios->ultimo = listaUsuarios->ultimo->prox;
		} else {
			listaUsuarios->ultimo = listaUsuarios->ultimo->ant;
			listaUsuarios->ultimo->prox = NULL;
		}
		listaUsuarios->quantidadeDeUsuarios--;
		free(aux);
		return SUCESSO;
	}	
				
	aux = listaUsuarios->primeiro;	
	Usuario *ant = NULL;
	
	while (aux != NULL) {
		if(aux->dados.id == id) {
			*dado = aux->dados;
			if(listaUsuarios->quantidadeDeUsuarios == 1) {
				listaUsuarios->primeiro = NULL;
				listaUsuarios->ultimo = NULL;
			} else {
				ant->prox = aux->prox;
				ant->prox->ant = ant;
			}
			listaUsuarios->quantidadeDeUsuarios--;
			free(aux);
			return SUCESSO;
		}
		ant = aux;
		aux = aux->prox;
	}
	return FALHA;
}

int removerAdm(ListaADMs *listaAdms, int id, Dado *dado) {
	
	if (listaAdms->quantidadeDeAdms == 0) {
    	return FALHA;
	}
	
	ADM *aux;
	
	if (listaAdms->primeiro->dados.id == id) {
	    *dado = listaAdms->primeiro->dados;
	    aux = listaAdms->primeiro;
	    listaAdms->primeiro = listaAdms->primeiro->prox;
	
	    if (listaAdms->quantidadeDeAdms == 1) {
	        listaAdms->ultimo = NULL;
	    } else {
	        listaAdms->primeiro->ant = NULL;
	    }
	
	    listaAdms->quantidadeDeAdms--;
	    free(aux);
	    return SUCESSO;
	}
	
	if (listaAdms->ultimo->dados.id == id) {
	    *dado = listaAdms->ultimo->dados;
	    aux = listaAdms->ultimo;
	
	    if (listaAdms->quantidadeDeAdms == 1) {
	        listaAdms->primeiro = NULL;
	        listaAdms->ultimo = NULL;
	    } else {
	        listaAdms->ultimo = listaAdms->ultimo->ant;
	        listaAdms->ultimo->prox = NULL;
	    }
	
	    listaAdms->quantidadeDeAdms--;
		    free(aux);
		    return SUCESSO;
		}
	
		aux = listaAdms->primeiro;
		ADM *ant = NULL;
	
		while (aux != NULL) {
		    if (aux->dados.id == id) {
		        *dado = aux->dados;
		
		        if (listaAdms->quantidadeDeAdms == 1) {
		            listaAdms->primeiro = NULL;
		            listaAdms->ultimo = NULL;
		        } else {
		            ant->prox = aux->prox;
		            if (aux->prox != NULL) {
		                aux->prox->ant = ant;
		            }
		        }
		
		        listaAdms->quantidadeDeAdms--;
		        free(aux);
		        return SUCESSO;
		    }
		
		    ant = aux;
		    aux = aux->prox;
		}	
	return FALHA;
}

int removerPedidoHistorico(Historico *historico, int id, Pedido *pedidoRemovido) {
	if(historico->primeiroPedido == NULL) {
		return FALHA;
	}
		
	Pedido *aux = historico->primeiroPedido;
	Pedido *ant = NULL;
	int pedidoEncontrado = 0;
	while(aux != NULL) {
		if(aux->usuario_id == id) {
			pedidoEncontrado = 1;
			if(ant == NULL) {
				historico->primeiroPedido = aux->prox;
			} else {
				ant->prox = aux->prox;
			}
			*pedidoRemovido = *aux;
			Pedido *removido = aux;
			aux = aux->prox;
			free(removido);
			return SUCESSO;
		} else {
			ant = aux;
			aux = aux->prox;
		}
	
	}
	if(pedidoEncontrado == 1) return SUCESSO;
	return FALHA;
}

int removerHistoricoUsuario(Historico *historico, int id, Historico *historicoRemovido) {
	if(historico->primeiroPedido == NULL) {
		return FALHA;
	}
		
	Pedido *aux = historico->primeiroPedido;
	Pedido *ant = NULL;

	int historicoEncontrado = 0;
	
	while(aux != NULL) {
		if(aux->usuario_id == id) {
			historicoEncontrado = 1;
			
			Pedido *pedidoRemovido = (Pedido*) malloc(sizeof(Pedido));
			
			if(pedidoRemovido == NULL) {
				return FALHA;
			}
			*pedidoRemovido = *aux;
			pedidoRemovido->produtos = copiarListaProdutos(aux->produtos);
			pedidoRemovido->prox = historicoRemovido->primeiroPedido;
			historicoRemovido->primeiroPedido = pedidoRemovido; 
			
			if(ant == NULL) {
				historico->primeiroPedido = aux->prox;
			} else {
				ant->prox = aux->prox;
			}
			
			
			Pedido *removido = aux;
			aux = aux->prox;
			free(removido);
			
		} else {
			ant = aux;
			aux = aux->prox;
		}
	}
	if(historicoEncontrado == 1) return SUCESSO;
	
	return FALHA;
}

int alterarDadosUsuario(ListaUsuarios *listaUsuarios, int id) {
	if(listaUsuarios->primeiro == NULL) {
		printf("Não há usuários cadastrados no sistema.\n");
		return FALHA;
	}
	
	Usuario *aux = listaUsuarios->primeiro;
	
	while (aux != NULL) {
		if(aux->dados.id == id) {
			int alterar;
			
			do {
				printf("+-- ALTERAR DADOS DO USUÁRIO --+\n");
				printf("\t0 --->\t  Sair\n");
				printf("\t1 --->\t Alterar o Nome\n");
				printf("\t2 --->\t Alterar o E-mail\n");
				printf("\t3 --->\t Alterar a senha\n");
				printf("Digite qual campo do usuário deseja alterar: ");
				scanf("%d", &alterar);
				while (getchar() != '\n');
				switch(alterar) {
					case 0: {
						printf("Saindo...\n");
						break;
					}
					case 1: {
						char nome[21];
						printf("Digite o novo nome: ");
						
						fgets(nome, sizeof(nome), stdin);
						nome[strcspn(nome, "\n")] = '\0';
						strcpy(aux->dados.nome, nome);		
						break;
					}
					case 2: {
						char email[51];
						printf("Digite o novo e-mail: ");
						fgets(email, sizeof(email), stdin);
						email[strcspn(email, "\n")] = '\0';
						strcpy(aux->dados.email, email);																						
						break;
					}
					case 3: {
						char senha[21];
						printf("Digite a nova senha: ");
						fgets(senha, sizeof(senha), stdin);
						senha[strcspn(senha, "\n")] = '\0';
						strcpy(aux->dados.senha, senha);	
						break;
					}
				}					
			} while (alterar != 0);
			return SUCESSO;
		}
		aux = aux->prox;
	} 	
	return FALHA;
}

int alterarSenha(ListaUsuarios *listaUsuarios, int id) {
	if(listaUsuarios->primeiro == NULL) {
		return FALHA;
	}
	
	Usuario *aux = listaUsuarios->primeiro;
	while (aux != NULL) {
		if(aux->dados.id == id) {
			char senha[21], senhaConfirmada[21];
			
			printf("Digite a nova senha: ");
			fgets(senha, sizeof(senha), stdin);
			senha[strcspn(senha, "\n")] = '\0';
			
			printf("Confirme a nova senha: ");
			fgets(senhaConfirmada, sizeof(senhaConfirmada), stdin);
			senhaConfirmada[strcspn(senhaConfirmada, "\n")] = '\0';
			
			if (strcmp(senha, senhaConfirmada) == 0) {
			    strcpy(aux->dados.senha, senha);
			    return SUCESSO;
			} else {
			    printf("As senhas não são iguais.\n");
			    return FALHA;
			}
		}
		aux = aux->prox;
	}					
	return FALHA;	
}

int IdUsuarioExisteNoArquivo(int idUsuario) {
	FILE *arquivo = fopen("usuarios.txt", "r");
	if (arquivo == NULL) {
		return FALHA;
	}

	Dado dadoUsuario;

	while (fscanf(arquivo, " %d %s %s %s", &dadoUsuario.id, dadoUsuario.nome, dadoUsuario.email, dadoUsuario.senha) != EOF) {
		if (dadoUsuario.id == idUsuario) {
			fclose(arquivo);
			return SUCESSO;
		}
	}
	fclose(arquivo);
	return FALHA;
}

int IdAdmExisteNoArquivo(int idAdm) {
	FILE *arquivo = fopen("administradores.txt", "r");
	if (arquivo == NULL) {
		return FALHA;
	}

	Dado dadoAdm;

	while (fscanf(arquivo, " %d %s %s %s", &dadoAdm.id, dadoAdm.nome, dadoAdm.email, dadoAdm.senha) != EOF) {
		if (dadoAdm.id == idAdm) {
			fclose(arquivo);
			return SUCESSO;
		}
	}
	fclose(arquivo);
	return FALHA;
}

int skuExisteNoArquivo(int skuBuscado) {
	FILE *arquivo = fopen ("produtos.txt","r" );
	if ( arquivo == NULL ){
		return FALHA;
	}
	
	Info info;
	
	while ( fscanf (arquivo," %d %s %s %d", &info.sku, info.nome, info.descricao, &info.quantidade) != EOF) {
			if(info.sku == skuBuscado) {
				fclose (arquivo);
				return SUCESSO;
			}
	}
	fclose (arquivo);
	return FALHA;
}

int pedidoExisteNoArquivo(int idUsuario, int idPedido) {
	FILE *arquivo = fopen("historico.txt", "r");
	if (arquivo == NULL) {
		return FALHA;
	}

	int u_id, p_id;
	while (fscanf(arquivo, " %d %d", &u_id, &p_id) != EOF) {
		if (u_id == idUsuario && p_id == idPedido) {
			fclose(arquivo);
			return SUCESSO;
		}
	}
	fclose(arquivo);
	return FALHA;
}

int gravarUsuarios(ListaUsuarios *listaUsuarios) {
	int i;
	FILE *arquivo = fopen("usuarios.txt", "a");
	Usuario *aux;
	if (arquivo == NULL) {
		return FALHA;
	}

	aux = listaUsuarios->primeiro;
	for (i = 0; i < listaUsuarios->quantidadeDeUsuarios; i++) {
		if (IdUsuarioExisteNoArquivo(aux->dados.id) == FALHA) {
			fprintf(arquivo, " %d %s %s %s", aux->dados.id, aux->dados.nome, aux->dados.email, aux->dados.senha);
		}
		aux = aux->prox;
	}
	fclose(arquivo);
	return SUCESSO;
}

int gravarAdministradores(ListaADMs *listaAdms) {
	int i;
	FILE *arquivo = fopen("administradores.txt", "a");
	ADM *aux;
	if (arquivo == NULL) {
		return FALHA;
	}

	aux = listaAdms->primeiro;
	for (i = 0; i < listaAdms->quantidadeDeAdms; i++) {
		if (IdAdmExisteNoArquivo(aux->dados.id) == FALHA) {
			fprintf(arquivo, " %d %s %s %s", aux->dados.id, aux->dados.nome, aux->dados.email, aux->dados.senha);
		}
		aux = aux->prox;
	}
	fclose(arquivo);
	return SUCESSO;
}


int gravarProdutos(ListaProdutos *listaProdutos) {
	int i;
	FILE *arquivo = fopen ("produtos.txt","a" );
	Produto *aux;
	if (arquivo == NULL) {
		return FALHA;
	}

	aux = listaProdutos->primeiro;
	for (i = 0; i < listaProdutos->quantidadeDeProdutos; i++ ) {
		if(skuExisteNoArquivo(aux->info.sku) == FALHA) {
			fprintf (arquivo," %d %s %s %d", aux->info.sku, aux->info.nome, aux->info.descricao, aux->info.quantidade);
		}
		
		aux = aux->prox;
	}
	fclose (arquivo);
	return SUCESSO;
}

int gravarHistorico(Historico *historicoPedidos) {
	FILE *arquivo = fopen("historico.txt", "a");
	Pedido *aux;

	if (arquivo == NULL) {
		return FALHA;
	}

	aux = historicoPedidos->primeiroPedido;
	while (aux != NULL) {
		if (pedidoExisteNoArquivo(aux->usuario_id, aux->pedido_id) == FALHA) {
			fprintf(arquivo, " %d %d %d", aux->usuario_id, aux->pedido_id, aux->produtos->quantidadeDeProdutos);

			Produto *p = aux->produtos->primeiro;
			while (p != NULL) {
				fprintf(arquivo, " %d %s %s", p->info.sku, p->info.nome, p->info.descricao);
				p = p->prox;
			}
			fprintf(arquivo, "\n"); 
		}
		aux = aux->prox;
	}
	fclose(arquivo);
	return SUCESSO;
}

int carregarUsuarios(ListaUsuarios *listaUsuarios, Dado dadoUsuario){
	FILE *arquivo = fopen("usuarios.txt", "r");
	if (arquivo == NULL) {
		return FALHA;
	}

	while (fscanf(arquivo, " %d %s %s %s", &dadoUsuario.id, dadoUsuario.nome, dadoUsuario.email, dadoUsuario.senha) != EOF) {
		registrarUsuario(listaUsuarios, dadoUsuario);
	}

	fclose(arquivo);
	return SUCESSO;
}

int carregarAdministradores(ListaADMs *listaAdms, Dado dadoAdm){
	FILE *arquivo = fopen("administradores.txt", "r");
	if (arquivo == NULL) {
		return FALHA;
	}

	while (fscanf(arquivo, " %d %s %s %s", &dadoAdm.id, dadoAdm.nome, dadoAdm.email, dadoAdm.senha) != EOF) {
		registrarAdm(listaAdms, dadoAdm);
	}

	fclose(arquivo);
	return SUCESSO;
}

int carregarListaDeProdutos(ListaProdutos *listaProdutos, Info info){
	FILE *arquivo = fopen ("produtos.txt","r" );
	if ( arquivo == NULL ){
		return FALHA;
	}
	
	
	while ( fscanf (arquivo," %d %s %s %d", &info.sku, info.nome, info.descricao, &info.quantidade) != EOF) {
			cadastrarProduto(listaProdutos, info);
	}
	fclose (arquivo);
	return SUCESSO;
	
}

int carregarHistoricoPedidos(Historico *historicoPedidos){
	int i, usuario_id, pedido_id, qtdProdutos;

	FILE *arquivo = fopen("historico.txt", "r");
	if (arquivo == NULL) {
		return FALHA;
	}

	while (fscanf(arquivo, " %d %d %d", &usuario_id, &pedido_id, &qtdProdutos) != EOF) {
		Pedido *novoPedido = (Pedido *) malloc(sizeof(Pedido));
		if (novoPedido == NULL) {
			fclose(arquivo);
			return FALTOU_MEMORIA;
		}

		novoPedido->usuario_id = usuario_id;
		novoPedido->pedido_id = pedido_id;
		
		novoPedido->produtos = (ListaProdutos *) malloc(sizeof(ListaProdutos));
		if (novoPedido->produtos == NULL) {
			free(novoPedido);
			fclose(arquivo);
			return FALTOU_MEMORIA;
		}
		
		criaListaDeProdutos(novoPedido->produtos);

		for (i = 0; i < qtdProdutos; i++) {
			Produto *p = (Produto *) malloc(sizeof(Produto));
			if (p == NULL) {
				fclose(arquivo);
				return FALTOU_MEMORIA;
			}
			
			fscanf(arquivo, " %d %s %s", &p->info.sku, p->info.nome, p->info.descricao);
			p->info.quantidade = 1;
			p->prox = NULL;
			p->ant = novoPedido->produtos->ultimo;

			if (novoPedido->produtos->ultimo != NULL) {
				novoPedido->produtos->ultimo->prox = p;
			} else {
				novoPedido->produtos->primeiro = p;
			}
			novoPedido->produtos->ultimo = p;
			novoPedido->produtos->quantidadeDeProdutos++;
		}

		novoPedido->prox = historicoPedidos->primeiroPedido;
		historicoPedidos->primeiroPedido = novoPedido;
	}

	fclose(arquivo);
	return SUCESSO;
}