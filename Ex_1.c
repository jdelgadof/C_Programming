//
// Created by Jeferson on 27/08/2023.
//
#include <stdio.h>
#include <stdbool.h>

int main() {
    float busPrice, taxiPrice, money;
    int choice;

    printf("Enter price of bus ticket:");
    scanf(" %f", &busPrice);

    printf("Enter price of taxi:");
    scanf(" %f", &taxiPrice);

    printf("How much money you have:");
    scanf(" %f", &money);

    while (true)
    {
        printf("You have %.2f Euro left.\n", money);
        if (money < busPrice && money < taxiPrice)
        {
            printf("You will need to walk. Bye!");
            break;
        }
        printf("Do you want to take\n");
        printf("\t1) Bus (%.2f)\n\t2) Taxi (%.2f)\n", busPrice, taxiPrice);
        printf("Enter your selection:");
        scanf(" %d", &choice);

        if (choice == 1)
        {
            if (money >= busPrice)
            {
                printf("You chose Bus\n");
                money -= busPrice;
            } else
            {
                //hypothetical case that the bus is more expensive than the taxi
                printf("You don't have enough money for a bus\n");
            }
        }
        if (choice == 2)
        {
            if (money >= taxiPrice)
            {
                printf("You chose Taxi\n");
                money -= taxiPrice;
            } else
            {
                printf("You don't have enough money for a taxi\n");
            }
        }
    }
    return 0;
}