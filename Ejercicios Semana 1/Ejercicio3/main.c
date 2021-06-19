#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_NAME 20
#define MAX_PEOPLE 2

typedef struct {
    char name [MAX_NAME];
    int age;
}Person;

int main () {
    Person * people[MAX_PEOPLE];
    initPeople(people);
    
    createPeople(people);
    showPeople(people);
    ordPeople(people);
    showPeople(people);

    return 0;
}

void initPeople(Person * people[]) {
    for (int i = 0; i < MAX_PEOPLE; i ++) {
        people[i] = (Person*)malloc(sizeof(Person));
    }
}

void createPeople (Person * people[]) {
    setPerson(people[0]);
    int i = 0;

   for (int i = 0; i < MAX_PEOPLE; i++) {
        i++;
        setPerson(people[i]);
    }
}

void setPerson (Person * person) {
    
    printf("Name : ");
    scanf("%s", person->name);
    printf("Age : ");
    scanf("%d", &person->age);

}

void showPeople (Person * people[]) {
    for (int i = 0; i < MAX_PEOPLE; i++) {
        printf("Name : %s, Edad : %d\n", people[i]->name, people[i]->age);
    }
}

void ordPeople (Person * people[]){
    Person * aux = (Person*)malloc(sizeof(Person));

    for (int i = 0; i < MAX_PEOPLE - 1; i++){
        for (int j = i + 1; j < MAX_PEOPLE - i; j++){

            if(people[i]->age > people[j]->age){
                aux = people[i];
                people[i] = people[j] ;
                people[j] = aux;
            }
        }
    }
}