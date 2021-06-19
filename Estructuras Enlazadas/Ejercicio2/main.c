#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define POS 3
#define MAX 5

typedef struct nodo {
    int num;
    struct nodo *ste;
}Nodo;

void push (Nodo ** stack, int num){
    Nodo * nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->num = num;
    nodo->ste = NULL;
    nodo->ste = *stack;
    *stack = nodo;
}

int pop (Nodo ** stack){
    int num = (*stack)->num;
    Nodo * aux = *stack;
    *stack = (*stack)->ste;
    free(aux);
    return num;
}

bool isEmpty (Nodo * stack){
    return stack == NULL;
}

void createStack (Nodo ** stack){
    for (int i = 0; i < MAX; i++){
        push(stack, i);
    }
}

Nodo * invStack (Nodo ** stack){
    Nodo * newStack = NULL;
    while(!isEmpty(*stack)){
        push(&newStack, pop(stack));
    }
    return newStack;
}

int lengthStack(Nodo ** stack){
    int cont = 0;
    Nodo * newStack = NULL;
    while(!isEmpty(*stack)){

    }
    return cont;
}

Nodo * insetIntoFirstPosition (Nodo ** stack, int i){

    Nodo * newStack = NULL;
    int cont = 1;
    int num = 0;

    while(!isEmpty(*stack)){

        num = pop(stack);

        if(cont == POS){
            push(&newStack, i);
        }
        else {
            push(&newStack, num);
        } 
        cont ++; 
    }
    return newStack;
}

void showStack (Nodo ** stack){
    while (!isEmpty(*stack)){
        printf("%d ", pop(stack));
    }
}

int main () {
    
    Nodo * stack = NULL;
    createStack(&stack);
    stack = invStack(&stack);
    stack = insetIntoFirstPosition(&stack, 22);
    showStack (&stack);

    return 0;
}