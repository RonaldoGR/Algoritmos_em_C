#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Gestao_H.h"

int main (void){
	ListaUsuarios listaUsuarios;
	ListaADMs listaAdms;
	ListaProdutos listaProdutos;
	FilaPedidos filaPedidos;
	Historico historicoPedidos;
	int op1;
	int novoUsuarioRegistrado = 0;
	int novoProdutoAdicionado = 0;
	int novoAdmRegistrado = 0;
	int historicoAtualizado = 0;
	
	setlocale(LC_ALL, "Portuguese");
	
	// inicializarSistemaZerado(&listaProdutos, &listaUsuarios, &listaAdms, &filaPedidos, &historicoPedidos);
   inicializarSistemaComDados(&listaProdutos, &listaUsuarios, &listaAdms, &filaPedidos, &historicoPedidos);
    
    
    
    do {
    	printf("\n[ LOJA DE MATERIAIS DE CONSTRUÇÃO IFSUL ]\n\n");
    	printf("+-----------------  MENU -----------------+\n");
		printf("\t0 --->\t  Sair\n");
		printf("\t1 --->\t Entrar\n");
		printf("\t2 --->\t Registrar\n");
		printf("+-----------------------------------------+\n");
		printf("\n\n");
		
		printf("Digite uma operação(somente números): ");
		scanf("%d", &op1);
		while (getchar() != '\n');
		
		switch(op1){
			case 0: 
				printf("Saindo....\n");
				break;
			case 1: {
				int op2;
				int voltarMenuPrincipal = 0;
				
				do {
					printf("\n[ LOJA DE MATERIAIS DE CONSTRUÇÃO IFSUL ]\n\n");
					printf("+-----------------  MENU -----------------+\n");
					printf("\t0 --->\t  Cancelar\n");
					printf("\t1 --->\t Usuario\n");
					printf("\t2 --->\t Administrador\n");
					printf("+-----------------------------------------+\n\n\n");
					do {
						printf("Digite uma operação(somente números): ");
						scanf("%d", &op2);
					} while (op2 > 2 || op2 < 0);
					
					switch(op2){
						case 0:
							printf("Operação cancelada.\n");
							voltarMenuPrincipal = 1;
							break;
						case 1: {
							int sair = 0;
									
							Dado dado;
							Usuario *usuarioLogado;	
							do {
								printf("Digite seu nome: ");
								while (getchar() != '\n');
								fgets(dado.nome, sizeof(dado.nome), stdin);
								dado.nome[strcspn(dado.nome, "\n")] = '\0';
		
								printf("Digite sua senha: ");
								fgets(dado.senha, sizeof(dado.senha), stdin);
								dado.senha[strcspn(dado.senha, "\n")] = '\0';

								usuarioLogado = validarUsuario(&listaUsuarios, dado.nome, dado.senha);
											
								if (usuarioLogado == NULL){
									printf("Senha ou nome incorreto. Digite novamente.\n");
									printf("Deseja sair?            0 ----- Não || 1 ----- Sim\n");
									scanf("%d", &sair);
								} 					
							} while (usuarioLogado == NULL && sair == 0);
							if(sair == 1) break;
										
							printf("Login realizado com sucesso!\n\n");
											
							ListaProdutos listaProdutosCliente;
							criaListaDeProdutos(&listaProdutosCliente);
											
							int usuarioMenu;
							int pedidoNaoFinalizado = 0;
										
							do {
								printf("\n[ LOJA DE MATERIAIS DE CONSTRUÇÃO IFSUL ]\n\n");								
								printf("+-----------------  MENU -----------------+\n");
								printf("\t0 --->\t  Sair\n");
								printf("\t1 --->\t Exibir produtos\n");
								printf("\t2 --->\t Exibir pedido\n"); 
								printf("\t3 --->\t Concluir pedido\n");
								printf("\t4 --->\t Finalizar pedido\n");
								printf("\t5 --->\t Cancelar pedido\n");
								printf("\t6 --->\t Exibir histórico de pedidos\n");
								printf("\t7 --->\t Remover pedido do histórico\n");
								printf("\t8 --->\t Alterar senha\n");				
								printf("+-----------------------------------------+\n\n\n");

								do {
									printf("Digite uma operação(somente números): ");
									scanf("%d", &usuarioMenu);
									while (getchar() != '\n');
								} while (usuarioMenu > 8 || usuarioMenu < 0);
								
												
								switch(usuarioMenu){
									case 0:
										printf("Saindo...\n");
										voltarMenuPrincipal = 1;
										break;
									case 1: {
										int menuProdutos;
										if(listaProdutos.quantidadeDeProdutos == 0) {
											printf("Não há produtos cadastrados no sistema.\n");
											break;	
										}
														
										visualizarProdutosUsuario(listaProdutos);
															
										do {
											printf("[ LOJA DE MATERIAIS DE CONSTRUÇÃO IFSUL ]\n\n");	
											printf("+-----------------  MENU -----------------+\n");
											printf("\t0 --->\t  Sair\n");
											printf("\t1 --->\t Adicionar produto\n");
											printf("\t2 --->\t Remover produto do pedido\n");
											printf("+-----------------------------------------+\n\n");

											do {
												printf("Digite uma operação(somente números): ");
												scanf("%d", &menuProdutos);
												while (getchar() != '\n');
											} while (menuProdutos != 0 && menuProdutos != 1 && menuProdutos != 2);
															
															
											switch (menuProdutos) {
												case 0:
													break;
												case 1: {
													int sku;
													printf("Digite o número do produto que deseja adicionar: ");
													scanf("%d", &sku);
													while (getchar() != '\n');
																
													int adicionar = adicionarProduto(&listaProdutosCliente,&listaProdutos, sku);
																	
													if(adicionar == SUCESSO){
														printf("Produto adicionado com sucesso!\n\n"); 
														pedidoNaoFinalizado = 1;
													} else if(adicionar == FALTOU_QUANTIDADE) {
														printf("Produto indisponível no momento.\n\n");
													} else {
														printf("Produto inexistente.\nPor favor, digite um número válido.\n\n");
													}
													break;
												}
												case 2: {
													int sku;
													Info info;
													printf("Digite o número do produto que deseja remover do pedido: ");
													scanf("%d", &sku);
													while (getchar() != '\n');
													int remover = removerProdutoPedido(&listaProdutosCliente, sku, &info);
																
													if(remover == SUCESSO){
														printf("Produto removido com sucesso!\n\n");
														printf("+-------------------- PRODUTO REMOVIDO -------------------+\n\n");
														printf("+--------------------------------------------------------------------------+\n");
														printf("| Número do produto:                           %27d |\n", info.sku );
														printf("| Nome do Produto:                             %27s |\n", info.nome);
														printf("| Descrição do Produto:                       %22s |\n", info.descricao);
														printf("+---------------------------------------------------------------------------+\n\n");
														
														ListaProdutos listaTemp;
														criaListaDeProdutos(&listaTemp);
														
														Produto *produto = (Produto *) malloc(sizeof(Produto));
														if(produto == NULL) {
															printf("Não foi possível realizar a operação.\n");
															return FALHA;
														} else {
														    produto->info = info;
														    produto->prox = NULL;
														    listaTemp.primeiro = produto;
														    listaTemp.ultimo = produto;
														    listaTemp.quantidadeDeProdutos = 1;
														
														    devolverProdutosAoEstoque(&listaProdutos, &listaTemp);
														}

														break;
													}
				
													if(remover == FALHA) {
														printf("Produto inexistente.\nPor favor, digite um número válido.\n");
														break;
													}
													break;
												}
												default:
													break;	
												}														
										} while (menuProdutos != 0);
										break;
									}
									case 2:{
										visualizarPedido(&filaPedidos, usuarioLogado->dados.id);		
										break;
									}
									case 3: {
										int filaDePedido = adicionarPedido(&filaPedidos,&listaProdutosCliente, usuarioLogado->dados.id);
										if (filaDePedido == FALTOU_QUANTIDADE) {
										    printf("Não há produtos para adicionar.\n");
										} else if (filaDePedido == SUCESSO) {
											printf("Pedido confirmado! Em andamento...\n\n");
											esvaziarListaProdutos(&listaProdutosCliente);
										} else {
											printf("Servidor indisponível. Tente novamente mais tarde.\n");
										}
										break;
									}
									case 4: {
										int numeroPedido;
										Pedido *pedidoFinalizado = (Pedido* ) malloc(sizeof(Pedido));
										if(pedidoFinalizado == NULL) return FALHA;
														
										printf("Digite o número do pedido que deseja confirmar a entrega: ");
										scanf("%d", &numeroPedido);
										int finalizar = finalizarPedido(&filaPedidos, &historicoPedidos, usuarioLogado->dados.id, numeroPedido, pedidoFinalizado);
												
										if(finalizar == SUCESSO) {
											printf("Pedido concluído com sucesso!\n");
											Produto *produtoP = pedidoFinalizado->produtos->primeiro;
														
  											printf("+-------------------- DADOS DO PEDIDO -------------------+\n\n");
											printf("+--------------------------------------------------------------------------+\n");
											printf("| ID do Pedido:                                  %25d |\n", pedidoFinalizado->pedido_id);
											while(produtoP != NULL){
												printf("| Número do produto:                             %25d |\n",  produtoP->info.sku );
												printf("| Nome do Produto:                               %25s |\n", produtoP->info.nome);
												printf("| Descrição do Produto:                       %20s |\n", produtoP->info.descricao);
												produtoP = produtoP->prox;
												printf("+--------------------------------------------------------------------------+\n\n");
											}
											
											historicoAtualizado = 1;
											break;
										}	
														
										if (finalizar == FALHA) {
											printf("Não foi encontrado o pedido. Verifique o número do pedido e tente novamente.\n");
											break;
										}
													
										if(finalizar == FALTOU_QUANTIDADE) {
											printf("Não há pedido para concluir.\n");
											break;
										}
 									break;
							}	
							case 5: {
								int numeroPedido;
								Pedido pedidoCancelado;
													
								printf("Digite o número do pedido que deseja cancelar: ");
								scanf("%d", &numeroPedido);
								while (getchar() != '\n');
								int cancelar = cancelarPedido(&filaPedidos, usuarioLogado->dados.id, numeroPedido, &pedidoCancelado);
													
								if(cancelar == SUCESSO) {
									
									printf("Pedido cancelado com sucesso!\n");
									Produto *produtoP = pedidoCancelado.produtos->primeiro;
									printf("+-------------------- DADOS DO PEDIDO -------------------+\n\n");
									printf("+--------------------------------------------------------------------------------+\n");
									printf("| ID do Pedido:                                      %27d |\n", pedidoCancelado.pedido_id);
									while(produtoP != NULL){
										printf("| Número do produto:                                 %27d |\n",  produtoP->info.sku );
										printf("| Nome do Produto:                                   %27s |\n", produtoP->info.nome);
										printf("| Descrição do Produto:                             %22s |\n", produtoP->info.descricao);
										produtoP = produtoP->prox;
									}
									printf("+--------------------------------------------------------------------------------+\n\n");
									devolverProdutosAoEstoque(&listaProdutos, pedidoCancelado.produtos);
									break;
								}	
															
								if (cancelar == FALHA) {
									printf("Não foi encontrado o pedido. Verifique o número do pedido e tente novamente.\n");
									break;
								}									
								if(cancelar == FALTOU_QUANTIDADE) {
									printf("Não há pedido para cancelar.\n");
									break;
								}
								break;
							}
							case 6: {
								visualizarHistorico(&historicoPedidos, usuarioLogado->dados.id);
								break;
							}
							case 7:{
								Pedido pedidoRemovido;
								if(removerPedidoHistorico(&historicoPedidos, usuarioLogado->dados.id, &pedidoRemovido) == SUCESSO) {
								   printf("Pedido removido do histórico com sucesso!\n\n");
									Produto *produtoP = pedidoRemovido.produtos->primeiro;
															
									printf("+-------------------- DADOS DO PEDIDO -------------------+\n\n");
									printf("+--------------------------------------------------------------------------+\n");
									printf("| ID do Pedido:                                  %25d |\n", pedidoRemovido.pedido_id);
										while(produtoP != NULL){
											printf("| Número do produto:                              %24d |\n",  produtoP->info.sku );
											printf("| Nome do Produto:                                %24s |\n", produtoP->info.nome);
											printf("| Descrição do Produto:                           %17s |\n", produtoP->info.descricao);
											produtoP = produtoP->prox;
										}
									printf("+--------------------------------------------------------------------------+\n\n");
								} else {
									printf("Não foi possível remover pedido do histórico. Verifique o número do pedido e tente novamente.\n");
								}	
								break;		
							}
							case 8: {
								if (alterarSenha(&listaUsuarios, usuarioLogado->dados.id) == SUCESSO){
								   printf("Senha atualizada com sucesso!\n");
								} else {
									printf("Não foi possível alterar a senha.\nVerifique os dados e tente novamente.\n");
								}
								break;
							}
							default:
								break;
				   			}
				   			
				   		if (usuarioMenu == 0 && pedidoNaoFinalizado == 1) {
							    devolverProdutosAoEstoque(&listaProdutos, &listaProdutosCliente);
							    pedidoNaoFinalizado = 0;
							}
							
						}while (usuarioMenu != 0);
					break;
				}
			case 2: {
				int sair = 0;
							
				Dado dado;
				ADM *loginADM;
										
				do {
					printf("[ LOJA DE MATERIAIS DE CONSTRUÇÃO IFSUL ]\n\n");
					printf("Digite o nome: ");
					while (getchar() != '\n');
					fgets(dado.nome, sizeof(dado.nome), stdin);
					dado.nome[strcspn(dado.nome, "\n")] = '\0';
		
					printf("Digite sua senha: ");
					fgets(dado.senha, sizeof(dado.senha), stdin);
					dado.senha[strcspn(dado.senha, "\n")] = '\0';
	
					loginADM = validarAdministrador(&listaAdms, dado.nome, dado.senha);
										
					if (loginADM == NULL){
						printf("Senha ou nome incorreto. Digite novamente.\n");
						printf("Deseja sair ?                0 ---- Não || 1 ---- Sim\n");
						scanf("%d", &sair);
					} 
				} while (loginADM == NULL && sair == 0);
				if(sair == 1) break;
								
			printf("Login realizado com sucesso!\n\n");
			int admMenu;

			do {
				printf("\n[ LOJA DE MATERIAIS DE CONSTRUÇÃO IFSUL ]\n\n");					
				printf("+-----------------  MENU -----------------+\n");
				printf("\t0 --->\t  Sair\n"); 
				printf("\t1 --->\t Cadastrar produto\n"); 
				printf("\t2 --->\t Remover produto\n"); 
				printf("\t3 --->\t Exibir produtos\n"); 
				printf("\t4 --->\t Exibir pedidos em andamento\n"); 
				printf("\t5 --->\t Exibir pedidos de um usuário\n"); 
				printf("\t6 --->\t Exibir histórico de pedidos de um usuário\n"); 
				printf("\t7 --->\t Exibir histórico de pedidos de todos os usuários\n"); 
				printf("\t8 --->\t Exibir lista de clientes cadastrados no sistema\n");
				printf("\t9 --->\t Cadastrar cliente no sistema\n");
				printf("\t10 -->\t Remover cliente do sistema\n");
				printf("\t11 -->\t Alterar dados de um cliente no sistema\n");
				printf("\t12 -->\t Remover histórico de um cliente\n");
				printf("\t13 -->\t Registrar administrador no sistema\n");
				printf("\t14 -->\t Exibir administradores do sistema\n");
				printf("\t15 -->\t Remover administrador do sistema\n\n");					
				printf("+-------- GRAVAR DADOS NO BANCO DE DADOS ----------+\n\n");
				printf("\t16 -->\t Gravar produtos cadastrados\n");
				printf("\t17 -->\t Gravar clientes cadastrados\n");
				printf("\t18 -->\t Gravar administradores cadastrados\n");
				printf("\t19 -->\t Gravar histórico de pedidos\n");
				printf("+-----------------------------------------+\n\n\n");
			    do {
					printf("Digite uma operação(somente números): ");
					scanf("%d", &admMenu);
					while (getchar() != '\n');
					if(admMenu > 19 || admMenu < 0) {
						printf("Somente números de 0 a 19 serão aceitos.\n");
					}
				} while (admMenu > 19 || admMenu < 0); 
				
				switch(admMenu){
					case 0:
						printf("Saindo...\n");
						voltarMenuPrincipal = 1;
						break;
					case 1: {
						Info info;																								
											
						printf("Digite o nome do produto [sem espaços]: ");				
						fgets(info.nome, sizeof(info.nome), stdin);
						info.nome[strcspn(info.nome, "\n")] = '\0';
										
						printf("Digite a descrição do produto [sem espaços]: ");						
						fgets(info.descricao, sizeof(info.descricao), stdin);
						info.descricao[strcspn(info.descricao, "\n")] = '\0';
												
						printf("Digite a quantidade que deseja cadastrar do produto: ");
						scanf("%d", &info.quantidade);
											
						cadastrarProduto(&listaProdutos, info);
						printf("Produto registrado com sucesso!\n");
						novoProdutoAdicionado = 1;
						break;
					}
					case 2: {
						Info info;
						int sku, quantidade;
											
						printf("Digite o SKU do produto que deseja remover: ");
						scanf("%d", &sku);
						while (getchar() != '\n');
						printf("Digite a quantidade que deseja remover: ");
						scanf("%d", &quantidade);
						while (getchar() != '\n');
						printf("\n\n");
						if (removerProdutoEstoque(&listaProdutos, sku, quantidade, &info) == SUCESSO){
								printf("Nome do Produto: %s\n", info.nome);
								printf("Descrição do Produto: %s\n", info.descricao);
								printf("Quantidade em Estoque: %d\n", info.quantidade);	
								if(info.quantidade == 0) {
									printf("Produto removido do estoque com sucesso!\n");
								} else {
									printf("Baixa no estoque registrada!\n");
								}							
							} else {
								printf("Não foi possível realizar a operação.\nQuantidade insuficiente ou produto não encontrado.\nVerifique os dados e tente novamente.\n");
							}						
						break;
					}
					case 3: {
						visualizarProdutosADM(listaProdutos);												
						break;
					}
					case 4:{
						visualizarTodosPedidos(&filaPedidos);						
						break;
					}
					case 5: {
						int id;
						printf("Digite o ID do usuário: ");
						scanf("%d", &id);
						while (getchar() != '\n');
						visualizarPedido(&filaPedidos, id);						
						break;
					}
					case 6:{
						int id;
						printf("Digite o ID do usuário: ");
						scanf("%d", &id);
						while (getchar() != '\n');
						visualizarHistorico(&historicoPedidos, id);					
						break;
					}
					case 7:{
						visualizarTodosHistoricos(&historicoPedidos);
						break;
					}
					case 8:{
						visualizarUsuarios(&listaUsuarios);
						break;
					}
					case 9:{
						Dado dado;					
						printf("Digite seu nome [sem espaços]: ");
						fgets(dado.nome, sizeof(dado.nome), stdin);
						dado.nome[strcspn(dado.nome, "\n")] = '\0';
												
						printf("Digite seu e-mail [sem espaços]: ");
						fgets(dado.email, sizeof(dado.email), stdin);
						dado.email[strcspn(dado.email, "\n")] = '\0';
													
						printf("Digite sua senha [sem espaços]: ");
						fgets(dado.senha, sizeof(dado.senha), stdin);
						dado.senha[strcspn(dado.senha, "\n")] = '\0';
													
						if(registrarUsuario(&listaUsuarios, dado) == SUCESSO){
							printf("Usuário registrado com sucesso!\n");
							novoUsuarioRegistrado = 1;
						}													
						break;
					}
					case 10: {
						Dado dado;
						int id;
						printf("Digite o ID do cliente que deseja excluir: ");
						scanf("%d", &id);
						while (getchar() != '\n');
						if(verificarPedidoUsuario(&filaPedidos, id) == SUCESSO) {
							printf("Usuário não pode ser removido antes de finalizar um pedido.\n");
							break;
						}																	
						int clienteRemovido = removerUsuario(&listaUsuarios, id, &dado);
										
						if(clienteRemovido == FALHA) {
							printf("Número do ID não encontrado.\nVerifique os dados e tente novamente.\n");
						} else {
							printf("Cliente removido do sistema com sucesso!\n\n");
							printf("+----------- DADOS DO CLIENTE REMOVIDO --------------+\n");
							printf("+---------------------------------------------------------+\n");
							printf("| ID:                         %27d |\n", dado.id);
							printf("| Nome:                       %27s |\n", dado.nome);
							printf("| E-mail:                     %27s |\n", dado.email);
							printf("+---------------------------------------------------------+\n");
						}		
						break;
					}
					case 11: {
						int id;
						printf("Digite o ID do usuário que deseja alterar os dados cadastrais: ");
						scanf("%d", &id);
						while (getchar() != '\n');
						alterarDadosUsuario(&listaUsuarios, id);
						break;
					}
					case 12: {
						int id;
						Historico *historicoRemovido = (Historico *) malloc (sizeof(Historico));
												
						if(historicoRemovido == NULL) return FALHA;						
						printf("Digite o ID do usuário que deseja remover o histórico: ");
						scanf("%d", &id);
						while (getchar() != '\n');
						if(removerHistoricoUsuario(&historicoPedidos,id,historicoRemovido) == SUCESSO) {
							printf("Histórico removido com sucesso!\n\n");
							visualizarHistorico(historicoRemovido, id);
						} else {
							printf("Histórico não encontrado no sistema. Verifique os dados e tente novamente.\n");
						}						
						break;
					}
					case 13: {
						Dado dado;						
						printf("Digite seu nome [sem espaços]: ");
						fgets(dado.nome, sizeof(dado.nome), stdin);
						dado.nome[strcspn(dado.nome, "\n")] = '\0';
													
						printf("Digite seu e-mail [sem espaços]: ");
						fgets(dado.email, sizeof(dado.email), stdin);
						dado.email[strcspn(dado.email, "\n")] = '\0';
													
						printf("Digite sua senha [sem espaços]: ");
						fgets(dado.senha, sizeof(dado.senha), stdin);
						dado.senha[strcspn(dado.senha, "\n")] = '\0';
													
						if(registrarAdm(&listaAdms, dado) == SUCESSO){
							printf("Administrador registrado com sucesso!\n");
							novoAdmRegistrado = 1;
						}
						break;
		 			}
					case 14: {
						visualizarAdms(listaAdms);	
						break;
					}
					case 15: {
						Dado dado;
						int id;
						printf("Digite o ID do administrador que deseja excluir: ");
						scanf("%d", &id);
						while (getchar() != '\n');
												
						if(loginADM->dados.id == id) {
							printf("Não é possível remover um administrador logado.\n");
							break;
						}
												
						int admRemovido = removerAdm(&listaAdms, id, &dado);
												
						if (admRemovido == FALHA) {
						    printf("Número do ID não encontrado.\nVerifique os dados e tente novamente.\n");
						} else {
						    printf("Administrador removido do sistema com sucesso!\n\n");
						    printf("+--- DADOS DO ADMINISTRADOR REMOVIDO ---+\n");
						    printf("ID: %d\n", dado.id);
						    printf("Nome: %s\n", dado.nome);
						    printf("E-mail: %s\n", dado.email);
						}
						break;
					}
					case 16:{				
						if(listaProdutos.quantidadeDeProdutos == 0) {
							printf("Não há produtos cadastrados no sistema.\nCadastre primeiro antes de fazer a gravação na base de dados.\n");
							break;
						}
												
						if(novoProdutoAdicionado == 0) {
							printf("Nenhum novo produto adicionado. Nada para gravar.\n"); 
							break;
						}
						if (gravarProdutos(&listaProdutos) == FALHA){
							printf("Não foi possível realizar a gravação.\n");
							break;
						}
						printf("Gravação realizada com sucesso!\n");
						novoProdutoAdicionado = 0;
						break;
					}
					case 17: {
						if(listaUsuarios.quantidadeDeUsuarios == 0) {
							printf("Não há clientes cadastrados no sistema.\nCadastre primeiro antes de fazer a gravação na base de dados.\n");
							break;
						}
											
						if(novoUsuarioRegistrado == 0) {
							printf("Nenhum novo cliente adicionado. Nada para gravar.\n"); 
							break;
						}
						if (gravarUsuarios(&listaUsuarios) == FALHA){
							printf("Não foi possível realizar a gravação.\n");
							break;
						}
						printf("Gravação realizada com sucesso!\n");
						novoUsuarioRegistrado = 0;			
						break;
					}
					case 18: {													
						if(novoAdmRegistrado == 0) {
							printf("Nenhum novo administrador foi adicionado. Nada para gravar.\n"); 
							break;
						}
						if (gravarAdministradores(&listaAdms) == FALHA){
							printf("Não foi possível realizar a gravação.\n");
							break;
						}
						printf("Gravação realizada com sucesso!\n");
						novoAdmRegistrado = 0;			
						break;
					}
					case 19: {						
						if(historicoAtualizado == 0){
							printf("Nenhum novo pedido foi adicionado ao histórico. Nada para gravar.\n");
							break;
						}
												
						if (gravarHistorico(&historicoPedidos) == FALHA) {
							printf("Não foi possível realizar a gravação.\n");
							break;
						}
											
						printf("Gravação realizada com sucesso!\n");
						historicoAtualizado = 0;		
						break;	
					}
					default:
						break;	
					}
				} while (voltarMenuPrincipal == 0);
				break;
				default:
					break;
				}
			}
		} while(voltarMenuPrincipal == 0);
			break;
		}
		case 2:{
			int op3;
			int sairDoCase2 = 0;
		
			do {
				printf("\n[ LOJA DE MATERIAIS DE CONSTRUÇÃO IFSUL ]\n\n");
				printf("+-----------------  MENU -----------------+\n");
				printf("\t0 --->\t  Cancelar\n");
				printf("\t1 --->\t Registrar Usuário\n");
				printf("\t2 --->\t Registrar Administrador\n");
				printf("+-----------------------------------------+\n\n\n");
				printf("Digite uma operação: ");
				scanf("%d", &op3);
				while (getchar() != '\n');	
				switch(op3) {
				case 0:
					printf("Operação cancelada.\n");
					sairDoCase2 = 1;
					break;
				case 1: {
					Dado dado;
					printf("Digite seu nome [sem espaços]: ");
					fgets(dado.nome, sizeof(dado.nome), stdin);
					dado.nome[strcspn(dado.nome, "\n")] = '\0';
										
					printf("Digite seu e-mail [sem espaços]: ");
					fgets(dado.email, sizeof(dado.email), stdin);
					dado.email[strcspn(dado.email, "\n")] = '\0';
										
					printf("Digite sua senha [sem espaços]: ");
					fgets(dado.senha, sizeof(dado.senha), stdin);
					dado.senha[strcspn(dado.senha, "\n")] = '\0';										

					if(registrarUsuario(&listaUsuarios, dado) == SUCESSO){
						printf("Usuário registrado com sucesso!\n");
						novoUsuarioRegistrado = 1;
						sairDoCase2 = 1;
					}
					break;
				}
				case 2: {
					Dado dado;				
					printf("Digite seu nome [sem espaços]: ");
					fgets(dado.nome, sizeof(dado.nome), stdin);
					dado.nome[strcspn(dado.nome, "\n")] = '\0';
						
					printf("Digite seu e-mail [sem espaços]: ");
					fgets(dado.email, sizeof(dado.email), stdin);
					dado.email[strcspn(dado.email, "\n")] = '\0';

					printf("Digite sua senha [sem espaços]: ");
					fgets(dado.senha, sizeof(dado.senha), stdin);
					dado.senha[strcspn(dado.senha, "\n")] = '\0';
														
					if(registrarAdm(&listaAdms, dado) == SUCESSO){
						printf("Administrador registrado com sucesso!\n");
						novoAdmRegistrado = 1;
						sairDoCase2 = 1;
					} else {
						printf("Não foi possível fazer o cadastro. Verifique os dados e tente novamente.\n");
					}
					break;
				}
				default:
				   break;			
				}
			} while (sairDoCase2 == 0 && (op3 > 2 || op3 < 0));
		}
	}
  } while (op1 != 0);
return 0;
}