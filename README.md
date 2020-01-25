# creditCardValidation
Credit card number validation using Luhn's algorithm (AMEX, MasterCard, Visa)

This program will prompt the user for a credit card number, and print whether it is a valid AMEX, MasterCard, or VISA credit card. If not valid, the program will output "INVALID."

Example (using a fake credit card number, of course):
```console
$ make credit
clang -fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow    credit.c  -lcrypt -lcs50 -lm -o credit
$ ./credit
Please enter a credit card number
4003600000000014
Number of digits = 16
sum = 13
sum2 = 7
Checksum = 20
VISA
```
