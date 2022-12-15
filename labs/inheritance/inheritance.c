// Simulate genetic inheritance of blood type

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>


// Each person has two ortu and two alleles
typedef struct person
{
    struct person *ortu[2];
    char alleles[2];
}
person;

const int generasi = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generasi);
void print_family(person *p, int generasi);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generasi
    person *p = create_family(generasi);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generasi`
person *create_family(int generasi)
{
    // Allocate memory for new person
    person *new_person = malloc(sizeof(person));

    if (new_person == NULL)
    {
        printf("Memory error while creating new person.\n");
        return NULL;
    }

    // If there are still generasi left to create
    if (generasi > 1)
    {
        // Create two new ortu for current person by recursively calling create_family
        person *parent0 = create_family(generasi - 1);
        person *parent1 = create_family(generasi - 1);

        // Set parent pointers for current person
        new_person->ortu[0] = parent0;
        new_person->ortu[1] = parent1;

        // Randomly assign current person's alleles based on the alleles of their ortu
        new_person->alleles[0] = parent0->alleles[rand() % 2];
        new_person->alleles[1] = parent1->alleles[rand() % 2];
    }

    // If there are no generasi left to create
    else
    {
        // Set parent pointers to NULL
        new_person->ortu[0] = NULL;
        new_person->ortu[1] = NULL;

        // Randomly assign alleles
        new_person->alleles[0] = random_allele();
        new_person->alleles[1] = random_allele();
    }

    // Return newly created person
    return new_person;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Free ortu recursively
    free_family(p->ortu[0]);
    free_family(p->ortu[1]);

    // Free child
    free(p);
}

// Print each family member and their alleles.
void print_family(person *p, int generasi)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generasi * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    if (generasi == 0)
    {
        printf("Child (generasi %i): blood type %c%c\n", generasi, p->alleles[0], p->alleles[1]);
    }
    else if (generasi == 1)
    {
        printf("Parent (generasi %i): blood type %c%c\n", generasi, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generasi - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (generasi %i): blood type %c%c\n", generasi, p->alleles[0], p->alleles[1]);
    }

    // Print ortu of current generasi
    print_family(p->ortu[0], generasi + 1);
    print_family(p->ortu[1], generasi + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}