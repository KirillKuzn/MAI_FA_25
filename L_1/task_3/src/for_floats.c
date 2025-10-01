#include "../include/for_floats.h"

int eq(double a, double b, double eps) {
    return fabs(a - b) < eps;
}

void solveQuadratic(double a, double b, double c, double eps){
    if (eq(a, 0.0, eps)) {
        if (eq(b, 0.0, eps)) {
            if (eq(c, 0.0, eps)) {
                printf("Infinitely many solutions\n");
            } else {
                printf("No solutions\n");
            }
        } else {
            double x = -c / b;
            printf("Linear equation, x = %.6f\n", x);
        }
        return;
    }

    double D = b*b - 4*a*c;
    if (D < -eps) {
        printf("No real solutions\n");
    } else if (eq(D, 0.0, eps)) {
        double x = -b / (2*a);
        printf("One solution: x = %.6f\n", x);
    } else {
        double sqrtD = sqrt(D);
        double x1 = (-b + sqrtD) / (2*a);
        double x2 = (-b - sqrtD) / (2*a);
        printf("Two solutions: x1 = %.6f, x2 = %.6f\n", x1, x2);
    }
}

void quadratics(double a, double b, double c, double eps){
    double coeffs[3] = {a, b, c};
    int used[3] = {0, 0, 0};
    double perms[6][3];
    int count = 0;

    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            for (int k=0;k<3;k++)
                if (i!=j && j!=k && i!=k) {
                    perms[count][0] = coeffs[i];
                    perms[count][1] = coeffs[j];
                    perms[count][2] = coeffs[k];
                    count++;
                }

    for (int i=0;i<6;i++) {
        printf("\nPermutation %d: a=%.3f, b=%.3f, c=%.3f\n",
               i+1, perms[i][0], perms[i][1], perms[i][2]);
        solveQuadratic(perms[i][0], perms[i][1], perms[i][2], eps);
    }
}

void isRightTriangle(double a, double b, double c, double eps){
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("The sides must be positive\n");
        return;
    }

    double sides[] = {a, b, c};
    for (size_t i = 1; i <= 2; i++){
        if (sides[i] > sides[0]){
            double temp = sides[i];
            sides[i] = sides[0];
            sides[0] = temp;
        }
    }

    if (sides[1] + sides[2] <= sides[0] + eps){
        printf("It is not a triangle\n");
        return;
    }

    double cc = pow(sides[0], 2), bb = pow(sides[1], 2), aa = pow(sides[2], 2);
    if (eq(aa+bb, cc, eps)){
        printf("It is a right triangle\n");
    } else {
        printf("It is not a right triangle\n");
    }
}