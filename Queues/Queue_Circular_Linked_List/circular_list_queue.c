#include "circular_list_queue.h"
#include <stdlib.h>

void createEmptyQueue(tQueue *Q) { *Q = QNULL; }

bool isEmptyQueue(tQueue Q) { return (Q == QNULL); }

bool createNode(tPosQ *p) {
  *p = malloc(sizeof(struct tNode));
  return *p != QNULL;
}

bool enqueue(tItemQ data, tQueue *Q) {
  tPosQ new;

  if (!createNode(&new)) {
    return false;
  } else {
    new->data = data;
    new->next = QNULL;

    if (isEmptyQueue(*Q)) { //if the queue is empty the node to be inserted points to itself
      new->next = new;
    } else {
      new->next = (*Q)->next; //1st --> new element points to front 
      (*Q)->next = new;       //2nd --> last element points to new
    }

    *Q = new; // 3rd -->  new element become last element

    return true;
  }
}

void dequeue(tQueue *Q) {
  tPosQ del;

  if ((*Q)->next == *Q) { // If there's only one element 
    del = *Q;
    *Q = QNULL;
  } else { 
    del = (*Q)->next;
    (*Q)->next = del->next;

  }

  free(del);

}

tItemQ front(tQueue Q) { return Q->next->data; }
