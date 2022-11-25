// Implements a dictionary's functionality
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

unsigned int contador;
unsigned int valor_hash;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //hash(word);
    valor_hash = hash(word);
    node *cursor = table[valor_hash];

    //lista
    while (cursor != 0)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long total = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        total += tolower(word[i]);
    }
    return total % N;
    /*return toupper(word[0]) - 'A';*/
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //Abre el diccionario
    FILE *file = fopen(dictionary, "r");

    //si el archivo no esta o es NULL no lo abre
    if (file == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }

    //aqui se llama a word
    char word[LENGTH + 1];

    //lee el diccionario
    while (fscanf(file, "%s", word) != EOF)
    {
        //reserva memoria para el nuevo nodo
        node *n = malloc(sizeof(node));

        //si malloc dice que esta node esta NULL, regresa false
        if (n == NULL)
        {
            return false;
        }

        //copia word en n
        strcpy(n->word, word);
        valor_hash = hash(word);
        n->next = table[valor_hash];
        table[valor_hash] = n;
        contador++;
    }
    //cerra el archivo
    fclose(file);
    return true;
}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (contador > 0)
    {
        return contador;
    }

    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // for (int i = 0; i < N; i++)
    // {
    //     node *cursor = table[i];
    //     while (cursor)
    //     {
    //         node *tmp = cursor;
    //         cursor = cursor ->next;
    //         free(tmp);
    //     }
    //     if (cursor == NULL)
    //     {
    //         return true;
    //     }
    // }
    // return false;
    // node *cursor = malloc(sizeof(node));
    // node *temp = malloc(sizeof(node));
    // if (cursor != NULL && temp != NULL)
    // {
    //     for (int i = 0; i < N; i++)
    //     {
    //         cursor = table[i];
    //         while (cursor != NULL)
    //         {
    //             temp = cursor;
    //             cursor = cursor -> next;
    //             free(temp);
    //         }
    //         if (i == N - 1 && cursor == NULL)
    //         {
    //             free(cursor);
    //             return true;
    //         }
    //     }
    // }
    //     return false;

    bool bien = false;
    for (int i = 0; i < N;)
    {
        if (table[i] == NULL)
        {
            i++;
        }

        else
        {
            node *iterador = table[i];
            node *tmp = iterador;
            while (iterador != NULL)
            {
                tmp = iterador;
                iterador = iterador->next;
                free(tmp);
                bien = true;
            }
            i++;
        }
    }

    return bien;
}
