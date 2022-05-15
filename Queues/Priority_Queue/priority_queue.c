#include "priority_queue.h"


bool isEmptyQueueP(tQueueP queueP){
  return (queueP==LNULL);
}

void createEmptyQueueP(tQueueP *queueP){
  *queueP=LNULL;
}

bool enqueueP(tItemQ item, tPriority prio, tQueueP *queueP) {
  /*PreCondition: There's memory enough for the operation */

  tPosL pos;
  tQueue Q;

  //There is such a priority?
  pos = findItem(prio, *queueP);

  if (pos == LNULL) {
    // Doesn't exist?--> Add it
    if (!insertItem(prio, queueP)) {
      return false;
    }
    pos = findItem(prio, *queueP);
  }

  //Extract the queue to add the element

  getItem(pos, *queueP, &prio, &Q);

  // Update the queue
  if (!enqueue(item, &Q)) {
    return false;
  }
  //Update the list
  updateItem(queueP, pos, Q);
  return true;
}

void dequeueP(tQueueP *queueP) {
  /* Precondition: priority queue is not empty */

  tPosL posL;
  tItemL itemL;
  tQueue queue;
  tPriority priority;

  //Extract the queue
  posL = first(*queueP);
  getItem(posL, *queueP, &priority, &queue);
  dequeue(&queue);
  //If the queue remains empty, delete the entire node.
  if (isEmptyQueue(queue)) {
    deleteAtPosition(posL, queueP);
  } else {
    updateItem(queueP, posL, queue);
  }
}

tItemQ frontP(tQueueP queueP){ //Precondition: QueueP not empty
  tPosL first_pos;
  tQueue queue;
  tPriority node_prio;


  first_pos=first(queueP);
  getItem(first_pos, queueP, &node_prio, &queue);
  return queue.front->item;

}
