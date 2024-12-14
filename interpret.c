#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "interpret.h"
#include "stack.h"

void interpret(const char *source) {
    char op[10];
    char arg[10];

    // Remover o caractere '>' se presente na entrada
    if (source[0] == '>') {
        source++;
    }

    // Usando strtok para separar o comando e o argumento
    char *token = strtok((char *)source, " \n");  // Remove espaços e a quebra de linha
    if (token != NULL) {
        strcpy(op, token);  // Copia o comando
    }

    token = strtok(NULL, " \n");  // Captura o argumento (se houver)
    if (token != NULL) {
        strcpy(arg, token);
    }

    // Imprime o comando e o argumento lido
    printf("Comando lido: '%s', Argumento lido: '%s'\n", op, arg);

    // Se o comando for "pop" e não houver argumento
    if (strcmp(op, "pop") == 0) {
        if (!is_empty()) {
            int value = pop();
            printf("Valor desempilhado: %d\n", value);
        } else {
            printf("Erro: Pilha vazia\n");
        }
    }
    // Se o comando for "push" e houver um argumento
    else if (strcmp(op, "push") == 0) {
        if (arg[0] != '\0') {  // Se o argumento não estiver vazio
            int value = atoi(arg); // Converte o argumento para inteiro
            push(value);
            printf("Valor %d empilhado\n", value);
        } else {
            printf("Erro: Argumento inválido para 'push'\n");
        }
    }
    else {
        printf("Erro: Comando desconhecido\n");
    }
}