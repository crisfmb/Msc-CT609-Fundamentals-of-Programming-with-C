/*
Question 1

One large chemical company pays its salespeople on a commission basis. The salespeople receive $200 per week plus 9% of their gross sales for that week. For example, a salesperson who sells $5000 worth of chemicals in a week receives $200 plus 9% of $5000, or a total of $650. Develop a program that will input each salesperson?s gross sales for last week and will calculate and display that salesperson's earnings. Process one salesperson's figures at a time. Here is a sample input/output dialog:

*/

#include <stdio.h> /*perform I/O operations. Tells the preprocessor to include the "stdio.h" header file to support input/output operations*/
#include <stdbool.h> /*Tells the pre-procesor to include the “stdbool.h” header file to support the use of Boolean data types used on the while*/

int main() // initialize the main function
{
    float sales, commission, weeklypay; //defines 3 variables type float being used in the calculation

    while (true) //Use a While to perform the loop calculation as long as sales entered is not -1
    {
        printf("Enter Weekly sales amount in dollars ( To stop execution type -1 ): "); //Display a prompting message asking for the sales amount, -1 to quit
        scanf("%f", &sales); //Read input from keyboard, store the amount in sales

        if (sales == -1) //starts the If statement. This will only execute if the condition sales == -1 returns true
        {
            return 0; //End statement. Exit
        }

        commission = sales / 100 * 9; //Start the calculation of commission if the previous condition wasn't true

        printf("Enter the weekly pay for the Sales Person: "); //Display a prompting message asking for the weekly pay that could varies, -1 to quit
        scanf("%f", &weeklypay);//Read input from keyboard, store the amount in weeklypay

        if (weeklypay == -1) //starts the If statement. This will only execute if the condition weeklypay == -1 returns true
        {
            return 0; //End statement. Exit
        }
        weeklypay = commission + weeklypay; //Starts calculation of weekly pay if the previous condition wasn't true

        printf("The total Salary is: %.2f\n", weeklypay); //prints the result total from the weeklypay + comission. %.2f prints a double with 2 decimal places
    }

    return 0; //End function Main. Exit
}
