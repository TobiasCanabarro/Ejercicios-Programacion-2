#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_STR 80

typedef struct node {
    char word[MAX_STR + 1];
    struct node *ste;
}Node;


typedef struct {
    Node * front;
    Node * back;
}Queue;

void add (Queue * queue, char * word){
    Node * node = (Node*)malloc(sizeof(Node));
    strcpy(node->word, word);
    node->ste = NULL;

    if(queue->front == NULL){

    }
}

void createQueue (Queue * queue){
    queue->front = NULL;
    queue->back = NULL;
}

bool isEmpty(Queue * queue){
    return queue->front == NULL && queue->back == NULL;
}

char * get(Queue * queue){
    return NULL;
}

void initialQueue(Queue * queue){
    add(queue, "pepe");
    add(queue, "aaaa");
    add(queue, "trttt");
}

void insertFirst (Node ** list, char * word){

}

bool isVowel (char letter){
    return letter == 'a' && letter == 'e' && letter == 'i' && letter == 'o' && letter == 'u';
}

bool hasVowel(char * word){
    bool value = false;
    char * aux = word;

    while(*aux && !value){
        value = isVowel(*aux);
        aux ++;
    }
    return value;
}

Node * createList (Queue * queue){//necs
    Node * list = NULL;
    char * word = NULL;
    while(!isEmpty(queue)){
        word = get(&queue);
        if(hasVowel(word)){
            insertFirst(&list, word);
        }
    }
    return list;
}

int main()
{
    Queue queue;
    initialQueue(&queue);
    Node * list = createList(&queue);

    return 0;
}


















