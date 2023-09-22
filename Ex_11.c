//
// Created by Jeferson on 15/09/2023.
//
#include <stdio.h>
#include <string.h>

int replace_char(char *word, const char *repl);
void get_input(char *input);

int main(void) {
    char word[80];
    char replace[3];

    printf("Enter a string with TWO characters:");      //Why when I asked the string first,
    get_input(replace);                              // it is modified to have the first item of the string as an '\000'???

    printf("Enter an initial string:");
    get_input(word);

    int count = replace_char(word, replace);
    if (count > 0){
        printf("Amount of characters changed = %d\n", count);
        printf("%s\n", word);
    }else{
        printf("The original string was not modify\n");
    }

    return 0;
}
int replace_char(char *word, const char *repl){
    int count = 0;
    if(strlen(repl) != 2){
        return 0;
    }
    for(int i = 0; word[i] != '\0' ;i++){
        if(word[i] == repl[0]){
            word[i] = repl[1];
            count ++;
        }
    }if (count > 0 ){
        return count;
    }else{
        return 0;
    }
}
void get_input(char *input){
    fgets(input, 80, stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
}