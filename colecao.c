#include <stdlib.h>
#include "colecao.h"

// Cria uma nova coleção com capacidade máxima
Colecao* criarColecao(int capacidade) {
    Colecao* c = malloc(sizeof(Colecao));
    if (c) {
        c->inicio = NULL;
        c->tamanho = 0;
        c->capacidade = capacidade;
    }
    return c;
}

// Insere um novo elemento no início da lista
int inserir(Colecao* c, void* elem) {
    if (!c || c->tamanho >= c->capacidade) return 0;

    No* novo = malloc(sizeof(No));
    if (!novo) return 0;

    novo->dado = elem;
    novo->prox = c->inicio;
    c->inicio = novo;
    c->tamanho++;
    return 1;
}

// Busca um elemento na coleção com função de comparação
void* consultar(Colecao* c, void* chave, int (*cmp)(const void*, const void*)) {
    if (!c) return NULL;

    No* atual = c->inicio;
    while (atual) {
        if (cmp(chave, atual->dado)) {
            return atual->dado;
        }
        atual = atual->prox;
    }
    return NULL;
}

// Remove um elemento da lista com base na comparação
int remover(Colecao* c, void* chave, int (*cmp)(const void*, const void*), void (*destruir)(void*)) {
    if (!c) return 0;

    No* atual = c->inicio;
    No* anterior = NULL;

    while (atual) {
        if (cmp(chave, atual->dado)) {
            if (anterior) anterior->prox = atual->prox;
            else c->inicio = atual->prox;

            destruir(atual->dado);
            free(atual);
            c->tamanho--;
            return 1;
        }
        anterior = atual;
        atual = atual->prox;
    }

    return 0;
}

// Percorre a lista e chama a função de impressão para cada elemento
void listar(Colecao* c, void (*print)(void*)) {
    if (!c) return;

    No* atual = c->inicio;
    while (atual) {
        print(atual->dado);
        atual = atual->prox;
    }
}

// Remove todos os elementos da coleção, liberando memória
void esvaziar(Colecao* c, void (*destruir)(void*)) {
    if (!c) return;

    No* atual = c->inicio;
    while (atual) {
        No* temp = atual;
        atual = atual->prox;
        destruir(temp->dado);
        free(temp);
    }

    c->inicio = NULL;
    c->tamanho = 0;
}

// Destroi a coleção (somente se estiver vazia)
int destruirColecao(Colecao* c) {
    if (c && c->tamanho == 0) {
        free(c);
        return 1;
    }
    return 0;
}
