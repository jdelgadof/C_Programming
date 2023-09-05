//
// Created by Jeferson on 05/09/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_numbers(const int *array, int count);    //Declaring function to print numbers of an array

int main() {
    srand(time(NULL));
    int length_array = 15;                          //length of the array decide by the exercise
    int numbers_to_print[length_array];
    for (int i=0; i<length_array; i++){
        numbers_to_print[i] = rand();               //Random number generate between [0,RAND_MAX], this case Max=32767
    }
    print_numbers(numbers_to_print, length_array);
    //printf("%d", RAND_MAX);
    return 0;
}

void print_numbers(const int *array, int count){
    for (int j=0; j<count; j++){
        printf("%-d.\t %8d\n", j+1, array[j]);
    }
}