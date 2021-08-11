#include <stdbool.h>

#define QNULL NULL

typedef int tItemQ;

typedef struct tNode *tPosQ; // Ptr to tNode
                             
struct tNode {

  tItemQ data;
  tPosQ next;
};

typedef tPosQ tQueue;

void createEmptyQueue(tQueue *Q);
bool enqueue(tItemQ data, tQueue *Q);
void dequeue(tQueue *Q);
tItemQ front(tQueue Q);
bool isEmptyQueue(tQueue Q);