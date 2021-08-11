#include <stdio.h>
#include "linked_ordered_list.h"
//#include "static_ordered_list.h"

//Introduce a few elements

void introduce(tList *L){
    insertItem(2,L);
    insertItem(1,L);
    insertItem(3,L);
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
    createEmptyList(&L);

    introduce(&L);
    printList(L);
	printf("\n\n\n");
	reverse_print(L);

    return 0;
}
