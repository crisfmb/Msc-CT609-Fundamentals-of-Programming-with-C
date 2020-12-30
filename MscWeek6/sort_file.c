/* Write a program, called sort_file, which takes a text file as input and produces an output file which has all the original lines in alphabetical order.

The program should do the following:

* Prompt the user for the names of the input and output files. You can prepare an input file  with appropriate unsorted data. A simple file with one word per line will suffice.
* Declare and define three functions to perform the following tasks:

1. Read the data from the input file into an array.
2. Sort the array using the bubble sort algorithm.
3. Write the sorted data array to the output file.*/

#include <stdio.h>  //performs I/O operations. Tells the preprocessor to include the "stdio.h" header file to support I/O operations
#include <stdlib.h> // Tells the preprocessor to include the "stdlib.h" header
#include <string.h> // Tells the preprocessor to include the "string.h" header which declares a set of functions to work strings

#define SIZE 30 // defines the variable size
#define LEN 31  // defines variable length

char name[LEN][SIZE]; /* defines data type to be stored as character */

void bubbleSort(int last) //void specifies that the function doesn't return a value - bubble sort run in this section of code
{

    char hold[LEN]; //store the variable len
    int i, j;       /* indices of array */

    for (i = last; i > 0; i--) //for loop used with bubble sort. initially sets i to the last value, checks if i>0 and decrements the process after each loop
    {
        for (j = 1; j <= i; j++) //for loop starting with the first entry of the array j, sets the condition for j less than or equal to i, and increments j after each loop
        {
            if (strcmp(name[j], name[j - 1]) < 0) //if loop where two strings are compared
            {
                strcpy(hold, name[j]);        //compares the value stored in the variable Len with the name of string j
                strcpy(name[j], name[j - 1]); //compares the values of the string j and j-1
                strcpy(name[j - 1], hold);    // compares the values of the string j-1 and the value stored in variable hold
            }
        }
    }
}

void writeData(char *outFilename, int last) //void specifies that function doesn't return a value - writedata stores the sorted data in the output file
{

    FILE *fp; //filepointer
    int i;    // defines integer value for i

    fp = fopen(outFilename, "wt"); //filepointer telling output file to open for writing
    //writes out put to screen
    for (i = 0; i <= last; i++) //for loop - setting initial value of i, check condition if i less than or equal to "last and increment the process
    {
        printf("- %s \n", name[i]);              //writes the string on a new line
        fwrite(name[i], 1, sizeof(name[i]), fp); //writes the string specified
        fwrite("\n", 1, sizeof("\n"), fp);
    }

    fclose(fp);
}

int readData(char *inFilename, char *outFilename) //function that reads the file name entered for the inputs to be sorted and the output file to be written to
{

    int i = 0; /* indices of array */
    int last;  /* index of last item in array */

    FILE *fpPtr; //filepointer

    //Testa if the file will open
    if ((fpPtr = fopen(inFilename, "r")) == NULL)
    {
        return 0;
    }
    else
    {

        //scrolls through the file reading each line of  fpPtr
        for (i = 0; !feof(fpPtr); i++)
        {
            fscanf(fpPtr, "%s", name[i]); //reads formatted data
        }

        //last index in array
        last = i - 1;

        //closes the file
        fclose(fpPtr);

        //performs the sort
        bubbleSort(last);

        printf("Enter Output Filename > "); //writes the string "Enter Output Filename >"
        scanf("%s", outFilename);           //reads formated output data to ouput file

        writeData(outFilename, last); //writes the output data to output file

        return 1;
    }
}

int main()
{

    char inFilename[1000], outFilename[1000]; //specifies file names

    //Reads the name of the file to be sorted
    printf("Enter Input Filename > ");
    scanf("%s", inFilename);

    //checks if the file can be read
    if (readData(inFilename, outFilename))
    {
        printf("File opened successfully"); //if file can be read, confirmes file opened
    }
    else
    {
        printf("File could not be opened"); //message returned if file cannot be opened
    }

    return 0;
}