#include "CAR_RENTAL.h"

typedef struct DaysAndDate{
    int days;
    float date;
};

void Rent(FILE *fleet)
{
    struct DaysAndDate DAD;

    puts("We hope that you checked if the car is available in chosen date.\nOtherwise, shout down the car rental and run the program again.\n\n");
       FILE  *f1;
       FILE *f2;
    char filename[400];
    char ch, cha;
    int line_w, temp = 1;

    strcpy(filename, "Fleet.txt");
    fleet = fopen(filename, "r");
    ch = getc(fleet);
   while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fleet);
    }

    rewind(fleet);
    printf("\n\nWhich car do you want to rent? Choose the number of line ");
        scanf("%d", &line_w);
    CalculatorPrise();

    f1 = fopen("Rented.txt", "a+");

    ch = 'A';
    while (ch != EOF)
    {
        ch = getc(fleet);

        if (temp==line_w)
        {
            putc(ch, f1);
        }
        if (ch == '\n')
        {
            temp++;
        }
    }

    fclose(f1);
    fclose(fleet);

    int customer_r, temp2 = 1;

    strcpy(filename, "Customers.txt");
    f2 = fopen(filename, "r");
    ch = getc(f2);

    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(f2);
    }

    rewind(f2);
    printf("\n\nWhich customer do you choose? give the number of line ");
    scanf("%d", &customer_r);

    f1 = fopen("Rented.txt", "a+");
    printf("How many days? (1 day = 24h)\n");
        scanf("%d", &DAD.days);
    printf("When do you want to rent? (day.month)\n");
        scanf("%f", &DAD.date);

    fprintf(f1, "Number of Days: %d, from: %.2f,\nCustomer: ", DAD.days, DAD.date);
     puts("YOU GOT IT! You have to pay in our office.");

    cha = 'A';
    while (cha != EOF)
    {
        cha = getc(f2);

        if (temp2==customer_r)
        {
            putc(cha, f1);
        }
        if (cha == '\n')
        {
            temp2++;
        }
    }
    fprintf(f1,"\n");
    fclose(f2);
    fclose(f1);
}

void CalculatorPrise()
{
    int brand, days, prise, transport;

    puts("#################################################################");
    puts("#\t1-Lamborghini, Ferrari, McLaren, Bugatti, Koenigsegg\t#");
    puts("#\t2-BMW, Mercedes, Bentley, Audi, Maserati, Porsche\t#");
    puts("#\t3-Volvo, Jaguar, Lexus, Mustang, Infiniti, Chevrolet\t#");
    puts("#\t4-Inne\t\t\t\t\t\t\t#");
    puts("#################################################################");

     puts("In which group is the car??");
        scanf("%d", &brand);
     puts("How many days? (1 day = 24h)");
        scanf("%d", &days);
     puts("With car's transport to the chosen place?\n1-Yes\n2-No");
        scanf("%d", &transport);

     switch(brand)
     {
        case 1:
                if(transport==1){
                prise=5500*days;
                printf("Price: %d\n\n", prise);
                }

                if (transport==2){
                prise=5000*days;
                printf("Price: %d\n\n", prise);
                }
                break;
        case 2:
                if(transport==1){
                prise=3500*days;
                printf("Price: %d\n\n", prise);
                }

                if (transport==2){
                prise=3000*days;
                printf("Price: %d\n\n", prise);
                }
                break;
        case 3:
                if(transport==1){
                prise=2000*days;
                printf("Price: %d\n\n", prise);
                }
                if (transport==2){
                prise=1500*days;
                printf("Price: %d\n\n", prise);
                }
                break;
        case 4:
                puts("Individual price\n");
                break;
        default:
                puts("Wrong option");
                break;
        }
}

void CheckFleet(FILE *fl)
{
    char ch;
        fl = fopen("Fleet.txt", "r");
    ch = getc(fl);
        while (ch != EOF)
        {
            printf("%c", ch);
            ch = getc(fl);
        }
    fclose(fl);
}

void RentedCar(FILE *z)
{
    char rented[400];
    z=fopen("Rented.txt", "r");

    puts("Rented car and who rented:\n");
        while (fgets(rented,sizeof rented, z)!=0)
        {
            printf("%s ", rented);
        }
    fclose(z);
}
