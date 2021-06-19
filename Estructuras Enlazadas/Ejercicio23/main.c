#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#define MAX_STR 80

typedef struct {
    char nameLastname[MAX_STR + 1];
    int legajo;
    int div;
}Data;

typedef struct node{
    Data * data;
    struct node *ste;
}Node;

Data * newData (char * name, int legajo, int div){
    Data * data = (Data*)malloc(sizeof(Data));
    strcpy(data->nameLastname, name);
    data->legajo = legajo;
    data->div = div;
    return data;
}

void featureData (Data * data){
    printf("Name lastname : %s Legajo : %d  Division : %d\n", data->nameLastname, data->legajo, data->div);
}

FILE * fileOpen (char * path, char * mode){
    FILE * pFile = NULL;
    pFile = fopen(path, mode);
    if(pFile == NULL){
        printf("ERROR AL ABRIR EL %s\n", path);
        exit(EXIT_FAILURE);
    }
    return pFile;
}

void createFile (){
    FILE * pFile = fileOpen("archivo.txt", "w");
    char * line = (char*)malloc(sizeof(char)* MAX_STR + 1);
    strcpy(line, "tobiascanabarro;1;2;");
    fputs(line, pFile);

    strcpy(line, "pepeargento;2;1;");
    fputs(line, pFile);

    strcpy(line, "moniargento;3;3;");
    fputs(line, pFile);
    fclose(pFile);
}

Node * search (Node ** list, Data * data){
    Node * listAux = *list;
    while (listAux != NULL && listAux != data->legajo){
        listAux = listAux->ste;
    }
    return listAux;
}

void insertOrdered (Node ** list, Data * data){
    Node * node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->ste = NULL;

    Node * listAux = *list;
    Node * nodePrev = NULL;
    while(listAux != NULL && listAux->data->legajo < data->legajo){
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
}

void insertWithoutDuplicates (Node ** list, Data * data){
    Node * node = search(list, data);
    if(node == NULL){
        insertOrdered(list, data);
    }
}

Data * deleteFirst(Node ** list){
    Node * nodeAux = *list;
    Data * data = nodeAux->data;
    *list = (*list)->ste;
    free(nodeAux);
    return data;
}

bool isEmpty (Node * list){
    return list == NULL;
}

void parseLine (Data * data, char * line){
    strcpy(data->nameLastname, strtok(line, ";"));
    data->legajo = atoi(strtok(NULL, ";"));
    data->div = atoi(strtok(NULL, ";"));
}

void getAll (Node ** list, char * path, char * mode){
    char * line = (char*)malloc(sizeof(char)* MAX_STR + 1);
    FILE * pFile = fileOpen(path, mode);
    Data * data = (Data*)malloc(sizeof(Data));


    fgets(line, MAX_STR, pFile);
    char * token = strtok(line, ";");

    while(token != NULL){

        data = (Data*)malloc(sizeof(Data));
        strcpy(data->nameLastname, token);

        token = strtok(NULL, ";");
        data->legajo = atoi(token);

        token = strtok(NULL, ";");
        data->div = atoi(token);

        insertWithoutDuplicates(list, data);
        token = strtok(NULL, ";");
    }

    fclose(pFile);
}

void showList(Node ** list){
    Data * data = NULL;
    while(!isEmpty(*list)){
        data = deleteFirst(list);
        featureData(data);
    }
}

int main()
{
    Node * list = NULL;
    createFile();
    getAll(&list, "archivo.txt", "r");
    showList(&list);

    return 0;
}

