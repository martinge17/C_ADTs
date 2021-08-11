#include <stdio.h>
#include "queue.h"

void createEmptyQueue(tQueue *Q) {
createEmptyList(Q);
}
bool enqueue(tItemQ d, tQueue *Q) {
return insertItem(d, QNULL, Q); //Always insert at the end
}
bool isEmptyQueue(tQueue Q) {
return isEmptyList(Q);
}

tItemQ front(tQueue Q) {
return getItem(first(Q), Q);
}
void dequeue(tQueue *Q) {
deleteAtPosition(first(*Q), Q); //Always delete from the front
}
