/*Write for statements that print the following sequences of values
a) 1,2,3,4,5,6,7		Add 1 each time
b) 3,8,13,18,23			Add 5 Each time
c) 20,14,8,2,-4,-10		Deduct 6 Each Time
d) 19,27,35,43,51		Add 8 Each Time*/

#include <stdio.h> //perform I/O operations. Tells the preprocessor to include the "stdio.h" header file to support input/output operations

int main() // initialize the main function
{
    //The first one is simple use a counter where the sequence starts at 1, use a "for" statement that prints the value until it is <=7
    printf("\n A) =-=-=Count out the following values 1,2,3,4,5,6,7 (+1) using a for statement=-=-=\n\n");
    int SeqA = 1;    //Define the SeqA as the variable type int
    int SeqMaxA = 7; //Define the SeqMaxA as Maximun value for SeqA.

    for (SeqA = 1; SeqA <= SeqMaxA; SeqA++) //Here we initialise the variable SeqA, define the condition to be satisfied for the loop to continue and set what it should be incremented by after each loop
    {
        printf("\t%d\n", SeqA); // prints the value for SeqA as long as the condition is satisfied
    }

    printf("\n B) =-=-=Count out the following values 3,8,13,18,23 (+5) using a for statement=-=-=\n\n");
    int SeqB = 3;     //Define the SeqB as the variable type int
    int SeqMaxB = 23; //Define the SeqMaxB as the Max value for DeqB

    for (SeqB = 3; SeqB <= SeqMaxB; SeqB += 5) //Here we initialise the variable SeqB, define the condition to be satisfied for the loop to continue and set what it should be incremented by after each loop - increment of 5 in this case
    {
        printf("\t%d\n", SeqB); // prints the value for SeqB as long as the condition is satisfied
    }

    printf("\n C) =-=-=Count out the following values 20,14,8,2,-4,-10 (-6) using a for statement=-=-=\n\n");
    int seqC = 20;     //Define SeqC as the variable type int
    int SeqMinC = -10; //Define SeqMinC as the  Minimum value for DeqC

    for (seqC = 20; SeqMinC <= seqC; seqC -= 6) //Here we initialise the variable SeqC, define condition to be satisfied for the loop to continue set what it should be decremented by after each loop - decrement of minus 6 in this case
    {
        printf("\t%d\n", seqC); // prints value of SeqC as long as condition satisfied
    }

    printf("\n D) =-=-=Count out the following values 19,27,35,43,51 (+8) using a for statement=-=-=\n\n");
    int SeqD = 19;    //Define the SeqD as an integer variable
    int SeqMaxD = 51; //Define the SeqMaxD as the maxmimum value for SeqD

    for (SeqD = 19; SeqD <= SeqMaxD; SeqD += 8) //Here we initialise the variable SeqD, define condition to be satisfied for the loop to continue set what it should be incremented by after each loop - increment of 8 in this
    {
        printf("\t%d\n", SeqD); // prints values for SeqD as long as condition satisfied
    }

    return 0; //End statement. Exit
}