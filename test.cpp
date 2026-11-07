#include <stdio.h>
int id;

void change(int a){
    id = a;
}

int main(void){
    change(5);
    printf("id: %d\n", id);
}