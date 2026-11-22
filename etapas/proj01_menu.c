#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
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
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu) {
            case 1:
                printf("\n--- Cadastrar produto ---\n");
                break;
            case 2:
                printf("\n--- Listar produtos ---\n");
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