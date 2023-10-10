//
// Created by Jeferson on 09/10/2023.
//
#include <stdio.h>
#include <string.h>

# define MAX_LENGTH_NAME_FILE 256   //Hopefully the name of the file is not longer than 256
# define MAX_LINES 256              //Toivotavasti each line is not longer than 256

void get_input(char *input);
int calculate_checksum(const char *line);

int main() {
    char file_name[MAX_LENGTH_NAME_FILE];
    char line[MAX_LINES];
    printf("Enter the file name: ");
    get_input(file_name);

    FILE *file = fopen(file_name, "r");
    while (file == NULL) {
        fprintf(stderr, "'%s' file not found or unable to open, check and try again\n", file_name);
        printf("Enter the file name again: ");
        get_input(file_name);
        file = fopen(file_name, "r");
    }
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '$' && strchr(line, '*')) { //Checks that line starts with a '$' and later has an '*'
            int ex_checksum;
            if (sscanf(strchr(line, '*')+1, "%2x", &ex_checksum) == 1) {
                int cal_checksum = calculate_checksum(line);
                if (ex_checksum == cal_checksum) {
                    printf("[ OK ]\t%s", line);
                } else {
                    printf("[FAIL]\t%s", line);
                }
            }
        }else {
            printf("[FAIL]\tInvalid format: -> %s", line); // In case the line doesn't have a NMEA format
        }
    }
    fclose(file);
    return 0;
}
void get_input(char *input){
    fgets(input, MAX_LENGTH_NAME_FILE, stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
}
int calculate_checksum(const char *line) {
    int checksum = 0;
    for(int j = 1; line[j] != '*'; j++){
        checksum ^= line[j];
    }
    return checksum;
}
