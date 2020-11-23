/*
Project Goal :
Write for statements that print the following sequences of values
a) 1,2,3,4,5,6,7		Add 1 each time
b) 3,8,13,18,23			Add 5 Each time
c) 20,14,8,2,-4,-10		Deduct 6 Each Time
d) 19,27,35,43,51		Add 8 Each Time

Author : Thomas Brett

Project Name : Assignment-4_7.c



*/

#include <stdio.h>

int main()
{
    //The fist one is simple use a counter start it at 1, use a for statement until it is <=7 and print the counter value
    printf("A) Count out the following values 1,2,3,4,5,6,7 (+1) using a for statement\n\n");
    int counterA = 1;  //Define the Counter for A
    int CountMaxA = 7; //Define the Max value for the A counter

    while (counterA <= CountMaxA)
    {
        printf("\t%d\n", counterA);
        //Increment the counter
        counterA++;
    }

    printf("B) Count out the following values 3,8,13,18,23 (+5) using a for statement\n\n");
    int counterB = 3;   //Define the Counter for A
    int CountMaxB = 23; //Define the Max value for the A counter

    while (counterB <= CountMaxB)
    {
        printf("\t%d\n", counterB);
        //Increment the counter
        counterB += 5;
    }

    printf("C) Count out the following values 20,14,8,2,-4,-10 (-6) using a for statement\n\n");
    int counterC = 20;   //Define the Counter for A
    int CountMinC = -10; //Define the Max value for the A counter

    while (counterC >= CountMinC)
    {
        printf("\t%d\n", counterC);
        //Increment the counter
        counterC -= 6;
    }

    printf("D) Count out the following values 19,27,35,43,51 (+8) using a for statement\n\n");
    int counterD = 19;  //Define the Counter for A
    int CountMaxD = 51; //Define the Max value for the A counter

    while (counterD <= CountMaxD)
    {
        printf("\t%d\n", counterD);
        //Increment the counter
        counterD += 8;
    }

    printf("\n\nProgram End\n\n\n");
    return 0;
}