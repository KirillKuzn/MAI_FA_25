#include "include/alnum.h"
#include <stdio.h>
#include <limits.h>

int main() {
    int base;
    char input[100];
    long long maxAbs = LLONG_MIN;
    long long maxNum = 0;

    printf("Enter the base of the number system (2..36): ");
    scanf("%d", &base);
    if (base < 2 || base > 36) {
        printf("Error: Base out of range.\n");
        return 1;
    }

    printf("Enter numbers in base %d (Stop for finish):\n", base);

    while (1) {
        scanf("%s", input);
        if (strcmp(input, "Stop") == 0)
            break;

        long long num = to_decimal(input, base);
        long long absVal = (num < 0) ? -num : num;

        if (absVal > maxAbs) {
            maxAbs = absVal;
            maxNum = num;
        }
    }

    char result[100];
    from_decimal(maxNum, base, result);
    printf("\nThe largest number in the original system (%d) by absolute value: %s\n", base, result);

    int bases[] = {9, 18, 27, 36};
    for (int i = 0; i < 4; i++) {
        from_decimal(maxNum, bases[i], result);
        printf("In the system with base %d: %s\n", bases[i], result);
    }

    return 0;
}