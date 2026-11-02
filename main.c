#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>
#include <gmp.h>

void fib_init(mpz_t* pfib[4], mpz_t fib[4]){
    for (int i = 0; i<4; i++){
        mpz_init(fib[i]);
        pfib[i] = &fib[i];
    }
}

void fib_clear(mpz_t fib[4]){
    for (int i = 0; i<4; i++){
        mpz_clear(fib[i]);
    }
}

void step(mpz_t* pfib[4], mpz_t* n){  // mpz_add_ui, mpz_mul
    mpz_t* p;
    mpz_mul_2exp(*n, *pfib[1], 1);
    mpz_sub(*n, *n, *pfib[0]);
    mpz_mul(*pfib[2], *n, *pfib[0]);
    mpz_mul(*pfib[1], *pfib[1], *pfib[1]);
    mpz_mul(*pfib[0], *pfib[0], *pfib[0]);
    mpz_add(*pfib[3], *pfib[0], *pfib[1]);
    p = pfib[0];
    pfib[0] = pfib[2];
    pfib[2] = p;
    p = pfib[1];
    pfib[1] = pfib[3];
    pfib[3] = p;
}


int main(void){
    mpz_t* pfib[4];
    mpz_t fib[4];

    uint64_t goal;
    printf ("Enter your number: ");
    if (!scanf("%lu" , &goal)){
        printf("Input error!");
        return 1;
    }

    fib_init(pfib, fib);
    mpz_set_ui(fib[0],2);
    mpz_set_ui(fib[1],3);
    mpz_set_ui(fib[2],5);

    mpz_t n;
    mpz_init(n);
    mpz_set_ui(n, 0);

    for (int i = 0; i<goal; i++){
        // printf("step %d", i);
        step(pfib, &n);
    }
    // gmp_printf("nth fibunacci = %Zd, %Zd, %Zd\n", *pfib[0], *pfib[1], *pfib[2]);
    gmp_printf("%Zd\n", *pfib[1]);
    fib_clear(fib);
    mpz_clear(n);
    return 0;
}