
#include<stdio.h>
#include<stdlib.h>
#define MAX_POS 10

int main () {

    int array [MAX_POS];

    createArray(array);


    //modifyArray(array);

    showArray(array);

    showInvOrdArray(array);

    return 0;
}

void createArray (int array[]) {
    for (int i = 0;i < MAX_POS; i++) {
        array[i] = i;
    }
}

void modifyArray(int array[]) {
    int act = 0;
    int next = 0;

    for (int i = 0; i < MAX_POS - 1; i++) {

        act = array[i];
        next = array[i+1];
        
        array[i] = next;
        array[i+1] = act;
    }
}

void showArray (int array[]) {
    for (int i = 0; i < MAX_POS; i++){
        printf("%d", array[i]);
    }
    printf("\n");
}

void showInvOrdArray (int array[]){

    for (int i = 0; i < MAX_POS; i++){
        printf("%d", array[MAX_POS - 1 - i]); 
    }
    

}