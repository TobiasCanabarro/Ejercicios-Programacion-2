#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 80

char * invStr (char * str) {
    char * auxStr = str;
    char * invStr = (char*)malloc(sizeof(char)* MAX + 1);
    char * auxInv = invStr;
    
    int n = strlen(str);

    for (int i = 0; i < n ; i++) {
        *auxInv = auxStr[n - 1 - i];
        auxInv++;
    }
    *auxInv = '\0';
    
    return invStr;
}

int main () {
    
    char * str = (char*)malloc(sizeof(char)* MAX + 1);
    strcpy(str, "Hola");

    printf("%s\n",  invStr(str));

    return 0;
}

