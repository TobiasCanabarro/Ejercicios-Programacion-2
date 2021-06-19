#include <iostream>
#include <string.h>
#define MAX_STR 50
#define COD_SUB 6
#define MAX_SUB 40
#define SUBJ_A 'a'
#define SUBJ_C 'c'

using namespace std;

typedef struct {
    char codSub[COD_SUB + 1];
    char description[MAX_STR + 1];
    char quarter;
    char mode;
    char maxCapacity;
}Subject;

typedef struct {
    char codSub[COD_SUB + 1];
    int dni;
    char lastname [MAX_STR + 1];
    char name [MAX_STR + 1];
}Inscription;

typedef struct node {
    Inscription * inscription;
    node *ste;
}Node;

void insertAtEnd (Node ** list, Inscription * inscription){
    Node* node = (Node*)malloc(sizeof(Node));
    node->inscription = inscription;
    node->ste = NULL;
    Node * listAux = *list;

    while(listAux != NULL && listAux->ste != NULL){
        listAux= listAux->ste;
    }
    if(listAux == NULL){
        *list = node;
    } else {
        listAux->ste = node;
    }
}

FILE * fileOpen (const char * path, const char * mode){
    FILE * pFile = fopen(path, mode);
    if(pFile == NULL){
        printf("ERROR AL ABRIR EL ARCHIVO\n");
        exit(EXIT_FAILURE);
    }
    return pFile;
}

void initSubject (char * subjects[]) {
    FILE * pFile = fileOpen("materias.dat", "rb");
    Subject subject;
    fread(&subject, sizeof(Subject), 1, pFile);
    int i = 0;
    while(!feof(pFile) && i < MAX_SUB){
     strcpy(subjects[i], subject.codSub);
     fread(&subject, sizeof(Subject), 1, pFile);
     i ++;
    }
    fclose(pFile);
}

char * getSubject (){
    char * subject = (char*)malloc(sizeof(char) * MAX_SUB + 1);
    printf("Ingrese codigo de la materia : ");
    scanf("%s", subject);
    return subject;
}

void parseBuffer (Inscription * inscription, char * buffer){
    strcpy(inscription->codSub, strtok(buffer, ";"));
    strcat(inscription->codSub, "\0");
    inscription->dni = atoi(strtok(buffer, NULL));
    strcpy(inscription->lastname, strtok(buffer, NULL));
    strcat(inscription->lastname, "\0");
    strcpy(inscription->name, strtok(buffer, "\n"));
    strcat(inscription->name, "\0");
}

int searchPos (char * subjects[], char * codSub){
    for (int i = 0; i < MAX_SUB ; i++){
        if (strcmp(subjects[i], codSub) == 0){
            return i;
        }
    }
    return -1;
}

int parseCodSub (char * codSub){
    strtok(codSub, "-");
    return atoi(strtok(codSub, NULL));
}

void processFile (Node ** list, char * subjects[], Node * inscriptionSubjects[]) {

    initSubject(subjects);
    FILE * pFileSub = fileOpen("materias.dat", "rb+");
    FILE * pFileIns = fileOpen("inscripciones.txt", "r");
    FILE * pFileRejected = fileOpen("rechadaso.txt", "w");
    char * inscriptionSubject = getSubject();
    char buffer[MAX_STR * 4 + 1];
    Inscription inscription;
    Subject subject;
    int pos = 0;

    while(fgets(buffer, MAX_STR * 4, pFileIns)){
        parseBuffer(&inscription, buffer);
        if (strcmp(inscription.codSub, inscriptionSubject) == 0){
            pos = searchPos(subjects, inscription.codSub);
            if(pos != -1){
                fseek(pFileSub, sizeof(Subject) * pos, SEEK_SET);
                fread(&subject, sizeof(Subject), 1, pFileSub);

                if(subject.maxCapacity > 1){
                    subject.maxCapacity --;
                    insertAtEnd(&inscriptionSubjects[parseCodSub(inscription.codSub) - 1], &inscription);
                }
                else if (subject.mode == SUBJ_A && subject.maxCapacity > -10){
                    subject.maxCapacity --;
                }
                else {
                    fprintf(pFileRejected, "%s;%d;%s;%s\n", inscription.codSub, inscription.dni,
                            inscription.lastname, inscription.name);
                }
            }
        }
        fseek(pFileSub, sizeof(Subject) * pos, SEEK_SET);
        fwrite(&subject, sizeof(Subject), 1, pFileSub);
    }
    fclose(pFileRejected);
    fclose(pFileIns);
    fclose(pFileSub);
}

int main()
{
    Node * list = NULL;
    char * subject[MAX_SUB + 1];
    Node * inscriptionSubject[MAX_SUB];
    processFile(&list, subject, inscriptionSubject);
    //showList();

    return 0;
}
