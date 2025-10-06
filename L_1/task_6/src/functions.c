#include "../include/functions.h"

double f_a(double x) {
    if (x == 0.0) return 1.0;         
    return log1p(x) / x;              
}

double f_b(double x) {
    return exp(-0.5 * x * x);
}

double f_c(double x) {
    // -ln(1-x); на x=1 не определено, интегрируем до 1 - delta
    if (x >= 1.0) return INFINITY;
    double t = 1.0 - x;
    return -log(t);
}

double f_d(double x) {
    if (x == 0.0) return 1.0;          
    return exp(x * log(x));
}

double trap_fixed(double (*f)(double), double a, double b, int n) {
    // Составная формула трапеций с n равными подотрезками
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        sum += f(a + i * h);
    }
    return sum * h;
}

double trap_adaptive(double (*f)(double), double a, double b, double eps) {
    // Адаптивное удвоение разбиения до достижения требуемой точности
    int n = 4;
    double prev = trap_fixed(f, a, b, n);
    for (;;) {
        n *= 2;
        double curr = trap_fixed(f, a, b, n);
        if (fabs(curr - prev) <= eps) return curr;
        prev = curr;
        if (n > (1<<27)) { 
            return curr;
        }
    }
}

double choose_delta(double tail_target) {
    // хвост = -delta * ln(delta) + delta = delta * (1 - ln delta)
    double delta = fmin(1e-2, tail_target);  
    for (int i = 0; i < 50; ++i) {
        double tail = -delta * log(delta) + delta;
        if (tail <= tail_target) break;
        delta *= 0.5;
    }
    return delta;
}