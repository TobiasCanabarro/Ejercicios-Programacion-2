#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX_QUERIES 2
#define MAX_NAME 20
#define MAX_QUERY 20

#define SALARY "salario"
#define HOLIDAYS "vacaciones"
#define COVERAGE_MEDICAL "coberturaMedica"

typedef struct {
    int legajo;
    char name[MAX_NAME];
    char query[MAX_QUERY];
}Person;

void typeQuery (Person person, int *quantQueriesSalary, int *quantQueriesHolidays, int *quantQueriesCoverageMedical) {

    if(strcmp(person.query, SALARY) == 0){
        *quantQueriesSalary = *quantQueriesSalary + 1;
    }
    if(strcmp(person.query, HOLIDAYS) == 0){
        *quantQueriesHolidays =  *quantQueriesHolidays + 1;
    }
    if(strcmp(person.query, COVERAGE_MEDICAL) == 0){
        *quantQueriesCoverageMedical = *quantQueriesCoverageMedical + 1;
    }
}

int lowLegajo (Person * person) {
    int lowLegajo = person->legajo;

    for (int i = 0; i< MAX_QUERIES; i++) {
        if(person->legajo < lowLegajo){
            lowLegajo = person->legajo;
        }
    }
    return lowLegajo;
}

void showPeoplesData (Person * person) {
    
    for(int i = 0; i < MAX_QUERIES; i ++) {
        printf("Legajo : %d\n", person->legajo);
        printf("Name : %s\n", person->name);
        printf("Query : %s\n", person->query);
        person++;
    }
}

Person * initQueries () {
    return (Person*)malloc(sizeof(Person) * MAX_QUERIES);
}

Person setPerson (Person * person, int i) {
    printf("Name : ");
    scanf("%s", person->name);
    printf("Type query : ");
    scanf("%s", person->query);
    person->legajo = i + 1;
}


int main () {
    
    Person * people = initQueries();
    int quantQueries = 0;
    int quantQueriesSalary = 0;
    int quantQueriesHolidays = 0;
    int quantQueriesCoverageMedical = 0;

    Person * aux = people;

   for (int i = 0; i < MAX_QUERIES; i++){
        setPerson(aux, i);
        typeQuery(*aux, &quantQueriesSalary, &quantQueriesHolidays, &quantQueriesCoverageMedical);
        quantQueries++;
        aux ++;
    }

    showPeoplesData(people);

    printf("quantQueries : %d\n", quantQueries);
    printf("quantQueriesSalary : %d\n", quantQueriesSalary);
    printf("quantQueriesHolidays : %d\n", quantQueriesHolidays);
    printf("quantQueriesCoverageMedical : %d\n", quantQueriesCoverageMedical);
    printf("Low legajo : %d\n", lowLegajo(people));

    return 0;
}

