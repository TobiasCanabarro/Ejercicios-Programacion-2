#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_NODE 10

typedef struct node {
    int num;
    struct node *ste;
}Node;

void insertOrdered(Node ** list, int i){
    Node * node = (Node*)malloc(sizeof(Node));
    node->num = i;
    node->ste = NULL;

    Node * listAux = *list;
    Node * nodePrev = NULL;
    while (listAux != NULL && i < listAux->num){
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

int deleteFirst(Node ** list){
    Node * nodeAux = *list;
    int i = nodeAux->num;
    *list = (*list)->ste;
    free(nodeAux);
    return i;
}

bool isEmpty (Node * list){
    return list == NULL;
}

void initList (Node ** list, int since, int till){
    for (int i = since; i < till; i++){
        insertOrdered(list, i);
    }
}

void getAll (Node ** listC, Node ** listX){
    while(!isEmpty(*listX)){
        insertOrdered(listC, deleteFirst(listX));
    }
}

Node * listCat (Node ** listA, Node ** listB){
    Node * listC = NULL;
    getAll(&listC, listA);
    getAll(&listC, listB);
    return listC;
}

void showList (Node ** listC){
    while(!isEmpty(*listC)){
        printf("%d ", deleteFirst(listC));
    }
}

int main () {
    
    Node * listA = NULL;
    Node * listB = NULL;

    initList(&listA, 0, 10);
    initList(&listB, 10, 20);

    Node * listC = listCat(&listA, &listB);
    showList(&listC);

    return 0;
}