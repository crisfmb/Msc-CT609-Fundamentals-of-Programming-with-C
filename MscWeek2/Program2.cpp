/* 
Question 2

The process of finding the largest number (i.e., the maximum of a group of numbers) is used frequently in computer applications. For example, a program that determines the winner of a sales contest would input the number of units sold by each salesperson. The salesperson who sold the most units wins the contest. Write a pseudocode program and then a program that inputs a series of 10 numbers and determines and prints the largest of the numbers.
*/

#include <stdio.h>

int main()
{
    int counter = 0, number = 0, largest = 0;

    while (counter < 10)
    {
        printf("Enter a number: \n");
        scanf("%d", &number);

        if (number >= largest)
        {
            largest = number;
        }
        counter++;
    }

    printf("The largest number is %d\n", largest);

    return 0;
}