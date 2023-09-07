//
// Created by Jeferson on 07/09/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_numbers(const int *array, int count);
int find_first(const unsigned int *list, unsigned int to_find);

int main() {
    srand(time(NULL));
    int length_array = 20;                          //length of the array decide by the exercise = 20
    int lista[length_array];
    int user_input;
    for (int i=0; i<length_array-1; i++){
        lista[i] = 1 + rand()/((RAND_MAX + 1u)/20);; //Random number generate between [0,20]
    }
    lista[19] = 0;                                  //set the last index as zero
    print_numbers(lista, length_array);
    do{
        printf("Enter a number between [1-20], or enter 0 to stop: ");
        scanf("%d", &user_input);
        if(user_input <= 20 && user_input >= 0) { ;

            int input = find_first(lista, user_input);
            if (input >= 0){
                printf("Found Index [%d]\n", input);
            }else{
                printf("Not Found!\n");
            }
        }else{
            printf("wrong input!\n");
        }
    }while(user_input !=0);

    return 0;
}

void print_numbers(const int *array, int count){            //Re-used function from previous exercise
    for (int j=0; j<count; j++){
        printf("[%-d]\t %2d\n", j, array[j]);
    }
}

int find_first(const unsigned int *list, unsigned int to_find){
    int count = 0;
    while (list[count]!= 0){
        if(list[count] == to_find){
            return count;
        }
        count ++;
    };
    return -1;
}
