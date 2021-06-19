#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 10

int main () {
    
    char * myPtr = (char*)malloc(sizeof(char) * MAX);

    initMyPtr(myPtr);

    printf("Cadena : %s\n", myPtr);
    printf("Direccion del puntero : %s\n", &myPtr);
    printf("Direccione del puntero : %d\n ", &myPtr);
    printf("Valor del puntero : %s\n", myPtr);
    printf("Valor de la primera posicion : %c\n", myPtr[0]);
    myPtr++;
    printf("Valor de la primera posicion : %c\n", myPtr[0]);

    return 0;
}
 
void initMyPtr (char * myPtr){
    strcpy(myPtr, "hola"); 
}