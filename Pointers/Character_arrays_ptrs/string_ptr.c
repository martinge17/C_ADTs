#include <stdio.h>

void print(char* c){
    int i=0;
    while(c[i]!='\0'){
        printf("%c",c[i]);
        i++;
    }
    printf("\n");
}

int main(){ 
    char c[20]="Hello";
    print(c);
    return 0;
}