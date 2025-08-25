#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

// Estrutura que representa cada item da mochila
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

int main() {
    struct Item mochila[MAX_ITENS];
    int qtdItens = 0;  // contador de itens cadastrados
    int opcao;

    do {
        printf("\n===== MOCHILA VIRTUAL - NIVEL NOVATO =====\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // consumir quebra de linha

        switch (opcao) {
            case 1: // Adicionar
                if (qtdItens < MAX_ITENS) {
                    printf("\nDigite o nome do item: ");
                    fgets(mochila[qtdItens].nome, 30, stdin);
                    mochila[qtdItens].nome[strcspn(mochila[qtdItens].nome, "\n")] = 0;

                    printf("Digite o tipo do item: ");
                    fgets(mochila[qtdItens].tipo, 20, stdin);
                    mochila[qtdItens].tipo[strcspn(mochila[qtdItens].tipo, "\n")] = 0;

                    printf("Digite a quantidade: ");
                    scanf("%d", &mochila[qtdItens].quantidade);
                    getchar();

                    qtdItens++;
                    printf("Item adicionado com sucesso!\n");
                } else {
                    printf("Mochila cheia! Nao e possivel adicionar mais itens.\n");
                }
                break;

            case 2: { // Remover
                if (qtdItens == 0) {
                    printf("Mochila vazia! Nao ha itens para remover.\n");
                    break;
                }

                char nomeRemover[30];
                printf("\nDigite o nome do item a remover: ");
                fgets(nomeRemover, 30, stdin);
                nomeRemover[strcspn(nomeRemover, "\n")] = 0;

                int encontrado = 0;
                for (int i = 0; i < qtdItens; i++) {
                    if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                        // sobrescreve o item removido com o último
                        mochila[i] = mochila[qtdItens - 1];
                        qtdItens--;
                        encontrado = 1;
                        printf("Item removido com sucesso!\n");
                        break;
                    }
                }
                if (!encontrado) {
                    printf("Item nao encontrado na mochila.\n");
                }
                break;
            }

            case 3: // Listar
                if (qtdItens == 0) {
                    printf("\nMochila vazia!\n");
                } else {
                    printf("\n=== ITENS NA MOCHILA ===\n");
                    printf("%-20s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
                    printf("------------------------------------------------\n");
                    for (int i = 0; i < qtdItens; i++) {
                        printf("%-20s %-15s %-10d\n",
                               mochila[i].nome,
                               mochila[i].tipo,
                               mochila[i].quantidade);
                    }
                }
                break;

            case 0:
                printf("\nSaindo da mochila... Ate a proxima!\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}