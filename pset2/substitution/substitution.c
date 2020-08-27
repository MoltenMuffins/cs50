#include <cs50.h>
#include <stdio.h>
#include <string.h>

string substitute(string plaintext, string key)
{
    char character;
    char new_char;
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        character = plaintext[i];
        if (character >= 'A' && character <= 'Z')
        {
            // Use the key to obtain the cipher character
            plaintext[i] = key[character - 65];

        }
        else if (character >= 'a' && character <= 'z')
        {
            // Use the key to obtain the cipher character
            // while converting to uppercase and back
            plaintext[i] = key[character - 65 - 32] + 32;
        }
    }
    return plaintext;
}


int main(int argc, string argv[])
{
    // Check if correct number of arguments are passed
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    // Check if correct length of key is passed
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;        
    }
    
    // Check that key characters are alphabets and
    // that they are unique while normalizing
    // key to all uppercase
    char key_char;
    int unique_checklist[26] = {0};
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        key_char = argv[1][i];
        if (key_char >= 'A' && key_char <= 'Z')
        {
            ;
        }
        else if (key_char >= 'a' && key_char <= 'z')
        {
            argv[1][i] = key_char - 32;;
        }
        else
        {
            // If a character lies outside the ranges we previously checked
            // it's an invalid character
            printf("Invalid character '%c' found in key.\n", key_char);
            return 1;        
        }
        
        // We keep track of uniqueness by storing an int for
        // each letter of the alphabet
        unique_checklist[argv[1][i] - 65] += 1;
        if (unique_checklist[argv[1][i] - 65] > 1)
        {
            printf("Character '%c' found repeated in key.\n", key_char);
            return 1;        
        }
    }  
    
    string plaintext = get_string("plaintext: ");
    string new_string = substitute(plaintext, argv[1]);
    printf("ciphertext: %s\n", new_string);
    return 0;
}