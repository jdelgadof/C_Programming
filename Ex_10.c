//
// Created by Jeferson on 11/09/2023.
//
#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[64];          // and hopefully no one enter a super long string
    do {
        printf("Enter a string. or type 'stop' to exit: ");
        fgets(word, sizeof(word), stdin);
        //printf("%s", word)
        if (word[strlen(word) - 1] == '\n') {
            word[strlen(word) - 1] = '\0';
        }
        printf("The amount of characters in '%s' is: %llu\n", word, strlen(word));
    }while (strcmp(word, "stop") != 0);

    return 0;
}
