#include "ordered_list.h"
#include <stdbool.h>
#include <stdlib.h>


/*
 * Order Explanation:
 *    1 -> Inmediate
 *    2 -> Very Urgent
 *    3 -> Urgent
 *    4 -> Standard
 *    5 -> Non-Urgent
 */


bool isEmptyList(tOrderedList L) { return (L == LNULL); }

void createEmptyList(tOrderedList *L) { *L = LNULL; }

bool createNodeL(tPosL *p) {
  *p = malloc(sizeof(struct tNodeL));
  return *p != LNULL;
}

tPosL findPosition(tOrderedList L, tItemL d) { 

  tPosL p,tmp;

  p = L;
  tmp = L;
  while ((p != LNULL) &&
         (p->data.prio < d.prio)) {  //Continue while data is ordered
      tmp = p;
      p = p->next;
  }
  return tmp;
}

bool insertItem(tPriority prio, tOrderedList *L) {
  tPosL q, p;

  if (!createNodeL(&q) || prio > MAXPRIO)
  {
    return false;
  } else {

    q->data.prio = prio;
    createEmptyQueue(&q->data.queue); //Attention! Queue must be initialized
    q->next = LNULL;

    if (isEmptyList(*L))
    {
      *L = q;          

    }
    else if (prio < (*L)->data.prio)
    { // insert at the top of the list (first element)

      q->next = *L;
      *L = q;
    }
    else
    { //Find right position
      p = findPosition(*L, q->data);
      q->next = p->next;
      p->next = q;
    }
    return true;
  }
}

void updateItem(tOrderedList *L, tPosL p, tQueue queue) { 
  p->data.queue = queue;
}

tPosL findItem(tPriority prio, tOrderedList L) { 
  tPosL p;

  for (p = L; (p != LNULL) && (p->data.prio < prio); p = p->next)
    ; 

  return p;
}


void getItem(tPosL p, tOrderedList L, tPriority *prio, tQueue *queue) {

  *prio = p->data.prio;
  *queue = p->data.queue;
}



tPosL first(tOrderedList L) { 

  return L; // L always points to te first element of the list
}

tPosL last(tOrderedList L) {

  tPosL p;

  for (p = L; p->next != LNULL; p = p->next)
    ;
  return p;
}

tPosL previous(tPosL p, tOrderedList L) {
  tPosL q;

  if (p == L) {
    return LNULL;
  } else {
    for (q = L; q->next != p; q = q->next)
      ;
    return q;
  }
}

tPosL next(tPosL p, tOrderedList L) { return p->next; }

void deleteAtPosition(tPosL p, tOrderedList *L) {
  tPosL q;

  if (p == *L)
  { // Delete first element
    *L = (*L)->next;
  }
  else if (p->next == LNULL)
  { //Delete last element
    for (q = *L; q->next->next != p; q = q->next)
      ;
    q->next = LNULL;

  }
  else { //Middle deletion Overwrite p with q
     //p--> element we want to delete
    //q-->next element

    q = p->next;
    p->data = q->data;
    p->next = q->next;
    p = q;
  }

  free(p);
}

void deleteList(tOrderedList *L) {
  tPosL p;

  while (!isEmptyList(*L)) { 
    p = *L;
    *L = (*L)->next;
    free(p);
  }
}
