//
// Created by Jeferson on 04/09/2023.
//
#include <stdio.h>
int read_range(int low, int high){
    int num_selection;
    do{
        printf("Roll a die and enter your result.\nEnter a number between %d and %d: ",low, high);
        scanf("%d", &num_selection);
        if (num_selection > high || num_selection < low){
            while (getchar() != '\n');
            printf("invalid input, Try again!\n");
        }else{
            return num_selection;
        }
    } while (num_selection < high || num_selection > low);
}

int main() {
    int rounds = 3;
    int low = 1;
    int high = 6;
    int number;
    printf("Let's play a small game!\n");
    for(int i = 0; i<rounds; i++){
        number = read_range(low, high);
        if(number == 6){
            printf("I got %d. It is a tie!\n", number);
        }else{
            printf("I got %d. I win!\n", number+1);
        }
    }
    printf("Better luck next time. Bye!\n");
}