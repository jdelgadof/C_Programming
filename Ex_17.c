//
// Created by Jeferson on 02/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

# define MAX_LENGTH_PASSWORD 32
# define MAX_LENGTH_NAME_FILE 32

bool password_generator(char *input, const char *word);

void get_input(char *input);

int main(void) {

    char word[MAX_LENGTH_NAME_FILE];
    do{
        srand(time(NULL));
        char password[MAX_LENGTH_PASSWORD];
        printf("Please enter a word to generate a secure password, or 'stop' to exit: ");
        get_input(word);
        if(password_generator(password,word)){
            printf("Your secure password is: %s\n", password);
        }else {
            fprintf(stderr, "Invalid input. The password is too long.\n");
        }
    }while (strcmp(word, "stop") != 0);

    return 0;
}
bool password_generator(char *input, const char *word){
    int length_word = 0;
    for (int i = 0; word[i] != '\0'; i++){
        length_word++;
    }
    int length_pass = (length_word*2)+1;
    if (length_pass < MAX_LENGTH_PASSWORD){ //size is supposed to be 32
        //input = (char*)malloc(length_pass);   I guess we do not supposed to allocated memory for the password (?)
        for(int i_pass = 0, j=0; j<=length_pass; j++){
            if(j % 2 == 0){
                int  ch;
                do{
                    ch = rand();
                }while(!isprint(ch));
                input[j] = ch;
            }else{
                input[j] = word[i_pass];
                i_pass ++;
            }
        }input[length_pass] = '\0';
        return true;
    }else{
        return false;
    }
}

void get_input(char *input){
    fgets(input, MAX_LENGTH_NAME_FILE, stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
}