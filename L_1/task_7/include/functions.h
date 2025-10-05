#pragma once

#include <string.h>
#include <ctype.h>

int char_value(char c);
int find_min_base(const char *s);
char *remove_leading_zeros(char *s);
long long to_decimal(const char *s, int base);
