#include "CAR_RENTAL.h"

typedef struct customer{
    char name[30];
    char surname[30];
    char PESEL[15];
    int mobile;
    int age;
};

int AddAccoucnt(FILE *k)
{
    struct customer customer_id;

    k=fopen("Customers.txt","a+");

    customer_id.mobile=0;
    customer_id.age=0;
    puts("\tCREATE ACCOUNT");
    printf("\nName\t: ");
        scanf("%s", customer_id.name);
    printf("Surname : ");
        scanf("%s", customer_id.surname);
    printf("PESEL\t: ");
        scanf("%s", customer_id.PESEL);
    printf("Mobile\t: ");
        scanf("%d", &customer_id.mobile);
    printf("Age\t: ");
        scanf("%d", &customer_id.age);

    if (customer_id.age<18)
        puts("You are too young to have an account\n");
    else
    {
    puts("\nAccount was created\n\n");

    fprintf(k,"%s %s, age: %d,PESEL: %s, mobile: %d\n",
            customer_id.name, customer_id.surname, customer_id.age, customer_id.PESEL, customer_id.mobile);
    }
    fclose(k);
    return 0;
}
int DeleteAccount()
{
     FILE *k1, *k2;
    char filename[400];
    char ch;
    int line_delete, temp = 1;

    strcpy(filename, "Customers.txt");
    k1 = fopen(filename, "r");
    ch = getc(k1);

    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(k1);
    }

    rewind(k1);
    printf("\n\nWchich customer do you want to delete? Choose a number of line ");
    scanf("%d", &line_delete);

    k2 = fopen("Hold.c", "w");

    ch = 'A';
    while (ch != EOF)
    {
        ch = getc(k1);

        if (temp!=line_delete)
        {
            putc(ch, k2);
        }
        if (ch == '\n')
        {
            temp++;
        }
    }
    fclose(k1);
    fclose(k2);

    remove(filename);
    rename("Hold.c", filename);

    printf("\nCustomers' base:\n\n");
    k1 = fopen("Customers.txt", "r");
    ch = getc(k1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(k1);
    }
    fclose(k1);
    return 0;
}

void CheckCustomer(FILE *check)
{
    char ch;
    check = fopen("Customers.txt", "r");
    puts("Our customers:\n");

    ch = getc(check);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(check);
    }
    fclose(check);
}
