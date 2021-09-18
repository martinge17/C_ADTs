#include <stdio.h>
#include <stdlib.h>

int* Add(int* a,int* b){
    int *c= malloc(sizeof(int));
    *c = (*a) + (*b);
    return c;
}

int main(){
    int a=2,b=4;
    int* ptr = Add(&a, &b);
    printf("Sum = %d\n",*ptr);
    

    return 0;
}