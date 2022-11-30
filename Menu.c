#include "CAR_RENTAL.h"

int Menu()
{
     int x;
    while(1){
        puts("#################################");
        puts("#\t1-Customer area\t\t#");
        puts("#\t2-Car area\t\t#");
        puts("#\t3-Admin area\t\t#");
        puts("#\t4-Exit\t\t\t#");
        puts("#################################");

        puts("Choose number");
        scanf("%d", &x);

        switch(x){
    case 1:
        MenuCustomer();
        break;
    case 2:
        MenuCar();
    case 3:
        MenuAdmin();
        break;
    case 4:
        puts("Bye ;)");
        exit(1);
         break;
    default:
        puts("Wrong options");
                }
        }
}

void MenuAdmin(){
    int x;

    puts("#################################");
    puts("#\tADMIN AREA\t\t#");
    puts("#################################");
    puts("#\t1-Add a car\t\t#");
    puts("#\t2-Delete a car\t\t#");
    puts("#\t3-Show rented cars\t#");
    puts("#\tand theirs customers\t#");
    puts("#\t4-Show customers\t#");
    puts("#\t5-Show car rental fleet\t#");
    puts("#\t6-Exit area\t\t#");
    puts("#################################");

    puts("Choose");
     scanf("%d", &x);
     switch(x){
     case 1:
            AddCar();
            break;
     case 2:
            DeleteCar();
            break;
     case 3:
            RentedCar();
            break;
     case 4:
            CheckCustomer();
            break;
     case 5:
            CheckFleet();
            break;
     case 6:
            Menu();
            break;
     default:
            puts("Wrong option");
            break;
     }
}

void MenuCar(){
    FILE *p;
    int x;
    puts("#################################");
    puts("#\tCARS AREA\t\t#");
    puts("#################################");
    puts("#\t1-Rent\t\t\t#");
    puts("#\t2-Show car rental fleet\t#");
    puts("#\t3-Check unavailable cars#");
    puts("#\t4-Exit area\t\t#");
    puts("#################################");

        puts("Choose");
        scanf("%d", &x);
            switch(x){
    case 1:
            Rent(p);
            break;
    case 2:
            CheckFleet(p);
            break;
    case 3:
            RentedCar(p);
            break;
    case 4:
            Menu();
            break;
    default:
            puts("Wrong option");
            break;
            }
}

void MenuCustomer(){
    int x;

    puts("#################################");
    puts("#\tCUSTOMER AREA\t\t#");
    puts("#################################");
    puts("#\t1-Create account\t#");
    puts("#\t2-Delete account\t#");
    puts("#\t3-Check a price\t\t#");
    puts("#\t4-Rent\t\t\t#");
    puts("#\t5-Exit area\t\t#");
    puts("#################################");

    puts("Choose");
    scanf("%d", &x);
    switch(x){
    case 1:
            AddAccoucnt();
            break;
    case 2:
            DeleteAccount();
            break;
    case 3:
            CalculatorPrise();
            break;
    case 4:
            Rent();
            break;
    case 5:
            Menu();
            break;
    default:
            puts("Wrong option");
            break;
            }
}
