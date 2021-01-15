#include <stdlib.h> // Tells the preprocessor to include the "stdlib.h" header
#include <string.h>
#include <stdio.h>

typedef struct alumnus
{
    int yearGraduated;
    char firstName[30];
    char lastName[30];
} Alumns;

int main(void)
{

    Alumns REC1;

     FILE *fptr;
    //fptr = fopen("Test.txt", "r");
    int i;
    if ((fptr = fopen("Test.txt", "r")) == NULL)
    {
        // o arquivo não existe
        printf("Érro");
    }
    else
    { //arquivo existe
        // for que percorre cada linha do arquivo
        for (i = 0; !feof(fptr); i++)
        {
        }
    }
    printf("Linhas: %d", i);

    fscanf(fptr, "%d %s %s", &REC1.yearGraduated, REC1.firstName, REC1.lastName);

    printf("%d %s %s", REC1.yearGraduated, REC1.firstName, REC1.lastName);
}