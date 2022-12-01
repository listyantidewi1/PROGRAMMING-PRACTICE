#include<stdio.h>
#include<cs50.h>


// A struct to represent a student
typedef struct
{
    string name;
    int score;
} student;


int main(void)
{
    // Declare an array for four students
    student students[4] = {
        {"Chris", 67},
        {"Harry", 91},
        {"Hermione", 99},
        {"Ron", 85}
    };

    printf("The following students got a score of 90 or better!: \n");

    // *** TODO: Print the names of the students who got a 90 or better ***

}