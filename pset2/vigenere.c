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

    string key = argv[1];
 
    // test if the key comes back NULL, exit if so
    if (key == NULL)
    {
        printf("key is NULL; exiting to avoid segfault\n");
        return 1;
    }
 
    // go through each character of argv[1] and test each one to make sure
    // it's an alphabetical character; if one fails, exit
    int keylen = strlen(key);
    for (int i = 0; i < keylen; i++)
    {
        if (!isalpha (key[i]))
        {
            printf("Non-alphabetical character in input \"%s\"\n", key);
            return 1;
        }
    }


/*
    // go through each character of key and convert it to a number

        for (int i = 0; i < n; i++)
        {
            printf("%c becomes %d\n", key[i], (int)key[i]);
        }
*/


    // "phrase" will contain the user's input
    string phrase;

    // prompt the user for an message    
    do 
    {
        phrase = GetString();
    }
    // repeat if nothing is entered
    while (phrase[0] == '\0');
    
    // printf("Take \"%s\" and modify it with \"%s\"\n", phrase, key);
    
    // run through the phrase string
    // p is our counter for the key position
    // when p gets to be the length of the key string (minus the null end 
    // character), reset it to zero
    int p = 0;
    int n = strlen(phrase);
    for (int i = 0; i < n; i++)
    {
        // first, just print the key letters over and over along with the
        // phrase letters
        // printf("%c %c\n", key[p], phrase[i]);
        
        // only encode letters, and don't increment along the key for 
        // non-shifted characters
        if (isalpha (phrase[i]))
        {
            // figure out how far to shift
            int k = key[p];
            
            
            if (isupper (key[p]))
            {
                // reduce the key so that a = 0
                k -= 65;
            }
            else
            {
                // reduce the key so that a = 0
                k -= 97;
            }
            
            if (((isupper (phrase[i])) && ((phrase[i] + k) > 90)) 
            ||  ((islower (phrase[i])) && ((phrase[i] + k) > 122)))
            {
                phrase[i] -=26;
            }
            
            // printf("key: %d %d  ", ((int)key[p]), k);
            // printf("phr: %d %c", (int)phrase[i], phrase[i]);

            phrase[i] += k;
            // printf(" %c\n", phrase[i]);
                
            if (p == (keylen - 1))
            {
                p = 0;
            }
            else
            {
                p += 1;
            }
        }
    }
    
    
    printf("%s\n", phrase);

    return 0;
}
