#include "dynamic_stack.h"
#include <stdlib.h>

void createEmptyStack(tStack *S) { *S = SNULL; }

bool createNode(tPosS *p) {
  *p = malloc(sizeof(struct tNodeS));
  return (*p != SNULL);
}

bool push(tItemS d, tStack *S) {
  tPosS aux;

  if (!(createNode(&aux))) {
    return false;
  } else {
    aux->data = d;
    aux->down = *S;
    *S = aux;
    return true;
  }
}

void pop(tStack *S) {
  tPosS aux;

  aux = *S;
  *S = (*S)->down;
  free(aux);
}

tItemS peek(tStack S) { return S->data; }

bool isEmptyStack(tStack S) { return (S == SNULL); }
