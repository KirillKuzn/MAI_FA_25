#include "include/functions.h"
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <number> <flag>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    char *flag = argv[2];

    if (flag[0] == '/') flag[0] = '-';

    if (strlen(flag) != 2 || flag[0] != '-'){
        printf("Wrong flag's format\n");
        return 1;
    }

    switch (flag[1]) {
        case 'h':
            printMultiplesOfX(x);
            break;
        case 'p':
            if (x < 2) {
                printf("%d is neither prime nor composite\n", x);
            } else if (isXPrime(x)) {
                printf("%d is prime\n", x);
            } else {
                printf("%d is composite\n", x);
            }
            break;
        case 's':
            splitHexDigits(x);
            break;
        case 'e':
            tableOfPowers(x);
            break;
        case 'a':
            sumFrom12X(x);
            break;
        case 'f':
            if (x < 0) {
                printf("The factorial of negative numbers is not defined\n");
                return 1;
            }
            printf("%d! = %llu\n", x, factorialX(x));
            break;
        default:
            printf("Unknown flag: %s\n", flag);
    }

    return 0;
}