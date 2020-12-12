//* Define a function called hypotenuse that calculates the length of the hypotenuse of a right triangle when the other two sides are given. Use this function in a program to determine the length of the hypotenuse for each of the following triangles. The function should take two arguments of type double and return the hypotenuse as a double. Test your program with the side values specified below:*/

#include <stdio.h> //perform I/O operations. Tells the preprocessor to include the "stdio.h" header file to support input/output operations
#include <math.h>  //*Declares a set of functions to compute common mathematical operations and transformations*/

double hypotenuse(double side1, double side2); //Function hyponetuse, takes two d

int main()
{
    //call the function hypotenuse three times and the result
    printf("Triangle 1: %.2f\n", hypotenuse(3.0, 4.0));
    printf("Triangle 2: %.2f\n", hypotenuse(5.0, 12.0));
    printf("Triangle 3: %.2f\n", hypotenuse(8.0, 15));
    return 0;
}

double hypotenuse(double side1, double side2)
{
    // calculate the hypotenuse using pythagoras theorem and return the result as double
    return sqrt(pow(side1, 2) + pow(side2, 2));
}
