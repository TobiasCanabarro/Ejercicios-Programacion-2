/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: tobias-note
 *
 * Created on 23 de enero de 2021, 18:08
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct node {
    int dato;
    struct node *ste;
}Node;

void push(Node ** stack, int i){
    Node * node = (Node*)malloc(sizeof(Node));
    node->dato = i;
    node->ste = NULL;
    node->ste = *stack;
    *stack = node;
}

int pop(Node ** stack){
    Node * node = *stack;
    int dato = node->dato;
    *stack = (*stack)->ste;
    free(node);
    return dato;
}

bool isEmpty(Node * stack){
    return stack == NULL;
}

void initStack(Node ** stack){
    for (int i = 0; i < MAX; i++){
        push(stack, i);
    }
}

Node * invStack (Node ** stack){
    Node * invStack = NULL;
    while(!isEmpty(*stack)){
        push(&invStack, pop(stack));
    }
    return invStack;
}

void showStack (Node ** stack){
    while(!isEmpty(*stack)){
        printf("%d\n", pop(stack));
    }
}

Node * deleteLastNode (Node ** stack){
    Node * newStack = *stack;
    pop(&newStack);
    return newStack;
}

int main(int argc, char** argv) {
        
    Node * stack = NULL;
    initStack(&stack);
    stack = deleteLastNode(&stack);
    showStack(&stack);
    
    return (EXIT_SUCCESS);
}

