#include "include/prime.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    const int T;
    printf("Enter the number of requests: ");
    scanf("%d", &T);
    int *res = (int*)malloc(T * sizeof(int));
    if (!res){
        printf("Memory allocation error\n");
        return -1;
    }
    printf("Enter %i numbers using ENTER:\n", T);
    for (size_t i = 0; i < T; i++){
        int n;
        scanf("%d", &n);
        res[i] = n;
    }
    printf("Results:\n");
    for (size_t i = 0; i < T; i++){
        printf("%d\n", nth_prime(res[i]));
    }
    free(res);
    res = NULL;
}