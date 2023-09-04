//
// Created by Jeferson on 04/09/2023.
//
#include <stdio.h>
#include <stdbool.h>

bool read_positive(int *value);

int main() {

    int num_attempts = 0;
    int number;
    do{

        printf("Guess how much money I have!\n");
        bool success = read_positive(&number);
        if (success) {
            printf("You didn't get it right. I have %d euros. \n", number*2 +20);
        } else {
            printf("Incorrect input or non-positive number entered.\n");
            num_attempts ++;
        }
    }while (num_attempts !=3);
    printf("I give up! See you later!");
    return 0;
}

bool read_positive(int *value){
    int input;
    printf("Please enter a positive number: ");
    if (scanf("%d", &input) == 1 && input > 0) {
        *value = input;
        return true;
    } else {
        while (getchar() != '\n');
        return false;
    }
}