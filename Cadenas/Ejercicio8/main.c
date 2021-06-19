#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 80
#define DELIMITER " "

char * strCatEquals (char * str1, char * str2){

    char * tokenStr1 = strtok(str1, DELIMITER);

    char * tokenStr2 = (char*)malloc(sizeof(char) * MAX + 1);
    memset(tokenStr2, '\0', MAX + 1);

    char * strResult = (char*)malloc(sizeof(char) * MAX * 2 + 2);
    memset(strResult, '\0', strlen(strResult));

    char * auxStr2 = str2;
    char *auxTokenStr2 = tokenStr2;

    while (tokenStr1 != NULL){
        
        while (*auxStr2 && *auxStr2 != ' '){
            *auxTokenStr2 = *auxStr2;
            auxStr2 ++; 
            auxTokenStr2 ++;
        }

        auxStr2++;

        if(strcmp(tokenStr1, tokenStr2) == 0){
            strcat(strResult, " ");
            strcat(strResult, tokenStr1);
        }
        memset(tokenStr2, '\0', MAX + 1);
        auxTokenStr2 = tokenStr2;
        tokenStr1 = strtok(NULL, DELIMITER);
    }

    return strResult;
}

int main () {
    
    char * str1 = (char*)malloc(sizeof(char) * MAX + 1);
    char * str2 = (char*)malloc(sizeof(char) * MAX + 1);

    strcpy(str1, "El futbol es un deporte que se juega con una pelota redonda.");
    strcpy(str2, "El rugby es un deporte que se juega con una pelota ovaldada.");

    printf("%s\n", strCatEquals(str1, str2));
    return 0;
}