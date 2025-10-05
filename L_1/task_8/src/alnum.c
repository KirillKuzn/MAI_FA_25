#include "../include/alnum.h"

int char_value(char c) {
    if (isdigit(c))
        return c - '0';
    if (isalpha(c))
        return toupper(c) - 'A' + 10;
    return -1;
}

long long to_decimal(const char *s, int base) {
    int neg = 0;
    long long value = 0;

    if (*s == '-'){
        neg = 1;
        s++;
    }

    while (*s) {
        int digit = char_value(*s++);
        if (digit < 0 || digit >= base) {
            fprintf(stderr, "Error: Invalid character in number.\n");
            exit(1);
        }
        value = value * base + digit;
    }
    return neg ? -value : value;
}

void from_decimal(long long num, int base, char *out) {
    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char buf[100];
    int neg = 0;
    int i = 0;

    if (num == 0) {
        strcpy(out, "0");
        return;
    }

    if (num < 0) {
        neg = 1;
        num = -num;
    }

    while (num > 0) {
        buf[i++] = digits[num % base];
        num /= base;
    }

    if (neg)
        buf[i++] = '-';

    for (int j = 0; j < i; j++)
        out[j] = buf[i - j - 1];
    out[i] = '\0';
}