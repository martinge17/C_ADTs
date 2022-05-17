#include <stdio.h>
#include "priority_queue.h"

//Create a function that prints the priority of each node and the front element the embedded queue

void print_headers(tPosL pos,tOrderedList queueP){
    tPriority prio;
    tQueue embedded_queue;

    if(pos==LNULL){
        return;
    }

    getItem(pos, queueP, &prio, &embedded_queue);

    printf("Priority: %d  First: %d \n",prio,front(embedded_queue));

}


void queue_tour(tQueueP queueP){

    tPosL pos;
    
    if (isEmptyQueueP(queueP)) {
        printf("Empty\n");
    }else {
        for (pos=queueP;pos!=LNULL;pos=pos->next){
            print_headers(pos, queueP);
        }
    }
}

 
int main(){

    tQueueP queueP;
    createEmptyQueueP(&queueP);
    if(isEmptyQueueP(queueP)){ printf("Empty\n");}



    enqueueP(911,1,&queueP);
    enqueueP(836,1,&queueP);
    queue_tour(queueP);
    dequeueP(&queueP);
    printf("Dequeue\n");
    enqueueP(432,2,&queueP);
    enqueueP(536,2,&queueP);
    enqueueP(123,5,&queueP);
    enqueueP(456,5,&queueP);
    queue_tour(queueP);
    dequeueP(&queueP);
    printf("Dequeue\n");
    queue_tour(queueP);
    dequeueP(&queueP);
    printf("Dequeue\n");
    queue_tour(queueP);
    dequeueP(&queueP);
    printf("Dequeue\n");
    queue_tour(queueP);
    dequeueP(&queueP);
    printf("Dequeue\n");
    queue_tour(queueP);
    dequeueP(&queueP);
    printf("Dequeue\n");
    queue_tour(queueP);



    return 0;
}
