#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"file.h"

Data * newData (char * name, int legajo, int div){
    Data * data = (Data*)malloc(sizeof(Data));
    strcpy(data->nameLastname, name);
    data->legajo = legajo;
    data->div = div;
    return data;
}

void newRegister (FILE * pFile, char *name, int legajo, int div) {
    Data * data = newData(name, legajo, div);
    fwrite(data, sizeof(Data), 1, pFile);
}

FILE * fileOpen (char * path, char * mode){
    FILE * pFile = NULL;
    pFile = fopen(path, mode);
    if(pFile == NULL){
        printf("ERROR AL ABRIR EL ARCHIVO\n");
        exit(EXIT_FAILURE);
    }
    return pFile;
}

void createFile (){
    FILE * pFile = fileOpen("archivo.dat", "wb");
    newRegister(pFile, "pepeArgento", 2, 3);
    newRegister("tobiasCanabarro", 1, 2);
    newRegister("moniArgento", 2, 3);
}



















