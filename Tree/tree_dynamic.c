#include "tree_dynamic.h"
#include <stdlib.h>

void CreateEmptyTree(tBinTree *T) { *T = TNULL; }

bool createNode(tPosT *p) {
  *p = malloc(sizeof(struct tNodeT));
  return *p != TNULL;
}

bool BuildTree(tBinTree LTree, tItemT d, tBinTree Rtree, tBinTree *T) {
  if (createNode(T)) {
    (*T)->data = d;
    (*T)->left = LTree;
    (*T)->right = Rtree;
    return true;

  } else {
    return false;
  }
}

void deleteTree(tBinTree *T){

    if (!IsEmptyTree(*T)) {

      deleteTree(&(*T)->left);
      deleteTree(&(*T)->right);

      free(*T);
      *T = TNULL;
    }


}



tBinTree LeftChild(tBinTree T) { return T->left; }

tBinTree RightChild(tBinTree T) { return T->right; }

tItemT Root(tBinTree T) { return T->data; }

bool IsEmptyTree(tBinTree T) { return (T == TNULL); }
