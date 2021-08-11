#include "tree_dynamic.h"
#include <stdio.h>
#include <stdlib.h>


//******************************************
//Recursive traversal
//******************************************

//Pre-Order (root left right)

void preorder_traversal(tBinTree T){
    if (T!=TNULL) {
        printf(" %d ",T->data);
        preorder_traversal(T->left);
        preorder_traversal(T->right);
    }
}

//In-Order (left root right)

void inorden_traversal(tBinTree T){
    if (T!=TNULL) {
        inorden_traversal(T->left);
        printf(" %d ",T->data);
        inorden_traversal(T->right);
    }
}

//Post-Order (left right root)

void post_order_traversal(tBinTree T){
     if (T!=TNULL) {
        post_order_traversal(T->left);
        post_order_traversal(T->right);
        printf(" %d ",T->data);
    }
}

