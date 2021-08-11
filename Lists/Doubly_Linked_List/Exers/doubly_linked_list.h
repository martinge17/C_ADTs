#include <stdbool.h>

/* Types definition */

#define LNULL NULL

typedef int tItemL;

typedef struct tNode* tPosL;  //Ptr to tNode
                              
struct tNode {

   tItemL data;
   tPosL next;
   tPosL prev; 
   
};

typedef tPosL tList;

//Prototypes

void createEmptyList(tList *L);
bool createNode(tPosL* p);
bool insertItem(tItemL d, tPosL p, tList *L);
void updateItem(tItemL d, tPosL p, tList* L);
tPosL findItem(tItemL d,tList L);
bool isEmptyList(tList L);
tItemL getItem(tPosL p, tList L);
tPosL first(tList L);
tPosL last(tList L);
tPosL previous(tPosL p, tList L);
tPosL next(tPosL p,tList L);
void deleteAtPosition(tPosL p , tList *L);
void deleteList(tList *L);



