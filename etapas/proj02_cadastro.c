#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_PRODUTOS 100 // capacidade máxima do estoque
#define TAM_NOME 50      // tamanho do nome do produto

struct Produto {
    int codigo;
    char nome[TAM_NOME];
    float preco;
    int quantidade;
};

void limparEntrada(void);
int cadastrarProduto(struct Produto estoque[], int total);
void listarProdutos(struct Produto estoque[], int total);

int main() {
    setlocale(LC_ALL, "Portuguese");
    struct Produto estoque[MAX_PRODUTOS];
    int totalProdutos = 0;
    int opcaoMenu = 0;

    do {
        printf("\n--- Menu ---\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar por código\n");
        printf("4 - Entrada/Saída de estoque\n");
        printf("5 - Remover produto\n");
        printf("6 - Estoque baixo\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        if (scanf("%d", &opcaoMenu) != 1) {
            limparEntrada();
            opcaoMenu = -1; // força cair no default
        }

        switch (opcaoMenu) {
            case 1:
                totalProdutos = cadastrarProduto(estoque, totalProdutos);
                break;
            case 2:
                printf("\n--- Listar produtos ---\n");
                listarProdutos(estoque, totalProdutos);
                break;
            case 3:
                printf("\n--- Buscar Produto ---\n");
                break;
            case 4:
                printf("\n--- Entrada/Saída de estoque ---\n");
                break;
            case 5:
                printf("\n--- Remover produto ---\n");
                break;
            case 6:
                printf("\n--- Estoque baixo ---\n");
                break;
            case 0:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opção inválida, tente novamente!\n");
                break;
        }
    } while (opcaoMenu != 0);

    return 0;
}

void limparEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int cadastrarProduto(struct Produto estoque[], int total) {
    struct Produto novo;

    printf("\n--- Cadastrar produto ---\n");

    // Estoque cheio?
    if (total >= MAX_PRODUTOS) {
        printf("Estoque cheio! Não é possível cadastrar.\n");
        return total;
    }

    // Código
    printf("Código: ");
    if (scanf("%d", &novo.codigo) != 1) {
        limparEntrada();
        printf("Código inválido!\n");
        return total;
    }

    // Código repetido?
    for (int i = 0; i < total; i++) {
        if (estoque[i].codigo == novo.codigo) {
            printf("Já existe um produto com esse código!\n");
            return total;
        }
    }

    // Nome
    limparEntrada();
    printf("Nome: ");
    fgets(novo.nome, TAM_NOME, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0'; // tira o '\n'

    // Preço e quantidade
    printf("Preço: ");
    if (scanf("%f", &novo.preco) != 1 || novo.preco < 0) {
        limparEntrada();
        printf("Preço inválido!\n");
        return total;
    }

    printf("Quantidade: ");
    if (scanf("%d", &novo.quantidade) != 1 || novo.quantidade < 0) {
        limparEntrada();
        printf("Quantidade inválida!\n");
        return total;
    }

    // Guardar
    estoque[total] = novo;

    printf("Produto cadastrado com sucesso!\n");
    return total + 1;
}

void listarProdutos(struct Produto estoque[], int total){
    float valorTotal = 0;

    // Estoque vazio
    if (total == 0){
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    // Cabeçalho
    printf("%-8s %-10s %10s %6s\n", "Código", "Nome", "Preço", "Qtd");

    for (int i = 0; i < total; i++){
        printf("%-8d %-10s %10.2f %6d\n",
            estoque[i].codigo,
            estoque[i].nome,
            estoque[i].preco,
            estoque[i].quantidade);

        valorTotal += estoque[i].preco * estoque[i].quantidade;
    }
    
    printf("\nValor total em estoque: R$%.2f\n", valorTotal);
}