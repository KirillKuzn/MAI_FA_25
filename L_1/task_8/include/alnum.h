#ifndef ALNUM_H_
#define ALNUM_H_

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int char_value(char c);
long long to_decimal(const char *s, int base);
void from_decimal(long long num, int base, char *out);

#endif