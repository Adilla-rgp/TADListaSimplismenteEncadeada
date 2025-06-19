#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disco.h"
#include "colecao.h"

int main() {
    Colecao* colecao = NULL;
    int opcao;
    char nome[30];
    int ano;
    float preco;

    do {
        // Exibe menu
        printf("\n--- MENU ---\n");
        printf("1. Criar colecao\n");
        printf("2. Inserir disco\n");
        printf("3. Listar discos\n");
        printf("4. Consultar disco\n");
        printf("5. Remover disco\n");
        printf("6. Esvaziar colecao\n");
        printf("7. Destruir colecao (se vazia)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpa buffer do ENTER

        switch (opcao) {
            case 1:
                // Cria coleção
                if (!colecao) {
                    colecao = criarColecao(20);
                    printf("Colecao criada com sucesso.\n");
                } else {
                    printf("Colecao já existe.\n");
                }
                break;

            case 2:
                // Insere novo disco
                if (!colecao) {
                    printf("Crie a colecao primeiro!\n");
                    break;
                }
                printf("Nome do disco: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0;

                printf("Ano: ");
                scanf("%d", &ano);
                printf("Preco: ");
                scanf("%f", &preco);
                getchar();

                Disco* d = criarDisco(nome, ano, preco);
                if (inserir(colecao, d)) {
                    printf("Disco inserido com sucesso.\n");
                } else {
                    destruirDisco(d);
                    printf("Falha ao inserir disco.\n");
                }
                break;

            case 3:
                // Lista todos os discos
                if (colecao) {
                    printf("\n--- Lista de Discos ---\n");
                    listar(colecao, imprimirDisco);
                } else {
                    printf("Colecao nao existe.\n");
                }
                break;

            case 4:
                // Consulta um disco
                if (!colecao) {
                    printf("Crie a colecao primeiro!\n");
                    break;
                }
                printf("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0;

                printf("Ano: ");
                scanf("%d", &ano);
                printf("Preco: ");
                scanf("%f", &preco);
                getchar();

                Disco temp;
                strncpy(temp.nome, nome, sizeof(temp.nome));
                temp.ano = ano;
                temp.preco = preco;

                Disco* encontrado = (Disco*) consultar(colecao, &temp, compararDisco);
                if (encontrado) {
                    printf("Disco encontrado:\n");
                    imprimirDisco(encontrado);
                } else {
                    printf("Disco nao encontrado.\n");
                }
                break;

            case 5:
                // Remove um disco
                if (!colecao) {
                    printf("Crie a colecao primeiro!\n");
                    break;
                }
                printf("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0;

                printf("Ano: ");
                scanf("%d", &ano);
                printf("Preco: ");
                scanf("%f", &preco);
                getchar();

                Disco temp2;
                strncpy(temp2.nome, nome, sizeof(temp2.nome));
                temp2.ano = ano;
                temp2.preco = preco;

                if (remover(colecao, &temp2, compararDisco, destruirDisco)) {
                    printf("Disco removido.\n");
                } else {
                    printf("Disco nao encontrado.\n");
                }
                break;

            case 6:
                // Esvazia coleção
                if (colecao) {
                    esvaziar(colecao, destruirDisco);
                    printf("Colecao esvaziada.\n");
                } else {
                    printf("Colecao nao existe.\n");
                }
                break;

            case 7:
                // Destroi a coleção (se estiver vazia)
                if (colecao && destruirColecao(colecao)) {
                    colecao = NULL;
                    printf("Colecao destruída.\n");
                } else {
                    printf("Erro ao destruir: colecao nao existe ou nao esta vazia.\n");
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }

    } while (opcao != 0);

    // Libera tudo no final, caso o usuário saia sem destruir
    if (colecao) {
        esvaziar(colecao, destruirDisco);
        destruirColecao(colecao);
    }

    return 0;
}
