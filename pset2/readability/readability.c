#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int count_letters(string txt)
{
    // Function to count letters by checking if the
    // ascii values are that of alphabetical characters
    char character;
    int num_letters = 0;
    for (int i = 0, n = strlen(txt); i < n; i++)
    {
        character = txt[i];
        if (character >= 'A' && character <= 'Z')
        {
            num_letters += 1;
        }
        else if (character >= 'a' && character <= 'z')
        {
            num_letters += 1;
        }
    }
    return num_letters;
}

int count_words(string txt)
{
    // Function to count the number of words in a string
    // using the number of spaces in the string
    int num_words = 1;
    for (int i = 0, n = strlen(txt); i < n; i++)
    {
        if (txt[i] == ' ')
        {
            num_words += 1;
        }
    }
    return num_words;
}

int count_sentences(string txt)
{
    // Function to count sentences by counting
    // the number of end characters in a string.
    char character;
    int num_sentences = 0;
    for (int i = 0, n = strlen(txt); i < n; i++)
    {
        character = txt[i];
        if (character == '.' || character == '!' || character == '?')
        {
            num_sentences += 1;
        }
    }
    return num_sentences;
}

int compute_CL_index(string txt)
{
    // Function to calculate a Coleman-Liau index
    int index;
    
    int num_words = count_words(txt);
    float avg_letters = count_letters(txt) * 100.0 / num_words;
    float avg_sentences = count_sentences(txt) * 100.0 / num_words;
    index = round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8);

    return index;
}

int main(void)
{
    int index;
    // Prompt for a string to compute a Coleman-Liau index for
    string txt = get_string("Text: ");
    // Calculate the Coleman-Liau index
    index = compute_CL_index(txt);
    
    // Print an appropriate response based on the index
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}