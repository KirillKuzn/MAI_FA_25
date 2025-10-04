#pragma once

#include <math.h>

double f_a(double x);
double f_b(double x);
double f_c(double x);
double f_d(double x);
double trap_adaptive(double (*f)(double), double a, double b, double eps);
double choose_delta(double tail_target);
