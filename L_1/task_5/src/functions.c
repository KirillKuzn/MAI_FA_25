#include "../include/functions.h"

void process_d(FILE *in, FILE *out){
    int c;
    while ((c = fgetc(in)) != EOF) {
        if (!isdigit(c)) {
            fputc(c, out);
        }
    }
}

void process_i(FILE *in, FILE *out){
    int c;
    int count = 0;

    while ((c = fgetc(in)) != EOF) {
        if (isalpha((unsigned char)c)) {
            count++;
        }
        if (c == '\n') {
            fprintf(out, "%d\n", count);
            count = 0;
        }
    }

    if (count > 0){
        fprintf(out, "%d/n", count);
    }
}

void process_s(FILE *in, FILE *out){
    int c;
    int count = 0;

    while ((c = fgetc(in)) != EOF) {
        unsigned char ch = (unsigned char)c;
        if (!isalpha(ch) && !isdigit(ch) && ch != ' ' && ch != '\n') {
            count++;
        }
        if (ch == '\n') {
            fprintf(out, "%d\n", count);
            count = 0;
        }
    }
    
    if (count > 0){
        fprintf(out, "%d/n", count);
    }
}

void process_a(FILE *in, FILE *out){
    int c;
    while ((c = fgetc(in)) != EOF) {
        if (isdigit(c)) {
            fputc(c, out);
        } else {
            fprintf(out, "%X", c);
        }
    }
}