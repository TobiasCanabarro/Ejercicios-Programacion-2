#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_STR 80
#define MAX_STACK 1

typedef struct {
    char name[MAX_STR + 1];
    char lastname [MAX_STR + 1];
}Data;

typedef struct node {
    Data * data;
    struct node *ste;
}Node;

void push(Node ** stack, Data * data){
    Node * node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->ste = NULL;
    node->ste = *stack;
    *stack = node;
}

Data * pop (Node ** stack){
    Node * aux = *stack;
    Data * data = aux->data;
    *stack = (*stack)->ste;
    free(aux);
    return data;
}

bool isEmpty(Node * stack){
    return stack == NULL;
}

Data * newData (){
    Data * data = (Data*)malloc(sizeof(Data));
    // memset(data->name, MAX_STR + 1, '\0');
    // memset(data->lastname, MAX_STR + 1, '\0');
    printf("Name : ");
    scanf("%s", data->name);
    printf("Lastname : ");
    scanf("%s", data->lastname);
    return data; 
}

Node * createStack (){
    Data * data = NULL;
    Node * stack = NULL;
    for (int i = 0; i < MAX_STACK; i++){
        data = newData();
        push(&stack , data);
    }
}

void showStack (Node ** stack){
    Data * data = NULL;
    while(!isEmpty(*stack)){
        data = pop(stack);
        printf("Name : %s, Lastname : %s\n", data->name, data->lastname);
    }
}

int main () {
    
    Node * stack = createStack();
    showStack(&stack);

    return 0;
}