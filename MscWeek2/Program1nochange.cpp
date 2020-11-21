/*
Question 1

One large chemical company pays its salespeople on a commission basis. The salespeople receive $200 per week plus 9% of their gross sales for that week. For example, a salesperson who sells $5000 worth of chemicals in a week receives $200 plus 9% of $5000, or a total of $650. Develop a program that will input each salesperson?s gross sales for last week and will calculate and display that salesperson's earnings. Process one salesperson's figures at a time. Here is a sample input/output dialog:

*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    float sales, commission, weeklypay;

    while (true)
    {
        printf("Enter Weekly sales amount in dollars ( To stop execution type -1 ): ");
        scanf("%f", &sales);

        if (sales == -1)
        {
            return 0;
        }

        commission = sales / 100 * 9;
        weeklypay = commission + 200;

        printf("he total Salary is: %.2f\n", weeklypay);
    }

    return 0;
}