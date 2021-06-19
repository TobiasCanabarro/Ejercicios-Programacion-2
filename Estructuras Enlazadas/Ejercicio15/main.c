#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_STR 80

typedef struct {
    char nameLastname[MAX_STR + 1];
    int legajo;
    int div;
}Data;

typedef struct node {
    Data * data;
    struct node *ste;
}Node;

Data * newData(char nameLastname[], int legajo, int div){
    Data * data = (Data*)malloc(sizeof(Data));
    strcpy(data->nameLastname, nameLastname);
    data->legajo = legajo;
    data->div = div;
    return data;
}

void insertOrdered (Node ** list, Data * data){
    Node * node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->ste = NULL;

    Node * listAux = *list;
    Node * nodePre = NULL;

    while(listAux != NULL && listAux->data->legajo < data->legajo && listAux->data->div < data->legajo){
        nodePre = listAux;
        listAux = listAux->ste;
    }
    if(nodePre == NULL){
        *list = node;
    }
    else {
      nodePre->ste = node;  
    }
    node->ste = listAux;
}

Data * deleteFirst (Node ** list){
    Node * nodeAux = *list;
    Data * data = nodeAux->data;
    *list  = (*list)->ste;
    free(nodeAux);
    return data;
}

bool isEmpty (Node * list){
    return list == NULL;
}

void createList(Node ** list){
    Data * data = newData("Tobias Canabarro", 1, 2);
    insertOrdered(list, data);
    data = newData("Pepe argento", 2, 1);
    insertOrdered(list, data);
    data = newData("jii haha", 3, 3);
    insertOrdered(list, data);
}

void showList (Node ** list){
    Data * data = NULL;
    while (!isEmpty(*list)){
        data = deleteFirst(list);
        printf("*Name & Lastname : %s\n*Legajo : %d\n*Division : %d\n", data->nameLastname, data->legajo, data->div);
    }
}

int main () {
    
    Node * list = NULL;
    createList(&list);
    showList(&list);

    return 0;
}