#include <stdio.h>
typedef struct{
    unsigned long long int a;
    unsigned long long int b;
    unsigned long long int c;
} Fib3;

void step(Fib3 *a, Fib3 *b){
    a->a = b->a*b->a + b->b*b->b;
    a->b = b->b*(b->a+b->c);
    a->c = b->b*b->b + b->c*b->c;
}

void printFib3(Fib3 *a){
    printf("%llu, %llu, %llu \n", a->a, a->b, a->c);
}

int main(void){
    int goal = 250;
    Fib3 a = {2, 3, 5};
    Fib3 b;
    for (int i = 0; i<20; i++){
        step(&b, &a);
        printFib3(&b);
        step(&a, &b);
        printFib3(&a);
    }
}