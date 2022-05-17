#include "static_ordered_list.h"
#include <stdbool.h>

bool isEmptyList(tList L) { return L.lastPos == LNULL; }

void createEmptyList(tList *L) { L->lastPos = LNULL; }

bool insertItem(tItemL d, tList *L) {
  tPosL i;

  if (L->lastPos == MAX - 1) //Check if list is full
    return false;
  else {
    if (isEmptyList(*L) || d > L->data[L->lastPos]) { // Insert at the end
      L->lastPos++;
      L->data[L->lastPos] = d;
    } else {
      L->lastPos++;
      for (i = L->lastPos; (i > 0) && (d < L->data[i - 1]); i--) {
        L->data[i] = L->data[i - 1]; //moves the elements one position forwar
      }
      L->data[i] = d; //Finally insert element in right position
    }
    return true;
  }
}

bool copyList(tList L, tList *M) {
  tPosL p;

  createEmptyList(M); //First initialize the destination list

  for (p = 0; p <= L.lastPos; p++)
    M->data[p] = L.data[p];
  M->lastPos = L.lastPos;
  return true;
}

void updateItem(tItemL d, tPosL p, tList *L) { L->data[p] = d; }

tPosL findItem(tItemL d, tList L) {
  tPosL p;

  if (isEmptyList(L)){ 
    return LNULL;
  }else if ((d < L.data[0]) || (d > L.data[L.lastPos])) { //If the item is not in the list 
    return LNULL;
  } else {
    for (p = 0; (p < L.lastPos) && (L.data[p] < d); p++)
      ;
    if (L.data[p] == d) {
      return p;
    } else {
      return LNULL;
    }
  }
}


tItemL getItem(tPosL p, tList L) { return L.data[p]; }

tPosL first(tList L) {
  return 0;
}

tPosL last(tList L) { return L.lastPos; }

tPosL previous(tPosL p, tList L) { return --p; }

tPosL next(tPosL p, tList L) {
  if (p == L.lastPos)
    return LNULL;
  else
    return ++p;
}


void deleteAtPosition(tPosL p, tList *L) {
  tPosL i;

  L->lastPos--; 
  for (i = p; i <= L->lastPos; i++) //Move the elements back one position
    L->data[i] = L->data[i + 1];
}

void deleteList(tList *L) {
  L->lastPos = LNULL;
}
