#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_QUEUE_A 10
#define MAX_QUEUE_B 20

typedef struct node {
    int num;
    struct node *ste;
}Node;

typedef struct {
    Node * front;
    Node * end;
}Queue;

Queue newQueue (){
    Queue queue;
    queue.end = NULL;
    queue.front = NULL;
    return queue;
}

void add (Queue * queue, int i){
    Node * node = (Node*)malloc(sizeof(Node));
    node->num = i;
    node->ste = NULL;

    if(queue->front == NULL){
        queue->front = node;
    }else {
        queue->end->ste = node;
    }
    queue->end = node;
}

int get (Queue * queue){
    Node * aux = queue->front;
    int i = aux->num;
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

void showQueue (Queue * queue) {
    while (!isEmpty(queue)){
        printf("%d ", get(queue));
    }
}

void initQueueA (Queue * queue){
    for (int i = 0; i < MAX_QUEUE_A; i++){
        add(queue, i);
    }
}

void initQueueB (Queue * queue){
    for (int i = MAX_QUEUE_A; i < MAX_QUEUE_B; i++){
        add(queue, i);
    }
}

void getAll (Queue * queueC, Queue * queueX){
    while (!isEmpty(queueX)){
        add(queueC, get(queueX));
    }
}

Queue queueCat (Queue * queueA, Queue * queueB){
    Queue queueC = newQueue();
    getAll(&queueC, queueA);
    getAll(&queueC, queueB);
    return queueC;
}

int main () {
    
    Queue queueA = newQueue();
    Queue queueB = newQueue();

    initQueueA(&queueA);
    initQueueB(&queueB);
    Queue queueC = queueCat(&queueA, &queueB);
    showQueue(&queueC);

    return 0;
}