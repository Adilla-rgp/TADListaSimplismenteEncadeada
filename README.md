# Trabalho de Estrutura de Dados  
## Implementação de um TAD Coleção Genérica de Discos

Este projeto implementa um **Tipo Abstrato de Dados (TAD) Coleção Genérica** em linguagem C, utilizando **lista simplesmente encadeada** para armazenar e manipular elementos definidos pelo usuário, através de uma API modular e reutilizável.

Como exemplo, foi utilizado o tipo `Disco`, que contém os seguintes campos obrigatórios:

- `char nome[30]` — nome do disco;  
- `int ano` — ano de lançamento;  
- `float preco` — preço do disco.

---

## 1. Ambiente de Desenvolvimento

- **Sistema Operacional:** Windows 11  
- **Compilador:** MinGW (GCC para Windows)  
- **Bibliotecas externas:** Nenhuma

---

## 2. Estrutura dos Arquivos

O projeto é composto pelos seguintes arquivos:

- `README.md` — este documento;  
- `colecao.h` — declaração do TAD genérico de coleção;  
- `colecao.c` — implementação da coleção com lista simplesmente encadeada;  
- `disco.h` — definição do tipo `Disco` e sua interface;  
- `disco.c` — implementação das funções auxiliares para `Disco`;  
- `main.c` — programa principal com menu interativo;  
- `colecao.exe` — executável compilado (gerado após compilação).

---

## 3. Compilação e Execução

### 3.1 Linux/macOS:

```bash
gcc main.c colecao.c disco.c -o colecao
./colecao


### 3.2 Windows

```bash
gcc main.c colecao.c disco.c -o colecao.exe
./colecao.exe
```

---

## 4. Funcionalidades Implementadas e Testadas

Conforme solicitado, o programa implementa o seguinte roteiro de testes, presente no arquivo `main.c`:

1. Criação de uma coleção;
2. Inserção de três elementos do tipo `Disco`;
3. Listagem de todos os elementos da coleção;
4. Consulta de um dos elementos por nome, matrícula e média;
5. Remoção do segundo elemento inserido;
6. Nova listagem da coleção;
7. Esvaziamento da coleção;
8. Listagem final, com a coleção vazia.

Todas as operações utilizam exclusivamente as funções definidas na API do TAD.

---

## 5. Restrições Atendidas

- O arquivo `colecao.c` não utiliza `printf`, `scanf` ou qualquer função de entrada/saída;
- A estrutura contém os campos obrigatórios (char[30], int e float);
- A estrutura de dados utilizada é uma lista simplesmente encadeada genérica;
- O projeto foi desenvolvido de forma modular, com separação entre a lógica do TAD e a interface de uso;
- A API utilizada é única e respeita o padrão definido;
- O trabalho é individual. 

---

## 6. Considerações Finais

Este projeto demonstra a aplicação de TADs genéricos em C, com foco na separação entre a lógica da estrutura de dados e sua utilização prática. A implementação com lista simplesmente encadeada garante flexibilidade e facilidade de manutenção. A abordagem modular permite adaptar facilmente a coleção para outros tipos além de Disco, bastando alterar as funções de comparação, impressão e destruição.

---

## 7. Identificação

**Disciplina:** Estrutura de Dados 1
**Aluno:** Ádilla Roberta Gomes Pereira  
**Professor:** Anselmo Paiva  
**Data de Entrega:** 20 de junho de 2025

---
