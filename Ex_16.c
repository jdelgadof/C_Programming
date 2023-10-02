//
// Created by Jeferson on 25/09/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define MAX_LENGTH_NAME_FILE 30

typedef struct node {
    int number;
    struct node *next;
} nnode;

nnode* add_Node(nnode* head, int num){
    nnode* new_node = (nnode*)malloc(sizeof(nnode));
    new_node->number = num;
    new_node->next = head;
    return new_node;
}
void print_numbers(nnode* head){
    nnode* actual = head;
    while(actual != NULL){
        printf("->\t[%d]\n", actual->number);
        actual = actual->next;
    }
}
void free_memory(nnode* head){
    while(head != NULL){
        nnode* temp = head;
        head = head->next;
        free(temp);
    }
}
void get_input(char *input){
    fgets(input, MAX_LENGTH_NAME_FILE, stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
}
int main(void) {
    nnode * head = NULL;
    char file_name[MAX_LENGTH_NAME_FILE];
    do{
        printf("Please enter a number or 'end' to finnish: ");
        get_input(file_name);
        int num;
        if (sscanf(file_name, "%d", &num) == 1) {
            head = add_Node(head, num);
        } else {
            fprintf(stderr, "Invalid input. Please enter a number or 'end'.\n");
        }
    }while(strcmp(file_name, "end") != 0);

    printf("Entered numbers:\n");
    printf("----------------\n");
    print_numbers(head);
    free_memory(head);

    return 0;
}