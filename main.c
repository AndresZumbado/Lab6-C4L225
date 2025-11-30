#include <stdlib.h>
#include <stdio.h>

#define NAME_SIZE 50                //Maximun size for name array
#define FIRST_LOWER_CASE 97         //Lower case a is 97 in ascci
#define CAPS_LOW_DIFF 32            //Distance between a lower case and a capital letter in ascii

typedef struct Person {
    char name[NAME_SIZE];
    int age;
    double height;
} Person;

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
