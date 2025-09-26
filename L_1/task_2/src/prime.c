#include "../include/prime.h"

bool isXPrime(const int x){
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int nthPrime(const int n){
    int index = 0, res = 2;
    while (index != n){
        if (isXPrime(res)) index++;
        if (index != n) res++;
    }
    return res;
}