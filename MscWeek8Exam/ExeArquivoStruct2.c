#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct alumnus
{
    int yearGraduated;
    char firstName[30];
    float salario;
};

struct alumnus *records;

void resizeArray(size_t n)
{
    /* TODO: Handle reallocations errors. */
    records = realloc(records, n * sizeof *records);
}

int main()
{
    system("clear");
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
    records = (struct alumnus *)malloc(sizeof(struct alumnus) * count);

    records[0].yearGraduated = 2020;
    printf("%d", records[0].yearGraduated);

    // condição que valida se o arquivo existe
    if ((fptr2 = fopen("Test.txt", "r")) != NULL)
    {
        for (i = 0; !feof(fptr2); i++)
        {
            fscanf(fptr2, "%d %s %f", &RECS[i].yearGraduated, RECS[i].firstName, &RECS[i].salario);
            printf("\n%d %s %f", RECS[i].yearGraduated, RECS[i].firstName, RECS[i].salario);
        }
    }

    /*
    1-Imprimir todos os structs
    2-Criar um array fixo de struct
    3-Criar um array dinamico de structs
    */

    free(records);

    return 0;
}