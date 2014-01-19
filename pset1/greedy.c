#include <cs50.h>
#include <stdio.h>
#include <math.h>

/**
 * greedy.c
 * Time for Change; pset1, cs50 Spring 2014
 *
 * Damian Haase
 * mail@damianhaase.com
 *
 * Figure out how many coins of each denomination (quarter & below) to give for
 * a given amount of change
 */

// variable is the denomination of what we will subtract
void makechng(int);

// make num and cents global variables so 'makechng' can operate on them
// num is going to hold the answer that is returned at the end
int num;
int cents;

int main(void)
{

    printf("O hai! ");

    // we take a floating point number so we can accept decimals
    float input;

    do
    {
        printf("How much change is owed?\n");
        input = GetFloat();
    }
    // repeat the prompt if input is less than 0, to get a non-negative int
    while (input < 0);

    // convert to pennies, and round to the nearest penny
    cents = round(input * 100);

    // and we'll use an array to store the denominations of the coins
    int eachden[] = {25, 10, 5, 1};

    // use function to first count out quarters, then dimes, then nickels,
    // then pennies
    for (int i = 0; i < (sizeof(eachden) / sizeof(int)); i++)
    {
        makechng(eachden[i]);
    }

    // print the total number of coins required
    printf("%d\n", num);

    return 0;

}

void makechng(int den)
{
    int j = (int) cents / den;
    if (j >= 1)
    {   
        num += j;
        cents %= den;
    }

    return;

}
