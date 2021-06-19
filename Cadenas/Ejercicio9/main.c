#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 80
#define INIT -1
#define DELIMITER " "

int startAt (char * str1, char * str2){
    
    int pos = INIT;
    char * token1 = strtok(str1, DELIMITER);
    char * token2 = (char*)malloc(sizeof(char) * MAX + 1);
    char * auxToken2 = token2; 
    int quantEqual = 0;

    while (token1 != NULL){
        
        while (*token1){

           while(*str2){
                if(*token1 == *str2){
                   quantEqual ++; 
                }
               str2++;
           }

           if(quantEqual == strlen(str2)){
               
           }
           token1++;
        }

        auxToken2++;

      
    }

}

int main () {
    
    // char * str1 = (char*)malloc(sizeof(char) * MAX + 1);
    // char * str2 = (char*)malloc(sizeof(char) * MAX + 1);

    printf("Posicion : %d\n", startAt("Hola mundo", "mundo"));
    return 0;
}