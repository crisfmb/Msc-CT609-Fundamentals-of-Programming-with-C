/* 
Instrução de teste:



*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fpPtr;                  // Ponteiro que aponta para a posição do arquivo da memória
struct Employee *RECS = NULL; //coloquei o array dos funcionarios dinamica aqui para ser acessado de qualquer lugar do arquivo
int recs_count = 0;           // conta quantos registros tem no arquivo
int menu_quit = 0;            // Variavel auxiliar para quanto terminar de fazer uma função voltar para o menu

void display_menu(); // cabeçalho da função display menu. Para que ela possa ser chamada antes da linha que ela e definida

struct Employee /*struct e um tipo de modelo de dados ou variavel que contem variaveis dentro que podem ser de diferentes tipos. Todas as variaveis dentro de um vetor precisam ser do mesmo tipo e no struct não. NÃO ESQUECE A DIFERENÇA.
Nesse caso criei um modelo para armazenar as informações dos funcionários como o professor pediu no primeiro enunciado - Define os campos dos empregados */
{
    int employee_code;
    char employee_name[1000];
    char employee_lastname[1000];
    int insurable_weeks;
    float gross_pay;
    float subsidy;
};

float calculatesubsidy(int insurable_weeks, float gross_pay) //com base no insurable weeks e gross pay retornar o valor do subsidy que a pessoa vai receber
{

    float subsidy = 0;                                // variavel que vai guardar o valor final do subsidio de acordo com cada caso. Quando a gente precisa de um codigo muito grande mais de uma vez dentro do programa  a gente cria uma função para n ter que reescrever tudo novamente.
    if (insurable_weeks >= 1 && insurable_weeks <= 5) //condição criada com base na tabela informada no enunciado, estar entre 1 e 5 semana de insurable e as outras abaixo são as fauxas salariais.
    {
        if (gross_pay > 0 && gross_pay <= 151.50)
        {
            subsidy = 0.0;
        }
        else if (gross_pay > 151.50 && gross_pay <= 203)
        {
            subsidy = 203.0;
        }
        else if (gross_pay > 203 && gross_pay <= 300)
        {
            subsidy = 250.0;
        }
        else if (gross_pay > 300 && gross_pay <= 400)
        {
            subsidy = 300.0;
        }
        else if (gross_pay > 400 && gross_pay <= 1462)
        {
            subsidy = 350.0;
        }
    }
    return subsidy;
}

void save_data() //função  que tranfere o array de registros para o arquivo. Ele verifica o que tem na memória no momento e escreve no arquivo
{

    FILE *fp; //filepointer ponteiro do arquivo que aponta pro data e escreve as informação que ja estao no RECS e eu quero passar pro arquivo
    int i;    // defines integer value for i

    fp = fopen("data.txt", "w"); //filepointer telling output file to open for writing

    //writes output to file
    for (i = 0; i <= recs_count; i++) //for loop - setting initial value of i, check condition if i less than or equal to "last and increment the process. percorrendo todos os registros e escrevendo o arquivo.
    {

        char codeAsString[12];
        sprintf(codeAsString, "%d", RECS[i].employee_code);
        fputs(codeAsString, fp);
        fputs(" ", fp);
        fputs(RECS[i].employee_lastname, fp);
        fputs(" ", fp);
        fputs(RECS[i].employee_name, fp);
        fputs(" ", fp);
        sprintf(codeAsString, "%d", RECS[i].insurable_weeks); // converte os numeros para string. Escolhi o sprintf porque o fputs so aceita escrever variaveis do tipo string.
        fputs(codeAsString, fp);
        fputs(" ", fp);
        sprintf(codeAsString, "%.2f", RECS[i].gross_pay);
        fputs(codeAsString, fp);
        fputs(" ", fp);
        fputs("\n", fp);
    }

    fclose(fp);
}

void add_new_employee() //a primeira opção do menu pede pra chamar uma nova funcao onde add um novo funcionario, esse e o enunciado 2 do documento.(Função adiciona novo funcionário ao final do arquivo)
{

    struct Employee newEmployee; // le a informação para um novo funcionario 97 to 111
    printf("Digite o código: ");
    scanf("%d", &newEmployee.employee_code);

    printf("Digite o surname: ");
    scanf("%s", newEmployee.employee_lastname);

    printf("Digite o name: ");
    scanf("%s", newEmployee.employee_name);

    printf("Digite o insurable: ");
    scanf("%d", &newEmployee.insurable_weeks);

    printf("Digite o gross_pay: ");
    scanf("%f", &newEmployee.gross_pay);

    newEmployee.subsidy = calculatesubsidy(newEmployee.insurable_weeks, newEmployee.gross_pay); //calcula subsidio a partir do insurable weeks e gross pay

    printf("%d %s %s %d %.2f %f", newEmployee.employee_code, newEmployee.employee_lastname, newEmployee.employee_name, newEmployee.insurable_weeks, newEmployee.gross_pay, newEmployee.subsidy); // imprime as informaçoes que acabei de ler. feedback na tela

    //Aumentou o espaço na memória para o RECS (Alargou o bolso)
    RECS = realloc(RECS, (recs_count + 1) * sizeof(struct Employee));

    RECS[recs_count].employee_code = newEmployee.employee_code; // 120 to 125 - passa os valores do novo funcionario para a ultima posição nos registros
    strcpy(RECS[recs_count].employee_lastname, newEmployee.employee_lastname);
    strcpy(RECS[recs_count].employee_name, newEmployee.employee_name);
    RECS[recs_count].insurable_weeks = newEmployee.insurable_weeks;
    RECS[recs_count].gross_pay = newEmployee.gross_pay;
    RECS[recs_count].subsidy = newEmployee.subsidy;

    //recs_count++;

    save_data(); // 129 to 131 - atualiza o bd do arquivo e o usuario precisa digitar algo pra continuar no menu
    scanf("%d", &menu_quit);
    display_menu();
}

void view_all_employees() // função que mostra uma lista com todos os funcionários utilizando um "for"e imprime
{
    int i;
    for (i = 0; i < recs_count; i++)
    {
        printf("\n%d %s %s %d %.2f %.2f", RECS[i].employee_code, RECS[i].employee_lastname, RECS[i].employee_name, RECS[i].insurable_weeks, RECS[i].gross_pay, RECS[i].subsidy);
    }
    scanf("%d", &menu_quit); //digite qualquer coisa pra voltar p menu ai ele volta pro menu pra escolher outra opção displau_menu abaixo
    display_menu();
}

void view_qualifying_employees() // função que mostra todos os emplyees que são aptos para receber o subsidio. o for verifica se o emplyee esta dentro da semanas 1 a 5 e se o gross pay esta entre 151.50 e 1462 de acordo com o enunciado.
{
    int i;
    for (i = 0; i < recs_count; i++)
    {
        if (RECS[i].insurable_weeks >= 1 && RECS[i].insurable_weeks <= 5)
        {
            if (RECS[i].gross_pay > 151.50 && RECS[i].gross_pay < 1462)
            {
                printf("\n%d %s %s %d %.2f %.2f", RECS[i].employee_code, RECS[i].employee_lastname, RECS[i].employee_name, RECS[i].insurable_weeks, RECS[i].gross_pay, RECS[i].subsidy);
            }
        }
    }
    scanf("%d", &menu_quit); //digite qualquer coisa pra voltar p menu ai ele volta pro menu pra escolher outra opção displau_menu abaixo
    display_menu();
}

void find_disqualified_employees() // função que mostra os employees que não são qualificados e imprime na tela a lista deles com o motivo. o for verifica se o emplyee esta dentro da semanas 1 a 5 e se o gross pay esta entre 151.50 e 1462 de acordo com o enunciado.
{
    int i;
    for (i = 0; i < recs_count; i++)
    {
        if (RECS[i].insurable_weeks < 1 || RECS[i].insurable_weeks > 5)
        {
            printf("\n%d %s %s %d %.2f %.2f (Reason: Insurable Weeks)", RECS[i].employee_code, RECS[i].employee_lastname, RECS[i].employee_name, RECS[i].insurable_weeks, RECS[i].gross_pay, RECS[i].subsidy);
        }
        else if (RECS[i].gross_pay < 151.50 || RECS[i].gross_pay > 1462)
        {
            printf("\n%d %s %s %d %.2f %.2f (Reason: Gross Pay) ", RECS[i].employee_code, RECS[i].employee_lastname, RECS[i].employee_name, RECS[i].insurable_weeks, RECS[i].gross_pay, RECS[i].subsidy);
        }
    }
    scanf("%d", &menu_quit); //digite qualquer coisa pra voltar p menu ai ele volta pro menu pra escolher outra opção displau_menu abaixo
    display_menu();
}

void view_total_subsidy_amount() //função que mostra a soma total do subsidio de todos os employees
{

    float totalsubsidyamount = 0;
    int i;
    for (i = 0; i < recs_count; i++)
    {
        totalsubsidyamount = totalsubsidyamount + RECS[i].subsidy;
    }
    printf("The total subsidy amount is: %.2f", totalsubsidyamount);
    scanf("%d", &menu_quit); //digite qualquer coisa pra voltar p menu ai ele volta pro menu pra escolher outra opção
    display_menu();
}

void display_menu() //aqui cria a função display_menu do enunciado dois. Exibe as opções do menu. só copiei e colei.
{
    int i = 0; // variavel para o laço de repetição
    int count = 0;

    // condição que valida se o arquivo existe
    if ((fpPtr = fopen("data.txt", "r")) == NULL)
    {
        printf("Arquivo não existe");

        fpPtr = fopen("data.txt", "wt"); //filepointer telling output file to open for writing
        //writes out put to screen
    }
    else
    {

        char c;
        // Extract characters from file and store in character c
        for (c = getc(fpPtr); c != EOF; c = getc(fpPtr))
        {
            if (c == '\n')
            { // Increment count if this character is newline
                count = count + 1;
            }
        }

        // Close the file. Estava tendo alguns problemas de buffer então decidi colocar o fclose. Não sabia abrir o arquivoe e achei essa alternativa na internet.
        fclose(fpPtr);
        recs_count = count + 1; //Conserta a contagem de registros no vetor
        printf("The file has %d lines\n ", recs_count);

        FILE *fptr2;
        //aloca espaço na memoria necessario para armazenas os registros dos funcionarios.
        RECS = malloc(recs_count * sizeof(struct Employee));

        // condição que valida se o arquivo existe
        if ((fptr2 = fopen("data.txt", "r")) != NULL) // se ao abrir o arquivo for diferente de nulo o arquivo existe
        {
            for (i = 0; !feof(fptr2); i++) //percorre cada linha do arquivo
            {
                fscanf(fptr2, "%d %s %s %d %f", &RECS[i].employee_code, RECS[i].employee_lastname, RECS[i].employee_name, &RECS[i].insurable_weeks, &RECS[i].gross_pay); //le variaveis dentro do arquivo

                RECS[i].subsidy = calculatesubsidy(RECS[i].insurable_weeks, RECS[i].gross_pay); //passa os parametros do calculo do subsidio

                //printf("\n%d %s %s %d %.2f %.2f", RECS[i].employee_code, RECS[i].employee_lastname, RECS[i].employee_name, RECS[i].insurable_weeks, RECS[i].gross_pay, RECS[i].subsidy); exibe os registros lidos.
            }
        }
        fclose(fptr2);
    }

    int opcao;                           //opção que sera lida pelo usuario
    printf("\n1. Add new employee: \n"); //243 to 251 menu do usuario
    printf("2. Delete employee: \n");
    printf("3. View all employees in the list: \n");
    printf("4. View only qualifying employees: \n");
    printf("5. View disqualified employees (and show reason): \n");
    printf("6. Sort employees by name: \n");
    printf("7. Sort employees by subsidy amount: \n");
    printf("8. View total subsidy amount (total for all employees): \n");
    printf("9. Exit: \n");
    printf("Digite uma opção: ");
    scanf("%d", &opcao);
    switch (opcao) //decidi colocar o switch aqui e não na função main pq no enunciado diz pra você ler uma opção. foi uma escolha ja que nao foi especificado nada. utiliza o switch para criar o menu. opções fixas e nao intervalares.
    {
    case 1: // se a opção selecionada for a 1 faz o calculo de soma ou qualquer outra operação e imprime o valor
        printf("Opcao Escolhida: Adicionar Usuário: ");
        add_new_employee(); //chama a função de adicionar novo funcionario
        break;
    case 2: // se a opção selecionada for a 2 faz o calculo de soma ou qualquer outra operação e imprime o valor
        printf("Opcao 2 do Menu");
        break;
    case 3:
        printf("Opcao Escolhida: Visualiza todos os Employees: ");
        view_all_employees(); // chama função ver todos os funcionarios

        break;
    case 4:
        printf("Opcao Escolhida: Qualifying Emplyees: ");
        view_qualifying_employees();
        break;
    case 5:
        printf("Opcao Escolhida: Disqualified Employees: ");
        find_disqualified_employees();
        break;

    case 6:
        printf("Opcao 6 do Menu");
        break;
    case 7:
        printf("Opcao 7 do Menu");
        break;
    case 8:
        printf("Opcao Escolhida: Total Subsidio Amount: ");

        view_total_subsidy_amount();

        break;
    case 9:
        printf("Opcao 9 do Menu");
        system("clear");
        printf("The End");
        save_data();
        break;

    default: // se não for nenhuma das opções acima imprime opcao invalida
        printf("Opção invalida");
        break;
    }
}

int main() // inicia função principal
{

    display_menu();
    fclose(fpPtr);
    return 0;
}
