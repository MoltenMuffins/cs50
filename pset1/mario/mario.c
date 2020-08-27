#include <cs50.h>
#include <stdio.h>

void str_printer(string str, int num_hashes)
{
    // Convenience function to print a string
    // a given number of times
    int i;
    for (i = 0; i < num_hashes; ++i)
    {
        printf("%s", str);
    }
}

void pyramid_printer(int height)
{
    int i;
    int space_offset;
    for (i = 1; i < height + 1; ++i)
    {
        // Calcuate how many spaces to print
        // so that the pyraimid prints properly
        space_offset = height - i;
        // Print the appropriate number of each
        // char using our str_printer function
        str_printer(" ", space_offset);
        str_printer("#", i);
        printf("  ");
        str_printer("#", i);
        printf("\n");
    }
}

int main(void)
{
    // init height
    int height = 0;

    // Loop prompt until input is within the desired range of 1-8 inclusive
    do
    {
        height = get_int("Input a value for Height:\n");

    }
    while (height > 8 || height < 1);
 
    // Call the pyrimid_printer functions
    // to help us sus out the details of pyramid
    // printing
    pyramid_printer(height);
}