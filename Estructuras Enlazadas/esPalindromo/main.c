#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    char letter;
    struct node *ste;
}Node;

typedef struct {
    Node * front;
    Node * end;
}Queue;

void add (Queue * queue, char letter){
    Node * node = (Node*)malloc(sizeof(Node));
    node->letter = letter;
    node->ste = NULL;

    if(queue->front == NULL){
        queue->front = node;
    }
    else {
        queue->end->ste = node;
    }
    queue->end = node;
}

char get (Queue * queue){
    Node * nodeAux = queue->front;
    char letter = nodeAux->letter;
    queue->front = nodeAux->ste;
    if(queue->front == NULL){
        queue->end = NULL;
    }
    free(nodeAux);
    return letter;
}

bool isEmptyQueue (Queue * queue){
    return queue->front == NULL && queue->end == NULL;
}

void showQueue (Queue * queue){
	while(!isEmptyQueue(queue)){
		printf("%c", get(queue));
	}
	printf("\n");
}



void push (Node ** stack, char dato){
    Node * node = (Node *)malloc(sizeof(Node));
    node->letter = dato;
    node->ste = NULL;
    node->ste = *stack;
    *stack = node;
}

char pop (Node ** stack){
    Node * nodeAux = *stack;
    char dato = nodeAux->letter;
    *stack = (*stack)->ste;
    free(nodeAux);
    return dato;
}

void showStack (Node ** stack){
	while(*stack){
		printf("%c", pop(stack));
	}
	printf("\n");
}

void initQueue (Queue * queue, char * word){
    queue->end = NULL;
    queue->front = NULL;

    while(*word){
        add(queue, *word);
        word++;
    }
}



void initStack (Node ** stack, Queue queue){

    while(!isEmptyQueue(&queue)){

        Node * nodeAux = queue.front;
        char letter = nodeAux->letter;
        queue.front = nodeAux->ste;

        if(queue.front == NULL){
            queue.end = NULL;
        }

        push(stack, letter);
    }
    //queue = &newQueue;
}

bool isPalindrome (Queue * queue){
    Node * stack = NULL;
    initStack(&stack, *queue);
    bool value = true;

    while(!isEmptyQueue(queue) && value){
        if(get(queue) != pop(&stack)) {
            value = false;
        }
    }

    return value;
}

char * ultPos (char * word){
    char * ultPos = NULL;
    char * aux = word;
    while(*aux){
        ultPos = aux;
        aux ++;
    }
    return ultPos;
}

bool isPalindromePtr (char * word){
   char * ultPosition = ultPos(word);
   char * aux = word;
   bool value = true;
   while(*aux && value){
        if(*aux != *ultPosition){
            value = false;
        }
        aux ++;
        ultPosition--;
   }
   return value;
}

int main()
{
    char * result = (char*)malloc(sizeof(char) * 80);
    strcpy(result, "No es palindromo!");

    if (isPalindromePtr("eee")){
        strcpy(result, "Es palindromo!");
    }
    printf("%s\n", result);


    return 0;
}
