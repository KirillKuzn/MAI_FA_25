#include "include/functions.h"
#include <stdio.h>

int main(){
    printf("e: series=%.7f, limit=%.7f, equation=%.7f\n", e_series(), e_limit(), e_equation());
    printf("pi: series=%.7f, limit=%.7f, equation=%.7f\n", pi_series(), pi_limit(), pi_equation());
    printf("ln2: series=%.7f, limit=%.7f, equation=%.7f\n", ln2_series(), ln2_limit(), ln2_equation());
    printf("sqrt2: series=%.7f, limit=%.7f, equation=%.7f\n", sqrt2_series(), sqrt2_limit(), sqrt2_equation());
    printf("gamma: series=%.7f, limit=%.7f, equation=%.7f\n", gamma_series(), gamma_limit(), gamma_equation());
    return 0;
}