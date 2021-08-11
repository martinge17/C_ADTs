#include <stdio.h>
#include <string.h>
#include "dynamic_queue.h"
#include "dynamic_stack.h"

void string_entry(char str[]){
    
    printf("Enter character sequence (MAX 50)(ENTER to finish): \n");
    scanf("%50[^\n]",str);

}

void str2stack(char str[],tStack* stack){
    char ch;
    int lenght= strlen(str);
    for (int i=lenght; 0<=i; i--) {
        push(str[i],stack);       
    }
}

void stack2queue(tStack* stack,tQueue* queue){
    
    char tmp;
    while (!isEmptyStack(*stack)) {
        tmp=peek(*stack);
        pop(stack);
        enqueue(tmp,queue);
    }
}

void queue2stack(tStack* stack,tQueue* queue){
    
    char tmp;
    while (!isEmptyQueue(*queue)) {
        tmp=front(*queue);
        dequeue(queue);
        push(tmp,stack);
    }
}

void read_stack(tStack stack){ //Only for test purposes !!!!!!!!!!!!! 
    char tmp;
    while (!isEmptyStack(stack)) {
        tmp=peek(stack);
        pop(&stack); 
        printf("%c\n",tmp);
    }
}



int main(){
    char string[50];
    tStack stack;
    createEmptyStack(&stack);
    tQueue queue;
    createEmptyQueue(&queue);
  

    string_entry(string);
    printf("Inital Stack:\n");
    printf("%s\n",string);
    str2stack(string,&stack);
    stack2queue(&stack,&queue);
    queue2stack(&stack,&queue);
    printf("Reverse Stack:\n");
    read_stack(stack);

    return 0;
}