#include "include/for_floats.h"
#include <string.h>

double parse_double(const char *s, int *ok) {
    char *endptr;
    double val = strtod(s, &endptr);
    if (*endptr != '\0') {
        *ok = 0; 
    } else {
        *ok = 1; 
    }
    return val;
}

int main(int argc, char* argv[]){
    if (argc < 2) {
        printf("Usage: prog -q eps a b c | -m x y | -t eps a b c\n");
        return 1;
    }

    char* flag = argv[1];
    if (strlen(flag) != 2 || flag[0] != '-'){
        printf("Wrong flag format: it must contain 2 symbols and starts with -\n");
        return 1;
    }

    int ok;
    switch (flag[1])
    {
    case ('q'):
    case ('t'):
        if (argc != 6) {
            printf("The -q/-t flag requires 4 parameters: eps a b c\n");
            return 1;
        }
        double eps = parse_double(argv[2], &ok);
        if (!ok) { printf("Error: eps is not a number\n"); return 1; }

        double a = parse_double(argv[3], &ok);
        if (!ok) { printf("Error: a is not a number\n"); return 1; }

        double b = parse_double(argv[4], &ok);
        if (!ok) { printf("Error: b is not a number\n"); return 1; }

        double c = parse_double(argv[5], &ok);
        if (!ok) { printf("Error: c is not a number\n"); return 1; }

        if (flag[1] == 'q'){
            quadratics(a, b, c, eps);
        } else {
            is_right_triangle(a, b, c, eps);
        }
        break;

    case ('m'):
        if (argc != 4) {
            printf("The -m flag requires 2 parameters: x y\n");
            return 1;
        }
        int x = atoi(argv[2]);
        int y = atoi(argv[3]);
        if (y == 0) {
            printf("Error: divisor must not be zero\n");
            return 1;
        }
        if (x % y == 0)
            printf("%d is a multiple of %d\n", x, y);
        else
            printf("%d is not a multiple of %d\n", x, y);
        break;
    default:
        printf("Error: unknown flag\n");
        printf("Usage: prog -q eps a b c | -m x y | -t eps a b c\n");
        return 1;
    }

    return 0;
}