//DESAFIO FREE FIRE NOVATO

#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

// Estrutura que representa um item na mochila
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Função para exibir o inventário atual
void listarItens(Item mochila[], int total) {
    printf("\n===== INVENTÁRIO DA MOCHILA =====\n");
    if (total == 0) {
        printf("A mochila está vazia!\n");
        return;
    }

    printf("%-20s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
    printf("--------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        printf("%-20s %-15s %-10d\n",
               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    printf("--------------------------------------------\n");
}

// Função para adicionar um item na mochila
void adicionarItem(Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("⚠️ Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;
    printf("\nDigite o nome do item: ");
    scanf(" %[^\n]", novo.nome);

    printf("Digite o tipo do item: ");
    scanf(" %[^\n]", novo.tipo);

    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[*total] = novo;
    (*total)++;

    printf("✅ Item adicionado com sucesso!\n");
}

// Função para remover um item da mochila pelo nome
void removerItem(Item mochila[], int *total) {
    if (*total == 0) {
        printf("⚠️ A mochila está vazia!\n");
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item a ser removido: ");
    scanf(" %[^\n]", nomeBusca);

    int encontrado = 0;
    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            // Desloca os itens seguintes para preencher o espaço
            for (int j = i; j < *total - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*total)--;
            encontrado = 1;
            printf("🗑️ Item '%s' removido da mochila!\n", nomeBusca);
            break;
        }
    }

    if (!encontrado) {
        printf("❌ Item não encontrado!\n");
    }
}

// Função principal
int main() {
    Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;

    do {
        printf("\n===== MENU MOCHILA FREE FIRE =====\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarItem(mochila, &total);
                break;
            case 2:
                removerItem(mochila, &total);
                break;
            case 3:
                listarItens(mochila, total);
                break;
            case 0:
                printf("🏝️ Encerrando o sistema da mochila... Boa sorte na ilha!\n");
                break;
            default:
                printf("⚠️ Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}


//Nível Aventureiro: Mochila com Busca

#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

// Estrutura que representa um item na mochila
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// ====== Funções ======

// Exibe todos os itens cadastrados
void listarItens(Item mochila[], int total) {
    printf("\n===== INVENTÁRIO DA MOCHILA =====\n");
    if (total == 0) {
        printf("A mochila está vazia!\n");
        return;
    }

    printf("%-20s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
    printf("--------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        printf("%-20s %-15s %-10d\n",
               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    printf("--------------------------------------------\n");
}

// Adiciona novo item à mochila
void adicionarItem(Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("⚠️ Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;
    printf("\nDigite o nome do item: ");
    scanf(" %[^\n]", novo.nome);

    printf("Digite o tipo do item: ");
    scanf(" %[^\n]", novo.tipo);

    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[*total] = novo;
    (*total)++;

    printf("✅ Item adicionado com sucesso!\n");
}

// Remove item da mochila pelo nome
void removerItem(Item mochila[], int *total) {
    if (*total == 0) {
        printf("⚠️ A mochila está vazia!\n");
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item a ser removido: ");
    scanf(" %[^\n]", nomeBusca);

    int encontrado = 0;
    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            for (int j = i; j < *total - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*total)--;
            encontrado = 1;
            printf("🗑️ Item '%s' removido da mochila!\n", nomeBusca);
            break;
        }
    }

    if (!encontrado)
        printf("❌ Item não encontrado!\n");
}

// 🔍 Busca sequencial por nome
void buscarItem(Item mochila[], int total) {
    if (total == 0) {
        printf("⚠️ A mochila está vazia!\n");
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    scanf(" %[^\n]", nomeBusca);

    int encontrado = 0;
    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\n===== ITEM ENCONTRADO =====\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            printf("============================\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("❌ O item '%s' não foi encontrado na mochila!\n", nomeBusca);
    }
}

// ====== Função Principal ======
int main() {
    Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;

    do {
        printf("\n===== MENU MOCHILA FREE FIRE =====\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item por nome\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarItem(mochila, &total);
                break;
            case 2:
                removerItem(mochila, &total);
                break;
            case 3:
                listarItens(mochila, total);
                break;
            case 4:
                buscarItem(mochila, total);
                break;
            case 0:
                printf("🏝️ Encerrando o sistema da mochila... Boa sorte na ilha!\n");
                break;
            default:
                printf("⚠️ Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

//Nível MESTRE

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITENS 10

// Enum para definir critérios de ordenação
typedef enum {
    NOME = 1,
    TIPO,
    PRIORIDADE
} CriterioOrdenacao;

// Estrutura do item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
    int prioridade; // 1 a 5
} Item;

// ===== Funções Básicas =====
void listarItens(Item mochila[], int total) {
    printf("\n===== INVENTÁRIO DA MOCHILA =====\n");
    if (total == 0) {
        printf("A mochila está vazia!\n");
        return;
    }

    printf("%-20s %-15s %-10s %-10s\n", "Nome", "Tipo", "Qtd", "Prioridade");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        printf("%-20s %-15s %-10d %-10d\n",
               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade, mochila[i].prioridade);
    }
    printf("------------------------------------------------------------\n");
}

void adicionarItem(Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("⚠️ Mochila cheia!\n");
        return;
    }

    Item novo;
    printf("\nDigite o nome do item: ");
    scanf(" %[^\n]", novo.nome);
    printf("Digite o tipo do item: ");
    scanf(" %[^\n]", novo.tipo);
    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);
    printf("Digite a prioridade (1 a 5): ");
    scanf("%d", &novo.prioridade);

    if (novo.prioridade < 1 || novo.prioridade > 5) {
        printf("⚠️ Prioridade inválida! Definida como 3 por padrão.\n");
        novo.prioridade = 3;
    }

    mochila[*total] = novo;
    (*total)++;

    printf("✅ Item adicionado com sucesso!\n");
}

// ===== Funções de Ordenação =====
int comparar(Item a, Item b, CriterioOrdenacao criterio) {
    switch (criterio) {
        case NOME:
            return strcmp(a.nome, b.nome);
        case TIPO:
            return strcmp(a.tipo, b.tipo);
        case PRIORIDADE:
            return a.prioridade - b.prioridade;
        default:
            return 0;
    }
}

void ordenarMochila(Item mochila[], int total, CriterioOrdenacao criterio, int *comparacoes) {
    *comparacoes = 0;

    for (int i = 1; i < total; i++) {
        Item chave = mochila[i];
        int j = i - 1;

        while (j >= 0 && comparar(mochila[j], chave, criterio) > 0) {
            mochila[j + 1] = mochila[j];
            j--;
            (*comparacoes)++;
        }
        mochila[j + 1] = chave;
    }

    printf("\n✅ Mochila ordenada com sucesso!\n");
    printf("📊 Total de comparações: %d\n", *comparacoes);
}

// ===== Busca Binária =====
int buscaBinaria(Item mochila[], int total, char nomeBusca[]) {
    int inicio = 0, fim = total - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(mochila[meio].nome, nomeBusca);

        if (cmp == 0)
            return meio;
        else if (cmp < 0)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1;
}

// ===== Função Principal =====
int main() {
    Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;
    bool ordenadaPorNome = false;
    int comparacoes = 0;

    do {
        printf("\n===== MENU MOCHILA - NÍVEL MESTRE =====\n");
        printf("1 - Adicionar item\n");
        printf("2 - Listar itens\n");
        printf("3 - Ordenar mochila\n");
        printf("4 - Busca binária por nome\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarItem(mochila, &total);
                ordenadaPorNome = false;
                break;

            case 2:
                listarItens(mochila, total);
                break;

            case 3: {
                int criterio;
                printf("\nEscolha o critério de ordenação:\n");
                printf("1 - Nome\n2 - Tipo\n3 - Prioridade\n");
                scanf("%d", &criterio);

                if (criterio >= 1 && criterio <= 3) {
                    ordenarMochila(mochila, total, (CriterioOrdenacao)criterio, &comparacoes);
                    if (criterio == NOME)
                        ordenadaPorNome = true;
                    else
                        ordenadaPorNome = false;
                } else {
                    printf("⚠️ Critério inválido!\n");
                }
                break;
            }

            case 4: {
                if (!ordenadaPorNome) {
                    printf("⚠️ A lista precisa estar ordenada por NOME antes da busca binária!\n");
                    break;
                }

                char nomeBusca[30];
                printf("\nDigite o nome do item para busca: ");
                scanf(" %[^\n]", nomeBusca);

                int pos = buscaBinaria(mochila, total, nomeBusca);
                if (pos != -1) {
                    printf("\n===== ITEM ENCONTRADO =====\n");
                    printf("Nome: %s\n", mochila[pos].nome);
                    printf("Tipo: %s\n", mochila[pos].tipo);
                    printf("Quantidade: %d\n", mochila[pos].quantidade);
                    printf("Prioridade: %d\n", mochila[pos].prioridade);
                    printf("============================\n");
                } else {
                    printf("❌ Item '%s' não encontrado!\n", nomeBusca);
                }
                break;
            }

            case 0:
                printf("\n🏝️ Encerrando o sistema... Você dominou a ilha!\n");
                break;

            default:
                printf("⚠️ Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
