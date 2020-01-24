#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Check sum function for card validity
void check(long long ccn)
{
    long long ccn1;
    int nDigits;
    int i;
    int j;
    int iter;
    long long n;
    int sum;
    int sum2;
    sum = 0;
    sum2 = 0;
    // Determine the number of digits of the credit card
    nDigits = log10(ccn) + 1;
    printf("Number of digits = %d\n", nDigits);
    
    // Multiply every other digit by 2, starting with the number’s second-to-last digit
    // Then add those products’ digits together
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
            printf("sum = %d\n", sum);
        }
    }
    // Sum of digits that weren't multiplied by 2
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
