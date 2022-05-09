#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Pointers by value

void function2(int *param)
{
    printf("param's address %p\n", param);
    param = NULL;
}

// Pointer by reference

void function4(int **par)
{
    *par = NULL;
}

int main()
{

    // Pointer by value

    int variable = 111;
    int *ptr = &variable;

    function2(ptr);
    printf("ptr's address %p\n", ptr);

    // Pointer by reference
    int *ptr2 = &variable;

    function4(&ptr2);
    printf("ptr's address %p\n", ptr2);

    return 0;
}
