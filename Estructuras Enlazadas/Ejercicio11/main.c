#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_STACK 10

typedef struct node {
    int i;
    struct node *ste;
}Node;

typedef struct {
    Node * front;
    Node * end;
}Queue;

Queue newQueue (){
    Queue queue;
    queue.front = NULL;
    queue.end = NULL;
    return queue;
}

void add (Queue * queue, int i) {
    Node * node = (Node*)malloc(sizeof(Node));
    node->i = i;
    node->ste = NULL;

    if(queue->front == NULL) {
        queue->front = node;
    }else {
        queue->end->ste = node;
    }
    queue->end = node;
}

int get (Queue * queue){
    Node *aux = queue->front;
    int i = aux->i;
    queue->front = aux->ste;

    if(queue->front == NULL){
        queue->end = NULL;
    }
    free(aux);
    return i;
}

bool isEmpty (Queue * queue){
    return queue->front == NULL && queue->end == NULL;
}

void initQueue(Queue * queue){
    for (int i = 0; i < MAX_STACK; i++){
        add(queue, i);
    } 
}

int quantNode (Queue * queue){
    int count = 0;
    int i = 0;
    while (!isEmpty(queue)){
        get(queue);
        count ++;
    }
    return count;
}

int main () {

    Queue queue = newQueue();
    initQueue(&queue);
    printf("Quant node : %d\n", quantNode(&queue));

    return 0;
}