#include <stdio.h>
#include <stdlib.h>

int main(){

    /*
    int a; //goes on stack

    int *p; //goes on heap
    p= malloc(sizeof(int));
    *p=20;     
    free(p);
    */

    int n;
    printf("Enter size of array\n");
    scanf("%d",&n);
    int *A= calloc(n,sizeof(int)); //Dynamically allocated array
    for (int i=0; i<n; i++) {
        A[i]=i+1;
    }
    for (int i=0; i<n; i++) {
        printf("%d ",A[i]);
    }

    return 0;
}

//calloc(num_of_arguments,size_of_data_type) also initializes to 0
//realloc(ptr_to_current_variable,new_size) -->change the size of a existing dynami variable
