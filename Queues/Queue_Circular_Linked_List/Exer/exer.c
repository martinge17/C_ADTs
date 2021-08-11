#include <stdio.h>
#include "circular_list_queue.h"

void print_front(tQueue Q){
    printf(" %d ",front(Q));
}


int main(){

    tQueue Queue;
    createEmptyQueue(&Queue);
    enqueue(1,&Queue);
    enqueue(3,&Queue);
    print_front(Queue);
    printf("\n ------------------------------------\n");
    dequeue(&Queue);
    print_front(Queue);
    printf("\n ------------------------------------\n");
    enqueue(15,&Queue);
    enqueue(20,&Queue);
    print_front(Queue);
    printf("\n ------------------------------------\n");
    dequeue(&Queue);
    //dequeue(&Queue);
    //dequeue(&Queue);
    print_front(Queue);
    
    return 0;
}