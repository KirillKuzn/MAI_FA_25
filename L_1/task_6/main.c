#include "include/functions.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <epsilon>\n", argv[0]);
        return 1;
    }

    char *endp = NULL;
    double eps = strtod(argv[1], &endp);
    if (endp == argv[1] || eps <= 0.0 || !isfinite(eps)) {
        fprintf(stderr, "Error: epsilon must be positive float number.\n");
        return 1;
    }

    double epsA = eps, epsB = eps, epsD = eps;

    // Интеграл (c): делим на численную часть и аналитический хвост
    double tail_target = eps / 4.0;
    double delta = choose_delta(tail_target);
    double tail = -delta * log(delta) + delta;
    double epsC_numeric = eps - tail;              
    if (epsC_numeric < eps * 0.25) epsC_numeric = eps * 0.25; 

    double Ia = trap_adaptive(f_a, 0.0, 1.0, epsA);
    double Ib = trap_adaptive(f_b, 0.0, 1.0, epsB);
    double Ic_num = trap_adaptive(f_c, 0.0, 1.0 - delta, epsC_numeric);
    double Ic = Ic_num + tail;
    double Id = trap_adaptive(f_d, 0.0, 1.0, epsD);

    printf("epsilon = %.12g\n", eps);
    printf("a) ∫_0^1 ln(1+x)/x dx      ≈ %.15f\n", Ia);
    printf("b) ∫_0^1 e^(-x^2/2) dx      ≈ %.15f\n", Ib);
    printf("c) ∫_0^1 ln(1/(1-x)) dx     ≈ %.15f (delta=%.3e, tail=%.3e)\n", Ic, delta, tail);
    printf("d) ∫_0^1 x^x dx             ≈ %.15f\n", Id);

    return 0;
}