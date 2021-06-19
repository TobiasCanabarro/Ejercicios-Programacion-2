#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_STACK 10

typedef struct {
    int num;
    char result;
}Data;

typedef struct node {
    Data * data;
    struct node *ste;
}Node;

void push (Node ** stack, Data * data){
    Node * node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->ste = NULL;
    node->ste = *stack;
    *stack = node;
}

Data * pop (Node ** stack) {
    Data * data = (*stack)->data;
    Node * aux = *stack;
    *stack = (*stack)->ste;
    free(aux);
    return data;
}

bool isEmpty (Node * stack){
    return stack == NULL;
}

void initStack (Node ** stack){
    Data * data = (Data*)malloc(sizeof(Data));
    for (int i = 0; i < MAX_STACK; i++){
        data = (Data*)malloc(sizeof(Data));
        data->num = i;
        data->result = 'N';
        if(i % 2 == 0){
            data->result = 'S';
        }
        push(stack, data);
    }
}

void showStack (Node ** stack){
    Data * data = NULL;
    while (!isEmpty(*stack)){
        data = pop(stack);
        printf("Value : %d\n Result : %c\n\n", data->num, data->result);
    }
}

int main () {
    
    Node * stack = NULL;
    initStack(&stack);
    showStack(&stack);

    return 0;
}