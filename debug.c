//
// Created by Jeferson on 09/10/2023.
//
#include "debug.h"
#include <stdio.h>
#include <stdarg.h>

static int current_debug_level = 0;

void set_debug_level(int debug_level) {
    current_debug_level = debug_level;
}

int dprintf(int debug_level, const char *fmt, ...) {
    if (debug_level <= current_debug_level) {
        va_list args;
        va_start(args, fmt);
        fprintf(stderr, "[DBG%d] ", debug_level);
        int result = vfprintf(stderr, fmt, args);
        va_end(args);
        return result;
    }
    return 0;
}
