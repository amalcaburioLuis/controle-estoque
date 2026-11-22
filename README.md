# Controle de Estoque de uma Lojinha

Programa de console em C para controlar o estoque de uma lojinha: cadastrar produtos, registrar entradas e saídas, buscar, remover e avisar quando o estoque está baixo. Os dados ficam salvos em arquivo de texto.

> Projeto de estudo, feito por etapas. Cada etapa é um arquivo `.c` independente e vira um commit no GitHub.

## Funcionalidades

- Cadastrar produtos
- Listar produtos
- Buscar produto por código
- Entrada de estoque
- Saída de estoque (bloqueia saída maior que a quantidade disponível)
- Remover produto
- Avisar estoque baixo
- Relatórios: valor total do estoque e produtos abaixo do mínimo
- Salvar e carregar os dados em `estoque.txt`

## Estrutura de dados

```c
struct Produto {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
};
```

Os produtos ficam em um vetor de `struct Produto`, com uma variável `total` que guarda quantos estão cadastrados.

## Restrições do projeto

Meu professor ainda não passou ponteiros, então o projeto usa apenas:

- variáveis e entrada/saída
- `if` / `switch`
- laços
- funções
- vetores e strings
- `struct`
- arquivos

Nada de ponteiros (`->`) por enquanto.

## Etapas

| Etapa | Arquivo | O que faz |
|-------|---------|-----------|
| 1 | `proj01_menu.c` | Menu principal com `switch` |
| 2 | `proj02_cadastro.c` | Cadastro e listagem de produtos |
| 3 | `proj03_busca.c` | Busca por código; impede código repetido |
| 4 | `proj04_movimentacao.c` | Entrada e saída de estoque; bloqueia saída maior que o disponível |
| 5 | `proj05_remover.c` | Remover produto (fecha o buraco no vetor) |
| 6 | `proj06_relatorios.c` | Valor total e produtos abaixo do mínimo |
| 7 | `proj07_arquivo.c` | Salvar e carregar em `estoque.txt` |
| 8 | `main.c`, `produto.h`, `produto.c` | Modularização e publicação no GitHub |

## Arquitetura

Decisão de organização: só os `case` do menu viram funções (o menu em si continua na `main`). As funções vão sendo criadas conforme cada etapa avança.

Funções previstas ao longo do projeto:

- `limparEntrada`, `lerInteiro`, `lerReal`: leitura segura (letra digitada no lugar de número não trava o programa)
- `cadastrarProduto`, `listarProdutos`
- `buscarPosicao` (devolve a posição no vetor ou `-1`) e `buscarProduto`
- funções de entrada, saída e remoção de estoque
- funções de relatório
- funções de salvar e carregar arquivo

Na etapa 8, o código se divide em:

```
main.c       -> menu e fluxo do programa
produto.h    -> struct Produto e declarações das funções
produto.c    -> implementação das funções
```

## Como compilar e executar

Etapas simples (um arquivo):

```bash
gcc proj02_cadastro.c -o estoque
./estoque
```

Versão modularizada:

```bash
gcc main.c produto.c -o estoque
./estoque
```

## Organização no GitHub

- Um commit por etapa concluída
- Etapas antigas ficam na pasta `etapas/` do repositório
- Executáveis e arquivos de contexto ficam fora do repositório (`.gitignore`)

```
controle-estoque/
├── etapas/
│   ├── proj01_menu.c
│   ├── ...
├── main.c
├── produto.h
├── produto.c
├── README.md
└── .gitignore
```

## Status

Começando o projeto do zero, a partir da etapa 1.

- [X] Etapa 1: menu
- [X] Etapa 2: cadastro
- [ ] Etapa 3: busca
- [ ] Etapa 4: movimentação
- [ ] Etapa 5: remover
- [ ] Etapa 6: relatórios
- [ ] Etapa 7: arquivo
- [ ] Etapa 8: modularização e GitHub

## Ideia futura

Trocar o `estoque.txt` por um banco SQLite (`estoque.db`). Antes disso: aprender SQL básico e ponteiros.

```bash
gcc main.c produto.c -o estoque -lsqlite3
```