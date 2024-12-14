#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

static int stack[STACK_SIZE];
static int top = -1;

void push(int value) {
    if (top >= STACK_SIZE - 1) {
        printf("Erro: Pilha cheia\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top < 0) {
        printf("Erro: Pilha vazia\n");
        exit(1);
    }
    return stack[top--];
}

int is_empty() {
    return top == -1;
}
