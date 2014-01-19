#include <cs50.h>
#include <stdio.h>

/**
 * mario.c
 * pset1, cs50 2014
 *
 * Damian Haase
 * mail@damianhaase.com
 *
 * Make a mario half-pyramid, accepting an integer no greater than 23 as input 
 * for the height. 
 *
 * Error handling: If user enters a number other than a non-negative integer 
 * less than or equal to 23, replay the "Height:" prompt;
 * if user enters anything besides a number, GetInt returns "Retry:"
 *
 * The overall output is (Height + 1) wide UNLESS the user enters 0 
 * Each line has (Height - LineNumber) spaces and (1 + LineNumber) blocks
 */

int main(void)
{

    int height;
    do
    {
        // prompt the user for an integer
        printf("Height: ");
        height = GetInt();
    }
    // repeat the prompt if input is less than 0 or more than 23
    while (height < 0 || height > 23);

    // print 'height' number of lines
    // also use 'i' to tell the next two loops what line number we're on
    for (int i = 1; i <= height; i++)
    {
        // print height - linenumber number of spaces
        for (int j = (height - i); j > 0; j--)
        {
            printf(" ");
        }
        // print linenumber + 1 number of hashes
        for (int k = (i + 1); k > 0; k--)
        {
            printf("#");
        }
        // then the newline
        printf ("\n");
    }

    return 0;

}
