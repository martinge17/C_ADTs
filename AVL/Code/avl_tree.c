#include "avl_tree.h"
#include <stdio.h>
#include <stdlib.h>

void CreateEmptyBST(tBST *tree) { *tree = NULLBST; }

bool isEmptyTree(tBST tree){ //DONE
    return (tree == NULLBST);
}

tBST LeftChild(tBST tree) { return tree->left; } 

tBST RightChild(tBST tree) { return tree->right; } 

int max(int a, int b){ //Returns the maximum of two integers 
	if (a>=b) {
		return a;
	}else {
		return b;
	}
}

int height(tBST tree){ //Returns tree height 

	if (isEmptyTree(tree)) {
		return 0;
	}else {
		return tree->height;
	}
}


int getBalance(tBST tree){ 
    
    if (isEmptyTree(tree)){ return 0;}
    return (height(tree->left)-height(tree->right));

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

//Rotations 


void rr_rotation(tBST *tree){ //left rotate 
    if (isEmptyTree(*tree)) { return;}
    
    printf("rr_rotating\n");


    tBST aux1 = (*tree)->right; 

    (*tree)->right=aux1->left;
    aux1->left=*tree;

    //Height update
    (*tree)->height=max(height((*tree)->left),height((*tree)->right)) + 1;
    aux1->height=max(height(aux1->left),height(aux1->right)) + 1;  

    *tree=aux1;
}

void ll_rotation(tBST *tree){ //right rotate 
    if (isEmptyTree(*tree)) { return;}

    printf("ll_rotating\n");


    tBST aux1 = (*tree)->left; 

    (*tree)->left=aux1->right;
    aux1->right=*tree;

     //Height update
     (*tree)->height=max(height((*tree)->left),height((*tree)->right)) + 1; 
     aux1->height=max(height(aux1->left),height(aux1->right)) + 1;  

    *tree=aux1;
}

void rl_rotation(tBST *tree){ 
    if (isEmptyTree(*tree)) { return;}

    ll_rotation(&(*tree)->right);
    rr_rotation(tree);
}

void lr_rotation(tBST *tree){ 
    if (isEmptyTree(*tree)) { return;}


    rr_rotation(&(*tree)->left);
    ll_rotation(tree);

}

bool createBSTNode (tBSTPos* p,tKey key){  

    *p = malloc(sizeof(struct tBSTNode));

    if(*p != NULLBST){ 
        (*p)->key = key;
        (*p)->left = NULLBST;
        (*p)->right = NULLBST;
        (*p)->height=1; 
    }
    return *p!=NULLBST;
}


bool insertKey(tBST* tree, tKey key)  
{
    bool check = false;
    bool check_createNode= false;

    if (isEmptyTree(*tree)){
        check_createNode = createBSTNode(tree, key);
        printf("NK:%d H:%d B:0 \n",(*tree)->key,(*tree)->height);
        return check_createNode;
    }
    else if (key == (*tree)->key)
        return true;
    else if (key < (*tree)->key)
         check = insertKey(&(*tree)->left, key);
    else // (key > (*tree)->key)
         check = insertKey(&(*tree)->right, key);


    if(check){


        (*tree)->height=max(height((*tree)->left),height((*tree)->right)) + 1; //Height Update

        //Check balance factor of initial node

        int balance = getBalance(*tree);

        printf("NK:%d H:%d B:%d \n",(*tree)->key,(*tree)->height,balance);


        if(balance>1){  //Left-?
            if(key<(*tree)->left->key){ //Left-Left
                ll_rotation(tree);
            }else{ //Left-Right
                lr_rotation(tree);
            }
        }

        if(balance<-1){ //Right-?
            if(key>(*tree)->right->key){ //Right-Right
                rr_rotation(tree);
            }else{ //Right-Left
                rl_rotation(tree);
            }
        }

    }
    
    return check;
      
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
          printf("Removing: %d\n",key);                  
          aux = *tree;
          if (isEmptyTree((*tree)->right))
          {                          //If it has no right child, replace by left one
              *tree = (*tree)->left; //this covers the no-child case
          }
          else if (isEmptyTree((*tree)->left))
          { //If it has no left child, replace by right one.
              *tree = (*tree)->right;
        
          }else {     
                                       //If it has two children we call replace() passing 
                                      //its left subtree as first argument
            replace(&(*tree)->left,&aux);                       
           }
          free(aux);
          aux=NULLBST;

    }

    if(isEmptyTree(*tree)) {return;}

    //Update Balance Factor and Height 
   (*tree)->height=max(height((*tree)->left),height((*tree)->right)) + 1; //Height Update

    int balance = getBalance(*tree);

    while((balance>1)||(balance<-1)){
        
        if(balance>1){  //Left-?
            if(getBalance((*tree)->left)>=0){ //Left-Left
                ll_rotation(tree);
            }else{ //Left-Right
                lr_rotation(tree);
            }
        }

        if(balance<-1){ //Right-?
            if(getBalance((*tree)->right)>0){ //Right-Left
                rl_rotation(tree);
            }else{ //Right-Right
                rr_rotation(tree);
            }
        }
        balance = getBalance(*tree);

    }

}