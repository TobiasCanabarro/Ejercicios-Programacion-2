#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

typedef struct nodo {
    int num;
    struct nodo *ste;
}Nodo;

void push (Nodo ** stack, int i){
    Nodo * nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->num = i;
    nodo->ste = NULL;
    nodo->ste = *stack;
    *stack = nodo;
}

int pop (Nodo **stack){
    int num = (*stack)->num;
    Nodo * nodo = *stack;
    *stack = (*stack)->ste;
    free(nodo);
    return num;
}

bool isEmpty (Nodo * stack) {
    return stack == NULL;
}

void createStack (Nodo ** stack){
    for (int i = 0; i < MAX; i++){
        push(stack, i);
    }
}

void showStack (Nodo ** stack){
    while (!isEmpty(*stack)){
        printf("%d ", pop(stack));
    }
}

Nodo * invStack (Nodo ** stack) {
    Nodo * newStack = NULL;
    while (!isEmpty(*stack)){
        push(&newStack, pop(stack));
    }

    return newStack;
}

Nodo * magic(Nodo ** stack, int i){
    Nodo * newStack = invStack(stack);
    int value = pop(&newStack);
    value = pop(&newStack);
    push(&newStack, i);
    return newStack;
}


int main () {

    Nodo * stack = NULL;
    createStack(&stack);

    int i = 22;

    stack = magic(&stack , i);

    showStack(&stack);

    return 0;
}

