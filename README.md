
![C](https://img.shields.io/badge/C-language-blue?logo=c)

# Exercícios Acadêmicos em C

Este repositório reúne **exercícios acadêmicos** desenvolvidos durante as disciplinas de **Lógica de Programação** e **Estrutura de Dados** com a linguagem **C**, utilizando abordagens estruturadas e recursos como `structs`, ponteiros, manipulação de arquivos e diversas estruturas de dados.

## Estrutura do Repositório

```
📁
├── Estruturas_de_Dados/
│   |── Listas/
│   │     └── ...
│   ├── Pilhas/
│   ├── Filas/
│   └── ...
├── Logica_de_Programacao/
│   └── ...
└── ProjetoFinal/
```

##  Conteúdo

### 🔷 Exercícios de Lógica de Programação

- Declarações básicas
- Controle de fluxo (`if`, `switch`, `for`, `while`)
- Vetores e matrizes
- Funções e modularização

### 🔷 Estrutura de Dados

- `structs` e ponteiros
- Revisão de funções
- Listas por contiguidade física, simplesmente e duplamente encadeadas
- Pilhas e filas por contiguidade física e simplesmente encadeadas
- Manipulação de arquivos `.txt`

---



## 🔷 Como executar os códigos

### VS Code (Linux ou WSL)
```bash
# Compile o arquivo
gcc nome_do_arquivo.c -o nome_do_programa

# Execute o programa
./nome_do_programa
```

### DevC++ (Windows)
1. Crie um novo projeto.
2. Adicione os arquivos `.c` e `.h`.
3. Compile e execute pela própria IDE.

---


## 🛒 Projeto Final: Sistema de Gestão de Pedidos e Estoque

O projeto simula o sistema de uma **loja de materiais de construção**, permitindo que usuários e administradores realizem operações de gerenciamento de produtos, pedidos e cadastros.

### 🔷 Funcionalidades

#### Para **usuários**:
- Login e alteração de senha
- Visualização e adição de produtos ao carrinho
- Criação de pedido (fila)
- Finalização de pedido (pilha de histórico)
- Cancelamento e visualização de pedidos
- Remoção de pedidos do histórico

#### Para **administradores**:
- Cadastro e remoção de produtos, usuários e administradores
- Visualização dos pedidos em andamento
- Gerenciamento do histórico de pedidos
- Gravação e carregamento de dados em arquivos `.txt`

### 🔷 Estruturas utilizadas:

- **Lista Duplamente Encadeada**  
  - Armazena: usuários, administradores e produtos
- **Fila**  
  - Controla: pedidos em andamento
- **Pilha (simplesmente encadeada)**  
  - Armazena: histórico de pedidos finalizados
- **Arquivos** (`usuarios.txt`, `produtos.txt`, `historico.txt`, `administradores.txt`)  
  - Persistência dos dados

---

## 📂 Arquivos principais do projeto final

- `mainGestao.c` — interface e controle principal
- `Gestao.c` — lógica das operações e manipulação das estruturas
- `Gestao_H.h` — definições das estruturas e protótipos
- `usuarios.txt`, `produtos.txt`, `administradores.txt`, `historico.txt` — persistência dos dados (simulação de um banco de dados)

---

## 🔷 Observações

- O projeto é modularizado com separação de cabeçalho (`.h`) e implementação (`.c`)
- Não utiliza bibliotecas externas
- Compatível com ambientes Windows/Linux
- Simula parcialmente operações CRUD com um banco de dados

---
# Autor

Ronaldo Gandra Rocha - Acadêmico no IFSUL (Instituto Federal de Educação, Ciência e Tecnologia) 
- Graduando em Tecnologia em Sistemas Para Internet