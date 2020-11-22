/* 
Question 2

The process of finding the largest number (i.e., the maximum of a group of numbers) is used frequently in computer applications. For example, a program that determines the winner of a sales contest would input the number of units sold by each salesperson. The salesperson who sold the most units wins the contest. Write a pseudocode program and then a program that inputs a series of 10 numbers and determines and prints the largest of the numbers.
*/

#include <stdio.h> /*perform I/O operations. Tells the preprocessor to include the "stdio.h" header file to support input/output operations*/

int main() // initialize the main function
{
    int count = 0, number = 0, largnumber = 0; //defines 3 variables type int initializing value zero

    while (count < 10) //Use a While to perform the loop to require count to be less than 10
    {
        printf("Enter a number: \n"); //Display a prompting message asking for a number
        scanf("%d", &number);         //Read input from keyboard, store the amount in number

        if (number >= largnumber) //starts the If statement. This will only execute if the condition number >= largnumber the number entered is greater than the largest number stored is true
        {
            largnumber = number; // set the largest number enteres to the variable largnumber
        }
        count++; //increment loop counter
    }

    printf("The largest of the numbers is: %d\n", largnumber); /*prints the text and returns integer value of the largest number input*/

    return 0; //End function Main. Exit
}