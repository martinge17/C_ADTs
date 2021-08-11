#include "ordered_list.h"
#include <stdio.h>


#define LNULL NULL

typedef tOrderedList tQueueP;

void createEmptyQueueP(tQueueP *queueP);
bool enqueueP(tItemQ item,tPriority prio, tQueueP *queueP);
void dequeueP(tQueueP *queueP);
bool isEmptyQueueP(tQueueP queueP);
tItemQ frontP(tQueueP queueP);