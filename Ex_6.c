//
// Created by Jeferson on 04/09/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int menu(int low, int high){
    int num_selection;
    printf("Choose an option:\n");
    printf("\t%d. Roll D6\n\t%d. Roll D10\n\t%d. Quit\n",low, low+1, high);

    do{
        printf("Enter your choice from 1 to 3: ");
        if (scanf("%d", &num_selection) != 1 || num_selection > high || num_selection < low){
            while (getchar() != '\n');
            printf("invalid input, Try again!\n");
        }else{
            return num_selection;
        }
    } while (1);
}
int main() {
    srand(time(NULL));
    int choice;
    int random_number;
    do {
        choice = menu(1,3);
        switch (choice) {
            case 1:
                random_number = 1 + rand() % 6;
                printf("You choose a 6 sides dice\nYou rolled a %d\n", random_number);
                break;
            case 2:
                random_number = 1 + rand() % 10;
                printf("You choose a 10 sides dice\nYou rolled a %d\n", random_number);
                break;
            case 3:
                printf("You quited\n");
                break;
        }
    }while (choice != 3);
    return 0;
}