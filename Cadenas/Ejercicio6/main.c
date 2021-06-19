#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 80

int myStrLen(char * str) {
    int quant = 0;
    char * auxStr = str;

    while (*auxStr){
        quant ++;
        auxStr ++;
    }
    return quant;
}

void myMemset (char * str, int len, char x){

    char * aux = str;
    for (int i = 0; i < len; i++){
        *aux = x;
        aux++;
    }
}

void myStrcpy (char * destStr, char * str){
    char * auxDest = destStr;
    char * auxStr = str;

    while (*auxDest && *auxStr){
        *auxDest = *auxStr;
        auxDest ++;
        auxStr ++;
    }
    *auxDest = '\0';
}

int main () {

    char * str = (char*)malloc(sizeof(char)* MAX + 1);   
    myStrcpy(str, "puede");

    char * longestWord = (char*)malloc(sizeof(char)* MAX + 1);
    char * auxLongestWord = longestWord;

    char * auxStr = str;
    int quantLettersLongest = 0;
    int quant = 0;
    int quantWord = 0;

    char * letters = (char*)malloc(sizeof(char)* MAX + 1);

    char * auxLetters = letters;
    myMemset(auxLetters, MAX + 1,'\0');

    while (*auxStr){

        if(*auxStr != ' '){
            *auxLetters = *auxStr;
            quant ++;
            auxLetters ++;      
        }else {

            if(quant > quantLettersLongest){
                quantLettersLongest = quant;
                *auxLetters = '\0';
                strcpy(longestWord, letters); 
            }
            memset(auxLetters, myStrLen(auxLetters),'\0');
            auxLetters = letters;
            quant = 0;
            quantWord ++;
        
        }
        
        
        auxStr++;
    }

    quantWord ++;
    if(quant > quantLettersLongest){
        quantLettersLongest = quant;
        *auxLetters = '\0';
        strcpy(longestWord, letters);  
    }

    printf("\nCantidad de palabras : %d\n", quantWord);

    printf("Palabra mas larga : %s\n", longestWord);
    printf("La cantidad que posee la palabra mas larga es de : %d\n", quantLettersLongest);

    return 0;
}