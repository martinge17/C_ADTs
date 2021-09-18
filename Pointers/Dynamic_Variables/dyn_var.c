#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Dyn Var by value 1st way

void print1(int param){
    printf("param's value:  %d\n",param);
    param=0;
}

//Dyn Var by value 2nd way

void print2(int *param){
    printf("param's value:  %d\n",*param);
    param=0;
}


//Dyn Var by reference

void sum(int *par){
    *par=*par + 10;
}

int main(){

    //Dyn Var by value 1st way

    int variable = 111;
    int *ptr= &variable;

    print1(*ptr);
    printf("ptr's value after %d\n",*ptr);

    //Dyn Var by value 2nd way

    print2(ptr);
    printf("ptr's value after %d\n",*ptr);

    
 
    //Dyn Var by reference

    int var = 111;
    
    printf("ptr's value before %d\n",var);
    sum(&var);
    printf("ptr's value after %d\n",var);


    return 0;
}

