#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NULLBST NULL

typedef int tKey;

typedef struct tBSTNode *tBSTPos;

struct tBSTNode {
    tKey key;
    tBSTPos right;
    tBSTPos left;
};

typedef tBSTPos tBST;


bool isEmptyTree (tBST tree);
void createEmptyTree(tBST* tree);
bool insertKey(tBST* tree, tKey key);
tBST findKey(tBST tree, tKey key);
void replace (tBST* subTree,tBST* auxTree);
void removeKey(tBST* tree,tKey key);
tBST LeftChild(tBST tree);
tBST RightChild(tBST tree);
tKey Root(tBST tree);

