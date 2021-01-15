/* 
Function 1: load_data [20 marks]

This function is automatically called when the program is started. It loads employee records
from the supplied file. If the file does not exist, notify the user, create a new file and display
the main menu. Once the file is open, data is read into an array of structs by dynamically
creating sufficient memory for each entry read from the file. The struct should include a
“Subsidy Amount” float field, the amount of which is added for each employee after running
their details through a calculator function.
Define a struct to represent the information for an employee, containing at least the
following fields:
• employee_code (int)
• employee_name (char[])
• insurable_weeks (int)
• gross_pay (float)
• subsidy (float)

Function 2: display_menu [5 marks]

After the application is started, use this function to print a list of options to the user using a
numbered list. When the user selects an option, the system performs the required action,
and returns to the menu, waiting for the user to select another option. Include an option to
exit the system.
Your main menu system might resemble the following:
1. Add new employee
2. Delete employee
3. View all employees in the list
4. View only qualifying employees
5. View disqualified employees (and show reason)
6. Sort employees by name
7. Sort employees by subsidy amount
8. View total subsidy amount (total for all employees)
9. Exit

Function 3: add_new_employee [10 marks]

When the user selects the “Add new employee” menu item, prompt them for the data for
the new record. Append the new record to the array of current employees and notify the
user that the new record has been added successfully.
Function 4: delete_employee [10 marks]
When the user selects the “Delete employee” option, they are prompted for an
employee_code. This function then removes the relevant employee from the array and
notifies the user that it has been removed successfully.
Function 5: view_all_employees [5 marks]
When the user selects the “View all employees” option, this function prints a list of all
employees and their information on record. Make sure that the information is formatted
neatly with headers and appropriate tabs or spacing, not simply a list of raw information.

Function 6: view_qualifying_employees [8 marks]

When the user selects the “View only qualifying employees” option, this function prints a list
of all employees who qualify for the subsidy and their information on record. Make sure
that the information is formatted neatly with headers and appropriate tabs or spacing, not
simply a list of raw information.

Function 7: find_disqualified_employees [5 marks]

When the user selects the “View disqualified employees” option, this function prints a list of
all employees who do not qualify for the subsidy and includes a reason as to why they do not
qualify. Make sure that the information is formatted neatly with headers and appropriate
tabs or spacing, not simply a list of raw information.

Function 8: sort_employees_by_name [7 marks]

Give the user the option to sort employees by name. Store the sorted information in a file
and notify the user of the name of the file.

Function 9: sort_employees_by_subsidy_amount [5 marks]

When the user selects the “Sort employees by subsidy amount” menu option, this function
displays just the employees’ names and their subsidy amount sorted from highest to lowest.

Function 10: view_total_subsidy_amount [5 marks]

When the user selects the “View total subsidy amount” menu option, this function displays
the sum of all employee subsidies.


Function 11: save_data [20 marks]

This function is called when the user chooses to exit the system. Open a data file and write
out the information contained in the array.

 - salario < 151.50 < 203 por semana o subsidio será = 203 semanal
 - salario > 203    < 300 por semana o subsidio será = 250
 - salario > 300    < 400 por semana o subsidio será = 300
 - salario > 400    < 1462

  MIN >             MAX <=      SUBSIDY
  0                 151.50    0  
  151.50            203       203
  203               300       250 
  300               400       300
  400               1462      350 
  
  insurable weeks precisa ser entre 1 e 5 ou subsidy será 0
employee_code (int) 
employee_name (char[]) 
insurable_weeks (int)
gross_pay (float)
subsidy (float)

1- Ler o arquivo data.txt
    SE FUNCIONAR(arquivo existir) -> 
        -carrega funcionários (dinamicamente no formato respeitando o struct)
    SENÃO FUNCIONAR(arquivo não existir) -> 
        -notifica o usuário
        -cria um arquivo novo chamado Data.txt
        
2- -exibe menu

new bolas[]

bola [tamanho: , cor:, marca:]

bola.tamanho = pequena

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee /*struct e um tipo de modelo de dados ou variavel que contem variaveis dentro que podem ser de diferentes tipos. Todas as variaveis dentro de um vetor precisam ser do mesmo tipo e no struct não. NÃO ESQUECE A DIFERENÇA.
Nesse caso criei um modelo para armazenar as informações dos funcionários como o professor pediu no primeiro enunciado */
{
    int employee_code;
    char employee_name[1000];
    int insurable_weeks;
    float gross_pay;
    float subsidy;
};

void add_new_employee() //a primeira opção do menu pede pra chamar uma nova funcao onde add um novo funcionario, esse e o enunciado 2 do documento.(Função adiciona novo funcionário ao final do arquivo)
{

    struct Employee newEmployee;
    printf("Digite o código: ");
    scanf("%d", &newEmployee.employee_code);

    printf("%d", newEmployee.employee_code);
}

void display_menu() //aqui cria a função display_menu do enunciado dois. Exibe as opções do menu. só copiei e colei.
{

    int opcao;
    printf("1. Add new employee: \n");
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
    switch (opcao) //decidi colocar o switch aqui e não na função main pq no enunciado diz pra você ler uma opção. foi uma escolha ja que nao foi especificado nada.
    {
    case 1: // se a opção selecionada for a 1 faz o calculo de soma ou qualquer outra operação e imprime o valor
        add_new_employee();
        break;
    case 2: // se a opção selecionada for a 2 faz o calculo de soma ou qualquer outra operação e imprime o valor
        printf("Opcao 2 do Menu");
        break;
    case 3:
        printf("Opcao 3 do Menu");
        break;
    case 4:
        printf("Opcao 4 do Menu");
        break;
    case 5:
        printf("Opcao 5 do Menu");
        break;

    case 6:
        printf("Opcao 6 do Menu");
        break;
    case 7:
        printf("Opcao 7 do Menu");
        break;
    case 8:
        printf("Opcao 8 do Menu");
        break;
    case 9:
        printf("Opcao 9 do Menu");
        break;

    default: // se não for nenhuma das opções acima imprime opcao invalida
        printf("Opção invalida");
        break;
    }
}

int main() // inicia função principal
{
    display_menu();

    return 0;
}