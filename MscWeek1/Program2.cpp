/* Program read the radius of a circle and prints the circle's diameter, circumference and area */

#include <stdio.h> /* perform I/O operations. Tells the preprocessor to include the "stdio.h" header file to support input/output operations */

int main() /* initialize the function main */
{
  int radius, diameter;                      /* Declare variables type integer */
  double constantValue, circumference, area; /* Declare variables type double */

  printf("Please enter the radius of the circle: "); /* Display a prompting message asking for the circle radius */
  scanf("%d", &radius);                              /* Read input from keyboar */

  diameter = radius * 2; /* Calculate the diameter and print the result */
  printf("The diameter is: %d\n", diameter);

  constantValue = 3.14159;
  circumference = constantValue * diameter; /* Calculate the Circumference and print the result */
  printf("The circumference is: %f\n", circumference);

  area = constantValue * radius * radius; /* Calculate the area and print the result */
  printf("The area of the circle is: %f\n", area);

  return 0; /* End function Main. Exit */
}