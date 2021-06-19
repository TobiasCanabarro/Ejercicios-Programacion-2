#include <stdio.h>
#include <stdlib.h>
#define MAX_NODE 2

typedef struct nodeSub {
    int j;
    struct nodeSub *ste;
}NodeSub;

typedef struct node {
    int i;
    NodeSub * subList;
    struct node *ste;
}Node;

NodeSub * insertOrderedNodeSub (NodeSub ** list, int j) {

    NodeSub * node = (NodeSub*)malloc(sizeof(NodeSub));
    node->j = j;
    node->ste = NULL;

    NodeSub * listAux = *list;
    NodeSub * nodePrev = NULL;

    while(listAux != NULL && listAux->j < j){
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
    return node;
}

Node * insertOrderedList (Node ** list, int i){

    Node * node = (Node*)malloc(sizeof(Node));
    node->i = i;
    node->ste = NULL;
    node->subList = NULL;

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
    return node;
}

int deleteSubList (NodeSub ** list){
    NodeSub * nodeAux = *list;
    int j = nodeAux->j;
    *list = (*list)->ste;
    //free(nodeAux);
    return j;
}

Node * deleteList (Node ** list){
    Node * nodeAux = *list;
    *list = (*list)->ste;
    return nodeAux;
}

void initList (Node ** list){

    Node * node = NULL;

    for (int i = 0; i < MAX_NODE; i++){

        node = insertOrderedList(list, i);

        for (int j = 0; j < MAX_NODE; j++){
           insertOrderedNodeSub(&node->subList, j);
        }
    }
}

void showList (Node ** list){

    Node * node = NULL;
    NodeSub * subList = NULL;

    while(*list != NULL){
        node = deleteList(list);
        subList = node->subList;
        printf("List node : %d\n", node->i);
        printf("Sublist node : ");

        while(subList != NULL){
            printf("%d ", deleteSubList(&subList));
        }
        printf("\n");
        free(node);
    }
}

int main()
{
   Node * list = NULL;
   initList(&list);










   showList(&list);
    return 0;
}
