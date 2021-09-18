#include <stdio.h>
#include <stdlib.h>

// Pointer to functions

int Add(int a, int b) { return a + b; }

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main() {

  int c;
  int (*p)(int, int); // Pointer to function that should take
                      //(int,int) as argument/parameter and return int

  p = &Add;
  c = (*p)(2, 3); // dereferencing and executing the function
  printf("Sum = %d\n\n", c);

  int m = 25;
  int n = 100;
  printf("m is %d, n is %d\n", m, n);
  swap(&m, &n);
  printf("m is %d, n is %d\n", m, n);

  return 0;
}