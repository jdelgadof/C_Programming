//
// Created by Jeferson on 15/09/2023.
//
#include <stdio.h>
#include <string.h>
int count_words(const char* str, const char *word);
void get_input(char *input);

int main(void) {
    char input_text [200];                 //Hoping the text is not longer that the 200 buffer
    char word [30];                        //Hoping that the word to find is not longer than 30
    do{
        printf("Enter text:");
        get_input(input_text);           //Function to avoid repeating the fgets() arguments

        printf("Enter a word to find the occurrence in the previous text:");
        get_input(word);

        int times = count_words(input_text, word);
        printf("Word '%s' is %d times in the text provided.\n", word, times);
    }while(strcmp(word, "stop") != 0);

    return 0;
}
int count_words(const char* str, const char *word){
    int count = 0;
    const char *position = str;
    while ((position = strstr(position, word)) != NULL) {
            position ++;
            count++;
        }
    return count;
}
void get_input(char *input){
    fgets(input, 200, stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
}