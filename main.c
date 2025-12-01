#include <stdlib.h>
#include <stdio.h>

#define NAME_SIZE 50                //Maximun size for name array
#define MAX_PEOPLE 50               //people_array max cap
#define FIRST_LOWER_CASE 97         //Lower case a is 97 in ascci
#define CAPS_LOW_DIFF 32            //Distance between a lower case and a capital letter in ascii

#define NAME 1
#define AGE 2
#define HEIGHT 3

typedef struct Person {
    char name[NAME_SIZE];
    int age;
    double height;
} Person;


typedef struct People_array {
    Person data[MAX_PEOPLE];
    int size;
} People_array;


void print_array(People_array* arr, int operation) {
    switch (operation) {
    case NAME:
        for (int i = 0; i < arr->size; i++) {
            printf("%s\n", arr->data[i].name);
        }
        break;
    case AGE:
        for (int i = 0; i < arr->size; i++) {
            printf("%d\n", arr->data[i].age);
        }
        break;
    case HEIGHT:
        for (int i = 0; i < arr->size; i++) {
            printf("%f\n", arr->data[i].height);
        }
        break;
    }
}

int compare_by_name(const void* person1, const void* person2) {

    const Person *p1 = (const Person *)person1;
    const Person *p2 = (const Person *)person2;

    int letter1;
    int letter2;
    
    for (int i = 0; i < NAME_SIZE; i++) {
        
                
        if ((p1->name)[i] == 0) {return -1;}      //If name has ended without a conclusion save the smaller one ex: Juan and JuanJose, Juan goes first 
        if ((p2->name)[i] == 0) {return 1;}       //If two people have the same name the first one in the array goes first

        letter1 = (p1->name)[i];
        letter2 = (p2->name)[i];

        if (letter1 >= FIRST_LOWER_CASE) {  //If letter is lower case
            letter1 -= CAPS_LOW_DIFF;       //Convert to capital letter
        }
        if (letter2 >= FIRST_LOWER_CASE) {
            letter2 -= CAPS_LOW_DIFF;
        }   

        if (letter1 < letter2) {            //If letter1 goes first, person one goes first 
            return -1;
        } 
        if (letter1 > letter2) {            //If letter2 goes first, person2 goes first
            return 1;
        }
        //If they are equal, loop continues
    }
    return -1;                              //If names are equal and equal in size to NAME_SIZE, first one in the array goes first
}

int compare_by_age(const void* person1, const void* person2) {
    const Person *p1 = (const Person *)person1;
    const Person *p2 = (const Person *)person2;
    if (p1->age < p2->age) {    //If person1 is younger, they go first
        return -1;
    }
    if (p1->age > p2->age) {    //If person2 is younger, they go first
        return 1;
    }
    return -1;      //If same age, person1 goes first
}

int compare_by_height(const void* person1, const void* person2) {
    const Person *p1 = (const Person *)person1;
    const Person *p2 = (const Person *)person2;
    if (p1->height < p2->height) {    //If person1 is shorter, they go first
        return -1;
    }
    if (p1->height > p2->height) {    //If person2 is shorted, they go first
        return 1;
    }
    return -1;      //If same height, person1 goes first
}
int main() {
    Person andres = (Person) {
    .name =  "Andres",
    .age = 19,
    .height = 183,
    };
    Person juanjose = (Person) {
    .name =  "JuanJose",
    .age = 21,
    .height = 180,
    };
    Person santiago = (Person) {
    .name =  "Santiago",
    .age = 13,
    .height = 160,
    };
    Person matias = (Person) {
    .name =  "Matias",
    .age = 8,
    .height = 140,
    };
    Person carolina = (Person) {
    .name =  "Carolina",
    .age = 48,
    .height = 170,
    };
    Person roy = (Person) {
    .name =  "Roy",
    .age = 55,
    .height = 173,
    };

    People_array familia = {
    .data = {andres, juanjose, santiago, matias, carolina, roy},
    .size = 6,
    };
    printf("\nArray before sorting\n");
    print_array(&familia, NAME);
    qsort(familia.data, familia.size, sizeof(Person), compare_by_name);
    printf("\nArray after sorting by name\n");
    print_array(&familia, NAME);
 
    qsort(familia.data, familia.size, sizeof(Person), compare_by_age); 
    printf("\nArray after sorting by age\n");
    print_array(&familia, NAME);

    qsort(familia.data, familia.size, sizeof(Person), compare_by_height); 
    printf("\nArray after sorting by height\n");
    print_array(&familia, NAME);

return 0;
}
