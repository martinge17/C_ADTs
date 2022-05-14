#include "circular_queue.h"
#include <stdbool.h>

void createEmptyQueue(tQueue *Q) {
  Q->front = 0;
  Q->rear = Q_MAX - 1;
}
int addOne(int i) {     // Advance one position.
  if (i == Q_MAX - 1) {  // If there's no more space we can "reset"
    return 0;
  } else {
    return ++i; 
  }
}

bool enqueue(tItemQ d, tQueue *Q) {
  int one_fordward = addOne(Q->rear); // Doing this we only call addOne 2 times.
  if (Q->front == addOne(one_fordward)) { //If there's no more space 
    return false;
  } else {
    Q->rear = one_fordward; 
    Q->data[Q->rear] = d;
    return true;
  }
}

void dequeue(tQueue *Q) {
  Q->front = addOne(Q->front); 
}

tItemQ front(tQueue Q) {
  return Q.data[Q.front]; 
}

bool isEmptyQueue(tQueue Q) {
  return (Q.front == addOne(Q.rear)); //Is empty when rear is right behind front
}
