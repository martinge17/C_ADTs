#include <stdio.h>

int main(){

    int x = 5;
    int* p;
    p= &x;
    *p = 6;
    int** q;
    q = &p;

    printf("%d",**q);



    return 0;
}