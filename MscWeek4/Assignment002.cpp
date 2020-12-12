//Access C Standard Library
#include <stdio.h> //performs I/O operations. Tell the preprocessor to include the "stdio.h" header file to support input/output operations
#include <time.h>  // This header file contains definitions of functions to get and manipulate date and time information.

//Define my constants
#define TERMS 50                //The number of terms in the series to calculate.
#define TEST_REPEAT_COUNT 10000 //How many times should we repeat the factorial processes tests

//Declare my functions
void ShowWelcome();                                                          //A Welcome Message
double recursiveTest();                                                      //The Recursive Function test
double iterativeTest();                                                      //The Iterative Function test
unsigned long long int recursiveFactorial(unsigned int number);              //Recursive Factorial function
unsigned long long int iterativeFactorial(unsigned int number);              //Iterative Factorial function
void ShowResult(double recursiveTestDuration, double iterativeTestDuration); //Outputs results to the user

int main() // shows the entry point for the program
{

    ShowWelcome(); //Display the Welcome Message

    //Write code to record time for the recursive and iterative loop methods
    //Declare variables for my function return values.
    double recursiveTestDuration; // variable stored as a double
    double iterativeTestDuration; // variable stored as a double

    recursiveTestDuration = recursiveTest(); //Perform the Recursive Function Test
    iterativeTestDuration = iterativeTest(); //Perform the Iterative Function Test

    //Requirement #5 - Present your timing results
    ShowResult(recursiveTestDuration, iterativeTestDuration); // displays result of time taken

    return (0); //Program completed successfully

} //End of main()

/*welcome
Displays an introduction to the user, describing what this program will do.
*/
void ShowWelcome() // function doesnt return a value
{
    puts("Recursive vs. Iterative function performance comparison.\n");
    puts("This program calculates an approximate value for series from with the");
    printf("equation e = 1/0! + 1/1! + 1/2! + 1/3! + ... for %d terms.\n\n", TERMS);

    puts("To determine if a Recursive function or Iterative function performs best we use the C Standard");
    puts("Library 'clock()' function, to time the calculation for both recursive and iterative functions");
    printf("The test is repeated %d times, as the result from\n", TEST_REPEAT_COUNT);
    puts("the 'count()' function is system dependant so the calc time done once may not register\n");
    puts("This timing data will then be presented to the user for evaluation.\n\n");

    printf("%s", "Press ENTER key to Continue...");
    getchar(); //Program pauses until user selects 'ENTER' key
    puts("\n\n");
}

/*recursiveTest
This function returns the time it takes to calculate series using 'TERMS' Factorial terms, 
calculated with a Recursive Factorial function call. 
The test is repeated 'TEST_REPEAT_COUNT' times, as the Standard Library C count()
function's resolution is system dependant. 
We then output the calculated number and the time taken to complete the task.
return duration – Time taken to complete test.
*/
double recursiveTest() // stores recurvise test result as a variable type double
{
    long double eRecursive;        //Result of Number Series to be calculated
    clock_t beforeTime, afterTime; //Before process and After process time variables
    double duration;               //Calculated duration of test variable

    //Start test
    puts("Starting calculation using Recursive function...");
    beforeTime = clock(); //Record the time since program launched

    //Repeat the process TEST_REPEAT_COUNT number of times defined at outset
    for (int x = 1; x <= TEST_REPEAT_COUNT; x++) //for loop - coutn starts at 1, checks if it is less than value of 10000 and increments by 1
    {
        eRecursive = 0.0;
        //Calculate expansion using the formula...
        //    e = 1/0! + 1/1! + 1/2! + 1/3! + ... for declared constant 'TERMS' terms
        for (int count = 0; count <= TERMS; count++) // for loop, count starts at 0. number of terms less than count it continues, and increments by 1 each time
        {
            eRecursive += 1.0 / recursiveFactorial(count);
        } //End of inner for
    }     //End of TEST_REPEAT for

    afterTime = clock(); //Record the time since program launched

    duration = (double)(afterTime - beforeTime) / CLOCKS_PER_SEC; //Display duration in seconds, divide by the system constant 'CLOCKS_PER_SEC' from <time.h>

    //Output calculated figure and time taken...
    printf("\te = %.16Lf\n", eRecursive);                                    //Display result to 16 digits
    printf("\tCalculation completed in a time of %f seconds\n\n", duration); // displays result with text
    return duration;
} //End of function recursiveTest()

/*Requirement #3 – Calculate ‘e’ using an iterative loop
iterativeTest
This function returns the time it takes to calculate result
using 'TERMS' Factorial terms, calculated with an Iterative Factorial function call.
*/
double iterativeTest() //stores iterative test result as double
{
    long double eIterative;        //Result of series being calculated
    clock_t beforeTime, afterTime; //Before process and After process time variables
    double duration;               //Calculated duration of test variable

    //Start test...
    puts("Starting calculation using the Iterative function...");
    beforeTime = clock(); //Record the time  since program launched

    //run the calculation for a defined number of times
    for (int x = 1; x <= TEST_REPEAT_COUNT; x++) //for loop start value at 1, check it satisfies condition & increment by 1 each time
    {
        eIterative = 0.0;
        //Calculate using the formula from question

        for (int count = 0; count <= TERMS; count++) // for loop starts count at 1, checks if it satisfies condtion & increments by 1 each time
        {
            eIterative += 1.0 / iterativeFactorial(count); // calculates series
        }                                                  //End of inner for
    }                                                      //End of TEST_REPEAT for

    afterTime = clock(); //Record the time since program launched

    duration = (double)(afterTime - beforeTime) / CLOCKS_PER_SEC; //Display duration in seconds, divide by the system constant 'CLOCKS_PER_SEC' from <time.h>

    //Output calculated and time taken recored
    printf("\te = %.16Lf\n", eIterative);                                    //display to 16 decimals
    printf("\tCalculation completed in a time of %f seconds\n\n", duration); //displays result with text
    return duration;
} //End of function iterativeTest()

//recursive definition of function recursiveFactorial
unsigned long long int recursiveFactorial(unsigned int number)
{

    if (number <= 1) //if loop, checks condition is met
    {
        return 1;
    } // end loop
    else
    {                                                     // recursive step
        return (number * recursiveFactorial(number - 1)); //else loop does recursive calc as long as condition satisfied
    }                                                     // end else
} // end function factorial

//Iterative loop
/*iterativeFactorial
Function returns a factorial value using an Iterative loop
parameter n - The input value whose factorial is to be calculated. ie. 1!, 2! ... n!
*/
unsigned long long int iterativeFactorial(unsigned int n) //integer can hold zero or positive numbers
{
    unsigned long long int factorial = 1;    //Initialise factorial to 1
    for (int count = n; count >= 1; count--) //for loop count set to n, check condition satisfied, decrement count
    {
        factorial *= count; //Increment factorial value with product of 'count'
    }
    return factorial; //return the factorial value.
}

/*ShowResult
Function shows the calc time for each process and compares
*/
void ShowResult(double recursiveTestDuration, double iterativeTestDuration) // fucntion does return result
{

    //Check if the Recursive function took longer.
    if (recursiveTestDuration > iterativeTestDuration) //if loop to test which is quicker
    {
        printf("\nThe Iterative process was %.1f times faster than the Recursive.\n\n",
               recursiveTestDuration / iterativeTestDuration); //if loop to test which is quicker
    }
    //Check if iterative took longer
    else if (recursiveTestDuration < iterativeTestDuration) //else if loop to test which is quicker
    {

        printf("\nThe Recursive process was %.1f times faster than the Iterative.\n\n",
               iterativeTestDuration / recursiveTestDuration);
    }
    //Check if calc time the same
    else
    {
        puts("\nThere was no performance difference between the Recursive and Iterative processes.\n");
    }
}
