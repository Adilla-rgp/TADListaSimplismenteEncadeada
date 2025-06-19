#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "disco.h"

// Cria dinamicamente um novo Disco com os dados informados
Disco* criarDisco(const char* nome, int ano, float preco) {
    Disco* d = malloc(sizeof(Disco));
    if (d) {
        strncpy(d->nome, nome, 29); // Copia no máximo 29 caracteres
        d->nome[29] = '\0';         // Garante término da string
        d->ano = ano;
        d->preco = preco;
    }
    return d;
}

// Libera a memória de um disco
void destruirDisco(void* d) {
    free((Disco*)d);
}

// Imprime os dados de um disco (chamado pela função listar)
void imprimirDisco(void* d) {
    Disco* disco = (Disco*)d;
    printf("Nome: %s | Ano: %d | Preco: %.2f\n", disco->nome, disco->ano, disco->preco);
}

// Compara dois discos: retorna verdadeiro se nome, ano e preco forem iguais
int compararDisco(const void* a, const void* b) {
    const Disco* d1 = (const Disco*)a;
    const Disco* d2 = (const Disco*)b;
    return strcmp(d1->nome, d2->nome) == 0 && d1->ano == d2->ano && d1->preco == d2->preco;
}
