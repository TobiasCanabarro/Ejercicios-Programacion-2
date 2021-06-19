#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10

int main () {
    
    int a = 10;
    printf("Value : %d\n", a);
    printf("Dir : %d\n", &a);

    float b = 2.5;
    printf("Value : %.1f\n", b);
    printf("Dir : %d\n", &b);

    int arr[MAX];
    createArr(arr);

    printf("Value : ");
    for (int i = 0; i < MAX; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Dir : %d\n", arr);

    return 0;
}

void createArr (int arr[]) {

    for (int i = 0; i< MAX; i++){
        arr[i] = i;
    }
}
