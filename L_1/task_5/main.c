#include "include/functions.h"
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <flag> <input_file> [output_file]\n", argv[0]);
        return 1;
    }

    char *flag = argv[1];
    char *input_path = argv[2];
    char output_path[256];

    if ((flag[1] == 'n') && argc >= 4) {
        strcpy(output_path, argv[3]);
    } else {
        snprintf(output_path, sizeof(output_path), "out_%s", input_path);
    }

    FILE *in = fopen(input_path, "r");
    if (!in) {
        perror("Error opening input file");
        return 1;
    }

    FILE *out = fopen(output_path, "w");
    if (!out) {
        perror("Error opening output file");
        fclose(in);
        return 1;
    }

    char action = (flag[1] == 'n') ? flag[2] : flag[1];

    switch (action) {
        case 'd': process_d(in, out); break;
        case 'i': process_i(in, out); break;
        case 's': process_s(in, out); break;
        case 'a': process_a(in, out); break;
        default:
            fprintf(stderr, "Неизвестный флаг: %s\n", flag);
            fclose(in);
            fclose(out);
            return 1;
    }

    fclose(in);
    fclose(out);
    return 0;
}
