#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO

    //Recorre el count de los candidatos
    for (int i = 0; i < candidate_count; i++)
    {
        //comprueba si el candidato es parecido a lo que escoge el usuario
        if (strcmp(candidates[i].name, name) == 0)
        {

            candidates[i].votes++; //si es igual a lo que el usuario vota, entonces aumenta el voto del candidato específico y devuelve true
            return true;
        }
    }
    //Si no es igual, devuelve false
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO



    int voto_mayor = 0; //voto maximo lo asignoen 0


    for (int i = 0; i < candidate_count; i++)
    {
        //Si los votos de los candidatos son mayores se ponen en el voto_mayor
        if (candidates[i].votes > voto_mayor)
        {
            voto_mayor = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        //comprueba los votos de los candidatos que sean iguales al voto_mayor
        if (candidates[i].votes == voto_mayor)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}