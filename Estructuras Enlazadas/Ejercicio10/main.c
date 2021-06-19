#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define YES 's'
#define NO 'n'
#define MAX_QUEUE 10

typedef struct {
    int data;
    char result;
}Data;

typedef struct node {
    Data * data;
    struct node *ste;    
}Node;

typedef struct {
    Node * front;
    Node * end;
}Queue;

void create (Queue * queue){
    queue->front = NULL;
    queue->end = NULL;
}

void add (Queue * queue, Data * data) {
    Node * node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->ste = NULL;

    if(queue->front == NULL){
        queue->front = node;
    }else {
        queue->end->ste = node;
    }
    queue->end = node;
}

Data * get (Queue * queue){
    Node * aux = queue->front;
    Data * data = aux->data;
    queue->front = aux->ste;

    if(queue->front == NULL){
        queue->end = NULL;
    }
    free(aux);
    return data;
}

bool isEmpty (Queue * queue) {
    return queue->front == NULL && queue->end == NULL;
}

void initQueue (Queue * queue){
    Data * data = NULL;
    for (int i = 0; i < MAX_QUEUE; i++){
        data = (Data*)malloc(sizeof(Data));
        data->result = NO;
        data->data = i;
        if(i % 2 == 0){
            data->result = YES;
        }
        add(queue, data);
    }
}

void showQueue (Queue * queue){
    Data * data = NULL;
    while (!isEmpty(queue)){
        data = get(queue);
        printf("Data : %d Result : %c\n", data->data, data->result);
    }
}

int main () {
    
    Queue queue;
    create(&queue);
    initQueue(&queue);
    showQueue(&queue);
    
    return 0;
}