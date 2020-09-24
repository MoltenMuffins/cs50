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
    // Iterate through the candidate names to find a match
    for (int i = 0; i < candidate_count; i++)
    {
        // Compare strings for equality
        if (strcmp(candidates[i].name, name) == 0)
        {
            // Increment vote count if a match is found
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{

    int highest_score = 0;
    // Create variable to store a candidate during the swap
    candidate temp_candidate;

    // Sort the array of candidates
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > highest_score)
        {
            highest_score = candidates[i].votes;
            temp_candidate = candidates[i];
            candidates[i] = candidates[candidate_count];
            candidates[candidate_count] = temp_candidate;
        }
    }

    // Iterate through the array again and print
    // the candidate names if their vote counts
    // are equal to the highest recorded score
    highest_score = candidates[candidate_count].votes;
    for (int i = candidate_count; i > 0; i--)
    {
        if (candidates[i].votes == highest_score)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}
