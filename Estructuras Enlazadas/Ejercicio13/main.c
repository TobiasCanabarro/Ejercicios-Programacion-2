#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_NODE 80
#define LIMIT_NODE 100

typedef struct node {
    int i;
    struct node *ste;
}Node;

typedef struct {
    Node *front;
    Node *end;
}Queue;

Queue newQueue (){
    Queue queue;
    queue.end = NULL;
    queue.front = NULL;
    return queue; 
}

void add (Queue * queue, int i){
    Node * node = (Node*)malloc(sizeof(Node));
    node->i = i;
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
    int i = aux->i;
    queue->front = aux->ste;

    if(queue->front == NULL){
        queue->end = NULL;
    }
    free(aux);
    return i;
}

bool isEmpty(Queue * queue){
    return queue->front == NULL && queue->end == NULL;
}

void push (Node ** stack, int i){
    Node * node = (Node*)malloc(sizeof(Node));
    node->i = i;
    node->ste = NULL;
    node->ste = *stack;
    *stack = node;
}

int pop (Node ** stack){
    Node * aux = *stack;
    int i = aux->i;
    *stack = (*stack)->ste;
    free(aux);
    return i;
}

void fillStack (Node ** stack, Queue * queue){
    while (!isEmpty(queue)) {
        push(stack, get(queue));   
    }
}

void fillQueue (Queue * queue){
    for (int i = 0; i < MAX_NODE; i++){
        add(queue, i);
    }
}

Queue quantNodeQueue (Queue * queue, int *quantNode){
    Queue  queueAux = newQueue();
    int count = 0;
    while(!isEmpty(queue)){
        add(&queueAux, get(queue));
        count ++;
    }
    *quantNode = count;
    return queueAux;
}

Queue invQueue (Queue * queue){
    Node * stack = NULL;
    Queue invQueue = newQueue();
    fillStack(&stack, queue);

    while(stack != NULL){
        add(&invQueue, pop(&stack));
    }
    return invQueue;
}

void showQueue (Queue * queue){
    while (!isEmpty(queue)){
        printf("%d ", get(queue));
    }
}

int main () {  

    Queue queue = newQueue();
    fillQueue(&queue);
    int quantNode = 0;
    queue = quantNodeQueue(&queue, &quantNode);

    if(quantNode < LIMIT_NODE) {
        queue = invQueue(&queue);
    }

    showQueue(&queue);

    return 0;
}