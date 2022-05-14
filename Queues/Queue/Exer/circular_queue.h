#include <stdbool.h>

/* Types definition */

#define Q_MAX 10
typedef int  tItemQ;

typedef struct Queue{
    tItemQ data[Q_MAX];
    int front, rear;
} tQueue;

/* Function prototypes */

void createEmptyQueue(tQueue *Q);
bool enqueue(tItemQ d, tQueue *Q);
void dequeue(tQueue *Q);
tItemQ front(tQueue Q);
bool isEmptyQueue(tQueue Q);


