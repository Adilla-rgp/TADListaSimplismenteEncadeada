#ifndef DISCO_H
#define DISCO_H

// Estrutura Disco com três campos obrigatórios: char[30], int e float
typedef struct {
    char nome[30];   // Nome do disco
    int ano;         // Ano de lançamento
    float preco;     // Preço do disco
} Disco;

// Cria um novo disco com os dados fornecidos
Disco* criarDisco(const char* nome, int ano, float preco);

// Libera a memória de um disco
void destruirDisco(void* d);

// Imprime os dados de um disco
void imprimirDisco(void* d);

// Compara dois discos por nome, ano e preço
int compararDisco(const void* a, const void* b);

#endif
