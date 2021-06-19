#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 80
#define DELIMITER " "

int main () {
    
    char * str = (char*)malloc(sizeof(char)* MAX + 1);   
    strcpy(str, "puede ser pa aaaaaaaaaaaa");

      char * longestWord = (char*)malloc(sizeof(char)* MAX + 1);
    char * auxLongestWord = longestWord;

    char * auxStr = str;
    int quantLettersLongest = 0;
    int quant = 0;
    int quantWord = 0;

    char * letters = (char*)malloc(sizeof(char)* MAX + 1);

    char * auxLetters = letters;
    memset(auxLetters, MAX + 1,'\0');

    char * token = strtok(str, DELIMITER);

    while (token != NULL) {

        quant = strlen(token);

        if (quant > quantLettersLongest){
            quantLettersLongest = quant;
            strcpy(longestWord, token);
        }
        token = strtok(NULL, DELIMITER);
        quantWord ++;
    }

    printf("\nCantidad de palabras : %d\n", quantWord);
    printf("Palabra mas larga : %s\n", longestWord);
    printf("La cantidad que posee la palabra mas larga es de : %d\n", quantLettersLongest);

    return 0;
}