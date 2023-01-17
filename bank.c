/**
*
* @brief this is the function of the this is the information related to bank management system
* @file bank.c
* @note this file only contains the code related to bank management
system
* @date 2023-01-16
* @copyright Copyright (c) 2023
* @see main()
* visit main function for the reference to the execution of code
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //required for string function
#include <windows.h>
#include <stdbool.h>
#include <conio.h> // required for getch()
#include "store.h"
#include <unistd.h> // for sleep
#include "hospital.h"
int i,
    a, b, j;
int exit_menu;
struct date
{
    int month, day, year;
};

struct user
{
    char user_name[50];
    char gender[10];
    char email[50];
    int account_number, age;
    char user_address[40];
    char user_citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit_amt;
    struct date withdraw_amt;
} _insert, _edit, _cheak, _delete, _amount;
/**
* @brief these are the user defined function
* @note this file only contains the user defined function related to bank
management system
*/
void HEADER_head();
void HEADER();
int SUB_HEADER(int bal);
void choice_B_S_H();
int password();
void _quit();
void loading();
void _manipulate_user();
float bank_interest(float time, float _amount, int rate);
void _view_user_list();
float deposit(float balance);
float withdraw(float balance);
void atm_menu();
void exit_atm_service();
void _end_program(void);
void _main_menu(void);
void _error();
void balance_query(float balance);

void _insert_user();
void _edit_user(void);
void transaction_amt(void);
void _delete_user(void);
void _detail_view_user_list();
void atm();
void rectangle_format_wd();
/**
* @brief this is the function required to make a rectangular frame of "*"
and "#"
* @see rectangle_format_wd()
* visit the function for the reference to the execution of code
*/
void rectangle_format_wd()
{
    int i, a;
    // top
    gotoxy(48, 8);
    // printf(BLUEB);
    for (i = 1; i <= 90; i++)
    {
        printf("#");
    }
    // left
    a = 48;
    for (i = 9; i <= 19; i++)
    {
        gotoxy(a, i);
        printf("*");
    }
    // right
    a = 137;
    for (i = 9; i <= 19; i++)
    {
        gotoxy(a, i);
        printf("*");
    }
    // down
    gotoxy(48, 20);
    for (i = 1; i <= 90; i++)
    {
        printf("#");
    }
}

/**
* @brief this is the function required to to give header file of
"Customer Management System"
* @see HEADER_head()
* visit the function for the reference to the execution of code
*/
void HEADER_head()
{
    printf("\n");
    for (i = 1; i <= 182; i++)
    {
        printf("\xCD");
    }
    gotoxy(81, 2);
    printf(" WELCOME TO ");
    gotoxy(73, 3);
    printf(" CUSTOMER MANAGEMENT SYSTEM ");
    printf("\n");
    for (i = 1; i <= 182; i++)
    {
        printf("\xCD");
    }
}
/**
 * @brief this is the front page of our project ..
 * @see HEADER()
 * visit the function for the reference to the execution of code
 */

void HEADER()
{
    int i;
    system("cls");
    HEADER_head();
    gotoxy(70, 6);
    printf(" PRESENTED TO YOU BY : MANAGEMENT CREW ");
    rectangle_format();
    gotoxy(70, 10);
    puts(UWHITE " TEAM MEMBERS NAME ");
    puts(RESET);
    gotoxy(70, 12);
    puts(" [1]. GARIMA SHAKYA [ TEAM LEADER ]");
    gotoxy(70, 14);
    puts(" [2]. ROMAN BHUJU [ CO-LEADER ]");
    gotoxy(70, 16);
    puts(" [3]. BIKASH KUMAR MAHATO [ CODER ]");
    gotoxy(70, 18);
    puts(WHITE "PRESS ANY KEY TO CONTINUE : ");
    printf(RESET);
    getch();
}
/**
 * @brief this is the function of sub header of the project
 * @see SUB_HEADER()
 * visit the function for the reference to the execution of code
 */
int SUB_HEADER(int bal)
{
    int i;
    system("cls");
    for (i = 0; i <= 181; i++)
    {
        printf(BLUE "=");
    }
    printf("\n");
    gotoxy(88, 1);
    printf(BLUE "BANK");

    gotoxy(82, 2);
    printf(BLUE "MANAGEMENT SYSTEM\n");
    for (i = 0; i <= 181; i++)
    {
        printf(BLUE "=");
    }
}
/**
 * @brief this is the function of loading page
 * @see loading()
 * visit the function for the reference to the execution of code
 */
void loading()
{
    int i;
    {
        system("cls");
        HEADER_head();
        rectangle_format_wd();
        gotoxy(50, 10);
printf(" HOPE ! THIS SOFTWARE TURN OUT TO BE PRODUCTIVE FOR YOU
...");
gotoxy(50, 11);
printf(" JUST FOLLOW THE INSTRUCTION/GUIDELINES...");
gotoxy(50, 12);
printf(" AND YOU WILL HAVE BETTER UNDERSTANDING ABOUT THE

FUNCTIONING OF OUR PROGRAM. :)");

gotoxy(50, 15);
printf(" LOADING ");
gotoxy(60, 15);
printf("\033[5m.\033[0m");
sleep(1);
gotoxy(62, 15);
printf("\033[5m.\033[0m");
sleep(1);
gotoxy(64, 15);
printf("\033[5m.\033[0m");
sleep(1);

gotoxy(66, 15);
printf("\033[5m.\033[0m");
sleep(1);
gotoxy(68, 15);
printf("\033[5m.\033[0m");
sleep(1);
printf(RESET);
fflush(stdout);
    }
}
/**
* @brief this is the function where a user has to insert username and
password to login the page
* @see password()
* visit the function for the reference to the execution of code
*/
int password()
{
    system("cls");
    HEADER_head();
    fflush(stdin);
    char username[20];
    static char password[6];
    int b;
    gotoxy(71, 6);
    puts(" ENTER USERNAME AND PASSWORD TO LOGIN ");
    rectangle_format();
    gotoxy(71, 10);
    printf("ENTER ADMIN USERNAME: ");
    printf(BLUE);
    scanf("%s", &username);
    if (strcmpi(username, "bikash") == 0 || strcmpi(username, "garima") == 0 || strcmpi(username, "roman") == 0 || strcmpi(username, "coder-bikash") == 0)
    {
int i = 0;
char character, pass[20], password[20];
gotoxy(71, 12);
printf(GREENB);

printf(GREEN "USERNAME VERIFIED");
sleep(1);
gotoxy(88, 12);
printf(GREEN "\033[5m.\033[0m");
sleep(1);
gotoxy(90, 12);
printf(GREEN "\033[5m.\033[0m");
sleep(1);
gotoxy(92, 12);
printf(GREEN "\033[5m.\033[0m");
printf(RESET);
gotoxy(71, 14);
printf("NOW, PLEASE ENTER THE PASSWORD : ");
// infinite loop
while (1)
{
    printf(BLUE);
    character = _getch(); // put input character in memory
    // check condition to mask input data
    if (character == 13)
    {
        password[i] = '\0';
        break;
    }
    else if (character == 8)
    {
        i--;
        printf("\b \b"); // \b means to move curser backward
    }
    else
    {
        password[i] = character;
        i++;
        printf("*");
    }
}

if (strcmp(password, "bikash") == 0 || strcmp(password, "garima")

                                           == 0)
{
    b = 1;
}
else
{
    b = 0;
}
    }
    return b;
}
/**
* @brief It is the interface of management system where the user has to
select the topic of related field...
* @see choice_B_S_H()
* visit the function for the reference to the execution of code
*/
void choice_B_S_H()
{
    int ch;
    system("cls");
    HEADER_head();
    gotoxy(68, 10);
    puts(UWHITE " WHICH FIELD YOU ARE FROM ? ");
    rectangle_format();
    gotoxy(68, 12);
    printf(YELLOW " [1]. BANK MANAGEMENT SYSTEM");
    gotoxy(68, 13);
    printf(YELLOW " [2]. HOSPITAL MANAGEMENT SYSTEM");
    gotoxy(68, 14);
    printf(YELLOW " [3]. STORE MANAGEMENT SYSTEM");
    gotoxy(68, 15);
    printf(YELLOW " [4]. EXIT");
    gotoxy(69, 17);
    printf(GREEN "Enter a choice: ");
    scanf("%d", &ch);
    switch (ch)

    {
    case 1:
system("cls");
_main_menu();
break;
    case 2:
main_menu_();
break;
    case 3:
int choice;
system("cls");
gotoxy(71, 6);
SUB_HEADER(0);
rectangle_format(); // set cursor in

a certain location based on given coordinates

    int A = 68; // given contant

value to x - coordinate
                 gotoxy(A, 6);
printf(RESET);
printf(" HI !! WHAT DO YOU WANT TO DO HERE ?? "); // ask user that

what he / she want to do... gotoxy(A, 10);
printf(YELLOW "[1]. EXPLORE PRODUCTS "); //[6] View customer's

list

    gotoxy(A, 11);
printf("[2]. EXPLORE CUSTOMERS "); //[4] Check the account details
gotoxy(A, 12);
printf("[3]. EXIT ");
gotoxy(A, 15);
printf(BBLUE "PLEASE, ENTER YOUR CHOICE : "); // ask user to

choose "one" among 1 to 5 scanf("%d", &choice);
system("cls");
switch (choice)
{
case 1:
    department_menu();
    break;

case 2:
    main_menu();
    break;
case 3:
    _end_program();
}
    case 4:
system("cls");
_quit();
break;
    default:
_quit();
    }
    getch();
}
/**
* @brief Here, the operator can insert the details of the user in bank
management system
* @see _insert_user()
* visit the function for the reference to the execution of code
*/
void _insert_user()
{
    int choice;
    FILE *fp;
    fp = fopen("bank_info.dat", "a+");
account_number:
    system("cls");
    gotoxy(71, 6);
    printf(UWHITE " INSERT USER DETAILS ");
    fflush(stdin);
    gotoxy(71, 9);
    printf(YELLOW "ENTER TODAY'S DATE (YYYY/MM/DD): ");
    scanf("%d/%d/%d", &_insert.deposit_amt.year,
          &_insert.deposit_amt.month, &_insert.deposit_amt.day);

    fflush(stdin);
    int A = 71;
    gotoxy(A, 10);
    printf("ENTER ACCOUNT NUMBER : ");
    scanf("%d", &_cheak.account_number);
    fflush(stdin);
    while (fscanf(fp, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f
                              % d / % d / % d\n ", &_insert.account_number, _insert.user_name, &_insert.dob.day,
                          & _insert.dob.month,
                  &_insert.dob.year, &_insert.age, _insert.user_address,
                  _insert.user_citizenship, _insert.gender, _insert.email, &_insert.phone,
                  _insert.acc_type, &_insert.amt, &_insert.deposit_amt.month,
                  &_insert.deposit_amt.day, &_insert.deposit_amt.year) != EOF)
    {
if (_cheak.account_number == _insert.account_number)
{
    printf("ACCOUNT NUMBER IS ALREADY IN USE :)");
    getch();
    goto account_number;
}
    }
    _insert.account_number = _cheak.account_number;
    gotoxy(A, 11);
    printf("ENTER USERNAME : ");
    gets(_insert.user_name);
    fflush(stdin);
    gotoxy(A, 12);
    printf("ENTER DATE OF BIRTH (YYYY//MM/DD) : ");
    scanf("%d/%d/%d", &_insert.dob.year, &_insert.dob.month,
          &_insert.dob.day);
    fflush(stdin);
    gotoxy(A, 13);
    printf("ENTER GENDER : ");
    gets(_insert.gender);
    fflush(stdin);

    gotoxy(A, 14);
    printf("Enter AGE : ");
    scanf("%d", &_insert.age);
    fflush(stdin);
    gotoxy(A, 15);
    printf("ENTER ADDRESS : ");
    gets(_insert.user_address);
    fflush(stdin);
    gotoxy(A, 16);
    printf("ENTER E-MAIL : ");
    gets(_insert.email);
    fflush(stdin);
    gotoxy(A, 17);
    printf("ENTER PHONE NUMBER : ");
    scanf("%lf", &_insert.phone);
    fflush(stdin);
    gotoxy(A, 18);
    printf("ENTER YOUR CITIZENSHIP NUMBER : ");
    scanf("%s", _insert.user_citizenship);
    fflush(stdin);
    gotoxy(A, 19);
    printf("ENTER THE AMOUNT YOU WANT TO DEPOSIT : RS. ");
    scanf("%f", &_insert.amt);
    fflush(stdin);
    gotoxy(A, 20);
    printf("TYPE OF ACCOUNT : ");
    gotoxy(A, 21);
    printf("$ SAVING ");
    gotoxy(A, 22);
    printf("$ CURRENT ");
    gotoxy(A, 23);

    printf("$ FIXED1 (FOR 1 YEAR) ");
    gotoxy(A, 24);
    printf("$ FIXED2 (FOR 2 YEAR) ");
    gotoxy(A, 25);
    printf("$ FIXED1 (FOR 3 YEAR) ");
    gotoxy(A, 26);
    printf("ENTER YOUR CHOICE : ");
    gets(_insert.acc_type);
    fprintf(fp, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d\n",
            _insert.account_number, _insert.user_name, _insert.dob.day,
            _insert.dob.month, _insert.dob.year, _insert.age, _insert.user_address,
            _insert.user_citizenship, _insert.gender, _insert.email, _insert.phone,
            _insert.acc_type, _insert.amt, _insert.deposit_amt.month,
            _insert.deposit_amt.day, _insert.deposit_amt.year);
    fclose(fp);
    gotoxy(A, 27);
    printf("ACCOUNT CREATED SUCCESSFULLY !!");
INVALID:
    gotoxy(A, 29);
    printf(" ENTER [1] TO GO BACK [0] TO EXIT !! ");
    scanf("%d", &exit_menu);
    system("cls");
    if (exit_menu == 1)
_main_menu();
    else if (exit_menu == 0)
    {
_end_program();
    }
    else
    {
gotoxy(A, 30);
printf("INVALID INPUT !! ");
goto INVALID;
    }
}
/**
* @brief Here, the operator can delete the details of the user in bank
management system
* @see _delete_user()
* visit the function for the reference to the execution of code
*/
void _delete_user(void)
{
    char yn[2];
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("bank_info.dat", "r");
    newrec = fopen("new.dat", "w");
    system("cls");
    SUB_HEADER(0);
    gotoxy(65, 7);
    printf("ENTER THE ACCOUNT NUMBER OF THE CUSTOMER : ");
    scanf("%d", &_delete.account_number);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d",
                  &_insert.account_number, _insert.user_name, &_insert.dob.day,
                  &_insert.dob.month, &_insert.dob.year, &_insert.age, _insert.user_address,
                  _insert.user_citizenship, _insert.gender, _insert.email, &_insert.phone,
                  _insert.acc_type, &_insert.amt, &_insert.deposit_amt.month,
                  &_insert.deposit_amt.day, &_insert.deposit_amt.year) != EOF)
    {
if (_insert.account_number == _delete.account_number)
{
    gotoxy(71, 10);
    printf(YELLOW "ACCOUNT NO : %d ", _insert.account_number);
    gotoxy(71, 11);
    printf("USER NAME : %s ", _insert.user_name);
    gotoxy(71, 12);
    printf("DATE OF BIRTH : %d / %d / %d ", _insert.dob.year,

           _insert.dob.month, _insert.dob.day);

    gotoxy(71, 13);
    printf("ADDRESS : %s ", _insert.user_address);
    gotoxy(71, 14);
    printf("EMAIL : %s ", _insert.email);

    gotoxy(71, 15);
    printf("CITIZENSHIP NUMBER : %s ", _insert.user_citizenship);
    gotoxy(71, 16);
    printf("AGE : %d ", _insert.age);
    gotoxy(71, 17);
    printf("PHONE NUMBER : %.0lf ", _insert.phone);
    gotoxy(71, 18);
    printf("TYPE OF ACCOUNT : %s ", _insert.acc_type);
    gotoxy(70, 20);
    printf(RED "DO YOU WANT OT DELETE THE USER ID (y/n) : ");
    scanf("%s", yn);
    if (strcmpi(yn, "Y") == 0)
    {
        test++;
        gotoxy(70, 22);
        printf(RED "RECORD DELETED SUCCESSFULLY !!");
        printf(RESET);
    }
    else
    {
        _main_menu();
    }
}
else
{
    fprintf(newrec, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f
                        % d / % d / % d\n ", _insert.account_number, _insert.user_name, _insert.dob.day,
                                      _insert.dob.month,
            _insert.dob.year, _insert.age, _insert.user_address,
            _insert.user_citizenship, _insert.gender, _insert.email, _insert.phone,
            _insert.acc_type, _insert.amt, _insert.deposit_amt.month,
            _insert.deposit_amt.day, _insert.deposit_amt.year);
}
    }
    fclose(old);
    fclose(newrec);
    remove("bank_info.dat");
    rename("new.dat", "bank_info.dat");

    if (test == 0)
    {
gotoxy(65, 8);
printf("RECORD NOT FOUND !! ");
    erase_invalid:
gotoxy(65, 24);
printf("ENTER [0] TO TRY AGAIN [1] TO GO BACK [2] TO EXIT !! ");
scanf("%d", &exit_menu);
if (exit_menu == 1)
    _main_menu();
else if (exit_menu == 2)
    _end_program();
else if (exit_menu == 0)
    _delete_user();
else
{
    gotoxy(65, 25);
    printf("INVALID !!");
    goto erase_invalid;
}
    }
    else
    {
gotoxy(65, 10);
printf("ENTER [1] TO GO BACK [0] TO EXIT !! ");
scanf("%d", &exit_menu);
system("cls");
if (exit_menu == 1)
    _main_menu();
else
    _end_program();
    }
}

/**
* @brief Here, the operator can the do transaction related of the user
account in bank management system
* @see transaction_user()

* visit the function for the reference to the execution of code
*/
void transaction_amt(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("bank_info.dat", "r");
    newrec = fopen("new.dat", "w");
    system("cls");
    SUB_HEADER(0);
    gotoxy(70, 6);
    printf(YELLOW "ENTER THE ACCOUNT NUMBER OF THE CUSTOMER : ");
    scanf("%d", &_amount.account_number);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d",
                  &_insert.account_number, _insert.user_name, &_insert.dob.day,
                  &_insert.dob.month, &_insert.dob.year, &_insert.age, _insert.user_address,
                  _insert.user_citizenship, _insert.gender, _insert.email, &_insert.phone,
                  _insert.acc_type, &_insert.amt, &_insert.deposit_amt.month,
                  &_insert.deposit_amt.day, &_insert.deposit_amt.year) != EOF)
    {
if (_insert.account_number == _amount.account_number)
{
    test = 1;
    if (strcmpi(_insert.acc_type, "fixed1") == 0 ||

        strcmpi(_insert.acc_type, "fixed2") == 0 || strcmpi(_insert.acc_type, "fixed3") == 0)
    {
        gotoxy(70, 7);
printf("YOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED

ACCOUNTS !!!!!");

system("cls");
_main_menu();
    }
    rectangle_format();
    gotoxy(71, 10);
    printf(YELLOW "ACCOUNT NO : %d ", _insert.account_number);
    gotoxy(71, 11);
    printf("USER NAME : %s ", _insert.user_name);
    gotoxy(71, 12);

    printf("DATE OF BIRTH : %d / %d / %d ", _insert.dob.year,

           _insert.dob.month, _insert.dob.day);

    gotoxy(71, 13);
    printf("ADDRESS : %s ", _insert.user_address);
    gotoxy(71, 14);
    printf("EMAIL : %s ", _insert.email);
    gotoxy(71, 15);
    printf("CITIZENSHIP NUMBER : %s ", _insert.user_citizenship);
    gotoxy(71, 16);
    printf("AGE : %d ", _insert.age);
    gotoxy(71, 17);
    printf("PHONE NUMBER : %.0lf ", _insert.phone);
    gotoxy(71, 18);
    printf("TYPE OF ACCOUNT : %s ", _insert.acc_type);
    gotoxy(71, 19);
    printf("CURRENT BALANCE : %.2f ", _insert.amt);
    gotoxy(70, 22);
    printf("WHAT DO YOU WANT TO DO ?");
    gotoxy(70, 24);
    printf("[1]. DEPOSIT ");
    gotoxy(70, 25);
    printf("[2]. WITHDRAW ");
    gotoxy(70, 26);
    printf("ENTER A CHOICE : ");
    scanf("%d", &choice);
    if (choice == 1)
    {
gotoxy(70, 29);
printf("ENTER THE AMOUNT YOU WANT TO DEPOSIT : RS. ");
scanf("%f", &_amount.amt);
_insert.amt += _amount.amt;
fprintf(newrec, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f
                    % d / % d / % d\n ", _insert.account_number, _insert.user_name, _insert.dob.day,
                                  _insert.dob.month,
        _insert.dob.year, _insert.age, _insert.user_address,
        _insert.user_citizenship, _insert.gender, _insert.email, _insert.phone,
        _insert.acc_type, _insert.amt, _insert.deposit_amt.month,
        _insert.deposit_amt.day, _insert.deposit_amt.year);

gotoxy(70, 31);
printf("SUCCESSFULLY DEPOSITED !!");
    }
    else if (choice == 2)
    {
gotoxy(70, 29);
printf("ENTER THE AMOUNT YOU WANT TO WITHDRAW : RS. ");
scanf("%f", &_amount.amt);
_insert.amt -= _amount.amt;
fprintf(newrec, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f
                    % d / % d / % d\n ", _insert.account_number, _insert.user_name, _insert.dob.day,
                                  _insert.dob.month,
        _insert.dob.year, _insert.age, _insert.user_address,
        _insert.user_citizenship, _insert.gender, _insert.email, _insert.phone,
        _insert.acc_type, _insert.amt, _insert.deposit_amt.month,
        _insert.deposit_amt.day, _insert.deposit_amt.year);

gotoxy(70, 31);
printf("SUCCESSFULLY WITHDRAWN !! ");
    }
    else
    {
fprintf(newrec, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f
                    % d / % d / % d\n ", _insert.account_number, _insert.user_name, _insert.dob.day,
                                  _insert.dob.month,
        _insert.dob.year, _insert.age, _insert.user_address,
        _insert.user_citizenship, _insert.gender, _insert.email, _insert.phone,
        _insert.acc_type, _insert.amt, _insert.deposit_amt.month,
        _insert.deposit_amt.day, _insert.deposit_amt.year);

gotoxy(71, 10);
printf(RED "RECORD NOT FOUND ");
getch();
    }
}
else
{
    fprintf(newrec, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f
                        % d / % d / % d\n ", _insert.account_number, _insert.user_name, _insert.dob.day,
                                      _insert.dob.month,
            _insert.dob.year, _insert.age, _insert.user_address,
            _insert.user_citizenship, _insert.gender, _insert.email, _insert.phone,
            _insert.acc_type, _insert.amt, _insert.deposit_amt.month,
            _insert.deposit_amt.day, _insert.deposit_amt.year);
}
    }
    fclose(old);

    fclose(newrec);
    remove("bank_info.dat");
    rename("new.dat", "bank_info.dat");
    if (test != 1)
    {
gotoxy(71, 10);
printf(RED "RECORD NOT FOUND ");
    EDIT_INVALID:
gotoxy(71, 11);
printf("ENTER [1] TO GO BACK [0] TO EXIT !! ");
scanf("%d", &exit_menu);
system("cls");
if (exit_menu == 1)
    _main_menu();
else if (exit_menu == 0)
{
    _end_program();
}
else
{
    gotoxy(71, 10);
    printf("INVALID INPUT !! ");
    goto EDIT_INVALID;
}
    }
    else
    {
gotoxy(68, 32);
printf("ENTER [1] TO GO BACK [0] TO EXIT !!");
scanf("%d", &exit_menu);
system("cls");
if (exit_menu == 1)
    _main_menu();
else
    _end_program();
    }
}

/**
* @brief Here, the operator can edit the details of the user in bank
management system
* @see _edit_user()
* visit the function for the reference to the execution of code
*/
void _edit_user(void)
{
    int choice, test = 0;
    FILE *fp, *fp2;
    fp = fopen("bank_info.dat", "r");
    fp2 = fopen("new.dat", "w");
_edit_loop:
    system("cls");
    SUB_HEADER(0);
    gotoxy(68, 6);
    printf(UWHITE "ENTER THE ACCOUNT NUMBER YOU WANT TO MODIFY : ");
    scanf("%d", &_edit.account_number);
    while (fscanf(fp, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d",
                  &_insert.account_number, _insert.user_name, &_insert.dob.day,
                  &_insert.dob.month, &_insert.dob.year, &_insert.age, _insert.user_address,
                  _insert.user_citizenship, _insert.gender, _insert.email, &_insert.phone,
                  _insert.acc_type, &_insert.amt, &_insert.deposit_amt.month,
                  &_insert.deposit_amt.day, &_insert.deposit_amt.year) != EOF)
    {
if (_insert.account_number == _edit.account_number)
{
    gotoxy(71, 10);
    printf(YELLOW "ACCOUNT NO : %d ", _insert.account_number);
    gotoxy(71, 11);
    printf("USER NAME : %s ", _insert.user_name);
    gotoxy(71, 12);
    printf("DATE OF BIRTH : %d / %d / %d ", _insert.dob.year,

           _insert.dob.month, _insert.dob.day);

    gotoxy(71, 13);
    printf("ADDRESS : %s ", _insert.user_address);
    gotoxy(71, 14);
    printf("EMAIL : %s ", _insert.email);

    gotoxy(71, 15);
    printf("CITIZENSHIP NUMBER : %s ", _insert.user_citizenship);
    gotoxy(71, 16);
    printf("AGE : %d ", _insert.age);
    gotoxy(71, 17);
    printf("PHONE NUMBER : %.0lf ", _insert.phone);
    gotoxy(71, 18);
    printf("TYPE OF ACCOUNT : %s ", _insert.acc_type);
    test = 1;
    gotoxy(68, 23);
    printf("WHICH INFORMATION DO YOU WANT TO CHANGE ?");
    rectangle_format();
    gotoxy(68, 24);
    printf("[1]. ADDRESS");
    gotoxy(68, 25);
    printf("[2]. E-MAIL");
    gotoxy(68, 26);
    printf("[3]. PHONE");
    gotoxy(68, 28);
    printf("ENTER YOUR CHOICE : ");
    scanf("%d", &choice);
    if (choice == 1)
    {
gotoxy(68, 30);
fflush(stdin);
printf("ENTER THE NEW ADDRESS : ");
gets(_edit.user_address);
fflush(stdin);
fprintf(fp2, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f
                 % d / % d / % d\n ", _insert.account_number, _insert.user_name, _insert.dob.day,
                               _insert.dob.month,
        _insert.dob.year, _insert.age, _edit.user_address,
        _insert.user_citizenship, _insert.gender, _insert.email, _insert.phone,
        _insert.acc_type, _insert.amt, _insert.deposit_amt.month,
        _insert.deposit_amt.day, _insert.deposit_amt.year);

gotoxy(68, 31);
printf("CHANGES SAVED !!");
    }
    else if (choice == 2)
    {
gotoxy(68, 29);

printf("ENTER THE NEW E-MAIL : ");
scanf("%s", &_edit.email);
fprintf(fp2, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f
                 % d / % d / % d\n ", _insert.account_number, _insert.user_name, _insert.dob.day,
                               _insert.dob.month,
        _insert.dob.year, _insert.age, _insert.user_address,
        _insert.user_citizenship, _insert.gender, _edit.email, _insert.phone,
        _insert.acc_type, _insert.amt, _insert.deposit_amt.month,
        _insert.deposit_amt.day, _insert.deposit_amt.year);

gotoxy(68, 31);
printf("CHANGES SAVED !!");
    }
    else if (choice == 3)
    {
gotoxy(68, 29);
printf("ENTER THE NEW PHONE NUMBER :");
scanf("%lf", &_edit.phone);
fprintf(fp2, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f
                 % d / % d / % d\n ", _insert.account_number, _insert.user_name, _insert.dob.day,
                               _insert.dob.month,
        _insert.dob.year, _insert.age, _insert.user_address,
        _insert.user_citizenship, _insert.gender, _insert.email, _edit.phone,
        _insert.acc_type, _insert.amt, _insert.deposit_amt.month,
        _insert.deposit_amt.day, _insert.deposit_amt.year);

gotoxy(68, 31);
printf("CHANGES SAVED !!");
    }
}
else
{
    fprintf(fp2, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f
                     % d / % d / % d\n ", _insert.account_number, _insert.user_name, _insert.dob.day,
                                   _insert.dob.month,
            _insert.dob.year, _insert.age, _insert.user_address,
            _insert.user_citizenship, _insert.gender, _insert.email, _insert.phone,
            _insert.acc_type, _insert.amt, _insert.deposit_amt.month,
            _insert.deposit_amt.day, _insert.deposit_amt.year);
}
    }
    fclose(fp);
    fclose(fp2);
    remove("bank_info.dat");
    rename("new.dat", "bank_info.dat");

    if (test != 1)
    {
gotoxy(71, 10);
printf(RED "RECORD NOT FOUND ");
    EDIT_INVALID:
gotoxy(71, 11);
printf("ENTER [1] TO GO BACK [0] TO EXIT !! ");
scanf("%d", &exit_menu);
system("cls");
if (exit_menu == 1)
    _main_menu();
else if (exit_menu == 0)
{
    _end_program();
}
else
{
    gotoxy(71, 10);
    printf("INVALID INPUT !! ");
    goto EDIT_INVALID;
}
    }
    else
    {
gotoxy(68, 32);
printf("ENTER [1] TO GO BACK [0] TO EXIT !!");
scanf("%d", &exit_menu);
system("cls");
if (exit_menu == 1)
    _main_menu();
else
    _end_program();
    }
}

/**

* @brief Here, interest can be added to user balance in determined time
in bank management system
* @see bank_interest()
* visit the function for the reference to the execution of code
*/
float bank_interest(float time, float _amount, int rate)
{
    float SI;
    SI = (rate * time * _amount) / 100.0;
    return (SI);
}

/**
* @brief Here the operator can view all the details of the user in bank
management system
* @see _view_user_list()
* visit the function for the reference to the execution of code
*/
void _view_user_list()
{
    FILE *fp;
    fp = fopen("bank_info.dat", "r");
    int test = 0;
    system("cls");
    gotoxy(70, 1);
    printf(BYELLOW);
    printf("CUSTOMER INFORMATION LIST\n");
    for (i = 1; i <= 168; i++)
    {
printf("-");
    }
    a = 3;
    gotoxy(1, a);
    printf("AC_NO");
    gotoxy(25, a);
    printf("USER NAME");
    gotoxy(50, a);
    printf("ADDRESS");

    gotoxy(75, a);
    printf("PHONE_NO");
    gotoxy(100, a);
    printf("AGE");
    gotoxy(125, a);
    printf("EMAIL");
    gotoxy(150, a);
    printf("BALANCE");
    printf("\n");
    for (i = 1; i <= 168; i++)
    {
printf("-");
    }
    i = 6;
    while (fscanf(fp, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f %d/%d/%d",
                  &_insert.account_number, _insert.user_name, &_insert.dob.day,
                  &_insert.dob.month, &_insert.dob.year, &_insert.age, _insert.user_address,
                  _insert.user_citizenship, _insert.gender, _insert.email, &_insert.phone,
                  _insert.acc_type, &_insert.amt, &_insert.deposit_amt.month,
                  &_insert.deposit_amt.day, &_insert.deposit_amt.year) != EOF)
    {
test = 1;
gotoxy(1, i);
printf("%d", _insert.account_number);
gotoxy(25, i);
printf("%s", _insert.user_name);
gotoxy(50, i);
printf("%s", _insert.user_address);
gotoxy(75, i);
printf("%lf", _insert.phone);
gotoxy(100, i);
printf("%d", _insert.age);
gotoxy(125, i);
printf("%s", _insert.email);
gotoxy(150, i);
printf("%f", _insert.amt);
i++;
    }

    fclose(fp);
    if (test == 0)
    {
system("cls");
printf("\n\nNO RECORDS FOUND !!");
    }
view_list_invalid:
    printf("\n\nENTER [1] TO GO BACK AND [0] TO EXIT : ");
    scanf("%d", &exit_menu);
    system("cls");
    if (exit_menu == 1)
_main_menu();
    else if (exit_menu == 0)
_end_program();
    else
    {
printf("INVALID INPUT !!\a");
goto view_list_invalid;
    }
}

/**
 * @brief this is the last interface of bank management for thanks giving.
 * @see _end_program()
 * visit the function for the reference to the execution of code
 */
void _end_program(void)
{
    printf("\n\n\n\nThank You!");
}

/**
* @brief this is the content for entering in bank management system for
further activity
* @see _main_menu()
* visit the function for the reference to the execution of code

*/
void _main_menu()
{
    int ch;
    system("cls");
    system("color 7");
    SUB_HEADER(0);
    rectangle_format();
    gotoxy(71, 6); // set cursor
    in a certain location based on given coordinates
        printf(REDB " HI !! WHAT DO YOU WANT TO DO HERE ?? "); // ask user
    that what he / she want to do... int A = 68;               // given
    contant value to x - coordinate
                             gotoxy(A, 10);
    printf(YELLOW "[1]. VIEW USER DETAILS"); //[6] View customer's list
    gotoxy(A, 11);
    printf("[2]. SEARCH USERS DETAILS "); //[4] Check the account details
    gotoxy(A, 12);
    printf("[3]. MANIPULATE USER DETAILS "); //[1] Create new account[2]
    Edit existing account[5] Remove existing accoun[3] Transactions
        gotoxy(A, 13);
    printf("[4]. ATM SERVICE "); // [7]. atm service
    gotoxy(A, 14);
    printf("[5]. EXIT ");
    gotoxy(A, 16);
    printf(BBLUE "PLEASE, ENTER YOUR CHOICE : "); // ask user to choose
    "one" among 1 to 5 scanf("%d", &ch);
    system("cls");
    switch (ch)
    {
    case 1:
_view_user_list(); // view_list();
break;
    case 2:
_detail_view_user_list(); // see();
break;
    case 3:

_manipulate_user();
    case 4:
atm(); // atm();
break;
    case 5:
_end_program(); // _end_program();
break;
    }
}
/**
* @brief this is just an interface in bank management system for
manipulating data
* @see _manipulate_user()
* visit the function for the reference to the execution of code
*/
void _manipulate_user()
{
    int choice;
    system("cls");
    system("color 7");
    SUB_HEADER(0);
    rectangle_format();
    gotoxy(71, 6); // set cursor
    in a certain location based on given coordinates
        printf(REDB " HI !! WHAT DO YOU WANT TO DO HERE ?? "); // ask user
    that what he / she want to do... int A = 68;               // given
    contant value to x - coordinate
                             gotoxy(A, 10);
    printf(YELLOW "[1]. INSERT USER DETAILS "); //[6] View customer's list
    gotoxy(A, 11);
    printf("[2]. EDIT USER DETAILS "); //[4] Check the account details
    gotoxy(A, 12);
    printf("[3]. DO TRANSACTIONS "); //[1] Create new account[2] Edit
    existing account[5] Remove existing accoun[3] Transactions
        gotoxy(A, 13);
    printf("[4]. DELETE USER DETAILS "); // [7]. atm service
    gotoxy(A, 14);
    printf("[5]. EXIT ");

    gotoxy(67, 16);
    printf(BBLUE "PLEASE, ENTER YOUR CHOICE : "); // ask user to choose
    "one" among 1 to 5 scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:
_insert_user(); // new_acc();
break;
    case 2:
_edit_user(); // _edit();
break;
    case 3:
transaction_amt(); // transact();
break;
    case 4:
_delete_user(); // _delete_user();
break;
    case 5:
_end_program(); // _end_program();
break;
    }
}
/**
 * @brief this is the main body of all there management
 * i.e. [1]. Bank Mangement System
 * i.e. [2]. Hospital Mangement System
 * i.e. [3]. Store Mangement System
 * @see main()
 * visit the function for the reference to the execution of code
 */
int main()
{
    system("cls");
    int b;
    HEADER();

    loop = false;
    atm();
}
else if (choose == 2)
{
    loop = false;
    exit_atm_service();
}
else
{
    atm_menu();
}
printf(RESET);
}
/**
* @brief this is the main body for entering in bank management system for
further activity
* @see atm_menu()
* visit the function for the reference to the execution of code
*/
void atm_menu()
{
    gotoxy(80, 6);
    printf(UBLUE " WELCOME TO ATM MENU ");
    gotoxy(75, 9);
    printf(UYELLOW " WHAT DO YOU WANT TO DO ?? ");
    gotoxy(75, 11);
    printf(YELLOW " [1]. CHEAK BALANCE ");
    gotoxy(75, 13);
    printf(" [2]. DEPOSIT MONEY ");
    gotoxy(75, 15);
    printf(" [3]. WITHDRAW MONEY ");
    gotoxy(75, 17);
    printf(" [4]. EXIT ");
}
/**
* @brief this is for cheaking the balance of atm
* @see balance_query(float balance)

* visit the function for the reference to the execution of code
*/
void balance_query(float balance)
{
    system("cls");
    SUB_HEADER(0);
    rectangle_format();
    gotoxy(66, 10);
    printf(UWHITE "HI !! YOU WANT TO CHECK BALANCE OF YOUR ACCOUNT ");
    gotoxy(66, 12);
    printf(GREEN "YOUR AVAILABLE BALANCE IS : RS.%.2f", balance);
    printf(RESET);
}

/**
 * @brief this is for depositing the balance of atm
 * @see deposit(float balance)
 * visit the function for the reference to the execution of code
 */
float deposit(float balance)
{
    system("cls");
    SUB_HEADER(0);
    rectangle_format();
    float deposit;
    gotoxy(66, 9);
    printf(GREEN " YOUR BALANCE IS : RS.%.2f ", balance);
    gotoxy(66, 10);
    printf(UWHITE " YOU WANT TO DEPOSIT YOUR MONEY .... ");
    printf(RESET);
    gotoxy(66, 11);
    printf("ENTER THE AMOUNT YOU WANT TO DEPOSIT : ");
    scanf("%f", &deposit);
    balance += deposit;
    gotoxy(66, 13);
    printf("YOUR NEW BALANCE IS : RS.%.2f", balance);
    return balance;
}

/**
 * @brief this is for withdrawing the balance of atm
 * @see withdraw(float balance)
 * visit the function for the reference to the execution of code
 */
float withdraw(float balance)
{
    system("cls");
    SUB_HEADER(0);
    rectangle_format();
    float withdraw;
    bool back = true;
    gotoxy(66, 9);
    printf(GREEN "YOUR BALANCE IS : RS. %.2f", balance);
    gotoxy(66, 10);
    printf(UWHITE "HI SIR !! YOU WANT TO WITHDRAW MONEY ");
    printf(RESET);
    while (back)
    {
gotoxy(66, 12);
printf("ENTER THE AMOUNT YOU WANT TO WITHDRAW : RS. ");
scanf("%f", &withdraw);
if (withdraw < balance)
{
    back = true;
    balance -= withdraw;
    gotoxy(66, 13);
    printf("YOU WANT TO WITHDRAW : RS.%.2f", withdraw);
    gotoxy(66, 14);
    printf("YOUR NEW BALANCE IS : RS. %.2f", balance);
    getch();
    break;
}
else

{
    gotoxy(66, 6);
    printf(" YOU DON'T HAVE ENOUGH BALANCE IN YOUR ACCOUNT ");
    gotoxy(66, 7);
printf(" PLEASE VISIT TO THE BANK FOR ANY TRANSACTION QUERIES

");

gotoxy(66, 8);
printf("YOUR CURRENT BALANCE IS: RS. %.2f ", balance);
getch();
break;
}
    }
    return balance;
} // money wi

/**
 * @brief this is for exit atm service...
 * @see balance_query(float balance)
 * visit the function for the reference to the execution of code
 */
void exit_atm_service()
{
    system("cls");
    gotoxy(70, 17);
    printf(" THANKS FOR VISITING ATM SERVICE ");
    gotoxy(70, 19);
    printf(" I AM VERY PLEASED TO SEE YOU HERE... ");
} // exit menu

/**
 * @brief this is for invalid character
 * @see _error()
 * visit the function for the reference to the execution of code
 */
void _error()
{

    printf("SORRY !! YOU HAVE SELECTED INVALID NUMBER ,PRESS ANY KEY...");
}

/**
 * @brief this is for viewing the details of users in berief
 * @see _ _detail_view_user_list()
 * visit the function for the reference to the execution of code
 */
void _detail_view_user_list()
{
    system("cls");
    SUB_HEADER(0);
    FILE *old;
    int test = 0, rate;
    int choice;
    float time;
    float intrst;
    old = fopen("bank_info.dat", "r");
    rectangle_format();
    printf(YELLOW);
    gotoxy(77, 10);
    printf("DO YOU WANT TO CHEAK BY :");
    gotoxy(71, 12);
    printf("[1]. ACCOUNT NUMBER");
    gotoxy(71, 13);
    printf("[2]. NAME ");
    gotoxy(71, 15);
    printf("ENTER YOUR CHOICE : ");
    scanf("%d", &choice);
    if (choice == 1)
    {
gotoxy(71, 17);
printf("ENTER THE ACCOUNT NUMBER :");
scanf("%d", &_cheak.account_number);
while (fscanf(old, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f
                           % d / % d / % d ", &_insert.account_number, _insert.user_name, &_insert.dob.day,
                       & _insert.dob.month,
              &_insert.dob.year, &_insert.age, _insert.user_address,

              _insert.user_citizenship, _insert.gender, _insert.email, &_insert.phone,
              _insert.acc_type, &_insert.amt, &_insert.deposit_amt.month,
              &_insert.deposit_amt.day, &_insert.deposit_amt.year) != EOF)

{
if (_insert.account_number == _cheak.account_number)
{
system("cls");
SUB_HEADER(0);
test = 1;
rectangle_format();
gotoxy(71, 9);
printf(UWHITE " USER INFORMATION ");
gotoxy(71, 10);
printf(YELLOW "ACCOUNT NO : %d ", _insert.account_number);
gotoxy(71, 11);
printf("USER NAME : %s ", _insert.user_name);
gotoxy(71, 12);
printf("DATE OF BIRTH : %d / %d / %d ", _insert.dob.year,

       _insert.dob.month, _insert.dob.day);
gotoxy(71, 13);
printf("ADDRESS : %s ", _insert.user_address);
gotoxy(71, 14);
printf("CITIZENSHIP NUMBER : %s ",

       _insert.user_citizenship);
gotoxy(71, 15);
printf("AGE : %d ", _insert.age);
gotoxy(71, 16);
printf("PHONE NUMBER : %.0lf ", _insert.phone);
gotoxy(71, 17);
printf("TYPE OF ACCOUNT : %s ", _insert.acc_type);
gotoxy(71, 18);
printf("BALANCE AMOUNT : %.2f", _insert.amt);
if (strcmpi(_insert.acc_type, "fixed1") == 0)
{
    time = 1.0;
    rate = 9;
    intrst = bank_interest(time, _insert.amt, rate);
    gotoxy(66, 20);

    printf("YOU WILL GET RS.%.2f AS INTEREST ON %d/%d/%d",

           intrst, _insert.deposit_amt.month, _insert.deposit_amt.day,
           _insert.deposit_amt.year + 1);
}
else if (strcmpi(_insert.acc_type, "fixed2") == 0)
{
    time = 2.0;
    rate = 11;
    intrst = bank_interest(time, _insert.amt, rate);
    gotoxy(66, 20);
    printf("YOU WILL GET RS.%.2f AS INTEREST ON %d/%d/%d",

           intrst, _insert.deposit_amt.month, _insert.deposit_amt.day,
           _insert.deposit_amt.year + 2);
}
else if (strcmpi(_insert.acc_type, "fixed3") == 0)
{
    time = 3.0;
    rate = 13;
    intrst = bank_interest(time, _insert.amt, rate);
    gotoxy(66, 20);
    printf("YOU WILL GET RS.%.2f AS INTEREST ON %d/%d/%d",

           intrst, _insert.deposit_amt.month, _insert.deposit_amt.day,
           _insert.deposit_amt.year + 3);
}
else if (strcmpi(_insert.acc_type, "saving") == 0)
{
    time = (1.0 / 12.0);
    rate = 8;
    intrst = bank_interest(time, _insert.amt, rate);
    gotoxy(68, 20);
printf("INTEREST AMOUNT ON %dth OF EVERY MONTH :

%.2f", _insert.deposit_amt.day, intrst);
}
else if (strcmpi(_insert.acc_type, "current") == 0)
{
gotoxy(71, 20);
printf("YOU WILL NOT GET BANK INTEREST.");
}
}
}
    }
    else if (choice == 2)
    {
gotoxy(71, 17);
printf("ENTER THE USER NAME :");
scanf("%s", &_cheak.user_name);
while (fscanf(old, "%d %s %d/%d/%d %d %s %s %s %s %lf %s %f
                           % d / % d / % d ", &_insert.account_number, _insert.user_name, &_insert.dob.day,
                       & _insert.dob.month,
              &_insert.dob.year, &_insert.age, _insert.user_address,
              _insert.user_citizenship, _insert.gender, _insert.email, &_insert.phone,
              _insert.acc_type, &_insert.amt, &_insert.deposit_amt.month,
              &_insert.deposit_amt.day, &_insert.deposit_amt.year) != EOF)

{
if (strcmpi(_insert.user_name, _cheak.user_name) == 0)
{
system("cls");
test = 1;
rectangle_format();
gotoxy(71, 9);
printf(UWHITE " USER INFORMATION ");
gotoxy(71, 10);
printf(YELLOW "ACCOUNT NO : %d ", _insert.account_number);
gotoxy(71, 11);
printf("USER NAME : %s ", _insert.user_name);
gotoxy(71, 12);
printf("DATE OF BIRTH : %d / %d / %d ", _insert.dob.year,

       _insert.dob.month, _insert.dob.day);
gotoxy(71, 13);
printf("ADDRESS : %s ", _insert.user_address);
gotoxy(71, 14);
printf("CITIZENSHIP NUMBER : %s ",

       _insert.user_citizenship);
gotoxy(71, 15);
printf("AGE : %d ", _insert.age);
gotoxy(71, 16);
printf("PHONE NUMBER : %.0lf ", _insert.phone);
gotoxy(71, 17);
printf("TYPE OF ACCOUNT : %s ", _insert.acc_type);
gotoxy(71, 18);

printf("AMOUNT DEPOSITED : %d ", _insert.amt);
gotoxy(71, 19);
printf("DATE OF DEPOSIT : %d / %d / %d ",
       _insert.deposit_amt.year, _insert.deposit_amt.month,
       _insert.deposit_amt.day);

if (strcmpi(_insert.acc_type, "fixed1") == 0)
{
time = 1.0;
rate = 9;
intrst = bank_interest(time, _insert.amt, rate);
gotoxy(66, 20);
printf("YOU WILL GET RS.%.2f AS INTEREST ON %d/%d/%d",

       intrst, _insert.deposit_amt.month, _insert.deposit_amt.day,
       _insert.deposit_amt.year + 1);
}
else if (strcmpi(_insert.acc_type, "fixed2") == 0)
{
time = 2.0;
rate = 11;
intrst = bank_interest(time, _insert.amt, rate);
gotoxy(66, 20);
printf("YOU WILL GET RS.%.2f AS INTEREST ON %d/%d/%d",

       intrst, _insert.deposit_amt.month, _insert.deposit_amt.day,
       _insert.deposit_amt.year + 2);
}
else if (strcmpi(_insert.acc_type, "fixed3") == 0)
{
time = 3.0;
rate = 13;
intrst = bank_interest(time, _insert.amt, rate);
gotoxy(66, 20);
printf("YOU WILL GET RS.%.2f AS INTEREST ON %d/%d/%d",

       intrst, _insert.deposit_amt.month, _insert.deposit_amt.day,
       _insert.deposit_amt.year + 3);
}
else if (strcmpi(_insert.acc_type, "saving") == 0)
{
time = (1.0 / 12.0);
rate = 8;

intrst = bank_interest(time, _insert.amt, rate);
gotoxy(68, 20);
printf("INTEREST AMOUNT ON %dth OF EVERY MONTH :

%.2f", _insert.deposit_amt.day, intrst);
}
else if (strcmpi(_insert.acc_type, "current") == 0)
{
gotoxy(71, 20);
printf("YOU WILL NOT GET BANK INTEREST");
}
}
}
    }
    fclose(old);
    if (test != 1)
    {
system("cls");
gotoxy(71, 8);
printf("RECORD NOT FOUND !!");
    see_invalid:
gotoxy(71, 8);
printf("ENTER [0] TO TRY AGAIN [1] TO RETURN TO MAIN MENU AND [2]

TO EXIT :");

scanf("%d", &exit_menu);
system("cls");
if (exit_menu == 1)
_main_menu();
else if (exit_menu == 2)
_end_program();
else if (exit_menu == 0)
_detail_view_user_list();
else
{
            system("cls");
            gotoxy(70, 5);
            printf("INVALID !!");
            goto see_invalid;
}
    }

    else
    {
gotoxy(65, 23);
printf("ENTER [1] TO RETURN TO MAIN MENU AND [2] TO EXIT :");
scanf("%d", &exit_menu);
    }
    if (exit_menu == 1)
    {
system("cls");
_main_menu();
    }
    else
    {
system("cls");
_end_program();
    }
}

/**
 * @brief this is for quit the program in bank mangement system
 * @see _ _quit()
 * visit the function for the reference to the execution of code
 */
void _quit()
{
    FILE *fp;
    system("cls");
    SUB_HEADER(0);
    system("color B1");
    char c;
    gotoxy(69, 11);
    printf("THANKS FOR YOUR PRECIOUS TIME");
    gotoxy(68, 13);
    printf("WE ARE PLEASED TO SEE YOU HERE :)");
    gotoxy(67, 15);
    printf("HOW WAS YOUR EXPERIENCE WITH US ??");
    gotoxy(66, 17);

    printf("DO YOU WANT TO GIVE US RATING [y/n] :");
    scanf("%s", &c);
    while (c = 'y')
    {
int x;
fp = fopen("rating.txt", "ab");
gotoxy(60, 19);
printf(" YOU CAN GIVE US RATING (should not exceed 5 ratings) :");
scanf("%d", &x);
putw(x, fp);
fclose(fp);
gotoxy(70, 21);
printf("THANKS FOR GIVING US RATING...");
gotoxy(75, 23);
printf("PRESS ANY KEY...");
getch();
exit(0);
    }
}