#include "linked_ordered_list.h"
#include <stdbool.h>
#include <stdlib.h>

bool isEmptyList(tList L) { return (L == LNULL); }

void createEmptyList(tList *L) { *L = LNULL; }

bool createNode(tPosL *p)
{
  *p = malloc(sizeof(struct tNode));
  return *p != LNULL;
}

tPosL findPosition(tList L, tItemL d)
{

  tPosL p, tmp;

  p = L;
  tmp = L;
  while ((p != LNULL) &&
         (p->data < d))
  { //Continue while data is ordered
    tmp = p;
    p = p->next;
  }
  return tmp;
}

bool insertItem(tItemL d, tList *L)
{
  tPosL q, p;

  if (!createNode(&q))
  {
    return false;
  }
  else
  {
    q->data = d;
    q->next = LNULL;

    if (isEmptyList(*L))
    {
      *L = q;
    }
    else if (d < (*L)->data)
    { // insert at the top of the list (first element)

      q->next = *L;
      *L = q;
    }
    else
    { //Find right position
      p = findPosition(*L, d);
      q->next = p->next;
      p->next = q;
    }
    return true;
  }
}

void updateItem(tItemL d, tPosL p, tList *L)
{
  p->data = d;
}

tPosL findItem(tItemL d, tList L)
{
  tPosL p;

  for (p = L; (p != LNULL) && (p->data < d); p = p->next)
    ;

  return p;
}

tItemL getItem(tPosL p, tList L) { return p->data; }

tPosL first(tList L)
{

  return L; // L always points to te first element of the list
}

tPosL last(tList L)
{

  tPosL p;

  for (p = L; p->next != LNULL; p = p->next)
    ;
  return p;
}

tPosL previous(tPosL p, tList L)
{
  tPosL q;

  if (p == L)
  {
    return LNULL;
  }
  else
  {
    for (q = L; q->next != p; q = q->next)
      ;
    return q;
  }
}

tPosL next(tPosL p, tList L) { return p->next; }

void deleteAtPosition(tPosL p, tList *L)
{
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
  else
  { //Middle deletion Overwrite p with q
    //p--> element we want to delete
    //q-->next element
    q = p->next;
    p->data = q->data;
    p->next = q->next;
    p = q;
  }

  free(p);
}

void deleteList(tList *L)
{
  tPosL p;

  while (!isEmptyList(*L))
  {
    p = *L;
    *L = (*L)->next;
    free(p);
  }
}

bool copyList(tList L, tList *M)
{

  tPosL p, q, r;
  bool result = true;

  createEmptyList(M);
  if (!isEmptyList(L))
  {
    p = L; //Point p to the top of the list
    while ((p != LNULL) &&
           (createNode(&r)))
    { // createNode() check if there's space enough to continue
      r->data = p->data;
      r->next = LNULL;
      if (p == L) //If we are copying the first element of the list
      {
        *M = r;
        q = r;
      }
      else
      {
        q->next = r;
        q = r;
      }
      p = p->next; //Advance one place in original list
    }
    if (p != LNULL) // In case there's not enough space availible
    {
      result = false;
      deleteList(M);
    }
  }
  return result;
}
