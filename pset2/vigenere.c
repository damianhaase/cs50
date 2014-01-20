#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * vigenere.c
 * pset2, cs50 Spring 2014
 *
 * Damian Haase
 * mail@damianhaase.com
 *
 * Accept a single command-line argument (k): a string. If no argument, more 
 * than one argument, or an argument that contains any non-alphabetical 
 * character, print an error message and return the value 1.
 *
 * Then, prompt the user for a string of plaintext. Return another string, 
 * which is that same string shifted by each successive character in argv[1]. 
 * Then exit.
 *
 * Preserve case, and just shift letters
 */

int main(int argc, string argv[])
{
    // test the first requirement of the input string: that there be just one
    // i had fun making the error messaging seem like a regular command's
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
    
    // go through each character of argv[1] and test each one to make sure
    // it's an alphabetical character
    string m = argv[1];
    if (m != NULL )
    {
        int n = strlen(m);
        for (int i = 0; i < n; i++)
        {
            if (!isalpha (m[i]))
            {
                printf("Non-alphabetical character in input \"%s\"\n", m);
                return 1;
            }
        }
    }
    

    string phrase;
    
    do 
    {    
        // prompt the user for an message
        phrase = GetString();
    }
    // repeat if nothing is entered
    while (phrase[0] == '\0');
    
    
    
    printf("Take \"%s\" and modify it with \"%s\"\n", phrase, argv[1]);
    
    /*
    // this is from caesar.c
    // convert the commandline argument (a string) to an int
    int k = atoi(argv[1]);

    // reduce the key down to between 0 and 25
    if (k > 25)
    {
        k %= 26;
    }
    */

    
/*
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
   */
        
    return 0;

}
