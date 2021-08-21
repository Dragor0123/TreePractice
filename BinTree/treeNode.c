#include <stdio.h>
#include <stdlib.h>
#include "treeNode.h"
#include "Queue.h"
#include "Stack.h"

treePtr MakeNode(int data_, treePtr leftNode_, treePtr rightNode_)
{
	treePtr root = (treePtr)malloc(sizeof(treeNode));
	if (!root)
		return NULL;
	root->left = leftNode_;
	root->right = rightNode_;
	root->data = data_;
	return root;
}

void Dealloc_Tree(treePtr root_)
{
	if (root_)
	{
		if (root_->left)
			Dealloc_Tree(root_->left);
		if (root_->right)
			Dealloc_Tree(root_->right);
		free(root_);
		root_ = NULL;
	}
}

int Get_Data(treePtr node_)
{
	if (!node_)
	{
		return INT_MIN;
	}
	return node_->data;
}

void In_Order(treePtr root_)
{
	if (root_)
	{
		if (root_->left)
			In_Order(root_->left);
		printf("%d, ", root_->data);
		if (root_->right)
			In_Order(root_->right);
	}
}

void In_Order_iter(treePtr root_)
{
}

void Pre_Order(treePtr root_)
{
	if (root_)
	{
		printf("%d, ", root_->data);
		if (root_->left)
			Pre_Order(root_->left);
		if (root_->right)
			Pre_Order(root_->right);
	}
}

void Pre_Order_iter(treePtr root_)
{
	StackType s;
	Init_Stack(&s);
	if (!root_) return;
	Push_Stack(&s, root_);
	while (1) {
		root_ = Pop_Stack(&s);
		printf("%d ,", root_->data);
		if (root_->right) Push_Stack(&s, root_->right);
		if (root_->left) Push_Stack(&s, root_->left);
		if (Is_StackEmpty(&s)) break;
	}
}

void Post_Order(treePtr root_)
{
	if (root_)
	{
		if (root_->left)
			Post_Order(root_->left);
		if (root_->right)
			Post_Order(root_->right);
		printf("%d, ", root_->data);
	}
}

void Post_Order_iter(treePtr root_)
{
}

void Level_Order(treePtr root)
{
}
