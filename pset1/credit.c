#include <stdio.h>
#include <cs50.h>

/**
 * credit.c
 * pset1 - hacker edition, cs50 Spring 2014
 *
 * Damian Haase
 * mail@damianhaase.com
 *
 * Prompt for a credit card number, then report if that number is a valid
 * number and what type
 *
 * check50 2014/x/hacker1/credit credit.c
 */
 
 int main(void)
 {
    // get input of number
    // use GetLongLong

    long long input;
 
    // just prompt for the number; it seems GetLongLong will trap many errors
    printf("Enter card number:\n");
    input = GetLongLong();
    
    //int len = (sizeof(input) / sizeof(int));
    
    int b = sizeof(input);
    printf("input is %d big\n", b);    
    
    int a = sizeof(int);
    printf("int is %d big\n", a);
    
    printf("%lld\n", input);
    // printf("%d digits\n", len);

    // first need to check that it's between 13 and 16 digits
 
 
 // checksum: multiply every other digit by two, starting with the 
 // second-to-last digit, then add those products' digits together
 
 
 // add the sum to the sum of the digits that weren't multiplied by two
 
 
 // if the total's last digit is 0 (or % 10 == 0), the number is valid
 
 
 // card identification:
 // amex: 34 or 37
 // mc:   51, 52, 53, 54, 55
 // visa: 4
 
 
 // return AMEX\n, MASTERCARD\n, VISA\n or INVALID\n
 
}
