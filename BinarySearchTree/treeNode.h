#pragma once
#include "element.h"

typedef struct treeNode* treePtr;
typedef struct treeNode
{
	element			key;
	treePtr			left, right;
}treeNode;

treePtr		MakeNode(element data, treePtr leftNode, treePtr rightNode);
void		Dealloc_Tree(treePtr root);
void		display(treePtr p);
treePtr		search(treePtr root, element key);
void		insertNode(treePtr* root, element key);
void		deleteNode(treePtr* root, element key);

