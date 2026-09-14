#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>
#include <gmp.h>

typedef struct{
    mpz_t a, b, c;
} Fib3;

void Fib3_init(Fib3* a){
    mpz_init(a->a);
    mpz_init(a->b);
    mpz_init(a->c);
}

void Fib3_clear(Fib3* a){
    mpz_clear(a->a);
    mpz_clear(a->b);
    mpz_clear(a->c);
}

void step(Fib3 *a, Fib3 *b, mpz_t* n, mpz_t* m){  // mpz_add_ui, mpz_mul
    mpz_mul(*n, b->a, b->a);
    mpz_mul(*m, b->b, b->b);
    mpz_add(a->a, *n, *m);
    mpz_add(*n, b->a, b->c);
    mpz_mul(a->b, b->b, *n);
    mpz_mul(*n, b->c, b->c);
    mpz_add(a->c, *n, *m);
}

void printFib3(Fib3 *a){
    gmp_printf("%Zd, %Zd, %Zd \n", a->a, a->b, a->c);
}

int main(void){
    uint64_t goal = 10;
    // printf ("Enter your number: ");
    // scanf("%lu", &goal); 

    int flag;
    Fib3 a, b;
    Fib3_init(&a);
    Fib3_init(&b);
    mpz_set_ui(a.a,2);
    mpz_set_ui(a.b,3);
    mpz_set_ui(a.c,5);

    mpz_t n, m;
    mpz_init(n);
    mpz_init(m);
    mpz_set_ui(n, 0);
    mpz_set_ui(m, 0);

    for (int i = 0; i<goal; i++){
        step(&b, &a, &n, &m);
        step(&a, &b, &n, &m);
    }
    printf (" nth fibunacci = ");
    gmp_printf("%Zd\n", a.a);
    printf ("\n");

    Fib3_clear(&a);
    Fib3_clear(&b);
}