/* Program ask a user to enter two numbers and prints their sum, product, difference, quotiente and reminder*/

#include <stdio.h> /*perform I/O operations. Tells the preprocessor to include the "stdio.h" header file to support input/output operations*/

int main(void) /* initialize the function main */
{
    int x, y, sum, product, difference, quotient, remainder; /* Declare a variables type integer */

    printf("Please enter first number: "); /* Display a prompting message asking for the first number */
    scanf("%d", &x);                       /* Read input from keyboar */

    printf("Please enter second number: "); /*Display a prompting message asking for second number*/
    scanf("%d", &y);                        /* Read input from keyboar*/

    sum = x + y;                                         /* Calculate the sum */
    printf("The sum of %d and %d is: %d.\n", x, y, sum); /* Print the sum result */

    product = x * y;                          /* Calculate the product */
    printf("The product is: %d.\n", product); /* Print the product result */

    difference = x - y;                                                /* Calculate the difference */
    printf("The difference of %d and %d is: %d.\n", x, y, difference); /* Print the difference result */

    quotient = x / y;                            /* Calculate the quotient */
    printf("The quotient is:  %d.\n", quotient); /* Print the quotient result */

    remainder = x % y;                                                /* Calculate the remainder */
    printf("The remainder of %d and %d is:  %d.\n", x, y, remainder); /* Print the remainder result */

    return 0; /* End function Main. Exit */
}
