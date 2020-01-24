#include <stdio.h>
#include <cs50.h>
#include <math.h>

void check(long long ccn)
{
    long long ccn1;
    int nDigits;
    int i;
    int iter;
    long long n;
    int sum;
    nDigits = log10(ccn) + 1;
    printf("Number of digits = %d\n", nDigits);
    sum = 0;
    
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
                sum = sum + (2* n);
            }
             printf("sum = %d\n", sum);
        }   
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
