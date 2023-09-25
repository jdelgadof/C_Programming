//
// Created by Jeferson on 22/09/2023.
//
#include <stdio.h>
#include <string.h>

# define MAX_LINES 40
# define MAX_NAME 40
# define MAX_LENGTH_NAME_FILE 30

typedef struct menu_item_ {
    char name[MAX_NAME];
    double price;
} menu_item;

void ReadMenu(const char* file_input,  menu_item *list_menu);
void get_input(char *input);

int main(void) {
    char file_name[MAX_LENGTH_NAME_FILE];       // and hopefully no one enter a super long file name
    menu_item list_menu[MAX_LINES];
    printf("Please enter the file name, don't forget to include the extension(i.e: .txt): ");
    get_input(file_name);
    ReadMenu(file_name, list_menu);
    return 0;
}
void ReadMenu(const char* file_input, menu_item *list_menu){
    int count = 0;
    FILE *file;
    file = fopen(file_input, "r");
    if (file == NULL) {
        fprintf(stderr, "'%s' file not found or unable to open, check and try again", file_input);
    }else{
        while (count < MAX_LINES) {
            if (fscanf(file, " %[^;];%lf",list_menu[count].name, &list_menu[count].price )==2){
                //Format specifier that helps to scan in both: name and price
                count++;
            }else{ break;}
        }
        fclose(file);
        printf("Here is the menu with the first 40 items on the file:\n\n");
        printf("Item\t   Price($)\tDescription\n");
        printf("---------------------------------------------------------------------\n");
        for(int i = 0; i < count; i++){
            printf("[%2d]\t%8.2f\t%s\n", i+1, list_menu[i].price, list_menu[i].name);
        }
    }
}
void get_input(char *input){
    fgets(input, MAX_LENGTH_NAME_FILE, stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
}