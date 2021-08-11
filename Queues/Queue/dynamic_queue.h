#include <stdbool.h>

/* Types definition */
#define QNULL NULL

typedef int tItemQ;

typedef struct tNodeQ *tPosQ;

struct tNodeQ{
    tItemQ item;
    tPosQ next;
};

typedef struct Queue{
    tPosQ front;
    tPosQ rear;

} tQueue;

/* Function prototypes */

void createEmptyQueue(tQueue *Q);
bool enqueue(tItemQ d, tQueue *Q);
void dequeue(tQueue *Q);
tItemQ front(tQueue Q);
bool isEmptyQueue(tQueue Q);

