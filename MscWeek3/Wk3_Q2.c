/*One interesting application of computers is drawing graphs and bar charts (sometimes called 'histograms'). Write a program that first reads and stores five numbers (each between 1 and 30). Then, for each number read, your program should print a line containing that number of adjacent asterisks (e.g. for the number seven, it should print *******), so that it displays five rows of asterisks. */

#include <stdio.h> //perform I/O operations. Tells the preprocessor to include the "stdio.h" header file to support input/output operations

int main() // initialise the main function
{
    //Define the variables type int and the variable count for the while loop to be used
    int number1;
    int number2;
    int number3;
    int number4;
    int number5;
    int count;

    do //Start statement Do while to get the first number
    {
        printf("\nEnter first number between 1 and 30 : "); //Display a message prompting user to enter a number between 1 and 30
        scanf("%d", &number1);                              //Reads keyboard input from user, store the number input in number1
    } while (number1 < 1 || number1 > 30);                  //Use a While statement to perform the loop to require count number1 to be between 1 and 30 only - user will keep being asked until the number entered is valid
    printf("\n\tThe Number %d is Valid\n", number1);        // if the number1 is in the range 1 to 30, it prints that the number is valid

    //Get Second Number
    do
    {
        printf("\nEnter second number between 1 and 30 : "); //Display a message prompting user to enter a second number between 1 and 30
        scanf("%d", &number2);                               //Reads keyboard input from user, store the number input in number2
    } while (number2 < 1 || number2 > 30);                   //Use a While statement to perform the loop to require count number2 to be between 1 and 30 only - user will keep being asked until the number entered is valid
    printf("\n\tThe Number %d is Valid\n", number2);         // if the number2 is in the range 1 to 30, it prints that the number is valid

    //Get Third Number
    do
    {
        printf("\nEnter third number between 1 and 30 : "); //Display a message prompting user to enter a third number between 1 and 30
        scanf("%d", &number3);                              //Reads keyboard input from user, store the number input in number3
    } while (number3 < 1 || number3 > 30);                  //Use a While statement to perform the loop to require count number3 to be between 1 and 30 only - user will keep being asked until the number entered is valid
    printf("\n\tThe Number %d is Valid\n", number3);        // if the number3 is in the range 1 to 30, it prints that the number is valid

    //Get Fourth Number
    do
    {
        printf("\nEnter fourth number between 1 and 30 : "); //Display a message prompting user to enter a fourth number between 1 and 30
        scanf("%d", &number4);                               //Reads keyboard input from user, store the number input in number4
    } while (number4 < 1 || number4 > 30);                   //Use a While statement to perform the loop to require count number4 to be between 1 and 30 only - user will keep being asked until the number entered is valid
    printf("\n\tThe Number %d is valid\n", number4);         // if the number4 is in the range 1 to 30, it prints that the number is valid

    //Get Fifth Number
    do
    {
        printf("\nEnter fifth number between 1 and 30 : "); //Display a message prompting user to enter a fifth number between 1 and 30
        scanf("%d", &number5);                              //Reads keyboard input from user, store the number input in number5
    } while (number5 < 1 || number5 > 30);                  //Use a While statement to perform the loop to require count number5 to be between 1 and 30 only - user will keep being asked until the number entered is valid
    printf("\n\tThe Number %d is Valid\n", number5);        // if the number5 is in the range 1 to 30, it prints that the number is valid

    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    //Process first number
    count = 1; //set the variable count to start with 1
    do
    {
        printf("*");            // do this statement - print * to build a line with the number entered previously
        count++;                //increment by 1 each time
    } while (count <= number1); // this is a condition to be satisfied before we can start writing to a new line
    printf("\n");               // move to the next line

    //Process Second Number
    count = 1; //set the variable count to start with 1
    do
    {
        printf("*");            // do this statement - print * to build a line with the number entered previously
        count++;                //increment by 1 each time
    } while (count <= number2); // this is a condition to be satisfied before we can start writing to a new line
    printf("\n");               // move to the next line

    //Process third Number
    count = 1; //set the variable count to start with 1
    do
    {
        printf("*");            // do this statement - print * to build a line with the number entered before
        count++;                //increment by1 each time
    } while (count <= number3); // this is a condition to be satisfied before we can start writing to a new line
    printf("\n");               // move to the next line

    //Process fourth Number
    count = 1; //set the variable count to start with 1
    do
    {
        printf("*");            // do this statement - print * to build a line with the number entered before
        count++;                //increment by 1 each time
    } while (count <= number4); // this is a condition to be satisfied before we can start writing to a new line
    printf("\n");               // move to the next line

    //Process fifth number
    count = 1; //set the variable count to start with 1
    do
    {
        printf("*");            // do this statement - print * to build a line with the number entered before
        count++;                //increment by 1 each time
    } while (count <= number5); // this is a condition to be satisfied before we can start writing to a new line
    printf("\n");               // move to the next line

    return 0; //means we have exited the loop and the program will end.
}