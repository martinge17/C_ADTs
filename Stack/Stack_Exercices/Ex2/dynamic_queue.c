#include "dynamic_queue.h"
#include <stdlib.h>

bool isEmptyQueue(tQueue Q) { return (Q.front == QNULL); }


void createEmptyQueue(tQueue *Q) {
  Q->front =   //We don't use (*Q)->front because tQueue is a struct, not a pointer
      QNULL; 
  Q->rear = QNULL;
}

bool createNode(tPosQ *p) {
  *p = malloc(sizeof(struct tNodeQ));
  return *p != QNULL;
}

bool enqueue(tItemQ d, tQueue *Q) {
  tPosQ p;

  if (!createNode(&p)) {
    return false;
  } else { 
    p->item = d;
    p->next = QNULL;

    if (isEmptyQueue(*Q)) { 
      Q->front = p;

    } else {
      Q->rear->next = p;
    }

    Q->rear = p;

    return true;
  }
}

void dequeue(tQueue *Q) {
  tPosQ p;

  if (isEmptyQueue(*Q)) { // If isEmptyQueue return nothing
    return;
  }

  p = Q->front;
  Q->front = p->next; 

  if (isEmptyQueue(*Q)) {
    Q->rear = QNULL;
  }

  free(p);
}

tItemQ front(tQueue Q) { return Q.front->item; }

