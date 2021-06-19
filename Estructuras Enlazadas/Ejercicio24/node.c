#include <stdio.h>
#include <stdlib.h>
#include"node.h"


void insertOrderedDiv(NodeSub ** list, int div){
    NodeSub * node = (NodeSub*)malloc(sizeof(NodeSub));
    node->div = div;
    node->ste = NULL;

    NodeSub * listAux = *list;
    NodeSub * nodePrev = NULL;
    while(listAux != NULL && listAux->div < div){
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

void insertOrderedLegajo (Node ** list, int legajo){
    Node * node = (Node*)malloc(sizeof(Node));
    node->legajo = legajo;
    node->subList = NULL;
    node->ste = NULL;

    Node * listAux = *list;
    Node * nodePrev = NULL;
    while(listAux != NULL && listAux->legajo < legajo){
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

int deleleDiv (NodeSub ** list){
    NodeSub * nodeAux = *list;
    int div = nodeAux->div;
    *list = (*list)->ste;
    free(nodeAux);
    return div;
}

int deleleLegajo (Node ** list){
    Node * nodeAux = *list;
    int legajo = nodeAux->legajo;
    *list = (*list)->ste;
    free(nodeAux);
    return legajo;
}
