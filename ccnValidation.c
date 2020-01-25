#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Check sum function for card validity
void check(long long ccn)
{
    int nDigits;
    int i;
    int j;
    bool found;
    long iter;
    long long n;
    int sum;
    int sum2;
    long long firstNum;
    long long secondNum;
    sum = 0;
    sum2 = 0;
    found = false;
    
    // Determine the number of digits of the credit card
    nDigits = log10(ccn) + 1;
    printf("Number of digits = %d\n", nDigits);
    
    // Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
    for(i = 1; i < nDigits; i++)
    {
        iter = powf(10, i);
        if(i % 2 != 0)
        {
            n = (ccn/iter) % 10;
            if(n * 2 >= 10)
            {
                sum = sum + (2 * n - 10) + 1;
            }
            else
            {
                sum = sum + (2 * n);
            }
        }
    }
    printf("sum = %d\n", sum);
    
    // Take the sum of all the numbers not multiplied
    for(j = 0; j < nDigits; j++)
    {
        if(j % 2 == 0)
        {
            iter = powf(10, j);
            n = (ccn/iter) % 10;
            sum2 = sum2 + n;
        }
    }
    printf("sum2 = %d\n", sum2);
    printf("Checksum = %d\n", sum + sum2);
    
    // Final check sum
    firstNum = powf(10, (nDigits - 1));
    secondNum = powf(10, (nDigits - 2));
    if((sum + sum2) % 10 == 0)
    {
        // VISA check
        if((nDigits == 13 || nDigits == 16) && (4 == (ccn/firstNum % 10)))
        {
            printf("VISA\n");
            found = true;
        }
        // AMEX check
        if((nDigits == 15) && (3 == (ccn/firstNum % 10)) && ((ccn/secondNum % 10) == (4 | 7)))
        {
            printf("AMEX\n");
            found = true;
        }
        // MASTERCARD check
        if((nDigits == 16) && (5 == (ccn/firstNum % 10)) && ((ccn/secondNum % 10) <= 5 && ((ccn/secondNum % 10) > 0)))
        {
            printf("MASTERCARD\n");
            found = true;
        }
        // If satisfies check sum, but no card on file
        if (!found)
        {
            printf("INVALID\n");
        }
    }
    // Credit card number does not satisfy check sum
    else
    {
        printf("INVALID\n");
    }
}

int main(void)
{
    // Input
    long long ccn; 
    do
    {
        ccn = get_long_long("Please enter a credit card number\n");
    }
    while(ccn <= 0);
    // Output
    check(ccn);
}
