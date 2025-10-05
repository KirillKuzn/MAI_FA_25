#include "include/functions.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Использование: %s <input.txt> <output.txt>\n", argv[0]);
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");
    if (!fin) {
        perror("Ошибка открытия входного файла");
        return 1;
    }

    FILE *fout = fopen(argv[2], "w");
    if (!fout) {
        perror("Ошибка открытия выходного файла");
        fclose(fin);
        return 1;
    }

    char token[128];
    while (fscanf(fin, "%127s", token) == 1) {
        char *num = remove_leading_zeros(token);
        int base = find_min_base(num);
        long long decimal = to_decimal(num, base);
        fprintf(fout, "%s %d %lld\n", num, base, decimal);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}