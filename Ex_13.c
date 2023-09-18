//
// Created by Jeferson on 18/09/2023.
//
#include <stdio.h>
#include <string.h>
#include "limits.h"

void ReadFile(const char* file_name);
void get_input(char *input);

int main(void) {
    char file_name[30];          // and hopefully no one enter a super long string
    printf("Please enter the file name, don't forget to include the extension(i.e: .txt): ");
    get_input(file_name);
    ReadFile(file_name);
    return 0;
}
void ReadFile(const char* file_name) {  //Function to read INT from a file and print out the largest, smaller and count of INT
    int number;
    int count = 0;
    FILE *file;
    file = fopen(file_name, "r");
    if (file == NULL) {
        fprintf(stderr,"'%s' file not found or unable to open, check and try again", file_name);
    } else {
        int min = INT_MAX;       //rough way to ensure the min INT and max INT, limits.h library
        int max = INT_MIN;
        while(fscanf(file, "%d", &number)==1){
            count ++;
            if (number>max){
                max = number;
            }
            if (number<min){
                min = number;
            }
        }
        printf("total count of numbers in the file: %d\n", count);
        printf("the smaller number of the file is: %d\n", min);
        printf("the greatest number of the file is: %d\n", max);
    }
    fclose(file);
}
void get_input(char *input){
    fgets(input, 30, stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
}

