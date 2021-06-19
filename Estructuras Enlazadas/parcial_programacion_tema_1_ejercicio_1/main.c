#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_STR 80
#define PATH_PRODUCTS "productos.dat"
#define PATH_ORDER "pedidos.txt"
#define PATH_PRODUCTS_LOST "productos_perdidos.dat"

typedef struct {
    int prodCode;
    char description[MAX_STR + 1];
    float price;
    int stock;
}Prod;

typedef struct {
    int date;
    int prodCode;
    int quantity;
}Order;

typedef struct {
    int prodCode;
    float total;
    int quantLost;
    int date;
}lostProd;

typedef struct prod {
    Prod * product;
    struct prod *ste;
}NodeProd;

typedef struct node{
    int prodCode;
    struct node *ste;
}Node;

typedef struct nodeMonth {
    int month;
    float total;
    struct nodeMonth *ste;
}Month;

FILE * fileOpen(char * path, char * mode){
    FILE * pFile = fopen(path, mode);
    if(pFile == NULL){
        printf("ERROR AL ABRIR EL ARCHIVO\n");
        exit(EXIT_FAILURE);
    }
    return pFile;
}

Prod newProd (int prodCode, char * description, float price, int stock){
    Prod prod;
    prod.prodCode = prodCode;
    strcpy(prod.description, description);
    prod.price = price;
    prod.stock = stock;
    return prod;
}

lostProd newLostProd (int prodCode, int date, float total, int quantLost){
    lostProd lostProd;
    lostProd.prodCode = prodCode;
    lostProd.date = date;
    lostProd.quantLost = quantLost;
    lostProd.total = total;
    return lostProd;
}

void createProd(){
    FILE * pFile = fileOpen(PATH_PRODUCTS, "wb");
    Prod prod;

    prod = newProd(1, "harina", 10.5, 1);
    fwrite(&prod, sizeof(Prod), 1, pFile);

    prod = newProd(2, "manteca", 20.2, 2);
    fwrite(&prod, sizeof(Prod), 1, pFile);

    prod = newProd(3, "agua", 5.23, 1);
    fwrite(&prod, sizeof(Prod), 1, pFile);

    fclose(pFile);
}

void createOrder(){
     FILE * pFile = fileOpen(PATH_ORDER, "w");
    char * buffer = (char*)malloc(sizeof(char) * MAX_STR + 1);
    strcpy(buffer, "10/02/21,1,1,");//fecha, prodCode, quantity
    fputs(buffer, pFile);
    strcpy(buffer, "10/01/21,2,3,");
    fputs(buffer, pFile);
    strcpy(buffer,"10/01/21,3,3,");
    fputs(buffer, pFile);
    strcpy(buffer, "10/03/21,1,2,");
    fputs(buffer, pFile);
    fclose(pFile);
}

void parseBufferProd (Prod * prod, char * buffer){
    //prodCode, description, price, strock
    prod->prodCode = atoi(strtok(buffer, ","));
    strcpy(prod->description, strtok(NULL, ","));
    prod->price = atof(strtok(NULL, ","));
    prod->stock = atoi(strtok(NULL, ","));
}

void parseBufferOrder(Order * order, char * buffer){
    order->date = atoi(strtok(buffer, ","));
    order->prodCode = atoi(strtok(NULL, ","));
    order->quantity = atoi(strtok(NULL, ","));
}

void showOrder (Order * order){
    printf("Date : %d Product code : %d Quantity : %d\n", order->date, order->prodCode, order->quantity);
}

void showProd(Prod * prod){
    printf("Description : %s Price : %2.f Stock : %d Product code : %d\n", prod->description, prod->price, prod->stock, prod->prodCode);
}

void showFileOrder (){
    FILE * pFile = fileOpen(PATH_ORDER, "r");
    char * buffer = (char*)malloc(sizeof(char) * MAX_STR + 1);
    Order order;
    while(fgets(buffer, MAX_STR, pFile)!= NULL){
        parseBufferOrder(&order, buffer);
        showOrder(&order);
        printf("%s\n", buffer);
    }
    fclose(pFile);
}

void showFileProd(){
    FILE * pFile = fileOpen(PATH_PRODUCTS, "rb");
    Prod prod;

    fread(&prod, sizeof(Prod), 1, pFile);
    while(!feof(pFile)){

        showFileProd(&prod);
        fread(&prod, sizeof(Prod), 1, pFile);
    }

    fclose(pFile);
}

void insertOrderMonth (Month ** list, float total, int month){
    Month * node = (Month*)malloc(sizeof(Month));
    node->month = month;
    node->total = total;
    node->ste = NULL;

    Month * listAux = NULL;
    Month * nodePrev = NULL;

    while(listAux != NULL && listAux->month < month){
        nodePrev = listAux;
        listAux = listAux->ste;
    }
    if(nodePrev == NULL){
        *list = node;
    }
    else {
        nodePrev->ste = node;
    }
    node->ste = listAux;
}

Month * searchMonth (Month ** list, int month){
    Month * listAux = *list;
    while(listAux != NULL && listAux->month != month){
        listAux = listAux->ste;
    }
    return listAux;
}

float deleteMonth (Month ** list){
    Month * nodeAux = *list;
    float total = nodeAux->total;
    *list = (*list)->ste;
    free(nodeAux);
    return total;
}

void insertOrderedOrder(Node ** list, int prodCode){
    Node * node = NULL;
    node->ste = NULL;
    node->prodCode = prodCode;

    Node * listAux = *list;
    Node * nodePrev = NULL;
    while(listAux != NULL && listAux->prodCode < prodCode){
        nodePrev = listAux;
        listAux = listAux->ste;
    }
    if(nodePrev == NULL){
        *list = node;
    }
    else {
        nodePrev->ste = node;
    }
    node->ste = listAux;
}

void insertOrderedProd(NodeProd ** list, Prod * prod){
    NodeProd * node = NULL;
    node->product = prod;
    node->ste = NULL;

    NodeProd * listAux = *list;
    NodeProd * nodePrev = NULL;

    while(listAux != NULL && listAux->product->prodCode < prod->prodCode){
        nodePrev = listAux;
        listAux = listAux->ste;
    }
    if(nodePrev == NULL){
        *list = node;
    }
    else {
        nodePrev->ste = node;
    }
    node->ste = listAux;
}

int deleteFirst(Node ** list){
    Node * nodeAux = *list;
    int prodCode = nodeAux->prodCode;
    *list = (*list)->ste;
    free(nodeAux);
    return prodCode;
}

bool isEmpty(Node * list){
    return list == NULL;
}

NodeProd * searchProd (NodeProd ** list, int prodCode){
    NodeProd * listAux = *list;
    while(listAux != NULL && listAux->product->prodCode != prodCode){
        listAux = listAux->ste;
    }
    return listAux;
}

void loadProdList (NodeProd ** list){
    char * buffer = (char*)malloc(sizeof(char) * MAX_STR + 1);
    FILE * pFileProd = fileOpen(PATH_PRODUCTS, "rb");
    Prod prod;

    fwrite(&prod, sizeof(Prod), 1, pFileProd);
    while(fgets(buffer, MAX_STR, pFileProd)){
            parseBufferProd(&prod, buffer);
            insertOrderedProd(list, &prod);
    }
    fclose(pFileProd);
}

//retorna el stock
int calculateStock(Prod * prod, int requestQuantity){
    int result = prod->stock - requestQuantity;// stock 2 requerido 3
    if(result < 0){
        result = result * -1;
    }
    return result;
}

float calculateLoss (int lostStock, float priceProd){
    return lostStock * priceProd;
}

void addTotalMonth (Month ** list, float total, int month){
    Month * node = searchMonth(list, month);
    if(node == NULL){
        insertOrderMonth(list, total, month);
    }
    else {
        node->total += total;
    }
}

int getMonth (int date){
    return (date/10000) % 100;
}

Month * getMonthMostLosses (Month ** list){
    Month * listAux = *list;
    Month * mostLoss = *list;
    Month * node = NULL;

    while(listAux != NULL){
        node = listAux;
        if(mostLoss->total > node->total){
            mostLoss = node;
        }
        listAux = listAux->ste;
        free(node);
    }
    return mostLoss;
}

//monthList En esta lista se carga los totales de cada mes
void doOrder (Month ** monthList){

    char * bufferOrder = (char*)malloc(sizeof(char) * MAX_STR + 1);
    FILE * pFileOrder = fileOpen(PATH_ORDER, "r");
    FILE * pFileProd = fileOpen(PATH_PRODUCTS, "r+");
    FILE * pFileLostProd = fileOpen(PATH_PRODUCTS_LOST, "wb");

    NodeProd * prodList = NULL;
    loadProdList(&prodList);//carga el prodCode de los prooductos en una lista.
    NodeProd * node = NULL;
    lostProd lostProd;

    int updateStock = 0;
    int totalLoss = 0;
    Order order;
    Prod prod;

    while(fgets(bufferOrder, MAX_STR, pFileProd)){

        parseBufferOrder(&order, bufferOrder);//parsea una linea del archivo de pedidos

        node = searchProd(&prodList, order.prodCode);//busca el producto pedido en la lista de productos.
        fseek(pFileProd, sizeof(Prod) * node->product->prodCode, SEEK_SET);//se posiciona en el archivo de productos

        updateStock = calculateStock(&prod, order.quantity);//calcula el stock final del producto
        prod.stock = updateStock;
        fwrite(&prod, sizeof(Prod), 1, pFileProd);//actualiza el archivo de productos con el stock final

        if(updateStock > 0){//en caso de que el stock sea x > 0, significa que falto stock
            totalLoss = calculateLoss(updateStock, prod.price);
            lostProd = newLostProd(prod.prodCode, order.date, totalLoss, updateStock);//int prodCode, int date, float total, int quantLost
            fwrite(&lostProd, sizeof(lostProd), 1, pFileLostProd);//escribe en el archivo de productos perdidos
            addTotalMonth(monthList, totalLoss, getMonth(order.date));
        }
    }
    fclose(pFileOrder);
    fclose(pFileProd);
    fclose(pFileLostProd);
}

int main()
{
    //Recorrer el archivo de productos
    //Recorrer el archivo de pedidos
    //por cada pedido ver en el archivo de productos si hay stock y actualizar el archivo de productos;
    //en caso de que no haya stock agregarlo en la lista de productos perdidos
    //Luego recorrer la lista, sacar el mes que mas perdida hubo e ir agregando los datos al archivo de productos perdidos.
    Month * monthList = NULL;
    doOrder(&monthList);
    Month * monthMostLosses = getMonthMostLosses(&monthList);
    printf("Month %d, Total : %.2f", monthMostLosses->month, monthList->total);
    free(monthList);
    return 0;
}













































