#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

bool isEmptyQueue(tQueue Q) {
  return (Q->rear == QNULL); //Alternative--> (Q.front == QNULL)
}

bool createNode(tPosQ* p) {
  *p = malloc(sizeof(struct tNodeQ));
  return *p!= QNULL;
}

void createEmptyQueue(tQueue* Q) {

  *Q = malloc(sizeof(tQueue)); 
  (*Q)->front =QNULL;
  (*Q)->rear=QNULL;
}

bool enqueue(tItemQ item, tQueue *Q) {
  tPosQ tmp;
  if (!createNode(&tmp)) {
    return false;
  }else {
    tmp->data=item;
    tmp->next=QNULL;
    if(isEmptyQueue(*Q)){
      (*Q)->front=tmp;
    }else {
      (*Q)->rear->next=tmp;
    }
    (*Q)->rear=tmp;
    return true;
  }
}

void dequeue(tQueue *Q) {
  tPosQ tmp;

  if (isEmptyQueue(*Q)) { // If isEmptyQueue return nothing
    return;
  }

  tmp = (*Q)->front; // Front goes backward
  (*Q)->front = (*Q)->front->next;

  if ((*Q)->front == QNULL) {
    (*Q)->rear = QNULL;
  }
  free(tmp);
}

tItemQ front(tQueue Q){ //Precondition: Queue not empty.
    return Q->front->data; 
}
