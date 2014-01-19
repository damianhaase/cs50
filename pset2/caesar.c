#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * caesar.c
 * pset2, cs50 Spring 2014
 *
 * Damian Haase
 * mail@damianhaase.com
 *
 * Accept a single command-line argument (k): a non-negative integer. If no 
 * argument, or more than one argument, print an error message and return 
 * the value 1.
 *
 * Then, prompt the user for a string of plaintext. Return another string, 
 * which is that same string shifted by k. Then exit.
 *
 * Preserve case, and just shift letters
 *
 * if p is some plaintext (i.e., an unencrypted message), p(i) is the (i)th 
 * character in p, and k is a secret key (i.e., a non-negative integer), then 
 * each letter, c(i), in the ciphertext, c, is computed as:
 * c(i) = (p(i) + k) % 26
 */

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("%s: missing key operand\n", argv[0]);
        printf("Try %s --help for more information.\n", argv[0]);
        return 1;
    } 
    else if (argc > 2 )
    {
        printf("%s: too many arguments\n", argv[0]);
        printf("Try %s --help for more information.\n", argv[0]);
        return 1;
    }

    // how can i tell if the user did not input an actual number for the 
    // argument? it converts non-integers to 0. i'm leaving this for later

    // convert the commandline argument (a string) to an int
    int k = atoi(argv[1]);

    // reduce the key down to between 0 and 25
    if (k > 25)
    {
        k %= 26;
    }

    string phrase;
    
    do 
    {    
        // prompt the user for an message
        phrase = GetString();
    }
    // repeat if nothing is entered
    while (phrase[0] == '\0');
    

    if (phrase != NULL)
    {
        int n = strlen(phrase);
        for (int i = 0; i < n; i++)
        {
            // only encode letters
            if (isalpha (phrase[i]))
            {
                // wrap value around if necessary
                if ((isupper (phrase[i]) && ((phrase[i] + k) > 90))
                    || (islower (phrase[i]) && ((phrase[i] + k > 122))))
                {
                    phrase[i] -= 26;
                }
                phrase[i] += k;
            }
        }
        printf("%s\n", phrase);
    }
        
    return 0;

}
