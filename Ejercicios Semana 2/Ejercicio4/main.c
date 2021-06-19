#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_NAME 20

typedef struct {
    char name[MAX_NAME + 1];
    int age;
}Person;

Person * newPerson(char name[], int age){
    Person * person = (Person*)malloc(sizeof(Person));
    strcpy(person->name, name);
    person->age = age;
    return person;
}

void feature(Person * person){
    printf("Name : %s\n", person->name);
    printf("Age %d\n", person->age);
}

void chageValues (Person * person) {
    feature(person);
    strcpy(person->name, "Jorge");
    person->age = 30;
}

int main () {
    
    Person * person = newPerson("Tobias", 22);
    chageValues(person);
    feature(person);

    return 0;
}

