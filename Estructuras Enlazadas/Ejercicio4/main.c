#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_STACK 10

typedef struct node {
    int data;
    struct node *ste;
}Node;

void push (Node ** stack, int i){
    Node * node = (Node*)malloc(sizeof(Node));
    node->data = i;
    node->ste = NULL;
    node->ste = *stack;
    *stack = node;
}

int pop (Node ** stack){
    int data = (*stack)->data;
    Node * aux = *stack;
    *stack = (*stack)->ste;
    free(aux);
    return data;
}

bool isEmpty (Node * stack){
    return stack == NULL;
}

void initStack (Node ** stack){
    for (int i = 0; i < MAX_STACK; i++){
        push(stack, i);
    }
}

Node * invStack (Node ** stack){
    Node * newStack = NULL;
    while (!isEmpty(*stack)){
        push(&newStack, pop(stack));
    }
    return newStack; 
}

void insetXinI (Node ** stack, int x, int i){

    Node * newStack = NULL;
    *stack = invStack(stack);
    int cont = 1;
    int data = 0;

    while (!isEmpty(*stack)){

        data = pop(stack);
        
        if(cont == i){
            data = x;
        }
        push(&newStack, data);
        cont ++;
    }
    *stack = newStack;
}

void showStack (Node ** stack){
    while(!isEmpty(*stack)){
        printf("%d ", pop(stack));
    }
}

int main () {
    
    Node * stack = NULL;
    initStack(&stack);
    insetXinI(&stack, 22, 4);
    showStack(&stack);

    return 0;
}