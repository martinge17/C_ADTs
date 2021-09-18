// Function ptrs and callbacks

// In this example we will use qsort() "That use function ptrs" to sort an array

#include <stdio.h>
#include <stdlib.h>

int cmp_function(const void *a, const void *b) {

  int A = *((int *)a); // First typecst to int pointer and then de-reference.
  int B = *((int *)b);

  return A - B; // A-B in case of lower to higher  B-A in case of higher to
                // lower
}

int main() {

  int nums[] = {13, 26, -4, 6, 67, -20, 32};
  int num_elements = sizeof(nums) / sizeof(int);

  for (int i = 0; i < num_elements; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n\n");

  qsort(nums, num_elements, sizeof(int), cmp_function);

  for (int i = 0; i < num_elements; i++) {
    printf("%d ", nums[i]);
  }

  return 0;
}