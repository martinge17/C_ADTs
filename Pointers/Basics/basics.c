#include <stdio.h>
#include <stdlib.h>





int main(){

    int a = 2;

    int *ptr;

    ptr=&a;

    int **p;
    p=&ptr;


    printf("Address: %p\n",ptr);
    printf("Value: %d\n",*ptr);
    printf("Address: %p\n",&a);
    printf("Address: %p\n",p);
    printf("Value: %d\n",**p);



    return 0;
}