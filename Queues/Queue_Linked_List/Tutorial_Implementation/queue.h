#include <stdbool.h>
#define QNULL NULL

typedef int tItemQ;

typedef struct tNodeQ* tPosQ;

struct tNodeQ{
    tItemQ data;
    tPosQ next;
};

typedef struct tNodeQueue* tQueue;

struct tNodeQueue{
    tPosQ front;
    tPosQ rear;
};


void createEmptyQueue(tQueue* Q);
bool enqueue(tItemQ item,tQueue *Q);
void dequeue(tQueue *Q);
tItemQ front(tQueue Q);
bool isEmptyQueue(tQueue Q);

