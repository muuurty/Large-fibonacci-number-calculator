#include <stdio.h>

typedef struct{
  int a, b, c;
  int *pa, *pb, *pc;
} Intp;

void mul(int a[6], int b){
  for (int i = 0; i<6; i++){
    a[i]*=b;
  }
}

void printArr(int arr[6]) {
    for (int i = 0; i < 6; i++)
        printf("%d: %d, ",i, arr[i]);
    printf("\n");
}

void fibp(int fib[6], int* pfib[6]) {
    for (int i = 0; i < 6; i++)
        pfib[i]=&fib[i];
    printf("\n");
}

int main() {
  int* pfib[6];
  int fib[6] = {0,1,2,3,4,5};
  fibp(fib, pfib);
  printf("%d", *pfib[1]);




  // int fib[6] = {0,1,2,3,4,5};
  // mul(fib, 5);
  // printArr(fib);
  //printf("0:%d, 1:%d, 2:%d, 3:%d, 4:%d, 5:%d \n", Fib[0], Fib[1], Fib[2], Fib[3], Fib[4], Fib[5]);

  // int a, b, c;
  // int *pa, *pb, *pc;
  // a = 1;
  // b = 2;
  // c = 3;
  // pa = &a;
  // pb = &b;
  // pc = &c;
  // printf("a:%d, b:%d, c:%d \n", *pa, *pb, *pc);
  // int* pd;
  // pd = pa;
  // pa = pb;
  // pb = pc;
  // pc = pd;
  // printf("a:%d, b:%d, c:%d \n", *pa, *pb, *pc);
}