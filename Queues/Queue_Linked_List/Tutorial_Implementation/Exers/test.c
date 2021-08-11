#include <stdio.h>
#include "queue.h"

void print_front(tQueue Q){
    printf(" %d ",front(Q));
}


int main(){

    tQueue Queue;
    createEmptyQueue(&Queue);
    enqueue(1,&Queue);
    enqueue(3,&Queue);
    dequeue(&Queue);
    print_front(Queue);
    enqueue(15,&Queue);
    enqueue(20,&Queue);
    print_front(Queue);
    dequeue(&Queue);
    print_front(Queue);
    
    return 0;
}