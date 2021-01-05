/* Write a program that reads in a file containing several lines of text and then prints only those strings that end with the letters “ed”.

The program should do the following:

 - Prompt the user for the name of a text file (if the file does not exist, display an error message and re-prompt)
 - Read in a series of strings from the text file and store these in an array of strings, dynamically allocating memory for each element
 - Loop through the populated string array and find elements that end with the characters "ed"
 - Display on screen a list of only those strings that end with "ed"*/

#include <stdio.h>  //performs I/O operations. Tells the preprocessor to include the "stdio.h" header file to support I/O operations
#include <stdlib.h> // Tells the preprocessor to include the "stdlib.h" header
#include <string.h> // Tells the preprocessor to include the "string.h" header which declares a set of functions to work strings

#define SIZE 30 // quantidade maxima de palavras que podem ser armazenadas no vetor
#define LEN 31  // tamanho maximo da palavra que pode ser armazenada dentro do vetor

char name[SIZE][LEN]; // vetor que determina a quantidade maxima de palavras e o tamanho maximo de cada palavra

int readData(char *inFilename) // le o arquivo txt de acordo com o nome informado no main
{

    int i = 0; // variavel para o laço de repetição
    int last;  //variavel auxiliar para saber quantas palavras tem no arquivo

    FILE *fpPtr; // Ponteiro que aponta para a posição do arquivo da memória

    // condição que valida se o arquivo existe
    if ((fpPtr = fopen(inFilename, "r")) == NULL)
    {
        // o arquivo não existe
        return 0;
    }
    else
    { //arquivo existe
        // for que percorre cada linha do arquivo
        for (i = 0; !feof(fpPtr); i++) // enquanto não o final do arquivo ele continuar lendo e armazena a palavra no vetor name
        {
            fscanf(fpPtr, "%s", name[i]); //armazena a palavra no vetor name
            //printf("%s \n", name[i]);
        }

        //last index in vetor
        last = i - 1;

        for (i = 0; i <= last; i++) // inicia o for que percorre todas as palavras do vetor name[i]
        {
            char ultimaLetra;                           // declara variavel ultima letra
            ultimaLetra = name[i][strlen(name[i]) - 1]; // ele pega a palavra que esta analisando utiliza a função strlen pra pegar o tamanho dela e utiliza o -1 para voltar uma posição na palavra

            char penultimaLetra;                           // declara variavel penultima letra
            penultimaLetra = name[i][strlen(name[i]) - 2]; // ele pega a palavra que esta analisando utiliza a função strlen pra pegar o tamanho dela e utiliza o -2 para voltar duas posições e pegar a penultima letra

        
            if (penultimaLetra == 'e') // inicia condicional if para validar se a penultima e a ultima letra atende os requisitos solicitados (ed)
            {
                if (ultimaLetra == 'd') // inicia condicional if para validar se a penultima e a ultima letra atende os requisitos solicitados (ed)
                {
                    printf("%s \n", name[i]); // se atender os requisitos imprime a palavra que termina em ed
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
