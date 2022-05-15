#include "tree_dynamic.h"
#include <stdlib.h>

int countNodes(tBinTree T)
{

	if (IsEmptyTree(T))
	{
		return 0;
	}

	return 1 + countNodes(LeftChild(T)) + countNodes(RightChild(T));
}

int countL(tBinTree T)
{ // Leaf counter
	if (IsEmptyTree(T))
	{
		return 0;
	}
	else if ((IsEmptyTree(LeftChild(T))) && (IsEmptyTree(RightChild(T))))
	{
		return 1;
	}
	else
	{
		return ((countL(LeftChild(T))) + countL(RightChild(T)));
	}
}

int comp(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int height(tBinTree T)
{ // Max tree height

	if (IsEmptyTree(T))
	{
		return 0;
	}
	else
	{
		return 1 + comp(height(LeftChild(T)), height(RightChild(T)));
	}
}

/* Check if tree is a "proper" tree (full tree)

	- Every parent node/internal node has either two or no children.
	- Leafs only at last level

*/

bool EsLleno_AUX(tBinTree T, int level, int height)
{

	// Check if tree is empty
	if (IsEmptyTree(T))
	{
		return false;
	}

	// Leaf --> last level?
	if (IsEmptyTree(T->left) && IsEmptyTree(T->right))
	{

		return (level == height);
	}

	// Two childs --> Keep checking
	if (!IsEmptyTree(T->left) && !IsEmptyTree(T->right))
	{

		return (EsLleno_AUX(T->left, level + 1, height) && EsLleno_AUX(T->right, level + 1, height));
	}

	// One child only
	return false;
}

bool EsLleno(tBinTree T)
{

	return EsLleno_AUX(T, 1, height(T));
}

void deleteTroo(tBinTree *T){

    if (!IsEmptyTree(*T)) {

      deleteTroo(&(*T)->left);
      deleteTroo(&(*T)->right);

      /* At last, delete root node */
      printf("Deleteing Node : %d\n", (*T)->data);
      free(*T);
	  *T = TNULL;
    }

}

/*  >------------------------------------------------------ TEST ------------------------------------------------------< */

/*     Original Tree
 *          100
 *     24         42
 *  1      1   2      32
 */

int main()
{

	tBinTree main_tree;
	CreateEmptyTree(&main_tree);
	tBinTree tree_2;
	CreateEmptyTree(&tree_2);
	tBinTree tree_3;
	CreateEmptyTree(&tree_3);
	tBinTree tree_4;
	CreateEmptyTree(&tree_4);
	tBinTree tree_5;
	CreateEmptyTree(&tree_5);
	tBinTree tree_6;
	CreateEmptyTree(&tree_6);
	tBinTree tree_7;
	CreateEmptyTree(&tree_7);

	BuildTree(TNULL, 2, TNULL, &tree_6);
	BuildTree(TNULL, 32, TNULL, &tree_7);

	BuildTree(tree_6, 42, tree_7, &tree_3);

	BuildTree(TNULL, 1, TNULL, &tree_4);
	BuildTree(TNULL, 1, TNULL, &tree_5);

	BuildTree(tree_4, 24, tree_5, &tree_2);

	BuildTree(tree_2, 100, tree_3, &main_tree);

	// Test Node Counter
	printf("Num of Nodes: %d\n", countNodes(main_tree));

	// Test Leaf
	printf("Num of Leafs: %d\n", countL(main_tree));

	// Test Height
	printf("Height: %d\n", height(main_tree));

	// Check full tree
	if (EsLleno(main_tree))
	{
		printf("Full Tree!\n");
	}
	else
	{
		printf("No Full Tree!\n");
	}

	deleteTroo(&main_tree);


	// Test Node Counter
	printf("Num of Nodes: %d\n", countNodes(main_tree));

	// Test Leaf
	printf("Num of Leafs: %d\n", countL(main_tree));

	// Test Height
	printf("Height: %d\n", height(main_tree));

	return 0;
}
