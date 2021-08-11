#include <stdio.h>
#include "doubly_linked_list.h"

//EXER 1: Print double list in reverse order.



void insertion(tList *List){

    tPosL p = LNULL;

    insertItem(1,p,List);
    insertItem(2, p, List);
    insertItem(3, p, List);
    insertItem(4, p, List);
}

void printElement(tItemL element){
    printf(" %d ",element);
}

void reverse_printList(tList List){
    tPosL tmp;
    if (List!=LNULL) {
        //Goto last element
        for (tmp=List;tmp->next!=LNULL;tmp=tmp->next);
        while (tmp!=LNULL) {
            printElement(tmp->data);
            tmp=tmp->prev;
        }   
    }
}

void printList(tList List){
    tPosL tmp;
    if (List!=LNULL) {
        //Goto last element
        for (tmp=List;tmp!=LNULL;tmp=tmp->next){
            printElement(tmp->data);
        }   
    }
}

int main(){

    tList List; 
    createEmptyList(&List);

    insertion(&List);
    printList(List);
    printf("\n\n");
    reverse_printList(List);

    return 0;
}
