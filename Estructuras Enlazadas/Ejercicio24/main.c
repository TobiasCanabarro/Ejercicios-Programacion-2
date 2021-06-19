#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR 80

typedef struct {
    char nameLastname[MAX_STR + 1];
    int legajo;
    int div;
}Data;

typedef struct nodeSub {
    int div;
    struct nodeSub *ste;
}NodeSub;

typedef struct node {
    int legajo;
    NodeSub * subList;
    struct node *ste;
}Node;

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

NodeSub * insertOrderedLegajo (Node ** list, int legajo){
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
    return node->subList;
}

int deleleDiv (NodeSub ** list){
    NodeSub * nodeAux = *list;
    int div = nodeAux->div;
    *list = (*list)->ste;
    free(nodeAux);
    return div;
}

Node * deleleLegajo (Node ** list){
    Node * nodeAux = *list;
    *list = (*list)->ste;
    return nodeAux;
}

Data * newData (char * name, int legajo, int div){
    Data * data = (Data*)malloc(sizeof(Data));
    strcpy(data->nameLastname, name);
    data->legajo = legajo;
    data->div = div;
    return data;
}

void newRegister (FILE * pFile, char *name, int legajo, int div) {
    Data * data = newData(name, legajo, div);
    fwrite(data, sizeof(Data), 1, pFile);
}

FILE * fileOpen (char * path, char * mode){
    FILE * pFile = NULL;
    pFile = fopen(path, mode);
    if(pFile == NULL){
        printf("ERROR AL ABRIR EL ARCHIVO\n");
        exit(EXIT_FAILURE);
    }
    return pFile;
}

void createFile (){
    FILE * pFile = fileOpen("archivo.dat", "wb");
    newRegister(pFile, "pepeArgento", 2, 3);
    newRegister(pFile, "tobiasCanabarro", 1, 2);
    newRegister(pFile, "moniArgento", 2, 3);
    fclose(pFile);
}

void showFile (){
    FILE * pFile = fileOpen ("archivo.dat", "rb");
    Data * data = (Data*)malloc(sizeof(Data));
    fread(data, sizeof(Data), 1, pFile);
    while(!feof(pFile)){
        printf("%s %d %d\n", data->nameLastname, data->legajo, data->div);
        fread(data, sizeof(Data), 1, pFile);
    }
    fclose(pFile);
}

void completeList (Node ** list){
    FILE * pFile = fileOpen("archivo.dat", "rb");
    Data * data = (Data*)malloc(sizeof(Data));
    NodeSub * subList = NULL;

    fread(data, sizeof(Data), 1, pFile);
    while(!feof(pFile)){
            printf("%d\n", data->legajo);
      subList = insertOrderedLegajo(list, data->legajo);
      insertOrderedDiv(&subList, data->div);
    printf("%d\n", data->div);
      fread(data, sizeof(Data), 1, pFile);
    }
    fclose(pFile);
}

void showList (Node ** list){
    Data data;
    Node * node = NULL;
    while(*list != NULL){
        node = deleleLegajo(list);
        printf("Legajo : %d\n", node->legajo);
        while(node->subList != NULL){
            printf("Division : %d", deleleDiv((&node->subList)));
        }
        free(node);
    }
}

int main()
{

    Node * list = NULL;
    completeList(&list);
    showList(&list);

    return 0;
}
