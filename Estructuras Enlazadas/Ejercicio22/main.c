#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_NODE_A 10
#define MAX_NODE_B 20


typedef struct node {
    int i;
    struct node *ste;
}Node;

void insertInOrdered (Node ** list, int i){
    Node * node = (Node*)malloc(sizeof(Node));
    node->i = i;
    node->ste = NULL;

    Node *listAux = *list;
    Node * nodePrev = NULL;
    while(listAux != NULL && i < listAux->i){
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

int delete (Node ** list ) {
    Node * nodeAux = *list;
    int i = nodeAux->i;
    *list = (*list)->ste;
    free(nodeAux);
    return i;
}

bool isEmpty(Node * list){
    return list == NULL;
}

Node * newList(int x, int n){
    Node * list = NULL;
    for (int i = x; i < n; i++){
        insertInOrdered(&list, i);
    }
    return list;
}

void getAll (Node ** listC, Node ** listX){
     while(!isEmpty(*listX)){
        insertInOrdered(listC, (*listX)->i);
        *listX = (*listX)->ste;
    }
}

Node * listCat (Node ** listA, Node **listB){
    Node * listC = NULL;
    Node * listA_aux = NULL;
    Node * listB_aux = NULL;
    int dataA = 0;
    int dataB = 0;

    while(!isEmpty(*listA) && !isEmpty(*listB)){
        dataA = (*listA)->i;
        dataB = (*listB)->i;

        if(dataA < dataB){
            insertInOrdered(&listC, dataA);
            insertInOrdered(&listB_aux, dataB);
        }
        else {
            insertInOrdered(&listC, dataB);
            insertInOrdered(&listA_aux, dataA);
        }
        *listA = (*listA)->ste;
        *listB = (*listB)->ste;
    }

    while(!isEmpty(listA_aux)){
        insertInOrdered(&listC, listA_aux->i);
        listA = listA_aux->ste;
    }
    while(!isEmpty(listB_aux)){
        insertInOrdered(&listC, listB_aux->i);
        listB_aux = listB_aux->ste;
    }
    return listC;
}

void showList (Node ** list){
    while(!isEmpty(*list)){
        printf("%d ", delete(list));
    }
}

int main (){

    Node * listA = newList(0, MAX_NODE_A);
    Node * listB = newList(MAX_NODE_A, MAX_NODE_B);
    
    Node * listC = listCat(&listA, &listB);
    showList(&listC);

    return 0;
}