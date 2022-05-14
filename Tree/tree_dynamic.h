#include <stdbool.h>
#include <stdio.h>



#define TNULL NULL

typedef int tItemT;

typedef struct tNodeT *tPosT;

struct tNodeT {
  tItemT data;
  tPosT right;
  tPosT left;
};
typedef tPosT tBinTree;


void CreateEmptyTree(tBinTree *T);
bool BuildTree(tBinTree LTree, tItemT d, tBinTree Rtree, tBinTree *T);
tBinTree LeftChild(tBinTree T);
tBinTree RightChild(tBinTree T);
tItemT Root(tBinTree T);
bool IsEmptyTree(tBinTree T);
void deleteTree(tBinTree *T);


