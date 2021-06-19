#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_IP 15
#define MAX_POINT 4
#define MAX_NUM 3

bool isNumber (char num){
    return num >= 48 && num <= 57;
}

bool isPoint (char dig){
    return dig == '.';
}

bool isValidIp (char * ip){
    char * auxIp = ip;
    int countPoint = 0;
    int countNum = 0;
    bool value = true;

    while (*auxIp && value){
        printf("%c\n", *auxIp);
        if(isNumber(*auxIp)){
            countNum ++;
        }else if(isPoint(*auxIp)) {
            value = countNum > 0 && countNum <= MAX_NUM;
            countNum = 0;
            countPoint++;
        }
        else {
            value = false;
        }
        auxIp++;
    }
    return value && countPoint == MAX_POINT;
}

int main () {
    
    char * ip = (char*)malloc(sizeof(char)* MAX_IP + 1);
    strcpy(ip, "192.168.1.2a");

    char * result = (char*)malloc(sizeof(char)* MAX_IP + 1);
    strcpy(result, "No es una ip valida!\n");

    if( isValidIp(ip) ){
       strcpy(result, "Es una ip valida!\n"); 
    }
  
    printf("%s\n", result);

    return 0;
}

