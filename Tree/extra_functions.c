#include "tree_dynamic.h"


int countNodes(tBinTree T){

	if(IsEmptyTree(T)){
		return 0;
	}

	return 1 + countNodes(LeftChild(T)) + countNodes(RightChild(T));

}


int countL(tBinTree T){ //Leaf counter
	if (IsEmptyTree(T)) {
		return 0;
	}else if ((IsEmptyTree(LeftChild(T)))&&(IsEmptyTree(RightChild(T)))) {
		return 1;
	}else {
		return ((countL(LeftChild(T)))+countL(RightChild(T)));
	}
}

int comp(int a, int b){ 
	if (a>=b) {
		return a;
	}else {
		return b;
	}
}

int height(tBinTree T){ //Max tree height

	if (IsEmptyTree(T)) {
		return 0;
	}else {
		return 1 + comp(height(LeftChild(T)),height(RightChild(T)));
	}
}

