#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main () {
    
    int a = 10;
    int * ptrA = &a;

    printf("Dir :%d\n", ptrA);
    printf("Value :%d\n", *ptrA);

    ptrA = (int*)malloc(sizeof(int));
    printf("Dir :%d\n", ptrA);
    printf("Value :%d\n", *ptrA);

    return 0;
}