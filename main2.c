#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>
#include <gmp.h>


void fib_init(mpz_t* pfib[6], mpz_t fib[6]){
    for (int i = 0; i<6; i++){
        mpz_init(fib[i]);
        pfib[i] = &fib[i];
    }
}

void fib_clear(mpz_t fib[6]){
    for (int i = 0; i<6; i++){
        mpz_clear(fib[i]);
    }
}

void step(mpz_t* pfib[6], mpz_t* n, mpz_t* m){  // mpz_add_ui, mpz_mul
    mpz_mul(*n, *pfib[0], *pfib[0]);
    mpz_mul(*m, *pfib[1], *pfib[1]);
    mpz_add(*pfib[3], *n, *m);
    mpz_add(*n, *pfib[0], *pfib[2]);
    mpz_mul(*pfib[4], *pfib[1], *n);
    mpz_mul(*n, *pfib[2], *pfib[2]);
    mpz_add(*pfib[5], *n, *m);
    mpz_t* p = pfib[0];
    pfib[0] = pfib[3];
    pfib[3] = p;
    p = pfib[1];
    pfib[1] = pfib[4];
    pfib[4] = p;
    p = pfib[2];
    pfib[2] = pfib[5];
    pfib[5] = p;
}


int main(void){
    mpz_t* pfib[6];
    mpz_t fib[6];

    uint64_t goal = 1;
    printf ("Enter your number: ");
    scanf("%lu", &goal); 

    fib_init(pfib, fib);
    mpz_set_ui(fib[0],2);
    mpz_set_ui(fib[1],3);
    mpz_set_ui(fib[2],5);

    mpz_t n, m;
    mpz_init(n);
    mpz_init(m);
    mpz_set_ui(n, 0);
    mpz_set_ui(m, 0);

    for (int i = 0; i<goal; i++){
        step(pfib, &n, &m);
    }
    // printf ("nth fibunacci = ");
    gmp_printf("nth fibunacci = %Zd, %Zd, %Zd\n", *pfib[0], *pfib[1], *pfib[2]);
    // printf ("\n");
    fib_clear(fib);
    mpz_clear(n);
    mpz_clear(m);
}
