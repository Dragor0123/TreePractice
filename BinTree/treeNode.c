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

/*
* recursive version of inorder traversal
*/
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

/*
* iterative version of inorder traversal
*/
void In_Order_iter(treePtr root_)
{
	StackType s;
	if (!root_)
		return;

	Init_Stack(&s);
	while (1)
	{
		while (root_)
		{
			Push_Stack(&s, root_);
			root_ = root_->left;
		}
		root_ = Pop_Stack(&s);
		printf("%d, ", root_->data);
		if (Is_StackEmpty(&s) && !(root_->right))
			break;
		root_ = root_->right;
	}
}

/*
* recursive version of preorder traversal
*/
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

/*
* iterative version of preorder traversal
*/
void Pre_Order_iter(treePtr root_)
{
	StackType s;
	if (!root_) 
		return;

	Init_Stack(&s);
	Push_Stack(&s, root_);
	while (1) 
	{
		root_ = Pop_Stack(&s);
		printf("%d, ", root_->data);
		if (root_->right) 
			Push_Stack(&s, root_->right);
		if (root_->left) 
			Push_Stack(&s, root_->left);
		if (Is_StackEmpty(&s)) 
			break;
	}
}

/*
* recursive version of postorder traversal
*/
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

/*
* iterative version of postorder traversal
*/
void Post_Order_iter(treePtr root_)
{
	StackType s, bs;
	if (!root_)
		return;

	Init_Stack(&s);
	Init_Stack(&bs);
	Push_Stack(&s, root_);
	while (!Is_StackEmpty(&s))
	{
		root_ = Pop_Stack(&s);
		Push_Stack(&bs, root_);
		if (root_->left)
			Push_Stack(&s, root_->left);
		if (root_->right)
			Push_Stack(&s, root_->right);
	}

	while (!Is_StackEmpty(&bs))
	{
		printf("%d, ", Pop_Stack(&bs)->data);
	}
}

void Level_Order(treePtr root_)
{
	QueueType q;
	if (!root_)
		return;
	
	Init_Queue(&q);
	Push_Queue(&q, root_);
	while (1)
	{
		root_ = Pop_Queue(&q);
		printf("%d, ", root_->data);
		if (root_->left)
			Push_Queue(&q, root_->left);
		if (root_->right)
			Push_Queue(&q, root_->right);
		if (Is_QueueEmpty(&q))
			break;
	}
}

treePtr Copy_Tree(treePtr in_)
{
	if (in_)
	{
		treePtr output = (treePtr)malloc(sizeof(treeNode));
		if (!output)
			return output;
		output->data = in_->data;
		output->left = Copy_Tree(in_->left);
		output->right = Copy_Tree(in_->right);
		return output;
	}
	else
	{
		return NULL;
	}
}

int Get_Max(treePtr root_)
{
	if(root_)
	{
		int max = root_->data;
		int tmp = Get_Max(root_->left);
		if (max < tmp)
			max = tmp;
		tmp = Get_Max(root_->right);
		if (max < tmp)
			max = tmp;
		return max;
	}
	else
		return 0;
}

int Get_Sum(treePtr root_)
{
	int leftSum = 0, rightSum = 0;
	if (!root_)
		return 0;
	else
	{
		leftSum = Get_Sum(root_->left);
		rightSum = Get_Sum(root_->right);
		return (root_->data + leftSum + rightSum);
	}
}
