#include "../include/functions.h"

int char_value(char c) {
    if (isdigit(c))
        return c - '0';
    if (isalpha(c))
        return toupper(c) - 'A' + 10;
    return -1;
}

int find_min_base(const char *s) {
    int max_digit = 0;
    for (int i = 0; s[i]; i++) {
        int val = char_value(s[i]);
        if (val >= 0 && val > max_digit)
            max_digit = val;
    }
    int base = max_digit + 1;
    if (base < 2) base = 2;
    return base;
}

char *remove_leading_zeros(char *s) {
    while (*s == '0' && s[1] != '\0') s++;
    return s;
}

long long to_decimal(const char *s, int base) {
    long long value = 0;
    for (int i = 0; s[i]; i++) {
        int digit = char_value(s[i]);
        if (digit < 0 || digit >= base) {
            return -1;
        }
        value = value * base + digit;
    }
    return value;
}