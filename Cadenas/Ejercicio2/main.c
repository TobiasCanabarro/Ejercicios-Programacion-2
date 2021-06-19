#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_STR 80

int calculatePos (int strLen, int i){
    return strLen - 1 - i;
}

char * ultPost (char * str){
    char * aux = str;
    char * pos = NULL;

    while (*aux) {
        pos = aux;
        aux++;
    }
    return pos;
}

bool isPalindrome (char * str, int strLen) {

    char * aux = str;
    char * auxUlt =  ultPost(str);
    bool value = false;
    int limit = strLen/2;

    while (*aux && !value && limit > 0) {  

        if(*aux != *auxUlt){
            value = true;
        }
        aux++;
        auxUlt--;
        limit--;
    }
    return !value;
}

int main () {
    
    char * str = (char*)malloc(sizeof(char)* MAX_STR + 1);
    char * result = (char*)malloc(sizeof(char)* MAX_STR + 1);

    strcpy(result, "No es palindromo");
    strcpy(str, "aaaba");
    int strLen = strlen(str);

    if( isPalindrome(str, strLen) ){
        strcpy(result, "Es palindromo");
    }
    
    printf("%s", result);

    return 0;
}




