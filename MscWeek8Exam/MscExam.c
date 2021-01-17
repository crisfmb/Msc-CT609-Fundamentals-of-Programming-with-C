/* 
Exam Instructions:

On the 23rd July 2020, the Irish Government announced an Employment Wage Subsidy
Scheme (EWSS) to help employers impacted by the Covid-19 pandemic. The aim of this
scheme is to provide a flat-rate subsidy to qualifying employers to allow them to retain as
many employees as possible. When payroll figures are submitted to Revenue, their software
will calculate how much subsidy to pay to the employer. But the employer would like to know
when processing the wages for employees how much that subsidy will be.

For the payroll user, an EWSS calculator is required to alert them if the employer will get the
subsidy for an employee based on the employee’s earnings in the payroll period.

The employer will get a subsidy for weekly paid employes if the number of insurable weeks
is between 1 and 5 and their gross pay is greater than €151.50 per week. The amount of the
subsidy is then determined by the gross pay. If an employee’s wages are less than €203 the
subsidy amount is €203. For employees earning between €203 and €300 per week the
subsidy is €250. Between €300 and €400 per week, an employee would get a subsidy of
€300. Finally, if an employee earns more than €400 per week, and up to and including €1462
per week, they will be entitled to a subsidy of €350 per week.

You have been asked to provide a system (using the C programming language) for analysing
a list of employees. The employee details will be provided as a text file. An example of an
entry is given below:

100001 Bloggs Joe 5 411

The entry above gives the employees Employee Code, Employee Last Name, First Name,
Insurable Weeks and Gross Pay.

Below is a list of required functions for the system

Function 1: load_data [20 marks]
This function is automatically called when the program is started. It loads employee records
from the supplied file. If the file does not exist, notify the user, create a new file and display
the main menu. Once the file is open, data is read into an array of structs by dynamically
creating sufficient memory for each entry read from the file. The struct should include a
“Subsidy Amount” float field, the amount of which is added for each employee after running
their details through a calculator function.
Define a struct to represent the information for an employee, containing at least the
following fields:
•	employee_code (int)
•	employee_name (char[])
•	insurable_weeks (int)
•	gross_pay (float)
•	subsidy (float)

Function 2: display_menu [5 marks]
After the application is started, use this function to print a list of options to the user using a
numbered list. When the user selects an option, the system performs the required action,
and returns to the menu, waiting for the user to select another option. Include an option to
exit the system.
Your main menu system might resemble the following:
1.	Add new employee
2.	Delete employee
3.	View all employees in the list
4.	View only qualifying employees
5.	View disqualified employees (and show reason)
6.	Sort employees by name
7.	Sort employees by subsidy amount
8.	View total subsidy amount (total for all employees)
9.	Exit

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
out the information contained in the array.*/

#include <stdio.h>  //performs I/O operations. Tells the preprocessor to include the "stdio.h" header file to support I/O operations
#include <stdlib.h> // Tells the preprocessor to include the "stdlib.h" header
#include <string.h> // Tells the preprocessor to include the "string.h" header which declares a set of functions to work strings

FILE *fpPtr;                  // Pointer that points to the position of the memory file
struct Employee *RECS = NULL; //put the array of dynamic employees here to be accessed from anywhere in the file
int recs_count = 0;           // counts how many records you have in the file
int menu_quit = 0;            // additional variable for when you finish making a function to return to the menu

void display_menu(); // header of the display menu function. So that it can be called before the line it is defined

struct Employee /*struct is a type of data declaration or variable that contains variables of different types. All variables within a vector must be of the same type and not in the struct. DON'T FORGET THE DIFFERENCE.
In this case, I created a template to store employee information as the examp asked in the first statement - Defines employee fields */

{
    int employee_code;            //defines an integer variable called employee_code
    char employee_name[1000];     // defines a character array called employee_name which can hold up to 1000 elements
    char employee_lastname[1000]; // defines a character array called employee_lastname which can hold up to 1000 elements
    int insurable_weeks;          // defines an integer variable called insurable weeks
    float gross_pay;              // defines a floating point data variable which can contina values that include a decimal point
    float subsidy;                // defines a floating point data variable which can contina vailes that include a decimal point
};

float calculatesubsidy(int insurable_weeks, float gross_pay) // based on the insurable weeks and gross pay return the amount of the subsidy that the person will receive
{

    float subsidy = 0;                                // variable that will hold the final amount of the subsidy for each case. When we need a very large code more than once inside the program we create a function so that we don't have to rewrite everything each time.
    if (insurable_weeks >= 1 && insurable_weeks <= 5) //condition created based on the table given requiring there to be between 1 and 5 week of insurable pay and the others below are the wage requirements.
    {
        if (gross_pay > 0 && gross_pay <= 151.50) //if loop for gross pay setting out the subsmidy payable for people in the 0-151.50 bracket
        {
            subsidy = 0.0; // subsmidy payable if condition met
        }
        else if (gross_pay > 151.50 && gross_pay <= 203) //else if loop setting out the subsidy payable for people in the 151.50-203 bracket
        {
            subsidy = 203.0; //subsidy payable if condition met
        }
        else if (gross_pay > 203 && gross_pay <= 300) // else if loop setting out subsidy payable for people in the 203-300 bracket
        {
            subsidy = 250.0; //subsidy payable if condition met
        }
        else if (gross_pay > 300 && gross_pay <= 400) //else if loop setting out subsidy payable for people in the 300-400 bracket
        {
            subsidy = 300.0; //subsidy payable if condition met
        }
        else if (gross_pay > 400 && gross_pay <= 1462) //else if loop setting out subsidy payable for people in the 400-1462 bracket
        {
            subsidy = 350.0; //subsidy payable if condition met
        }
    }
    return subsidy; //returns the subsidy value
}

void save_data() //function that transfers the array of records to the file. It checks what is currently in memory and writes to the file
{

    FILE *fp; //filepointer file pointer that points to the date and writes the information that is already in the RECS and I want to write to the file
    int i;    // defines integer value for i

    fp = fopen("data.txt", "w"); //filepointer telling output file to open for writing

    //writes output to file
    for (i = 0; i <= recs_count; i++) //for loop - setting initial value of i, check condition if i less than or equal to "last and increment the process. going through all the records and writing the file.
    {

        char codeAsString[12];                                //declares a character array that can hold 12 characters
        sprintf(codeAsString, "%d", RECS[i].employee_code);   //writes the string that is pointed to from the data file
        fputs(codeAsString, fp);                              //writes the string requested
        fputs(" ", fp);                                       //writes a space to the string in the data file
        fputs(RECS[i].employee_lastname, fp);                 //writes the employee_lastname to the string in the data file
        fputs(" ", fp);                                       //writes a space to the string in the data file
        fputs(RECS[i].employee_name, fp);                     //writes the employee_NAME to the string in the data file
        fputs(" ", fp);                                       //writes a space to the string in the data file
        sprintf(codeAsString, "%d", RECS[i].insurable_weeks); // converts numbers to string. I chose sprintf because fputs only accepts writing string variables.
        fputs(codeAsString, fp);                              //Writes codeAsString to data file
        fputs(" ", fp);                                       //writes a space to the data file
        sprintf(codeAsString, "%.2f", RECS[i].gross_pay);     //converts numbers to string, writes the gross pay from the record to the string.
        fputs(codeAsString, fp);                              //writes the codeAsString to data file
        fputs(" ", fp);                                       //writes a space to the file
        fputs("\n", fp);                                      //writes a new line to the file
    }

    fclose(fp); // instruction to close file
}

void add_new_employee() //the first option in the menu asks to call a new function where you can add a new employee, this is instruction 3 from the exam. (Function adds new employee at the end of the file)
{

    struct Employee newEmployee;             // read information for a new employeee
    printf("\nEnter employee code: ");       // prints instruction to screen
    scanf("%d", &newEmployee.employee_code); //reads in information entered by user

    printf("Enter employee surname: ");         //prints instruction to enter employee surname to the screen
    scanf("%s", newEmployee.employee_lastname); // reads in information entered by user

    printf("Enter employee first name: ");  //prints instruction input employee first name to the screen
    scanf("%s", newEmployee.employee_name); // reads the information entered by the user

    printf("Enter number of insurable week: "); // prints instruction to input number of insurable weeks to the screen
    scanf("%d", &newEmployee.insurable_weeks);  // reads the information entered by the user

    printf("Enter gross_pay: ");         // prints instruction to input gross pay to the screen
    scanf("%f", &newEmployee.gross_pay); // reads the information entred by the user

    newEmployee.subsidy = calculatesubsidy(newEmployee.insurable_weeks, newEmployee.gross_pay); //Calculates subsidy using insurable weeks and gross pay

    printf("%d %s %s %d %.2f %f", newEmployee.employee_code, newEmployee.employee_lastname, newEmployee.employee_name, newEmployee.insurable_weeks, newEmployee.gross_pay, newEmployee.subsidy); // prints information read in to screen

    //Increases memory space on records
    RECS = realloc(RECS, (recs_count + 1) * sizeof(struct Employee));

    RECS[recs_count].employee_code = newEmployee.employee_code;                // passes the value of the new employee added to the last line of the file
    strcpy(RECS[recs_count].employee_lastname, newEmployee.employee_lastname); // copies new employee name to file
    strcpy(RECS[recs_count].employee_name, newEmployee.employee_name);         //copies new employee name to file
    RECS[recs_count].insurable_weeks = newEmployee.insurable_weeks;            // copies new employee insurable weeks to file
    RECS[recs_count].gross_pay = newEmployee.gross_pay;                        // copies new employees gross pay to file
    RECS[recs_count].subsidy = newEmployee.subsidy;                            // copies new employees subsidy to file

    //recs_count++;

    save_data();             // updates file and user will then need to type a number to continue to menu
    scanf("%d", &menu_quit); // reads data and returns to menu
    display_menu();
}

void view_all_employees() // function that shows a list of all employees using a for statement and prints
{
    int i;
    for (i = 0; i < recs_count; i++) // for loop - starts at record 0, if i less than total number of records and increments
    {
        printf("\n%d %s %s %d %.2f %.2f", RECS[i].employee_code, RECS[i].employee_lastname, RECS[i].employee_name, RECS[i].insurable_weeks, RECS[i].gross_pay, RECS[i].subsidy); //prints information for record "i"
    }
    scanf("%d", &menu_quit); //type anything to go back to the menu then it goes back to the menu to choose another option displau_menu below
    display_menu();
}

void view_qualifying_employees() // function that shows all emplyees who are eligible to receive the subsidy. so it checks if the employee has between 1 to 5 of insurable pay and if the gross pay is between 151.50 and 1462 per exam paper
{
    int i;
    for (i = 0; i < recs_count; i++) // for loop - starts at record 0, if i less than total number of records and increments
    {
        if (RECS[i].insurable_weeks >= 1 && RECS[i].insurable_weeks <= 5) // if loop for records with 1-5 insurable weeks
        {
            if (RECS[i].gross_pay > 151.50 && RECS[i].gross_pay < 1462) // if loop for records with gross pay between 151.50 and 1462
            {
                printf("\n%d %s %s %d %.2f %.2f", RECS[i].employee_code, RECS[i].employee_lastname, RECS[i].employee_name, RECS[i].insurable_weeks, RECS[i].gross_pay, RECS[i].subsidy); // prints records that satisfy conditions of both if loops
            }
        }
    }
    scanf("%d", &menu_quit); //type anything to go back to the menu then it goes back to the menu to choose another option display_menu below
    display_menu();
}

void find_disqualified_employees() // function that shows employees who are not qualified and prints their list with the reason on the screen. so it checks if the employee has between 1 to 5 of insurable pay and if the gross pay is between 151.50 and 1462 per exam paper.
{
    int i;
    for (i = 0; i < recs_count; i++)
    {
        if (RECS[i].insurable_weeks < 1 || RECS[i].insurable_weeks > 5)
        {
            printf("\n%d %s %s %d %.2f %.2f (Reason: Insurable Weeks)", RECS[i].employee_code, RECS[i].employee_lastname, RECS[i].employee_name, RECS[i].insurable_weeks, RECS[i].gross_pay, RECS[i].subsidy); // prints records that satisfy conditions of if loop
        }
        else if (RECS[i].gross_pay < 151.50 || RECS[i].gross_pay > 1462)
        {
            printf("\n%d %s %s %d %.2f %.2f (Reason: Gross Pay) ", RECS[i].employee_code, RECS[i].employee_lastname, RECS[i].employee_name, RECS[i].insurable_weeks, RECS[i].gross_pay, RECS[i].subsidy); // prints records that satisfy conditions of if loop
        }
    }
    scanf("%d", &menu_quit); //type anything to go back to the menu then it goes back to the menu to choose another option displau_menu below
    display_menu();
}

void view_total_subsidy_amount() //function that shows the total sum of the subsidy payable to all employees
{

    float totalsubsidyamount = 0;    //variable that will hold a decimal number
    int i;                           //integer
    for (i = 0; i < recs_count; i++) //for loop and conditions of loop
    {
        totalsubsidyamount = totalsubsidyamount + RECS[i].subsidy; // total subsidy amount calculated by adding the subsidy payable for each record.
    }
    printf("The total subsidy amount is: %.2f", totalsubsidyamount); // print total subsidy amount to screen
    scanf("%d", &menu_quit);                                         //type anything to go back to the menu then it goes back to the menu to choose another option
    display_menu();
}

void display_menu() //here it creates the function display_menu. Displays menu options.
{
    int i = 0; // variable for loop
    int count = 0;

    // condition that checks if file exists
    if ((fpPtr = fopen("data.txt", "r")) == NULL)
    {
        printf("File doesn't exist");

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

        // Close the file. I was having some buffering problems so I decided to put fclose. I didn't know how to open the file and found this alternative on the internet.
        fclose(fpPtr);
        recs_count = count + 1;                         //Increments the record count
        printf("The file has %d lines\n ", recs_count); //prints the number of lines in record

        FILE *fptr2;
        //allocates space in the memory needed to store employee records.
        RECS = malloc(recs_count * sizeof(struct Employee));

        // condition to check file exists
        if ((fptr2 = fopen("data.txt", "r")) != NULL) // if opening the file isn't null, file exists
        {
            for (i = 0; !feof(fptr2); i++) //for loop going through each line of file
            {
                fscanf(fptr2, "%d %s %s %d %f", &RECS[i].employee_code, RECS[i].employee_lastname, RECS[i].employee_name, &RECS[i].insurable_weeks, &RECS[i].gross_pay); //variables in the file

                RECS[i].subsidy = calculatesubsidy(RECS[i].insurable_weeks, RECS[i].gross_pay); //gives the parameters for the subsidy calculation

                //printf("\n%d %s %s %d %.2f %.2f", RECS[i].employee_code, RECS[i].employee_lastname, RECS[i].employee_name, RECS[i].insurable_weeks, RECS[i].gross_pay, RECS[i].subsidy); //prints the data
            }
        }
        fclose(fptr2);
    }

    int opcao;                                                            //option that will be read in by user
    printf("\n1. Add new employee: \n");                                  //user menu - prints text in function then goes to new line
    printf("2. Delete employee: \n");                                     //prints text in function then goes to new line
    printf("3. View all employees in the list: \n");                      //prints text in function then goes to new line
    printf("4. View only qualifying employees: \n");                      //prints text in function then goes to new line
    printf("5. View disqualified employees (and show reason): \n");       //prints text in function then goes to new line
    printf("6. Sort employees by name: \n");                              //prints text in function then goes to new line
    printf("7. Sort employees by subsidy amount: \n");                    //prints text in function then goes to new line
    printf("8. View total subsidy amount (total for all employees): \n"); //prints text in function then goes to new line
    printf("9. Exit: \n");                                                //prints text in function then goes to new line
    printf("Enter option: \n");                                           // prints text prompting user to enter option
    scanf("%d", &opcao);
    switch (opcao) //I decided to use the switch function here and not in the main function because the statement tells us to read an option, it was a choice since nothing was specified. uses the switch to create the menu. fixed and non-interval options.
    {
    case 1: // if the selected option is 1 it carries out the operaration and prints the value
        printf("Chosen option - Add user: ");
        add_new_employee(); //calls the function to add new employee
        break;
    case 2: // if the selected option is 2 it carries out the operation and prints the value
        printf("Menu option 2");
        break;
    case 3: // if the selected option is 3 it carries out the operation and prints the value
        printf("Chosen Option - View all Employees: ");
        view_all_employees(); // chama função ver todos os funcionarios

        break;
    case 4: // if the selected option is 4 it carries out the operation and prints the value
        printf("Chosen option - Qualifying Emplyees: ");
        view_qualifying_employees();
        break;
    case 5: // if the selected option is 5 it carries out the operation and prints the value
        printf("Option chosen - Disqualified Employees: ");
        find_disqualified_employees();
        break;

    case 6: // if the selected option is 6 it carries out the operation and prints the value
        printf("Menu option 6");
        break;
    case 7: // if the selected option is 7 it carries out the operation and prints the value
        printf("Menu option 7");
        break;
    case 8: // if the selected option is 8 it carries out the operation and prints the value
        printf("Chosen option - Total Subsidy Amount: ");

        view_total_subsidy_amount(); //returns total subsidy amount calculated

        break;
    case 9: // if the selected option is 9 it carries out the operation and prints the value
        printf("Menu option 9: ");
        system("clear");
        printf("\nThe End");
        save_data();
        break;

    default: // if none of the above options are selected, print invalid option
        printf("Invalid option");
        break;
    }
}

int main() // start main function
{

    display_menu();
    fclose(fpPtr);
    return 0;
}