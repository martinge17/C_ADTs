#include "doubly_linked_list.h"
#include <stdlib.h>

bool isEmptyList(tList L) { return (L == NULL); }

void createEmptyList(tList *L) { *L = LNULL; }

bool createNode(tPosL *p) {
  *p = malloc(sizeof(struct tNode));
  return *p != NULL;
}

bool insertItem(tItemL d, tPosL p, tList *L) { 
  tPosL q, r; //q--> element we want to add
              //r-->element prior to q
  if (!createNode(&q)) {
    return false;
  } else {
    q->data = d;
    q->next = LNULL;
    q->prev = LNULL;   
    if (isEmptyList(*L)) { 
      *L = q;
    } else if (p == LNULL) { //If given position is NULL, add the element at the end of list
      for (r = *L; r->next != LNULL; r = r->next)
        ; //We move to the end of the list
      r->next = q;
      q->prev = r;

    } else if (p == *L) { // insert at the top of the list (first element)
      q->next = p;
      p->prev = q; 
      *L = q;

    } else { //insert in intermediate position

      q->data = p->data; // data exchange
      p->data = d;
      if (p->next != LNULL) { //in case of inserting in the last position we cannot access the "previous" field of NULL
        p->next->prev = q; 
      }
      q->next = p->next;
      p->next = q;
      q->prev = p; 
    }
    return true;
  }
}

void updateItem(tItemL d, tPosL p, tList *L) { 
  p->data = d;
}

tPosL findItem(tItemL d, tList L) { 
  tPosL p;

  for (p = L; (p != NULL) && (p->data != d); p = p->next)
    ;
  return p;
}



tItemL getItem(tPosL p, tList L) { return p->data; }



tPosL first(tList L) { 

  return L; // L always points to te first element of the list
}

tPosL last(tList L) {
  tPosL p;

  for (p = L; p->next != LNULL; p = p->next)
    ;
  return p;
}

tPosL previous(tPosL p, tList L) { 
  return p->prev;
}

tPosL next(tPosL p, tList L) { return p->next; }

void deleteAtPosition(tPosL p, tList *L) {
  tPosL q;

  if (p == *L) { // Delete first element
    *L = (*L)->next;

    if (!isEmptyList(*L)) {
      (*L)->prev = LNULL;
    }

  }else { // Middle and end deletion
    
    q = p->prev;       
    q->next = p->next; 

    if (p->next != LNULL) { 
      p->next->prev = p->prev; 
    }
  }

  free(p);
}

void deleteList(tList *L) {
  tPosL p;

  while (!isEmptyList(*L)) { 
    p = *L;
    *L = (*L)->next;
    free(p);
  }
}

bool copyList(tList L, tList *M) { 

  /*
   * p -> L iterator
   * q -> M iterator
   * r -> tmp position
   */

  tPosL p, q, r;
  bool result = true;

  createEmptyList(M);
  if (!isEmptyList(L)) {
    p = L; 
    while ((p != LNULL) &&
           (createNode(&r))) { // createNode() check if there's space enough to continue
      r->data = p->data;
      r->next = LNULL;
      r->prev = LNULL; 
      if (p == L) { //If we are copying the first element of the list
        *M = r; 
        q = r;
      } else {
        q->next = r;
        r->prev = q; 
        q = r;
      }
      p = p->next; //Advance one place in original list
    }
    if (p != LNULL) // If there's no more free space to continue
    {
      result = false;
      deleteList(M);
    }
  }
  return result;
}
