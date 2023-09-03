//
// Created by Jeferson on 03/09/2023.
//
#include <stdio.h>
int read_integer(void){     // function to validate the input, ensuring it is an integer
    int num_selection;
    do{
        printf("Enter positive numbers or negative to stop: ");
        if (scanf("%d", &num_selection) != 1){
            while (getchar() != '\n');
            printf("invalid input, Try again\n");
        }else{
            return num_selection;
        }
    } while (num_selection == 0);
}

int main() {
    int number = 1;
    int total = 0;
    float average = 0;
    int count;
    for (count =1; number >= 0; count++){
                            //including Zero as "positive", however it's not specify in the instruction
        number = read_integer();
        if (number >= 0){
            total += number;
            average = (float)total / count;
        }
    }
    printf("You entered %d positive numbers. The average is:%.3f", count-2, average);
                            //Rough solution (count-2) to exclude two extra count in the loop
                            //and display the correct amount of positive numbers
    return 0;

}
