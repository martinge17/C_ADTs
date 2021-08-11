#include <stdio.h>
#include <string.h>
#include "dynamic_stack.h"

void string_entry(char str[]){
    
    printf("Enter algebric expresion {} () [] (MAX 50)(ENTER to finish): \n");
    scanf("%50[^\n]",str);

}

void check_stack(char ch,tStack* stack){
    char stack_char=peek(*stack);

    if ((stack_char=='(')&&(ch==')')) {
        pop(stack);
    }else if((stack_char=='{')&&(ch=='}')){
        pop(stack);
    }else if ((stack_char=='[')&&(ch==']')) {
        pop(stack);
    }else {
        printf("Error! Incorrect Sequence\n");
        exit(1);

    }
}


void read_and_push(char str[],tStack* stack){
    char ch;
    int lenght= strlen(str);
    for (int i=0; i<lenght; i++) {
        ch=str[i];    
        if((ch=='(')||(ch=='{')||(ch=='[')){ push(ch,stack);}
        if((ch==')')||(ch=='}')||(ch==']')){ check_stack(ch,stack);}
    }
    if (!isEmptyStack(*stack)) {
        printf("Error! Unclosed Elements\n");
    }
      
}


int main(){
    char string[50];
    tStack stack;
    createEmptyStack(&stack);


    string_entry(string);

    printf("%s\n",string);
    read_and_push(string,&stack);

    
    return 0;
}

