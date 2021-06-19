#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_STR 80

int myStrLen (char * str) {
    char * aux = str;
    int len = 0;
    while (*aux){
        len++;
        aux++;
    }
    return len;
}

void myStrCpy (char * str, char *strCpy){
    char * auxStr = str;
    char *auxStrCpy = strCpy;

    while (*auxStr && *auxStrCpy){
        *auxStr = *auxStrCpy;
        auxStr++;
        auxStrCpy++;
    }
    *auxStr = '\0';
}

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

    myStrCpy(result, "No es palindromo");
    myStrCpy(str, "aaaba");
    int strLen = myStrLen(str);

    if( isPalindrome(str, strLen) ){
        myStrCpy(result, "Es palindromo");
    }
    
    printf("%s", result);

    return 0;
}




