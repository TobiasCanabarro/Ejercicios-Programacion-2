#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_NODE 10
#define LIMIT_NODE 100

typedef struct node {
    int i;
    struct node *ste;
}Node;

Node * search (Node ** list, int i){
    Node * listAux = *list;
    while(listAux != NULL && i != listAux->i){
        listAux = listAux->ste;
    }
    return listAux;
}

void insertOrdered (Node ** list, int i){
    Node * node = (Node*)malloc(sizeof(Node));
    node->i = i;
    node->ste = NULL;

    Node * listAux = *list;
    Node * nodePrev = NULL;

    while(listAux != NULL && listAux->i < i){
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

void insertWithoutDuplicates (Node ** list, int i){
    Node * node = search(list, i);
    if(node == NULL){
        insertOrdered(list, i);
    }
}

int deleteFirts (Node ** list){
    Node * nodeAux = *list;
    int i = nodeAux->i;
    *list = (*list)->ste;
    free(nodeAux);
    return i;
}

bool isEmpty(Node * list){
    return list == NULL;
}

void insertInFront (Node ** list, int i){
    Node * node = (Node*)malloc(sizeof(Node));
    node->i = i;
    node->ste = NULL;
    node->ste = *list;
    *list = node;
}

int quantNode (Node ** list){
    Node * listAux = *list;
    int count = 0;
    while (listAux != NULL){
        count ++;
        listAux = listAux->ste;   
    }
    return count;
}

void initList (Node ** list){
    for (int i = 0; i < MAX_NODE; i++){
        insertWithoutDuplicates(list, i);
    }
}

void showList (Node ** list){
    while (!isEmpty(*list)){
        printf("%d ", (*list)->i);
        *list = (*list)->ste;
    }
}

Node * invList (Node ** list){
    Node * invList = NULL;
    int i = 0;
    while(!isEmpty(*list)){
        i = deleteFirts(list);
        insertInFront(&invList, i);
    }
    return invList;
}

int main (){

    Node * list = NULL;
    initList(&list);
    int quant = quantNode(&list);
    if(quant < LIMIT_NODE){
        list = invList(&list);
    }

    showList(&list);

    return 0;
}