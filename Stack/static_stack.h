#include <stdbool.h>

/* Types definition */

#define SNULL -1
#define SMAX 10

typedef int tItemS;
typedef int tPosS;

typedef struct Stack {
  tItemS data[SMAX];
  tPosS top;
} tStack;

/* Function prototypes */

void createEmptyStack(tStack *S);
bool push(tItemS d, tStack *S);
void pop(tStack *S);
tItemS peek(tStack S);
bool isEmptyStack(tStack S);

