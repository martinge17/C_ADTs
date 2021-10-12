#include <stdio.h>
#include "linked_list.h"
//#include "static_list.h"

//Introduce a few elements

void introduce(tList *L){

    insertItem(1,LNULL,L);
    insertItem(2,LNULL,L);
    insertItem(3,LNULL,L);
}

//Print List 

void printList(tList L){
    tPosL p;
    printf("(");
    if (!isEmptyList(L))
    {
        p=first(L);
        while (p!=LNULL) {
        
        printf(" %d ",getItem(p,L));
        p=next(p,L);

        }

    }
     printf(")");

}

//Reverse Print List

void reverse_print(tList L){

    tPosL p;

    printf("(");
    if (!isEmptyList(L))
    {
        
        p=last(L);
        while (p!=LNULL) {
        
        printf(" %d ",getItem(p,L));
        p=previous(p,L);

        }

    }
     printf(")");

}

int main(){
    //Initialization
    tList L;
    tList H;
    createEmptyList(&L);
    introduce(&L);
    printList(L);
   // copyList(L,&H);
    //printList(H);
	printf("\n\n\n");
	reverse_print(L);
    printf("\n");


    return 0;
}