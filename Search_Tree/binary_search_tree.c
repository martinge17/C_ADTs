#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>


bool isEmptyTree (tBST tree){
    return (tree == NULLBST);
}

void createEmptyTree(tBST* tree){
    *tree=NULLBST;
}


tBST findKey(tBST tree, tKey key){

    if (isEmptyTree(tree))
        return NULLBST;
    else if (key == tree->key)
        return tree;
    else if (key < tree->key)
        return findKey(tree->left, key);
    else // (key > tree->key)
        return findKey(tree->right, key);     

}

bool createBSTNode(tBSTPos* p,tKey key){

    *p = malloc(sizeof(struct tBSTNode));

    if(*p != NULLBST){ 
        (*p)->key = key;
        (*p)->left = NULLBST;
        (*p)->right = NULLBST;
    }
    return *p!=NULLBST;
}

bool insertKey(tBST* tree, tKey key)
{
    if (isEmptyTree(*tree))
        return createBSTNode(tree, key);
    else if (key == (*tree)->key)
        return true;
    else if (key < (*tree)->key)
        return insertKey(&(*tree)->left, key);
    else // (key > (*tree)->key)
        return insertKey(&(*tree)->right, key);
}


void replace (tBST* subTree,tBST* auxTree){  //Replace the content of a node by its predecessors
    if (!isEmptyTree((*subTree)->right)) { 
        replace(&(*subTree)->right,auxTree); //Going down the right branch
    }else {
        (*auxTree)->key = (*subTree)->key; //We replace the data fields of the node
        *auxTree = *subTree;               //We mark the node on which we will call free()
        (*subTree) = (*subTree)->left;     //We re-link the tree structure by "skyping"
                                           //the node to be deleted
    }
}

void removeKey(tBST* tree,tKey key){

    tBST aux;
    if (key < (*tree)->key) {
        removeKey(&(*tree)->left, key);    //If the key is smaller, continue through left subtree    
    }else if (key > (*tree)->key) {
        removeKey(&(*tree)->right, key);    //If the key is larger, continue through right subtree   
    }else {  // key == (*tree)->key         //Once we locate the key, we proceed to its deletion
        aux = *tree;                       
        if (isEmptyTree((*tree)->right)) {  //If it has no right child, replace by left one
            *tree = (*tree)->left;          //this covers the no-child case
        }else if (isEmptyTree((*tree)->left)) { //If it has no left child, replace by right one.
            *tree = (*tree)->right;
        }else {                               //If it has two children we call replace() passing 
                                             //its left subtree as first argument
            replace(&(*tree)->left,&aux);              
        }
        free(aux); 
    }

}

tBST LeftChild(tBST tree){
    return tree->left;
}
tBST RightChild(tBST tree){
    return tree->right;
}
tKey Root(tBST tree){
    return tree->key;
}
