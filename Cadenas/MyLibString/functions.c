#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "head.h"


int strlen (char * str){
    char * aux = str;
    int cont = 0;
    while (*aux){
        cont ++;
        aux++;
    }
    return cont;
}


