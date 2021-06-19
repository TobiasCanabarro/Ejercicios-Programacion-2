#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int dato;
    struct node *ste;
}Node;

typedef struct nodeList {
    int id;
    Node * stack;
    struct nodeList *ste;
}List;


void push (Node ** stack, int dato){
    Node * node = (Node *)malloc(sizeof(Node));
    node->dato = dato;
    node->ste = NULL;
    node->ste = *stack;
    *stack = node;
}

int pop (Node ** stack){
    Node * nodeAux = *stack;
    int dato = nodeAux->dato;
    *stack = (*stack)->ste;
    free(nodeAux);
    return dato;
}

List * insertOrdered(List ** list, int id){
    List * node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->stack = NULL;
    node->ste = NULL;

    List * listAux = *list;
    List * nodePrev = NULL;
    while(listAux != NULL && listAux->id < id){
        nodePrev = listAux;
        listAux = listAux->ste;
    }
    if (nodePrev == NULL){
        *list = node;
    }
    else {
        nodePrev->ste = node;
    }
    node->ste = listAux;
    return node;
}

List * deleteFirst(List ** list){
    List * nodeAux = *list;
    *list = (*list)->ste;
    return nodeAux;
}

void initList (List ** list){
    List * node = NULL;
    for (int i = 0; i < 10; i++){
        node = insertOrdered(list, i);
        for (int j = 0; j < 10; j++){
            push(&node->stack, j);
        }
    }
}

void showList (List ** list){
    List * node = NULL;
    while(*list != NULL){
       node = deleteFirst(list);
       printf("%d\n", node->id);
       while(node->stack != NULL){
           printf("%d ", pop(&node->stack));
       }
       printf("\n");
    }
}

int main()
{
    List * list = NULL;
    initList(&list);
    showList(&list);

    return 0;
}
