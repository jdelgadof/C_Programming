//
// Created by Jeferson on 02/10/2023.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

# define MAX_LINES 40
# define MAX_NAME 40
# define MAX_LENGTH_NAME_FILE 30

typedef struct menu_item_ {
    char name[MAX_NAME];
    double price;
} menu_item;

void ReadMenu(const char* file_input,  menu_item *list_menu, int decision);
void get_input(char *input);
int compareByName(const void *a, const void *b);
int compareByPrice(const void *a, const void *b);

int main(void) {
    char file_name[MAX_LENGTH_NAME_FILE];       // and hopefully no one enter a super long file name
    menu_item list_menu[MAX_LINES];
    int decision;
    printf("Please enter the file name, don't forget to include the extension(i.e: .txt): ");
    get_input(file_name);
    printf("How yo like to organise the menu by\n[1] Price\t[2] Name\n");
    scanf("%d", &decision);
    while (decision<1 || decision>2){
        printf("Decision out of the scope\n");
        printf("How yo like to organise the menu by\n[1] Price\t[2] Name\n");
        scanf("%d", &decision);
    }
    printf("Here is the menu sorted:\n\n");
    ReadMenu(file_name, list_menu, decision);
    return 0;
}
void ReadMenu(const char* file_input, menu_item *list_menu, int decision){
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
        if (decision == 1){
            qsort(list_menu, count, sizeof(menu_item), compareByPrice);
        }else{
            qsort(list_menu, count, sizeof(menu_item), compareByName);
        }
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
int compareByName(const void *a, const void *b) {
    return strcmp(((menu_item*)a)->name, ((menu_item*)b)->name);
}
int compareByPrice(const void *a, const void *b) {
    return (((menu_item*)a)->price > ((menu_item*)b)->price) - (((menu_item*)a)->price < ((menu_item*)b)->price);
}