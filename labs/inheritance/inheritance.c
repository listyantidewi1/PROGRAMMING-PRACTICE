// Simulate genetic inheritance of blood type

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//ini buat allele 2 buat setiap orang
typedef struct manusia
{
    struct manusia *parents[2];
    char alleles[2];
}
manusia;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

manusia *create_family(int generations);
void print_family(manusia *p, int generation);
void free_family(manusia *p);
char random_allele();

int main(void)
{
    // kasih bilangan acak
    srand(time(0));

    // buat sebuah family untuk tiga generasi
    manusia *p = create_family(GENERATIONS);

    // cetak keluarga
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// fungsi utk membuat keluarga
manusia *create_family(int generations)
{
    //alokasi memory untuk manusia baru
    manusia *manusia_baru = malloc(sizeof(manusia));

    if (manusia_baru == NULL)
    {
        printf("Memory error while creating new manusia.\n");
        return NULL;
    }


    if (generations >= 2)
    {

        manusia *parent0 = create_family(generations - 1);
        manusia *parent1 = create_family(generations - 1);

        manusia_baru->parents[0] = parent0;
        manusia_baru->parents[1] = parent1;

        manusia_baru->alleles[0] = parent0->alleles[rand() % 2];
        manusia_baru->alleles[1] = parent1->alleles[rand() % 2];
    }

    else
    {
        manusia_baru->parents[0] = NULL;
        manusia_baru->parents[1] = NULL;

        manusia_baru->alleles[0] = random_allele();
        manusia_baru->alleles[1] = random_allele();
    }

    return manusia_baru;
}

// Free `p` and all ancestors of `p`.
void free_family(manusia *p)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Free parents recursively
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // Free child
    free(p);
}

// Print each family member and their alleles.
void print_family(manusia *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print manusia
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Print parents of current generation
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
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