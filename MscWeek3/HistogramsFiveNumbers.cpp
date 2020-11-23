/*
Project Goal :
Bar Chart Printing Program
One interesting application of computers is drawing graphs and bar charts (sometimes called “histograms”). 
Write a program that first reads and stores five numbers (each between 1 and 30). 
Then, for each number read, your program should print a line containing that number of adjacent asterisks (e.g. for the number seven, it should print *******), 
so that it displays five rows of asterisks. 

Author : Thomas Brett

Project Name : Assignment-4_18.c



*/

#include <stdio.h>

int main()
{
    //Define the variables
    int number1;
    int number2;
    int number3;
    int number4;
    int number5;
    int counter; //counter to be used for the do while loop

    //Get First Number
    do
    {
        printf("\nEnter first number between 1 and 30 : "); //Ask the user to enter value between 1 and 30
        scanf("%d", &number1);                              //Store the number
    } while (number1 < 1 || number1 > 30);
    printf("\n\tNumber 1 : %d is Valid", number1);

    //Get Second Number
    do
    {
        printf("\nEnter second number between 1 and 30 : "); //Ask the user to enter value between 1 and 30
        scanf("%d", &number2);                               //Store the number
    } while (number2 < 1 || number2 > 30);
    printf("\n\tNumber 2 : %d is Valid", number2);

    //Get Thirdd Number
    do
    {
        printf("\nEnter third number between 1 and 30 : "); //Ask the user to enter value between 1 and 30
        scanf("%d", &number3);                              //Store the number
    } while (number3 < 1 || number3 > 30);
    printf("\n\tNumber 3 : %d is Valid", number3);

    //Get Fourth Number
    do
    {
        printf("\nEnter fourth number between 1 and 30 : ");
        scanf("%d", &number4);
    } while (number4 < 1 || number4 > 30);
    printf("\n\tNumber 4 : %d is valid", number4);

    //Get Fifth Number
    do
    {
        printf("\nEnter fifth number between 1 and 30 : ");
        scanf("%d", &number5);
    } while (number5 < 1 || number5 > 30);
    printf("\n\tNumber 5 : %d is Valid\n", number5);

    /*ok If this was taking a number then writing the **** I would have included a do while in the the counter for that number is less than the number entered
but because the numbers where to be entered in at the start, I am doing a seperate block for each */

    //Process first number
    counter = 1;
    do
    {
        printf("*");
        counter++;
    } while (counter <= number1);
    printf("\n");

    //Process Second Number
    counter = 1;
    do
    {
        printf("*");
        counter++;
    } while (counter <= number2);
    printf("\n");

    //Process third Number
    counter = 1;
    do
    {
        printf("*");
        counter++;
    } while (counter <= number3);
    printf("\n");

    //Process fourth Number
    counter = 1;
    do
    {
        printf("*");
        counter++;
    } while (counter <= number4);
    printf("\n");

    //Process fifth number
    counter = 1;
    do
    {
        printf("*");
        counter++;
    } while (counter <= number5);
    printf("\n");

    printf("\n\nProgram End\n\n\n");
    return 0;
}
