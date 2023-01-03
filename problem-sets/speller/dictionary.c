/*
Theoretically, on input of size n, an algorithm with a running time of n is "asymptotically equivalent," in terms of O, to an algorithm with a running time of 2n. Indeed, when describing the running time of an algorithm, we typically focus on the dominant (i.e., most impactful) term (i.e., n in this case, since n could be much larger than 2). In the real world, though, the fact of the matter is that 2n feels twice as slow as n.

The challenge ahead of you is to implement the fastest spell checker you can! By "fastest," though, we're talking actual "wall-clock," not asymptotic, time.
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

#define N 10000

/*
 Notice how, atop the file, we've defined a struct called node that represents a node in a hash table. And we've declared a global pointer array, table, which will (soon) represent the hash table you will use to keep track of words in the dictionary. The array contains N node pointers, and we've set N equal to 26 for now, to match with the default hash function as described below. You will likely want to increase this depending on your own implementation of hash.
*/
// Defines struct for a node
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// variabel untuk menghitung jumlah kata
int jumlah_kata = 0;

node *table[N];

// fungsi untuk melakukan hash
// word yg akan di hash berada di new node
// hashing menghasilkan index dan dimasukkan ke dalam sebuah linked list
int hash_index(char *word_to_hash)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word_to_hash); i < n; i++)
    {
        hash = (hash << 2) ^ word_to_hash[i];
    }
    return hash % N;
}



/*
Next, notice that we've implemented load, check, size, and unload, but only barely, just enough for the code to compile. Notice too that we've implemented hash with a sample algorithm based on the first letter of the word. Your job, ultimately, is to re-implement those functions as cleverly as possible so that this spell checker works as advertised. And fast!
*/

//fungsi untuk load
bool load(const char *dictionary)
{
    //buka file
    FILE *file = fopen(dictionary, "r");

    //return false jika file gagal dibuka
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    //loop
    while (fscanf(file, "%s", word) != EOF)
    {
        //alokasi memory untuk newnode
        node *newnode = malloc(sizeof(node));

        //return false jika malloc gagal
        if (newnode == NULL)
        {
            unload();
            return false;
        }

        //salin word
        strcpy(newnode->word, word);
        newnode->next = NULL;

        int h = hash_index(newnode->word);

        node *head = table[h];

        if (head == NULL)
        {
            table[h] = newnode;
            jumlah_kata = jumlah_kata + 1;
        }
        else
        {
            newnode->next = table[h];
            table[h] = newnode;
            jumlah_kata = jumlah_kata + 1;
        }
    }
    fclose(file);
    return true;
}

bool check(const char *word)
{
    int wordsize = strlen(word);
    char wordcopy[LENGTH + 1];
    for (int i = 0; i < wordsize; i++)
    {
        wordcopy[i] = tolower(word[i]);
    }
    wordcopy[wordsize] = '\0';
    int h = hash_index(wordcopy);
    node *penunjuk = table[h];
    while (penunjuk != NULL)
    {
        if (strcasecmp(penunjuk->word, wordcopy) == 0)
        {
            return true;
        }
        else
        {
            penunjuk = penunjuk->next;
        }
    }
    return false;
}


//return jumlah kata
unsigned int size(void)
{
    return jumlah_kata;
}

//membersihkan list
bool unload(void)
{
    for (int i = 0; i < N ; i ++)
    {
        node *head = table[i];
        node *penunjuk = head;
        node *tmp = head;

        while (penunjuk != NULL)
        {
            penunjuk = penunjuk -> next;
            free(tmp);
            tmp = penunjuk;
        }

    }
    return true;
}