#include "CAR_RENTAL.h"

struct car{
    char brand[30];
    char model[30];
    char plate[20];
    char colour[20];
    int year;
};

int AddCar(FILE *f)
{
    struct car car_id;

    f=fopen("Fleet.txt","a+");

    puts("\tADD A CAR");
    printf("\nBrand\t\t: ");
        scanf("%s", car_id.brand);

    printf("Model\t\t: ");
        scanf("%s", car_id.model);

    printf("License plate\t: ");
        scanf("%s", car_id.plate);

    printf("Colour\t\t: ");
        scanf("%s", car_id.colour);

    printf("Year\t\t: ");
        scanf("%d", &car_id.year);
    puts("\nAdded to the car rental fleet!\n");

    fprintf(f,"Brand: %s; Model: %s; License plate: %s; Colour: %s; Year: %d;\n",
            car_id.brand, car_id.model, car_id.plate, car_id.colour, car_id.year);

    fclose(f);
    return 0;
}

int DeleteCar()
{
     FILE *plik1, *plik2;
    char filename[400];
    char ch;
    int line, temp = 1;

    strcpy(filename, "Fleet.txt");
    plik1 = fopen(filename, "r");

    ch = getc(plik1);
        while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(plik1);
    }
    rewind(plik1);

    printf("\n\nWhich car do you want to delete? Choose the number of line ");
        scanf("%d", &line);

    plik2 = fopen("replica.c", "w");
    ch = 'A';
    while (ch != EOF)
    {
        ch = getc(plik1);

        if (temp!=line)
        {
            putc(ch, plik2);
        }
        if (ch == '\n')
        {
            temp++;
        }
    }
    fclose(plik1);
    fclose(plik2);

    remove(filename);
    rename("replica.c", filename);
    printf("\nFleet after delete:\n\n");

    plik1 = fopen("Fleet.txt", "r");
    ch = getc(plik1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(plik1);
    }
    fclose(plik1);

    return 0;
}
