#include "../include/functions.h"
#include <stdbool.h>

#define EPS 1e-7



double e_series(){
    double sum = 1.0, term = 1.0;
    int n = 1;
    while (term > EPS) {
        term /= n;
        sum += term;
        n++;
    }
    return sum;
}

double e_limit(){
    int n = 1e7;
    return pow(1.0 + 1.0/n, n);
}

double e_equation(){
    double x = 2.0;
    while (fabs(log(x) - 1.0) > EPS) {
        x = x - (log(x) - 1.0) / (1.0/x);
    }
    return x;
}

double pi_series(){
    double sum = 0.0, term;
    int n = 0;
    do {
        term = (n % 2 == 0 ? 1.0 : -1.0) / (2.0*n + 1);
        sum += term;
        n++;
    } while (fabs(term) > EPS);
    return 4.0 * sum;
}

double pi_limit(){
    double product = 1.0, pi = pi_series();
    int k = 1;
    do {
        product *= (4.0 * k * k)/(4.0 * k * k - 1);
        k++;
    } while (fabs(pi - product * 2.0) > EPS);
    return product * 2.0;
}

double pi_equation() {
    double x = 3.0; // начальное приближение
    while (fabs(cos(x) + 1.0) > EPS) {
        x = x - (cos(x) + 1.0)/(-sin(x));
    }
    return x;
}

double ln2_series(){
    double sum = 0.0, term;
    int n = 1;
    do {
        term = (n % 2 == 0 ? -1.0 : 1.0) / n;
        sum += term;
        n++;
    } while (fabs(term) > EPS);
    return sum;
}

double ln2_limit() {
    int n = 1000000;
    return n * (pow(2.0, 1.0/n) - 1.0);
}

double ln2_equation(){
    double x = 0.5;
    while (fabs(exp(x) - 2.0) > EPS) {
        x = x - (exp(x) - 2.0)/exp(x);
    }
    return x;
}

double sqrt2_series(){
    double product = pow(2.0, 1.0/4), term;
    int k = 3;
    do {
        term = pow(2.0, pow(2.0, -k));
        product *= term;
        k++;
    } while (fabs(term - 1.0) > EPS);
    return product;
}

double sqrt2_limit(){
    double x = -0.5;
    while (sqrt(2) - x > EPS){
        x = x - pow(x, 2)/2 + 1;
    }
    return x;
}

double sqrt2_equation() {
    double x = 1.0;
    while (fabs(x*x - 2.0) > EPS) {
        x = x - (x*x - 2.0)/(2.0*x);
    }
    return x;
}

double gamma_series() {
    double gamma = -pi_equation()/6, term;
    int k = 2;
    do {
        term = 1 / pow((int)sqrt(k), 2) - 1 / k;
        gamma += term;
        k++;
    } while (fabs(term) > EPS);
    return gamma;
}

double gamma_limit(){
    int m = 1000000;
    double sum = 0.0;
    for (int k = 1; k <= m; k++) sum += 1.0/k;
    return sum - log(m);
}

bool is_prime(int n){
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

double gamma_equation(){
    double product = 1.0;
    double prev_limit = 0.0;
    double cur_limit = 0.0;

    int t = 2;
    int step = 1;

    do {
        if (is_prime(t)) {
            product *= (t - 1.0) / t;
        }
        
        prev_limit = cur_limit;
        cur_limit = log(t) * product;

        if (t < 1000) step = 1;
        else if (t < 10000) step = 10;
        else if (t < 100000) step = 100;
        else step = 1000;
        
        t += step;

    } while(fabs(cur_limit - prev_limit) > EPS && t < 10000000);

    return -log(cur_limit);
}

