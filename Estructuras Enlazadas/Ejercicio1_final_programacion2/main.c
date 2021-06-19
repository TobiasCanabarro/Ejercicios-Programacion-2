#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_COD_ENTITY 10
#define MAX_COD_BUSSINESS_NAME 100

#define PATH_QUOTATION_DOLAR "cotizacion_dolat.txt"
#define PATH_ENTITIES "entidades.dat"

#define READ_FILE_B "rb+"
#define WRITE_FILE_B "wb"
#define READ_FILE_TXT "rb+"
#define WRITE_FILE_TXT "wb"
#define MONTH 12
#define MAX_BUFFER 256

typedef struct {
    char codEntity[MAX_COD_ENTITY + 1];
    int day;
    int month;
    float quotation;
}Bank;

typedef struct {
    char codEntity[MAX_COD_ENTITY + 1];
    int cuit;
    char businessName[MAX_COD_BUSSINESS_NAME + 1];
    float variation;
}Entity;

typedef struct{
    int month;
    char codEntity[MAX_COD_ENTITY + 1];
    char businessName[MAX_COD_BUSSINESS_NAME + 1];//razon social
    float quotationMin;
    float quotationMax;
    float valueAvg;//promedio
    float monthlyVariation;//ultima variacion mensual
}ResultEntity;

typedef struct node{
    int month;
    int count;
    ResultEntity * result;
    struct node *ste;
}Node;

ResultEntity newResultEntity (char codEntity[]){
    ResultEntity entity;
    strcpy(entity.codEntity, codEntity);

    //faltan los demas campos
    return entity;
}

FILE * fileOpen (char * path, char * mode){
    FILE * pFile = fopen(path, mode);
    if(pFile == NULL){
        printf("ERROR AL ABRIR EL ARCHIVO\n");
        exit(EXIT_FAILURE);
    }
    return pFile;
}

void insertOrdered(Node ** list, ResultEntity * result){
    Node * node = (Node*)malloc(sizeof(Node));
    node->result = result;
    node->ste = NULL;

    Node * listAux = *list;
    Node * nodePrev = NULL;
    while(listAux != NULL && listAux->month < result->month){
        nodePrev = listAux;
        listAux = listAux->ste;
    }
    if (nodePrev == NULL){
        *list = node;
    }
    else {
        nodePrev->ste = node;
    }
    node->ste = listAux;
}

Node * search(Node ** list, int month){
    Node * listAux = *list;
    while(listAux != NULL && listAux->result->month != month){
        listAux = listAux->ste;
    }
    return listAux;
}

void insertWithoutDuplicates (Node ** list, ResultEntity * result){
    Node * node = search(list, result->month);
    if(node != NULL){
        node->count ++;
        node->result->valueAvg = node->result->valueAvg / node->count ++;//saco el promedio
    }
    insertOrdered(list, result);
}

ResultEntity * deleteFirst(Node ** list){
    Node * nodeAux = *list;
    ResultEntity * result = nodeAux->result;
    *list = (*list)->ste;
    free(nodeAux);
    return result;
}

void parseBuffer (Bank * bank, char * buffer){
    strcpy(bank->codEntity, strtok(buffer, ";"));
    bank->day = atoi(strtok(NULL, ";"));
    bank->month = atoi(strtok(NULL, ";"));
    bank->quotation = atof(strtok(NULL, "\n"));
}

int calculateEntities (){
    FILE * pFile = fileOpen(PATH_ENTITIES, READ_FILE_B);
    fseek(pFile, 0, SEEK_END);
    int cantEntidades = ftell(pFile)/sizeof(Entity);
    fclose(pFile);
    return cantEntidades;
}

float calculateMonthlyVariation (float quotationMin, float quotationMax){
    return quotationMax - quotationMin;
}

void initEntities (Entity entities[]){
    FILE * pFile = fileOpen(PATH_ENTITIES, READ_FILE_B);
    int i = 0;
    Entity entity;
    fread(&entity, sizeof(Entity), 1, pFile);
    while(!feof(pFile)){
        entities[i] = entity;
        i ++;
        fread(&entity, sizeof(Entity), 1, pFile);
    }
    fclose(pFile);
}

void processFile (Node ** list, Entity entities[]){

    FILE * pFileBank = fileOpen(PATH_QUOTATION_DOLAR, READ_FILE_B);
    char buffer [MAX_BUFFER + 1];
    ResultEntity result;
    Bank bank;

    while(fgets(buffer, MAX_BUFFER, pFileBank)){
         parseBuffer(&bank, buffer);
         result = newResultEntity(bank.codEntity);
         insertWithoutDuplicates(list, &result);
    }

    fclose(pFileBank);
}

void monthlyQuote (Node ** list){
    ResultEntity * entity = NULL;
    while(*list){
        entity = deleteFirst(list);
        printf("Mes : %d\n", (*list)->month);
        printf("%s %f %f %f %f", entity->codEntity, entity->monthlyVariation,
            entity->quotationMin, entity->quotationMax, entity->valueAvg);
    }
}

void moreQuotation(Node ** list){
    ResultEntity  * resultEntity = deleteFirst(list);
    printf("%s %f %f %f %f", resultEntity->codEntity, resultEntity->monthlyVariation,
            resultEntity->quotationMin, resultEntity->quotationMax, resultEntity->valueAvg);

}

int main()
{
    Node * list = NULL;
    list->count = 0;

    Entity entities[calculateEntities()];
    initEntities(entities);
    processFile(&list, entities);
    monthlyQuote(&list);
    moreQuotation(&list);


    return 0;
}










