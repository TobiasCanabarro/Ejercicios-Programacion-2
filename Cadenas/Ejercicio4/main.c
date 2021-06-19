#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX 80
#define EN "eng"
#define ARG "arg"

bool isNumber (char num) {
    return num >= 48 && num <= 57;
}

char * formatNumberEn (char * str) {
    char * strFinal = (char*)malloc(sizeof(char) * MAX + 1);

    char * auxStrFinal = strFinal;
    char * auxStr = str;

    while (*auxStr){

        if(isNumber(*auxStr)){
            *auxStrFinal = *auxStr; 
        }
        else if(*auxStr == '.'){
            *auxStrFinal = ',';
        }
        else if (*auxStr == ','){
             *auxStrFinal = '.';
        }
        
        auxStr++;
        auxStrFinal++;
    }
    *auxStrFinal = '\0';
    return strFinal;
}

char * formatNumberArg (char * str) {
    char * strFinal = (char*)malloc(sizeof(char) * MAX + 1);

    char * auxStrFinal = strFinal;
    char * auxStr = str;

    while (*auxStr){
        
        if(isNumber(*auxStr)){
            *auxStrFinal = *auxStr; 
        }
        else if(*auxStr == ','){
            *auxStrFinal = '.';
        }
        else if (*auxStr == '.'){
             *auxStrFinal = ',';
        }
        printf("%c", *auxStrFinal);
        auxStr++;
        auxStrFinal++;
    }
    *auxStrFinal = '\0';
    return strFinal;
}

char * formatNumber (char * str, char * separator) {

    char * strFinal = NULL;

   if (strcmp(separator, EN) == 0){
       strFinal = formatNumberEn (str);
   }else {
       strFinal = formatNumberArg(str);
   }

   return strFinal;
}

int main () {
    
    char * str = (char*)malloc(sizeof(char) * MAX + 1);
    char * separator = (char*)malloc(sizeof(char) * MAX + 1);

    strcpy(str, "1,050,214.56");
    strcpy(separator, ARG);

    printf("%s\n", formatNumber(str, separator));

    return 0;
}