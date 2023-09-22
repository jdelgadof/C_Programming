//
// Created by Jeferson on 19/09/2023.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

# define MAX_LINES 100
# define MAX_LENGTH_LINE 80
# define MAX_LENGTH_NAME_FILE 30

void ReadWriteCapitalFile(const char* file_input, char list[MAX_LINES][MAX_LENGTH_LINE]);
void get_input(char *input);

int main(void) {
    char file_name[MAX_LENGTH_NAME_FILE];       // and hopefully no one enter a super long file name
    char list[MAX_LINES][MAX_LENGTH_LINE];
    printf("Please enter the file name, don't forget to include the extension(i.e: .txt): ");
    get_input(file_name);
    ReadWriteCapitalFile(file_name, list);
    return 0;
}

void ReadWriteCapitalFile(const char* file_input, char list[MAX_LINES][MAX_LENGTH_LINE]) {
    int count = 0;
    FILE *file;
    file = fopen(file_input, "r");
    if (file == NULL) {
        fprintf(stderr, "'%s' file not found or unable to open, check and try again", file_input);
    } else {
        while (count < MAX_LINES && fgets(list[count], MAX_LENGTH_LINE, file) != NULL) {
            count++;
        }
        fclose(file);

        printf("Read %d lines from '%s':\n", count, file_input);
        // count = 100
        file = fopen(file_input, "w");  //not specify, but writing in the same file everything in CAPS
        if (file == NULL) {
            fprintf(stderr, "'%s' file not found or unable to open", file_input);
            // Stderr again in case the file can not access after reading, and according to Keijo is good practice
            // to always check if the file was successfully accessed.
        } else {
            for (int i = 0; i < count; i++) {
                int length = strlen(list[i]);
                //printf("%2d: strlen = %2d  ", i+1, length);
                for (int j = 0; j < length; j++) {
                    //printf("%c", toupper(list[i][j]));
                    putc(toupper(list[i][j]), file);
                    /*Puts character by character within the limits of the list(100x80)
                     if the original text is longer than (100x80) the rest will disappear*/
                }
            }
            printf("The file '%s' has been modify to uppercase successfully", file_input);
            fclose(file);
        }
    }
}

void get_input(char *input){
    fgets(input, MAX_LENGTH_NAME_FILE, stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
}