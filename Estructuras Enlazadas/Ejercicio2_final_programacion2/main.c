#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int dato;
    struct node *ste;
}Node;

typedef struct {
    Node * front;
    Node * end;
}Queue;

void push (Node ** stack, int dato){
    Node * node = (Node *)malloc(sizeof(Node));
    node->dato = dato;
    node->ste = NULL;
    node->ste = *stack;
    *stack = node;
}

int pop (Node ** stack){
    Node * nodeAux = *stack;
    int dato = nodeAux->dato;
    *stack = (*stack)->ste;
    return dato;
}

bool isEmptyStack (Node * stack){
    return stack == NULL;
}

void initQueue (Queue * queue){
    queue->front = NULL;
    queue->end = NULL;
}

void add (Queue * queue, int dato){
    Node * node = (Node*)malloc(sizeof(Node));
    node->dato = dato;
    node->ste = NULL;

    if(queue->front == NULL){
        queue->front = node;
    }
    else {
        queue->end->ste = node;
    }
    queue->end = node;
}

int get (Queue * queue){
    Node * nodeAux = queue->front;
    int dato = nodeAux->dato;
    queue->front = nodeAux->ste;
    if(queue->front == NULL){
        queue->end = NULL;
    }
    return dato;
}

bool isEmptyQueue (Queue * queue){
    return queue->front == NULL && queue->end;
}

Queue concat(Node ** stack, Queue * queue){
    Queue newQueue;
    initQueue(&newQueue);
    int dato = 0;

    while(!isEmptyStack(*stack)){
        dato = pop(stack);
        if(dato != 0){
            add(&newQueue, dato);
        }
    }
    while(!isEmptyQueue(queue)){
        dato = get(queue);
        if(dato != 0){
            add(&newQueue, dato);
        }
    }
    return newQueue;
}

int main()
{
    Node * stack = NULL;
    Queue queue;
    initQueue(&queue);
    Queue newQueue = concat(&stack, &queue);
    showQueue()

    return 0;
}


















