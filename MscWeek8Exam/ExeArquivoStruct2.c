#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct alumnus
{
    int yearGraduated;
    char firstName[30];
    char lastName[30];
};

int main()
{
    int i = 0; // variavel para o laço de repetição
    int count = 0;
    FILE *fpPtr; // Ponteiro que aponta para a posição do arquivo da memória

    // condição que valida se o arquivo existe
    if ((fpPtr = fopen("Test.txt", "r")) == NULL)
    {
        printf("Arquivo não existe");
    }
    else
    {
        printf("Arquivo existe");

        char c;
        // Extract characters from file and store in character c
        for (c = getc(fpPtr); c != EOF; c = getc(fpPtr))
        {
            if (c == '\n')
            { // Increment count if this character is newline
                count = count + 1;
            }
        }

        // Close the file
        fclose(fpPtr);
        printf("The file has %d lines\n ", count);
        count = count + 1; //Conserta
    }

    FILE *fptr2;
    struct alumnus RECS[count];

    // condição que valida se o arquivo existe
    if ((fptr2 = fopen("Test.txt", "r")) != NULL)
    {
        for (i = 0; !feof(fptr2); i++)
        {
            fscanf(fptr2, "%d %s %s", &RECS[i].yearGraduated, RECS[i].firstName, RECS[i].lastName);
            printf("\n%d %s %s", RECS[i].yearGraduated, RECS[i].firstName, RECS[i].lastName);
        }
    }

    /*
    1-Imprimir todos os structs
    2-Criar um array fixo de struct
    3-Criar um array dinamico de structs
    */

    return 0;
}