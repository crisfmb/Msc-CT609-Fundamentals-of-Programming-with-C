/* Write a program that reads in a file containing several lines of text and then prints only those strings that end with the letters “ed”.

The program should do the following:

 - Prompt the user for the name of a text file (if the file does not exist, display an error message and re-prompt)
 - Read in a series of strings from the text file and store these in an array of strings, dynamically allocating memory for each element
 - Loop through the populated string array and find elements that end with the characters "ed"
 - Display on screen a list of only those strings that end with "ed" 

 */

#include <stdio.h>  //performs I/O operations. Tells the preprocessor to include the "stdio.h" header file to support I/O operations
#include <stdlib.h> // Tells the preprocessor to include the "stdlib.h" header
#include <string.h> // Tells the preprocessor to include the "string.h" header which declares a set of functions to work strings

#define SIZE 30 // sets the maximum number of words that can be stored
#define LEN 31  // sets the maximum length of the word that can be stored

char name[SIZE][LEN]; // variable that defines the maximum number of words and word size

int readData(char *inFilename) // reads in a txt file with the name specified by the user
{

    int i = 0; // variable for the loop
    int last;  //variable to tell us how many owrds in the file

    FILE *fpPtr; // Pointer that shows the position of the memory file

    // Condition that checks if the file name entered exists
    if ((fpPtr = fopen(inFilename, "r")) == NULL)
    {
        // what happens if the file doesn't exist
        return 0;
    }
    else
    { //if the file exists
        // for loop that works through each line of the text file
        for (i = 0; !feof(fpPtr); i++) // for loop - when it gets to the end of the file it stops reading and stores the words
        {
            fscanf(fpPtr, "%s", name[i]); //stores the word
            //printf("%s \n", name[i]);
        }

        //defines the last location in the file
        last = i - 1;

        for (i = 0; i <= last; i++) // starts a for loop that goes through each word in the text file
        {
            char ultimaLetra;                           // declare a variable that stores the last letter
            ultimaLetra = name[i][strlen(name[i]) - 1]; // take the word that has been looked at and uses the "strlen" function to find the word length and uses -1 to return the final letter from the word

            char penultimaLetra;                           // declares a variable that stores the 2nd last letter in word
            penultimaLetra = name[i][strlen(name[i]) - 2]; // takes the word that has been looked at and uses "strlen" function to find the word lenght and uses the -2 to return the second last letter of the word

            //printf("%lu \n", strlen(name[i]));
            //printf("%c \n", penultimaLetra);
            //printf("%c \n", ultimaLetra);

            if (penultimaLetra == 'e') // if loop specifying condition to be satisfied to meet assignment requirements - requires second last letter to have a value "e"
            {
                if (ultimaLetra == 'd') // if loop specifying condition to be satisfied to meet assignment requirements - requies last two letters to have value "ed"
                {
                    printf("%s \n", name[i]); // prints the word if the specified requirements met i.e. end with "ed"
                }
            }
        }

        //closes the file
        fclose(fpPtr);

        return 1;
    }
}

int main()
{
    //system("clear");

    char inFilename[1000]; //specifies file names

    //Reads the name of the file to be sorted
    printf("Enter Input Filename > ");
    scanf("%s", inFilename);

    //checks if the file can be read
    if (readData(inFilename))
    {
        printf("File opened successfully"); //if file can be read, confirmes file opened
    }
    else
    {
        printf("File could not be opened"); //message returned if file cannot be opened
    }

    return 0;
}