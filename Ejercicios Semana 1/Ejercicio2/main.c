#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define CUT_NUM -1

int main () {

    int num = setNum();
    int may = num;
    int men = num;

    int acum = 0;
    int quant = 0;

    while (num != CUT_NUM) {
        acum += num;
        quant ++;

        if(num > may) {
            may = num;
        }
        if(num < men){
            men = num;
        }
        num = setNum();
        
    }

    printf("Mayor : %d\n", may);
    printf("Menor : %d\n", men);
    printf("Prom : %d\n", calculateAvg(acum, quant));

    return 0;
}

int setNum () {
    int num = 0;
    printf("Ingrese un numero : ");
    scanf("%d", &num);
    return num;
}

int calculateAvg (int acum, int quant) {
    return acum / quant;
}