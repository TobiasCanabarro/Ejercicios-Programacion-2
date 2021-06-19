#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_NODE 10

typedef struct node {
    int num;
    struct node *ste;
}Node;

void insertOrdered (Node ** list, int i){
    Node * node = (Node*)malloc(sizeof(Node));
    node->num = i;
    node->ste = NULL;

    Node * listAux = *list;
    Node * nodePrev = NULL;
    while(listAux != NULL && i < listAux->num){
        nodePrev = listAux;
        listAux = listAux->ste;
    }
    if(nodePrev == NULL){
        *list = node;
    }
    else {
        nodePrev->ste = node;
    }
    node->ste = listAux;
}

int deleteFirst (Node ** list){
    Node * nodeAux = *list;
    int i = nodeAux->num;
    *list = (*list)->ste;
    free(nodeAux);
    return i;
}

bool isEmpty (Node * list) {
    return list == NULL;
}

void initList(Node ** list){
    for (int i = 0; i < MAX_NODE; i++){
        insertOrdered(list, i);
    }
}

int quantNode(Node ** list) {
    int count = 0;
    while(!isEmpty(*list)){
        deleteFirst(list);
        count ++;
    }
    return count;
}

int main () {
    
    Node * list = NULL;
    initList(&list);
    printf("Cantidad de nodos : %d\n", quantNode(&list));

    return 0;
}