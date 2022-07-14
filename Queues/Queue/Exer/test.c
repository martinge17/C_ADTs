#include <stdio.h>
#include "circular_queue.h"


void print_front(tQueue Q){
    if(!isEmptyQueue(Q)){
        printf(" %d \n",front(Q));
    }else{
        printf("Empty!\n");
    }
}

int main(){

    tQueue Queue;
    createEmptyQueue(&Queue);
    enqueue(1,&Queue);
    if(!isEmptyQueue(Queue)){ dequeue(&Queue); }
    enqueue(3,&Queue);
    print_front(Queue);
    if(!isEmptyQueue(Queue)){ dequeue(&Queue); }
    print_front(Queue);
    enqueue(15,&Queue);
    enqueue(20,&Queue);
    if(!isEmptyQueue(Queue)){ dequeue(&Queue); }
    print_front(Queue);
    if(!isEmptyQueue(Queue)){ dequeue(&Queue); }
    print_front(Queue);
    if(!isEmptyQueue(Queue)){ dequeue(&Queue); }
    print_front(Queue); //Empty
    if(!isEmptyQueue(Queue)){ dequeue(&Queue); }
    print_front(Queue); //Empty

    printf("Check\n");


    //Check if full
    if(!enqueue(1,&Queue)){
        printf("Full!!!!\n");
    }else{
        printf("No problem\n");
    }

    return 0;
}
