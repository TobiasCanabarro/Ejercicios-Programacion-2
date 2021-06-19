#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define DELIMITER '.'
#define MAX_STR 80
#define MAX 7

typedef struct node {
    char value;
    struct node *ste;
}Node;

void push(Node ** stack, char value){
    Node * node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->ste = NULL;
    node->ste = *stack;
    *stack = node;
}

char pop (Node ** stack) {
    Node * aux = *stack;
    char value = aux->value;
    *stack = (*stack)->ste;
    free(aux);
    return value;
} 

bool isEmpty(Node * stack){
    return stack == NULL;
}

bool isDiferent (Node * stack, char value){
    return stack->value != value;
}

void initStack (Node ** stack, char str[]){
    for (int i = 0; i < MAX; i++){
        push(stack, str[i]);
    }
}

void showStack (Node ** stack){
    while(!isEmpty(*stack)){
        printf("%c", pop(stack));
    }
}

Node * getFirstPart (Node ** stack){
    Node * firstPart = NULL;
    char value = pop(stack);
    while(!isEmpty(*stack) && value != DELIMITER) {
        push(&firstPart, value);
        value = pop(stack);
    }
    return firstPart;
}

bool isEquals (Node ** stack){

    Node * firtsPart = getFirstPart(stack);
    bool result = true;
    char value1;
    char value2;    

    while(!isEmpty(*stack) && !isEmpty(firtsPart) && result){
        value1 = pop(stack);
        value2 = pop(&firtsPart);
        if(value1 != value2){
            result = false;
        }
    }
    return result;
}


int main () {
    
    Node * stack = NULL;
    char str[] = {'a', 'b', 'c', '.', 'c', 'h', 'b'};
    initStack(&stack, str);
    
    char * result = (char*)malloc(sizeof(char) * MAX_STR + 1);
    strcpy(result, "No son iguales");

    if(isEquals(&stack)){
        strcpy(result, "Son iguales");
    }

    printf("%s\n", result);

    return 0;
}