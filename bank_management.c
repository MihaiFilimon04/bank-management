#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
char name[20];
int dip_amount, amount = 10000, acc_no, ac, count = 0;
int trans_amount;
int with_amount;

void deposit_money();
void withdraw_money();
void transfer_money();
void checkDetail();
void LastDetail();
void transaction_details();
void menu();

void separator()
{
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
}
int main()
{
    FILE *ptr = fopen("account_details", "w");

    int ch;
    printf("Enter your name : \n");
    gets(name);
    fprintf(ptr, "\nName : %s\n", name);
    printf("Enter your account no. : ");
    scanf("%d", &acc_no);
    fprintf(ptr, "Account no. : %d\n", acc_no);
    fclose(ptr);
    while (1)
    {
        menu();
        printf("\nEnter your choice :\n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                system("cls");
                deposit_money();
                break;
            case 2:
                system("cls");
                withdraw_money();
                break;

            case 3:
                system("cls");
                transfer_money();
                break;

            case 4:
                system("cls");
                checkDetail();
                break;

            case 5:
                transaction_details();
                break;

            case 6:
                system("cls");
                LastDetail();
                exit(0);

            default:
                printf("*****Invalid choice*****");
        }
    }

    return 0;
}

void menu()
{

    system("cls");
    separator();
    printf("\n\tMENU\n");
    separator();
    printf("\n1.Deposit Money\n");
    printf("2.Withdraw Money\n");
    printf("3.Transfer Money\n");
    printf("4.Account details\n");
    printf("5.Transaction details\n");
    printf("6.Exit\n");
    separator();
}

void deposit_money()
{

    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    printf("*****DEPOSITING MONEY*****\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-"); /// to look decent
    }

    printf("\nEnter the amount you want to deposit\n");
    scanf("%d", &dip_amount);
    amount += dip_amount;
    printf("****Money Deposited****\n");
    printf("Now balance : %d\n", amount);
    fprintf(ptr, "\nRs%d had been deposited to your account \n", dip_amount);
    fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
    count++;

    fclose(ptr);
    printf("Press any key....\n");
    getch();
}
void withdraw_money()
{

    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    printf("*****WITHDRAWING MONEY*****\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }

    printf("\nEnter the amount you want to withdraw\n");
    scanf("%d", &with_amount);

    if (amount < with_amount)
    {
        printf("****Insufficient balance****\n");
    }
    else
    {
        amount = amount - with_amount;
        printf("*****Money withdrawn*****\n");
        printf("Current balance : %d\n", amount);
        fprintf(ptr, "\nRs%d had been withdrawn from your account \n", with_amount);
        fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
        count++;
    }
    fclose(ptr);
    printf("Press any key....\n");

    getch();
}

void transfer_money()
{

    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    printf("*****TRANSFERRING MONEY*****\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }

    printf("\nEnter the account no. in which you want to transfer the money : ");
    scanf("%d", &ac);
    printf("\nEnter the amount you want to transfer\n");
    scanf("%d", &trans_amount);

    if (amount < trans_amount)
    {
        printf("****You have not sufficient balance****\n");
    }
    else
    {
        amount = amount - trans_amount;
        printf("****Money Transferred****\n");
        printf("Current balance : %d\n", amount);
        fprintf(ptr, "\nRs%d had been transferred from your account to %d\n", trans_amount, ac);
        fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
        count++;
    }
    fclose(ptr);
    printf("Press any key....\n");
    getch();
}

void checkDetail()
{
    printf("ACCOUNT DETAILS\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }

    printf("\nName : %s\n", name);
    printf("Account No. : %d\n", acc_no);
    printf("Total balance = %d\n ", amount);
    printf("\n%d transactions have been made from your account \n", count);
    printf("Press any key.....");
    getch();
}

void transaction_details()
{

    system("cls");

    FILE *ptr;
    ptr = fopen("Account.txt", "r");
    char c = fgetc(ptr);
    if (c == EOF)
    {
        printf("TRANSACTION DETAILS\n");
        separator();
        printf("\n*******NO RECENT TRANSACTION*******\n");
    }
    else
    {
        printf("TRANSACTION DETAILS\n");
        separator();
        printf("\n%d transactions have been made from your account \n", count);
        while (c != EOF)
        {
            printf("%c", c);
            c = fgetc(ptr);
        }
    }

    getch();
}

void LastDetail()
{
    printf("ACCOUNT DETAILS\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
    printf("\nName : %s\n", name);
    printf("Account No. : %d\n", acc_no);
    printf("Total balance = %d\n ", amount);

    printf("\n\nPress any key to exit.....");
    getch();
}
