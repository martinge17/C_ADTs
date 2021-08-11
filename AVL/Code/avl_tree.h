#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NULLBST NULL

typedef int tKey;


typedef struct tBSTNode *tBSTPos;

struct tBSTNode {
    tKey key;
    int  height; 
    tBSTPos right;
    tBSTPos left;
};

typedef tBSTPos tBST;

void CreateEmptyBST(tBST *tree);
bool isEmptyTree (tBST tree);
bool createBSTNode (tBSTPos* p,tKey key);
bool insertKey(tBST* tree, tKey key);
tBST findKey(tBST tree, tKey key);
void replace (tBST* subTree,tBST* auxTree);
void removeKey(tBST* tree,tKey key);