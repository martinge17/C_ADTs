#include <stdbool.h>
#include "dynamic_queue.h"

/* Types definition */

#define LNULL NULL
#define MAXPRIO 5 //Max priority level

typedef int tPriority; 

typedef struct tItemL {
   tPriority prio;
   tQueue queue;
} tItemL;

typedef struct tNodeL* tPosL;  //Ptr to tNode
                              
struct tNodeL {
   tItemL data;
   tPosL next;
};

typedef tPosL tOrderedList;

/* Function prototypes */

void createEmptyList(tOrderedList *L);
bool insertItem(tPriority prio,tOrderedList *L); 
tPosL findPosition(tOrderedList L, tItemL d);
void updateItem(tOrderedList* L,tPosL p,tQueue queue);
tPosL findItem(tPriority prio,tOrderedList L);
bool isEmptyList(tOrderedList L);
void getItem(tPosL p, tOrderedList L,tPriority *prio,tQueue *queue);
tPosL first(tOrderedList L);
tPosL last(tOrderedList L);
tPosL previous(tPosL p, tOrderedList L);
tPosL next(tPosL p,tOrderedList L);
void deleteAtPosition(tPosL p , tOrderedList *L);
void deleteList(tOrderedList *L);



