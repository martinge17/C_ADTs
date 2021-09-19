#include <stdio.h>
#include "avl_tree.h"



void preorder_traversal(tBST tree){
    if (tree!=NULLBST) {
        printf(" %d ",tree->key);
        preorder_traversal(tree->left);
        preorder_traversal(tree->right);
    }
}


int main(){

    tBST tree;

    CreateEmptyBST(&tree);
    insertKey(&tree,65);
    insertKey(&tree,43);
    insertKey(&tree,70);
    insertKey(&tree,25);
    insertKey(&tree,58);
    insertKey(&tree,67);
    insertKey(&tree,75);
    insertKey(&tree,10);
    insertKey(&tree,47);
    insertKey(&tree,62);
    insertKey(&tree,66);
    insertKey(&tree,69);
    insertKey(&tree,73);
    insertKey(&tree,86);
    insertKey(&tree,60);
    insertKey(&tree,68);
    insertKey(&tree,93);

    /*
    insertKey(&tree,20);
    insertKey(&tree,30);
    insertKey(&tree,15);
*/
    if(isEmptyTree(tree)){printf("VACIO");};


    preorder_traversal(tree);

    printf("\n");

    removeKey(&tree,25);
    removeKey(&tree,75);
    removeKey(&tree,66);
    removeKey(&tree,65);
    removeKey(&tree,62);
    removeKey(&tree,10);
    removeKey(&tree,43);
    removeKey(&tree,47);


    printf("\n");

   // if(isEmptyTree(tree)){printf("VACIO\n");};

    preorder_traversal(tree);

    printf("\n");
/*
    insertKey(&tree,2);
    printf("\n\n");
    preorder_traversal(tree);
  */  

    

    return 0;
}