#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STR 80
#define PATH_PALABRAS "palabras.txt"
#define PATH_MORE_CONSONANTS "mas_consonantes.dat"
#define WRITE "w"
#define WRITE_B "wb"
#define READ "r"
#define READ_B "rb"

typedef struct {
    char word [MAX_STR + 1];
}Word;

FILE * fileOpen (char * path, char * mode){
    FILE * pFile = fopen(path, mode);
    if(pFile == NULL){
        printf("ERROR AL ABRIR EL ARCHIVO\n");
        exit(EXIT_FAILURE);
    }
    return pFile;
}

bool isVowels (char letter){
    return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u';
}

int quantityVowels (char * word){
    char * wordAux = word;
    int quantity = 0;

    while(*wordAux){
       if(isVowels(*wordAux)){
            quantity ++;
       }
       wordAux ++;
    }
    return quantity;
}

void processFile () {
    FILE * pFileMoreConsonants = fileOpen(PATH_MORE_CONSONANTS, WRITE_B);
    char * line = (char*)malloc(sizeof(char) * MAX_STR + 1);
    FILE * pFileWord = fileOpen(PATH_PALABRAS, READ);
    int quantity = 0;
    int result = 0;
    Word word;

    while(fgets(line, MAX_STR, pFileWord) != NULL){//posee

        quantity = quantityVowels(line);//3
        result = strlen(line) - quantity;//5 - 3 = 2

        if(quantity > result ){
            strcpy(word.word, line);
            fwrite(&word, sizeof(Word), 1, pFileMoreConsonants);
        }
    }
    fclose(pFileWord);
    fclose(pFileMoreConsonants);
}

void showFile (){
    FILE * pFile = fileOpen(PATH_MORE_CONSONANTS, READ_B);
    Word word;
    fread(&word, sizeof(Word), 1, pFile);

    while(!feof(pFile)){
        printf("%s\n", word.word);
        fread(&word, sizeof(Word), 1, pFile);
    }
    fclose(pFile);
}

int main()
{
    processFile();
    showFile();
    return 0;
}
















