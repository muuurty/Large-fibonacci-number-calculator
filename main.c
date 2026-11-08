#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>
#include <gmp.h>

#define FIB_LEN 5

typedef struct {
  int length;
  uint64_t code;
} Code;

Code make_code(uint64_t goal){
    Code c;
    c.length = 0;
    c.code = 0;
    int code_len = 0;
    while(1 != goal){
        if (goal%2==0){
            goal/=2;
            c.code+=1;
        }else{
            goal-=1;
        }
        c.length++;
        c.code <<= 1;
    }
    return c;
}

void fib_init(mpz_t* pfib[FIB_LEN], mpz_t fib[FIB_LEN]){
    for (int i = 0; i<FIB_LEN; i++){
        mpz_init(fib[i]);
        pfib[i] = &fib[i];
    }
}

void fib_clear(mpz_t fib[FIB_LEN]){
    for (int i = 0; i<FIB_LEN; i++){
        mpz_clear(fib[i]);
    }
}

void add_index(mpz_t* pfib[FIB_LEN]){
    mpz_t* p;
    mpz_add(*pfib[0], *pfib[1], *pfib[0]);
    mpz_add(*pfib[2], *pfib[3], *pfib[2]);
    p = pfib[0];
    pfib[0] = pfib[1];
    pfib[1] = p;
    p = pfib[2];
    pfib[2] = pfib[3];
    pfib[3] = p;
}

void double_index(mpz_t* pfib[FIB_LEN]){  // mpz_add_ui, mpz_mul
    mpz_t* p;
    mpz_mul_2exp(*pfib[4], *pfib[1], 1);
    mpz_sub(*pfib[4], *pfib[4], *pfib[0]);
    mpz_mul(*pfib[2], *pfib[4], *pfib[0]);
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
    mpz_t* pfib[FIB_LEN];
    mpz_t fib[FIB_LEN];

    uint64_t goal;
    printf ("Enter your number: ");
    if (!scanf("%lu" , &goal)){
        printf("Input error!");
        return 1;
    }
    Code code = make_code(goal);

    fib_init(pfib, fib);
    mpz_set_ui(fib[0],1);
    mpz_set_ui(fib[1],1);
    mpz_set_ui(fib[4],0);
    for (int i = 0; i<code.length; i++){
        if (code.code & 2){
            double_index(pfib);
        }else{
            add_index(pfib);
        }
        code.code >>= 1;
    }
    gmp_printf("%Zd\n", *pfib[0]);
    fib_clear(fib);
    return 0;
}