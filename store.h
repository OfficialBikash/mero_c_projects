/**
 * @brief this is the information related to store management system
 * @file store.h
 * @date 2023-01-16
 * @copyright Copyright (c) 2023
 * @see main_menu()
 * visit main function for the reference to the execution of code
 */
#include "color.h"
#define CNN 15
#define CBN 4
COORD xy = {0, 0};
int i, a, b, j;
int exit_menu;
struct _date
{
    int month, day, year;
};
struct store
{
    char name[50];
    char gender[10];
    char email[50];
    int serial_number;
    char address[40];
    double phone;
    float amount_due;
    float amount_paid;
    float amount_total;
    struct _date paid_amt;
    struct _date withdraw_amt;

} insert, edit, cheak, delete, amount;
typedef struct
{
    char name[CNN], code[CBN];
    float rate;
    int quantity;
} record;
record stocks;

/**
* @brief these are the user defined function
* @note this file only contains the user defined function related to bank
management system
*/
void rectangle_format();
int SUBHEADER(int bal);
void quit();
void gotoxy(int x, int y);
void insert_customer();
void delete_customer(void);
void edit_customer(void);
void main_menu(void);
void end_program(void);
void view_customer_list();
void detail_view_customer_list();
void quit();
void manipulate_customer();
void checking_code(char[]);
int checking(char[]);
void cur(int);
void department_bill();
void department_menu();
void view(record *, int, int);
void view_concern();
void search_in_department();
void h_light(int, int);
void cal_bill();

void modify();
void add_stocks();
void delete_stocks();
void exit();
void depart_code();
void depart_rate();
void depart_quantity();
void depart_all();
/**
* @brief this is the function required to place text in a particular
position
* @see gotoxy()
* visit the function for the reference to the execution of code
*/
void gotoxy(int x, int y)
{
    COORD c;
    // COORD    = > pre_defined function
    c.X = x;
    // x    co - ordination value storing variable
    c.Y = y;
    // y    co - ordination value storing variable
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    // set position of cursor on a cartain position giving x and y coordinate value
}
/**
* @brief this is the function required to make a rectangular frame of "*"
and "#"
* @see rectangle_format(int x,int y)
* visit the function for the reference to the execution of code
*/
void rectangle_format()
{
    int i;
    // top
    gotoxy(64, 8);
    for (i = 1; i <= 52; i++)

    {
        printf("#");
    }
    // left
    a = 64;
    for (i = 9; i <= 20; i++)
    {
        gotoxy(a, i);
        printf("*");
    }
    // right
    a = 115;
    for (i = 9; i <= 20; i++)
    {
        gotoxy(a, i);
        printf("*");
    }
    // down
    gotoxy(64, 21);
    for (i = 1; i <= 52; i++)
    {
        printf("*");
    }
}
/**
 * @brief this is the function required to make a sub topic
 * @see SUBHEADER(int bal)
 * visit the function for the reference to the execution of code
 */
int SUBHEADER(int bal)
{
    int i;
    system("cls");
    for (i = 0; i <= 181; i++)
    {
        printf(BLUE "=");
    }

    printf("\n");
    gotoxy(88, 1);
    printf(BLUE "STORE");
    gotoxy(82, 2);
    printf(BLUE "MANAGEMENT SYSTEM\n");
    for (i = 0; i <= 181; i++)
    {
        printf(BLUE "=");
    }
}

/**
* @brief Here, the operator can insert the details of the customer in
store management system
* @see insert_customer()
* visit the function for the reference to the execution of code
*/
void insert_customer()
{
    int choice;
    FILE *fp;
    fp = fopen("store_info.dat", "a+");
serial_number:
    system("cls");
    gotoxy(71, 6);
    printf(UWHITE " INSERT USER DETAILS ");
    fflush(stdin);
    gotoxy(71, 9);
    printf(YELLOW "ENTER TODAY'S DATE (YYYY/MM/DD): ");
    scanf("%d/%d/%d", &insert.paid_amt.year, &insert.paid_amt.month,
          &insert.paid_amt.day);
    fflush(stdin);
    int A = 71;

    gotoxy(A, 13);
    printf("ENTER ACCOUNT NUMBER : ");
    scanf("%d", &cheak.serial_number);
    fflush(stdin);
    while (fscanf(fp, "%d %s %s %s %s %lf %f %f %f %d/%d/%d",
                  &insert.serial_number, insert.name, insert.address, insert.gender,
                  insert.email, &insert.phone, &insert.amount_due, &insert.amount_paid,
                  &insert.amount_total, &insert.paid_amt.month, &insert.paid_amt.day,
                  &insert.paid_amt.year) != EOF)
    {
        if (cheak.serial_number == insert.serial_number)
        {
            printf("ACCOUNT NUMBER IS ALREADY IN USE :)");
            getch();
            goto serial_number;
        }
    }
    insert.serial_number = cheak.serial_number;
    gotoxy(A, 15);
    printf("ENTER CUSTOMER NAME : ");
    gets(insert.name);
    fflush(stdin);
    gotoxy(A, 23);
    printf("ENTER ADDRESS : ");
    gets(insert.address);
    fflush(stdin);
    gotoxy(A, 19);
    printf("ENTER GENDER : ");
    gets(insert.gender);
    fflush(stdin);
    gotoxy(A, 25);
    printf("ENTER E-MAIL : ");
    gets(insert.email);
    fflush(stdin);

    gotoxy(A, 27);
    printf("ENTER PHONE NUMBER : ");
    scanf("%lf", &insert.phone);
    fflush(stdin);
    gotoxy(A, 29);
    printf("ENTER THE AMOUNT HE NEED TO PAY : RS. ");
    scanf("%f", &insert.amount_total);
    fflush(stdin);
    fprintf(fp, "%d %s %s %s %s %lf %f %f %f %d/%d/%d",
            insert.serial_number, insert.name, insert.address, insert.gender,
            insert.email, insert.phone, insert.amount_due, insert.amount_paid,
            insert.amount_total, insert.paid_amt.month, insert.paid_amt.day,
            insert.paid_amt.year);
    fclose(fp);
    gotoxy(A, 40);
    printf("ACCOUNT CREATED SUCCESSFULLY !!");
INVALID:
    gotoxy(A, 42);
    printf(" ENTER [1] TO GO BACK [0] TO EXIT !! ");
    scanf("%d", &exit_menu);
    system("cls");
    if (exit_menu == 1)
        main_menu();
    else if (exit_menu == 0)
    {
        end_program();
    }
    else
    {
        gotoxy(76, 7);
        printf("INVALID INPUT !! ");
        goto INVALID;
    }
}
/**

* @brief Here, the operator can delete the details of the customer in
store management system
* @see delete_customer()
* visit the function for the reference to the execution of code
*/
void delete_customer(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("store_info.dat", "r");
    newrec = fopen("store_new.dat", "w");
    printf("ENTER THE CUSTOMER'S SERIAL NUMBER OF THE CUSTOMER : ");
    scanf("%d", &delete.serial_number);
    while (fscanf(old, "%d %s %s %s %s %lf %f %f %f %d/%d/%d",
                  &insert.serial_number, insert.name, insert.address, insert.gender,
                  insert.email, &insert.phone, &insert.amount_due, &insert.amount_paid,
                  &insert.amount_total, &insert.paid_amt.month, &insert.paid_amt.day,
                  &insert.paid_amt.year) != EOF)
    {
        if (insert.serial_number != delete.serial_number)
            fprintf(newrec, "%d %s %s %s %s %lf %f %f %f %d/%d/%d",
                    insert.serial_number, insert.name, insert.address, insert.gender,
                    insert.email, insert.phone, insert.amount_due, insert.amount_paid,
                    insert.amount_total, insert.paid_amt.month, insert.paid_amt.day,
                    insert.paid_amt.year);

        else
        {
            test++;
            printf("RECORD DELETE SUCCESSFULLY !!");
        }
    }
    fclose(old);
    fclose(newrec);
    remove("store_info.dat");
    rename("store_new.dat", "store_info.dat");
    if (test == 0)
    {
        printf("RECORD NOT FOUND !! ");

    erase_invalid:
        printf("ENTER [0] TO TRY AGAIN [1] TO GO BACK [2] TO EXIT !! ");
        scanf("%d", &exit_menu);
        if (exit_menu == 1)
            main_menu();
        else if (exit_menu == 2)
            end_program();
        else if (exit_menu == 0)
            delete_customer();
        else
        {
            printf("\nInvalid!\a");
            goto erase_invalid;
        }
    }
    else
    {
        printf("ENTER [1] TO GO BACK [0] TO EXIT !! ");
        scanf("%d", &exit_menu);
        system("cls");
        if (exit_menu == 1)
            main_menu();
        else
            end_program();
    }
}
/**
* @brief Here, the operator can edit the details of the customer in store
management system
* @see edit_customer()
* visit the function for the reference to the execution of code
*/
void edit_customer(void)
{
    int choice, test = 0;
    FILE *fp, *fp2;
    fp = fopen("store_info.dat", "r");
    fp2 = fopen("store_new.dat", "w");

    printf("ENTER THE CUSTOMER'S SERIAL NUMBER YOU WANT TO MODIFY : ");
    scanf("%d", &edit.serial_number);
    while (fscanf(fp, "%d %s %s %s %s %lf %f %f %f %d/%d/%d",
                  &insert.serial_number, insert.name, insert.address, insert.gender,
                  insert.email, &insert.phone, &insert.amount_due, &insert.amount_paid,
                  &insert.amount_total, &insert.paid_amt.month, &insert.paid_amt.day,
                  &insert.paid_amt.year) != EOF)
    {
        if (insert.serial_number == edit.serial_number)
        {
            test = 1;
            printf("WHICH INFORMATION DO YOU WANT TO CHANGE ?");
            printf("[1] .ADDRESS");
            printf("[2] .E-MAIL");
            printf("[3] .PHONE");
            scanf("%d", &choice);
            system("cls");
            if (choice == 1)
            {
                printf("ENTER THE NEW ADDRESS : ");
                scanf("%s", edit.address);
                fprintf(fp2, "%d %s %s %s %s %lf %f %f %f %d/%d/%d",
                        insert.serial_number, insert.name, edit.address, insert.gender,
                        insert.email, insert.phone, insert.amount_due, insert.amount_paid,
                        insert.amount_total, insert.paid_amt.month, insert.paid_amt.day,
                        insert.paid_amt.year);

                system("cls");
                printf("CHANGES SAVED !!");
            }
            else if (choice == 2)
            {
                printf("ENTER THE NEW E-MAIL : ");
                scanf("%s", &edit.email);
                fprintf(fp2, "%d %s %s %s %s %lf %f %f %f %d/%d/%d",
                        insert.serial_number, insert.name, insert.address, insert.gender,
                        edit.email, insert.phone, insert.amount_due, insert.amount_paid,
                        insert.amount_total, insert.paid_amt.month, insert.paid_amt.day,
                        insert.paid_amt.year);

                system("cls");

                printf("CHANGES SAVED !!");
            }
            else if (choice == 3)
            {
                printf("ENTER THE NEW PHONE NUMBER :");
                scanf("%lf", &edit.phone);
                fprintf(fp2, "%d %s %s %s %s %lf %f %f %f %d/%d/%d",
                        insert.serial_number, insert.name, insert.address, insert.gender,
                        insert.email, edit.phone, insert.amount_due, insert.amount_paid,
                        insert.amount_total, insert.paid_amt.month, insert.paid_amt.day,
                        insert.paid_amt.year);

                system("cls");
                printf("CHANGES SAVED !!");
            }
        }
        else
            fprintf(fp2, "%d %s %s %s %s %lf %f %f %f %d/%d/%d",
                    insert.serial_number, insert.name, insert.address, insert.gender,
                    insert.email, insert.phone, insert.amount_due, insert.amount_paid,
                    insert.amount_total, insert.paid_amt.month, insert.paid_amt.day,
                    insert.paid_amt.year);
    }
    fclose(fp);
    fclose(fp2);
    remove("store_info.dat");
    rename("store_new.dat", "store_info.dat");
    if (test != 1)
    {
        system("cls");
        printf("RECORD NOT FOUND ");
    EDIT_INVALID:
        printf(" ENTER [1] TO GO BACK [0] TO EXIT !! ");
        scanf("%d", &exit_menu);
        system("cls");
        if (exit_menu == 1)
            main_menu();
        else if (exit_menu == 0)
        {

            end_program();
        }
        else
        {
            printf("INVALID INPUT !! ");
            goto EDIT_INVALID;
        }
    }
    else
    {
        printf("ENTER [1] TO GO BACK [0] TO EXIT !!");
        scanf("%d", &exit_menu);
        system("cls");
        if (exit_menu == 1)
            main_menu();
        else
            end_program();
    }
}
/**
* @brief Here the operator can view details of the customer in store
management system
* @see view_customer_list()
* visit the function for the reference to the execution of code
*/
void view_customer_list()
{
    FILE *fp;
    fp = fopen("store_info.dat", "r");
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
    printf("S.N.");
    gotoxy(70, a);
    printf("NAME");
    gotoxy(50, a);
    printf("ADDRESS");
    gotoxy(75, a);
    printf("PHONE_NO");
    gotoxy(100, a);
    printf("EMAIL");
    gotoxy(125, a);
    printf("DUE AMT");
    gotoxy(135, a);
    printf("PAID AMT");
    gotoxy(155, a);
    printf("TOTAL AMT");
    printf("\n");
    for (i = 1; i <= 168; i++)
    {
        printf("-");
    }
    i = 6;
    while (fscanf(fp, "%d %s %s %s %s %lf %f %f %f %d/%d/%d",
                  &insert.serial_number, insert.name, insert.address, insert.gender,
                  insert.email, &insert.phone, &insert.amount_due, &insert.amount_paid,
                  &insert.amount_total, &insert.paid_amt.month, &insert.paid_amt.day,
                  &insert.paid_amt.year) != EOF)
    {
        test = 1;
        gotoxy(1, i);
        printf("%d", insert.serial_number);
        gotoxy(70, i);
        printf("%s", insert.name);
        gotoxy(50, i);
        printf("%s", insert.address);
        gotoxy(75, i);
        printf("%lf", insert.phone);
        gotoxy(100, i);

        printf("%s", insert.email);
        gotoxy(125, i);
        printf("%.2f", insert.amount_due);
        gotoxy(135, i);
        printf("%.2f", insert.amount_paid);
        gotoxy(155, i);
        printf("%.2f", insert.amount_total);
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
        main_menu();
    else if (exit_menu == 0)
        end_program();
    else
    {
        printf("INVALID INPUT !!\a");
        goto view_list_invalid;
    }
}
/**
* @brief Here the operator can choose the customer and product related
topics...
* @see main_menu()
* visit the function for the reference to the execution of code
*/
void main_menu()

{
    int ch;
    system("cls");
    system("color 7");
    SUBHEADER(0);
    rectangle_format();
    gotoxy(71, 6); // set cursor
    in a certain location based on given coordinates
        printf(REDB " HI !! WHAT DO YOU WANT TO DO HERE ?? "); // ask customer
    that what he / she want to do... int A = 68;               // given
    contant value to x - coordinate
                             gotoxy(A, 10);
    printf(YELLOW "[1]. VIEW CUSTOMER DETAILS"); //[6] View customer's
    list
        gotoxy(A, 11);
    printf("[2]. SEARCH CUSTOMER DETAILS "); //[4] Check the account
    details
        gotoxy(A, 12);
    printf("[3]. MANIPULATE CUSTOMER DETAILS "); //[1] Create new
    account[2] Edit existing account[5] Remove existing accoun[3] Transactions
        gotoxy(A, 13);
    printf("[4]. EXIT ");
    gotoxy(A, 16);
    printf(BBLUE "PLEASE, ENTER YOUR CHOICE : "); // ask customer to
    choose "one" among 1 to 5 scanf("%d", &ch);
    system("cls");
    switch (ch)
    {
    case 1:
        view_customer_list(); // view_list();
        break;
    case 2:
        detail_view_customer_list(); // see();
        break;
    case 3:
        manipulate_customer();

    case 5:
        end_program(); // end_program();
        break;
    }
}
/**
 * @brief this is the end interface of the program ...
 * @see end_program()
 * visit the function for the reference to the execution of code
 */
void end_program(void)
{
    printf("\n\n\n\nTHANK YOU !!");
}
/**
 * @brief this is the error interface of the program ...
 * @see error_program()
 * visit the function for the reference to the execution of code
 */
void error()
{
    printf("SORRY !! YOU HAVE SELECTED INVALID NUMBER ,PRESS ANY KEY...");
}
/**
* @brief Here the operator can view all the details of the customer in
store management system
* @see detail_view_customer_list()
* visit the function for the reference to the execution of code
*/
void detail_view_customer_list()
{
    system("cls");
    SUBHEADER(0);
    FILE *old;
    int test = 0, rate;
    int choice;
    float time;

    float intrst;
    old = fopen("store_info.dat", "r");
    rectangle_format();
    gotoxy(77, 10);
    printf(YELLOW);
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
        scanf("%d", &cheak.serial_number);
        while (fscanf(old, "%d %s %s %s %s %lf %f %f %f %d/%d/%d",
                      &insert.serial_number, insert.name, insert.address, insert.gender,
                      insert.email, &insert.phone, &insert.amount_due, &insert.amount_paid,
                      &insert.amount_total, &insert.paid_amt.month, &insert.paid_amt.day,
                      &insert.paid_amt.year) != EOF)

        {
            if (insert.serial_number == cheak.serial_number)
            {
                system("cls");
                SUBHEADER(0);
                test = 1;
                rectangle_format();
                gotoxy(71, 8);
                printf(UWHITE " USER INFORMATION ");
                gotoxy(71, 10);
                printf(YELLOW "ACCOUNT NO : %d ", insert.serial_number);
                gotoxy(71, 11);
                printf("USER NAME : %s ", insert.name);
                gotoxy(71, 12);
                printf("ADDRESS : %s ", insert.address);

                gotoxy(71, 13);
                printf("PHONE NUMBER : %.0lf ", insert.phone);
                gotoxy(71, 14);
                printf("PHONE NUMBER : %s ", insert.email);
                gotoxy(71, 15);
                printf("TOTAL AMOUNT : %.2f ", insert.amount_total);
                gotoxy(71, 16);
                printf("AMOUNT TO BE PAID : %.2f ", insert.amount_due);
                gotoxy(71, 17);
                printf("TOTAL PAID AMOUNT : %.2f ", insert.amount_paid);
                gotoxy(71, 18);
                printf("DATE OF DEPOSIT : %d / %d / %d ",

                       insert.paid_amt.year, insert.paid_amt.month, insert.paid_amt.day);
            }
        }
    }
    else if (choice == 2)
    {
        gotoxy(71, 17);
        printf("ENTER THE CUSTOMER NAME :");
        scanf("%d", &cheak.name);
        while (fscanf(old, "%d %s %s %s %s %lf %f %f %f %d/%d/%d",
                      &insert.serial_number, insert.name, insert.address, insert.gender,
                      insert.email, &insert.phone, &insert.amount_due, &insert.amount_paid,
                      &insert.amount_total, &insert.paid_amt.month, &insert.paid_amt.day,
                      &insert.paid_amt.year) != EOF)

        {
            if (insert.serial_number == cheak.serial_number)
            {
                system("cls");
                SUBHEADER(0);
                test = 1;
                rectangle_format();
                gotoxy(71, 8);
                printf(UWHITE " USER INFORMATION ");
                gotoxy(71, 10);
                printf(YELLOW "ACCOUNT NO : %d ", insert.serial_number);
                gotoxy(71, 11);
                printf("USER NAME : %s ", insert.name);

                gotoxy(71, 12);
                printf("ADDRESS : %s ", insert.address);
                gotoxy(71, 13);
                printf("PHONE NUMBER : %.0lf ", insert.phone);
                gotoxy(71, 14);
                printf("PHONE NUMBER : %s ", insert.email);
                gotoxy(71, 15);
                printf("TOTAL AMOUNT : %s ", insert.amount_total);
                gotoxy(71, 16);
                printf("AMOUNT TO BE PAID : %s ", insert.amount_due);
                gotoxy(71, 17);
                printf("TOTAL PAID AMOUNT : %s ", insert.amount_paid);
                gotoxy(71, 18);
                printf("DATE OF DEPOSIT : %d / %d / %d ",

                       insert.paid_amt.year, insert.paid_amt.month, insert.paid_amt.day);
            }
        }
    }
    fclose(old);
    if (test != 1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
    see_invalid:
printf("\nEnter 0 to try again,1 to return to main menu and 2 to

exit:");

scanf("%d", &exit_menu);
system("cls");
if (exit_menu == 1)
main_menu();
else if (exit_menu == 2)
end_program();
else if (exit_menu == 0)
detail_view_customer_list();
else
{
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;

}
    }
    else
    {
printf("\nEnter 1 to go to the main menu and 0 to exit:");
scanf("%d", &exit_menu);
    }
    if (exit_menu == 1)
    {
system("cls");
main_menu();
    }
    else
    {
system("cls");
end_program();
    }
}
/**
 * @brief this is the error interface of the program ...
 * @see quit()
 * visit the function for the reference to the execution of code
 */
void quit()
{
    FILE *fp;
    system("cls");
    SUBHEADER(0);
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
/**
 * @brief here we can maniupuate the data of the customer ...
 * @see manipulate_customer()
 * visit the function for the reference to the execution of code
 */
void manipulate_customer()
{
    int choice;
    system("cls");
    system("color 7");
    gotoxy(71, 6); // set cursor
    in a certain location based on given coordinates
        printf(REDB " HI !! WHAT DO YOU WANT TO DO HERE ?? "); // ask customer
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
    printf("[4].DELETE USER DETAILS "); // [7]. atm service
    gotoxy(67, 15);
    printf("[5]. EXIT ");
    gotoxy(67, 18);
    printf(BBLUE "PLEASE, ENTER YOUR CHOICE : "); // ask customer to
    choose "one" among 1 to 5 scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:
insert_customer(); // new_acc();
break;
    case 2:
edit_customer(); // edit();
break;
    case 3:
// transaction_amt(); // transact();
break;
    case 4:
delete_customer(); // delete_customer();
break;
    case 5:
end_program(); // end_program();
break;
    }
}
/**
* @brief this is the main interface of the product management system...
* @see department_menu()
* visit the function for the reference to the execution of code

*/
void department_menu()
{
    system("cls");
    int a;
    char st;
    const char *menu[] = { " BILL CALCULATOR ", " INSERT PRODUCTS ", "
                           MODIFY GOODS ", " VIEW PRODUCTS ", " SEARCH PRODUCTS ", " DELETE GOODS ", " EXIT "};
                           SUBHEADER(0);
    rectangle_format();
    gotoxy(73, 6);
    printf(RESET);
    printf(BRED "## ## ## M A I N M E N U ## ## ##");
    printf(RESET);
    gotoxy(68, 10);
    printf(URED " WHAT DO YOU WANT TO DO ? ");
    for (a = 0; a <= 6; a++)
    {
gotoxy(68, 12 + a);
printf("%s\n\n\n", menu[a]);
    }
    cur(7);
}
/**
* @brief here we can search information about products of the product
management system...
* @see search_in_department()
* visit the function for the reference to the execution of code
*/
void search_in_department()
{
    char st;
    int a;
    system("cls");
    const char *menu[] = { " BY CODE ", " BY RATE", " BY QUANTITY", "
                           BACK TO MAIN MENU "};
                           SUBHEADER(0);
    rectangle_format();

    gotoxy(73, 6);
    printf(RESET);
    printf(BRED "## ## ## S E A R C H M E N U ## ## ##");
    printf(RESET);
    for (a = 0; a <= 3; a++)
    {
gotoxy(68, 13 + a);
printf("%s\n\n\n", menu[a]);
    }
    cur(4);
}
/**
 * @brief here the cursor placement is managed...
 * @see cur(int no)
 * visit the function for the reference to the execution of code
 */
void cur(int no)
{
    int counting = 1;
    char st = '0';
    gotoxy(68, 10);
    while (1)
    {
switch (st)
{
case 80:
    counting++;
    if (counting == no + 1)
        counting = 1;
    break;
case 72:
    counting--;
    if (counting == 0)
        counting = no;
    break;
}
h_light(no, counting);
st = getch();
if (st == '\r')

{
    if (no == 7)
    {
        if (counting == 1)
            cal_bill();
        else if (counting == 2)
            add_stocks();
        else if (counting == 3)
            modify();
        else if (counting == 4)
            depart_all();
        else if (counting == 5)
            search_in_department();
        else if (counting == 6)
            delete_stocks();
        else
            exit(0);
    }
    if (no == 4)
    {
        if (counting == 1)
            depart_code();
        else if (counting == 2)
            depart_rate();
        else if (counting == 3)
            depart_quantity();
        else
            department_menu();
    }
}
    }
}
/**
 * @brief this is the main interface of product management system
 * @see h_light(int no, int count)
 * visit the function for the reference to the execution of code
 */
void h_light(int no, int count)
{

    if (no == 4)
    {
gotoxy(68, 13);
printf(" BY CODE ");
gotoxy(68, 14);
printf(" BY RATE ");
gotoxy(68, 15);
printf(" BY QUANTITY ");
gotoxy(68, 16);
printf(" BACK TO MAIN MENU");
switch (count)
{
case 1:
    gotoxy(68, 13);
    printf(" - BY CODE ");
    break;
case 2:
    gotoxy(68, 14);
    printf(" - BY RATE ");
    break;
case 3:
    gotoxy(68, 15);
    printf(" - BY QUANTITY ");
    break;
case 4:
    gotoxy(68, 16);
    printf(" - BACK TO MAIN MENU");
    break;
}
    }
    if (no == 7)
    {
gotoxy(68, 12);
printf(YELLOW " BILL CALCULATOR ");
gotoxy(68, 13);
printf(" INSERT PRODUCTS ");

gotoxy(68, 14);
printf(" MODIFY GOODS ");
gotoxy(68, 15);
printf(" VIEW PRODUCTS ");
gotoxy(68, 16);
printf(" SEARCH PRODUCTS ");
gotoxy(68, 17);
printf(" DELETE GOODS ");
gotoxy(68, 18);
printf(" EXIT ");
switch (count)
{
case 1:
    gotoxy(68, 12);
    printf(" - BILL CALCULATOR ");
    break;
case 2:
    gotoxy(68, 13);
    printf(" - INSERT PRODUCTS ");
    break;
case 3:
    gotoxy(68, 14);
    printf(" - MODIFY GOODS ");
    break;
case 4:
    gotoxy(68, 15);
    printf(" - VIEW PRODUCTS ");
    break;
case 5:
    gotoxy(68, 16);
    printf(" - SEARCH PRODUCTS ");
    break;
case 6:
    gotoxy(68, 17);
    printf(" - DELETE GOODS ");
    break;
case 7:
    gotoxy(68, 18);
    printf(" - EXIT ");

    break;
}
    }
}
/**
 * @brief this is the interface of bill calculator
 * @see cal_bill()
 * visit the function for the reference to the execution of code
 */
void cal_bill()
{
    char c[4] = {0};
    int d = 20, e = 0, size = 0, f = 1;
    float d_tot = 0, gross_tot = 0;
    FILE *openfile;
    openfile = fopen("product.dat", "r+b");
    rewind(openfile);
    system("cls");
    SUBHEADER(0);
    gotoxy(80, 16);
    printf("* CUSTOMER'S BILL *");
    gotoxy(67, 18);
    printf("SN. ITEM NAME QUANTITY RATE TOTAL");
    gotoxy(78, 7);
    printf(UBLUE "ENTER \"END\" TO FINISH INPUT");
    printf(RESET);
    while (1)
    {
gotoxy(69, 10);
printf(" ");
gotoxy(69, 11);
printf(" ");
gotoxy(69, 10);
printf("ENTER ITEM CODE : ");
scanf("%s", c);
if (strcmpi(c, "end") == 0)
    break;
gotoxy(69, 11);
printf("ENTER QUANTITY : ");

scanf("%d", &e);
rewind(openfile);
while (fread(&stocks, sizeof(stocks), 1, openfile))
{
    if ((strcmp(stocks.code, c) == 0))
    {
        d_tot = stocks.rate * e;
        gotoxy(64, d);
        printf("%4d", f);
        printf("%12s", stocks.name);
        printf("%8d", e);
        printf("%17.2f", stocks.rate);
        printf("%14.2f", d_tot);
        gross_tot = gross_tot + d_tot;
        size = sizeof(stocks);
        stocks.quantity = stocks.quantity - e;
        d += 2;
        f++;
        fseek(openfile, -size, SEEK_CUR);
        fwrite(&stocks, sizeof(stocks), 1, openfile);
        break;
    }
}
    }
    if (gross_tot != 0)
    {
gotoxy(69, d + 5);
printf("TOTAL AMOUNT = RS . %6.2f", gross_tot);
    }
    fclose(openfile);
    getch();
    department_menu();
}
/**
 * @brief here, we can add product information
 * @see add_stocks()
 * visit the function for the reference to the execution of code
 */
void add_stocks()

{
    FILE *openfile;
    char l[CBN], m[12];
    system("cls");
    SUBHEADER(0);
    rectangle_format();
    gotoxy(70, 12);
    printf(RESET);
    printf("ENTER NEW RECORD (Y/N) ? ");
    while (toupper(getche()) == 'Y')
    {
system("cls");
openfile = fopen("product.dat", "ab");
checking_code(l);
strcpy(stocks.code, l);
fflush(stdin);
gotoxy(71, 12);
printf("ENTER RATE OF THE ITEM:");
scanf("%f", &stocks.rate);
fflush(stdin);
gotoxy(71, 14);
printf("ENTER QUANTITY OF ITEM:");
scanf("%d", &stocks.quantity);
fflush(stdin);
gotoxy(71, 16);
printf("ENTER NAME OF THE ITEM:");
scanf("%s", stocks.name);
fflush(stdin);
// fseek(openfile, 0, SEEK_END);
fwrite(&stocks, sizeof(stocks), 1, openfile);
fclose(openfile);
gotoxy(71, 18);
printf(" ENTER NEW RECORD (Y/N) ? ");
    }
    department_menu();
}
/**
* @brief here, we can cheak code product information
* @see checking_code()

* visit the function for the reference to the execution of code
*/
void checking_code(char y[])
{
    int flagerized;
    FILE *openfile;
    openfile = fopen("product.dat", "rb");
    while (1)
    {
system("cls");
SUBHEADER(0);
gotoxy(71, 8);
printf(URED "## ## ## PRODUCT INFO ## ## ## ");
flagerized = 1;
rewind(openfile);
gotoxy(65, 10);
printf(YELLOW "ENTER THE CODE OF THE PRODUCT : ");
scanf(" %[^\n]", y);
while (fread(&stocks, sizeof(stocks), 1, openfile) == 1)
{
    if (strcmp(y, stocks.code) == 0)
    {
        flagerized = 0;
        gotoxy(75, 30);
        printf("CODE ALREADY EXISTS");
        gotoxy(79, 32);
        printf("ENTER AGAIN");
        getch();
        break;
    }
}
if (flagerized == 1)
    break;
    }
}
/**
* @brief here, we can change product information
* @see modify()
* visit the function for the reference to the execution of code

*/
void modify()
{
    int flagerized = 0, options;
    char r[CBN], s[CBN];
    FILE *openfile;
    int sze;
    system("cls");
    gotoxy(70, 6);
    printf("EDIT RECORDS");
    ;
    gotoxy(70, 8);
    printf("ENTER ITEM CODE: ");
    scanf("%s", r);
    flagerized = checking(r);
    if (flagerized == 0)
    {
openfile = fopen("product.dat", "r+b");
rewind(openfile);
while (fread(&stocks, sizeof(stocks), 1, openfile))
{
    if (strcmp(stocks.code, r) == 0)
    {
        gotoxy(70, 10);
        printf("NAME = %s", stocks.name);
        gotoxy(70, 11);
        printf("CODE = %s", stocks.code);
        gotoxy(70, 12);
        printf("RATE = %g", stocks.rate);
        gotoxy(70, 13);
        printf("QUANTITY = %d", stocks.quantity);
        gotoxy(70, 15);
        ;
        printf("DO YOU WANT TO EDIT THIS RECORD ?(y/n) : ");
        fflush(openfile);
        if (toupper(getche()) == 'Y')
        {
            gotoxy(70, 17);
            printf("1- EDIT NAME ");
            gotoxy(70, 18);

            printf("2- EDIT CODE ");
            gotoxy(70, 19);
            printf("3- EDIT RATE ");
            gotoxy(70, 20);
            printf("4- EDIT QUANTITY ");
            gotoxy(70, 21);
            ;
            printf(" ENTER YOUR CHOICE[1, 2, 3, 4] : ");
            scanf("%d", &options);
            switch (options)
            {
            case 1:
                system("cls");
                gotoxy(70, 6);
                printf("EDIT RECORDS");
                gotoxy(70, 8);
                printf(" ENTER NAME: ");
                scanf("%s", stocks.name);
                sze = sizeof(stocks);
                fseek(openfile, -sze, SEEK_CUR);
                fwrite(&stocks, sizeof(stocks), 1, openfile);
                break;
            case 2:
                system("cls");
                gotoxy(70, 6);
                printf("EDIT CODES");
                gotoxy(70, 8);
                checking_code(s);
                strcpy(stocks.code, s);
                sze = sizeof(stocks);
                fseek(openfile, -sze, SEEK_CUR);
                fwrite(&stocks, sizeof(stocks), 1, openfile);
                break;
            case 3:
                system("cls");
                gotoxy(70, 6);
                printf("EDIT RATE");
                gotoxy(70, 8);
                printf(" ENTER NEW RATE : ");
                scanf("%f", &stocks.rate);

                sze = sizeof(stocks);
                fseek(openfile, -sze, SEEK_CUR);
                fwrite(&stocks, sizeof(stocks), 1, openfile);
                break;
            case 4:
                system("cls");
                gotoxy(70, 6);
                printf("EDIT QUANTITY : ");
                gotoxy(70, 8);
                printf(" ENTER NEW QUANTITY : ");
                scanf("%d", &stocks.quantity);
                sze = sizeof(stocks);
                fseek(openfile, -sze, 1);
                fwrite(&stocks, sizeof(stocks), 1, openfile);
                break;
            }
            gotoxy(70, 10);
            printf("//--- ITEM EDITED---//");
            break;
        }
    }
}
    }
    if (flagerized == 1)
    {
gotoxy(70, 8);
printf("ITEM DOESN'T EXIST.");
gotoxy(70, 10);
printf("TRY AGAIN ...");
    }
    getch();
    fclose(openfile);
    department_menu();
}
/**
 * @brief here, we can see product information
 * @see depart_all()
 * visit the function for the reference to the execution of code
 */

void depart_all()
{
    int a, d = 1;
    FILE *openfile;
    view_concern();
    openfile = fopen("product.dat", "rb");
    rewind(openfile);
    a = 14;
    fflush(openfile);
    while (fread(&stocks, sizeof(stocks), 1, openfile))
    {
view(&stocks, a, d);
a++;
d++;
if ((d % 20) == 0)
{
    gotoxy(70, 10); /*textcolor(0)*/
    ;
    printf("PRESS ANY KEY TO SEE MORE...........");
    getch();
    system("cls");
    view_concern();
    a = 26;
    continue;
}
    }
    getch();
    if (a == 14)
    {
gotoxy(73, 30);
printf("-- NO RECORD FOUND --");
    }
    getch();
    fclose(openfile);
    department_menu();
}

/**
* @brief here, we can search product information by quantity

* @see depart_rate()
* visit the function for the reference to the execution of code
*/
void depart_quantity()
{
    int s, t = 1;
    int p, q;
    FILE *openfile;
    view_concern();
    openfile = fopen("product.dat", "rb");
    rewind(openfile);
    s = 26;
    gotoxy(16, 20);
    ;
    printf("ENTER LOWER RANGE: ");
    scanf("%d", &p);
    gotoxy(16, 21);
    printf("ENTER UPPER RANGE:");
    scanf("%d", &q);
    fflush(openfile);
    while (fread(&stocks, sizeof(stocks), 1, openfile))
    {
if ((stocks.quantity >= p) && (stocks.quantity <= q))
{
    view(&stocks, s, t);
    s++;
    t++;
    if ((t % 20) == 0)
    {
        gotoxy(77, 47);
        printf("PRESS ANY KEY TO SEE MORE...........");
        getch();
        system("cls");
        view_concern();
        s = 26;
        continue;
    }
}
    }
    getch();

    if (s == 26)
    {
gotoxy(78, 30);
printf(" NO ITEMS FOUND.");
    }
    getch();
    search_in_department();
    fclose(openfile);
}
/**
 * @brief here, we can search product information by rate
 * @see depart_rate()
 * visit the function for the reference to the execution of code
 */
void depart_rate()
{
    int s, t = 1;
    float p, q;
    FILE *openfile;
    view_concern();
    openfile = fopen("product.dat", "rb");
    rewind(openfile);
    s = 26;
    gotoxy(16, 20);
    ;
    printf("ENTER LOWER RANGE: ");
    scanf("%f", &p);
    gotoxy(16, 21);
    printf("ENTER UPPER RANGE: ");
    scanf("%f", &q);
    fflush(openfile);
    while (fread(&stocks, sizeof(stocks), 1, openfile))
    {
if ((stocks.rate >= p) && (stocks.rate <= q))
{
    view(&stocks, s, t);
    s++;
    t++;
    if ((t % 20) == 0)

    {
        gotoxy(77, 47);
        printf("PRESS ANY KEY TO SEE MORE...........");
        getch();
        system("cls");
        view_concern();
        s = 26;
        continue;
    }
}
    }
    getch();
    if (s == 26)
    {
gotoxy(78, 30);
printf(" NO ITEM FOUND ");
    }
    getch();
    fclose(openfile);
    search_in_department();
}
/**
 * @brief here, this is also another phase to view product information
 * @see view_concern()
 * visit the function for the reference to the execution of code
 */
void depart_code()
{
    int s, t = 1;
    char d[4] = {0};
    FILE *openfile;
    view_concern();
    openfile = fopen("product.dat", "rb");
    rewind(openfile);
    s = 26;
    gotoxy(16, 20);
    ;
    printf("ENTER ITEM CODE: ");
    scanf("%s", d);

    fflush(openfile);
    while (fread(&stocks, sizeof(stocks), 1, openfile))
    {
if ((strcmp(stocks.code, d) == 0))
{
    view(&stocks, s, t);
    s++;
    t++;
    break;
}
    }
    if (s == 26)
    {
gotoxy(78, 30);
printf("NO ITEM FOUND");
    }
    getch();
    fclose(openfile);
    search_in_department();
}
/**
 * @brief here, this is another phase to view product information
 * @see view_concern()
 * visit the function for the reference to the execution of code
 */
void view_concern()
{
    int a;
    system("cls");
    gotoxy(78, 9);
    printf(RESET);
    for (a = 1; a <= 10; a++)
printf("*");
    printf(RED " * BILLING SYSTEM * ");
    printf(RESET);
    for (a = 1; a <= 10; a++)
printf("*");
    gotoxy(90, 11);
    printf(YELLOW "DEPARTMENTAL STORE");

    gotoxy(75, 13);
    printf("SN ITEM NAME ITEM CODE RATE QUANTITY");
}
/**
 * @brief thsi is for view product information
 * @see view(record *stocks, int i, int j)
 * visit the function for the reference to the execution of code
 */
void view(record *stocks, int i, int j)
{
    gotoxy(73, i);
    printf("%4d", j);
    printf("%11s", stocks->name);
    printf("%5s", stocks->code);
    printf("%19.2f", stocks->rate);
    printf("%7d", stocks->quantity);
}
/**
 * @brief this is for delete porduct information
 * @see delete_stocks()
 * visit the function for the reference to the execution of code
 */
void delete_stocks()
{
    int flagerized;
    char d[CNN];
    FILE *openfile, *openfile1;
    system("cls");
    gotoxy(79, 18);
    printf("DELETE PRODUCTS");
    gotoxy(77, 20);
    printf("ENTER ITEM CODE: ");
    scanf("%s", d);
    flagerized = checking(d);
    if (flagerized == 0)
    {
openfile1 = fopen("product1.dat", "ab");
openfile = fopen("product.dat", "rb");

rewind(openfile);
while (fread(&stocks, sizeof(stocks), 1, openfile))
{
    if (strcmp(stocks.code, d) != 0)
        fwrite(&stocks, sizeof(stocks), 1, openfile1);
}
gotoxy(77, 22);
printf("---ITEM DELETED---");
remove("product.dat");
rename("product1.dat", "product.dat");
    }
    if (flagerized == 1)
    {
gotoxy(70, 22);
printf("---ITEM DOESN'T EXIST---");
gotoxy(80, 22);
printf("TRY AGAIN");
    }
    fclose(openfile1);
    fclose(openfile);
    getch();
    department_menu();
}
/**
 * @brief this is for modify section...
 * @see checking(char x[CNN])
 * visit the function for the reference to the execution of code
 */
int checking(char x[CNN])
{
    FILE *openfile;
    int flagerized = 1;
    openfile = fopen("product.dat", "rb");
    rewind(openfile);
    while (fread(&stocks, sizeof(stocks), 1, openfile))
    {
if (strcmp(stocks.code, x) == 0)
{
    flagerized = 0;

    break;
}
    }
    fclose(openfile);
    return flagerized;
}