#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_digit(long num, int n)
{
    // Function to get a specific digit
    // from a long where n is the
    // digit count from the right of the number
    // ie. n = 1 refers to the ones place
    // n = 2 refers to the tens place, so on
    // and so forth. I know it's kind of inefficient
    // to keep dividing the credit card number
    // multiple times but I wanted to encapsulate
    // getting digits since it's used in three places
    // in the checksum

    long offset_num;
    int result;

    // First we divide the number by 10 repeatedly
    // until the digit we want is in the Ones place
    offset_num = floor(num / pow(10, n - 1));
    // We then use the modulo to get the last digit,
    // and then cast that long to an int
    result = (int)(offset_num % 10);
    return result;
}

void cc_checksum(long cc_num)
{
    // Function to run a checksum on a
    // given credit card number

    int i = 0;
    int n = 0;
    int cur_num = 0;
    int prev_num = 0;
    
    int magic_num = 0;
    int magic_sum = 0;
    int cum_sum = 0;

    int final_sum = 0;
    bool legit;

    while (cc_num / pow(10, n) >= 1)
    {
        n += 1;
        prev_num = cur_num;
        cur_num = get_digit(cc_num, n);
        // We do magic with every other digit
        if (n % 2 == 0)
        {
            i = 0;
            magic_num = cur_num * 2;
            while (magic_num / pow(10, i) >= 1)
            {
                i += 1;
                magic_sum += get_digit(magic_num, i);
            }
        }
        else
        {
            // For these digits we just add them
            // to a cumsum
            cum_sum += cur_num;
        }
    }
    
    final_sum = magic_sum + cum_sum;
    if (get_digit(final_sum, 1) == 0)
    {
        // The number seems legit but we now need
        // to check the card provider. Welcome to
        // if-else hell.
        if (n == 13)
        {
            if (cur_num == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (n == 15)
        {
            if (cur_num == 3)
            {
                if (prev_num == 4 || prev_num == 7)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else if (cur_num == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (n == 16)
        {
            if (cur_num == 5)
            {
                i = 0;
                for (i = 1; i < 6; ++i)
                {
                    if (prev_num == i)
                    {
                        printf("MASTERCARD\n");
                        // Early exit because I don't
                        // know how else
                        // to print "invalid"
                        // if this statement is never true
                        return;
                    }
                }
                printf("INVALID\n");
            }
            else if (cur_num == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int main(void)
{
    // Prompt for a credit card number
    long cc_num = get_long("Input a Credit Card Number:");
 
    // int result = get_digit(cc_num, 5);
    // printf("%d", result);
    // Call the cc_checksum function to check if the Credit Card is valid
    cc_checksum(cc_num);
}