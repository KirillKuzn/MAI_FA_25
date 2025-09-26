#include "../include/functions.h"

void printMultiplesOfX(const int x){
    if (x > 100 || x < 1){
        printf("There are no numbers within 100 that are multiples of x\n");
        return;
    }
    for (int i = x; i <= 100; i += x){
        if (i % x == 0)
            printf("%i\n", i);
    }
}

bool isXPrime(const int x){
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

void splitHexDigits(const int x){
    char buf[128];
    sprintf(buf, "%X", x);
    for (int i = 0; buf[i]; i++) {
        printf("%c ", buf[i]);
    }
    printf("\n");
}

void tableOfPowers(const int x){
    if (x > 10) {
        printf("For -e flag x must be less or equal 10");
        return;
    }
    for (int base = 1; base <= 10; base++) {
        printf("Base %d: ", base);
        for (int p = 1; p <= x; p++) {
            printf("%d^%d=%d ", base, p, (int)pow(base, p));
        }
        printf("\n");
    }
}

void sumFrom12X(const int x){
    if (x < 1){
        printf("For -a flag x must be greater or equal than 1");
        return;
    }

    long long sum = (long long)x * (x + 1) / 2;
    printf("Sum of numbers from 1 to %i: %lli\n", x, sum);
}

unsigned long long factorialX(const int x){
    unsigned long long res = 1;
    for (int i = 2; i <= x; i++) res *= i;
    return res;
}