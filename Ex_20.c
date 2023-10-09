//
// Created by Jeferson on 08/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "debug.h"

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Ask the user for the debug level
    int debug_level;
    printf("Enter debug level (0-4): ");
    if (scanf("%d", &debug_level) != 1 || debug_level < 0 || debug_level > 4) {
        fprintf(stderr, "Invalid debug level. Please enter a number between 0 and 4.\n");
        return 1;
    }

    set_debug_level(debug_level);

    for (int i = 1; i <= 5; i++) {
        int random_debug_level = rand() % 5;
        dprintf(random_debug_level, "This is a random debug message index [%d]\n", i);
    }

    return 0;
}
