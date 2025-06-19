#ifndef COLECAO_H
#define COLECAO_H

// Nó da lista: armazena um dado genérico (void*) e ponteiro para o próximo nó
typedef struct No {
    void* dado;
    struct No* prox;
} No;

// Estrutura da coleção com cabeça da lista, tamanho e capacidade máxima
typedef struct {
    No* inicio;      // Início da lista encadeada
    int tamanho;     // Quantidade atual de elementos
    int capacidade;  // Capacidade máxima permitida
} Colecao;

// Cria uma coleção com capacidade definida
Colecao* criarColecao(int capacidade);

// Insere um novo elemento genérico na coleção
int inserir(Colecao* c, void* elem);

// Consulta um elemento na coleção com base na função de comparação
void* consultar(Colecao* c, void* chave, int (*cmp)(const void*, const void*));

// Remove um elemento usando comparação e destruição
int remover(Colecao* c, void* chave, int (*cmp)(const void*, const void*), void (*destruir)(void*));

// Lista todos os elementos da coleção
void listar(Colecao* c, void (*print)(void*));

// Remove todos os elementos da coleção
void esvaziar(Colecao* c, void (*destruir)(void*));

// Destroi a coleção somente se estiver vazia
int destruirColecao(Colecao* c);

#endif