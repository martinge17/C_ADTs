#include <stdbool.h>
#include "linked_list.h"

#define QNULL LNULL

typedef tList tQueue;
typedef tItemL tItemQ;
typedef tPosL front_pos;
typedef tPosL rear_pos;

void createEmptyQueue(tQueue *Q);
bool enqueue(tItemQ d, tQueue *Q);
void dequeue(tQueue *Q);
tItemQ front(tQueue Q);
bool isEmptyQueue(tQueue Q);