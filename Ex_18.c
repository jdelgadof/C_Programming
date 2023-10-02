//
// Created by Jeferson on 02/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int number;

    srand(time(NULL));
    do {
        printf("Please enter a number between 0-15 or a negative number to quit");
        scanf("%d", &number);
        if (number >= 0 && number <= 15) {
            int rand_int = rand() & 0xFFFF;
            printf("Original number: [0x%X]\n", rand_int);
            rand_int = rand_int >> number;
            printf("After moving %d bits to the right [0x%X]\n", number, rand_int);
            rand_int = rand_int & 0x21;          //Clears all bit but 0 and 5 [0010 0001]
            printf("After clearing everything but bit 0 and 5 [0x%02X]\n", rand_int);
        } else if(number>15){
            printf("Invalid input\n");
        }
    }while(number>=0);
    return 0;
}

